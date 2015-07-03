#Boa:Frame:Frame1
""" 
    $Date: 2009-06-25 12:07:53 +0200 (Do, 25 Jun 2009) $
    $Rev: 6883 $
    $Author: agrawal $
    $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/TOOLS/Python_scripts/trunk/DiagnoseScript/DiagFrame_1.py $

    Copyright (c) 2008 S1nn GmbH & Co. KG.
    All Rights Reserved.
"""
import os
import wx
import sys
import re
import wx.gizmos
import wx.lib.buttons
import DiagApp
import Queue
import CanCyclicThread
from threading import Thread
from time import clock
import datetime
import time
import XML2Bin
import struct
import ConfigParser
import TimerApp
from HelpFile import HelpText
from datetime import date

def create(parent):
    Frame1Instance = Frame1(parent)
    return Frame1Instance

class QueueGet(Thread):
    
    def setFrameInstance(self, ref):
        self.Frame1Instance = ref
        
    def __init__ (self, queueobject, logger):
      Thread.__init__(self)
      self.print_q = queueobject
      self.logger_q = logger
      self.init_done_PrintQThread = True
      
  
    def run(self):
        while(1):
            if self.init_done_PrintQThread == True:
                try:
                  time.sleep(.001)
                  items  = self.print_q.get()
                  self.Frame1Instance.updateResultTextControl(items)
                  if ( self.logger_q.stopLogging == False ):
                      self.Frame1Instance.DTCLogger.write(items)
                except Queue.Empty:
                  print "message q is empty"

                  
class FrameActivities(Thread):
    def setFrameInstance(self, ref):
        self.Frame1Instance = ref

    def __init__(self, DiagAppInstance, MessageQInstance, MainQObject):
        Thread.__init__(self)
        self.message = None
        self.da = DiagAppInstance
        self.mq = MessageQInstance
        self.uq = MainQObject
        self.frameact_init_done = True
        self.response = None
        self.responseID = None
    
    def importUserInterface_GUI(self):
        self.CurrentEcu = self.Frame1Instance.comboBox1.GetValue()
        print self.CurrentEcu
        if ( self.CurrentEcu == 'SCM_125'):
            self.UserInterface_GUI = __import__('UserInterface_GUI_SCM')
        elif ( self.CurrentEcu == 'UHV_100' or self.CurrentEcu == 'Kombi_500' or self.CurrentEcu == 'UHV_500'):
            self.UserInterface_GUI = __import__('UserInterface_GUI_UHV')
        elif ( self.CurrentEcu == 'UMI_100' or 'UMI_500'):
            self.UserInterface_GUI = __import__('UserInterface_GUI_UMI')
        elif (self.CurrentEcu == 'ADR_500'):
            self.UserInterface_GUI = __import__('UserInterface_GUI_ADR')
        elif (self.CurrentEcu == 'OCU_500'):
            self.UserInterface_GUI = __import__('UserInterface_GUI_OCU')
        elif ( self.CurrentEcu == 'SYNC_500'):
            self.UserInterface_GUI = __import__('UserInterface_GUI_SYNC')
        return self.UserInterface_GUI
            
    def run(self):
        while ( 1 ):
            if self.frameact_init_done == True:
              try:
                  time.sleep(0.001)
                  items  = self.mq.get()
                  self.response, self.responseID, self.responseLength = self.da.SendReceiveMain(items)
                  if ( self.response == None or self.responseID == None):
                      while (1):
                          try:
                              items_flush = self.mq.get_nowait()
                          except Queue.Empty:
                              break
                  elif ( items[0][0] == 0x22 and (self.responseID == 0x62 )):
                        if (self.Frame1Instance.AppendTextToBenutzerDefinierteBox == True):
                            generated_list =  self.response[3:self.responseLength]
                            self.Frame1Instance.textCtrl1_BenutzerDefinierte.AppendText('  ,')                                    
                            self.Frame1Instance.ListBoxCommonFunction(generated_list)
                            self.AppendTextToBenutzerDefinierteBox = False
                        if ( self.Frame1Instance.DatadownloadIsActive == False ):
                            while ( self.Frame1Instance.queueInstance_UnicodeConvert.empty() == False ):
                                value = self.Frame1Instance.queueInstance_UnicodeConvert.get_nowait()
                                try:
                                    self.Frame1Instance.textCtrl1Result.AppendText(value)
                                except UnicodeDecodeError:
                                    pass
                  elif ( items[0][0] == 0x23 and (self.responseID == 0x63 )):
                        if (self.Frame1Instance.AppendTextToBenutzerDefinierteBox == True):
                            generated_list =  self.response[1:self.responseLength]
                            self.Frame1Instance.textCtrl1_BenutzerDefinierte.Clear()
                            self.Frame1Instance.ListBoxCommonFunction(generated_list)
                            self.AppendTextToBenutzerDefinierteBox = False
                        while ( self.Frame1Instance.queueInstance_UnicodeConvert.empty() == False ):
                            value = self.Frame1Instance.queueInstance_UnicodeConvert.get_nowait()
                            try:
                                self.Frame1Instance.textCtrl1Result.AppendText(value)
                            except UnicodeDecodeError:
                                pass
                  elif ( items[0][0] == 0x19 and (self.responseID == 0x59 )):  #Fehlerspeicher
                        #self.Frame1Instance.textCtrl1_BenutzerDefinierte.Clear()
                        self.Frame1Instance.listBox8.DeleteAllItems()
                        importUserInterface = self.importUserInterface_GUI()
                        dictDTC = importUserInterface.diagnostics_dict_DtcOverview
                        responseTemp=[]
                        i=0
                        count=0
                        
                        for item in self.response: 
                            responseTemp=self.response[i]
                            errorType=responseTemp.pop()#
                            if (errorType==0x09):
                                stringError = 'ACTIVE'
                            elif(errorType==0x08):
                                stringError='PASSIVE'  
                            elif(errorType==0x10):
                                stringError = 'Ungepr. Fehlerpfad' 
                            else:
                                stringError='UNKNOWN'
                            for dtc in dictDTC:
                                if responseTemp==dictDTC[dtc]: 
                                    line = " %s" % count
                                    self.Frame1Instance.listBox8.InsertStringItem(count, line)
                                    self.Frame1Instance.listBox8.SetStringItem(count, 1, dtc)
                                    self.Frame1Instance.listBox8.SetStringItem(count, 2, stringError)
#                                    if (errorType==0x09):
#                                        self.Frame1Instance.listBox8.SetItemTextColour(count, wx.BLUE)
                                    self.Frame1Instance.listBox8.Refresh()
                                    
                            count=count+1                           
                            i=i+1                                            
                        
                  elif ( items[0][0] == 0x36 and (self.responseID == 0x7F )):
                      while (1):
                          try:
                              items_flush = self.mq.get_nowait()
                          except Queue.Empty:
                              self.uq.put("Datensatz nicht geschrieben\r\n")
                              break
              except Queue.Empty:
                  print "message q is empty"
 
class Scripting(Thread):
    def __init__(self, DiagFrameInstance):
        Thread.__init__(self)
        self.diagFrameInstance = DiagFrameInstance
        self.stopLogging = True
        
    def setFrameInstance(self, ref):
        self.Frame1Instance = ref

    def run(self):
        while (1):
            time.sleep(1)
            if ( self.stopLogging == False ):
                generated_list =  self.diagFrameInstance.diagnostics_dict_DtcOverview['MIKROFON_DTC_GND']
                tosendmsg = [generated_list]
                self.diagFrameInstance.MessagequeueInstance.put(tosendmsg)
                


[wxID_FRAME1, wxID_FRAME1ADDFILTERBUTTON, wxID_FRAME1BUTTON1, 
 wxID_FRAME1BUTTON10, wxID_FRAME1BUTTON11, wxID_FRAME1BUTTON12, 
 wxID_FRAME1BUTTON13, wxID_FRAME1BUTTON1_ABFRAGEN, 
 wxID_FRAME1BUTTON1_BENUTZERDEFINIERTE, wxID_FRAME1BUTTON1_BENUTZERDEFINIERTE_CLEAR, wxID_FRAME1BUTTON2, 
 wxID_FRAME1BUTTON3,
 wxID_FRAME1BUTTON4, wxID_FRAME1BUTTON5, 
 wxID_FRAME1BUTTON6, wxID_FRAME1BUTTON7, wxID_FRAME1BUTTON8, 
 wxID_FRAME1BUTTON9, wxID_FRAME1CLEARTRACEBUTTON, wxID_FRAME1COMBOBOX1, 
 wxID_FRAME1COMBOBOX2, wxID_FRAME1COMBOBOX3, wxID_FRAME1COMBOBOX4, wxID_FRAME1COMBOBOX5,
 wxID_FRAME1COMBOBOX6, wxID_FRAME1COMBOBOX7, wxID_FRAME1COMBOBOX8, wxID_FRAME1COMBOBOX9,  
 wxID_FRAME1LISTBOX1, wxID_FRAME1LISTBOX2, wxID_FRAME1LISTBOX3, 
 wxID_FRAME1LISTBOX4, wxID_FRAME1LISTBOX5, wxID_FRAME1LISTBOX6, 
 wxID_FRAME1LISTBOX7, wxID_FRAME1LISTBOX8,
 wxID_FRAME1PANEL1, wxID_FRAME1PANEL2, wxID_FRAME1PANEL3, 
 wxID_FRAME1PANEL4, wxID_FRAME1PANEL5, wxID_FRAME1PANEL6,
 wxID_FRAME1PANEL7, wxID_FRAME1PANEL8, wxID_FRAME1PANEL9, 
 wxID_FRAME1QUEUE1CONTENT, wxID_FRAME1QUEUE2CONTENT, wxID_FRAME1STARTBUTTON, 
 wxID_FRAME1STATICTEXT1, wxID_FRAME1STATICTEXT2, wxID_FRAME1STATICTEXT3, 
 wxID_FRAME1STATICTEXT4, wxID_FRAME1STATICTEXT5, wxID_FRAME1STATICTEXT7, 
 wxID_FRAME1STATICTEXT8, wxID_FRAME1STATICTEXT9, wxID_FRAME1STATICTEXT_HIGHBYTE, 
 wxID_FRAME1STATICTEXT_LENGTH, wxID_FRAME1STATICTEXT_LOWBYTE, 
 wxID_FRAME1STATICTEXT_RESULT, wxID_FRAME1STOPBUTTON, wxID_FRAME1TEXTCTRL1, 
 wxID_FRAME1TEXTCTRL1RESULT, wxID_FRAME1TEXTCTRL1_BENUTZERDEFINIERTE, 
 wxID_FRAME1TEXTCTRL4_RESULT, wxID_FRAME1TEXTCTRL_HIGHBYTE, 
 wxID_FRAME1TEXTCTRL_LENGTH, wxID_FRAME1TEXTCTRL_LOWBYTE, wxID_FRAME1BUTTON14,
 wxID_FRAME1BUTTON15, wxID_FRAME1BUTTON16,wxID_FRAME1BUTTON17,wxID_HELPTEXTCTRL,
 wxID_FRAME1BUTTON18,wxID_FRAME1BUTTON19, wxID_FRAME1BUTTON20, wxID_FRAME1BUTTON21, wxID_FRAME1BUTTON22
] = [wx.NewId() for _init_ctrls in range(78)]

class Frame1(wx.Frame):
    def _init_utils(self):
        # generated method, don't edit
        self.menuBar1 = wx.MenuBar()
        self.flagCreateLogFile=False       
        self.syncstart=0     
        self.TimeStamp=0   
        
    def _init_ctrls(self, prnt):
        # generated method, don't edit
        space = ' '*175
        print space
        wx.Frame.__init__(self, id=wxID_FRAME1, name='', parent=prnt,
              pos=wx.Point(0, 0), size=wx.Size(1279, 689),
              style=wx.DEFAULT_FRAME_STYLE, title='Python Diagnostics and Developmet Tool Version 2.0'+space+'by Vikas Agrawal')
        self._init_utils()
        self.SetClientSize(wx.Size(1242, 661))

        self.panel1 = wx.Panel(id=wxID_FRAME1PANEL1, name='panel1', parent=self,
              pos=wx.Point(0, 32), size=wx.Size(784, 630),
              style=wx.TAB_TRAVERSAL)

        self.panel2 = wx.Panel(id=wxID_FRAME1PANEL2, name='panel2', parent=self,
              pos=wx.Point(800, 32), size=wx.Size(472, 630),
              style=wx.TAB_TRAVERSAL)

        self.panel3 = wx.Panel(id=wxID_FRAME1PANEL3, name='panel3', parent=self,
              pos=wx.Point(0, 0), size=wx.Size(1272, 32),
              style=wx.TAB_TRAVERSAL)

        self.panel4 = wx.Panel(id=wxID_FRAME1PANEL4, name='panel4', parent=self,
              pos=wx.Point(0, 32), size=wx.Size(784, 630),
              style=wx.TAB_TRAVERSAL)

        self.panel5 = wx.Panel(id=wxID_FRAME1PANEL5, name='panel5', parent=self,
              pos=wx.Point(0, 32), size=wx.Size(784, 630),
              style=wx.TAB_TRAVERSAL)

        self.panel6 = wx.Panel(id=wxID_FRAME1PANEL6, name='panel6', parent=self,
              pos=wx.Point(0, 32), size=wx.Size(784, 630),
              style=wx.TAB_TRAVERSAL)

        self.panel7 = wx.Panel(id=wxID_FRAME1PANEL7, name='panel7', parent=self,
              pos=wx.Point(0, 32), size=wx.Size(784, 630),
              style=wx.TAB_TRAVERSAL)

        self.panel8 = wx.Panel(id=wxID_FRAME1PANEL8, name='panel8', parent=self,
              pos=wx.Point(0, 32), size=wx.Size(784, 630),
              style=wx.TAB_TRAVERSAL)

        self.panel9 = wx.Panel(id=wxID_FRAME1PANEL9, name='panel9', parent=self,
              pos=wx.Point(0, 32), size=wx.Size(784, 630),
              style=wx.TAB_TRAVERSAL)


