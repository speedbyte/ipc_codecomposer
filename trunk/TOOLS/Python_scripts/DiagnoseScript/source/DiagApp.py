""" 

    $Date: 2009-06-25 12:07:53 +0200 (Do, 25 Jun 2009) $
    $Rev: 6883 $
    $Author: agrawal $
    $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/TOOLS/Python_scripts/trunk/DiagnoseScript/DiagApp.py $

    Copyright (c) 2008 S1nn GmbH & Co. KG.
    All Rights Reserved.

"""

_svn_id = "$Id$"
_svn_rev = "$Rev: 6883 $"
__version__ = _svn_rev[6:-2]


#from UserInterface import messageseq
import SendReceive
import CreatePayload
import AnalyseResponse
import PayloadProtocol
import pyCAN
import time
import Queue
import time
from threading import Thread
import threading
import Queue
from time import clock, sleep


#import pyPdf

# ------- Init -----------

routineStatus_dict = {
'active' : 0x02,
'completed' : 0x0,
'aborted' : 0x1
}
responseStatus_dict = {
'negative_notSupported' : 0x7F,
'negative_responsePending' : 0x78,
'negative_ECUbusy' : 0x21,
'positive' : 0x71,
'positive_diagnostic' : 0x50,
'positive_SteerButton' : 0x62,
'positive_TesterPres' : 0x7e,
}
routineType_dict = {
'quickrun': 0x10,
'timeRun' : 0x20,
'tillstopRun' : 0x30
}
DefaultRestPayload = 0x00

class DiagApp(object):
    def __init__(self, obj, uni_q_obj):

        self.cd = pyCAN.CanDriver()

        self.PrintQueueObject = obj
        self.UnicodeConvertQueueObject = uni_q_obj   # this is a second queue because of a second textctrl box.
        #===============================================================================
        # #initialise objects      
        self.cp = CreatePayload.CreatePayload(self.PrintQueueObject)  # create Payload
        self.sr = SendReceive.SendReceive(self.PrintQueueObject)      # send on Bus and get the response back
        self.ar = AnalyseResponse.AnalyseResponse(self.PrintQueueObject)  # analyze the response
        self.pp = PayloadProtocol.PayloadProtocol(self.PrintQueueObject)
        
        self.CurrentEcu = ""
        #self.FlowControlMessage = self.cp.createFlowControlMessage()
        self.PrintQueueObject.put(" Diagnosis through PEAK \r\n")
        #===============================================================================     
    def SendReceiveMain(self, messageToSend):

        # create requests
        time.sleep(0.2)
        self.FlowControlMessage = self.cp.createFlowControlMessage()
        for msgs in messageToSend:
            #before starting a new message clear the print queue completely.
            try:
                self.PrintQueueObject.get_nowait()
            except:
                pass
            self.PrintQueueObject.put("----------------------------------------\r\n")
            self.PrintQueueObject.put(str(msgs))
            self.PrintQueueObject.put("\r\n")
