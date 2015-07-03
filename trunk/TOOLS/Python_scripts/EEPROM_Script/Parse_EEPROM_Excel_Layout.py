""" 


    $Date: 2010-02-25 11:30:48 +0100 (Do, 25 Feb 2010) $
    $Rev: 11268 $
    $Author: agrawal $
    $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/TOOLS/Python_scripts/trunk/EEPROM_Script/Parse_EEPROM_Excel_Layout.py $

    Copyright (c) 2007 S1nn GmbH & Co. KG.
    All Rights Reserved.

"""

_svn_id = "$Id$"
_svn_rev = "$Rev: 11268 $"
__version__ = _svn_rev[6:-2]


## \file Parse_EEPROM_Excel_Layout.py
#  \brief  
#  1. This tool reads the excel sheet and generates the xml and bin files for the production.   
#  2. How to use this tool.
# The user should have the EEPROM_Layout as defined in the UHV Architecure. 
# This layout will be read and two files xml and bin files will be generated.
# The user needs to adjust the parameters defined in the settings file.


import ConfigParser
import csv
import easyexcel
import glob
import optparse
import re
import string
import struct
import sys
import os
import time
import filecmp
import ctypes



# ------------- Version -----------------------
script_version="0.1  2010-Jan-07"


class UHVEepromDataConversion(object):
    """
    """
    def __init__(self,instanceInputFile = r"BLAH_BLAH.xls", instanceOutputFile = ""):

        instanceInputFile = instanceInputFile
        print "INPUT = " + instanceInputFile
        self.OutputPath=instanceOutputFile

        try:
            self.EasyExcelObject_1 = easyexcel.easyExcel(instanceInputFile, False)
        except:
            print " Excel file not found or cannot be opened"
            raise KeyError  

        try:
            self.logFileDes = open(self.OutputPath+"/Output/output.txt", "w")
        except:
            print " Log file cannot be created"
            raise KeyError
        print "OUTPUT DIR =", self.OutputPath  

            


    def initialiseExcelSheet_1(self, AutoMarke, worksheet):
        #===============================================================================
        #    create input file instance.
        #===============================================================================        
        curdir = os.getcwd()
        workingSheetNumber = worksheet

        config = ConfigParser.ConfigParser()
        config.read(self.OutputPath + '/' + "EepromLayoutSettingsFile.cfg")    

        LengthColumn = int(config.get("EEPROMLAYOUTPROPERIES", "LengthColumn"))
        StartingAddressColumn = int(config.get("EEPROMLAYOUTPROPERIES", "StartingAddressColumn"))
        DescriptionColumn = int(config.get("EEPROMLAYOUTPROPERIES", "DescriptionColumn"))
        StartingAddressHexColumn =     int(config.get("EEPROMLAYOUTPROPERIES", "StartingAddressHexColumn"))
        RamShadowRequiredColumn = int(config.get("EEPROMLAYOUTPROPERIES", "RamShadowRequiredColumn"))
        
        self.DatafieldLength = [] 
        self.DatafieldStartAddress = []
        self.DatafieldDescription = []
        self.DatafieldStartAddressHex = []
        self.DatafieldRamShadowRequired = []
        
        
        try:
            self.EasyExcelObject_1.setSheet(workingSheetNumber)
        #===============================================================================
        #     below a tuple of tuples is returned. i.e a 2 D array by the function
        #     which is converted into a list.
        #     this will store the information in integer / UTf-16 format in 
        #     the below mentioned list.
        #===============================================================================
            row = 1
            column = 1
            value = self.EasyExcelObject_1.getValue(row, column)
            while (( value != "START" )):
                value = self.EasyExcelObject_1.getValue(row , column)
                row = row + 1
            StartRow = row
            print "Starting Row = " , StartRow
            
            row = 1
            column = 1
            value = self.EasyExcelObject_1.getValue(row, column)
            while (( value != "END" )):
                value = self.EasyExcelObject_1.getValue(row , column)
                #print "Val =", value
                row = row + 1
            LastRow = row - 1
            print "Last Row = " , LastRow
            
            if ( ('BASIS' in AutoMarke) == True ):
                self.TotalNumberOfRows = LastRow - StartRow
                LastRowCommon = LastRow
                self.TotalNumberOfRowsFinal = self.TotalNumberOfRows
            else:
                self.TotalNumberOfRowsDeltaSheet =  LastRow - StartRow
                LastRowCommon = LastRow
                self.TotalNumberOfRowsFinal = self.TotalNumberOfRowsDeltaSheet

            DatafieldLengthExcel = list(self.EasyExcelObject_1.getSpecificRange(StartRow,LengthColumn,LastRowCommon,LengthColumn))
            for counter in range(self.TotalNumberOfRowsFinal):
                self.DatafieldLength.append(int(DatafieldLengthExcel[counter][0]))
            #print self.DatafieldLength
            
            DatafieldStartAddressExcel = list(self.EasyExcelObject_1.getSpecificRange(StartRow,StartingAddressColumn,LastRowCommon,StartingAddressColumn))
            for counter in range(self.TotalNumberOfRowsFinal):
                self.DatafieldStartAddress.append(int(DatafieldStartAddressExcel[counter][0]))
            #print self.DatafieldStartAddress

            DatafieldDescriptionExcel = list(self.EasyExcelObject_1.getSpecificRange(StartRow,DescriptionColumn,LastRowCommon,DescriptionColumn))
            for counter in range(self.TotalNumberOfRowsFinal):
                self.DatafieldDescription.append(DatafieldDescriptionExcel[counter][0])
            #print self.DatafieldStartAddress

            DatafieldStartAddressHexExcel = list(self.EasyExcelObject_1.getSpecificRange(StartRow,StartingAddressHexColumn,LastRowCommon,StartingAddressHexColumn))
            for counter in range(self.TotalNumberOfRowsFinal):
                self.DatafieldStartAddressHex.append(DatafieldStartAddressHexExcel[counter][0])
            #print self.DatafieldStartAddress

            DatafieldRamShadowRequiredExcel = list(self.EasyExcelObject_1.getSpecificRange(StartRow,RamShadowRequiredColumn,LastRowCommon,RamShadowRequiredColumn))
            for counter in range(self.TotalNumberOfRowsFinal):
                self.DatafieldRamShadowRequired.append(DatafieldRamShadowRequiredExcel[counter][0])
            #print self.DatafieldStartAddress

            self.WorksheetName = self.EasyExcelObject_1.getValue(1, 2)
            self.WorksheetVersion= self.EasyExcelObject_1.getValue(2, 2)
            self.WorksheetDate = self.EasyExcelObject_1.getValue(3, 2)
            self.Partnumber = self.EasyExcelObject_1.getValue(6, 11)
            sys.stdout = self.logFileDes
            print "Worksheet Name = " , self.WorksheetName 
            print "Worksheet Version = " , self.WorksheetVersion
            print "Worksheet Date = " , self.WorksheetDate 
            print "Part Number = ", self.Partnumber
            print "EXCEL FILE SUCCESSFULLY INIT, Pl WAIT......"
            sys.stdout = sys.__stdout__
            print "Worksheet Name = " , self.WorksheetName 
            print "Worksheet Version = " , self.WorksheetVersion
            print "Worksheet Date = " , self.WorksheetDate 
            print "Part Number = ", self.Partnumber
            print "EXCEL FILE SUCCESSFULLY INIT, Pl WAIT......"
        