# Panel 1:

# Buttons
        self.StartDiagnosticsButton = wx.Button(id=wxID_FRAME1BUTTON8,
              label='Start Diagnostics', name='StartDiagnosticsButton',
              parent=self.panel1, pos=wx.Point(650, 487), size=wx.Size(120, 23),
              style=0)
        self.StartDiagnosticsButton.Enable(False)
        self.StartDiagnosticsButton.Bind(wx.EVT_BUTTON, self.OnButton8Button,
              id=wxID_FRAME1BUTTON8)

        self.DataDownloadButton = wx.Button(id=wxID_FRAME1BUTTON7,
              label='Data Download', name='DataDownloadButton',
              parent=self.panel1, pos=wx.Point(650, 512), size=wx.Size(120, 23),
              style=0)
        self.DataDownloadButton.Enable(False)
        self.DataDownloadButton.Bind(wx.EVT_BUTTON, self.OnButton1_DataDownload,
              id=wxID_FRAME1BUTTON7)

        self.button5 = wx.Button(id=wxID_FRAME1BUTTON5, label='START',
              name='button5', parent=self.panel1, pos=wx.Point(650, 599),
              size=wx.Size(50, 23), style=0)
        self.button5.Enable(False)
        self.button5.Bind(wx.EVT_BUTTON, self.OnButton1_StellgliedStart,
              id=wxID_FRAME1BUTTON5)

        self.button6 = wx.Button(id=wxID_FRAME1BUTTON6, label='STOP',
              name='button6', parent=self.panel1, pos=wx.Point(720, 599),
              size=wx.Size(50, 23), style=0)
        self.button6.Enable(False)
        self.button6.Bind(wx.EVT_BUTTON, self.OnButton1_StellgliedStop,
              id=wxID_FRAME1BUTTON6)


# Listboxes

        # Listbox Measurement Value
        self.staticText1 = wx.StaticText(id=wxID_FRAME1STATICTEXT1,
              label='Measurement Value', name='staticText1', parent=self.panel1,
              pos=wx.Point(8, 10), size=wx.Size(95, 13), style=0)
        self.listBox1 = wx.ListBox(choices=[], id=wxID_FRAME1LISTBOX1,
              name='listBox1', parent=self.panel1, pos=wx.Point(8, 25),
              size=wx.Size(380, 135), style=wx.LB_HSCROLL)
        self.listBox1.Bind(wx.EVT_LISTBOX, self.OnListBox1Listbox,
              id=wxID_FRAME1LISTBOX1)

        # Listbox Calibration Data Writable
        self.staticText2 = wx.StaticText(id=wxID_FRAME1STATICTEXT2,
              label='Calibration Data Writable', name='staticText2',
              parent=self.panel1, pos=wx.Point(390, 10), size=wx.Size(121, 13),
              style=0)
        self.listBox2 = wx.ListBox(choices=[], id=wxID_FRAME1LISTBOX2,
              name='listBox2', parent=self.panel1, pos=wx.Point(390, 25),
              size=wx.Size(380, 135), style=wx.LB_HSCROLL)
        self.listBox2.Bind(wx.EVT_LISTBOX, self.OnListBox2Listbox,
              id=wxID_FRAME1LISTBOX2)

        # Listbox ECU Identification Writable
        self.staticText5 = wx.StaticText(id=wxID_FRAME1STATICTEXT5,
              label='ECU Identification Writable', name='staticText5',
              parent=self.panel1, pos=wx.Point(390, 168), size=wx.Size(130, 13),
              style=0)
        self.listBox3 = wx.ListBox(choices=[], id=wxID_FRAME1LISTBOX3,
              name='listBox3', parent=self.panel1, pos=wx.Point(390, 183),
              size=wx.Size(380, 135), style=wx.LB_HSCROLL)
        self.listBox3.Bind(wx.EVT_LISTBOX, self.OnListBox3Listbox,
              id=wxID_FRAME1LISTBOX3)

        # Listbox Ecu Identification
        self.staticText3 = wx.StaticText(id=wxID_FRAME1STATICTEXT3,
              label='Ecu Identification', name='staticText3',
              parent=self.panel1, pos=wx.Point(8, 168), size=wx.Size(84, 13),
              style=0)
        self.listBox4 = wx.ListBox(choices=[], id=wxID_FRAME1LISTBOX4,
              name='listBox4', parent=self.panel1, pos=wx.Point(8, 183),
              size=wx.Size(380, 135), style=wx.LB_HSCROLL)
        self.listBox4.Bind(wx.EVT_LISTBOX, self.OnListBox4Listbox,
              id=wxID_FRAME1LISTBOX4)

        # Listbox Miscallenous
        self.staticText4 = wx.StaticText(id=wxID_FRAME1STATICTEXT4,
              label='Miscallenous', name='staticText4', parent=self.panel1,
              pos=wx.Point(8, 320), size=wx.Size(60, 13), style=0)
        self.listBox5 = wx.ListBox(choices=[], id=wxID_FRAME1LISTBOX5,
              name='listBox5', parent=self.panel1, pos=wx.Point(8, 335),
              size=wx.Size(380, 135), style=wx.LB_HSCROLL)
        self.listBox5.Bind(wx.EVT_LISTBOX, self.OnListBox5Listbox,
              id=wxID_FRAME1LISTBOX5)

        # Listbox Actuator Test
        self.staticText7 = wx.StaticText(id=wxID_FRAME1STATICTEXT7,
              label='Actuator Test', name='staticText7', parent=self.panel1,
              pos=wx.Point(390, 320), size=wx.Size(67, 13), style=0)
        self.listBox6 = wx.ListBox(choices=[], id=wxID_FRAME1LISTBOX6,
              name='listBox6', parent=self.panel1, pos=wx.Point(390, 335),
              size=wx.Size(380, 135), style=wx.LB_HSCROLL)
        self.listBox6.Bind(wx.EVT_LISTBOX, self.OnListBox6Listbox,
              id=wxID_FRAME1LISTBOX6)

        # Listbox Identifier Variant Coding
        self.staticText8 = wx.StaticText(id=wxID_FRAME1STATICTEXT8,
              label='Identifier Variant Coding', name='staticText8',
              parent=self.panel1, pos=wx.Point(650, 555), size=wx.Size(120, 13),
              style=0)
        self.listBox7 = wx.ListBox(choices=[], id=wxID_FRAME1LISTBOX7,
              name='listBox7', parent=self.panel1, pos=wx.Point(650, 570),
              size=wx.Size(120, 20), style=wx.LB_HSCROLL)
        self.listBox7.Bind(wx.EVT_LISTBOX, self.OnListBox7Listbox,
              id=wxID_FRAME1LISTBOX7)

        # Listbox DTCs
        self.staticText9 = wx.StaticText(id=wxID_FRAME1STATICTEXT9,
              label='DTCs', name='staticText9', parent=self.panel1,
              pos=wx.Point(8, 472), size=wx.Size(120, 13), style=0)
        self.listBox8 = wx.ListCtrl(id=wxID_FRAME1LISTBOX8,
              name='listBox8', parent=self.panel1, pos=wx.Point(8, 487),
              size=wx.Size(626, 135), style=wx.LC_REPORT|wx.BORDER_SUNKEN)
        self.listBox8.Bind(wx.EVT_LISTBOX, self.OnListBox8Listbox,
              id=wxID_FRAME1LISTBOX8)
# Panel 1 End 
        
# Panel 2 Start

        self.textCtrl1_BenutzerDefinierte = wx.TextCtrl(id=wxID_FRAME1TEXTCTRL1_BENUTZERDEFINIERTE,
              name='textCtrl1_BenutzerDefinierte', parent=self.panel2,
              pos=wx.Point(14, 25), size=wx.Size(420, 23), style=0,
              value='0x22, 0xF1, 0x8c')

        self.BenutzerdefinierteAbfrageButton = wx.Button(id=wxID_FRAME1BUTTON1_BENUTZERDEFINIERTE,
              label='Benutzer Definierte Abfrage',
              name='BenutzerdefinierteAbfrageButton', parent=self.panel2,
              pos=wx.Point(14, 50), size=wx.Size(370, 23), style=0)
        self.BenutzerdefinierteAbfrageButton.Enable(False)
        self.BenutzerdefinierteAbfrageButton.Bind(wx.EVT_BUTTON,
              self.OnButton1_BenutzerDefinierteButton,
              id=wxID_FRAME1BUTTON1_BENUTZERDEFINIERTE)

        self.ClearBenutzerdefinierteAbfrageButton = wx.Button(id=wxID_FRAME1BUTTON1_BENUTZERDEFINIERTE_CLEAR,
              label='Clear',
              name='ClearBenutzerdefinierteAbfrageButton', parent=self.panel2,
              pos=wx.Point(385, 50), size=wx.Size(50, 23), style=0)
        self.ClearBenutzerdefinierteAbfrageButton.Enable(False)
        self.ClearBenutzerdefinierteAbfrageButton.Bind(wx.EVT_BUTTON,
              self.OnButton1_BenutzerDefinierteButton_Clear,
              id=wxID_FRAME1BUTTON1_BENUTZERDEFINIERTE_CLEAR)

        self.textCtrl4_Result = wx.TextCtrl(id=wxID_FRAME1TEXTCTRL4_RESULT,
              name='textCtrl4_Result', parent=self.panel2, pos=wx.Point(14,
              83), size=wx.Size(420, 282), style=wx.TE_MULTILINE, value='')

        self.ResultButton = wx.Button(id=wxID_FRAME1BUTTON3, label='>> Result',
              name='ResultButton', parent=self.panel2, pos=wx.Point(14, 375),
              size=wx.Size(420, 23), style=0)
        self.ResultButton.Enable(False)
        self.ResultButton.Bind(wx.EVT_BUTTON, self.OnButton3Button,
              id=wxID_FRAME1BUTTON3)

        self.textCtrl1Result = wx.TextCtrl(id=wxID_FRAME1TEXTCTRL1RESULT,
              name='textCtrl1Result', parent=self.panel2, pos=wx.Point(14, 400),
              size=wx.Size(420, 222), style=wx.TE_MULTILINE, value='')

# Panel 2 End

# Panel 3 Start

        self.button1 = wx.Button(id=wxID_FRAME1BUTTON1, label='EMV',
              name='button1', parent=self.panel3, pos=wx.Point(8, 8),
              size=wx.Size(100, 23), style=0)
        self.button1.Bind(wx.EVT_BUTTON, self.EMV_Button, id=wxID_FRAME1BUTTON1)

        self.button9 = wx.Button(id=wxID_FRAME1BUTTON9, label='Diagnostics',
              name='button9', parent=self.panel3, pos=wx.Point(118, 8),
              size=wx.Size(100, 23), style=0)
        self.button9.Bind(wx.EVT_BUTTON, self.Diagnsotics_Button,
              id=wxID_FRAME1BUTTON9)

        self.button11 = wx.Button(id=wxID_FRAME1BUTTON11, label='CAN Messages',
              name='button11', parent=self.panel3, pos=wx.Point(228, 8),
              size=wx.Size(100, 23), style=0)
        self.button11.Bind(wx.EVT_BUTTON, self.CANMessages_Button,
              id=wxID_FRAME1BUTTON11)

        self.button12 = wx.Button(id=wxID_FRAME1BUTTON12, label='CAN Tracer',
              name='button12', parent=self.panel3, pos=wx.Point(338, 8),
              size=wx.Size(100, 23), style=0)
        self.button12.Bind(wx.EVT_BUTTON, self.OnButton12Button,
              id=wxID_FRAME1BUTTON12)

        self.button13 = wx.Button(id=wxID_FRAME1BUTTON13, label='EEPROM',
              name='button13', parent=self.panel3, pos=wx.Point(448, 8),
              size=wx.Size(100, 23), style=0)
        self.button13.Bind(wx.EVT_BUTTON, self.OnEEPROM_Button,
              id=wxID_FRAME1BUTTON13)

        self.button17 = wx.Button(id=wxID_FRAME1BUTTON17, label='HELP',
              name='button17', parent=self.panel3, pos=wx.Point(558, 8),
              size=wx.Size(100, 23), style=0)
        self.button17.Bind(wx.EVT_BUTTON, self.OnHELP_Button,
              id=wxID_FRAME1BUTTON17)

        self.button18 = wx.Button(id=wxID_FRAME1BUTTON18, label='TOOLS',
              name='button18', parent=self.panel3, pos=wx.Point(668, 8),
              size=wx.Size(100, 23), style=0)
        self.button18.Bind(wx.EVT_BUTTON, self.OnTOOLS_Button,
              id=wxID_FRAME1BUTTON18)

        
        self.comboBox1 = wx.ComboBox(choices=['UHV_100', 'UHV_500', 'Kombi_500', 'SCM_125',
              'SYNC_500', 'ADR_500', 'OCU_500' , 'ClosePeak' , 'UMI_100', 'UMI_500', 'IPODOut_125'],
              id=wxID_FRAME1COMBOBOX1, name='comboBox1', parent=self.panel3,
              pos=wx.Point(1110, 8), size=wx.Size(125, 23), style=0,
              value='Select Device')
        self.comboBox1.SetLabel('Select Device')
        self.comboBox1.SetStringSelection('')
        self.comboBox1.Bind(wx.EVT_COMBOBOX, self.OnComboBox1Combobox,
              id=wxID_FRAME1COMBOBOX1)



