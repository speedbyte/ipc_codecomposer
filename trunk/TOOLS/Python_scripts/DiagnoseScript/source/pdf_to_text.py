""" 


    $Date: 2009-06-23 15:46:24 +0200 (Di, 23 Jun 2009) $
    $Rev: 6848 $
    $Author: agrawal $
    $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/TOOLS/Python_scripts/trunk/DiagnoseScript/pdf_to_text.py $

    Copyright (c) 2008 S1nn GmbH & Co. KG.
    All Rights Reserved.


"""

import os

from pyPdf import PdfFileWriter, PdfFileReader



class GenerateFile(object):
    def __init__(self):
        pass
    
    def extractDiagnoseInformation(self, startCursor, endCursor, startDelimiter, endDelimiter):
        rightCursor = 0
        listOfElements = []
        while ( rightCursor < endCursor ):
            leftCursor = fileContents.find(startDelimiter,startCursor, endCursor)
            if leftCursor == -1 :
                break
            #print leftCursor
            rightCursor = fileContents.find(endDelimiter,leftCursor)
            #print rightCursor
            receivedString = fileContents[leftCursor:rightCursor].rstrip(' ')
            startCursor = rightCursor
            #print receivedString
            convString = receivedString.encode('utf-8')
            convString = convString.replace('Ä'.encode('utf-8'), 'AE')
            convString = convString.replace('Ö'.encode('utf-8'), 'OE')
            convString = convString.replace('Ü'.encode('utf-8'), 'UE')
            convString = convString.replace('ß'.encode('utf-8'), 'SS')
            convString = convString.replace('ä'.encode('utf-8'), 'AE')
            convString = convString.replace('ö'.encode('utf-8'), 'OE')
            convString = convString.replace('ü'.encode('utf-8'), 'UE')
            convString = convString.replace('/'.encode('utf-8'), '_')
            convString = convString.replace('-', '_')
            convString = convString.replace(' ', '_')
            convString = convString.replace(',','')
            convString = convString.replace('$','')
            #print convString
            newString = convString.upper()
            listOfElements.append(newString)
        self.stringList = listOfElements
        self.StringListBroken = []
        for element in range(len(listOfElements)):
            x = []
            IdentifierCode_string = listOfElements[element][0:4]
            #print IdentifierCode_string
            x.append(IdentifierCode_string)
            IdentifierName_string = listOfElements[element][6:len(listOfElements[element])]
            #print IdentifierName_string
            x.append(IdentifierName_string)
            self.StringListBroken.append(x)
        #print self.stringList
        print self.StringListBroken

    def extractDiagnoseInformationDtc(self, startCursor, endCursor, startDelimiter, endDelimiter):
        rightCursor = 0
        listOfElements = []
        while ( rightCursor < endCursor ):
            leftCursor = fileContents.find(startDelimiter,startCursor, endCursor)
            if leftCursor == -1 :
                break
            #print leftCursor
            rightCursor = fileContents.find(endDelimiter,leftCursor)
            #print rightCursor
            receivedString = fileContents[leftCursor:rightCursor].rstrip(' ')
            startCursor = rightCursor
            #print receivedString
            convString = receivedString.encode('utf-8')
            convString = convString.replace('Ä'.encode('utf-8'), 'AE')
            convString = convString.replace('Ö'.encode('utf-8'), 'OE')
            convString = convString.replace('Ü'.encode('utf-8'), 'UE')
            convString = convString.replace('ß'.encode('utf-8'), 'SS')
            convString = convString.replace('ä'.encode('utf-8'), 'AE')
            convString = convString.replace('ö'.encode('utf-8'), 'OE')
            convString = convString.replace('ü'.encode('utf-8'), 'UE')
            convString = convString.replace('/'.encode('utf-8'), '_')
            convString = convString.replace('('.encode('utf-8'), '_')
            convString = convString.replace(')'.encode('utf-8'), '_')
            convString = convString.replace('-', '_')
            convString = convString.replace(' ', '_')
            convString = convString.replace(',','')
            convString = convString.replace('$','')
            convString = convString.replace('"','')
            #print convString
            newString = convString.upper()
            listOfElements.append(newString)
        self.stringList = listOfElements
        self.StringListBroken = []
        for element in range(len(listOfElements)):
            x = []
            IdentifierCode_string = listOfElements[element][0:7]
            #print IdentifierCode_string
            x.append(IdentifierCode_string)
            IdentifierName_string = listOfElements[element][8:len(listOfElements[element])]
            #print IdentifierName_string
            x.append(IdentifierName_string)
            self.StringListBroken.append(x)
        #print self.stringList
        print self.StringListBroken
                
    def storeInHeaderFile(self, dictOfElements):
        """
        #define WERKSTATTCODE_DAS_ANGESCHLOSSENEN_TESTERS 0xF198
        """
        fileDes = open("..\..\..\MOD\MOD_APP_DIAG\inc\APP_DIAG_ID_CHART.h", "w")
        #fileDes_params = open("..\..\..\MOD\MOD_APP_DIAG\inc\APP_DIAG_ID_CHART_PARAMS_LEN.h", "w")
        fileHeader = open("c_header.txt","r")
        fileDes.write(fileHeader.read())
        #fileDes_params.write(fileHeader.read())
        listElements = list(dictOfElements)
        fileDes.write('\r\n')
        for element in range(len(listElements)):
            fileDes.write('/*')
            fileDes.write(listElements[element])
            fileDes.write('*/\r\n')
            current_service = listElements[element]
            if ( current_service == 'IdentifierMeasurementValue'):
                fileDesTemp = open('temp.txt', 'w')
                fileDesTemp.write("#define CASE_ALL_ID_MESSWERT       \\\r\n")
            if ( current_service == 'CalibrationDataWritable'):
                fileDesTemp = open('temp.txt', 'w')
                fileDesTemp.write("#define CASE_ALL_ID_ANPASSUNG       \\\r\n")
            if ( current_service == 'IdentifierVariantCoding'):
                fileDesTemp = open('temp.txt', 'w')
                fileDesTemp.write("#define CASE_ALL_ID_CODIERUNG       \\\r\n")  
            if ( current_service == 'ActuatorTest'):
                fileDesTemp = open('temp.txt', 'w')
                fileDesTemp.write("#define CASE_ALL_ID_STELLGLIEDTEST       \\\r\n")  
            #fileDes.write('\r\n')
            for subelements in range(len(dictOfElements[listElements[element]])):
                fileDes.write('#define ')
                if ( current_service == 'CalibrationDataWritable' or  
                     current_service == 'EcuIdentificationWritable' or  
                     current_service == 'CodierungWritable'):
                    strVal = 'ID_2E_' + dictOfElements[listElements[element]][subelements][0][0:4] + '_'
                elif ( current_service == 'IdentifierMeasurementValue' or
                       current_service == 'IdentifierVariantCoding' or
                       current_service == 'CalibrationData'):
                    strVal = 'ID_22_' + dictOfElements[listElements[element]][subelements][0][0:4] + '_'
                elif ( current_service == 'EcuIdentification'):
                    strVal = 'ID_22_' + dictOfElements[listElements[element]][subelements][0][0:4] + '_'
                elif ( current_service ==  'ActuatorTest'):
                    strVal = 'ID_2F_' + dictOfElements[listElements[element]][subelements][0][0:4] + '_'
                elif ( current_service ==  'DtcOverview'):
                    strVal = 'ID_DTCS_' + dictOfElements[listElements[element]][subelements][0][0:11] + '_'
                elif ( current_service ==  'RoutineControlSettings'):
                    strVal = '_' + dictOfElements[listElements[element]][subelements][0][0:4] + '_'
                strVal = strVal + dictOfElements[listElements[element]][subelements][1]
                minVal = '#define       ' + strVal +  '_MIN\r\n'
                maxVal = '#define       ' + strVal +  '_MAX\r\n'
                fileDes.write(strVal)
                #fileDes_params.write(minVal)
                #fileDes_params.write(maxVal)
                if ( current_service == 'IdentifierMeasurementValue' or
                     current_service == 'CalibrationDataWritable' or
                     current_service == 'ActuatorTest' or
                     current_service == 'CodierungWritable'):
                    fileDesTemp.write("\t\t\t\t\t case ")
                    fileDesTemp.write(strVal +': \\\r\n')
                fileDes.write('              0x')  # give enough space in #define
                if ( current_service ==  'DtcOverview'):
                    fileDes.write(dictOfElements[listElements[element]][subelements][0][2:])
                else:
                    fileDes.write(dictOfElements[listElements[element]][subelements][0][0:4])
                fileDes.write('\r\n')
            if ( current_service == 'IdentifierMeasurementValue' or
                 current_service == 'CalibrationDataWritable' or
                 current_service == 'ActuatorTest' or
                 current_service == 'CodierungWritable'):
                fileDesTemp.close()
                fileDesTemp = open("temp.txt", "r")
                tempFileCaseContents = fileDesTemp.read()
                fileDes.write(tempFileCaseContents)
                fileDesTemp.close()
            #fileDes.write('\r\n')
        fileFooter = open("c_footer.txt","r")
        fileDes.write(fileFooter.read())
        #fileDes_params.write(fileFooter.read())
        fileFooter.close()
        fileHeader.close()
        fileDes.close()
        #fileDes_params.close()
        #os.system("del temp.txt")

        
    def storeInPythonFile(self, dictOfElements):
        """
        'WERKSTATTCODE_DAS_ANGESCHLOSSENEN_TESTERS' : [0x2E ,0xF1,0x98, 0x04, 0xBA, 0x35, 0x35, 0x04],
        """
        fileDes = open("UserInterface_GUI.py", "w")
        fileHeader = open("python_header.txt","r")
        fileDes.write(fileHeader.read())
        listElements = list(dictOfElements)
        fileDes.write('\r\n')
        for element in range(len(listElements)):
            fileDes.write('#')
            fileDes.write(listElements[element])
            fileDes.write('\r\ncommand_dict_' + listElements[element] + ' = {')
            current_service = listElements[element]
            #print listElements[element]
            fileDes.write('\r\n')
            for subelements in range(len(dictOfElements[listElements[element]])):
                fileDes.write('\'')
                fileDes.write(dictOfElements[listElements[element]][subelements][1])
                fileDes.write('\' : [')
                if ( current_service == 'CalibrationDataWritable') or ( current_service == 'EcuIdentificationWritable') or ( current_service == 'CodierungWritable'):
                    fileDes.write('0x2E, ')
                elif ( current_service == 'IdentifierMeasurementValue') or ( current_service == 'EcuIdentification'):
                    fileDes.write('0x22, ')
                elif ( current_service ==  'ActuatorTest'):
                    fileDes.write('0x2F, ')
                fileDes.write('0x')
                if ( current_service == 'DtcOverview'):
                    fileDes.write(dictOfElements[listElements[element]][subelements][0][2:4])
                else:
                    fileDes.write(dictOfElements[listElements[element]][subelements][0][0:2])
                fileDes.write(', ')
                fileDes.write('0x')
                fileDes.write(dictOfElements[listElements[element]][subelements][0][2:4])
                fileDes.write('],\r\n')
                #print dictOfElements[listElements[element]][subelements][1]
            fileDes.write('}\r\n')
        fileFooter = open("python_footer.txt","r")
        fileDes.write(fileFooter.read())
        fileFooter.close()
        fileHeader.close()
        fileDes.close()
        