#===============================================================================
#            At the time of exception
#===============================================================================
        except:
            print "Closing due to problem"
            self.EasyExcelObject_1.close()


    def __del__(self):
        """
        destruct created instances.
        """
        self.EasyExcelObject_1.close()
        self.logFileDes.close()
       

    
    def createFileHeader(self):
        """
        To create the header information in the file.
        Please fill the information what you want to put in the file in the beginning.
        """
        import_file_desc_h = open('xml_header.txt', 'r')
        readlines = import_file_desc_h.read()
        replacedHeader = readlines.replace("-----------", str(self.Partnumber))
        replacedHeader = replacedHeader.replace("----", "0001")
        self.fileDesXmlData.write(replacedHeader)
        import_file_desc_h.close()
                

    def createFileFooter(self):
        """
        To create the footer information in the file.
        Please fill the information what you want to put in the file in the beginning.
        """
        import_file_desc_h = open('xml_footer.txt', 'r')
        readlines = import_file_desc_h.read()
        self.fileDesXmlData.write(readlines)
        import_file_desc_h.close()


    def createFileHeader_Pre(self):
        """
        To create the header information in the file.
        Please fill the information what you want to put in the file in the beginning.
        """
        import_file_desc_h = open('xml_header_pre.txt', 'r')
        readlines = import_file_desc_h.read()
        #replacedHeader = readlines.replace("-----------", str(self.Partnumber))
        #replacedHeader = replacedHeader.replace("----", "0001")
        self.fileDesXmlData_Pre.write(readlines)
        import_file_desc_h.close()
                

    def createFileFooter_Pre(self):
        """
        To create the footer information in the file.
        Please fill the information what you want to put in the file in the beginning.
        """
        import_file_desc_h = open('xml_footer_pre.txt', 'r')
        readlines = import_file_desc_h.read()
        self.fileDesXmlData_Pre.write(readlines)
        import_file_desc_h.close()

    
    def extractEepromWorkingSheetContents(self):
        config = ConfigParser.ConfigParser()
        config.read(self.OutputPath + '/' + "EepromLayoutSettingsFile.cfg")    

        StartRow = int(config.get("EEPROMLAYOUTPROPERIES", "StartingRow"))
        StartByteColumn = int(config.get("EEPROMLAYOUTPROPERIES", "StartByteColumn"))


        self.excelLinePropertiesList = []
        for counter in range(self.TotalNumberOfRowsFinal):
#===============================================================================
#                if ( self.DatafieldLength[counter] != None or
#                     self.DatafieldStartAddress[counter] == None):
#                    raise execption
#===============================================================================
                                
            if ( self.DatafieldLength[counter] != None and
                 self.DatafieldStartAddress[counter] != None):
                    #print self.DatafieldLength[counter]
                    byteContentsHex = []
                    byteContentsString = []
                    for length in range(int(self.DatafieldLength[counter])):
                        length_modified = length
                        if ( length > 40 ):
                            length_modified = 40                          
                        ByteValue = self.EasyExcelObject_1.getValue(StartRow+counter, StartByteColumn+length_modified)
                        if ( isinstance(ByteValue, float) == True):
                            ByteValueConverted = '0x' + str(ByteValue)[:-2]
                        elif (isinstance(ByteValue, unicode) == True):
                            ByteValueConverted = '0x' + ByteValue
                        elif (ByteValue == None):
                            ByteValueConverted = LastByteValue
                        LastByteValue = ByteValueConverted
                        byteContentsString.append(ByteValueConverted) #to store in xml file
                        byteContentsHex.append(int(ByteValueConverted, 16)) # to store in bin file.
            self.excelLinePropertiesList.append([self.DatafieldStartAddress[counter], self.DatafieldLength[counter], byteContentsString, byteContentsHex ])
        sys.stdout = self.logFileDes 
        for counter in range(self.TotalNumberOfRowsFinal):
            print "Address = ", hex(self.excelLinePropertiesList[counter][0])
            print "Length = ", self.excelLinePropertiesList[counter][1]
            print "BytesXml = ", self.excelLinePropertiesList[counter][2] 
            BytesBin = map ( hex, self.excelLinePropertiesList[counter][3])
            print "BytesBin = ", BytesBin
            print "NEXT"

        # Print to Console #
        sys.stdout = sys.__stdout__    
