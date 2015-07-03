#!/usr/bin/python
# -*- coding: utf-8 -*-
""" 


    $Date: 2010-03-09 10:41:04 +0100 (Di, 09 Mrz 2010) $
    $Rev: 11457 $
    $Author: goldammer $
    $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/TOOLS/Python_scripts/trunk/KombiTextPrompts/Conversion_Text_Prompts.py $

    Copyright (c) 2007 S1nn GmbH & Co. KG.
    All Rights Reserved.

"""

_svn_id = "$Id$"
_svn_rev = "$Rev: 11457 $"
__version__ = _svn_rev[6:-2]

import sys, os, time
import glob
import easyexcel
import csv
import re
import struct

from SignalsSettingsFile import MapFieldNameToColumnNumber_dict
from SignalsSettingsFile import MapFieldNameToRowNumber_dict


def initialiseList():
    abcd = []
    for counter in range(MapFieldNameToRowNumber_dict['LastRow'] - MapFieldNameToRowNumber_dict['StartingRow'] ):
        abcd.append(None)
    return abcd    

def initialiseList_Mailbox():
    abcd = []
    for counter in range(MapFieldNameToRowNumber_dict['LastMailboxRow'] - MapFieldNameToRowNumber_dict['StartingMailboxRow'] ):
        abcd.append(None)
    return abcd    
    
class CANSignals(object):
    """
    Signal generattor enums
    """
    def __init__(self, 
                 instanceInputFile, instanceInputFileDirectory, instanceOutputDirectory):

        self.instanceInputFile = instanceInputFile
        print "File" , instanceInputFile
        print "FileinputDirectory", instanceInputFileDirectory
        print "GenerateDirectory", instanceOutputDirectory
        instanceOutputHFile =  instanceOutputDirectory + 'CANSignalGenerator.h'
        self.DescriptorCreatedHFile = open(instanceOutputHFile, 'w')


    def initialiseExcelSheet(self):
        #===============================================================================
        #    create input file instance.
        #===============================================================================        
         
        try:
            self.EasyExcelObject = easyexcel.easyExcel(self.instanceInputFile, False)
