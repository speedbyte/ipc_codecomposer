""" 


    $Date: 2009-06-23 15:46:24 +0200 (Di, 23 Jun 2009) $
    $Rev: 6848 $
    $Author: agrawal $
    $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/TOOLS/Python_scripts/trunk/DiagnoseScript/UserInterface_GUI.py $

    Copyright (c) 2008 S1nn GmbH & Co. KG.
    All Rights Reserved.


"""

_svn_id = "$Id$"
_svn_rev = "$Rev: 6848 $"
__version__ = _svn_rev[6:-2]

# -----------------------------------------------------------------------
# -----------------------------------------------------------------------
DefaultRestpayload = 0x00

#CalibrationDataWritable
diagnostics_dict_CalibrationDataWritable = {
'RESET_TO_FACTORY_SETTING' : [0x2E, 0x09, 0x05],
}

#IdentifierMeasurementValue
diagnostics_dict_IdentifierMeasurementValue = {
'SPANNUNG_KLEMME_30' : [0x22, 0x02, 0x86],
'STEUERGERAETETEMPERATUR' : [0x22, 0x02, 0x8D],
'SOFTWAREVERSION' : [0x22, 0x03, 0x00],
'BLUETOOTH_DEVICE_MAC_ADDRESS' : [0x22, 0x11, 0x00],
'MICROPHONE_STATUS' : [0x22, 0x24, 0x00],
'MICROPHONE_CURRENT_DRAIN' : [0x22, 0x24, 0x01],
'TELEPHONE_SIGNAL_STRENGTH' : [0x22, 0x24, 0x02],
'AUDIO_OUTPUT_LEFT' : [0x22, 0x24, 0x03],
'AUDIO_OUTPUT_RIGHT' : [0x22, 0x24, 0x04],
'BLUETOOTH_CONNECTED_DEVICE_VIA_HFP' : [0x22, 0x24, 0x08],
'BLUETOOTH_CONNECTED_HEADSET' : [0x22, 0x24, 0x0A],
'BLUETOOTH_PAIRED_DEVICES_VIA_HFP' : [0x22, 0x24, 0x0B],
'BLUETOOTH_PAIRED_MEDIA_DEVICES' : [0x22, 0x24, 0x0D],
'BLUETOOTH_CONNECTED_MEDIA_DEVICE' : [0x22, 0x24, 0x0F],
'BLUETOOTH_PAIRED_HEADSETS' : [0x22, 0x24, 0x11],
'AERIAL_CONNECTION_STATUS' : [0x22, 0x24, 0x17],
'MEDIA_DEVICE_CONNECTION_STATUS' : [0x22, 0x24, 0x18],
'BLUETOOTH_VISIBILITY' : [0x22, 0x24, 0x28],
'TELEPHONE_CONNECTIVITY' : [0x22, 0x24, 0x35],
'MICROPHONE_MUTE_BUTTON_SERVICE_CALL_BUTTON' : [0x22, 0x24, 0x5E],
'BLUETOOTH_BUTTON_INFO_CALL_BUTTON' : [0x22, 0x24, 0x5F],
'ANSWER_TELEPHONE_BUTTON_VOICE_CONTROL_BUTTON' : [0x22, 0x24, 0x60],
'SERVICE_CALL_BUTTON_EMERGENCY_CALL_BUTTON_CRADLE' : [0x22, 0x24, 0x66],
'INFO_CALL_BUTTON_VOICE_CONTROL_BUTTON_CRADLE' : [0x22, 0x24, 0x67],
}