if __name__ == '__main__':
    generateDiagFileObject = GenerateFile()
    output = PdfFileWriter()
    input1 = PdfFileReader(file(r"..\..\..\doc\Diagnose\PDF\EV_UHVNA_S02013_anw_de.pdf", "rb"))
    
    anwender_doc_dict = {}
    # print the title of document1.pdf
    print "title = %s" % (input1.getDocumentInfo().title)
    
    #output.addPage(input1.getPage(0))
    output.addPage(input1.getPage(1))
    output.addPage(input1.getPage(2))
    output.addPage(input1.getPage(3))
    output.addPage(input1.getPage(4))
    
    # print how many pages input1 has:
    print "document1.pdf has %s pages." % input1.getNumPages()
    inputPDF = "gen_doc"
    # finally, write "output" to document-output.pdf
    outputStream = file((inputPDF + '.pdf'), "wb")
    
    output.write(outputStream)
    outputStream.close()
    
    os.system(r"E:\Programme\pdf2txt\pdf2txt" + ' ' + (inputPDF + '.pdf') + ' ' + './' )
    filePath = inputPDF + '.txt'
    inputGeneratedFile = file(filePath , "r")
    
    fileContents = inputGeneratedFile.read()
    inputGeneratedFile.close()
    os.system("del" + ' ' + inputPDF + '.pdf')
    os.system("del" + ' ' + inputPDF + '.txt')
    
    startCursor = fileContents.find("Record Data Identifier Calibration Data")
    endCursor = fileContents.find("Record Data Identifier Calibration Data Writable")
    generateDiagFileObject.extractDiagnoseInformation(startCursor, endCursor, "$", ".")
    anwender_doc_dict['CalibrationData'] = generateDiagFileObject.StringListBroken
    #print "-----------------------------------"
    startCursor = fileContents.find("Record Data Identifier Calibration Data Writable")
    endCursor = fileContents.find("Record Data Identifier ECU Identification")
    generateDiagFileObject.extractDiagnoseInformation(startCursor, endCursor, "$", ".")
    anwender_doc_dict['CalibrationDataWritable'] = generateDiagFileObject.StringListBroken
    #print "-----------------------------------"
    startCursor = fileContents.find("Record Data Identifier ECU Identification")
    endCursor = fileContents.find("Record Data Identifier ECU Identification Writable")
    generateDiagFileObject.extractDiagnoseInformation(startCursor, endCursor, "$", ".")    
    anwender_doc_dict['EcuIdentification'] = generateDiagFileObject.StringListBroken
    #print "-----------------------------------"
    startCursor = fileContents.find("Record Data Identifier ECU Identification Writable")
    endCursor = fileContents.find("Record Data Identifier Measurement Value")
    generateDiagFileObject.extractDiagnoseInformation(startCursor, endCursor, "$", ".")    
    anwender_doc_dict['EcuIdentificationWritable'] = generateDiagFileObject.StringListBroken
    #print "-----------------------------------"
    startCursor = fileContents.find("Record Data Identifier Measurement Value")
    endCursor = fileContents.find("Record Data Identifier Variant Coding")
    generateDiagFileObject.extractDiagnoseInformation(startCursor, endCursor, "$", ".")    
    anwender_doc_dict['IdentifierMeasurementValue'] = generateDiagFileObject.StringListBroken
    #print "-----------------------------------"
    startCursor = fileContents.find("Record Data Identifier Variant Coding")
    endCursor = fileContents.find("Record Data Identifier Variant Coding Writable")
    generateDiagFileObject.extractDiagnoseInformation(startCursor, endCursor, "$", ".")
    anwender_doc_dict['IdentifierVariantCoding'] = generateDiagFileObject.StringListBroken    
    #print "-----------------------------------"
    startCursor = fileContents.find("Record Data Identifier Variant Coding Writable")
    endCursor = fileContents.find("IO Control Actuator Test")
    generateDiagFileObject.extractDiagnoseInformation(startCursor, endCursor, "$", ".")
    anwender_doc_dict['CodierungWritable'] = generateDiagFileObject.StringListBroken    
    #print "-----------------------------------"
    startCursor = fileContents.find("IO Control Actuator Test")
    endCursor = fileContents.find("Routine Control Basic Settings")
    generateDiagFileObject.extractDiagnoseInformation(startCursor, endCursor, "$", ".")    
    anwender_doc_dict['ActuatorTest'] = generateDiagFileObject.StringListBroken
