""" 


    $Date: 2010-02-25 11:22:22 +0100 (Do, 25 Feb 2010) $
    $Rev: 11267 $
    $Author: agrawal $
    $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/TOOLS/Python_scripts/trunk/EEPROM_Script/EepromLayoutSettingsFile.py $

    Copyright (c) 2007 S1nn GmbH & Co. KG.
    All Rights Reserved.

"""

_svn_id = "$Id$"
_svn_rev = "$Rev: 11267 $"
__version__ = _svn_rev[6:-2]

import sys
import os


def generateTraceConfigFileChangeable(entireFile, generatedDirectory):
    print "Search for source files and generate Modifiable trace File\n"
    fd_generated_file = open(generatedDirectory+"/TRACE_CONFIG_CHANGEABLE.h", "wb")
    fd_generated_file.write("/******************************************************************************/\r\n")
    fd_generated_file.write("/*****************  Copyright (c) 2010 by S1nn GmbH & Co. KG  *****************/\r\n")
    fd_generated_file.write("/***************************  All Rights Reserved  ****************************/\r\n")
    fd_generated_file.write("/******************************************************************************/\r\n")    

    fd_generated_file.write("#ifndef _TRACE_CONFIG_CHANGEABLE_H\r\n")    
    fd_generated_file.write("#define _TRACE_CONFIG_CHANGEABLE_H\r\n")

    for line in entireFile:
        #print line
        fd_generated_file.write("\r\n")
        if "," in line and '=' in line:
            line_splitted = line.split(',')
            val = line_splitted[0].find('=')
            line_splitted = line_splitted[0][:val]
            line_splitted = line_splitted.strip(' ')
            line_splitted = line_splitted.strip('\t')
            print line_splitted
            line_splitted = line_splitted.replace('MOD_', '')
            fd_generated_file.write("#define " + line_splitted + "_SWI_ERR               1\r\n")
            fd_generated_file.write("#define " + line_splitted + "_SWI_WNG               1\r\n")
            fd_generated_file.write("#define " + line_splitted + "_SWI_TRC               1\r\n")
            fd_generated_file.write("#define " + line_splitted + "_SWI_DBG               0\r\n")

    fd_generated_file.write("#endif\r\n")
    fd_generated_file.close()

    return

def generateTraceConfigFile(entireFile, generatedDirectory):
    print "Search for source files and generate FileID\n"
    fd_generated_file = open(generatedDirectory+"/TRACE_CONFIG_GENERATED.h", "wb")
    fd_generated_file.write("/******************************************************************************/\r\n")
    fd_generated_file.write("/*****************  Copyright (c) 2010 by S1nn GmbH & Co. KG  *****************/\r\n")
    fd_generated_file.write("/***************************  All Rights Reserved  ****************************/\r\n")
    fd_generated_file.write("/******************************************************************************/\r\n")    

    fd_generated_file.write("#ifndef _TRACE_CONFIG_GENERATED_H\r\n")    
    fd_generated_file.write("#define _TRACE_CONFIG_GENERATED_H\r\n")

    fd_generated_file.write("#include \"TRACE_CONFIG_CHANGEABLE.h\"\r\n\r\n\r\n")

    for line in entireFile:
        #print line
        
        
        if "#define" in line and "_TRACE_CONFIG_CHANGEABLE_H" not in line:
            line_splitted = line.split(' ')
            print line_splitted[1]
            fd_generated_file.write("#if (1 == " + line_splitted[1] + ")\r\n")
            fd_generated_file.write("    #define " + line_splitted[1] + "_TEXT(moduleID, format)                                         LOG_TEXT(moduleID, format)\r\n")
            fd_generated_file.write("    #define " + line_splitted[1] + "_VALUE1(moduleID, format, value)                                LOG_VALUE1(moduleID, format, value)\r\n")
            fd_generated_file.write("    #define " + line_splitted[1] + "_VALUE2(moduleID, format, value1, value2)                       LOG_VALUE2(moduleID, format, value1, value2)\r\n")                        
            fd_generated_file.write("    #define " + line_splitted[1] + "_VALUE4(moduleID, format, value1, value2, value3, value4)       LOG_VALUE4(moduleID, format, value1, value2, value3, value4)\r\n")
            fd_generated_file.write("    #define " + line_splitted[1] + "_STRING(moduleID, format, string)                               LOG_STRING(moduleID, format, string)\r\n")
            fd_generated_file.write("    #define " + line_splitted[1] + "_STATE1(moduleID, format, state)                                LOG_STATE1(moduleID, format, state)\r\n")
            fd_generated_file.write("    #define " + line_splitted[1] + "_STATE2(moduleID, format, state1, state2)                       LOG_STATE2(moduleID, format, state1, state2)\r\n")
            fd_generated_file.write("    #define " + line_splitted[1] + "_STATE4(moduleID, format, state1, state2, state3, state4)       LOG_STATE4(moduleID, format, state1, state2, state3, state4)\r\n")                                                        

            fd_generated_file.write("#else\r\n")
            fd_generated_file.write("    #define " + line_splitted[1] + "_TEXT(moduleID, format)                                         {}\r\n")
            fd_generated_file.write("    #define " + line_splitted[1] + "_VALUE1(moduleID, format, value)                                {}\r\n")
            fd_generated_file.write("    #define " + line_splitted[1] + "_VALUE2(moduleID, format, value1, value2)                       {}\r\n")                        
            fd_generated_file.write("    #define " + line_splitted[1] + "_VALUE4(moduleID, format, value1, value2, value3, value4)       {}\r\n")
            fd_generated_file.write("    #define " + line_splitted[1] + "_STRING(moduleID, format, string)                               {}\r\n")
            fd_generated_file.write("    #define " + line_splitted[1] + "_STATE1(moduleID, format, state)                                {}\r\n")
            fd_generated_file.write("    #define " + line_splitted[1] + "_STATE2(moduleID, format, state1, state2)                       {}\r\n")
            fd_generated_file.write("    #define " + line_splitted[1] + "_STATE4(moduleID, format, state1, state2, state3, state4)       {}\r\n")                                                        

            fd_generated_file.write("#endif\r\n")

    fd_generated_file.write("#endif\r\n")
    fd_generated_file.close()

    return


def runScript(InputFilePath, InputFileDirectory, scriptDirectory):
    generatedDirectory = os.path.join(scriptDirectory,'../generated/' )
    toolsDirectory = os.path.join(scriptDirectory,'../tools/TraceScript/' )    

    fd = open(InputFilePath, "rb")
    entireFileInput = fd.readlines()
    fd.close()
    
    generateTraceConfigFileChangeable(entireFileInput, InputFileDirectory)
    
    InputFilePathChangeable = os.path.join(InputFileDirectory + "/TRACE_CONFIG_CHANGEABLE.h")    
    
    fd2 = open(InputFilePathChangeable, "rb")
    entireFile = fd2.readlines()
    fd2.close()
    
    generateTraceConfigFile(entireFile, InputFileDirectory)
    
    print 'END'


if __name__ == '__main__':
    print 'THIS IS NOT ALLOWED. USE THE GUI ( http://subversion-01/svn/SW_HW_System/Tools/PythonDiagnosticsTool/trunk ) TO GENERATE THE FILES.'    
