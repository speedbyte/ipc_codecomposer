""" 

    $Date: 2009-06-25 12:07:53 +0200 (Do, 25 Jun 2009) $
    $Rev: 6883 $
    $Author: agrawal $
    $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/TOOLS/Python_scripts/trunk/DiagnoseScript/DiagApp.py $

    Copyright (c) 2008 S1nn GmbH & Co. KG.
    All Rights Reserved.

"""

_svn_id = "$Id$"
_svn_rev = "$Rev: 6883 $"
__version__ = _svn_rev[6:-2]


import pyCAN
import time
import Queue
from threading import Thread
import threading
import Queue



        
class CyclicSend(Thread):
    def __init__ (self, da_object):
        Thread.__init__(self)
        self.stopIt = False
        self.classobject = da_object
        self.CurrentEcu = "SCM"
        
    def stopSending(self):
        print "DA:Stop sending"
        self.stopIt = True
    
    def startSending(self):
        print "DA:Start sending"
        self.stopIt = False
  
    def setCurrentEcu(self, CurrentEcu):
        print "Current Ecu for CAN Messages is %s" % CurrentEcu
        self.CurrentEcu = CurrentEcu


    def init_parameters(self):
        self.stopIgnition = True
        self.stopTP = True
        self.stopSystemInfo_1 = True
        self.stopLanguageInfo = True
        self.stopNM = True
        self.stopCarConfig = True
        self.stopHMI = True
        self.CarConfigElement = 0
        if ( self.CurrentEcu == 'SCM_125'):
            self.UserInterface_GUI = __import__('UserInterface_GUI_SCM')
        
        elif ( self.CurrentEcu == 'UHV_100' or  self.CurrentEcu == 'UHV_500' or  self.CurrentEcu == 'Kombi_500'):
            self.UserInterface_GUI = __import__('UserInterface_GUI_UHV')
            
        elif ( self.CurrentEcu == 'UMI_100' or  self.CurrentEcu == 'UMI_500'):
            self.UserInterface_GUI = __import__('UserInterface_GUI_UMI')

        elif ( self.CurrentEcu == 'ADR_500'):
            self.UserInterface_GUI = __import__('UserInterface_GUI_ADR')
			
        elif ( self.CurrentEcu == 'OCU_500'):
            self.UserInterface_GUI = __import__('UserInterface_GUI_OCU')
            
        elif ( self.CurrentEcu == 'SYNC_500'):
            self.UserInterface_GUI = __import__('UserInterface_GUI_SYNC')

    
    def run(self):
      counter = 0
      while not (self.stopIt):
          time.sleep(0.1)
          counter = counter + 1
          if ( self.stopLanguageInfo == False ):
              if ( (counter % 10) == 0 ) :
                  msg1 = pyCAN.makeCanMsg(self.UserInterface_GUI.canmsg_dict_2[self.KombiLanguage][0], self.UserInterface_GUI.canmsg_dict_2[self.KombiLanguage][1])
                  try:
                      self.classobject.cd.write(msg1)
                  except pyCAN.BUSOFF_Error:
                      self.classobject.cd.resetClient()
                      print "Bus was Off, resetting the Tx and Rx buffer"  

          if ( self.stopCarConfig == False ):
              if ( (counter % 3) == 0 ) :
                  self.CarConfigElement = self.CarConfigElement + 1
                  messageLength = len(self.UserInterface_GUI.canmsg_dict_4[self.CarConfig])-1
                  msg1 = pyCAN.makeCanMsg(self.UserInterface_GUI.canmsg_dict_4[self.CarConfig][0], self.UserInterface_GUI.canmsg_dict_4[self.CarConfig][self.CarConfigElement])
                  if ( self.CarConfigElement == messageLength):
                      self.CarConfigElement = 0
                      self.stopCarConfig = True
                  try:
                      self.classobject.cd.write(msg1)
                  except pyCAN.BUSOFF_Error:
                      self.classobject.cd.resetClient()
                      print "Bus was Off, resetting the Tx and Rx buffer"  

    
          if ( self.stopIgnition == False ):
              if ( (counter % 2) == 0 ) :
                  msg1 = pyCAN.makeCanMsg(self.UserInterface_GUI.canmsg_dict_3[self.IgnitionSignal][0], self.UserInterface_GUI.canmsg_dict_3[self.IgnitionSignal][1])                             
                  try:
                      self.classobject.cd.write(msg1)
                  except pyCAN.BUSOFF_Error:
                      self.classobject.cd.resetClient()
                      print "Bus was Off, resetting the Tx and Rx buffer"  
     
          if ( self.stopSystemInfo_1 == False ):
              if ( (counter % 10) == 0 ) :
                  msg1 = pyCAN.makeCanMsg(self.canmsg_dict_2[self.IgnitionSignal][0], self.UserInterface_GUI.canmsg_dict_3[self.IgnitionSignal][1])                             
                  try:
                      self.classobject.cd.write(msg1)
                  except pyCAN.BUSOFF_Error:
                      self.classobject.cd.resetClient()
                      print "Bus was Off, resetting the Tx and Rx buffer"  

              try:
                  self.classobject.cd.write(msg1)
              except pyCAN.BUSOFF_Error:
                  self.classobject.cd.resetClient()
                  print "Bus was Off, resetting the Tx and Rx buffer"
            
          if ( self.stopHMI == False ):
              msg1 = pyCAN.makeCanMsg(self.UserInterface_GUI.canmsg_dict_5[self.HMI][0], self.UserInterface_GUI.canmsg_dict_5[self.HMI][1])
              try:
                  self.classobject.cd.write(msg1)
              except pyCAN.BUSOFF_Error:
                  self.classobject.cd.resetClient()
                  print "Bus was Off, resetting the Tx and Rx buffer"  

          if ( self.stopTP == False ):
              if ( (counter % 20) == 0 ) :
                  msg1 = pyCAN.makeCanMsg(self.UserInterface_GUI.canmsg_dict_6['TP'][0], self.UserInterface_GUI.canmsg_dict_6['TP'][1])
                  try:
                      self.classobject.cd.write(msg1)
                  except pyCAN.BUSOFF_Error:
                      self.classobject.cd.resetClient()
                      print "Bus was Off, resetting the Tx and Rx buffer"  

          if ( self.stopNM == False ):
              msg1 = pyCAN.makeCanMsg(self.UserInterface_GUI.canmsg_dict_7['Alive'][0], self.UserInterface_GUI.canmsg_dict_7['Alive'][1])
              try:
                  self.classobject.cd.write(msg1)
              except pyCAN.BUSOFF_Error:
                  self.classobject.cd.resetClient()
                  print "Bus was Off, resetting the Tx and Rx buffer"  



          if ( (counter % 60) == 0 ) :
              counter = 0                  



if __name__ == '__main__':
    time.sleep(1)
