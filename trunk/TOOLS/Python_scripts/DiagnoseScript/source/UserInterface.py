""" 


    $Date: 2009-06-23 15:46:24 +0200 (Di, 23 Jun 2009) $
    $Rev: 6848 $
    $Author: agrawal $
    $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/TOOLS/Python_scripts/trunk/DiagnoseScript/UserInterface.py $

    Copyright (c) 2008 S1nn GmbH & Co. KG.
    All Rights Reserved.


"""

_svn_id = "$Id$"
_svn_rev = "$Rev: 6848 $"
__version__ = _svn_rev[6:-2]


UHV_All_Diagnose = [
'UHV_SoftwareVersionNumber',
'UHV_HardwareVersionNumber',
'UHV_ReadSerialNumber',
'UHV_MikrofonStatus',
'UHV_StromMikrofonAufnahme',
'UHV_AudioStatusLinks',
'UHV_AudioStatusRecht',
'UHV_SteuergeraetTemperature',
'UHV_SpannungKlemme30',
'UHV_MikrofonButtonStatus',
'UHV_BluetoothButtonStatus',
'UHV_VCRButtonStatus',
'UHV_GekoppelteGeraet',
'UHV_BluetoothPinAuslesen',
'UHV_BluetoothPinSetzen',
'UHV_MuteDelayAuslesen',
'UHV_MuteDelaySetzen',
'UHV_BT_Name_Auslesen',
'UHV_RuecksetzenAuslesen',
'UHV_RuecksetzenSetzen',
]

UHV_EEPROM = [
'UHV_DiagnoseSessionProgramming',
'UHV_ReadEEPROM'
              ]

UHV_Check = [
'UHV_SoftwareVersionNumber',

]
# ** --------------------------------- INPUT ---------------------
messageseq = UHV_EEPROM
# ** --------------------------------- INPUT ---------------------