#===============================================================================
#            print " "
#            print "----------------------------------------------" 
#            print "DiagApp:" , msgs
#===============================================================================
            RequestMessage = self.cp.createPayloadAndSegment(msgs)
            response = self.sr.sendReceiveProtocol(RequestMessage, self.FlowControlMessage, self.cd)
            if response == [1]:
                #Close The peak driver
                print " Problem in Receiving, Resetting the PeakDongle"
                self.cd.resetClient()
                return None, None, None
            # read response
            responseZussamen, Canid = self.ar.readMessageResponse(response)
            responseID = self.pp.getResponseId(responseZussamen)
            testStatus = self.pp.getTestStatus(responseZussamen)         
            waitID = self.pp.getWaitId(responseZussamen)
            while ( waitID == responseStatus_dict['negative_responsePending']):
                self.PrintQueueObject.put("Waiting\r\n")
                response = self.sr.sendReceiveProtocol(None, self.FlowControlMessage, self.cd)
                if response == [1]: # Queue Empty
                    self.PrintQueueObject.put('Queue Empty, no Pending\r\n')
                    continue
                elif response == [3]:
                    self.PrintQueueObject.put('Queue Empty, no ID\r\n')
                    return None, None, None
                responseZussamen, Canid = self.ar.readMessageResponse(response)
                responseID = self.pp.getResponseId(responseZussamen)
                testStatus = self.pp.getTestStatus(responseZussamen)         
                waitID = self.pp.getWaitId(responseZussamen)
            responseID = self.pp.getResponseId(responseZussamen)
            testStatus = self.pp.getTestStatus(responseZussamen) 
            responseLength = self.pp.getResponseLength(responseZussamen)         
            waitID = self.pp.getWaitId(responseZussamen)
            responseContents = self.ar.readCharacters(response)

            # loops if the message sent is Result
            if (self.CurrentEcu == "SYNC_500" ):
                print "Current Ecu is %s" %self.CurrentEcu
                if  '49, 3' in str(msgs):
                    if '49, 3, 251, 4' in str(msgs):
                        while 1:
                            RequestMessage = self.cp.createPayloadAndSegment(msgs)
                            response = self.sr.sendReceiveProtocol(RequestMessage, self.FlowControlMessage, self.cd)
                            if response == [1]:
                                #Close The peak driver
                                self.cd.resetClient()
                                return None, None, None
                            # read response
                            responseZussamen, Canid = self.ar.readMessageResponse(response)
                            responseID = self.pp.getResponseId(responseZussamen)
                            testStatus = self.pp.getTestStatus(responseZussamen)         
                            waitID = self.pp.getWaitId(responseZussamen)
                            time.sleep(2)
                            if waitID == responseStatus_dict['negative_ECUbusy']:
                                print "Cold Reboot Busy, Retrying..."
                                pass
                            else:
                                print "Cold Reboot complete"
                                break
                        else:
                            while (testStatus & 0x7) == routineStatus_dict['active']:
                                RequestMessage = self.cp.createPayloadAndSegment(msgs)
                                response = self.sr.sendReceiveProtocol(RequestMessage, self.FlowControlMessage, self.cd)
                                if response == [1]:
                                    #Close The peak driver
                                    self.cd.resetClient()
                                    return None, None, None
                                # read response
                                responseZussamen, Canid = self.ar.readMessageResponse(response)
                                responseID = self.pp.getResponseId(responseZussamen)
                                testStatus = self.pp.getTestStatus(responseZussamen)         
                                waitID = self.pp.getWaitId(responseZussamen)
                                time.sleep(2)
                                if ((testStatus & 0x7) == routineStatus_dict['active']):
                                    time.sleep(4)   

            if responseID == (msgs[0] + 0x40):
                responseContentsUnicode = self.ar.convertToUnicode(responseContents,responseID)
                responseContentsToFloat = self.ar.convertToFloat(responseContents, responseID)
                self.PrintQueueObject.put('positive response\r\n')
                self.UnicodeConvertQueueObject.put(responseContentsUnicode + '\r\n')                
                if (self.CurrentEcu == "SYNC_500" ):
                    self.UnicodeConvertQueueObject.put(responseContentsToFloat + '\r\n')
            elif responseID == 0x7F:
                self.PrintQueueObject.put("negative response\r\n")
                continue
        if ( messageToSend[0][0] == 0x19 and responseID == 0x59 ):  # Fehlerspeicher
            analysedDtcResponse = self.ar.decodeDiagnosticsError(responseContents)
            responseContents = analysedDtcResponse
        if ( messageToSend[0][0] == 0x22 and responseID == 0x62 ):  # response 0x22            
            analysed0x22Response = self.ar.DecodeMesuarment0x22(responseContents)
            responseContents = analysed0x22Response
#        if ( messageToSend[0][0] == 0x23 and responseID == 0x63 ):  # response 0x23
#            analysed0x22Response = self.ar.DecodeMesuarment0x22(responseContents)
#            #analysedDtcResponse = [[208, 20, 0, 24], [144, 81, 19, 24]]
#            #responseContents = analysedDtcResponse
        return responseContents, responseID, responseLength
    
    
    def setCurrentEcu(self, CurrentEcu):
        self.CurrentEcu = CurrentEcu

        

class CanFilter:
    """ Filter for CAN message IDs
    """
    def __init__(self):
        self.CanIDs = []

    def addCanID(self, canID):
        self.CanIDs.append(canID)

    def clearCanIDs(self):
        self.CanIDs = []


