""" 
    $Date: 2009-06-23 15:46:24 +0200 (Di, 23 Jun 2009) $
    $Rev: 6848 $
    $Author: agrawal $
    $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/TOOLS/Python_scripts/trunk/DiagnoseScript/CreatePayload.py $

    Copyright (c) 2008 S1nn GmbH & Co. KG.
    All Rights Reserved.
"""

_svn_id = "$Id$"
_svn_rev = "$Rev: 6848 $"
__version__ = _svn_rev[6:-2]


import PayloadProtocol as PP
import IsoTpProtocol as TP
import DiagFrame_1

dict_TransmitCanIds = {
'UHV_100' : 0x76B,
'UHV_500' : 0x76B,
'Kombi_500' : 0x714,
'SCM_125': 0x772,
'SYNC_500': 0x7D0,
'ADR_500' : 0x773,
'OCU_500' : 0x767,
'UMI_100' : 0x76B,
'UMI_500' : 0x76B,
}


command_dict_fc = {
'FlowControlMessage' : [0x30] + [0x0] + [0x14] + [0x0]*5 , # VMCU V.6 ok 
}
class CreatePayload(object):
    """
    """
    
    def __init__(self, obj):
        """
        """
        self.QueueObject = obj
        pass
    
    
    
    def createPayloadAndSegment(self, Command):

#===============================================================================
#        Create simply a Payload to be sent later for segmenting.
#===============================================================================
        OnlyPayload = PP.PayloadProtocol(self.QueueObject)
        if isinstance(Command, str) is True:
            OnlyPayload.setRestPayload(command_dict[Command])
        else:
            OnlyPayload.setRestPayload(Command)
        rawPayLoad = OnlyPayload.getPayload()
        #print "ER TotalPayLoad = ", rawPayLoad

#===============================================================================
#        Segment message created according to ISOTP protocol
#===============================================================================
        CompleteMessage = TP.IsoTpProtocol(self.TransmitCanId, rawPayLoad)
        toSendToCanControllerMessage = CompleteMessage.getCanMessages()
        return toSendToCanControllerMessage
            
    
    
    def createFlowControlMessage(self):

#===============================================================================
#        Create simply a Payload to be sent later for segmenting.
#===============================================================================
        OnlyPayload = PP.PayloadProtocol(self.QueueObject)
        OnlyPayload.setRestPayload(command_dict_fc['FlowControlMessage'])
        rawPayLoad = OnlyPayload.getPayload()
        #print "ER FC TotalPayLoad = ", rawPayLoad

#===============================================================================
#        Segment message created according to ISOTP protocol
#===============================================================================
        CompleteMessage = TP.IsoTpProtocol(self.TransmitCanId, rawPayLoad)
        toSendToCanControllerMessage = CompleteMessage.getFlowControlMessage()
        return toSendToCanControllerMessage

    def setTransmitCanId(self, device):
        self.TransmitCanId = dict_TransmitCanIds[device]
        print "Initialising Peak with Transmit Id = ", hex(self.TransmitCanId) 


