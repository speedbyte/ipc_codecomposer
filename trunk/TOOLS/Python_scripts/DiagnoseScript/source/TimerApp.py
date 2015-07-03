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
import time
import threading

class Timer(threading.Thread):
     def __init__(self, seconds):
         self.runTime = seconds
         threading.Thread.__init__(self)
     def run(self):
         time.sleep(self.runTime)
         print "Buzzzz!! Time's up!"
         
class CountDownTimer(Timer):
     def run(self):
         counter = self.runTime
         for sec in range(self.runTime):
             print counter
             time.sleep(1.0)
             counter -= 1
         print "Done."
         
class CountDownExec(CountDownTimer):
     def __init__(self, seconds, action):
         self.action = action
         CountDownTimer.__init__(self, seconds)

     def run(self):
         CountDownTimer.run(self)
         self.action()

     def myAction():
         print "Performing my action local"
     

if __name__ == '__main__':
    c = CountDownExec(10, myAction)
    c.start()