# Panel 3 End

# Panel 4 Start

        self.EmvAudioLoopBackButton = wx.ToggleButton(id=wxID_FRAME1BUTTON15,
              label='Audio LoopBack', name='EmvAudioLoopBackButton',
              parent=self.panel4, pos=wx.Point(32, 140), size=wx.Size(80, 23),
              style=0)
        self.EmvAudioLoopBackButton.Enable(False)
        self.EmvAudioLoopBackButton.Bind(wx.EVT_TOGGLEBUTTON,
              self.OnButton15Button, id=wxID_FRAME1BUTTON15)

        self.EmvLogDtcButton = wx.ToggleButton(id=wxID_FRAME1BUTTON16,
              label='Log DTC', name='EmvLogDtcButton', parent=self.panel4,
              pos=wx.Point(32, 180), size=wx.Size(80, 23), style=0)
        self.EmvLogDtcButton.Enable(False)
        self.EmvLogDtcButton.Bind(wx.EVT_TOGGLEBUTTON, self.OnButton16Button,
              id=wxID_FRAME1BUTTON16)

# Panel 4 End

# Panel 5 Start
        self.StartCanTracingButton = wx.Button(id=wxID_FRAME1STARTBUTTON,
              label="Start Test", name='StartCanTracingButton',
              parent=self.panel5, pos=wx.Point(8, 25), size=wx.Size(320, 23),
              style=0)
        self.StartCanTracingButton.Enable(False)
        self.StartCanTracingButton.Bind(wx.EVT_BUTTON, self.OnStartButton,
              id=wxID_FRAME1STARTBUTTON)

        self.StopCanTracingButton = wx.Button(id=wxID_FRAME1STOPBUTTON,
              label="Stop Test, reset counter", name='StopCanTracingButton',
              parent=self.panel5, pos=wx.Point(338, 25), size=wx.Size(320, 23),
              style=0)
        self.StopCanTracingButton.Enable(False)
        self.StopCanTracingButton.Bind(wx.EVT_BUTTON, self.OnStopButton,
              id=wxID_FRAME1STOPBUTTON)
        
        self.LogTraceCheckbox = wx.CheckBox(self.panel5, -1, label="Save Trace", name='LogTraceCheckbox', pos=wx.Point(668, 50), size=wx.Size(100,25)) #'Save Trace' 
        self.Bind(wx.EVT_CHECKBOX, self.OnLogTraceCheckbox, self.LogTraceCheckbox)
        self.LogTraceCheckbox.SetValue(True)
        
        self.textCtrlLogFilePath = wx.TextCtrl(id=wxID_FRAME1TEXTCTRL1, name='textCtrlLogFilePath',
              parent=self.panel5, pos=wx.Point(448, 50), size=wx.Size(210, 23),
              style=0, value='log/log1.asc')
        
        

#        self.Queue1Content = wx.TextCtrl(id=wxID_FRAME1QUEUE1CONTENT,
#              name='Queue1Content', parent=self.panel5, pos=wx.Point(16, 112),
#              size=wx.Size(368, 112), style=wx.TE_RICH|wx.TE_MULTILINE,
#              value='')

        self.staticTextFilter = wx.StaticText(id=wxID_FRAME1STATICTEXT8,
              label='Filter', name='Filter',
              parent=self.panel5, pos=wx.Point(10, 55), size=wx.Size(30, 23),
              style=0) 
        
        self.textCtrl1 = wx.TextCtrl(id=wxID_FRAME1TEXTCTRL1, name='textCtrl1',
              parent=self.panel5, pos=wx.Point(38, 50), size=wx.Size(288, 23),
              style=0, value='0x665, 0x5C1')

        self.Queue2Content = wx.TextCtrl(id=wxID_FRAME1QUEUE2CONTENT,
              name='Queue2Content', parent=self.panel5, pos=wx.Point(8, 83),
              size=wx.Size(760, 540), style=wx.TE_RICH|wx.TE_MULTILINE,
              value='')
        font1 = wx.Font(10, wx.MODERN, wx.NORMAL, wx.NORMAL, False, u'Consolas')
        self.Queue2Content.SetFont(font1)

#        self.addFilterButton = wx.Button(id=wxID_FRAME1ADDFILTERBUTTON,
#              label='addFilter', name='addFilterButton', parent=self.panel5,
#              pos=wx.Point(216, 72), size=wx.Size(75, 23), style=0)
#        self.addFilterButton.Enable(False)
#        self.addFilterButton.Bind(wx.EVT_BUTTON, self.OnAddFilterButtonButton,
#              id=wxID_FRAME1ADDFILTERBUTTON)

        self.ClearCanTracesButton = wx.Button(id=wxID_FRAME1CLEARTRACEBUTTON,
              label='Clear Trace', name='ClearCanTracesButton',
              parent=self.panel5, pos=wx.Point(668, 25), size=wx.Size(100, 23),
              style=0)
        self.ClearCanTracesButton.Enable(False)
        self.ClearCanTracesButton.Bind(wx.EVT_BUTTON,
              self.OnClearCanTracesButtonButton,
              id=wxID_FRAME1CLEARTRACEBUTTON)
        
        self.CreateLogFileButton = wx.Button(id=wxID_FRAME1CLEARTRACEBUTTON,
              label='Create new Log', name='CreateLogFileButton',
              parent=self.panel5, pos=wx.Point(338, 50), size=wx.Size(100, 23),
              style=0)
        self.CreateLogFileButton.Enable(False)
        self.CreateLogFileButton.Bind(wx.EVT_BUTTON,
              self.OnCreateLogFileButton,
              id=wxID_FRAME1CLEARTRACEBUTTON)

# Panel 5 End

#Panel 6 Start

        self.comboBox2 = wx.ComboBox(choices=[''], id=wxID_FRAME1COMBOBOX2,
              name='comboBox2', parent=self.panel6, pos=wx.Point(24, 200),
              size=wx.Size(112, 21), style=0, value='CAN ID 1')
        self.comboBox2.SetStringSelection('')
        self.comboBox2.Bind(wx.EVT_COMBOBOX, self.OnComboBox2Combobox,
              id=wxID_FRAME1COMBOBOX2)

        self.comboBox3 = wx.ComboBox(choices=[''], id=wxID_FRAME1COMBOBOX3,
              name='comboBox3', parent=self.panel6, pos=wx.Point(154, 200),
              size=wx.Size(112, 21), style=0, value='CAN ID 2')
        self.comboBox3.SetStringSelection('')
        self.comboBox3.Bind(wx.EVT_COMBOBOX, self.OnComboBox3Combobox,
              id=wxID_FRAME1COMBOBOX3)

        self.comboBox4 = wx.ComboBox(choices=[''], id=wxID_FRAME1COMBOBOX4,
              name='comboBox4', parent=self.panel6, pos=wx.Point(294, 200),
              size=wx.Size(112, 21), style=0, value='CAN ID 3')
        self.comboBox4.SetStringSelection('')
        self.comboBox4.Bind(wx.EVT_COMBOBOX, self.OnComboBox4Combobox,
              id=wxID_FRAME1COMBOBOX4)

        self.comboBox5 = wx.ComboBox(choices=[''], id=wxID_FRAME1COMBOBOX5,
              name='comboBox5', parent=self.panel6, pos=wx.Point(434, 200),
              size=wx.Size(112, 21), style=0, value='CAN ID 4')
        self.comboBox5.SetStringSelection('')
        self.comboBox5.Bind(wx.EVT_COMBOBOX, self.OnComboBox5Combobox,
              id=wxID_FRAME1COMBOBOX5)

        self.comboBox6 = wx.ComboBox(choices=[''], id=wxID_FRAME1COMBOBOX6,
              name='comboBox6', parent=self.panel6, pos=wx.Point(24, 100),
              size=wx.Size(112, 21), style=0, value='CAN ID 5')
        self.comboBox6.SetStringSelection('')
        self.comboBox6.Bind(wx.EVT_COMBOBOX, self.OnComboBox6Combobox,
              id=wxID_FRAME1COMBOBOX6)

        self.comboBox7 = wx.ComboBox(choices=[''], id=wxID_FRAME1COMBOBOX7,
              name='comboBox7', parent=self.panel6, pos=wx.Point(154, 100),
              size=wx.Size(112, 21), style=0, value='CAN ID 6')
        self.comboBox7.SetStringSelection('')
        self.comboBox7.Bind(wx.EVT_COMBOBOX, self.OnComboBox7Combobox,
              id=wxID_FRAME1COMBOBOX7)

        self.comboBox8 = wx.ComboBox(choices=[''], id=wxID_FRAME1COMBOBOX8,
              name='comboBox8', parent=self.panel6, pos=wx.Point(294, 100),
              size=wx.Size(112, 21), style=0, value='CAN ID 7')
        self.comboBox8.SetStringSelection('')
        self.comboBox8.Bind(wx.EVT_COMBOBOX, self.OnComboBox8Combobox,
              id=wxID_FRAME1COMBOBOX8)

        self.comboBox9 = wx.ComboBox(choices=[''], id=wxID_FRAME1COMBOBOX9,
              name='comboBox9', parent=self.panel6, pos=wx.Point(434, 100),
              size=wx.Size(112, 21), style=0, value='CAN ID 8')
        self.comboBox9.SetStringSelection('')
        self.comboBox9.Bind(wx.EVT_COMBOBOX, self.OnComboBox9Combobox,
              id=wxID_FRAME1COMBOBOX9)

        self.ScmAliveButton = wx.ToggleButton(id=wxID_FRAME1BUTTON14,
              label='SCM', name='ScmAliveButton', parent=self.panel6,
              pos=wx.Point(24, 20), size=wx.Size(80, 23), style=0)
        self.ScmAliveButton.Enable(False)
        self.ScmAliveButton.Bind(wx.EVT_TOGGLEBUTTON, self.OnButton14Button,
              id=wxID_FRAME1BUTTON14)

        self.TesterPresentButton = wx.ToggleButton(id=wxID_FRAME1BUTTON2,
              label='Select TesterPresent', name='TesterPresentButton',
              parent=self.panel6, pos=wx.Point(154, 20), size=wx.Size(112, 23),
              style=0)
        self.TesterPresentButton.Enable(False)
        self.TesterPresentButton.Bind(wx.EVT_TOGGLEBUTTON, self.OnButton2Button,
              id=wxID_FRAME1BUTTON2)

# Panel 6 End

#Panel 7 Start
        self.staticText_HighByte = wx.StaticText(id=wxID_FRAME1STATICTEXT_HIGHBYTE,
              label='High Byte', name='staticText_HighByte', parent=self.panel7,
              pos=wx.Point(24, 40), size=wx.Size(47, 13), style=0)

        self.staticText_LowByte = wx.StaticText(id=wxID_FRAME1STATICTEXT_LOWBYTE,
              label='Low Byte', name='staticText_LowByte', parent=self.panel7,
              pos=wx.Point(24, 80), size=wx.Size(45, 13), style=0)

        self.staticText_Length = wx.StaticText(id=wxID_FRAME1STATICTEXT_LENGTH,
              label='Length', name='staticText_Length', parent=self.panel7,
              pos=wx.Point(24, 128), size=wx.Size(34, 13), style=0)

        self.textCtrl_HighByte = wx.TextCtrl(id=wxID_FRAME1TEXTCTRL_HIGHBYTE,
              name='textCtrl_HighByte', parent=self.panel7, pos=wx.Point(88,
              32), size=wx.Size(100, 21), style=0, value='0x00')

        self.textCtrl_LowByte = wx.TextCtrl(id=wxID_FRAME1TEXTCTRL_LOWBYTE,
              name='textCtrl_LowByte', parent=self.panel7, pos=wx.Point(88, 80),
              size=wx.Size(100, 21), style=0, value='0x0B')

        self.textCtrl_Length = wx.TextCtrl(id=wxID_FRAME1TEXTCTRL_LENGTH,
              name='textCtrl_Length', parent=self.panel7, pos=wx.Point(88, 120),
              size=wx.Size(100, 21), style=0, value='0x4')

        self.ReadE2PButton = wx.Button(id=wxID_FRAME1BUTTON1_ABFRAGEN,
              label='EEPROM Abfragen', name='ReadE2PButton', parent=self.panel7,
              pos=wx.Point(24, 168), size=wx.Size(104, 32), style=0)
        self.ReadE2PButton.Enable(False)
        self.ReadE2PButton.Bind(wx.EVT_BUTTON, self.OnButton1_AbfragenButton,
              id=wxID_FRAME1BUTTON1_ABFRAGEN)

        self.ReadEntireE2PButton = wx.Button(id=wxID_FRAME1BUTTON4,
              label='Read Entire EEPROM', name='ReadEntireE2PButton',
              parent=self.panel7, pos=wx.Point(136, 168), size=wx.Size(112, 32),
              style=0)
        self.ReadEntireE2PButton.Enable(False)
        self.ReadEntireE2PButton.Bind(wx.EVT_BUTTON,
              self.OnButton1_ReadEntireEeprom, id=wxID_FRAME1BUTTON4)

        self.E2PWriteButton = wx.Button(id=wxID_FRAME1BUTTON10,
              label='EEPROM Schreiben', name='E2PWriteButton',
              parent=self.panel7, pos=wx.Point(200, 32), size=wx.Size(104, 32),
              style=0)
        self.E2PWriteButton.Enable(False)
        self.E2PWriteButton.Bind(wx.EVT_BUTTON, self.OnButton_EEPROMSchreiben,
              id=wxID_FRAME1BUTTON10)

