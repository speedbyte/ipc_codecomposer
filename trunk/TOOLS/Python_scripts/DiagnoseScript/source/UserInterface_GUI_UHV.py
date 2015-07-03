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

DefaultRestpayload = 0x55

#CalibrationDataWritable
diagnostics_dict_CalibrationDataWritable = {
'ANALYSE_1' : [0x2E, 0x05, 0x00],
'RESET_TO_FACTORY_SETTING' : [0x2E, 0x09, 0x05],
'SET_NUMBER_ROAMING_FOR_INFO_CALL' : [0x2E, 0x09, 0x09],
'SET_NUMBER_ROAMING_FOR_SERVICE_CALL' : [0x2E, 0x09, 0x0A],
'SET_NUMBER_FOR_INFO_CALL' : [0x2E, 0x09, 0x0B],
'SET_NUMBER_FOR_SERVICE_CALL' : [0x2E, 0x09, 0x0C],
'SMS_FUNCTIONALITY_OPERATING_UNIT' : [0x2E, 0x09, 0x11],
'BLUETOOTH_ACKNOWLEDGEMENT_SIGNAL' : [0x2E, 0x09, 0x14],
'DEVELOPER_TESTMODE' : [0x2E, 0x10, 0x01],
'MASKING_OF_LANGUAGES' : [0x2E, 0x22, 0x33],
'UNIVERSAL_PREPARATION_FOR_MOBILE_TELEPHONE' : [0x2E, 0x24, 0x16, "YourName"],
'TELEPHONE_BASIC_VOLUME' : [0x2E, 0x24, 0x1C],
'VOICE_OUTPUT_BASIC_VOLUME' : [0x2E, 0x24, 0x1D],
'MICROPHONE_SENSITIVITY' : [0x2E, 0x24, 0x1E],
'BLUETOOTH_SET_PIN_CODE' : [0x2E, 0x24, 0x20],
'USER_PROFILES' : [0x2E, 0x24, 0x22],
'MUTE_DELAY' : [0x2E, 0x24, 0x23],
'REFERENCE_CHANNEL_DELAY' : [0x2E, 0x24, 0x24],
'MEDIA_DEVICE_BASIC_VOLUME' : [0x2E, 0x24, 0x29],
'EMERGENCY_NUMBER' : [0x2E, 0x24, 0x48],
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
'STATUS_DES_PROGRAMMSPEICHERS' : [0x22, 0x04, 0x05],
'ANZAHL_DER_PROGRAMMIERVERSUCHE' : [0x22, 0x04, 0x07],
'ANZAHL_ERFOLGREICHER_PROGRAMMIERVERSUCHE' : [0x22, 0x04, 0x08],
'ANZAHL_DER_PARAMETRIERVERSUCHE' : [0x22, 0x04, 0x09],
'ANZAHL_ERFOLGREICHER_PARAMETRIERVERSUCHE' : [0x22, 0x04, 0x0A],
'VW_LOGICAL_SOFTWARE_BLOCK_LOCK_VALUE' : [0x22, 0x04, 0x0F],
'FINGERPRINT' : [0x22, 0xF1, 0x5B],
'DATUM_DER_LETZTEN_CODIERUNG' : [0x22, 0xF1, 0x7B],
'FAZIT_SERIENNUMMER' : [0x22, 0xF1, 0x7C],
'HERSTELLERAENDERUNGSSTAND' : [0x22, 0xF1, 0x7E],
'IDENTIFIKATION_DER_STANDARDSOFTWARE' : [0x22, 0xF1, 0x81],
'IDENTIFIKATION_DER_PARAMETRIERUNG' : [0x22, 0xF1, 0x82],
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
'FINGERPRINT' : [0x2E, 0xF1, 0x5A],
'SYSTEMBEZEICHNUNG' : [0x2E, 0xF1, 0x97],
'WERKSTATTCODE_DAS_ANGESCHLOSSENEN_TESTERS' : [0x2E, 0xF1, 0x98],
'PROGRAMMING_DATE' : [0x2E, 0xF1, 0x99],
'ASAM_ODX_DATEI_KENNZEICHNUNG' : [0x2E, 0xF1, 0x9E],
'VARIANTE_DES_PARAMETERSATZES' : [0x2E, 0xF1, 0xA0],
'VERSION_DES_PARAMETERSATZES' : [0x2E, 0xF1, 0xA1],
'ASAM_ODX_DATEIVERSION' : [0x2E, 0xF1, 0xA2],
'HARDWAREVERSION' : [0x2E, 0xF1, 0xA3],
'FAHRZEUGAUSSTATTUNGSCODE' : [0x2E, 0xF1, 0xA4],
'BAUZUSTANDSDOKUMENTATION' : [0x2E, 0xF1, 0xAC],
}

#CodierungWritable

diagnostics_dict_CodierungWritable = {
'CODIERUNG' : [0x2E, 0x06, 0x00],
}