class CanFilterThread(threading.Thread):
    """ Thread for dispatching CAN messages from bus. It can be configured with filters
    """
    def __init__(self, da_object):
        threading.Thread.__init__(self)
        #prepare event flag for shutdown signal       
        self.shutdownNow = threading.Event()
        self.shutdownNow.set()
        #set interval for message dispatching        
        self.fetchInterval = 0.001
        #Initialize empty Filter object
        self.Filter = CanFilter()
        #Set InQueue for messages coming from CAN bus
        self.RxQueue = Queue.Queue()
        #Set OutQueue for messages going to CAN bus         
        self.TxQueue = Queue.Queue()
        self.startsync = 0
        self.TimeStamp = 0
        self.classobject = da_object

    def __del__(self):
        if self.canDriver is not None:
            self.classobject.cd.close()
    def getRxQueue(self):
        return self.RxQueue
    def getTimeStamp(self):
        return self.TimeStamp
    def getTxQueue(self):
        return self.TxQueue
    def stop(self):
        self.shutdownNow.set()
    def startAgain(self):
        self.shutdownNow.clear()
     
    def run(self):
        #open or reopen can driver        
        #self.classobject.cd.open()        
        #Loop until shutdown event        
        start = self.startsync
        while(True):
            #Sleep before fetching next can message
            time.sleep(self.fetchInterval)
            if self.shutdownNow.isSet() is False:
                # If shutdown event was issued, jump out of while loop and end thread
                try:
                    self.TimeStamp=(clock()-start)
                    
                    msg = self.classobject.cd.read()                                    
                except pyCAN.QRCVEMPTY_Error:
                    #Receive queue is empty, don't continue to process msg
                    pass
                except pyCAN.UNKNOWN_Error:
                    pass
                else:
                    #check if filter for current CAN message exists
                    
                    if self.Filter.CanIDs.__len__()==0:
                        try:
                             #Put CAN message in new object together with timestamp
                             #Forward message to filtered queue                          
                             self.RxQueue.put(msg,False)

                        except Queue.Full():
                             #TODO: error handling
                             print "InQueue is full, Dropping received CAN message."
                    else:
                        for msgId in self.Filter.CanIDs:
                            if msg.ID == msgId:                    
                                try:
                                    #Put CAN message in new object together with timestamp
                                    #Forward message to filtered queue                                   
                                   self.RxQueue.put(msg,False)
                                except Queue.Full():
                                    #TODO: error handling
                                    print "InQueue is full, Dropping received CAN message."
              #  Sending CAN messages now
                while not (self.TxQueue.empty()):
                    try:
                        outMsg = self.TxQueue.get(False)
                    except Queue.Empty:
                        #Send queue is now empty, continue
                        print 'CAN Send queue empty'
                        pass                  
                    else:
                        try:
                            #Put msg on CAN bus
                            self.classobject.cd.write(outMsg)
                        except pyCAN.BUSOFF_Error:
                            self.classobject.cd.resetClient()
            #self.classobject.cd.close()
    def addFilter(self, filter):
        self.Filter = None
        self.Filter = filter

class CanDispatcher(threading.Thread):
    """ Base class for CAN message dispatchers. Implement processQueuedMsg() to
        get useful functionality
    """
    def __init__(self):
        threading.Thread.__init__(self)
        self.RxQueue = Queue.Queue()
        self.TxQueue = Queue.Queue()
        self.CallBackFct = None
        self.fetchInterval = 0.001
        #prepare event flag for shutdown signal       
        self.shutdownNow = threading.Event()
        self.shutdownNow.clear()

    def setRxQueue(self, rxQueue):
        """ Set filtered queue (Origin of msg objects)
        """
        self.RxQueue = None
        self.RxQueue = rxQueue
        
    def getRxQueue(self):
        """ Returns filtered Queue from CanFilterThread            
        """
        return self.RxQueue
        
    def getTxQueue(self):
        return self.TxQueue

    def stop(self):
        self.shutdownNow.set()

    def registerCallBackFct(self, callMe):
        self.CallBackFct = callMe

    def processQueuedMsg(self):
        #Overload this function with wanted functionality
        #Default behaviour is reading and dropping messages
        try:
            msg = self.RxQueue.get(False)
        except Queue.Empty:
            pass
        else:
            #inform Listener
            self.CallBackFct(msg)

    def run(self):

        #Thread loop
        while(True):
            time.sleep(self.fetchInterval)
            
            if self.shutdownNow.isSet():
                break
            self.processQueuedMsg()            

                        




if __name__ == '__main__':

    queueInstance1 = Queue.Queue(0)
    queueInstance2 = Queue.Queue(0)
    da = DiagApp(queueInstance1, queueInstance2)
    cyclicSender = CyclicSend(da)
    cyclicSender.start()    
    cyclicSender.startSending()
    da.SendReceiveMain(UserInterface.messageseq)        

    time.sleep(1) # The CAN Controller starts after  seconds.
    da.ReadForever()
    cyclicSender.stopSending()
    cd.close()
    cyclicSender = 1 # this would destroy the instance created for CyclicSender
    print " eolApp there was a problem in the CAN Driver.. restarting in 10 seconds"
    print " "
    print " ==========================================================================="
    print " ====                                                                   ===="
    print " ====                                                                   ===="
    print " ====                                                                   ===="
    print " ====                                                                   ===="
    print " ====                                                                   ===="
    print " ====                                                                   ===="
    print " ====                           RESTART                                 ===="
    print " ====                                                                   ===="
    print " ====                                                                   ===="
    print " ====                                                                   ===="
    print " ====                                                                   ===="
    print " ====                                                                   ===="
    print " ==========================================================================="
    print " ==========================================================================="
    #winsound.Beep(767,150)
    print time.ctime()
    time.sleep(1)
