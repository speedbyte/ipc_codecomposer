""" 


    $Date: 2009-06-23 15:46:24 +0200 (Di, 23 Jun 2009) $
    $Rev: 6848 $
    $Author: agrawal $
    $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/TOOLS/Python_scripts/trunk/DiagnoseScript/XML2Bin.py $

    Copyright (c) 2008 S1nn GmbH & Co. KG.
    All Rights Reserved.

"""

_svn_id = "$Id$"
_svn_rev = "$Rev: 6848 $"
__version__ = _svn_rev[6:-2]

import os
import sys
import struct

class parseXmlFile(object):
    def __init__(self, xmlFileName = "xyz.xml"):
        import elementtree.ElementTree as ET
        self.et = ET.ElementTree(file = xmlFileName)

    def createBinFile(self):
        datasets = self.et.getiterator("DATA")
        print datasets
        i = 0
        for dataset in datasets:
            i += 1
            self.filename = "binFromXML_%i.bin" % i
            file = open(self.filename, "wb")    
        
            for data in dataset.getiterator("PARAMETER_DATA"):
                values = data.text.replace("\n","").strip().split(",")
                ints = []
                for val in values:
                    file.write(struct.pack("B", int(val.strip(),16)))
            file.close()
            
    def parseOdxFile(self):
        ptrToDtcElements = self.et.getiterator("DTC")
        print ptrToDtcElements
        i = 0
        for dataset in ptrToDtcElements:
            xyz = dataset.getiterator("TROUBLE-CODE")
            for data in xyz:
                #print data
                print hex(int(data.text, 10))
                #print data.text
            xyz = dataset.getiterator("DISPLAY-TROUBLE-CODE")
            for data in xyz:
                #print data
                #print hex(int(data.text, 10))
                print data.text
            xyz = dataset.getiterator("TEXT")
            for data in xyz:
                #print data
                #print hex(int(data.text, 10))
                dtcDefines = self.convertIntoCSpecificLang(data.text)
                print dtcDefines
            xyz = dataset.getiterator("LEVEL")
            for data in xyz:
                #print data
                #print hex(int(data.text, 10))
                print data.text
            xyz = dataset.getiterator("SDG")
            for data in xyz:
                #print data
                #print hex(int(data.text, 10))
                data1 = data.getiterator("SD SI=\"Entstoerzeit\"")
                print data1
                print data1[0].text
                
    def parseSourceMonitorXmlFile(self):
        ptrToDtcElements = self.et.getiterator("file")
        outputFile = open("temp.txt", 'w')
        #print ptrToDtcElements
        i = 0
        for dataset in ptrToDtcElements:
            fileName = dataset.get("file_name")
            fileName = fileName.replace('debug\\', '')
            xyz = dataset.getiterator("function")
            for data in xyz:
                outputFile.write(fileName)
                outputFile.write(', ')
                fnName = data.get('name')
                outputFile.write(fnName)
                outputFile.write('\n')
        outputFile.close()
                
    def convertIntoCSpecificLang(self, rawText):
        strVal = rawText.upper()
        strVal = strVal.rstrip(' ')
        strVal = strVal.replace(',', '')
        strVal = strVal.replace(' ', '_')
        strVal = strVal.replace('(','')
        strVal = strVal.replace(')','')
        strVal = strVal.replace('-' , '')
        strVal = strVal.replace('/' , '')
        
        return strVal
    
    def padBinFile(self):
        file = open(self.filename, "ab")
        ActualSizeOfFile = os.path.getsize(self.filename)
        PreferredSizeOfFile = 2048
        PadBytesInFile = PreferredSizeOfFile - ActualSizeOfFile
        for x in range(PadBytesInFile):
            file.write(struct.pack("B", 0xDE))
            PadBytesInFile -= 1
            if ( PadBytesInFile == 0):
                break
            file.write(struct.pack("B", 0xAD))
            PadBytesInFile -= 1
            if ( PadBytesInFile == 0):
                break
            file.write(struct.pack("B", 0xBE))
            PadBytesInFile -= 1
            if ( PadBytesInFile == 0):
                break
            file.write(struct.pack("B", 0xEF))
            PadBytesInFile -= 1
            if ( PadBytesInFile == 0):
                break
        file.close()
    
    def convertInFormats(self):
        ioutfile = "intelhexFromXML_%i.hex" % i
        soutfile = "s19FromXML_%i.s19" % i
        os.execl("./srec_cat.exe", "srec_cat.exe", "%s -Binary" % filename, "-output %s" % ioutfile, "-Intel")
        os.execl("./srec_cat.exe", "srec_cat.exe", "%s -Binary" % filename, "-output %s" % soutfile, "-Motorola")

if ( __name__ == '__main__'):
    #XML2BinObject = parseXmlFile('F:\MyDocuments\workspace\eclipse\SYS_VW_UHV_NAR_TMS470\TOOLS\Python_scripts\DiagnoseScript\PRG_77_UHV_EEPROM_VW_VAS5163.xml')
    #XML2BinObject.createBinFile()
    ##XML2BinObject.padBinFile()
    #XML2BinObject2 = parseXmlFile('F:\MyDocuments\workspace\eclipse\SYS_VW_UHV_NAR_TMS470\TOOLS\Python_scripts\DiagnoseScript\EV_UHVNA_S02012.odx')
    #XML2BinObject2.parseOdxFile()

    XML2BinObject3 = parseXmlFile('F:\MyDocuments\workspace\eclipse\SYS_VW_UHV_NAR_TMS470\TOOLS\Python_scripts\DiagnoseScript\UHVNAR.xml')
    XML2BinObject3.parseSourceMonitorXmlFile()
    
    #XML2BinObject.padBinFile()
    #XML2BinObject.convertInFormats()
    