#Panel 7 End

#Panel 8 Start

        self.textCtrl_Help = wx.StaticText(id=wxID_HELPTEXTCTRL,
              name='textCtrl_Help', label=HelpText, parent=self.panel8, pos=wx.Point(10,
              32), size=wx.Size(774, 630), style=0)

#Panel 8 End

#Panel 9 Start

        self.SignalGenerator= wx.Button(id=wxID_FRAME1BUTTON19, label='Signal Generator',
              name='button19', parent=self.panel9, pos=wx.Point(32, 140),
              size=wx.Size(100, 23), style=0)
        self.SignalGenerator.Bind(wx.EVT_BUTTON, self.OnSignalGenerator_Button, id=wxID_FRAME1BUTTON19)

        self.KombiTextPrompts= wx.Button(id=wxID_FRAME1BUTTON20, label='KombiTextPrompts',
              name='button20', parent=self.panel9, pos=wx.Point(32, 190),
              size=wx.Size(100, 23), style=0)
        self.KombiTextPrompts.Bind(wx.EVT_BUTTON, self.OnGenerateKombiTextPrompts_Button, id=wxID_FRAME1BUTTON20)

        self.EepromDataGenerateButton= wx.Button(id=wxID_FRAME1BUTTON21, label='EepromGenerate',
              name='button21', parent=self.panel9, pos=wx.Point(32, 240),
              size=wx.Size(100, 23), style=0)
        self.EepromDataGenerateButton.Bind(wx.EVT_BUTTON, self.OnGenerateEepromData_Button, id=wxID_FRAME1BUTTON21)

        self.TraceGenerateButton= wx.Button(id=wxID_FRAME1BUTTON22, label='TraceConfigGenerate',
              name='button22', parent=self.panel9, pos=wx.Point(32, 290),
              size=wx.Size(100, 23), style=0)
        self.TraceGenerateButton.Bind(wx.EVT_BUTTON, self.OnGenerateTraceConfig_Button, id=wxID_FRAME1BUTTON22)


#Panel 9 End

    
    def __init__(self, parent):
        self._init_ctrls(parent)

        self.panel1.Hide()
        self.panel4.Hide()
        self.panel5.Hide()        
        self.panel6.Hide()
        self.panel7.Hide()        
        self.panel8.Show()
        self.panel9.Hide()

        self.comboBox2.Enable(False)
        self.comboBox3.Enable(False)
        self.comboBox4.Enable(False)
        self.comboBox5.Enable(False)

        self.comboBox6.Enable(False)
        self.comboBox7.Enable(False)
        self.comboBox8.Enable(False)
        self.comboBox9.Enable(False)

        self.Sender = None
        self.Timers = []
        self.FilterThread = None
        self.Dispatcher = DiagApp.CanDispatcher()
        self.Dispatcher.registerCallBackFct(self.logMessage)
        self.Dispatcher.start()
        # Create GUI elements                
        buttons = wx.BoxSizer(wx.HORIZONTAL)
        #self.panel5.SetSizer(main)
    
        # Bind GUI events
        self.Bind(wx.EVT_CLOSE, self.OnCloseWindow)
       
        
        self.date = datetime.date(1, 1, 1 )
        self.queueInstance = Queue.Queue(0)
        self.queueInstance_UnicodeConvert = Queue.Queue(0)
        self.da = DiagApp.DiagApp(self.queueInstance, self.queueInstance_UnicodeConvert )
        self.cyclicSender = CanCyclicThread.CyclicSend(self.da)
        self.cyclicSender.init_parameters()
        self.cyclicSender.start()

#Thread 2

        self.loggingThread = Scripting(self)
        #self.loggingThread.setFrameInstance(self)
        self.loggingThread.start()


# Thread 1
        self.queuestart = QueueGet(self.queueInstance, self.loggingThread)
        self.queuestart.setFrameInstance(self)
        self.queuestart.start()


        self.toggle_TP = 0

        self.textCtrl1_BenutzerDefinierte.SetFocus()
        self.MessagequeueInstance = Queue.Queue(0)
        
        self.threadMessageSend = FrameActivities(self.da, self.MessagequeueInstance, self.queueInstance)
        self.threadMessageSend.setFrameInstance(self)
        
        self.threadMessageSend.start()
        self.filter = DiagApp.CanFilter()
        self.initFilterThread()
        self.AppendTextToBenutzerDefinierteBox = False
        self.DatadownloadIsActive = False

    def logMessage(self, msg):
        substrinfo=[]
        if self.flagCreateLogFile is True:
            self.syncstart=clock()
            self.flagCreateLogFile=False        
        self.TimeStamp=(clock() - self.syncstart)                        
        data_tuple = ("%.6f" %(self.TimeStamp),"1","0x%X" % msg.ID,"Rx","d",str(msg.LEN))
        
        time = "%11s" % ("%4.6f" %(self.TimeStamp))
        info = time +" 1  " + "%4s" % "%.3X" % msg.ID + "             Rx   d " + str(msg.LEN)     
        for index in range(msg.LEN):
            data_tuple = data_tuple + ("%.2X" % msg.DATA[index],)
            info = "%s %.2X" % (info, msg.DATA[index])

        self.Queue2Content.AppendText(info+"\n")
        if (self.Queue2Content.GetNumberOfLines()>10000):
            self.Queue2Content.Clear()            
        
        if self.LogTraceCheckbox.GetValue() is True:
            try:
                path = self.textCtrlLogFilePath.GetValue()
                self.file = open(path,'a')
                self.file.write(info+"\n")        
                self.file.close()
            except IOError,ioe:
                print "File Not Found"
                self.createMessageDlg("Error", "File not found")                
            except IOException,ex:
                print ex
        
    def initFilterThread(self):
        # Create and add filters to filter list
        self.FilterThread = DiagApp.CanFilterThread(self.da)
        self.filter.clearCanIDs()
        createdmsg_string = self.textCtrl1.GetValue()
        splitted_userdefined_text = createdmsg_string.split(',')
        print splitted_userdefined_text
        for element in range(len(splitted_userdefined_text)):
            self.filter.addCanID(int(splitted_userdefined_text[element],16))
        self.FilterThread.addFilter(self.filter)
        self.Dispatcher.setRxQueue(self.FilterThread.getRxQueue())
        self.FilterThread.start()
        self.IsFilterThreadRunning = False
    
    
    def createMessageDlg(self,title,msg): 
        dlg = wx.MessageDialog(self, msg,
                               title,
                               wx.OK | wx.ICON_INFORMATION
                               #wx.YES_NO | wx.NO_DEFAULT | wx.CANCEL | wx.ICON_INFORMATION
                               )
        dlg.ShowModal()
        dlg.Destroy() 
            
    def OnStartButton(self, evt):

        self.queuestart.init_done_PrintQThread = False
        self.counter = 0
        
        self.filter.clearCanIDs()
        
        createdmsg_string = self.textCtrl1.GetValue()
        splitted_userdefined_text = createdmsg_string.split(',')
        
        
        # exception muss hinzugefuegt werden
        if createdmsg_string!="":
            for element in range(len(splitted_userdefined_text)):
                self.filter.addCanID(int(splitted_userdefined_text[element],16))
        
        
        
        if self.IsFilterThreadRunning is False: 
            self.FilterThread.startAgain()
            self.IsFilterThreadRunning = True
            self.BenutzerdefinierteAbfrageButton.Enable(False)  

    def OnLogTraceCheckbox(self, evt):
        pass
    
    def OnStopButton(self, evt):
        self.counter = 0
        self.queuestart.init_done_PrintQThread = True
        if self.IsFilterThreadRunning is True:
            self.FilterThread.stop()
            self.IsFilterThreadRunning = False
            self.BenutzerdefinierteAbfrageButton.Enable(True)                        
       
    def OnCloseWindow(self, evt):
        self.StopThreads()
        self.Destroy()

    def StopThreads(self):
        if not self.FilterThread is None:
            #self.Queue1Content.AppendText("Stopping threads.\n")
            self.Queue2Content.AppendText("Stopping threads.\n")
            self.FilterThread.stop()
            self.FilterThread = None

    def InitialiseMiniVas(self):
        """
        This contains coding and reading the values on UHV.
        The info put in the send message q is : [dict["UserInterface_GUI]]
        """
        if ( self.CurrentEcu == 'SCM_125'):
            generated_list = self.diagnostics_dict_Miscallenous['DIAGNOSE_SESSION']
            generated_list = generated_list + self.diagnostics_dict_All_WriteDataByIdentifier['ExtendedDiagSession']
            tosendmsg = [generated_list]
            self.MessagequeueInstance.put(tosendmsg)
    

        elif ( self.CurrentEcu == 'UHV_100' or self.CurrentEcu == 'UHV_500' or self.CurrentEcu == 'Kombi_500' or self.CurrentEcu == 'ADR_500' or self.CurrentEcu == 'OCU_500' or self.CurrentEcu == 'UMI_100' or self.CurrentEcu == 'UMI_500'):
            generated_list = self.diagnostics_dict_Miscallenous['DIAGNOSE_SESSION']
            generated_list = generated_list + self.diagnostics_dict_All_WriteDataByIdentifier['ExtendedDiagSession']
            tosendmsg = [generated_list]
            self.MessagequeueInstance.put(tosendmsg)
    
            generated_list =  self.diagnostics_dict_EcuIdentificationWritable['WERKSTATTCODE_DAS_ANGESCHLOSSENEN_TESTERS']
            generated_list = generated_list + self.diagnostics_dict_All_WriteDataByIdentifier['Werkstatt_Code_Parameters']
            tosendmsg = [generated_list]
            self.MessagequeueInstance.put(tosendmsg)
            
            generated_list =  self.diagnostics_dict_EcuIdentificationWritable['PROGRAMMING_DATE']
            yymmdd = self.date.today()
            generated_list = generated_list + [yymmdd.year % 2000, yymmdd.month, yymmdd.day]
            tosendmsg = [generated_list]
            self.MessagequeueInstance.put(tosendmsg)

        elif ( self.CurrentEcu == 'SYNC_500'):
                generated_list =  self.diagnostics_dict_IdentifierMeasurementValue['EnterDiagSessionStart']
                tosendmsg = [generated_list]
                self.MessagequeueInstance.put(tosendmsg)
    
                generated_list =  self.diagnostics_dict_IdentifierMeasurementValue['StartEol']
                tosendmsg = [generated_list]
                self.MessagequeueInstance.put(tosendmsg)
    
                generated_list =  self.diagnostics_dict_IdentifierMeasurementValue['SetEOLCCPUPin']
                tosendmsg = [generated_list]
                self.MessagequeueInstance.put(tosendmsg)
    
                generated_list =  self.diagnostics_dict_IdentifierMeasurementValue['ColdRebootCCPUStart']
                tosendmsg = [generated_list]
                self.MessagequeueInstance.put(tosendmsg)
    
                generated_list =  self.diagnostics_dict_IdentifierMeasurementValue['ColdRebootCCPUResult']
                tosendmsg = [generated_list]
                self.MessagequeueInstance.put(tosendmsg)
            
    def OnButton1_AbfragenButton(self, event):
        self.AppendTextToBenutzerDefinierteBox = True
        HighByte = int(self.textCtrl_HighByte.GetValue(), 0)
        LowByte = int(self.textCtrl_LowByte.GetValue(), 0)
        Length = int(self.textCtrl_Length.GetValue(), 0)
        createdmsg = [[0x10, 0x4F]]
        self.MessagequeueInstance.put(createdmsg)
        createdmsg = [[0x23, 0x12, HighByte, LowByte, Length]]
        self.MessagequeueInstance.put(createdmsg)
        print "Button press completed"
            
    def updateResultTextControl(self, value):
        pos = self.textCtrl4_Result.GetLastPosition()
        self.textCtrl4_Result.AppendText(value)

    def OnButton1_BenutzerDefinierteButton(self, event):
        createdmsg = []
        tosendmsg = []
        print "User Defined button pressed"
