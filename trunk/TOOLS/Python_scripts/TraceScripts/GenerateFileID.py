# -*- coding: iso-8859-1 -*-
# Copyright (C) 2010  S1nn GmbH
# Author: Oliver.Braun@s1nn (Oliver Braun, base taken from Hayo Butz ;-)...)

import os
import os.path
import sys
import string
import shutil
import glob


#Target Directory for generate files
TargetDirectory = "./TEMP"

Root = "."

#makeoptsinc file definition
MakeOptsIncFile = "makeoptsinc"
#makeoptsinc file definition
MakeFileForMOD_RekursiveSubList = "MOD_RekursiveSubList"
#uCprojectopts file definition
MakeFileForuCprojectopts = "uCprojectopts"
#search the prozessor ID
SearchIdOfProzessor = "ucopts"

# global working directory list
WorkingDirList=[]
MakeFileWorkingDirList=[]


def GetNecessaryInformation():
    # look for directories
    try:
        AllList=os.listdir(".\\MOD")
    except:
        RootPoint = ".\\"
        AllList=os.listdir(RootPoint)
    for list in AllList:
        # only directories (no hide)
        if ((os.path.isdir(".\\MOD" +"\\"+list)) & (list.find(".") == -1)):
            WorkingDirList.append(list)
#    print WorkingDirList

    return

def LookForSourceDirs():
#    print "Search for Source Dirs\n"
    for list in WorkingDirList:
        pathname=".\\MOD"+"\\"+list+"\\src"
#        print pathname
        if (os.path.isdir(pathname)):
            MakeFileWorkingDirList.append(pathname)
#    print MakeFileWorkingDirList
    return

def LookForSourceFilesGenerateFileID():
    print "Search for source files and generate FileID\n"
    AllFoundFiles=[]
    FileID=0x000000
    print "Number of directories to parse" , len(MakeFileWorkingDirList)
    if (len(MakeFileWorkingDirList) != 0):
        pass
    else:
        MakeFileWorkingDirList.append(".\\src") # This is when someone clicks the Make batch from the Module level.
    for list in MakeFileWorkingDirList:
        FileLocationPatternC = list+"\\*.c"
        FoundFiles=glob.glob(FileLocationPatternC)
        for list in FoundFiles:
            FileID=FileID+0x10000
            (path, filename) = os.path.split(list)
            (name, extension) = os.path.splitext(filename)
            id_filename = path+ "\\" + name + ".id"
#            print "CWD: %s, File: %s" % (os.path.abspath(os.curdir), id_filename)
            output_id_file = open(id_filename, "wb+")
            output_id_file.write("#define __C_FILE_ID 0x%X\n" % FileID)
            output_id_file.close()
        AllFoundFiles.append(FoundFiles)
#    print AllFoundFiles
    return

def check_generation(Value, path):
    if ( Value in path):
        return True
    else:
        return False
    

def ReplaceMakeFile(Value):
    print "\nAutomatic %s generation" %(Value)
    AllFoundFiles=[]
    count = 1
    curpath = os.getcwd()
    fd6 = open(curpath + "/BUILD/SYS/ignoreMakefileList", "r")
    IgnoreModules = fd6.read()
    IgnoreModulesList = IgnoreModules.strip('').split('\n')
    """
    MakefileWorkingDirList: [.\MOD\MOD_ADC\src\, .\MOD\MOD_APP_CAN\src\]
    """
    for list1 in MakeFileWorkingDirList:
        fd5 = open(curpath + "/TOOLS/Python_scripts/TraceScripts/import_file_h.txt", "r")
        count = count + 1
        FileLocationPatternC = list1 + "\\*.c"
        FileLocationPatternASM = list1 + "\\*.asm"
        FoundFiles_C=glob.glob(FileLocationPatternC)
        FoundFiles_ASM=glob.glob(FileLocationPatternASM)
        (path, filename) = os.path.split(list1)
        GenerateMakefile = True
        for x in range(len(IgnoreModulesList)):
            if (IgnoreModulesList[x] == ""):
                continue
            elif  ( check_generation(IgnoreModulesList[x], path) == True ):
                print "ignoring generating makefile for %s " % (path)
                GenerateMakefile = False
            else:
                continue
        if ( GenerateMakefile == True ):
            makefile_fd = list1 + "\\" + Value
            output_id_file = open(makefile_fd, "wb+")
            
            output_id_file.write(fd5.read())
    
            output_id_file.write("LIBRARY = $(LIB_"+ WorkingDirList[count] + ")\n")
            output_id_file.write("OBJS= \\\n\t")
    
            for list in FoundFiles_C:
                (path_src, filename) = os.path.split(list)
                (name, extension) = os.path.splitext(filename)
                output_id_file.write(name + ".obj\\\n")
            for list in FoundFiles_ASM:
                (path_src, filename) = os.path.split(list)
                (name, extension) = os.path.splitext(filename)
                output_id_file.write(name + ".obj\\\n")
            AllFoundFiles.append(FoundFiles_C)
            output_id_file.write("\nall : $(LIBRARY)\n")
            output_id_file.write("$(LIBRARY): $(OBJS)\n\t")
            output_id_file.write("$(MODULEMAKE)\n\n")
            output_id_file.write("$(DEPEND)\n\n")
            output_id_file.write("\nclean:\n\t")
            output_id_file.write("$(MODULECLEAN)\n")
            output_id_file.close()
    fd5.close()
#    print AllFoundFiles
    return

# ###########
# Main part
# ###########
if __name__ == "__main__":
    # RunScript
    GetNecessaryInformation()
    LookForSourceDirs()
    LookForSourceFilesGenerateFileID()
    ReplaceMakeFile("makefile")
    ReplaceMakeFile("makefileModul")
    sys.exit(0)

