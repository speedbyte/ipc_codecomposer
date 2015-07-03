""" 


    $Date: 2009-06-23 15:46:24 +0200 (Di, 23 Jun 2009) $
    $Rev: 6848 $
    $Author: agrawal $
    $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/TOOLS/Python_scripts/trunk/DiagnoseScript/AnalyseResponse.py $

    Copyright (c) 2008 S1nn GmbH & Co. KG.
    All Rights Reserved.


"""

_svn_id = "$Id$"
_svn_rev = "$Rev: 6848 $"
__version__ = _svn_rev[6:-2]



import IsoTpProtocol as IP
import PayloadProtocol as PP
import struct
       
class AnalyseResponse(object):
    """
    """
  
    def __init__(self, obj):
        """
        """
        self.ip = IP.IsoTpProtocol(obj)
        self.pp = PP.PayloadProtocol(obj) 
        #self.fileDesEeprom = open("Eeprom.bin", "wb")
    
    def readEolResponse(self, response):
        """
        """
        responsecombined, id = self.ip.convertCanToResponseFrame(response)
        responseId = self.pp.getResponseId(responsecombined)
        testStatus = self.pp.getTestStatus(responsecombined)         
        return [responseId, testStatus]
    
    def readUSBResponse(self, response):
        """
        """
        responsecombined, id = self.ip.convertCanToResponseFrame(response)  
        USBStatus = self.pp.getUSBStatus(responsecombined)       
        return [USBStatus]
    
    def readStWheelResponse(self, response):
        """
        """
        responsecombined, id = self.ip.convertCanToResponseFrame(response)  
        StWheelStatus = self.pp.getStWheelStatus(responsecombined)       
        return [StWheeltatus]    
    
    def readMessageResponse(self, response):
        """
        """
        responsecombined, id = self.ip.convertCanToResponseFrame(response)     
        return [responsecombined, id]
    
    def readCharacters(self,response):
        """
        """
        responsecombined, id = self.ip.convertCanToResponseFrame(response)
        responseContents = self.pp.getDataContents(responsecombined)
        if (len(responsecombined) == 1):
            responseContents = responseContents
        else:
            responseContents = responseContents[1:]
        resultOfContents = ''.join(["%c" % i for i in responseContents if i != 0x0])[6:]
        #print resultOfContents
        #print ''.join(["%c" % i for i in resultContents])
        return responseContents
          

    def convertToUnicode(self, byteContents, responseID):
        if ( responseID == 0x063 ) :
            resultOfContents = ''.join(["%c" % i for i in byteContents[1:] if (i != 0x0) and (i != 0xAA)])
        else:
            resultOfContents = ''.join(["%c" % i for i in byteContents[3:] if (i != 0x0) and (i != 0xAA)])
        return 'Char: %s' % resultOfContents

    def convertToEepromFile(self, byteContents):
#        resultOfContents = ''.join(["%c" % i for i in byteContents])
        #byteContents = [for i in byteContents if (i != 0xAA )])
        byteContentsHex = []
        byteContentsHexString = map(hex, byteContents[1:-3]) 
        for elem in range(len(byteContentsHexString)):
            byteContentsHex.append(int(byteContentsHexString[elem], 16))
        fileDesEeprom = open("Eeprom.bin", "ab")
        for x in range(len(byteContentsHex)):
            data = struct.pack("B", byteContentsHex[x])
            fileDesEeprom.write(data)
            fileDesEeprom.flush()
        fileDesEeprom.close()
    
    def decodeDiagnosticsError(self, byteContents):
        errorcode=[]
        errors=[]
        index = 0        
        for i in range(len(byteContents)):
            if (byteContents[i]==0x19):
                index=i+1;
                break;
        for i in range(index,len(byteContents)):
            if (len(errorcode)<4):
                errorcode.append(byteContents[i])
            if (len(errorcode)>=4):
                errors.append(errorcode)
                errorcode=[]
        return errors
    
    def DecodeMesuarment0x22(self, byteContents):
        responseContents=[] 
        for i in range(3,len(byteContents)):
            responseContents.append(byteContents[i])
        return responseContents 
    
    def convertToFloat(self, byteContents, responseID):
        if ( responseID == 0x063 ) :
            resultOfContents = ''.join(["%f" % i for i in byteContents[3:] if (i != 0x0) and (i != 0xAA)])
        else:
            resultOfContents = ''.join(["%f" % i for i in byteContents[1:] if (i != 0x0) and (i != 0xAA)])
        return 'Float: %s' % resultOfContents
    
    
    