#===============================================================================
#        for x in range(len(self.list_combo_boxes)):
#            self.list_combo_boxes[x].Enable(False)
#===============================================================================
        createdmsg_string = self.textCtrl1_BenutzerDefinierte.GetValue()
        splitted_userdefined_text = createdmsg_string.split(',')
        for element in range(len(splitted_userdefined_text)):
            try:
                createdmsg.append(int(splitted_userdefined_text[element], 0))
            except:
                x = splitted_userdefined_text[element].encode('utf-8')
                UnpackAndConvertToHex = map(hex, struct.unpack(len(splitted_userdefined_text[element])*'B',splitted_userdefined_text[element]))
                print UnpackAndConvertToHex
                for element_name in range(len(UnpackAndConvertToHex)):
                    createdmsg.append(int(UnpackAndConvertToHex[element_name], 0))
                for element_name in range(30 - len(UnpackAndConvertToHex)):
                    createdmsg.append(0x00)             
        tosendmsg.append(createdmsg)
        self.MessagequeueInstance.put(tosendmsg)

    def OnButton2Button(self, event):
        if ( self.TesterPresentButton.GetValue() is True ): # button not pressed
            self.cyclicSender.stopTP = False
            print "Start TP"            
        else:
            self.cyclicSender.stopTP = True
            print "Stop TP"

    def sendReadBeforeWrite(self, event):
        createdmsg_string = self.textCtrl1_BenutzerDefinierte.GetValue()
        print createdmsg_string
        createdmsg_string_temp = createdmsg_string.replace('0x2e', '0x22')
        self.textCtrl1_BenutzerDefinierte.Clear()
        self.textCtrl1_BenutzerDefinierte.AppendText(createdmsg_string_temp) 
        self.OnButton1_BenutzerDefinierteButton(event)
        self.textCtrl1_BenutzerDefinierte.Clear()
        self.textCtrl1_BenutzerDefinierte.AppendText(createdmsg_string) 
        
    def NotifyPanelListener(self, param, data):
#===============================================================================
#        if param == self.listBox2 and ( data == 'SET_NUMBER_ROAMING_FOR_INFO_CALL' or
#                                        data == 'SET_NUMBER_ROAMING_FOR_SERVICE_CALL' or
#                                        data == 'SET_NUMBER_FOR_INFO_CALL' or
#                                        data == 'SET_NUMBER_FOR_SERVICE_CALL' or
#                                        data == 'EMERGENCY_NUMBER'):
#            self.textCtrl2.Enable(True)
#        else:
#            self.textCtrl2.Enable(False)
#===============================================================================
        if param == self.listBox7 :
            self.button5.Enable(True)
            self.button6.Enable(True)
            self.button5.SetLabel("VALID") 
            self.button6.SetLabel("INVALID")
        elif param == self.listBox6:
            self.button5.Enable(True)
            self.button6.Enable(True)
            self.button5.SetLabel("START") 
            self.button6.SetLabel("STOP")
        else:
            self.button5.Enable(False)
            self.button6.Enable(False)

    def ListBoxCommonFunction(self, generated_list):
        for element in range(len(generated_list)):
            if ( isinstance(generated_list[element], basestring ) == False):
                self.textCtrl1_BenutzerDefinierte.AppendText(hex(generated_list[element]) + ',')
            else:
                self.textCtrl1_BenutzerDefinierte.AppendText((generated_list[element]) + ',')
        cur_pos = self.textCtrl1_BenutzerDefinierte.GetLastPosition()
        self.textCtrl1_BenutzerDefinierte.Remove(cur_pos-1, cur_pos)
    

    def OnListBox1Listbox(self, event):
        self.AppendTextToBenutzerDefinierteBox = False
        self.textCtrl1_BenutzerDefinierte.Clear()
        selected_list = self.listBox1.GetSelection()
        selected_data = self.listBox1.GetClientData(selected_list)
        generated_list =  self.diagnostics_dict_IdentifierMeasurementValue[selected_data]
        self.ListBoxCommonFunction(generated_list)
        self.NotifyPanelListener(self.listBox1, selected_data)
        self.sendReadBeforeWrite(event)
        
    def OnListBox2Listbox(self, event):
        self.AppendTextToBenutzerDefinierteBox = True
        self.textCtrl1_BenutzerDefinierte.Clear()
        selected_list = self.listBox2.GetSelection()
        selected_data = self.listBox2.GetClientData(selected_list)
        generated_list =  self.diagnostics_dict_CalibrationDataWritable[selected_data]
        self.ListBoxCommonFunction(generated_list)
        self.NotifyPanelListener(self.listBox2, selected_data)
        self.sendReadBeforeWrite(event)
        
      
    def OnListBox3Listbox(self, event):
        self.AppendTextToBenutzerDefinierteBox = True
        self.textCtrl1_BenutzerDefinierte.Clear()
        selected_list = self.listBox3.GetSelection()
        selected_data = self.listBox3.GetClientData(selected_list)
        generated_list =  self.diagnostics_dict_EcuIdentificationWritable[selected_data]
#        if (selected_data ==  'WERKSTATTCODE_DAS_ANGESCHLOSSENEN_TESTERS'):
#            generated_list = generated_list + self.diagnostics_dict_All_WriteDataByIdentifier['Werkstatt_Code_Parameters']
#        elif (selected_data ==  'PROGRAMMING_DATE'):
#            yymmdd = self.date.today()
#            date_list  = [yymmdd.year % 2000, yymmdd.month, yymmdd.day]
#            generated_list = generated_list + date_list
        self.ListBoxCommonFunction(generated_list)
        self.NotifyPanelListener(self.listBox3, selected_data)
        self.sendReadBeforeWrite(event)

        
    def OnListBox4Listbox(self, event):
        self.AppendTextToBenutzerDefinierteBox = False
        self.textCtrl1_BenutzerDefinierte.Clear()
        selected_list = self.listBox4.GetSelection()
        selected_data = self.listBox4.GetClientData(selected_list)
        generated_list =  self.diagnostics_dict_EcuIdentification[selected_data]
        self.ListBoxCommonFunction(generated_list)
        self.NotifyPanelListener(self.listBox4, selected_data)       
        self.sendReadBeforeWrite(event)            
        
    def OnListBox5Listbox(self, event):
        self.AppendTextToBenutzerDefinierteBox = False
        self.textCtrl1_BenutzerDefinierte.Clear()
        selected_list = self.listBox5.GetSelection()
        selected_data = self.listBox5.GetClientData(selected_list)
        generated_list =  self.diagnostics_dict_Miscallenous[selected_data]
        self.ListBoxCommonFunction(generated_list)
        self.NotifyPanelListener(self.listBox5, selected_data)
        self.sendReadBeforeWrite(event)           

       
    def OnListBox6Listbox(self, event):
        self.AppendTextToBenutzerDefinierteBox = False
        self.textCtrl1_BenutzerDefinierte.Clear()
        selected_list = self.listBox6.GetSelection()
        selected_data = self.listBox6.GetClientData(selected_list)
        generated_list =  self.diagnostics_dict_ActuatorTest[selected_data]
        self.ListBoxCommonFunction(generated_list)
        self.NotifyPanelListener(self.listBox6, selected_data)
        
       
    def OnListBox7Listbox(self, event):
        self.AppendTextToBenutzerDefinierteBox = True
        self.textCtrl1_BenutzerDefinierte.Clear()
        selected_list = self.listBox7.GetSelection()
        selected_data = self.listBox7.GetClientData(selected_list)
        generated_list =  self.diagnostics_dict_CodierungWritable[selected_data]
        self.ListBoxCommonFunction(generated_list)
        self.NotifyPanelListener(self.listBox7, selected_data)
        self.sendReadBeforeWrite(event)   
        
    def OnListBox8Listbox(self, event):
        self.AppendTextToBenutzerDefinierteBox = False
        self.textCtrl1_BenutzerDefinierte.Clear()
        selected_list = self.listBox8.GetSelection()
        selected_data = self.listBox8.GetClientData(selected_list)
        generated_list =  self.diagnostics_dict_DtcOverview[selected_data]
        self.ListBoxCommonFunction(generated_list)
        self.NotifyPanelListener(self.listBox8, selected_data)   

            
    def fillListBox(self):
        self.CurrentEcu = self.comboBox1.GetValue()        
        
        self.comboBox2.Clear()
        self.comboBox3.Clear()
        self.comboBox4.Clear()
        self.comboBox5.Clear()
        self.comboBox6.Clear()
        self.comboBox7.Clear()
        self.comboBox8.Clear()
        self.comboBox9.Clear()

        self.listBox1.Clear()
        self.listBox2.Clear()
        self.listBox3.Clear()
        self.listBox4.Clear()
        self.listBox5.Clear()
        self.listBox6.Clear()
        self.listBox7.Clear()
        self.listBox8.ClearAll()
        print self.CurrentEcu
        
        if ( self.CurrentEcu == 'SCM_125'):
            self.UserInterface_GUI = __import__('UserInterface_GUI_SCM')
        elif ( self.CurrentEcu == 'UHV_100' or self.CurrentEcu == 'Kombi_500' or self.CurrentEcu == 'UHV_500'):
            self.UserInterface_GUI = __import__('UserInterface_GUI_UHV')
        elif ( self.CurrentEcu == 'UMI_100' or 'UMI_500'):
            self.UserInterface_GUI = __import__('UserInterface_GUI_UMI')
        elif (self.CurrentEcu == 'ADR_500'):
            self.UserInterface_GUI = __import__('UserInterface_GUI_ADR')
        elif (self.CurrentEcu == 'OCU_500'):
            self.UserInterface_GUI = __import__('UserInterface_GUI_OCU')
        elif ( self.CurrentEcu == 'SYNC_500'):
            self.UserInterface_GUI = __import__('UserInterface_GUI_SYNC')
            self.diagnostics_dict_IdentifierMeasurementValue = self.UserInterface_GUI.diagnostics_dict_IdentifierMeasurementValue
            self.diagnostics_dict_EcuIdentification = self.UserInterface_GUI.diagnostics_dict_EcuIdentification
            messageseq = self.diagnostics_dict_IdentifierMeasurementValue
            self.listBox1.SetThemeEnabled(False)
            self.listBox1.SetLabel('')
            count = 0
            for item in messageseq:
                self.listBox1.Insert(item,count,item)
                count = count + 1
    
            messageseq = self.diagnostics_dict_EcuIdentification
            self.listBox4.SetThemeEnabled(False)
            self.listBox4.SetLabel('')
            count = 0
            for item in messageseq:
                self.listBox4.Insert(item,count,item)
                count = count + 1
    

        else:
            print "No valid project was found"
            self.UserInterface_GUI = __import__('UserInterface_GUI_Default')
            
        
        self.diagnostics_dict_IdentifierMeasurementValue = self.UserInterface_GUI.diagnostics_dict_IdentifierMeasurementValue
        self.diagnostics_dict_CalibrationDataWritable = self.UserInterface_GUI.diagnostics_dict_CalibrationDataWritable
        self.diagnostics_dict_EcuIdentificationWritable = self.UserInterface_GUI.diagnostics_dict_EcuIdentificationWritable
        self.diagnostics_dict_EcuIdentification = self.UserInterface_GUI.diagnostics_dict_EcuIdentification
        self.diagnostics_dict_Miscallenous = self.UserInterface_GUI.diagnostics_dict_Miscallenous 
        self.diagnostics_dict_ActuatorTest = self.UserInterface_GUI.diagnostics_dict_ActuatorTest
        self.diagnostics_dict_CodierungWritable = self.UserInterface_GUI.diagnostics_dict_CodierungWritable
        self.diagnostics_dict_All_WriteDataByIdentifier = self.UserInterface_GUI.diagnostics_dict_All_WriteDataByIdentifier
        self.diagnostics_dict_DtcOverview = self.UserInterface_GUI.diagnostics_dict_DtcOverview

        messageseq = self.diagnostics_dict_IdentifierMeasurementValue
        self.listBox1.SetThemeEnabled(False)
        self.listBox1.SetLabel('')
        count = 0
        #print messageseq        
        for item in messageseq:
            self.listBox1.Insert(item,count,item)
            count = count + 1

        messageseq = self.diagnostics_dict_CalibrationDataWritable
        self.listBox2.SetThemeEnabled(False)
        self.listBox2.SetLabel('')
        count = 0
        for item in messageseq:
            self.listBox2.Insert(item,count,item)
            count = count + 1

        messageseq = self.diagnostics_dict_EcuIdentificationWritable
        self.listBox3.SetThemeEnabled(False)
        self.listBox3.SetLabel('')
        count = 0
        for item in messageseq:
            self.listBox3.Insert(item,count,item)
            count = count + 1

        messageseq = self.diagnostics_dict_EcuIdentification
        self.listBox4.SetThemeEnabled(False)
        self.listBox4.SetLabel('')
        count = 0
        for item in messageseq:
            self.listBox4.Insert(item,count,item)
            count = count + 1

        messageseq = self.diagnostics_dict_Miscallenous
        self.listBox5.SetThemeEnabled(False)
        self.listBox5.SetLabel('')
        count = 0
        for item in messageseq:
            self.listBox5.Insert(item,count,item)
            count = count + 1

        messageseq = self.diagnostics_dict_ActuatorTest
        self.listBox6.SetThemeEnabled(False)
        self.listBox6.SetLabel('')
        count = 0
        for item in messageseq:
            self.listBox6.Insert(item,count,item)
            count = count + 1

        messageseq = self.diagnostics_dict_CodierungWritable
        self.listBox7.SetThemeEnabled(False)
        self.listBox7.SetLabel('')
        count = 0
        for item in messageseq:
            self.listBox7.Insert(item,count,item)
            count = count + 1
            
        messageseq = self.diagnostics_dict_DtcOverview
        self.listBox8.SetThemeEnabled(False)
        self.listBox8.SetLabel('')
        count = 0
        self.listBox8.InsertColumn(0,'Num')
        self.listBox8.SetColumnWidth(0,50)
        self.listBox8.InsertColumn(1,'Fehler')
        self.listBox8.SetColumnWidth(1,400)
        self.listBox8.InsertColumn(2,'Fehlertyp')
        self.listBox8.SetColumnWidth(2,150)
