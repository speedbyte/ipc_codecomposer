""" 


    $Date: 2009-06-23 15:46:24 +0200 (Di, 23 Jun 2009) $
    $Rev: 6848 $
    $Author: agrawal $
    $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/TOOLS/Python_scripts/trunk/DiagnoseScript/IsoTpProtocol.py $

    Copyright (c) 2008 S1nn GmbH & Co. KG.
    All Rights Reserved.

"""

_svn_id = "$Id$"
_svn_rev = "$Rev: 6848 $"
__version__ = _svn_rev[6:-2]


import pyCAN

class IsoTpProtocol(object):
    def __init__(self, CanId = 0x76B, Payload = []):
        self.CanId = CanId
        self.Payload = Payload
        
        
    def getCanMessages(self):
        from DiagApp import DefaultRestPayload
        result = []
        length = len(self.Payload)
        if length < 8:
            if length > 0:
                frame = [length] + self.Payload + [DefaultRestPayload]*(7 - length)
            else:
                frame = [0x0]*8    
            if __name__=='main':
                print frame
            result.append(pyCAN.makeCanMsg(self.CanId, frame))
        else:
            if length < 255:
                incrementer = 1
                frame = [0x10]
                frame.extend([length])
                frame.extend(self.Payload[0:6])
                pointtoindex = 6
                if __name__=='main':
                    print frame
                result.append(pyCAN.makeCanMsg(self.CanId, frame))
                restpayload = length - pointtoindex
                while restpayload > 0:
                    if __name__=='main':
                        print restpayload
                    frame = [0x20 + incrementer]
                    frame.extend(self.Payload[pointtoindex:(pointtoindex+7)])
                    pointtoindex = pointtoindex + 7
                    restpayload = restpayload - 7
                    if restpayload < 0:
                        frame.extend([0x0]*(0 - restpayload))
                    result.append(pyCAN.makeCanMsg(self.CanId, frame))
                    if __name__=='main':
                        print frame
                    incrementer+=1
                    if incrementer == 16:
                        incrementer = 0
        return result

    def getFlowControlMessage(self):
        # To do
        frame = self.Payload
        result = [pyCAN.makeCanMsg(self.CanId, frame)]
        return result
    
 
    def convertCanToResponseFrame(self,response):
        """ Converts given data bytes to a Response Message object.
        """
        framenumber = []
        for msg in response:
            combineddataresponse = []
            for index in range(8):
                combineddataresponse+=[msg.DATA[index]]
            framenumber.append(combineddataresponse)
        self.Payload = framenumber
        self.CanId = msg.ID
        return self.Payload, self.CanId
    
    def setDefaultRestPayload(self, DefaultPayload):
        self.DefaultRestpayload = DefaultPayload
    
if __name__=='__main__':
    
    payload = [1,2,3]*10
    GesamtMessage = IsoTpProtocol(0x76B, payload)
    a = GesamtMessage.getCanMessages()
    print a
    b = GesamtMessage.getFlowControlMessages()
    print b
                 
                        
                    
                    
                                 