#        for counter in range(self.TotalNumberOfRowsFinal):
#            print "Address = ", hex(self.excelLinePropertiesList[counter][0])
#            print "Length = ", self.excelLinePropertiesList[counter][1]
#            print "BytesXml = ", self.excelLinePropertiesList[counter][2] 
#            BytesBin = map ( hex, self.excelLinePropertiesList[counter][3])
#            print "BytesBin = ", BytesBin
#            print "NEXT"

    
    def generateEepromBinData(self):
        """
        """
        #===============================================================================
        #    Generate  ENUMS.
        #===============================================================================
        self.CalculatedCrc = 0
        self.byteContentsString = []
        curdir = os.getcwd()
        fileDesEeprom = open(self.OutputPath+"/PROD/BIN/"+self.WorksheetName+'_'+self.WorksheetVersion+ '_' + self.WorksheetDate +  '.bin', "wb")
        for counter in range(self.TotalNumberOfRows):
            for x in range(len(self.excelLinePropertiesListFinal[counter][3])):
                data = struct.pack("B", self.excelLinePropertiesListFinal[counter][3][x])
                fileDesEeprom.write(data)
                fileDesEeprom.flush()
        fileDesEeprom.close()
        fileDesEeprom = open(self.OutputPath+"/PROD/BIN/"+self.WorksheetName+'_'+self.WorksheetVersion+ '_' + self.WorksheetDate +  '.bin', "rb")
        value = fileDesEeprom.read()
        for counter in range (2048/32):
            for x in range (32):
                data = struct.unpack("B", value[32*counter + x])
                self.CalculatedCrc = self.CalculatedCrc + data[0]
            self.CalculatedCrc = self.CalculatedCrc ^ 9281
        fileDesEeprom.close()
        print hex(self.CalculatedCrc)

    def generateXmlData(self):
        curdir = os.getcwd()
        self.fileDesXmlData = open(self.OutputPath+"/PROD/XML/" +self.WorksheetName+'_'+self.WorksheetVersion+ '_' + self.WorksheetDate + 'VAS5163.xml', 'w')
        self.createFileHeader()
        self.fileDesXmlData.write('\n')
        for counter in range(self.TotalNumberOfRows):
            for x in range( len(self.excelLinePropertiesListFinal[counter][2])):
                #self.fileDesXmlData.write(self.excelLinePropertiesListFinal[counter][2][x])
                self.fileDesXmlData.write( unicode( "0x%02X" % int(self.excelLinePropertiesListFinal[counter][3][x])))
                self.fileDesXmlData.write(',\n')

	if checksumType == "calc":
	    self.fileDesXmlData.write ( ("0x%02X,\n" % (( self.CalculatedCrc >> 32 ) & 0xFF )))
	    self.fileDesXmlData.write ( ("0x%02X,\n" % ((self.CalculatedCrc >> 16 ) & 0xFF )))
	    self.fileDesXmlData.write ( ("0x%02X,\n" % ((self.CalculatedCrc >> 8 ) & 0xFF )))
	    self.fileDesXmlData.write ( ("0x%02X\n" % (self.CalculatedCrc & 0xFF )))
	elif checksumType == "predefined":
	    self.fileDesXmlData.write('0x12,\n0x34\n')

        self.createFileFooter()
        self.fileDesXmlData.close()
        #print self.excelLinePropertiesListFinal
    
       
    def generateXmlData_Pre(self):
        curdir = os.getcwd()
        self.fileDesXmlData_Pre = open(self.OutputPath+"/PROD/XML/" +self.WorksheetName+'_'+self.WorksheetVersion+ '_' + self.WorksheetDate + '.xml', 'w')
        self.createFileHeader_Pre()
        self.fileDesXmlData_Pre.write('\n')
        for counter in range(self.TotalNumberOfRows):
            for x in range( len(self.excelLinePropertiesListFinal[counter][2])):
                #self.fileDesXmlData.write(self.excelLinePropertiesListFinal[counter][2][x])
                self.fileDesXmlData_Pre.write( unicode( "0x%02X" % int(self.excelLinePropertiesListFinal[counter][3][x])))
                self.fileDesXmlData_Pre.write(',\n')

	if checksumType == "calc":
	    self.fileDesXmlData_Pre.write ( ("0x%02X,\n" % (( self.CalculatedCrc >> 32 ) & 0xFF )))
	    self.fileDesXmlData_Pre.write ( ("0x%02X,\n" % ((self.CalculatedCrc >> 16 ) & 0xFF )))
	    self.fileDesXmlData_Pre.write ( ("0x%02X,\n" % ((self.CalculatedCrc >> 8 ) & 0xFF )))
	    self.fileDesXmlData_Pre.write ( ("0x%02X\n" % (self.CalculatedCrc & 0xFF )))
	elif checksumType == "predefined":
	    self.fileDesXmlData_Pre.write('0x12,\n0x34\n')

        self.createFileFooter_Pre()
        self.fileDesXmlData_Pre.close()
        #print self.excelLinePropertiesListFinal

    
    def createDeltaSheets(self):
        for counter in range(self.TotalNumberOfRowsDeltaSheet):
            i = 0
            found = True
            while ( (self.excelLinePropertiesList[counter][0] != self.excelLinePropertiesListBasis[i][0])):
                i = i + 1
                if ( i == self.TotalNumberOfRows ) :
                    found = False
                    break
            if ( found == True ):
                if ( self.excelLinePropertiesList[counter][1] != self.excelLinePropertiesListBasis[i][1]):
                    print "Length is not the same.. abort generation"
                    raise KeyError
                else:
                    self.excelLinePropertiesListFinal[i][2] = self.excelLinePropertiesList[counter][2] # copy for XML
                    self.excelLinePropertiesListFinal[i][3] = self.excelLinePropertiesList[counter][3] # copy for BIN
            else:
                print "Abort Generation. Error in Excel sheet"
                raise KeyError
    
    def saveBasisDataValues(self):
        self.excelLinePropertiesListBasis = self.excelLinePropertiesList
        self.excelLinePropertiesListFinal = self.excelLinePropertiesList
        
    def printAllModuleVariables(self):
        #===============================================================================
        #    Print Tables
        #===============================================================================
        print "-------------------------------------------"
        print "Total Number of Rows = %d" %self.TotalNumberOfRowsFinal
        print self.DatafieldLength
        print self.DatafieldStartAddress
        print "-------------------------------------------"
       

    def generateEepromLayoutAddressHeaderFile(self, ProjectName):
        #===============================================================================
        #    Generate Header Files
        #===============================================================================
        fd = open("EEPROM_LAYOUT_generated_ADR.h", "w")
        fd5 = open("import_file_h_address.txt", "r")
        fd.write(fd5.read())
        fd.write('\n\n\n\n')
        
        for counter in range(self.TotalNumberOfRowsFinal):
            startpoint = fd.tell()
            if ( ProjectName == "SCM"):
                fd.write('#define          FODB_EE_ADDDRESS_')
            elif ( ProjectName == "UHV"):
                fd.write('#define          VWDB_EE_ADDDRESS_')
            elif ( ProjectName == "ADR"):
                fd.write('#define          PAG_DB_EE_ADDRESS_')
                
            fd.write(self.DatafieldDescription[counter].encode('utf-8').rstrip(' '))
            fd.write('                                                                                                               ')

            fd.seek(startpoint)
            y = fd.seek(100,1)
            fd.write('0x'+str(self.DatafieldStartAddressHex[counter]) + 'u')
            fd.write('\n')
            
            startpoint = fd.tell()
            if ( ProjectName == "SCM"):
                fd.write('#define          FODB_EE_ADDDRESS_')
            elif ( ProjectName == "UHV"):
                fd.write('#define          VWDB_EE_ADDDRESS_')
            elif ( ProjectName == "ADR"):
                fd.write('#define          PAG_DB_EE_ADDRESS_')
            fd.write(self.DatafieldDescription[counter].encode('utf-8').rstrip(' ')+'_LEN')
            fd.write('                                                                                                               ')
            
            fd.seek(startpoint)
            y = fd.seek(105,1)
            fd.write(str(self.DatafieldLength[counter]) + 'u')
            fd.write('\n')
        fd.write('\n#endif /* _EEPROM_LAYOUT_GENERATED_ADR_H */\n')
        fd.write('/* End Of File EEPROM_LAYOUT_generated_ADR.h */\n')

        fd.close()
        
      
    def findFragmentation(self):
        # Y -> N -> Y transition in a Block is not allowed !
        BlockNrOld = 0
        OffsetOld = 0
        LenOld = 0
        LastAddedBlockNr = -1
        IsAllowedOld = 'N'
        SIZEOF_EE_PAGE = 32
        Fragmentation = False
        StartRow = int(config.get("EEPROMLAYOUTPROPERIES", "StartingRow"))
        for counter in range(self.TotalNumberOfRowsFinal):
            IsAllowed = self.DatafieldRamShadowRequired[counter]
            BlockNr = self.DatafieldStartAddress[counter]/SIZEOF_EE_PAGE
            Offset = self.DatafieldStartAddress[counter]%SIZEOF_EE_PAGE
            Len = self.DatafieldLength[counter]
            if ( (IsAllowed == 'Y') ):