#        for item in messageseq:
#            self.listBox8.Insert(item,count,item)
#            count = count + 1

        
        messageseq = self.UserInterface_GUI.canmsg_dict_2
        self.comboBox2.SetThemeEnabled(False)
        self.comboBox2.SetLabel('Select Language')
        count = 0
        for item in messageseq:
            self.comboBox2.Insert(item,count,item)
            count = count + 1
        
        messageseq = self.UserInterface_GUI.canmsg_dict_3
        self.comboBox3.SetThemeEnabled(False)
        self.comboBox3.SetLabel('Select Ignition')
        count = 0
        for item in messageseq:
            self.comboBox3.Insert(item,count,item)
            count = count + 1

        messageseq = self.UserInterface_GUI.canmsg_dict_4
        self.comboBox4.SetThemeEnabled(False)
        self.comboBox4.SetLabel('Select CarConfig')
        count = 0
        for item in messageseq:
            self.comboBox4.Insert(item,count,item)
            count = count + 1
            
        messageseq = self.UserInterface_GUI.canmsg_dict_5
        self.comboBox5.SetThemeEnabled(False)
        self.comboBox5.SetLabel('Select Abschaltstufe')
        count = 0
        for item in messageseq:
            self.comboBox5.Insert(item,count,item)
            count = count + 1

        messageseq = self.UserInterface_GUI.canmsg_dict_6
        self.comboBox6.SetThemeEnabled(False)
        self.comboBox6.SetLabel('')
        count = 0
        for item in messageseq:
            self.comboBox6.Insert(item,count,item)
            count = count + 1
            
        messageseq = self.UserInterface_GUI.canmsg_dict_7
        self.comboBox7.SetThemeEnabled(False)
        self.comboBox7.SetLabel('')
        count = 0
        for item in messageseq:
            self.comboBox7.Insert(item,count,item)
            count = count + 1

       
    def OnButton3Button(self, event):
        while ( self.queueInstance_UnicodeConvert.empty() == False ):
            value = self.queueInstance_UnicodeConvert.get_nowait()
            self.textCtrl1Result.AppendText(value)

    def OnButton1_BenutzerDefinierteButton_Clear(self, event):
        #print "Clear Benutzer Definierte Abfrage Window"
        self.textCtrl4_Result.Clear()
        self.textCtrl1Result.Clear()

    def OnButton1_StellgliedStart(self, event):
        generated_list = []
        tosendmsg = []
        createdmsg_string = self.textCtrl1_BenutzerDefinierte.GetValue()
        splitted_userdefined_text = createdmsg_string.split(',')
        for element in range(len(splitted_userdefined_text)):
            generated_list.append(int(splitted_userdefined_text[element], 0))
        if ( '0x2f' in createdmsg_string ):
            generated_list = generated_list + self.diagnostics_dict_All_WriteDataByIdentifier['Stellglied_Start']
            self.textCtrl1_BenutzerDefinierte.Clear()
            for element in range(len(generated_list)):
                self.textCtrl1_BenutzerDefinierte.AppendText(hex(generated_list[element]) + ',')
            cur_pos = self.textCtrl1_BenutzerDefinierte.GetLastPosition()
            self.textCtrl1_BenutzerDefinierte.Remove(cur_pos-1, cur_pos)    

        elif ( '0x2e' in createdmsg_string ):
#===============================================================================
#            for x in range(len(self.list_combo_boxes)):
#                self.list_combo_boxes[x].Enable(True)
#===============================================================================
            generated_list = generated_list + self.diagnostics_dict_All_WriteDataByIdentifier['ValidParams']
            self.textCtrl1_BenutzerDefinierte.Clear()
            for element in range(len(generated_list)):
                self.textCtrl1_BenutzerDefinierte.AppendText(hex(generated_list[element]) + ',')
            cur_pos = self.textCtrl1_BenutzerDefinierte.GetLastPosition()
            self.textCtrl1_BenutzerDefinierte.Remove(cur_pos-1, cur_pos)      
        self.button5.Enable(False)
        self.button6.Enable(False)

    def OnButton1_StellgliedStop(self, event):
        generated_list = []
        tosendmsg = []
        createdmsg_string = self.textCtrl1_BenutzerDefinierte.GetValue()
        splitted_userdefined_text = createdmsg_string.split(',')
        for element in range(len(splitted_userdefined_text)):
            generated_list.append(int(splitted_userdefined_text[element], 0))
        if ( '0x2f' in createdmsg_string ):
            generated_list = generated_list + self.diagnostics_dict_All_WriteDataByIdentifier['Stellglied_Stop']
            self.textCtrl1_BenutzerDefinierte.Clear()
            for element in range(len(generated_list)):
                self.textCtrl1_BenutzerDefinierte.AppendText(hex(generated_list[element]) + ',')
            cur_pos = self.textCtrl1_BenutzerDefinierte.GetLastPosition()
            self.textCtrl1_BenutzerDefinierte.Remove(cur_pos-1, cur_pos)    

        elif ( '0x2e' in createdmsg_string ):
#===============================================================================
#            for x in range(len(self.list_combo_boxes)):
#                self.list_combo_boxes[x].Enable(True)
#===============================================================================
            generated_list = generated_list + self.diagnostics_dict_All_WriteDataByIdentifier['InvalidParams']
            self.textCtrl1_BenutzerDefinierte.Clear()
            for element in range(len(generated_list)):
                self.textCtrl1_BenutzerDefinierte.AppendText(hex(generated_list[element]) + ',')
            cur_pos = self.textCtrl1_BenutzerDefinierte.GetLastPosition()
            self.textCtrl1_BenutzerDefinierte.Remove(cur_pos-1, cur_pos)    
        self.button5.Enable(False)
        self.button6.Enable(False)
       
        #Uebergabe des Key: 76b 6 27 4 be eb 8e 1d 55
        tosendmsg = [[0x27, 0x4, Key[0], Key[1], Key[2], Key[3]]]
        self.MessagequeueInstance.put(tosendmsg)        
        

    def OnButton1_DataDownload(self, event):
        filepath_open = None 
        Wildcard = "*.xml"
        txt = "Open File"
        dlg = wx.FileDialog(self, message=txt, defaultDir=os.getcwd(),
            defaultFile="",wildcard=Wildcard,style=wx.OPEN|wx.CHANGE_DIR)
        if dlg.ShowModal() == wx.ID_OK:
            paths = dlg.GetPaths()
            paths2 = dlg.GetDirectory()

            dlg.Destroy()
            XML2BinObject = XML2Bin.parseXmlFile(paths[0])
            XML2BinObject.createBinFile()
    
            self.DatadownloadIsActive = True
            
            generated_list = self.diagnostics_dict_EcuIdentification['FAZIT_SERIENNUMMER']
            tosendmsg = [generated_list]
            self.MessagequeueInstance.put(tosendmsg)
    
            generated_list = self.diagnostics_dict_EcuIdentification['SERIENNUMMER']
            tosendmsg = [generated_list]
            self.MessagequeueInstance.put(tosendmsg)
            
            #76b 2 10 40 55 55 55 55 55
            generated_list = self.diagnostics_dict_Miscallenous['DIAGNOSE_SESSION']
            generated_list = generated_list + self.diagnostics_dict_All_WriteDataByIdentifier['EolSession']
            tosendmsg = [generated_list]
            self.MessagequeueInstance.put(tosendmsg)
            
            LoginKey = 9281
            DataDownloadKey = 20103
            self.CommonSeedKeyExchange(DataDownloadKey)
    
            generated_list =  self.diagnostics_dict_EcuIdentificationWritable['WERKSTATTCODE_DAS_ANGESCHLOSSENEN_TESTERS']
            generated_list = generated_list + self.diagnostics_dict_All_WriteDataByIdentifier['Werkstatt_Code_Parameters']
            tosendmsg = [generated_list]
            self.MessagequeueInstance.put(tosendmsg)
            
            generated_list =  self.diagnostics_dict_EcuIdentificationWritable['PROGRAMMING_DATE']
            yymmdd = self.date.today()
            generated_list = generated_list + [yymmdd.year % 2000, yymmdd.month, yymmdd.day]
            tosendmsg = [generated_list]
            self.MessagequeueInstance.put(tosendmsg)
            
            
            tosendmsg = [[0x31, 0x1, 0x3, 0x0, 0x3, 0x1, 0x0]]
            self.MessagequeueInstance.put(tosendmsg)
            
            #76b 4 31 3 3 0 55 55 55
            tosendmsg = [[0x31, 0x3, 0x3, 0x0]]
            self.MessagequeueInstance.put(tosendmsg)
            
            tosendmsg = [[0x34, 0x0, 0x44, 0x0, 0x0,0x0,0x0, 0x0, 0x0, 0x08, 0x04]]
            self.MessagequeueInstance.put(tosendmsg)
    
            ActualSizeOfFile = os.path.getsize("binFromXML_1.bin")
            TotalBytesInOneMessage = 32
            totaliterations = ActualSizeOfFile / TotalBytesInOneMessage
            leftBytes = ActualSizeOfFile % TotalBytesInOneMessage
            count = 0
            binFileDes = open("binFromXML_1.bin", "rb")

            for iterations in range(totaliterations):                        
                generated_list  = [0x36, iterations+1]
                for x in range(TotalBytesInOneMessage):
                    binFileDes.seek(count)
                    strval = binFileDes.read(1)
                    val = struct.unpack('B',strval)
                    generated_list.append(val[0])
                    count = count + 1
                tosendmsg = [generated_list]
                self.MessagequeueInstance.put(tosendmsg)
            iterations += 1
            if ( leftBytes > 0):
                TotalBytesInOneMessage = leftBytes
                generated_list  = [0x36, iterations+1]
                for x in range(TotalBytesInOneMessage):
                    binFileDes.seek(count)
                    strval = binFileDes.read(1)
                    val = struct.unpack('B',strval)
                    generated_list.append(val[0])
                    count = count + 1
                tosendmsg = [generated_list]
                self.MessagequeueInstance.put(tosendmsg)
    
    
            generated_list =  [0x37]
            tosendmsg = [generated_list]
            self.MessagequeueInstance.put(tosendmsg)
        
            generated_list =  [0x31, 0x01, 0x02, 0xEF, 0x03, 0x01, 0x0]
            tosendmsg = [generated_list]
            self.MessagequeueInstance.put(tosendmsg)
        
            generated_list =  [0x31, 0x03, 0x02, 0xEF]
            tosendmsg = [generated_list]
            self.MessagequeueInstance.put(tosendmsg)
        
            generated_list =  self.diagnostics_dict_EcuIdentificationWritable['VARIANTE_DES_PARAMETERSATZES']
            generated_list = generated_list + 13*[0x2D]
            tosendmsg = [generated_list]
            self.MessagequeueInstance.put(tosendmsg)
        
            generated_list =  self.diagnostics_dict_EcuIdentificationWritable['VERSION_DES_PARAMETERSATZES']
            generated_list = generated_list + 4*[0x2D]
            tosendmsg = [generated_list]
            self.MessagequeueInstance.put(tosendmsg)
        
            generated_list =  self.diagnostics_dict_EcuIdentificationWritable['FAHRZEUGAUSSTATTUNGSCODE']
            generated_list = generated_list + 8*[0x0]
            tosendmsg = [generated_list]
            self.MessagequeueInstance.put(tosendmsg)
        
            generated_list =  self.diagnostics_dict_EcuIdentificationWritable['BAUZUSTANDSDOKUMENTATION']
            generated_list = generated_list + 18*[0x2D]
            tosendmsg = [generated_list]
            self.MessagequeueInstance.put(tosendmsg)
        
            generated_list =  [0x11,0x2]
            tosendmsg = [generated_list]
            self.MessagequeueInstance.put(tosendmsg)
            
            self.DatadownloadIsActive = False
    
    def OnButton1_ReadEntireEeprom(self, event):
        print 'set file path'
        self.filepath_save = None
        txt  = 'Save data To...'
        Wildcard = "*.bin"
        dlg = wx.FileDialog(
            self, message= txt ,defaultDir=os.getcwd(), 
            wildcard=Wildcard,style=wx.SAVE|wx.CHANGE_DIR
            )
        if dlg.ShowModal() == wx.ID_OK:
            paths = dlg.GetPaths()
            paths2 = dlg.GetDirectory()
        dlg.Destroy()
        self.filepath_save = paths[0]
        
        os.system("del Eeprom.bin")
        HighByte = int(self.textCtrl_HighByte.GetValue(), 0)
        LowByte = int(self.textCtrl_LowByte.GetValue(), 0)
        Length = int(self.textCtrl_Length.GetValue(), 0)
        createdmsg = [[0x10, 0x4F]]
        self.MessagequeueInstance.put(createdmsg)
        address = 0x0000
        for x in range(16):
            HighByte_Complete = (address >> 8) & 0xFF
            LowByte_Complete = address & 0xFF
            createdmsg = [[0x23, 0x12, HighByte_Complete, LowByte_Complete, 0x80]]
            self.MessagequeueInstance.put(createdmsg)
            print "Button press completed"
            address += 0x80
            print hex(HighByte_Complete)
            print hex(LowByte_Complete)

    def OnButton8Button(self, event):
        print "Start Diagnsotics and TP"
        self.cyclicSender.stopTP = False            
        self.InitialiseMiniVas()
        if ( self.TesterPresentButton.GetValue() is False ):
            self.TesterPresentButton.SetValue(True)

    def OnTextCtrl2KeyDown(self, event):
        print event.GetKeyCode()