#EcuIdentification
diagnostics_dict_EcuIdentification = {
'VW_AUDI_TEILENUMMER' : [0x22, 0xF1, 0x87],
'SOFTWAREVERSION' : [0x22, 0xF1, 0x89],
'SERIENNUMMER' : [0x22, 0xF1, 0x8C],
'HARDWARETEILENUMMER' : [0x22, 0xF1, 0x91],
'SYSTEMBEZEICHNUNG' : [0x22, 0xF1, 0x97],
'DATUM_DER_LETZTEN_UPDATE_PROGRAMMIERUNG' : [0x22, 0xF1, 0x99],
'WERKSTATTCODE_DER_ANPASSUNG' : [0x22, 0xF1, 0x9A],
'DATUM_DER_LETZTEN_ANPASSUNG' : [0x22, 0xF1, 0x9B],
'ASAM_ODX_DATEI_KENNZEICHNUNG' : [0x22, 0xF1, 0x9E],
'VARIANTE_DES_PARAMETERSATZES' : [0x22, 0xF1, 0xA0],
'VERSION_DES_PARAMETERSATZES' : [0x22, 0xF1, 0xA1],
'ASAM_ODX_DATEIVERSION' : [0x22, 0xF1, 0xA2],
'HARDWAREVERSION' : [0x22, 0xF1, 0xA3],
'FAHRZEUGAUSSTATTUNGSCODE' : [0x22, 0xF1, 0xA4],
'WERKSTATTCODE_DER_CODIERUNG' : [0x22, 0xF1, 0xA5],
'WERKSTATTCODE_DER_PARAMETRIERUNG' : [0x22, 0xF1, 0xA8],
'DATUM_DER_PARAMETRIERUNG' : [0x22, 0xF1, 0xA9],
'SYSTEMKURZZEICHEN' : [0x22, 0xF1, 0xAA],
'VERSIONEN_DER_SOFTWAREMODULE' : [0x22, 0xF1, 0xAB],
'BAUZUSTANDSDOKUMENTATION' : [0x22, 0xF1, 0xAC],
'STATUS_DER_PROGRAMMIERBARKEIT' : [0x22, 0xF1, 0xDF],
'KONSISTENZ_DER_EEPROM_DATEN' : [0x22, 0xF1, 0xE0],
}

#EcuIdentificationWritable
diagnostics_dict_EcuIdentificationWritable = {
'HARDWAREVERSION' : [0x2E, 0xF1, 0xA3],
'WERKSTATTCODE_DAS_ANGESCHLOSSENEN_TESTERS' : [0x2E, 0xF1, 0x98],
'PROGRAMMING_DATE' : [0x2E, 0xF1, 0x99],
'UNIVERSAL_PREPARATION_FOR_MOBILE_TELEPHONE' : [0x2E, 0xD1, 0x31, "YourName"],
}

#CodierungWritable
diagnostics_dict_CodierungWritable = {
'CODIERUNG' : [0x2E, 0x06, 0x00],
}


diagnostics_dict_Miscallenous = {
'DIAGNOSE_SESSION' : [0x10],
}


#ActuatorTest
diagnostics_dict_ActuatorTest = {

'AUDIO_LOOP_BACK_START' : [0x31, 0x01, 0xF0, 0x00],
'AUDIO_LOOP_BACK_STOP' : [0x31, 0x02, 0xF0, 0x00],
'RESET_OVER_WATCHDOG' : [0x11, 0x01],
'RESTORE_TO_FACTORY' : [0x31, 0x01, 0xF0, 0x03],
}
#DtcOverview
diagnostics_dict_DtcOverview = {

'MIKROFON_DTC_GND': [0x19, 0x04, 0x9D, 0x79, 0x11, 0x10],
'MIKROFON_DTC_BAT': [0x19, 0x04, 0x9D, 0x79, 0x12, 0x10],
'MIKROFON_DTC_OPEN': [0x19, 0x04, 0x9D, 0x79, 0x13, 0x10],
'MIKROFON_DTC_NOT_IN_RANGE': [0x19, 0x04, 0x9D, 0x79, 0x1E, 0x10],
'FUNKTIONSEINSCHRAENKUNG_DURCH_UNTERSPANNUNG' : [0x40, 0x40],
'FUNKTIONSEINSCHRAENKUNG_DURCH_UEBERSPANNUNG' : [0x40, 0x40],
'CLEAR_ALL_DTCs' : [0x14, 0xFF, 0xFF, 0xFF],
'READ_ALL_DTC_WITHOUT_MASK' : [0x19, 0x02, 0xFF],
'LIST_OF_DTC' : [0x19, 0x0A],
'READ_ALL_DTC_CONF_MASK' : [0x19, 0x02, 0x09],
}


