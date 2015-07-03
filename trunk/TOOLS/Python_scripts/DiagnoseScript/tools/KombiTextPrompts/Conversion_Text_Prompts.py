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
import re
import struct

from LanguageSettingsFile import MapFieldNameToColumnNumber_dict
from LanguageSettingsFile import MapFieldNameToRowNumber_dict
from LanguageSettingsFile import MaxLines_dict
from LanguageSettingsFile import ListLanguages_1
from LanguageSettingsFile import UserEntriesMaxLinesList


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
    
class UHVSecondaryDisplayTextPrompts(object):
    """
    enums
    INPUTS:
    text prompt english = 6
    text prompt german = 11
    
    MAX NO OF LINES
    No. of lines  = 1 =>  _1 = text
    No. of lines  = 2 =>  _1 = text1stline; _2 = text_2ndline
    No. of lines  = 3 =>  _1 = text1stline; _2 = text_2ndline; _3 = text_3ndline
    No. of lines  = 4 =>  _1 = text1stline; _2 = text_2ndline; _3 = text_3ndline; _4 = text_4thline
    
    Check if the text in any language has been coded with max number of lines. 
    If in any other language there are lesser lines than the max no. of lines; then the last line will be coded with dummy
    array and a length of 0.
    """
    def __init__(self, generatedDirectory = '.', generatedDirectory_C = '.', generatedDirectory_H = '.'):
        pass
         

    def initialiseGeneralVariables(self, generatedDirectory = '.', generatedDirectory_C = '.', generatedDirectory_H = '.'):
        instanceOutputHFile = generatedDirectory_H + 'APP_SD_FrameDataBase.h'
        instanceOutputCFile = generatedDirectory_C + 'APP_SD_FrameDataBase.c'       
        self.TotalNumberOfRows = MapFieldNameToRowNumber_dict['LastRow'] - MapFieldNameToRowNumber_dict['StartingRow']
        self.TotalNumberOfMailboxRows = MapFieldNameToRowNumber_dict['LastMailboxRow'] - MapFieldNameToRowNumber_dict['StartingMailboxRow']
#===============================================================================
#            Enum Lists.
#===============================================================================
        self.ExtractENUMFromTables = []