#    def OnAddFilterButtonButton(self, event):
#        createdmsg = []
#        tosendmsg = []
#        print "User Defined button pressed"
##===============================================================================
##        for x in range(len(self.list_combo_boxes)):
##            self.list_combo_boxes[x].Enable(False)
##===============================================================================
#        self.filter.clearCanIDs()
#        createdmsg_string = self.textCtrl1.GetValue()
#        splitted_userdefined_text = createdmsg_string.split(',')
#        for element in range(len(splitted_userdefined_text)):
#            self.filter.addCanID(int(splitted_userdefined_text[element],16))

    def OnClearCanTracesButtonButton(self, event):
        self.Queue2Content.Clear()
    
    def OnCreateLogFileButton(self, event):
        try:
            path = self.textCtrlLogFilePath.GetValue()  
            pathtemp=os.path.dirname(path)
            print pathtemp
            if(not os.path.exists(pathtemp)):
                dir=os.path.dirname(path)
                os.makedirs(dir)        
            self.file=open(path,'w') #create new file
            self.file.write("date "+time.ctime()+"\n")
            self.file.write("base hex  timestamps absolute\n")
            self.file.write("internal events logged\n")
            self.file.write("// version 7.2.0\n")    
            self.file.close()
            self.createMessageDlg("Message", "File "+path+" was created") 
            self.flagCreateLogFile=True   
        except IOError,ioe:
            self.createMessageDlg("Error", "Path is invalid!")            
        
        
        
    def CommonSeedKeyExchange(self, AccessKey):
        #Seed-Anforderung bei Security Access: 76b 2 27 3 55 55 55 55 55
        tosendmsg = [[0x27, 0x3]]
        self.MessagequeueInstance.put(tosendmsg)
        while  ( self.threadMessageSend.response == None ):
            pass
        while ((self.threadMessageSend.response[0] != 0x67) and (self.threadMessageSend.response[1] != 0x03)):
            pass
        Key = [1,2,3,4]
        TotalKey = self.threadMessageSend.response[2]*(2**24) + self.threadMessageSend.response[3]*(2**16)+ self.threadMessageSend.response[4]*(2**8) + self.threadMessageSend.response[5]
        TotalKey = TotalKey + AccessKey
        
        Key[0] = (TotalKey & 0xFF000000) >> 24
        Key[1] = (TotalKey & 0x00FF0000) >> 16
        Key[2] = (TotalKey & 0x0000FF00) >> 8
        Key[3] = TotalKey & 0x000000FF
        
        #Uebergabe des Key: 76b 6 27 4 be eb 8e 1d 55
        tosendmsg = [[0x27, 0x4, Key[0], Key[1], Key[2], Key[3]]]
        self.MessagequeueInstance.put(tosendmsg)
        
    def OnButton_EEPROMSchreiben(self, event):
        #76b 2 10 40 55 55 55 55 55
        generated_list = self.diagnostics_dict_Miscallenous['DIAGNOSE_SESSION']
        generated_list = generated_list + self.diagnostics_dict_All_WriteDataByIdentifier['DevelopmentSession']
        tosendmsg = [generated_list]
        self.MessagequeueInstance.put(tosendmsg)
        
        LoginKey = 9281
        DataDownloadKey = 20103

        self.CommonSeedKeyExchange(LoginKey)
                
    def OnButton_EEPROMSchreiben(self, event):
        #76b 2 10 40 55 55 55 55 55
        generated_list = self.diagnostics_dict_Miscallenous['DIAGNOSE_SESSION']
        generated_list = generated_list + self.diagnostics_dict_All_WriteDataByIdentifier['DevelopmentSession']
        tosendmsg = [generated_list]
        self.MessagequeueInstance.put(tosendmsg)
        
        LoginKey = 9281
        DataDownloadKey = 20103

        self.CommonSeedKeyExchange(LoginKey)
                
        HighByte = int(self.textCtrl_HighByte.GetValue(), 0)
        LowByte = int(self.textCtrl_LowByte.GetValue(), 0)
        Length = int(self.textCtrl_Length.GetValue(), 0)
        
        DataBytes = []
        createdmsg = []
        tosendmsg = []
        print "User Defined button pressed"
#===============================================================================
#        for x in range(len(self.list_combo_boxes)):
#            self.list_combo_boxes[x].Enable(False)
#===============================================================================
        Databytes_string = self.textCtrl1_BenutzerDefinierte.GetValue()
        splitted_userdefined_text = Databytes_string.split(',')
        for element in range(len(splitted_userdefined_text)):
            try:
                DataBytes.append(int(splitted_userdefined_text[element], 0))
            except:
                x = splitted_userdefined_text[element].encode('utf-8')
                UnpackAndConvertToHex = map(hex, struct.unpack(len(splitted_userdefined_text[element])*'B',splitted_userdefined_text[element]))
                print UnpackAndConvertToHex
                for element_name in range(len(UnpackAndConvertToHex)):
                    DataBytes.append(int(UnpackAndConvertToHex[element_name], 0))
        createdmsg = [0x3D, 0x12, HighByte, LowByte, Length] + DataBytes
        tosendmsg = [createdmsg]
        self.MessagequeueInstance.put(tosendmsg)
        print "Button press completed"

    def OnComboBox1Combobox(self,event):
        Value = self.comboBox1.GetValue()
        print Value
        if ( Value == "ClosePeak"):
            self.da.cd.close()
            from UserInterface_GUI_SYNC import DefaultRestpayload
            DiagApp.DefaultRestPayload = DefaultRestpayload      
            self.fillListBox()
            self.EnableAllButtons(Value)
            self.cyclicSender.stopIgnition = True
            self.cyclicSender.stopTP = True
            self.cyclicSender.stopSystemInfo_1 = True
            self.cyclicSender.stopLanguageInfo = True
            self.cyclicSender.stopNM = True
            self.cyclicSender.stopCarConfig = True
            self.cyclicSender.stopHMI = True


        else:
            self.da.cd.close()
            self.da.cd.open(Value)
            self.da.cd.resetClient()
            #self.da.cd.resetClient()
    #Notifying Applications
            self.da.sr.setReceiveCanId(Value)
            self.da.cp.setTransmitCanId(Value)
            self.da.setCurrentEcu(Value)
            
            self.cyclicSender.setCurrentEcu(Value)
            self.cyclicSender.init_parameters()        
            
            if ( Value == "SCM_125"):
                from UserInterface_GUI_SCM import DefaultRestpayload
                DiagApp.DefaultRestPayload = DefaultRestpayload
                
            elif ( Value == "UHV_100" or Value == "UHV_500" or Value == "ADR_500" or Value == "OCU_500"):
                from UserInterface_GUI_UHV import DefaultRestpayload
                DiagApp.DefaultRestPayload = DefaultRestpayload
            elif ( Value == "UMI_100" or Value == "UMI_500"):
                from UserInterface_GUI_UMI import DefaultRestpayload
                DiagApp.DefaultRestPayload = DefaultRestpayload
                                    
            elif ( Value == "SYNC_500"):
                from UserInterface_GUI_SYNC import DefaultRestpayload
                DiagApp.DefaultRestPayload = DefaultRestpayload                
                    
            self.fillListBox()
            self.EnableAllButtons(Value)
        
    