#===============================================================================
#            At the time of exception
#===============================================================================
        except:
            print "Closing due to problem"
            self.EasyExcelObject.close()


    
    def getLanguageTextAndFrameIdsFromExcelSheet(self, workingSheetNumber = 2):
        #===============================================================================
        #     below a tuple of tuples is returned. i.e a 2 D array by the function
        #     which is converted into a list.
        #     this will store the information in integer / UTf-16 format in 
        #     the below mentioned list.
        #===============================================================================
            
        print workingSheetNumber
        self.EasyExcelObject.setSheet(workingSheetNumber)
        
        self.BotschaftList = list(self.EasyExcelObject.getSpecificRange(MapFieldNameToRowNumber_dict['StartingRow'],
                                                                  MapFieldNameToColumnNumber_dict['Botschaft'],
                                                                  MapFieldNameToRowNumber_dict['LastRow'],
                                                                  MapFieldNameToColumnNumber_dict['Botschaft']))

        self.SignalList = list(self.EasyExcelObject.getSpecificRange(MapFieldNameToRowNumber_dict['StartingRow'],
                                                                  MapFieldNameToColumnNumber_dict['SignalName'],
                                                                  MapFieldNameToRowNumber_dict['LastRow'],
                                                                  MapFieldNameToColumnNumber_dict['SignalName']))

        self.Receiver = list(self.EasyExcelObject.getSpecificRange(MapFieldNameToRowNumber_dict['StartingRow'],
                                                                  MapFieldNameToColumnNumber_dict['Receiver'],
                                                                  MapFieldNameToRowNumber_dict['LastRow'],
                                                                  MapFieldNameToColumnNumber_dict['Receiver']))
        print self.Receiver


    def __del__(self):
        """
        destruct created instances.
        """
        self.EasyExcelObject.close()
        self.DescriptorCreatedHFile.close()
       
    def createFileHeader(self, toolsDirectory):
        """
        To create the header information in the file.
        Please fill the information what you want to put in the file in the beginning.
        """
        import_file_desc_h = open(toolsDirectory + 'import_file_h.txt', 'r')
        readlines = import_file_desc_h.read()
        self.DescriptorCreatedHFile.write(readlines)
        import_file_desc_h.close()

    def generateEepromLayoutEnumFile(self, toolsDirectory):
        Botschaft = 'Test'
        
        readBlackListMessages = open(toolsDirectory + "/" + "BlacklistMessages.txt", 'r')
        readBlackListSignals = open(toolsDirectory + "/" + "BlacklistSignals.txt", 'r')
        self.BlacklistMessage = []
        self.BlacklistSignals = []
        BlackEntryFound = 0
        #copy file informations
        for line in readBlackListMessages:
            self.BlacklistMessage.append(line.rstrip())
        for line in readBlackListSignals:
            self.BlacklistSignals.append(line.rstrip())
        
        print self.BlacklistMessage
        
        print self.BlacklistSignals
        
        self.DescriptorCreatedHFile.write('typedef enum\n{\n')
        #self.DescriptorCreatedHFile.write(self.BotschaftList[0])
        for x in range (len(self.Receiver)):
            if (self.Receiver[x][0] != None):
                for line in range(len(self.BlacklistMessage)):
                    if (self.BlacklistMessage[line] == self.BotschaftList[x][0]):
                        BlackEntryFound = 1
                for line in range(len(self.BlacklistSignals)):
                    if (self.BlacklistSignals[line] == self.SignalList[x][0]):
                        BlackEntryFound = 1
                if (BlackEntryFound == 0):
                    if ('S' in self.Receiver[x][0]) or ( 'E' in self.Receiver[x][0]):
                        if (Botschaft in 'Test'):
                            enumIndexOffset = 0
                            enumIndex = 0
                        elif (self.BotschaftList[x][0] != Botschaft):
                            enumIndex = 0;
                            enumIndexOffset += 0x100
                        else:
                            enumIndex += 1
                        #print 'Signal ' + self.SignalList[x][0] + ' 0x%08x'%(enumIndex+enumIndexOffset&0xffffffff)
                        Botschaft = self.BotschaftList[x][0]
                        self.DescriptorCreatedHFile.write('    ' + self.BotschaftList[x][0] + '_' + self.SignalList[x][0] + '\t' + ' = ' + '0x%08X'%(enumIndex+enumIndexOffset) + ',')
                        self.DescriptorCreatedHFile.write('\n')
                else:
                    BlackEntryFound = 0
        self.DescriptorCreatedHFile.write('    MAX_CAN_SIGNALS\t = 0xFFFFFFFF\n')
        self.DescriptorCreatedHFile.write('}CAN_SIGNAL_ENUMS;\n')


    def createFileFooter(self):
        """
        To create the footer information in the file.
        Please fill the information what you want to put in the file in the end.
        """
        self.DescriptorCreatedHFile.write('\n#endif /* _CAN_GEN_SIGNALS_H */\n')
        self.DescriptorCreatedHFile.write('/* End Of File CANSignalGenerator.h */\n')
        self.DescriptorCreatedHFile.close()    

    def runScript(self, ExcelFilePath, ExcelFileDirectory, scriptDirectory):
        generatedDirectory = os.path.join(scriptDirectory,'../generated/' )
        toolsDirectory = os.path.join(scriptDirectory,'../tools/SignalGenerator/' )
        ClassObjectCANSignals = CANSignals(ExcelFilePath, ExcelFileDirectory, generatedDirectory)
        ##Initialise the excel sheets
        instanceExcelObject = ClassObjectCANSignals.initialiseExcelSheet()
        
        workingSheet = 3
        ClassObjectCANSignals.getLanguageTextAndFrameIdsFromExcelSheet(workingSheet)
        
        ##Create File Header
        ClassObjectCANSignals.createFileHeader(toolsDirectory)
        
        #Generate the Language enums
        ClassObjectCANSignals.generateEepromLayoutEnumFile(toolsDirectory)
        
   
        ##Create File Header
        ClassObjectCANSignals.createFileFooter()
        print 'END'



if __name__ == '__main__':

    pass            


# End Of File Conversion_Text_Prompts.py
