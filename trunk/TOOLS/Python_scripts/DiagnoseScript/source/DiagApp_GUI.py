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

import wx
import DiagFrame_1
import os

modules ={u'DiagFrame_1': [1, 'Main frame of Application', u'DiagFrame_1.py']}

class BoaApp(wx.App):
    def OnInit(self):
        self.main = DiagFrame_1.create(None)
        self.main.Show()
        self.SetTopWindow(self.main)
        return True

def main():
    application = BoaApp(0)
    application.MainLoop()
    

if __name__ == '__main__':
    main()