diagnostics_dict_All_WriteDataByIdentifier = {
                                 
'Werkstatt_Code_Parameters' : [0x04, 0xBA, 0x35, 0x35, 0x04, 0x02],
'Stellglied_Start' : [0x3, 0xFF, 0xFF, 0xFF, 0xFF],
'Stellglied_Stop' : [0x0],
'InvalidParams' : [0xFF, 0xFF, 0xFF, 0xFF,0xFF, 0xFF, 0xFF, 0xFF],
'ValidParams' : [0xA,0x0,0x0,0x0,0x0,0x0,0x0,0x0],
'DefaultSession' : [0x1],
'EcuProgrammingSession' : [0x2],
'ExtendedDiagSession' : [0x3],
'EolSession' : [0x40],
'IoTestSession' : [0x41],
'DevelopmentSession' : [0x4F],
'InfoNummer' : [0x07, 0x11, 0x90, 0x12, 0x19, 0x89, 0xFF, 0x00, 0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00],
}



canmsg_dict_2 = {
'StopMsg' :   [[0xFF]],            
'Invalid' :   [0x4D7, [0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'English' :   [0x4D7, [0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'German' :    [0x4D7, [0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'Italian' :   [0x4D7, [0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'French' :    [0x4D7, [0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'Spanish' :   [0x4D7, [0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'Turkish' :   [0x4D7, [0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'Russian' :   [0x4D7, [0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'Dutch' :     [0x4D7, [0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'Polish' :    [0x4D7, [0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'Swedish' :   [0x4D7, [0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'Portugese' : [0x4D7, [0x0B,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
}

canmsg_dict_3 = {
'StopMsg' :             [[0xFF]],  
'IgnitionOn_Gen2' :     [0x285, [0x20,0,0,0,0,0,0,0]],
'IgnitionOff_Gen2' :    [0x285, [0x00,0,0,0,0,0,0,0]],
'IgnitionOn_Gen3' :     [0x48, [0x00,0,0,0,7,0,0,0]],
'IgnitionOff_Gen3' :    [0x48, [0x00,0,0,0,5,0,0,0]],
}


canmsg_dict_4 = {
'StopMsg' : [0xFF],            
'Fiesta_Gen2' : [0x400, 
[0x01,0x06,0x02,0x01,0x01,0x16,0x01,0x01],
[0x02,0x01,0x07,0x01,0x06,0x04,0x00,0x05],
[0x03,0x02,0x05,0x01,0x02,0x02,0x05,0x02],
[0x04,0x01,0x03,0x02,0x02,0x01,0x02,0x01],
[0x05,0x02,0x03,0x02,0x01,0x01,0x02,0x01],
[0x06,0x01,0x04,0x00,0x01,0x01,0x01,0x01],
[0x07,0x07,0x01,0x05,0x00,0x02,0x01,0x01],
[0x08,0x01,0x65,0x00,0x00,0x03,0x02,0x01],
[0x09,0x03,0x02,0x01,0x01,0x01,0x02,0x24],
[0x0A,0x07,0x02,0x01,0x02,0x00,0x12,0x17],
[0x0B,0x02,0x00,0x03,0x01,0x03,0x02,0x01],
[0x0C,0x01,0x00,0x00,0x02,0x00,0x01,0x01],
[0x0D,0x02,0x02,0x02,0x02,0x02,0x01,0x02],
[0x0E,0x02,0x05,0x01,0x01,0x02,0x02,0x02],
[0x0F,0x01,0x02,0x03,0x01,0x01,0x00,0x01],
[0x10,0x04,0x01,0x01,0x02,0x01,0x02,0x12],
[0x11,0x02,0x01,0x01,0x00,0x01,0x00,0x01],
[0x12,0x00,0x02,0x00,0x02,0x00,0x01,0x02],
[0x13,0x01,0x01,0x00,0x01,0x02,0x02,0x02],
[0x14,0x02,0x02,0x01,0x00,0x00,0x00,0x00],
[0x15,0x03,0x00,0x02,0x02,0x02,0x00,0x00],
[0x16,0x00,0x01,0x01,0x00,0x01,0x01,0x01],
[0x17,0x00,0x00,0x05,0x00,0x01,0x00,0x00],
[0x18,0x00,0x00,0x00,0x00,0x03,0x01,0x01],
[0x19,0x01,0x00,0x00,0x01,0x02,0x00,0x05],
[0x1A,0x00,0x01,0x01,0x01,0x00,0x00,0x00],
[0x1B,0x01,0x03,0x01,0x02,0x00,0x00,0x00],
[0x1C,0x01,0x02,0x00,0x00,0x02,0x04,0x02],
[0x1D,0x00,0x00,0x00,0x00,0x00,0x00,0x00],
[0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x03],
[0x1F,0x02,0x00,0x00,0x00,0x00,0x00,0x00],
[0x20,0x02,0x00,0x00,0x00,0x01,0x00,0x02],
[0x21,0x00,0x00,0x00,0x00,0x00,0x00,0x00],
[0x22,0x00,0x00,0x00,0x01,0x00,0x00,0x00],
[0x23,0x00,0x00,0x00,0x00,0x00,0x00,0x00],
[0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x00]                 
],
'Focus_Gen3' : [0x400, 
[0x01,0x45,0x02,0x01,0x01,0x78,0x02,0x01],
[0x02,0x01,0x44,0x01,0x0C,0x01,0x00,0x02],
[0x03,0x02,0x02,0x01,0x02,0x02,0x01,0x03],
[0x04,0x01,0x02,0x02,0x01,0x04,0x00,0x00],
[0x05,0x02,0x03,0x02,0x01,0x01,0x01,0x01],
[0x06,0x01,0x01,0x00,0x02,0x01,0x01,0x01],
[0x07,0x07,0x01,0x05,0x01,0x01,0x01,0x01],
[0x08,0x01,0x61,0x01,0x00,0x01,0x00,0x01],
[0x09,0x03,0x02,0x01,0x01,0x01,0x02,0x24],
[0x0A,0x01,0x03,0x01,0x03,0x13,0x13,0x57],
[0x0B,0x30,0x00,0x05,0x01,0x02,0x01,0x01],
[0x0C,0x01,0x00,0x00,0x00,0x00,0x01,0x01],
[0x0D,0x01,0x01,0x01,0x02,0x02,0x01,0x02],
[0x0E,0x02,0x05,0x00,0x00,0x01,0x01,0x01],
[0x0F,0x02,0x00,0x44,0x00,0x01,0x00,0x01],
[0x10,0x01,0x01,0x02,0x02,0x01,0x01,0x04],
[0x11,0x02,0x01,0x01,0x03,0x00,0x00,0x01],
[0x12,0x02,0x02,0x00,0x02,0x04,0x02,0x00],
[0x13,0x01,0x01,0x00,0x01,0x02,0x01,0x02],
[0x14,0x02,0x02,0x01,0x00,0x00,0x03,0x00],
[0x15,0x00,0x01,0x02,0x02,0x02,0x00,0x01],
[0x16,0x01,0x00,0x01,0x00,0x01,0x01,0x04],
[0x17,0x00,0x00,0x05,0x01,0x01,0x00,0x01],
[0x18,0x01,0x00,0x00,0x00,0x01,0x01,0x00],
[0x19,0x00,0x00,0x00,0x03,0x00,0x00,0x05],
[0x1A,0x00,0x01,0x02,0x00,0x00,0x00,0x00],
[0x1B,0x00,0x02,0x00,0x02,0x03,0x00,0x00],
[0x1C,0x01,0x01,0x01,0x00,0x02,0x02,0x03],
[0x1D,0x00,0x00,0x01,0x00,0x01,0x00,0x01],
[0x1E,0x00,0x00,0x00,0x00,0x02,0x00,0x03],
[0x1F,0x02,0x00,0x00,0x02,0x00,0x04,0x00],
[0x20,0x02,0x02,0x00,0x00,0x02,0x00,0x02],
[0x21,0x00,0x03,0x00,0x00,0x00,0x00,0x06],
[0x22,0x00,0x00,0x00,0x02,0x01,0x00,0x00],
[0x23,0x01,0x01,0x00,0x02,0x00,0x00,0x00],
[0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x00],             
],
}


canmsg_dict_5 = {
'StopMsg' :     [[0xFF]],  
'HMI_On' :      [0x2e3, [0x02,0,0,0,0,0,0,0]],
'HMI_Off' :     [0x2e3, [0x01,0,0,0,0,0,0,0]],
}

canmsg_dict_6 = {
'StopMsg' : [[0xFF]],  
'TP' :      [0x7DF, [0x2,0x3E,0x80,DefaultRestpayload,DefaultRestpayload,DefaultRestpayload,DefaultRestpayload,DefaultRestpayload]]
}

canmsg_dict_7 = {
'Alive' : [0x511, [0x0,02,0,0,0,0,0,0]],
}