#    print "-----------------------------------"
#===============================================================================
#    startCursor = fileContents.find("Routine Control Basic Settings")
#    endCursor = fileContents.find("Record Data Identifier Variant Coding Writable Textual")
#    generateDiagFileObject.extractDiagnoseInformation(startCursor, endCursor, "$", ".")    
#    anwender_doc_dict['RoutineControlSettings'] = generateDiagFileObject.StringListBroken
#===============================================================================
#    print "-----------------------------------"
#    startCursor = fileContents.find("Record Data Identifier Variant Coding Writable Textual")
#    endCursor = fileContents.find("Detaillierte Beschreibung der DTCs")
#    generateDiagFileObject.extractDiagnoseInformation(startCursor, endCursor, "$", ".")    
#    anwender_doc_dict['CodierungWritable'] = generateDiagFileObject.StringListBroken
#    print "-----------------------------------"

    startCursor = fileContents.find("Detaillierte Beschreibung der DTCs")
    endCursor = fileContents.find("Negative Response Codes")
    generateDiagFileObject.extractDiagnoseInformationDtc(startCursor, endCursor, "\"", ".")        
    anwender_doc_dict['DtcOverview'] = generateDiagFileObject.StringListBroken
    print "-----------------------------------"

    generateDiagFileObject.storeInPythonFile(anwender_doc_dict)
    generateDiagFileObject.storeInHeaderFile(anwender_doc_dict)              