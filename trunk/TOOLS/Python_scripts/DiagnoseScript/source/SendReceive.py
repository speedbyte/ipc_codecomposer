""" 


    $Date: 2009-06-23 15:46:24 +0200 (Di, 23 Jun 2009) $
    $Rev: 6848 $
    $Author: agrawal $
    $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/TOOLS/Python_scripts/trunk/DiagnoseScript/SendReceive.py $

    Copyright (c) 2008 S1nn GmbH & Co. KG.
    All Rights Reserved.


"""

_svn_id = "$Id$"
_svn_rev = "$Rev: 6848 $"
__version__ = _svn_rev[6:-2]



import pyCAN
import time

dict_ReceiveCanIds = {
'UHV_100' : 0x7D5,
'UHV_500' : 0x7D5,
'Kombi_500' : 0x77E,
'SCM_125' : 0x77A,
'SYNC_500' : 0x7D8,
'ADR_500' : 0x7DD,
'OCU_500' : 0x7D1,
'UMI_100' : 0x7D5,
'UMI_500' : 0x7D5,
}

class SendReceive(object):
    def __init__(self, print_q_obj):
        self.SRActive = False
        self.timer = 200000
        self.MessageRequest = None
        self.timer_wait = 200000
        self.PrintQueueObject= print_q_obj
        pass
    
    def sendReceiveProtocol(self, MessageRequests, FlowControlMessage, CanDriverObject):
        """
        """
        self.MessageRequest = MessageRequests
        self.SRActive = True
        response = []
        ignorefirstread = False
        if self.MessageRequest != None:
            if len(MessageRequests) == 1:
                ignorefirstread = False
            else:
                # The first read will be a FlowControl message
                ignorefirstread = True
            for element in MessageRequests:
                 #try:
                    self.timer = 200000
                    return_val = self.writeSequence(CanDriverObject, element)
                    if return_val == [1] or return_val == [3]:
                        return return_val
                    elif return_val == [2]:
                        continue
                    self.PrintQueueObject.put('SR Sending :\r\n')
                    for index in range(element.LEN):
                        self.PrintQueueObject.put("0x%.2x  " % element.DATA[index])
                    self.PrintQueueObject.put("\r\n")
                    while ignorefirstread is True:
                        # Executing 1st stage
                        return_val = self.readSequence(CanDriverObject)
                        if return_val == [1] or return_val == [3]:
                            return return_val
                        elif return_val == [2]:
                            continue
                        self.PrintQueueObject.put("UHV-Skript: Flow Control Frame\r\n")
                        print "%x %x %x"  % (self.result.ID, self.result.DATA[0],self.result.DATA[1])
                        ignorefirstread = False
        self.timer = 200000
        while 1:                
            # Executing second stage
            return_val = self.readSequence(CanDriverObject)
            if return_val == [1] or return_val == [3]:
                return return_val
            elif return_val == [2]:
                continue            
            self.PrintQueueObject.put("Received:\r\n")
            response.append(self.result)

            if self.result.DATA[0] > 15:
                totalminus6 = ( self.result.DATA[1] - 6 )
                totaliterations = totalminus6 / 7
                if (totalminus6%7) > 0:
                    totaliterations+=1
            else:
                totaliterations = 0
            #print "Total It = " ,totaliterations
            for index in range(self.result.LEN):
                self.PrintQueueObject.put("0x%.2x  " % self.result.DATA[index])
            self.PrintQueueObject.put("\r\n")
            
            
            
            if totaliterations > 0:                
                for element in FlowControlMessage:
                    self.timer = 200000
                    return_val = self.writeSequence(CanDriverObject, element)
                    if return_val == [1] or return_val == [3]:
                        return return_val
                    elif return_val == [2]:
                        continue
                    self.PrintQueueObject.put("Sending Flow Control Frame to receive further messages\r\n")
            self.timer = 200000        
            while totaliterations > 0:
                return_val = self.readSequence(CanDriverObject)
                if return_val == [1] or return_val == [3]:
                    return return_val
                elif return_val == [2]:
                    continue
                totaliterations = totaliterations - 1
                response.append(self.result)
                for index in range(self.result.LEN):
                    self.PrintQueueObject.put("0x%.2x  " % self.result.DATA[index])
                self.PrintQueueObject.put("\r\n")
                self.timer = 200000
            break
        #CanDriverObject.close()    
        
        return response
    
    def readSequence(self, CanDriverObject):
        try:
            time.sleep(0.0002)  # this timing is very critical.
            if self.SRActive == True:
                self.result=CanDriverObject.read()
                #print "trying"
            elif self.SRActive == False:
                print "SR:Read Error SR Active is False"
                return [1]
        except pyCAN.QRCVEMPTY_Error:
            self.timer = self.timer - 1
            if self.timer == 0:
                self.timer = 200000
                self.PrintQueueObject.put("No messages on CAN Bus\r\n")
                return [1]
            return [2]
        except pyCAN.UNKNOWN_Error:
            #self.PrintQueueObject.put("unknown error\r\n")
            return [2]
        if self.result.ID != self.ReceiveCanId:
            if self.MessageRequest == None:
                self.timer_wait = self.timer_wait - 1
                if self.timer_wait == 0:
                    self.timer_wait = 200000
                    self.PrintQueueObject.put("Wait message timeout\r\n")
                    print "SR:Read Error"
                    return [3]
            return [2]
        #self.PrintQueueObject.put(str(time.time()))
   

    def writeSequence(self, CanDriverObject, element):
        try:
            time.sleep(0.01) # this timing is very critical
            if self.SRActive == True:
                self.result=CanDriverObject.write(element)
            elif self.SRActive == False:
                print "SR:Write Error"
                return [1]
        except:
            self.timer = self.timer - 1
            if self.timer == 0:
                self.PrintQueueObject.put("Retried 5000 times and failed to write\r\n")
                print "SR:Write Error"
                return [1]
            return [2]
    
    def setReceiveCanId(self, device):
        self.ReceiveCanId = dict_ReceiveCanIds[device]
        print "Initialising Peak with Recv Id = ", hex(self.ReceiveCanId) 

if __name__ == '__main__':
    
    import PayloadProtocol as PP
    import IsoTpProtocol as TP    
     
    cd = pyCAN.CanDriver()
    cd.open()
    sr = SendReceive()
    OnlyPayload2 = PP.PayloadProtocol()
    OnlyPayload2.setServiceId([0x31])
    OnlyPayload2.setRestPayload([0x01, 0xFB, 0x00, 0xCE, 0x00])
    
    b = OnlyPayload2.getPayload()
    c = [0x30] + [0x0]*7
    print "SR TotalPayLoad = ", b
    Completemessage2 = TP.IsoTpProtocol(0x76B, b)
    Completemessage3 = TP.IsoTpProtocol(0x76B, c)
    TosendtoCancontrollerMessage = Completemessage2.getCanMessages()      
    TosendFlowcontrolMessage = Completemessage3.getFlowControlMessages()        
    response = sr.sendReceiveProtocol(TosendtoCancontrollerMessage,TosendFlowcontrolMessage, cd)
    print response
