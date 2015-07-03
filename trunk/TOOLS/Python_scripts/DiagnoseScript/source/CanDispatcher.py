""" 


    $Date: 2006-10-23 $
    $Rev: $
    $Author: bourgett $

    Copyright (c) 2004-2006 S1nn GmbH & Co. KG.
    All Rights Reserved.

"""

import threading
import Queue
import pyCAN
from time import time, clock, sleep

class CanMsgEnvelope:
    """ Envelope object for CAN message. It holds an additional
        Receive Timestamp
    """
    def __init__(self, msg, ts):
        self.Msg = msg
        self.Timestamp = ts

    def getMsg(self):
        return self.Msg

    def getTimestamp(self):
        return self.Timestamp
        

class CanFilter:
    """ Filter for CAN message IDs
    """
    def __init__(self):
        self.CanIDs = []

    def addCanID(self, canID):
        self.CanIDs.append(canID)

    def clearCanIDs(self):
        self.CanIDs = []

class CanFilterThread(threading.Thread):
    """ Thread for dispatching CAN messages from bus. It can be configured with filters
    """
    def __init__(self):
        threading.Thread.__init__(self)

        #prepare event flag for shutdown signal       
        self.shutdownNow = threading.Event()
        self.shutdownNow.clear()

        #set interval for message dispatching        
        self.fetchInterval = 0.001
        
        #Initialize empty Filter object
        self.Filter = CanFilter()

        #Set InQueue for messages coming from CAN bus
        self.RxQueue = Queue.Queue()

        #Set OutQueue for messages going to CAN bus         
        self.TxQueue = Queue.Queue()
        
        try:        
            self.canDriver = pyCAN.CanDriver()
        except:
            #Problems with CAN driver
            print "CAN driver Error.\n"
            sleep(10)
            self.stop()
            raise

    def __del__(self):
        if self.canDriver is not None:
            self.canDriver.close()

    def getRxQueue(self):
        return self.RxQueue

    def getTxQueue(self):
        return self.TxQueue
    
    def stop(self):
        self.shutdownNow.set()

    def run(self):
        #open or reopen can driver        
        self.canDriver.open()        

        #Loop until shutdown event        
        while(True):
            #Sleep before fetching next can message
            sleep(self.fetchInterval)

            # If shutdown event was issued, jump out of while loop and end thread
            if self.shutdownNow.isSet():
                break

            try:
                msg = self.canDriver.read()                  
            except pyCAN.QRCVEMPTY_Error:
                #Receive queue is empty, don't continue to process msg
                pass
            except pyCAN.UNKNOWN_Error:
                pass
            else:
                #check if filter for current CAN message exists
                for msgId in self.Filter.CanIDs:
                    if msg.ID == msgId:                    
                        try:
                            #Put CAN message in new object together with timestamp
                            #env = CanMsgEnvelope(msg, time())
                            #Forward message to filtered queue
                            self.RxQueue.put(msg,False)
                        except Queue.Full():
                            #TODO: error handling
                            print "InQueue is full, Dropping received CAN message."
            #Sending CAN messages now
            while not (self.TxQueue.empty()):
                try:
                    outMsg = self.TxQueue.get(False)
                except Queue.Empty:
                    #Send queue is now empty, continue
                    print 'CAN Send queue empty'
                    pass                  
                else:
                    try:
                        #Put msg on CAN bus
                        self.canDriver.write(outMsg)
                    except pyCAN.BUSOFF_Error:
                        self.canDriver.resetClient()

        self.canDriver.close()

    def addFilter(self, filter):
        self.Filter = None
        self.Filter = filter