#                if ( (Len) > 32 ):
#                    str1 = "Currently cannot deal with Length for more than 32 Bytes at Line Number " + str( counter + StartRow ) + ", \
#                    Aborting Generation.. To solve this please divide the line into multiple blocks with less than or equal to 32 bytes in each line."
#                    str2 = "EEPROM_RamMirror"
#                    ctypes.windll.user32.MessageBoxA(None, str1, str2, 0)
#                    raise KeyError
                if ( (BlockNrOld == BlockNr) and (Fragmentation == True )):
                    str1 = "Fragments in the E2P Layout in Line Number " + str( counter + StartRow - 1 ) + ", Aborting Generation.. \nTo solve this please write Y instead of N at this line number."
                    str2 = "EEPROM_RamMirror"
                    ctypes.windll.user32.MessageBoxA(None, str1, str2, 0)
                    raise KeyError
                if ( (BlockNrOld != BlockNr) or ( LastAddedBlockNr != BlockNr ) ): 
                    Fragmentation = False
                LastAddedBlockNr = BlockNr
            else:
                if  ((OffsetOld + LenOld > 32 ) and (IsAllowedOld == 'Y') and ( Offset != 0 ) ):
                    LastAddedBlockNr = BlockNr
                if ( LastAddedBlockNr == BlockNr ):
                    Fragmentation = True
                else:
                    Fragmentation = False
            OffsetOld = Offset
            LenOld = Len
            IsAllowedOld = IsAllowed
            BlockNrOld = BlockNr


    def generateInitEepromBlockTable(self):
        
        BlockNrOld = 0
        OffsetOld = 0
        LenOld = 0
        IsAllowedOld = 'N'
        SIZEOF_EE_PAGE = 32
        self.eeprom_block_download_list = []
        for x in range(64):
            self.eeprom_block_download_list.append(-1)
        for counter in range(self.TotalNumberOfRowsFinal):
            IsAllowed = self.DatafieldRamShadowRequired[counter]
            BlockNr = self.DatafieldStartAddress[counter]/SIZEOF_EE_PAGE
            Offset = self.DatafieldStartAddress[counter]%SIZEOF_EE_PAGE
            Len = self.DatafieldLength[counter]
            if ( (IsAllowed == 'Y') ):
                offsetCounter = Offset + Len
                counter = 0
                while ( True ):
                    self.eeprom_block_download_list[BlockNr+counter] = 1
                    counter = counter + 1
                    offsetCounter = offsetCounter - 32
                    if ( offsetCounter <= 0 ):
                        break
            OffsetOld = Offset
            LenOld = Len
            IsAllowedOld = IsAllowed
            BlockNrOld = BlockNr

        for x in range(64):
            if ( self.eeprom_block_download_list[x] == -1 ):
                 self.eeprom_block_download_list[x] = 0 
                      
        fd_final = open("TEMP_EEPROM_LAYOUT_generated_INIT.h", "w")

        fd_final.write('#define EEPROM_RAMBLOCK_NOTDEFINED 255')
        fd_final.write('\n\n\n\n')
        
        fd_final.write('#define SIZEOF_EE_PAGE 32')
        fd_final.write('\n\n\n\n')

        for count in range(64):
            fd_final.write('#define EEPROM_RAMBLOCK_' + str(count) + '  ' + str(count) + '\n')
        fd_final.write('\n\n\n\n')

        for count in range(64):
            fd_final.write('#define EEPROM_BLOCK_' + str(count) + '  ' + str(count) + '\n')
        fd_final.write('\n\n\n\n')

        fd_final.write('#define INIT_BLOCK_0_31    \\\n')
        for count in range(32):
            fd_final.write(str(self.eeprom_block_download_list[count]) + '<<' + 'EEPROM_BLOCK_' + str(count) + ' ')
            if ( count != 31 ):
                fd_final.write('|' + '\\\n')
        fd_final.write('\n\n\n\n')

        fd_final.write('#define INIT_BLOCK_32_63    \\\n')
        for count in range(32):
            fd_final.write(str(self.eeprom_block_download_list[count+32]) + '<<' + '(EEPROM_BLOCK_' + str(count+32) + ' - SIZEOF_EE_PAGE)' + ' ')
            if ( count != 31 ):
                fd_final.write('|' + '\\\n')
        fd_final.write('\n\n\n\n')

        fd_final.write('#define RAMBLOCK_TO_E2PBLOCK_MAP    \\\n')
        x = 0
        for count in range(64):
            if ( self.eeprom_block_download_list[count] == 1):
                fd_final.write('EEPROM_RAMBLOCK_' + str(x) + ',\\\n')
                x = x+1
            else:
                fd_final.write('EEPROM_RAMBLOCK_NOTDEFINED' + ',\\\n')
        
        fd_final.write('\n\n\n\n')
        fd_final.close()

    def generateEepromLayoutEnumFile(self):

        fd2 = open("EEPROM_LAYOUT_generated_ENUM.h", "w")
        fd2.write('typedef enum\n{\n')
        IsAllowedOld = 'N'
        enumcount = 0
        for counter in range(self.TotalNumberOfRowsFinal):
            IsAllowed = self.DatafieldRamShadowRequired[counter]
            enum = 'EEPROM_LAYOUT_ENUM_' + self.DatafieldDescription[counter].encode('utf-8').rstrip(' ')
            if ( (IsAllowed == 'Y') ):
                fd2.write('/*' + str(enumcount) + '*/ '+ enum + ',')
                fd2.write('\n')
                enumcount = enumcount + 1
        self.total_enum = enumcount
        print "Total Enum" , self.total_enum
        fd2.write('ENUM_EEPROM_LAYOUT_MAX\n} EEPROM_ENUM_GET_EEPROM; //EEPROM_LAYOUT_ENUM_ALL_ELEMENTS;\n')
        fd2.close()
        

    def generateInitEepromMapEnumWithEepromBlock(self):

        fd3 = open("TEMP_EEPROM_LAYOUT_generated_BLOCK.h", "w")
        SIZEOF_EE_PAGE = 32
        enumcount = 0
        x = 0
        LastAddedBlockNr = 0
        self.mapEnumWithBlockNumber_list = []
        self.mapEnumWithRamBlockNumber_list = []
        for enumcount in range(self.total_enum):
            self.mapEnumWithBlockNumber_list.append(-1)
            self.mapEnumWithRamBlockNumber_list.append(-1)
        enumcount = 0
        for counter in range(self.TotalNumberOfRowsFinal):
            IsAllowed = self.DatafieldRamShadowRequired[counter]
            BlockNr = self.DatafieldStartAddress[counter]/SIZEOF_EE_PAGE
            if ( (IsAllowed == 'Y') ):
                self.mapEnumWithBlockNumber_list[enumcount] = BlockNr
                count = BlockNr - LastAddedBlockNr
                for y in range(count):
                    if ( self.eeprom_block_download_list[LastAddedBlockNr + y] == 1 ):
                        x = x + 1
                fd3.write('/*' + str(enumcount) + '*/ '+ '  EEPROM_BLOCK_' + str(self.mapEnumWithBlockNumber_list[enumcount]) +   ',\\')
                fd3.write('\n')
                self.mapEnumWithRamBlockNumber_list[enumcount] = x
                LastAddedBlockNr = BlockNr
                enumcount = enumcount + 1

        fd3.close()

                
    def generateEepromMappingTableCompact(self):
        fd1 = open("TEMP_EEPROM_LAYOUT_generated_MAP.h", "w")
        
        BlockNrOld = 0
        OffsetOld = 0
        LenOld = 0
        SIZEOF_EE_PAGE = 32
        enumcount = 0
        for counter in range(self.TotalNumberOfRowsFinal):
            IsAllowed = self.DatafieldRamShadowRequired[counter]
            enum = 'EEPROM_LAYOUT_ENUM_' + self.DatafieldDescription[counter].encode('utf-8').rstrip(' ')
            BlockNr = self.DatafieldStartAddress[counter]/SIZEOF_EE_PAGE
            Offset = self.DatafieldStartAddress[counter]%SIZEOF_EE_PAGE
            Len = self.DatafieldLength[counter]
            if ( (IsAllowed == 'Y') ):
                startpoint = fd1.tell()
                fd1.write('                                                                                                                                                                        ')
                fd1.seek(startpoint)
                y = fd1.seek(0,1)
                fd1.write('/*' + str(enumcount) + '  EEPROM_BLOCK_' + str(BlockNr)+  ' , ' + enum + '*/')
                fd1.seek(startpoint)
                y = fd1.seek(100,1)
                fd1.write('{' + str(Offset) + ',')
                fd1.seek(startpoint)
                y = fd1.seek(110,1)
                fd1.write('EEPROM_RAMBLOCK_' + str(self.mapEnumWithRamBlockNumber_list[enumcount]) + ',')
                fd1.seek(startpoint)
                y = fd1.seek(145,1)
                fd1.write(str(Len) + '},\\')
                fd1.write('\n')
                enumcount = enumcount + 1
            BlockNrOld = BlockNr
            OffsetOld = Offset
            LenOld = Len
                      
        fd1.close()

        fd2 = open("EEPROM_LAYOUT_generated_ENUM.h", "a")
        fd2.write('\n\n\n\n')
        fd2.write('#define RAM_BLOCK_COUNT    ' + str(self.mapEnumWithRamBlockNumber_list[self.total_enum - 1]+1))
        fd2.write('\n\n')
        fd2.close()
        
        fd1 = open("TEMP_EEPROM_LAYOUT_generated_MAP.h", "r")
        fd2 = open("EEPROM_LAYOUT_generated_ENUM.h", "r")
        fd3 = open("TEMP_EEPROM_LAYOUT_generated_BLOCK.h", "r")
        fd4 = open("TEMP_EEPROM_LAYOUT_generated_INIT.h", "r")
        fd5 = open("import_file_h.txt", "r")
        
        fd_final = open("EEPROM_LAYOUT_generated_H1.h", "w")

        fd_final.write(fd5.read())
        fd_final.write('\n\n\n\n')

        fd_final.write(fd4.read())
        
        fd_final.write('#define EEPROM_OFFSET_TABLE \\\n')
        fd_final.write(fd1.read())
        fd_final.write('\n\n\n\n')
        
        fd_final.write('#define EEPROM_BLOCK_DETAILS \\\n')
        fd_final.write(fd3.read())
        fd_final.write('\n\n\n\n')
        
        fd_final.write('\n#endif /* _EEPROM_LAYOUT_GENERATED_HI_H */\n')
        fd_final.write('/* End Of File EEPROM_LAYOUT_generated_H1.h */\n')
        
        fd_final.close()

        fd1.close()
        fd2.close()
        fd3.close()
        fd4.close()
        fd5.close()
        
        os.system("del TEMP*.h")         

    def generateEepromMappingTableOffset(self):
        fd6 = open("TEMP_EEPROM_LAYOUT_generated_OFFSET_0_31.h", "w")
        fd7 = open("TEMP_EEPROM_LAYOUT_generated_LENGTH_0_31.h", "w")
        fd8 = open("TEMP_EEPROM_LAYOUT_generated_OFFSET_32_63.h", "w")
        fd9 = open("TEMP_EEPROM_LAYOUT_generated_LENGTH_32_63.h", "w")
        
        StartRow = int(config.get("EEPROMLAYOUTPROPERIES", "StartingRow"))
        
        BlockNrOld = 0
        OffsetOld = 0
        LenOld = 0
        LastAddedBlockNr = -1
        IsAllowedOld = 'N'
        FindLengthMask = False
        PreventBlockGeneration = 0
        SIZEOF_EE_PAGE = 32
        self.offset_list = []
        self.length_list = []
        for enumcount in range(64):
            self.offset_list.append(-1)
            self.length_list.append(-1)
        enumcount = 0
        for counter in range(self.TotalNumberOfRowsFinal):
            IsAllowed = self.DatafieldRamShadowRequired[counter]
            BlockNr = self.DatafieldStartAddress[counter]/SIZEOF_EE_PAGE                
            Offset = self.DatafieldStartAddress[counter]%SIZEOF_EE_PAGE
            Len = self.DatafieldLength[counter]
            enum = 'EEPROM_LAYOUT_ENUM_' + self.DatafieldDescription[counter].encode('utf-8').rstrip(' ')
            if ( IsAllowed == 'Y' ):                    
                if ( self.offset_list[BlockNr] == -1  ): 
                    self.offset_list[BlockNr] = Offset
                offsetCounter = Offset + Len
                tempBlockNr = BlockNr
                while ( True ) :
                    if ( (Offset + Len) >= 32 ):
                        if ( offsetCounter > 32 ):
                            self.offset_list[tempBlockNr + 1] = 0
                        self.length_list[tempBlockNr] = 32 - self.offset_list[tempBlockNr]
                        offsetCounter = offsetCounter - 32
                        tempBlockNr = tempBlockNr + 1
                    if ( offsetCounter < 32 ):
                        break

            elif ( IsAllowed == 'N' and BlockNrOld == BlockNr):
                if (self.offset_list[BlockNr] != -1 ):
                    if ( self.length_list[BlockNr] == -1 ):
                        self.length_list[BlockNr] = OffsetOld + LenOld - self.offset_list[BlockNr]
                
            elif ( IsAllowed == 'N' and BlockNrOld != BlockNr ): 
                if ( self.offset_list[BlockNr] != -1 ):
                    self.length_list[BlockNr] = OffsetOld + LenOld - (32 * (BlockNr - BlockNrOld))
                


            OffsetOld = Offset
            LenOld = Len
            IsAllowedOld = IsAllowed
            BlockNrOld = BlockNr  
        

        
        fd6 = open("TEMP_EEPROM_LAYOUT_generated_OFFSET_0_31.h", "w")
        fd7 = open("TEMP_EEPROM_LAYOUT_generated_LENGTH_0_31.h", "w")
        fd8 = open("TEMP_EEPROM_LAYOUT_generated_OFFSET_32_63.h", "w")
        fd9 = open("TEMP_EEPROM_LAYOUT_generated_LENGTH_32_63.h", "w")
        fd_final = open("EEPROM_LAYOUT_generated_H2.h", "w")

        for count in range(64):
            if ( count < 32 ):
                if ( self.eeprom_block_download_list[count] == 1 ):
                    if ( self.offset_list[count] == 0 ):
                       fd6.write("/* Y_0 if ( i == " +  str(count) + " )  {\tOffset = " + str(self.offset_list[count]) + ";\t} */ \\\n" )
                    else:
                       fd6.write("/* Y */ if ( i == " +  str(count) + " )  {\tOffset = " + str(self.offset_list[count]) + ";\t} \\\n" ) 
            else:
                if ( self.eeprom_block_download_list[count] == 1 ):
                    if ( self.offset_list[count] == 0 ):
                       fd8.write("/* Y_0 if ( i == " +  str(count) + " )  {\tOffset = " + str(self.offset_list[count]) + ";\t} */ \\\n" )
                    else:
                       fd8.write("/* Y */ if ( i == " +  str(count) + " )  {\tOffset = " + str(self.offset_list[count]) + ";\t} \\\n" ) 

        for count in range(64):
            if ( count < 32 ):
                if ( self.eeprom_block_download_list[count] == 1 ):
                    if ( self.length_list[count] == 32 ):
                        fd7.write("/* Y if ( i == " +  str(count) + " )  {\tLength = " + str(self.length_list[count]) + ";\t} */ \\\n" )
                    else:
                        fd7.write("/* Y */ if ( i == " +  str(count) + " )  {\tLength = " + str(self.length_list[count]) + ";\t} \\\n" )
            else:
                if ( self.eeprom_block_download_list[count] == 1 ):
                    if ( self.length_list[count] == 32 ):
                        fd9.write("/* Y if ( i == " +  str(count) + " )  {\tLength = " + str(self.length_list[count]) + ";\t} */ \\\n" )
                    else:
                        fd9.write("/* Y */ if ( i == " +  str(count) + " )  {\tLength = " + str(self.length_list[count]) + ";\t} \\\n" )

        fd6.close()
        fd7.close()        
        fd8.close()
        fd9.close()        
        
        fd6 = open("TEMP_EEPROM_LAYOUT_generated_OFFSET_0_31.h", "r")
        fd7 = open("TEMP_EEPROM_LAYOUT_generated_LENGTH_0_31.h", "r")
        fd8 = open("TEMP_EEPROM_LAYOUT_generated_OFFSET_32_63.h", "r")
        fd9 = open("TEMP_EEPROM_LAYOUT_generated_LENGTH_32_63.h", "r")

        fd_final.write('#define EEPROM_LAYOUT_OFFSET_MASK_0_31 \\\n')
        fd_final.write(fd6.read())
        fd_final.write('\n\n\n\n')

        fd_final.write('#define EEPROM_LAYOUT_OFFSET_MASK_32_63 \\\n')
        fd_final.write(fd8.read())
        fd_final.write('\n\n\n\n')

        fd_final.write('#define EEPROM_LAYOUT_LENGTH_MASK_0_31 \\\n')
        fd_final.write(fd7.read())
        fd_final.write('\n\n\n\n')

        fd_final.write('#define EEPROM_LAYOUT_LENGTH_MASK_32_63 \\\n')
        fd_final.write(fd9.read())
        fd_final.write('\n\n\n\n')
        
        fd_final.write('/* End Of File EEPROM_LAYOUT_generated_H2.h */\n')
        
        fd_final.close()

        fd6.close()
        fd7.close()
        fd8.close()
        fd9.close()
        
        os.system("del TEMP*.h")

    def consistencyCheck(self):
        for count in range ( 64 ):
            if ( self.eeprom_block_download_list[count] == 1 ):
                if ( self.offset_list[count] > 31 or self.length_list[count]  > 32  ):
                    str1 = "Fatal Error in genrating for Block Nr " + str( count ) + ", \
                    Aborting Generation.. Please check for Offset and Length in this block number."
                    str2 = "EEPROM_RamMirror"
                    ctypes.windll.user32.MessageBoxA(None, str1, str2, 0)
                    raise KeyError
                if ( self.offset_list[count] < 0 or self.length_list[count]  < 0  ):
                    str1 = "Fatal Error in genrating for Block Nr " + str( count ) + ", \
                    Aborting Generation.. Please check for Offset and Length in this block number."
                    str2 = "EEPROM_RamMirror"
                    ctypes.windll.user32.MessageBoxA(None, str1, str2, 0)
                    raise KeyError
        if ( self.mapEnumWithBlockNumber_list[self.total_enum-1] > 63 and self.mapEnumWithBlockNumber_list[self.total_enum-1] < 0):
            raise KeyError
        
              
    
