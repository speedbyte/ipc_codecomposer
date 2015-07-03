""" 


    $Date: 2009-06-23 15:46:24 +0200 (Di, 23 Jun 2009) $
    $Rev: 6848 $
    $Author: agrawal $
    $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/TOOLS/Python_scripts/trunk/DiagnoseScript/DiagApp_GUI.py $

    Copyright (c) 2008 S1nn GmbH & Co. KG.
    All Rights Reserved.


"""

_svn_id = "$Id$"
_svn_rev = "$Rev: 6848 $"
__version__ = _svn_rev[6:-2]



#!/usr/bin/env python
#Boa:App:BoaApp

fd = open("HelpFile.txt", "r")

HelpText = fd.read()
    

if __name__ == '__main__':
    main()
