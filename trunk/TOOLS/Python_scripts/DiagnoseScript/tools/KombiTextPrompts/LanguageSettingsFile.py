""" 


    $Date: 2010-03-30 14:16:09 +0200 (Di, 30 Mrz 2010) $
    $Rev: 11846 $
    $Author: goldammer $
    $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/TOOLS/Python_scripts/trunk/KombiTextPrompts/LanguageSettingsFile.py $

    Copyright (c) 2007 S1nn GmbH & Co. KG.
    All Rights Reserved.

"""

_svn_id = "$Id$"
_svn_rev = "$Rev: 11846 $"
__version__ = _svn_rev[6:-2]



MapFieldNameToColumnNumber_dict = {
'ToDoColumn' : 1,
'TranslationTableColumn' : 2,
'ContextIDColumn'  :3,

'ToDoMailboxColumn' : 1,
'TranslationTableMailboxColumn' : 2,
'ContextIDMailboxColumn'  :3,

'EnglishTextColumn':16,
'GermanTextColumn':11,
'CzechTextColumn': 21,
'FrenchTextColumn':26,
'ItalianTextColumn': 31,
'PortugeseTextColumn':36,
'SpanishTextColumn':41,
'USEnglishTextColumn':6,
'RussianTextColumn':46,
'CanadianFrenchTextColumn':51,
'DutchTextColumn': 56,
'SwedishTextColumn':61,
'NorwegianTextColumn':66,
'TurkishTextColumn':71,
'PolishTextColumn':76,
'USSpanishTextColumn':81,

'EnglishMailboxColumn':6,
'GermanMailboxColumn':5,
'SpanishMailboxColumn': 11,
'FrenchMailboxColumn':8,
'PortugeseMailboxColumn': 10,
'CzechMailboxColumn':7,
'RussianMailboxColumn':12,
'ItalianMailboxColumn':9,
'DutchMailboxColumn':14,
'USEnglishMailboxColumn':4,
'USSpanishMailboxColumn': 19,
'CanadianFrenchMailboxColumn':13,
'SwedishMailboxColumn':15,
'NorwegianMailboxColumn':16,
'PolishMailboxColumn':18,
'TurkishMailboxColumn':17,

'MaximumLinesColumn':86,

}

MapFieldNameToRowNumber_dict = {
'StartingRow':4,
'LastRow':455, #please enter her the first line that is empty after all lines that are not empty

'StartingMailboxRow':3,
'LastMailboxRow':8 #please enter her the first line that is empty after all lines that are not empty

}


UserEntriesMaxLinesList = ['Auswahl', 'Icon_Auswahl', '1_Zeile', '2_Zeile', '3_Zeile', '4_Zeile', 'Langtext']

MaxLines_dict = {
'Auswahl': 1,
'Icon_Auswahl': 1,
'1_Zeile': 1,
'2_Zeile': 2,
'3_Zeile': 3,
'4_Zeile': 4,
'Langtext':1
}

ListLanguages_1 = ['English', 'German', 'Czech', 'Spanish', 'Italian', 'French', 'Portugese', 'USEnglish', 'Russian', 'CanadianFrench', 'Dutch', 'Swedish', 'Turkish', 'Norwegian', 'Polish', 'USSpanish']