if __name__ == '__main__':

    description=""" Hello tool """     
    parser = optparse.OptionParser( usage="%prog [options] directory", version="%prog "+ script_version, description=description )
    #parser.add_option( "-t", "--test",  action="store_true", dest="test",  default=False, help="Test-only. Don't create a tag" )
    #parser.add_option( "-d", "--debug", action="store_true", dest="debug", default=False, help="Debugging output" )
    parser.add_option( "-g", "--generate", action="store_true", dest="generate", default=False, help="Generate header file only" )
    (options, args ) = parser.parse_args()
    
    UserInterface = __import__('EepromLayoutSettingsFile')
    developmentMode = UserInterface.developmentMode
    for x in range(2):
        if ( developmentMode == True ):
            if ( x == 0 ):
                InputExcelFilePath = UserInterface.InputExcelFilePath_Project1 
                OutputPath = UserInterface.OutputPath_Project1
            elif ( x == 1 ):
                InputExcelFilePath = UserInterface.InputExcelFilePath_Project2 
                OutputPath = UserInterface.OutputPath_Project2
        try:
            InputExcelFilePath = args[0]
        except:
            print "Excel file path: <%s>" % InputExcelFilePath
            IsRelativePath = 0
            Outputpath = OutputPath
            print "output path: <%s>" % Outputpath
        else:
            print "Excel file path: <%s>" % InputExcelFilePath
            isRelativePath = 1
            Outputpath = os.path.dirname( InputExcelFilePath )
            print "output path: <%s>" % Outputpath 
    
        GenerateHeaderFile = options.generate
        config = ConfigParser.ConfigParser()
        config.read(Outputpath + '/' + "EepromLayoutSettingsFile.cfg")
        SheetsToGenerate = config.items("VARIANTS_TO_GENERATE")
        #ProjectToGenerate = config.items("PROJECT")
        #CurrentProject = ProjectToGenerate["name"][1]
        #print "current project: <%s> (%s)" % (CurrentProject, ProjectToGenerate)
	
        CurrentProject = config.get( "PROJECT", "name" )
        print "current project: <%s>" % CurrentProject

	try:
	    checksumType = config.get( "PROJECT", "Checksum" )
	except ConfigParser.NoOptionError:
	    checksumType = "calc"
	    
	print "project checksum type: <%s>" % checksumType
	
        if ( developmentMode == True ):
            value = "START"
        else:
            print "Please type START" 
            value = raw_input()
        value = value.replace('\r' , '')
        i = 0
        
        if (( value == "START")== True):
	    if "%s_EEPROM_DS.xls" % CurrentProject in InputExcelFilePath:
                UHVClassObjectEepromDataConversion = UHVEepromDataConversion(InputExcelFilePath, Outputpath)
                UHVClassObjectEepromDataConversion.initialiseExcelSheet_1('BASIS_DS', 3)
                UHVClassObjectEepromDataConversion.extractEepromWorkingSheetContents()
                UHVClassObjectEepromDataConversion.saveBasisDataValues()
                if ( GenerateHeaderFile == True):
                    UHVClassObjectEepromDataConversion.findFragmentation()
                    UHVClassObjectEepromDataConversion.generateEepromLayoutAddressHeaderFile(CurrentProject)
                    UHVClassObjectEepromDataConversion.generateEepromLayoutEnumFile()
                    UHVClassObjectEepromDataConversion.generateInitEepromBlockTable()
                    UHVClassObjectEepromDataConversion.generateInitEepromMapEnumWithEepromBlock()
                    UHVClassObjectEepromDataConversion.generateEepromMappingTableCompact()
                    UHVClassObjectEepromDataConversion.generateEepromMappingTableOffset()
                    UHVClassObjectEepromDataConversion.consistencyCheck()
                else:
                    for counter in range( len(SheetsToGenerate)): 
                        value = string.upper(SheetsToGenerate[counter][0])
                        worksheetNumber = int(SheetsToGenerate[counter][1])
                        UHVClassObjectEepromDataConversion.initialiseExcelSheet_1(value, worksheetNumber)
                        UHVClassObjectEepromDataConversion.extractEepromWorkingSheetContents()
                        UHVClassObjectEepromDataConversion.createDeltaSheets()
                        UHVClassObjectEepromDataConversion.generateEepromBinData()
                        UHVClassObjectEepromDataConversion.generateXmlData()
                        UHVClassObjectEepromDataConversion.generateXmlData_Pre()
                        i = i + 1
                
                UHVClassObjectEepromDataConversion.__del__()
            else:
                print "VARIANT NOT SUPPORTED or WRONG Excel File"
                break
            if ( developmentMode == True ):
                if ( x == 0):
                    instanceFileCmp = filecmp.dircmp(".", r"F:\MyDocuments\workspace\eclipse\FORD_SOP1\MOD\MOD_EEPROM_LAYOUT_CFG\inc\\", [".svn"])
                    Value = instanceFileCmp.diff_files
                    print "Unidentical Files " , Value        
                    if ( len(Value) != 0):
                        str1 = "Ford Files nicht gleich !"
                        str2 = "EEPROM_RamMirror" 
                        ctypes.windll.user32.MessageBoxA(None, str1, str2, 0)
                        raise KeyError
                    else:
                        pass
                elif ( x == 1):
                    instanceFileCmp = filecmp.dircmp(".", r"F:\MyDocuments\workspace\eclipse\UHV_SOP2_DEV\MOD\MOD_EEPROM_LAYOUT_CFG\inc\\")        
                    Value = instanceFileCmp.diff_files
                    print "Unidentical Files " , Value        
                    if ( len(Value) != 0):
                        str1 = "VW Files nicht gleich !"
                        str2 = "EEPROM_RamMirror"
                        ctypes.windll.user32.MessageBoxA(None, str1, str2, 0)
                        raise KeyError
                    else:
                        pass
            else:
                print 'END with generated sheets = ', i
                break
        else:
            print "Please type START"  
    
        print 'END with generated sheets = ', i
    os.system("pause")
        
            
    

# End Of File Conversion_Text_Prompts.py