diagnostics_dict_Miscallenous = {
'DIAGNOSE_SESSION' : [0x10],
'LAENGE_DER_CODIERUNG' : [0x06, 0x01],
'COMM_ENABLE_MESSAGES' : [0x28, 0x00, 0x01],
'COMM_DISABLE_MESSAGES' : [0x28, 0x01, 0x01],
'DTC_AUSLESEN' : [0x19, 0x02, 0x0c],
'LISTE_DER_UNGEPRUEFTEN_FEHLERPFADE_AUSLESEN' : [0x19, 0x02, 0x10],
'ALLE_DTC_LOESCHEN' : [0x14, 0xFF, 0xFF, 0xFF],
}

#ActuatorTest

diagnostics_dict_ActuatorTest = {
'TESTING_SIGNAL_AUDIO' : [0x2F, 0x01, 0x6B],
'AUDIO_MUTE_BY_WIRE' : [0x2F, 0x01, 0x6C],
'AUDIO_MUTE_BY_CAN' : [0x2F, 0x01, 0x6D],
'BLUETOOTH_SEARCH_DEVICES' : [0x2F, 0x01, 0x6E],
'BLUETOOTH_PAGING' : [0x2F, 0x01, 0x6F],
'TEST_VOICE_PROMPT' : [0x2F, 0x01, 0x70],
'ILLUMINATION_TELEPHONE_OPERATING_UNIT' : [0x2F, 0x01, 0x71],
'TESTING_SIGNAL_AUDIO_ALTERNATING' : [0x2F, 0x01, 0x72],
'AUDIO_LOOP_BACK' : [0x2F, 0x02, 0xE1],
'POWER_SUPPLY_CRADLE_ON_OFF_TEST' : [0x2F, 0x04, 0x10],
'ILLUMINATION_TELEPHONE_OPERATION_UNIT_CONTROL_TEST' : [0x2F, 0x04, 0x11],
'BLUETOOTH_AUDIO_PATH_LOOPBACK_CONTROL_TEST' : [0x2F, 0x04, 0x12],
}

#DtcOverview