#===============================================================================
#            English Language list.
#===============================================================================

        self.ListLanguages_1 = ListLanguages_1
        self.UserEntriesMaxLinesList = UserEntriesMaxLinesList
            
    #===============================================================================
    #    create output file instance.
    #===============================================================================     
        try:
            self.DescriptorCreatedHFile = open(instanceOutputHFile, 'w')
            self.DescriptorCreatedCFile = open(instanceOutputCFile, 'w')
            self.DescriptorTempTextFile = open(generatedDirectory + 'temp_text.txt', 'w')
            self.DescriptorTempLenFile = open(generatedDirectory + 'temp_len.txt', 'w')
            self.DescriptorTempMailboxFile = open(generatedDirectory + 'temp_mailbox.txt', 'w')
        except:
            pass

        
    def initialiseExcelSheet(self, instanceInputFile = '.'):
        #===============================================================================
        #    create input file instance.
        #===============================================================================        
        print instanceInputFile
         
        try:
            self.EasyExcelObject = easyexcel.easyExcel(instanceInputFile, False)
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
        
        self.TranslationTableList = list(self.EasyExcelObject.getSpecificRange(MapFieldNameToRowNumber_dict['StartingRow'],
                                                                  MapFieldNameToColumnNumber_dict['TranslationTableColumn'],
                                                                  MapFieldNameToRowNumber_dict['LastRow'],
                                                                  MapFieldNameToColumnNumber_dict['TranslationTableColumn']))
        self.ContextIdList = list(self.EasyExcelObject.getSpecificRange(MapFieldNameToRowNumber_dict['StartingRow'],
                                                              MapFieldNameToColumnNumber_dict['ContextIDColumn'],
                                                              MapFieldNameToRowNumber_dict['LastRow'],
                                                              MapFieldNameToColumnNumber_dict['ContextIDColumn']))
        self.MaxLinesList = list(self.EasyExcelObject.getSpecificRange(MapFieldNameToRowNumber_dict['StartingRow'],
                                                                  MapFieldNameToColumnNumber_dict['MaximumLinesColumn'],
                                                                  MapFieldNameToRowNumber_dict['LastRow'],
                                                                  MapFieldNameToColumnNumber_dict['MaximumLinesColumn'])) 
        self.ToDoList = list(self.EasyExcelObject.getSpecificRange(MapFieldNameToRowNumber_dict['StartingRow'],
                                                                  MapFieldNameToColumnNumber_dict['ToDoColumn'],
                                                                  MapFieldNameToRowNumber_dict['LastRow'],
                                                                  MapFieldNameToColumnNumber_dict['ToDoColumn'])) 
        
    
    def getMailboxTextFromExcelSheet(self, workingSheetNumber = 5):
        #===============================================================================
        #     below a tuple of tuples is returned. i.e a 2 D array by the function
        #     which is converted into a list.
        #     this will store the information in integer / UTf-16 format in 
        #     the below mentioned list.
        #===============================================================================
            
        print workingSheetNumber
        self.EasyExcelObject.setSheet(workingSheetNumber)
        
        self.TranslationTableMailboxList = list(self.EasyExcelObject.getSpecificRange(MapFieldNameToRowNumber_dict['StartingMailboxRow'],
                                                                  MapFieldNameToColumnNumber_dict['TranslationTableMailboxColumn'],
                                                                  MapFieldNameToRowNumber_dict['LastMailboxRow'],
                                                                  MapFieldNameToColumnNumber_dict['TranslationTableMailboxColumn']))
        self.ContextIdMailboxList = list(self.EasyExcelObject.getSpecificRange(MapFieldNameToRowNumber_dict['StartingMailboxRow'],
                                                              MapFieldNameToColumnNumber_dict['ContextIDMailboxColumn'],
                                                              MapFieldNameToRowNumber_dict['LastMailboxRow'],
                                                              MapFieldNameToColumnNumber_dict['ContextIDMailboxColumn']))

        self.ToDoMailboxList = list(self.EasyExcelObject.getSpecificRange(MapFieldNameToRowNumber_dict['StartingMailboxRow'],
                                                                  MapFieldNameToColumnNumber_dict['ToDoMailboxColumn'],
                                                                  MapFieldNameToRowNumber_dict['LastMailboxRow'],
                                                                  MapFieldNameToColumnNumber_dict['ToDoMailboxColumn']))


    
    def __del__(self):
        """
        destruct created instances.
        """
        print "destroying"
        self.EasyExcelObject.close()
        self.DescriptorCreatedHFile.close()
        self.DescriptorCreatedCFile.close()
       
    def __convertToStructTextElements(self, string_selection, language_array, language_array_breakup_length):
        """
        const Uint8Type APP_SD_au8English_ta_menu_cancel[0x6] = {
        0x43, 0x61, 0x6e, 0x63, 0x65, 0x6c = 
        } 
        This is the constant UTF-8 Byte array which is generated for every Text Prompt in every language.
        
        INPUTS:
        translation table  
        text display table.        
        """
        range_value = MaxLines_dict[string_selection]

        for counter in range(self.TotalNumberOfRows):
            if ((self.MaxLinesList[counter][0] == string_selection) and ( self.ToDoList[counter][0] == '1') and ( self.ContextIdList[counter][0] != None) and self.TranslationTableList[counter][0] != None): 
                for i in range(len(re.split(';|,', self.ContextIdList[counter][0]))):
                    length = 0
                    for i in range(range_value):
                        try:
                            # write only the pointer to the text and the offset if text is for more than one line
                            self.DescriptorTempTextFile.write('/* ' + str(self.total_text_struct_elements) + ' */')
                            self.DescriptorTempTextFile.write('\t(' +
                                                       language_array[counter] +
                                                       ' + ' + hex(length) + ' ),\n'
                                                       )
                            length = length + language_array_breakup_length[counter][i]
                            self.total_text_struct_elements = self.total_text_struct_elements + 1
                        except:
                            # Even in case of an exception the TempText File was written and we 
                            # need to increase the total count here only, cause this is ommitted in the 
                            # code above in case of an exception 
                            self.total_text_struct_elements = self.total_text_struct_elements + 1  
                            #print "problem in __convertToStructTextElements ...."

    def __convertToStructLenElements(self, string_selection, language_array, language_array_breakup_length):
        """
        const Uint8Type APP_SD_au8English_ta_menu_cancel[0x6] = {
        0x43, 0x61, 0x6e, 0x63, 0x65, 0x6c = 
        } 
        This is the constant UTF-8 Byte array which is generated for every Text Prompt in every language.
        
        INPUTS:
        translation table  
        text display table.        
        """
        range_value = MaxLines_dict[string_selection]
        

        for counter in range(self.TotalNumberOfRows):
            if ((self.MaxLinesList[counter][0] == string_selection) and ( self.ToDoList[counter][0] == '1') and ( self.ContextIdList[counter][0] != None) and self.TranslationTableList[counter][0] != None): 
                for i in range(len(re.split(';|,', self.ContextIdList[counter][0]))):
                    length = 0
                    for i in range(range_value):
                        try:
                            # write only the length of the text 
                            self.DescriptorTempLenFile.write('/* ' + str(self.total_len_struct_elements) + ' */')
                            self.DescriptorTempLenFile.write('\t ' + 
                                                       hex(language_array_breakup_length[counter][i]) +
                                                       ',\n'
                                                       )
                            length = length + language_array_breakup_length[counter][i]
                            self.total_len_struct_elements = self.total_len_struct_elements + 1
                        except:
                            if string_selection == 'Langtext':
                                display_Struct_length = hex(language_array_breakup_length[counter])
                            else:
                                display_Struct_length  = '0'
                            # write only the length of the text 
                            self.DescriptorTempLenFile.write('\t ' +
                                                       display_Struct_length  +
                                                       ',\n'
                                                       )
                            self.total_len_struct_elements = self.total_len_struct_elements + 1  
                            #print "problem in __convertToStructLenElements ...."
    


    # Context Id enum
    def __convertinENUM(self, string_selection, counter):
        """
        """
        
        range_value = MaxLines_dict[string_selection]        
        ExtractContextIDFromTables = re.split(';|,', self.ContextIdList[counter][0])
        for i in range(len(ExtractContextIDFromTables)):
           ctr = 1
           for j in range(range_value):
               self.ExtractENUMFromTables.append('APP_SD_en_' + 
                                         ExtractContextIDFromTables[i].strip().replace("_ ", "_") +
                                         '_' +
                                         map(str, self.TranslationTableList[counter])[0][8:] +
                                         '_' +
                                         self.MaxLinesList[counter][0] + '_' +
                                         str(ctr)+ ',\n')
               self.total_enum = self.total_enum + 1
               ctr = ctr + 1 
                                           

    # byte arrays containing the text for each language / context
    def __create_ConstantByteArray_StructureElements(self, language_string):

        """
        Inputs self.TextPromptsList
        In the C File creates a const array byte with a comment of the created constant byte array.
        In the temp file, the structure is initialised.
        That means, the entire C file is written in this function call ( constant byte array and the strucute initialisation )
        The temp file is mainly written in another function __convertToStructElements which is called by this function.
        """
        
        
        ExtractConstantArrayName = initialiseList()
        UTF_8TextPrompts = initialiseList()
        UTF_8TextPrompts_length = initialiseList()
        UTF_8TextPrompts_BreakUplength = initialiseList()

        RecreateTable = initialiseList()
        #===============================================================================
        #    Generate  UTF-8 Byte Sequence.
        #===============================================================================
        if (language_string in self.ListLanguages_1) :
            print language_string
            for counter in range(self.TotalNumberOfRows):
                if (( self.ToDoList[counter][0] == '1') and 
                    self.TranslationTableList[counter][0] != None and
                     self.ContextIdList[counter][0] != None):
                    RemovePercentU = self.TextPromptsList[counter][0]
                    if ( self.MaxLinesList[counter][0] == 'Langtext' ):
                        Split_AtNewLine = RemovePercentU
                    else:
                        Split_AtNewLine = RemovePercentU.split('\n')
                    RecreateTable[counter] = Split_AtNewLine
            for counter in range(self.TotalNumberOfRows):
                if ( ( self.ToDoList[counter][0] == '1') and
                     self.TranslationTableList[counter][0] != None and
                     self.ContextIdList[counter][0] != None):                
                    StripNewLineCharachters = []
                    list_length = []
                    length = 0
                    for i in range(len(RecreateTable[counter])):
                        # Here the total len is the length of the prompt. For lang text it is the total length of the alphabets.
                        result=RecreateTable[counter][i].encode('utf-8')
                        if ( result != '' ):
                            list_length.append((len(result)),)
                            UnpackAndConvertToHex = tuple(map(hex, struct.unpack(len(result)*'B',result)))
                            JoinStrings = ', '.join(UnpackAndConvertToHex)
                            StripNewLineCharachters.append(JoinStrings)
                            length += len(result)
                        #struct.unpack returns a tuple.
                    tuple_length = tuple(list_length)
                    UTF_8TextPrompts[counter] = StripNewLineCharachters
                    UTF_8TextPrompts_length[counter] = length
                    UTF_8TextPrompts_BreakUplength[counter] = tuple_length
                    
                    if ( self.MaxLinesList[counter][0] == 'Langtext' ):
                        ModifiedTextPrompts = ', '.join(UTF_8TextPrompts[counter])
                        ModifiedTextPrompts  = ModifiedTextPrompts.split()
                        for y in range(100):
                            for x in range(length/92 + 1):
                                try:
                                    problemIndex = 0
                                    if (int(ModifiedTextPrompts[93*x-1].rstrip(','),16) >= 0xc2 and int(ModifiedTextPrompts[93*x-1].rstrip(','),16) <= 0xdf ):   
                                        problemIndex = 93*x-1
                                        print "problem", ModifiedTextPrompts[problemIndex].rstrip(','), problemIndex 
                                        break
                                except:
                                    pass
                            if ( problemIndex != 0 ):
                                correctingIndex = problemIndex
                                while ( ModifiedTextPrompts[correctingIndex].rstrip(',') != '0xa' ):
                                    correctingIndex = correctingIndex - 1
                                print "Correcting at " , correctingIndex
                                CorrectedTextPrompt = ModifiedTextPrompts[:correctingIndex] + ['0x20,'] + ModifiedTextPrompts[correctingIndex:len(ModifiedTextPrompts)]
                                ModifiedTextPrompts = CorrectedTextPrompt
                            if ( problemIndex == 0):
                                print "Breaking after %d attempts" % y
                                break
                        
                        UTF_8TextPrompts_length[counter] = len(ModifiedTextPrompts) 
                        for x in range ( len(ModifiedTextPrompts)):
                            ModifiedTextPrompts[x] = ModifiedTextPrompts[x].rstrip(',')
                        UTF_8TextPrompts[counter] = ModifiedTextPrompts                             
                            
                            
                
                
            for counter in range(len(RecreateTable)):
                if ( ( self.ToDoList[counter][0] == '1') and
                     self.TranslationTableList[counter][0] != None and
                     self.ContextIdList[counter][0] != None):                
                   ExtractConstantArrayName[counter] = 'APP_SD_au8' + language_string + '_' + map(str, self.TranslationTableList[counter])[0][8:]

                   try:
                       self.DescriptorCreatedCFile.write('/* ' + self.TextPromptsList[counter][0].encode('utf-8').replace('\n', ' ') + ' */\n')
                   except:
                       self.DescriptorCreatedCFile.write('/* Comment cannot be showed because ' + language_string + ' language unsupported by Win Code pages */\n')
                   self.DescriptorCreatedCFile.write('const Uint8Type ' +
                                                     ExtractConstantArrayName[counter] +
                                                    '[' + hex(UTF_8TextPrompts_length[counter]) + ']' +
                                                    ' = {\n' +
                                                    ', '.join(UTF_8TextPrompts[counter]) +
                                                    '\n};\n')
                      
            #self.generateStructElements()
            self.total_text_struct_elements = 0
            self.total_len_struct_elements = 0
    #===============================================================================
    #        Create Language Structures
    #===============================================================================
            # first write the array for the pointers to the byte arrays containing the text
            self.DescriptorTempTextFile.write('{\n ')
            self.DescriptorTempTextFile.write('/* ' + str(self.total_text_struct_elements) + ' */')
            self.total_text_struct_elements = self.total_text_struct_elements + 1
            self.DescriptorTempTextFile.write('\t (APP_SD_au8Common_Error + 0x0 ),\n ')
            self.__convertToStructTextElements('Auswahl', ExtractConstantArrayName, UTF_8TextPrompts_BreakUplength)
            self.__convertToStructTextElements('Icon_Auswahl', ExtractConstantArrayName, UTF_8TextPrompts_BreakUplength)
            self.__convertToStructTextElements('1_Zeile', ExtractConstantArrayName, UTF_8TextPrompts_BreakUplength)
            self.__convertToStructTextElements('2_Zeile', ExtractConstantArrayName, UTF_8TextPrompts_BreakUplength)
            self.__convertToStructTextElements('3_Zeile', ExtractConstantArrayName, UTF_8TextPrompts_BreakUplength)
            self.__convertToStructTextElements('4_Zeile', ExtractConstantArrayName, UTF_8TextPrompts_BreakUplength)
            self.__convertToStructTextElements('Langtext', ExtractConstantArrayName, UTF_8TextPrompts_length)
            self.DescriptorTempTextFile.write('},\n')

            # now write tha array for the prompt length values, for error text the length is constant
            self.DescriptorTempLenFile.write('{\n ')
            self.DescriptorTempLenFile.write('/* ' + str(self.total_len_struct_elements) + ' */')
            self.total_len_struct_elements = self.total_len_struct_elements + 1
            self.DescriptorTempLenFile.write('\t 0x5 ,\n ')
            self.__convertToStructLenElements('Auswahl', ExtractConstantArrayName, UTF_8TextPrompts_BreakUplength)
            self.__convertToStructLenElements('Icon_Auswahl', ExtractConstantArrayName, UTF_8TextPrompts_BreakUplength)
            self.__convertToStructLenElements('1_Zeile', ExtractConstantArrayName, UTF_8TextPrompts_BreakUplength)
            self.__convertToStructLenElements('2_Zeile', ExtractConstantArrayName, UTF_8TextPrompts_BreakUplength)
            self.__convertToStructLenElements('3_Zeile', ExtractConstantArrayName, UTF_8TextPrompts_BreakUplength)
            self.__convertToStructLenElements('4_Zeile', ExtractConstantArrayName, UTF_8TextPrompts_BreakUplength)
            self.__convertToStructLenElements('Langtext', ExtractConstantArrayName, UTF_8TextPrompts_length)
            self.DescriptorTempLenFile.write('},\n')



            print 'total struct ' + language_string + ' text elements = %d, len elements = %d ' % (self.total_text_struct_elements,self.total_len_struct_elements)
            #print UTF_8TextPrompts_BreakUplength
            #print UTF_8TextPrompts_length


    # byte arrays containing the text for each language / context
    def __create_ConstantByteArray_MailboxElements(self, language_string):

        """
        Inputs self.TextPromptsList
        In the C File creates a const array byte with a comment of the created constant byte array.
        In the temp file, the structure is initialised.
        That means, the entire C file is written in this function call ( constant byte array and the strucute initialisation )
        The temp file is mainly written in another function __convertToStructElements which is called by this function.
        """
        
        
        ExtractConstantArrayName = initialiseList_Mailbox()
        UTF_8TextPrompts = initialiseList_Mailbox()
        UTF_8TextPrompts_length = initialiseList_Mailbox()
        UTF_8TextPrompts_BreakUplength = initialiseList_Mailbox()

        RecreateTable = initialiseList_Mailbox()
        #===============================================================================
        #    Generate  UTF-8 Byte Sequence.
        #===============================================================================
        if (language_string in self.ListLanguages_1):
            print language_string
            for counter in range(self.TotalNumberOfMailboxRows):
                if ( ( True==True) and
                     self.TranslationTableMailboxList[counter][0] != None and
                     self.ContextIdMailboxList[counter][0] != None):
                    StripNewLineCharachters = []
                    list_length = []
                    length = 0
                    result=self.TextPromptsMailboxList[counter][0].encode('utf-8')
                    if ( result != '' ):
                        list_length.append((len(result)),)
                        UnpackAndConvertToHex = tuple(map(hex, struct.unpack(len(result)*'B',result)))
                        JoinStrings = ', '.join(UnpackAndConvertToHex)
                        StripNewLineCharachters.append(JoinStrings)
                        length += len(result)
                        #struct.unpack returns a tuple.
                    tuple_length = tuple(list_length)
                    UTF_8TextPrompts[counter] = StripNewLineCharachters
                    UTF_8TextPrompts_length[counter] = length
               
            #print     UTF_8TextPrompts
            for counter in range(self.TotalNumberOfMailboxRows):
                if ( ( True == True) and
                     self.TranslationTableMailboxList[counter][0] != None and
                     self.ContextIdMailboxList[counter][0] != None):                
                   print UTF_8TextPrompts[counter]
                   ExtractConstantArrayName[counter] = 'APP_SD_au8' + language_string + '_' + map(str, self.TranslationTableMailboxList[counter])[0][8:]
    
                   try:
                       self.DescriptorTempMailboxFile.write('/* ' + self.TextPromptsMailboxList[counter][0].encode('utf-8').replace('\n', ' ') + ' */\n')
                   except:
                       self.DescriptorTempMailboxFile.write('/* Comment cannot be showed because ' + language_string + ' language unsupported by Win Code pages */\n')
                   self.DescriptorTempMailboxFile.write('const Uint8Type ' +
                                                     ExtractConstantArrayName[counter] +
                                                    '[' + hex(UTF_8TextPrompts_length[counter]) + ']' +
                                                    ' = {\n' +
                                                    ', '.join(UTF_8TextPrompts[counter]) +
                                                    '\n};\n')
            #self.generateStructElements()
            self.total_text_struct_elements = 0
            self.total_len_struct_elements = 0

            print 'total struct ' + language_string + ' text elements = %d, len elements = %d ' % (self.total_text_struct_elements,self.total_len_struct_elements)
            #print UTF_8TextPrompts_BreakUplength
            #print UTF_8TextPrompts_length

    
    def createFileHeader(self, toolsDirectory):
        """
        To create the header information in the file.
        Please fill the information what you want to put in the file in the beginning.
        """
        import_file_desc_h = open(toolsDirectory + 'import_file_h.txt', 'r')
        readlines = import_file_desc_h.read()
        self.DescriptorCreatedHFile.write(readlines)
        import_file_desc_h.close()
        
        import_file_desc_c = open(toolsDirectory + 'import_file_c.txt', 'r')
        readlines = import_file_desc_c.read()
        self.DescriptorCreatedCFile.write(readlines)
        import_file_desc_c.close()
        

    def createFileFooter(self):
        """
        To create the footer information in the file.
        Please fill the information what you want to put in the file in the end.
        """
        self.DescriptorCreatedHFile.write('typedef const Uint8Type * const CONST_U8_PTR_CONST_T;\n\n') 
        self.DescriptorCreatedHFile.write('extern CONST_U8_PTR_CONST_T \
        APP_SD_a2stStaticTexts[APP_SD_enMAX_LANGUAGE][APP_SD_enMAX_CONTEXT_ID];\n')
        self.DescriptorCreatedHFile.write('extern const Uint16Type \
        APP_SD_a2stStaticTextLens[APP_SD_enMAX_LANGUAGE][APP_SD_enMAX_CONTEXT_ID];\n')
        self.DescriptorCreatedHFile.write('\n#endif /* _APP_SD_FRAMEDATABASE_H */\n')
        self.DescriptorCreatedHFile.write('/* End Of File APP_SD_FrameDataBase.h */\n')

        self.DescriptorCreatedCFile.write('\n/* End Of File APP_SD_FrameDataBase.c */\n')

    
    def generateContextIdENUMs(self):
        """
        S994_TA_NOTE_IGNITION_x : 
        This is the enum word which will be generated for every translation table.
        The _x in the end depends on the no of max lines in the text.
        
        INPUTS:
        translation table  
        context id  
        Max no of lines 
        The format for enum will be taken from
        1. translation table, context Id, Max no of lines, _X ( Max no of lines means max no of enums to create )
        Generate ENUMS  
        """
        #===============================================================================
        #    Generate  ENUMS.
        #===============================================================================
        self.total_enum = 0
        for counter_maxLines in range(len(self.UserEntriesMaxLinesList)):
            for counter in range(self.TotalNumberOfRows):
                if ( ( self.ToDoList[counter][0] == '1') and
                     self.TranslationTableList[counter][0] != None and
                     self.ContextIdList[counter][0] != None):
                    if (self.MaxLinesList[counter][0] == self.UserEntriesMaxLinesList[counter_maxLines]): 
                        self.__convertinENUM(self.UserEntriesMaxLinesList[counter_maxLines], counter)


        self.DescriptorCreatedHFile.write('\ntypedef enum\n{\n')
        self.DescriptorCreatedHFile.write('APP_SD_enError,\n')
        for counter in range(len(self.ExtractENUMFromTables)):
            self.DescriptorCreatedHFile.write(self.ExtractENUMFromTables[counter])
        
        print "total enums = %d" % self.total_enum
        self.DescriptorCreatedHFile.write('APP_SD_enMAX_CONTEXT_ID\n')    
        self.DescriptorCreatedHFile.write('} APP_SD_ENUM_TEXT_PROMPTS_SEC_DISPLAY;\n\n')
         

    def generate_ConstantByteArray_LanguageTextElements(self):
        """
        const Uint8Type APP_SD_au8English_ta_menu_cancel[0x6] = {
        0x43, 0x61, 0x6e, 0x63, 0x65, 0x6c = 
        } 
        This is the constant UTF-8 Byte array which is generated for every Text Prompt in every language.
        
        INPUTS:
        translation table  
        text display table.
        """
     
        for counter in range(len(self.ListLanguages_1)):
            self.TextPromptsList = list(self.EasyExcelObject.getSpecificRange(MapFieldNameToRowNumber_dict['StartingRow'],
                                                                  MapFieldNameToColumnNumber_dict[self.ListLanguages_1[counter] +'TextColumn'],
                                                                  MapFieldNameToRowNumber_dict['LastRow'],
                                                                  MapFieldNameToColumnNumber_dict[self.ListLanguages_1[counter] +'TextColumn']))   
            self.__create_ConstantByteArray_StructureElements(self.ListLanguages_1[counter])
            print self.TextPromptsList
        self.DescriptorTempTextFile.close()
        self.DescriptorTempLenFile.close()
        
        
    def generate_ConstantByteArray_MailboxElements(self):
        """
        const Uint8Type APP_SD_au8English_ta_menu_cancel[0x6] = {
        0x43, 0x61, 0x6e, 0x63, 0x65, 0x6c = 
        } 
        This is the constant UTF-8 Byte array which is generated for every Text Prompt in every language.
        
        INPUTS:
        translation table  
        text display table.
        """
     
        for counter in range(len(self.ListLanguages_1)):
            self.TextPromptsMailboxList = list(self.EasyExcelObject.getSpecificRange(MapFieldNameToRowNumber_dict['StartingMailboxRow'],
                                                                  MapFieldNameToColumnNumber_dict[self.ListLanguages_1[counter] +'MailboxColumn'],
                                                                  MapFieldNameToRowNumber_dict['LastMailboxRow'],
                                                                  MapFieldNameToColumnNumber_dict[self.ListLanguages_1[counter] +'MailboxColumn']))   
            self.__create_ConstantByteArray_MailboxElements(self.ListLanguages_1[counter])
            print self.TextPromptsList
        self.DescriptorTempTextFile.close()
        self.DescriptorTempLenFile.close()

    
    def printAllModuleVariables(self):
        #===============================================================================
        #    Print Tables
        #===============================================================================
        print "-------------------------------------------"
        print "Total Number of Rows = %d" %self.TotalNumberOfRows
        print self.ToDoList
        print self.TranslationTableList
        print self.ContextIdList
        print self.MaxLinesList
        print "-------------------------------------------"
    
    def lengthUTF_8TextPrompts_English(self, counter):
        return self.UTF_8TextPrompts_length[counter]
    
    # 2 dim. Array of lang and context in FrameDataBase.c 
    def copyStaticStructTable(self, generatedDirectory):
        #### add array header for text array 
        self.DescriptorCreatedCFile.write('\n\nCONST_U8_PTR_CONST_T \
        APP_SD_a2stStaticTexts[APP_SD_enMAX_LANGUAGE][APP_SD_enMAX_CONTEXT_ID] = {\n' )
        # read text prompts array from temp file and copy it 
        self.DescriptorTempTextFile = open(generatedDirectory + 'temp_text.txt', 'r')
        readlines = self.DescriptorTempTextFile.read()
        self.DescriptorCreatedCFile.write(readlines)
        self.DescriptorTempTextFile.close()    
        self.DescriptorCreatedCFile.write('};')  
        
        #### add array header for len array 
        self.DescriptorCreatedCFile.write('\n\nconst Uint16Type \
        APP_SD_a2stStaticTextLens[APP_SD_enMAX_LANGUAGE][APP_SD_enMAX_CONTEXT_ID] = {\n' )
        # get content from file with len of prompts array  
        self.DescriptorTempLenFile = open(generatedDirectory + 'temp_len.txt', 'r')
        readlines = self.DescriptorTempLenFile.read()
        self.DescriptorCreatedCFile.write(readlines)
        self.DescriptorTempTextFile.close()    
        self.DescriptorTempLenFile.close()
        self.DescriptorCreatedCFile.write('};')    
        #os.system("del \"../generated/temp_text.txt\"")
        #os.system("del \"../generated/temp_len.txt\"")

    # language enum in FrameDataBase.h
    def generateLanguageENUMs(self):
        self.DescriptorCreatedHFile.write('typedef enum\n{\n')
        for counter in range(len(self.ListLanguages_1)):
            self.DescriptorCreatedHFile.write('APP_SD_enLANG_' + ListLanguages_1[counter]+',\n')
        self.DescriptorCreatedHFile.write('APP_SD_enMAX_LANGUAGE\n}\nAPP_SD_ENUM_LANGUAGES;\n')
        
    def runScript(self, ExcelFilePath, ExcelFileDirectory, scriptDirectory):
        generatedDirectory = os.path.join(scriptDirectory,'../generated/' )
        generatedDirectory_H = os.path.join(ExcelFileDirectory,'../inc/' )
        generatedDirectory_C = os.path.join(ExcelFileDirectory,'../src/' )
        toolsDirectory = os.path.join(scriptDirectory,'../tools/KombiTextPrompts/' )
        UHVClassObjectSecondaryDisplayTextPrompts = UHVSecondaryDisplayTextPrompts()
        #Initialise the excel sheets
        UHVClassObjectSecondaryDisplayTextPrompts.initialiseGeneralVariables(generatedDirectory, generatedDirectory_C, generatedDirectory_H)
        instanceExcelObject1 = UHVClassObjectSecondaryDisplayTextPrompts.initialiseExcelSheet(ExcelFilePath)
        
        
        workingSheet = 2
        UHVClassObjectSecondaryDisplayTextPrompts.getLanguageTextAndFrameIdsFromExcelSheet(workingSheet)
        
        #Create File Header
        UHVClassObjectSecondaryDisplayTextPrompts.createFileHeader(toolsDirectory)
        
        #Generate the Language enums
        UHVClassObjectSecondaryDisplayTextPrompts.generateLanguageENUMs()
        
        print dir(UHVClassObjectSecondaryDisplayTextPrompts)
            
        #Generate the Context Id enums
        UHVClassObjectSecondaryDisplayTextPrompts.generateContextIdENUMs()
        
        #Generate constant Byte array language text elements.
        UHVClassObjectSecondaryDisplayTextPrompts.generate_ConstantByteArray_LanguageTextElements()
        # Copy information from temp file into the source code.
        UHVClassObjectSecondaryDisplayTextPrompts.copyStaticStructTable(generatedDirectory)
    
        workingSheet = 5
        UHVClassObjectSecondaryDisplayTextPrompts.getMailboxTextFromExcelSheet(workingSheet)
        #Generate constant Byte array mailbox text elements.
        UHVClassObjectSecondaryDisplayTextPrompts.generate_ConstantByteArray_MailboxElements()
   
        #Create File Header
        UHVClassObjectSecondaryDisplayTextPrompts.createFileFooter()
        print 'END'
        
    
if __name__ == '__main__':

        print 'THIS IS NOT ALLOWED. USE THE GUI ( http://subversion-01/svn/SW_HW_System/Tools/PythonDiagnosticsTool/trunk ) TO GENERATE THE FILES.'
        
# End Of File Conversion_Text_Prompts.py