#    def OnAddFilterButtonButton(self, event):
#        createdmsg = []
#        tosendmsg = []
#        print "User Defined button pressed"
##===============================================================================
##        for x in range(len(self.list_combo_boxes)):
##            self.list_combo_boxes[x].Enable(False)
##===============================================================================
## self.filter.CanIDs - filter        
#        self.filter.clearCanIDs()
#        createdmsg_string = self.textCtrl1.GetValue()
#        if createdmsg_string !='':
#            splitted_userdefined_text = createdmsg_string.split(',')
#            for element in range(len(splitted_userdefined_text)):
#                self.filter.addCanID(int(splitted_userdefined_text[element],16))
    

    def OnClearCanTracesButtonButton(self, event):
        self.Queue2Content.Clear()


    def EnableAllButtons(self, Value):
        self.ReadE2PButton.Enable(False)        
        self.BenutzerdefinierteAbfrageButton.Enable(False)        
        self.TesterPresentButton.Enable(False)        
        self.ResultButton.Enable(False)        
        self.ReadEntireE2PButton.Enable(False)        
        self.DataDownloadButton.Enable(False)        
        self.StartDiagnosticsButton.Enable(False)        
        self.StartCanTracingButton.Enable(False)        
        self.StopCanTracingButton.Enable(False)        
       # self.addFilterButton.Enable(False)        
        self.ClearCanTracesButton.Enable(False)        
        self.E2PWriteButton.Enable(False)        
        self.BenutzerdefinierteAbfrageButton.Enable(False)
        self.comboBox2.Enable(False)
        self.comboBox3.Enable(False)
        self.comboBox4.Enable(False)
        self.comboBox5.Enable(False)
        self.comboBox6.Enable(False)
        self.comboBox7.Enable(False)
        self.comboBox8.Enable(False)
        self.comboBox9.Enable(False)
        
        self.ScmAliveButton.Enable(False)        
        self.EmvAudioLoopBackButton.Enable(False)
        self.EmvLogDtcButton.Enable(False)

        if ( Value == 'UHV_100' or Value == 'UHV_500' or Value == 'ADR_500'  or Value == 'OCU_500' or Value == 'UMI_100' or Value == 'UMI_500'):
            self.ReadE2PButton.Enable(True)        
            self.BenutzerdefinierteAbfrageButton.Enable(True)        
            self.TesterPresentButton.Enable(True)        
            self.ResultButton.Enable(True)        
            self.ReadEntireE2PButton.Enable(True)        
            self.DataDownloadButton.Enable(True)        
            self.StartDiagnosticsButton.Enable(True)        
            self.StartCanTracingButton.Enable(True)        
            self.StopCanTracingButton.Enable(True)        
          #  self.addFilterButton.Enable(True)        
            self.ClearCanTracesButton.Enable(True)      
            self.CreateLogFileButton.Enable(True)  
            self.E2PWriteButton.Enable(True)        
            self.comboBox2.Enable(True)
            self.comboBox3.Enable(True)
            self.comboBox4.Enable(True)
            self.comboBox5.Enable(True)
            self.comboBox6.Enable(False)
            self.comboBox7.Enable(False)
            self.ClearBenutzerdefinierteAbfrageButton.Enable(True)         

        if ( Value == 'SCM_125'):
            self.BenutzerdefinierteAbfrageButton.Enable(True)        
            self.TesterPresentButton.Enable(True)        
            self.ResultButton.Enable(True)        
            self.StartDiagnosticsButton.Enable(True)        
            self.StartCanTracingButton.Enable(True)        
            self.StopCanTracingButton.Enable(True)        
          #  self.addFilterButton.Enable(True)        
            self.ClearCanTracesButton.Enable(True)        
            
            self.ScmAliveButton.Enable(True)        
            self.EmvAudioLoopBackButton.Enable(True)
            self.EmvAudioLoopBackButton.SetLabel("Audio Loop Back")
            self.EmvLogDtcButton.Enable(True)
            self.comboBox2.Enable(True)
            self.comboBox3.Enable(True)
            self.comboBox4.Enable(True)
            self.comboBox5.Enable(True)
            self.comboBox6.Enable(False)
            self.comboBox7.Enable(False)
            self.ClearBenutzerdefinierteAbfrageButton.Enable(True)          

        elif ( Value == 'SYNC_500'):    
            self.BenutzerdefinierteAbfrageButton.Enable(True)        
            self.TesterPresentButton.Enable(True)        
            self.ResultButton.Enable(True)        
            self.StartDiagnosticsButton.Enable(True)        
            self.StartCanTracingButton.Enable(True)        
            self.StopCanTracingButton.Enable(True)        
            self.addFilterButton.Enable(True)        
            self.ClearCanTracesButton.Enable(True)        
            
            self.EmvAudioLoopBackButton.Enable(True)
            self.EmvAudioLoopBackButton.SetLabel("Perf Eval")
            self.ClearBenutzerdefinierteAbfrageButton.Enable(True)       
        
        else:
            self.BenutzerdefinierteAbfrageButton.Enable(True)        
            self.TesterPresentButton.Enable(True)        
            self.ResultButton.Enable(True)        
            self.StartDiagnosticsButton.Enable(True)        
            self.StartCanTracingButton.Enable(True)        
            self.StopCanTracingButton.Enable(True)        
           # self.addFilterButton.Enable(True)        
            self.ClearCanTracesButton.Enable(True)        
            self.ClearBenutzerdefinierteAbfrageButton.Enable(True)       
            

    def OnButton7Button(self, event):
        event.Skip()

    def OnComboBox2Combobox(self,event):
        Value = self.comboBox2.GetValue()
        print Value
        if ( Value != "StopMsg" ):
            self.cyclicSender.stopLanguageInfo = False
        else:
            self.cyclicSender.stopLanguageInfo = True
        self.cyclicSender.KombiLanguage = Value


    def OnComboBox3Combobox(self, event):
        Value = self.comboBox3.GetValue()
        print Value
        if ( Value != "StopMsg" ):
            self.cyclicSender.stopIgnition = False
        else:
            self.cyclicSender.stopIgnition = True
        self.cyclicSender.IgnitionSignal = Value


    def OnComboBox4Combobox(self, event):
        Value = self.comboBox4.GetValue()
        print Value
        if ( Value != "StopMsg" ):
            self.cyclicSender.stopCarConfig = False
        else:
            self.cyclicSender.stopCarConfig = True
        self.cyclicSender.CarConfig = Value

    def OnComboBox5Combobox(self, event):
        Value = self.comboBox5.GetValue()
        print Value
        if ( Value != "StopMsg" ):
            self.cyclicSender.stopHMI = False
        else:
            self.cyclicSender.stopHMI = True
        self.cyclicSender.HMI = Value

    def OnComboBox6Combobox(self,event):
        Value = self.comboBox6.GetValue()
        print Value
        if ( Value != "StopMsg" ):
            self.cyclicSender.stopTP = False
        else:
            self.cyclicSender.stopTP = True
            self.ScmAliveButton.SetValue(0)            


    def OnComboBox7Combobox(self, event):
        Value = self.comboBox7.GetValue()
        print Value
        if ( Value != "StopMsg" ):
            self.cyclicSender.stopNM = False
        else:
            self.cyclicSender.stopNM = True
            self.ScmAliveButton.SetValue(0)

    def OnComboBox8Combobox(self, event):
        Value = self.comboBox9.GetValue()
        print Value
        if ( Value != "StopMsg" ):
            self.cyclicSender.stopSystemInfo_1 = False
        else:
            self.cyclicSender.stopSystemInfo_1 = True
        self.cyclicSender.SystemInfo_1 = Value

    def OnComboBox9Combobox(self, event):
        Value = self.comboBox9.GetValue()
        print Value
        if ( Value != "StopMsg" ):
            self.cyclicSender.stopSystemInfo_1 = False
        else:
            self.cyclicSender.stopSystemInfo_1 = True
        self.cyclicSender.SystemInfo_1 = Value

    def Diagnsotics_Button(self, event):
        self.panel4.Hide()
        self.panel5.Hide()
        self.panel6.Hide()        
        self.panel7.Hide()
        self.panel1.Show() 
        self.panel8.Hide()  
        self.panel9.Hide()     

    def EMV_Button(self, event):
        self.panel1.Hide()
        self.panel5.Hide()
        self.panel6.Hide()
        self.panel7.Hide()        
        self.panel4.Show()  
        self.panel8.Hide()  
        self.panel9.Hide()    


    def CANMessages_Button(self, event):
        self.panel1.Hide()
        self.panel4.Hide()
        self.panel5.Hide()
        self.panel6.Show() 
        self.panel7.Hide()        
        self.panel8.Hide()
        self.panel9.Hide()       

    def OnButton12Button(self, event):
        self.panel1.Hide()
        self.panel4.Hide()
        self.panel5.Show()
        self.panel6.Hide()
        self.panel7.Hide()       
        self.panel8.Hide()
        self.panel9.Hide()      
        if self.LogTraceCheckbox.GetValue() is True:
            path = self.textCtrlLogFilePath.GetValue()
            if(not os.path.exists(path)):
                dir=os.path.dirname(path)
                os.makedirs(dir)
                self.file=open(path,'w') #create new file
                self.file.write("date "+time.ctime()+"\n")
                self.file.write("base hex  timestamps absolute\n")
                self.file.write("internal events logged\n")
                self.file.write("// version 7.2.0\n")    
                self.file.close() 
        
                
    def onSwitchPanels(self, event):
        """"""
        #self.fileMenu = wx.Menu()
        #switch_panels_menu_item = self.fileMenu.Append(wx.ID_ANY,
        #                                          "Switch Panels",
        #                                          "Some text")
        #self.Bind(wx.EVT_MENU, self.onSwitchPanels,
        #          switch_panels_menu_item)
        #self.menuBar1.Append(fileMenu, '&File')
        #self.SetMenuBar(self.menuBar1)

        self.Layout()

    def OnEEPROM_Button(self, event):
        self.panel1.Hide()
        self.panel4.Hide()
        self.panel5.Hide()       
        self.panel6.Hide()
        self.panel7.Show()
        self.panel8.Hide()
        self.panel9.Hide()
 
    def OnHELP_Button(self, event):
        print "help buitton is pressed"
        self.panel1.Hide()
        self.panel4.Hide()
        self.panel5.Hide()       
        self.panel6.Hide()
        self.panel7.Hide()
        self.panel8.Show()
        self.panel9.Hide()
         
    def OnTOOLS_Button(self, event):
        self.panel1.Hide()
        self.panel4.Hide()
        self.panel5.Hide()       
        self.panel6.Hide()
        self.panel7.Hide()
        self.panel8.Hide()
        self.panel9.Show()

    def OnButton14Button(self, event):
        if ( self.ScmAliveButton.GetValue() is True ):
            self.cyclicSender.stopNM = False            
            print "Start SCM"
        else:
            self.cyclicSender.stopNM = True            
            print "Sleep SCM"

    def OnButton15Button(self, event):
        
        Value = self.comboBox1.GetValue()
        if (Value == 'SYNC_500'):
            if ( self.EmvAudioLoopBackButton.GetValue() is True ):
                
                generated_list =  self.diagnostics_dict_IdentifierMeasurementValue['UsbPenDrive3Test']
                tosendmsg = [generated_list]
                self.MessagequeueInstance.put(tosendmsg)
    
                generated_list =  self.diagnostics_dict_IdentifierMeasurementValue['UsbPenDriveResult']
                tosendmsg = [generated_list]
                self.MessagequeueInstance.put(tosendmsg)
    
                generated_list =  self.diagnostics_dict_IdentifierMeasurementValue['BluetoothDiscoverableModeOn']
                tosendmsg = [generated_list]
                self.MessagequeueInstance.put(tosendmsg)
    
                generated_list =  self.diagnostics_dict_IdentifierMeasurementValue['BluetoothDiscoverableModeOnResult']
                tosendmsg = [generated_list]
                self.MessagequeueInstance.put(tosendmsg)
    
                generated_list =  self.diagnostics_dict_IdentifierMeasurementValue['ReadSteeringButtonValue']
                tosendmsg = [generated_list]
                self.MessagequeueInstance.put(tosendmsg)
    
                generated_list =  self.diagnostics_dict_IdentifierMeasurementValue['StartAudioInternalLoopbackTest010101']
                tosendmsg = [generated_list]
                self.MessagequeueInstance.put(tosendmsg)
        elif (Value == 'SCM_125'):
            if ( self.EmvAudioLoopBackButton.GetValue() is True ):
                print "Start Audio Loopback"
                generated_list =  self.diagnostics_dict_ActuatorTest['AUDIO_LOOP_BACK_START']
                tosendmsg = [generated_list]
                self.MessagequeueInstance.put(tosendmsg)
            else:
                print "Stop Audio Loopback"
                generated_list =  self.diagnostics_dict_ActuatorTest['AUDIO_LOOP_BACK_STOP']
                tosendmsg = [generated_list]
                self.MessagequeueInstance.put(tosendmsg)

    def OnButton16Button(self, event):
        if ( self.EmvLogDtcButton.GetValue() is True ):
            print "Start Logging"
            self.loggingThread.stopLogging = False
            self.DTCLogger = open("DTCLogging.txt", "w")
            self.DTCLogger.write(str(time.time()) + '\r\n')
            
        else:
            print "Stop Logging"
            self.loggingThread.stopLogging = True
            self.DTCLogger.close()
            
    def OnSignalGenerator_Button(self, event):
        filepath_open = None 
        Wildcard = "*.xls"
        txt = "Open File"
        curdir = os.getcwd()
        #print 'current directory' + curdir
        sys.path.append(os.path.abspath('../tools/SignalGenerator'))
        #print sys.path
        dlg = wx.FileDialog(self, message=txt, defaultDir=os.getcwd(),
            defaultFile="",wildcard=Wildcard,style=wx.OPEN|wx.CHANGE_DIR)
        if dlg.ShowModal() == wx.ID_OK:
            paths = dlg.GetPaths()
            paths2 = dlg.GetDirectory()
            dlg.Destroy()
            print paths[0]
            import Conversion_CAN_Signals
            UHVClassObjectConversionTextPrompts = Conversion_CAN_Signals.CANSignals(paths, paths2, curdir)
            UHVClassObjectConversionTextPrompts.runScript(paths[0], paths2, curdir)
        else:
            print "Aborted"

    def OnGenerateKombiTextPrompts_Button(self, event):
        filepath_open = None 
        Wildcard = "*.xls"
        txt = "Open File"
        curdir = os.getcwd()
        #print 'current directory' + curdir
        sys.path.append(os.path.abspath('../tools/KombiTextPrompts'))
        #print sys.path
        dlg = wx.FileDialog(self, message=txt, defaultDir=os.getcwd(),
            defaultFile="",wildcard=Wildcard,style=wx.OPEN|wx.CHANGE_DIR)
        if dlg.ShowModal() == wx.ID_OK:
            paths = dlg.GetPaths()
            paths2 = dlg.GetDirectory()
            dlg.Destroy()
            print paths[0]
            import Conversion_Text_Prompts
            UHVClassObjectConversionTextPrompts = Conversion_Text_Prompts.UHVSecondaryDisplayTextPrompts()
            UHVClassObjectConversionTextPrompts.runScript(paths[0], paths2, curdir)
        else:
            print " Aborted"

    def OnGenerateEepromData_Button(self, event):
        filepath_open = None 
        Wildcard = "*.xls"
        txt = "Open File"
        curdir = os.getcwd()
        #print 'current directory' + curdir
        sys.path.append(os.path.abspath('../tools/EEPROM_Script'))
        #print sys.path
        dlg = wx.FileDialog(self, message=txt, defaultDir=os.getcwd(),
            defaultFile="",wildcard=Wildcard,style=wx.OPEN|wx.CHANGE_DIR)
        if dlg.ShowModal() == wx.ID_OK:
            paths = dlg.GetPaths()
            paths2 = dlg.GetDirectory()
            dlg.Destroy()
            print paths[0]
            import Parse_EEPROM_Excel_Layout
            UHVClassObjectConversionTextPrompts = Parse_EEPROM_Excel_Layout.UHVEepromDataConversion(paths, paths2, curdir)
            UHVClassObjectConversionTextPrompts.runScript(paths[0], paths2, curdir)
        else:
            print "Aborted"

    
    def OnGenerateTraceConfig_Button(self, event):
        filepath_open = None 
        Wildcard = "*.h"
        txt = "Open File"
        curdir = os.getcwd()
        #print 'current directory' + curdir
        sys.path.append(os.path.abspath('../tools/TraceScripts'))
        #print sys.path
        dlg = wx.FileDialog(self, message=txt, defaultDir=os.getcwd(),
            defaultFile="",wildcard=Wildcard,style=wx.OPEN|wx.CHANGE_DIR)
        if dlg.ShowModal() == wx.ID_OK:
            paths = dlg.GetPaths()
            paths2 = dlg.GetDirectory()
            dlg.Destroy()
            print paths[0]
            import GenerateTraceConfig
            GenerateTraceConfig.runScript(paths[0], paths2, curdir)
        else:
            print "Aborted"

    
    def myAction(object):
        print "Performing my action"
        self.OnButton16Button(wx.EVT_TOGGLEBUTTON)
        
        
        