diagnostics_dict_DtcOverview = {
'MIKROFON_FUER_TELEFON_KURZSCHLUSS_NACH_MASSE' : [0x90, 0x48,0x11],
'MIKROFON_FUER_TELEFON_KURZSCHLUSS_NACH_PLUS' : [0x90, 0x048, 0x12],
'MIKROFON_FUER_TELEFON_UNTERBRECHUNG' : [0x90, 0x048, 0x13],
#'STUMMSCHALTUNG_RADIO_KURZSCHLUSS_NACH_MASSE' : [0x04, 0x04, 0x04],
#'STUMMSCHALTUNG_RADIO_KURZSCHLUSS_NACH_PLUS' : [0x04, 0x04, 0x04],
#'STUMMSCHALTUNG_RADIO_UNTERBRECHUNG' : [0x04, 0x04, 0x04],
'AUDIOKANAL_RECHTS_KURZSCHLUSS_NACH_MASSE' : [0x90, 0x04e, 0x11],
'AUDIOKANAL_RECHTS_KURZSCHLUSS_NACH_PLUS' : [0x90, 0x04e, 0x12],
'AUDIOKANAL_RECHTS_UNTERBRECHUNG' : [0x90, 0x04e, 0x13],
'AUDIOKANAL_RECHTS_KURZSCHLUSS_UNTEREINANDER' : [0x90, 0x04e, 0xf0],
'AUDIOKANAL_LINKS_KURZSCHLUSS_NACH_MASSE' : [0x90, 0x4F, 0x11],
'AUDIOKANAL_LINKS_KURZSCHLUSS_NACH_PLUS' : [0x90, 0x4F, 0x12],
'AUDIOKANAL_LINKS_UNTERBRECHUNG' : [0x90, 0x4F, 0x13],
'AUDIOKANAL_LINKS_KURZSCHLUSS_UNTEREINANDER' : [0x90, 0x4F, 0xf0],
'FUNKTIONSEINSCHRAENKUNG_DURCH_UEBERTEMPERATUR' : [0x90,0x50,0x00],
'HALTERUNG_FUER_HANDYHALTER__BASEPLATE__KURZSCHLUSS_NACH_MASSE' : [0x90,0x51,0x11],
'HALTERUNG_FUER_HANDYHALTER__BASEPLATE__KURZSCHLUSS_NACH_PLUS' : [0x90,0x51,0x12],
'HALTERUNG_FUER_HANDYHALTER__BASEPLATE__UNTERBRECHUNG' : [0x90,0x51,0x13],
'BEDIENEINHEIT_FUER_HANDYVORBEREITUNG__DREI_TASTEN_MODULE__MECHANISCHER_FEH__LER' : [0x90,0x52,0x07],
'BEDIENEINHEIT_FUER_HANDYVORBEREITUNG__DREI_TASTEN_MODULE__KURZSCHLUSS_NACH_MASSE' : [0x90,0x52,0x11],
'BEDIENEINHEIT_FUER_HANDYVORBEREITUNG__DREI_TASTEN_MODULE__KURZSCHLUSS_NACH_PLUS' : [0x90,0x52,0x012],
'BEDIENEINHEIT_FUER_HANDYVORBEREITUNG__DREI_TASTEN_MODULE__UNTERBRECHUNG' : [0x90,0x52,0x13],
'GSM_ANTENNE_KURZSCHLUSS_NACH_MASSE' : [0x90,0x53,0x11],
'GSM_ANTENNE_UNTERBRECHUNG_KURZSCHLUSS_NACH_PLUS' : [0x90,0x53,0x15],
'HANDYHALTER__CRADLE__MECHANISCHER_FEHLER' : [0x90,0x57,0x07],
'STEUERGERAET_DEFEKT_Programmspeicherfehler' : [0xA0,0x00,0x45],
'STEUERGERAET_DEFEKT_EEPROM_FEHLER' : [0xA0,0x00,0x46],
'STEUERGERAET_DEFEKT_Watchdogfehler' : [0xA0,0x00,0x47],
'UNGUELTIGER_DATENSATZ' : [0xA0, 0x05, 0x00],
'DATENBUS_KOMFORT_DEFEKT' : [0x00, 0x00, 0x21],
'DATENBUS_KOMFORT_KEINE_KOMMUNIKATION' : [0x00, 0x00, 0x22],
'INFOTAINMENT_CAN_DEFEKT' : [0xC0,0x64,0x00],
'INFOTAINMENT_CAN_KEINE_KOMMUNIKATION' : [0xC0,0x65,0x00],
'BODYCOMPUTER_1__BORDNETZSTEUERGERAET___EL' : [0xC1,0x40,0x00], 
'DIAGNOSE_INTERFACE_SG_KEINE_KOMMUNIKATION' : [0xD0,0x09,0x00],
'STEUERGERAET_FUER_SCHALTTAFELEINSATZ_KEINE_KOMMUNIKATION' : [0xC1,0x55,0x00],
'STEUERGERAET_FUER_LENKSAEULENELEKTRONIK_KEINE_KOMMUNIKATION' : [0xC2,0x12,0x00],
'VERSORGUNGSSPANNUNG_SPANNUNG_ZU_NIEDRIG' : [0xD0,0x11,0x00],
'VERSORGUNGSSPANNUNG_SPANNUNG_ZU_HOCH' : [0xD0,0x12,0x00],
'STEUERGERAET_NICHT_CODIERT' : [0xD0,0x13,0x00],
'STEUERGERAET_FALSCH_CODIERT' : [0xD0,0x14,0x00],
'STEUERGERAET_RADIO__RNS__KEIN_SIGNAL_KOMMUNIKATION' : [0x00,0x00,0x16],
'FUNKTIONSEINSCHRAENKUNG_DURCH_UNTERSPANNUNG' : [0xD4,0x00,0x00],
'FUNKTIONSEINSCHRAENKUNG_DURCH_UEBERSPANNUNG' : [0xD4,0x01,0x00],
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
'Invalid' :   [0x6C1, [0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'English' :   [0x6C1, [0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'German' :    [0x6C1, [0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'Italian' :   [0x6C1, [0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'French' :    [0x6C1, [0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'Spanish' :   [0x6C1, [0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'Turkish' :   [0x6C1, [0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'Russian' :   [0x6C1, [0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'Dutch' :     [0x6C1, [0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'Polish' :    [0x6C1, [0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'Swedish' :   [0x6C1, [0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
'Portugese' : [0x6C1, [0x0B,0x00,0x00,0x00,0x00,0x00,0x00,0x00]],
}

canmsg_dict_3 = {
'StopMsg' :             [[0xFF]],  
'IgnitionOn' :      [0x575, [0x20,0,0,0,0,0,0,0]],
'IgnitionOff' :     [0x575, [0x00,0,0,0,0,0,0,0]],
'RadioOn' :         [0x575, [0x20,0,0,0,0,0,0,0]],
'RadioOff' :        [0x575, [0x00,0,0,0,0,0,0,0]],
}

canmsg_dict_4 = {
'StopMsg' : [[0xFF]],            
'VW' :      [0x651, [0xC0,0x04,0x62,0x8F,0x34,0x53,0xC1,0x00]],
'Skoda' :   [0x651, [0xC0,0x14,0x62,0x8F,0x34,0x53,0xC1,0x00]],
'Seat' :    [0x651, [0xC0,0x24,0x62,0x8F,0x34,0x53,0xC1,0x00]],
'VW-Nutz' : [0x651, [0xC0,0x34,0x62,0x8F,0x34,0x53,0xC1,0x00]],
'Audi' :    [0x651, [0xC0,0x44,0x62,0x8F,0x34,0x53,0xC1,0x00]],
}

canmsg_dict_5 = {
'StopMsg' :     [[0xFF]],  
'HMI_On' :      [0x2e3, [0x02,0,0,0,0,0,0,0]],
'HMI_Off' :     [0x2e3, [0x01,0,0,0,0,0,0,0]],
}

canmsg_dict_6 = {
'StopMsg' : [[0xFF]],  
'TP' :      [0x700, [0x2,0x3E,0x80,DefaultRestpayload,DefaultRestpayload,DefaultRestpayload,DefaultRestpayload,DefaultRestpayload]]
}

canmsg_dict_7 = {
'Alive' : [0x511, [0x0,02,0,0,0,0,0,0]],
}

