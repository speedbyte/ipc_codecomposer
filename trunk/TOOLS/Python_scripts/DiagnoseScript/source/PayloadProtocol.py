""" 


    $Date: 2009-06-23 15:46:24 +0200 (Di, 23 Jun 2009) $
    $Rev: 6848 $
    $Author: agrawal $
    $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/TOOLS/Python_scripts/trunk/DiagnoseScript/PayloadProtocol.py $

    Copyright (c) 2008 S1nn GmbH & Co. KG.
    All Rights Reserved.


"""

_svn_id = "$Id$"
_svn_rev = "$Rev: 6848 $"
__version__ = _svn_rev[6:-2]



import IsoTpProtocol as TP

class PayloadProtocol(object):
    """
    Service Id, RoutineControl, Routine Id high, Routine Id low, 
    Major code, Minor code.
    This class just creates the Frame upto the max size of 255 bytes
    It will be later segmented in the IsoTpProtocol.
    """
    
    def __init__(self, obj):
        self.Payload = [] 
        self.serviceId = 0x0
   
    def setServiceId(self, value):
        """
        It is not needed to use this function call because
        setRestPayload suffices. But when needed it just extends 
        frame with one byte.
        """
        self.Payload+= value
    
    def setRestPayload(self, value):
        """ 
        This function simply extends the bytes needed to be send on 
        the Bus.
        """
        self.Payload.extend(value)
            
    def getPayload(self):
        return self.Payload
    
    def getResponseId(self, responsecombined):
        if len(responsecombined) == 1:
            responseId = responsecombined[0][1]
        else:
            responseId = responsecombined[0][2] # the 2nd byte in this case is the length of the entire message
        #print "0x%.2x" % responseId
        return responseId    

    def getResponseLength(self, responsecombined):
        if len(responsecombined) == 1:
            responseLen = responsecombined[0][0]
        else:
            responseLen = responsecombined[0][1] # the 2nd byte in this case is the length of the entire message
        #print "0x%.2x" % responseId
        return responseLen    


    def getWaitId(self, responsecombined):
        waitID = responsecombined[0][3]
        return waitID
    
    def getTestStatus(self, responsecombined):
        if len(responsecombined) == 1:
            testStatus = responsecombined[0][5]
        else:
            testStatus = responsecombined[0][6] # the 2nd byte in this case is the length of the entire message
        #print "0x%.2x" % testStatus   
        return testStatus  
    
    def getUSBStatus(self, responsecombined):
        if len(responsecombined) == 1:
            USBStatus = responsecombined[1][2]
        else:
            USBStatus = responsecombined[1][2] # the 2nd byte in this case is the length of the entire message
        #print "0x%.2x" % testStatus   
        return USBStatus    
    
    def getStWheelStatus(self, responsecombined):
        if len(responsecombined) == 1:
            StWheelStatus = responsecombined[1][2]
        else:
            StWheelStatus = responsecombined[1][2] # the 2nd byte in this case is the length of the entire message
        #print "0x%.2x" % testStatus   
        return StWheelStatus 
    
    def getDataContents(self, responsecombined):
        leftLength = len(responsecombined)
        dataWithoutFrameNumbers = []
        if len(responsecombined) == 1:
            dataWithoutFrameNumbers += responsecombined[0][1:8]
        else:
            while (leftLength > 0):
                dataWithoutFrameNumbers += responsecombined[len(responsecombined)-leftLength][1:8]  # the 2nd byte in this case is the length of the entire message
                leftLength-=1
        return dataWithoutFrameNumbers
    



if __name__=='__main__':
    
    OnlyPayload= PayloadProtocol()
    OnlyPayload.setServiceId([0x31])
    OnlyPayload.setRestPayload([0x2, 0x4, 0x2]*10)
    a = OnlyPayload.getPayload()
    print a
    Completemessage = TP.IsoTpProtocol(0x7D0, a)
    Completemessage.getCanMessages()      
                 
                        