class CanDispatcher(threading.Thread):
    """ Base class for CAN message dispatchers. Implement processQueuedMsg() to
        get useful functionality
    """
    def __init__(self):
        threading.Thread.__init__(self)
        
        self.RxQueue = Queue.Queue()
        self.TxQueue = Queue.Queue()

        self.CallBackFct = None
        
        self.fetchInterval = 0.001
        
        #prepare event flag for shutdown signal       
        self.shutdownNow = threading.Event()
        self.shutdownNow.clear()

    def setRxQueue(self, rxQueue):
        """ Set filtered queue (Origin of msg objects)
        """
        self.RxQueue = None
        self.RxQueue = rxQueue
        
    def getRxQueue(self):
        """ Returns filtered Queue from CanFilterThread            
        """
        return self.RxQueue
        
    def getTxQueue(self):
        return self.TxQueue

    def stop(self):
        self.shutdownNow.set()

    def registerCallBackFct(self, callMe):
        self.CallBackFct = callMe

    def processQueuedMsg(self):
        #Overload this function with wanted functionality
        #Default behaviour is reading and dropping messages
        try:
            msg = self.RxQueue.get(False)
        except Queue.Empty:
            pass
        else:
            #inform Listener
            self.CallBackFct(msg)

    def run(self):

        #Thread loop
        while(True):
            sleep(self.fetchInterval)
            
            if self.shutdownNow.isSet():
                break
            self.processQueuedMsg()            

                        
#Test application
if __name__ == '__main__':
  
    import wx

    class MyFrame(wx.Frame):
            def __init__(self):
                wx.Frame.__init__(self, None, title = "CanFilterThread Test GUI")
                self.Sender = None
                self.Timers = []
                self.FilterThread = None
                self.Dispatcher = CanDispatcher()
                self.Dispatcher.registerCallBackFct(self.logMessage)
                self.Dispatcher.start()
                
                # Create GUI elements                
                panel = wx.Panel(self)
                startButton = wx.Button(panel, wx.ID_ANY, "Start Test")
                stopButton = wx.Button(panel, wx.ID_ANY, "Stop Test, reset counter")
                self.Queue1Content = wx.TextCtrl(panel, wx.ID_ANY, "", style=wx.TE_RICH|wx.TE_MULTILINE)
                self.Queue2Content = wx.TextCtrl(panel, wx.ID_ANY, "", style=wx.TE_RICH|wx.TE_MULTILINE)
                buttons = wx.BoxSizer(wx.HORIZONTAL)
                buttons.Add(startButton, 0, wx.RIGHT, 15)
                buttons.Add(stopButton, 0, wx.RIGHT, 15)
                main = wx.BoxSizer(wx.VERTICAL)
                main.Add(buttons, 0, wx.ALL, 5)
                main.Add(self.Queue1Content, 1, wx.EXPAND|wx.ALL, 5)
                main.Add(self.Queue2Content, 1, wx.EXPAND|wx.ALL,5)
                panel.SetSizer(main)

                # Bind GUI events
                self.Bind(wx.EVT_BUTTON, self.OnStartButton, startButton)
                self.Bind(wx.EVT_BUTTON, self.OnStopButton, stopButton)
                self.Bind(wx.EVT_CLOSE, self.OnCloseWindow)

            def logMessage(self, msg):
                info = "%x %x %x %x %x %x %x %x %x\n" % (msg.ID, msg.DATA[0], msg.DATA[1], msg.DATA[2], msg.DATA[3], msg.DATA[4], msg.DATA[5], msg.DATA[6], msg.DATA[7])
                self.Queue2Content.AppendText(info)
                
            def initFilterThread(self):
                # Create and add filters to filter list
                filter = CanFilter()
               # filter.addCanID(0x3EB)
               # filter.addCanID(0x3E8)  
                filter.addCanID(0x76B)
                filter.addCanID(0x7D5)
                self.FilterThread.addFilter(filter)
                
            def OnStartButton(self, evt):
                self.Queue1Content.AppendText("Starting FilterThread\n")
                self.counter = 0
                if self.FilterThread == None:
                    self.FilterThread = CanFilterThread()
                    self.initFilterThread()
                    self.Dispatcher.setRxQueue(self.FilterThread.getRxQueue())
                    self.FilterThread.start()

            def OnStopButton(self, evt):
                self.counter = 0
                self.Queue1Content.AppendText("Stopping FilterThread, Reset counter\n")
                if self.FilterThread is not None:
                    self.FilterThread.stop()
                    self.FilterThread = None
                
            def OnCloseWindow(self, evt):
                self.StopThreads()
                self.Destroy()

            def StopThreads(self):
                if not self.FilterThread is None:
                    self.Queue1Content.AppendText("Stopping threads.\n")
                    self.FilterThread.stop()
                    self.FilterThread = None
                
    app = wx.App()
    frame = MyFrame()
    frame.Show()
    app.MainLoop()
