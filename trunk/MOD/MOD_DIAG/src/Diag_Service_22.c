/******************************************************************************/
/*****************  Copyright (c) 2011 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     Diag_Service_22.c
*-----------------------------------------------------------------------------
* Module Name:    DIAG
*-----------------------------------------------------------------------------
* Description:    Handle Diagnose Service 22
*-----------------------------------------------------------------------------
* $Date: 2011-07-20 16:38:51 +0200 (Mi, 20 Jul 2011) $
* $Rev: 20971 $
* $Author: weber $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_APP_CAN/trunk/src/APP_CAN_C1.c $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/
#include <osek.h>
/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*---------------------------------------------------------------------------- */

#include <stdlib.h>

#include "Common.h"
#include "Version.h"
#include "desc.h"
#include "ccl_inc.h"
#include "OSEK_HostTask_H1.h"
#include "APP_DESC.h"
#include "Diag_ReqHandling.h"
#include "Diag_Service_22.h"
#include "Diag_Service_2E.h"
#include "APP_COMMON_Utils.h"
#include "EEPROM.h"
#include "EEPROM_LAYOUT_CFG.h"
#include "DEH.h"
#include "MONITOR_ADC.h"
#include "TEMPERATURE.h"
#include "TRACE.h"
#include "Diag_Service_22.id"
/*----------------------------------------------------------------------------*/
/* pragma Directives                                                          */
/*----------------------------------------------------------------------------*/
extern DiagnoseContextType gDiagnoseContext;
/*----------------------------------------------------------------------------*/
/* Global Variables Definitions (avoid as much as possible!)                  */
/*----------------------------------------------------------------------------*/
/*variable for dynamic Baudrate handling*/
/*----------------------------------------------------------------------------*/
/* Private Manifest Constant Definitions                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Types                                                              */
/*----------------------------------------------------------------------------*/
/**
\brief	description of the type
*/

/*----------------------------------------------------------------------------*/
/* Prototypes of file local Methods                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* File local Code Macros                                                     */
/*----------------------------------------------------------------------------*/
/**
\brief	description of the macros
*/

/*----------------------------------------------------------------------------*/
/* File local Variables                                                       */
/*----------------------------------------------------------------------------*/
#define ID_F181_STANDARD_SOFTWARE_PLATTFORM     46

/*----------------------------------------------------------------------------*/
/* File local const Definitions                                               */
/*----------------------------------------------------------------------------*/
const Uint8Type MOD_DIAG_SDS_VERSION_VALUES[ID_F181_STANDARD_SOFTWARE_PLATTFORM] =
{
    0xFF, 0xFF, 0xFF,       // Component Protection
    0xFF, 0xFF, 0xFF,       // BAP
    0x02, 0xFF, 0xFF,       // UDS-Protocol
    DEH_SW_MAJOR_VERSION, DEH_SW_MINOR_VERSION, DEH_SW_PATCH_VERSION,       // Diagnostic-Event-Handler
    (Uint8Type)(DRVCAN_TMS470HECCSCCHLL_VERSION>>8), (Uint8Type)DRVCAN_TMS470HECCSCCHLL_VERSION, DRVCAN_TMS470HECCSCCHLL_RELEASE_VERSION,       // CAN-Driver
    0xFF, 0xFF, 0xFF,       // VW-TP2.0
    0xFF, 0xFF, 0xFF,       // VW-TP1.6
    (Uint8Type)(TP_ISO15765_VERSION >> 8),(Uint8Type)TP_ISO15765_VERSION, TP_ISO15765_RELEASE_VERSION,       // ISO-TP
    0x07, 0xFF, 0xFF,       // KWP2000 Protocol
    0x09, 0x02, 0x02,       // OSEK-Operating System
    0xFF, 0xFF, 0xFF,       // Porsche CAN-Stack
    0xFF, 0xFF, 0xFF, 0xFF, // Porsche CAN-Stack license number
    0xFF, 0xFF, 0xFF,       // Porsche Bootloader version
    0xFF, 0xFF, 0xFF, 0xFF, // Porsche Bootloader licence number
    (Uint8Type)(VERSIONNUMBER >> 8), (Uint8Type)VERSIONNUMBER              // Porsche CAN database version
};



/**
\brief	description of the private constant
*/
/************** A T T E N T I O N *****************************
   because of speed optimization binary search algorithm is used
   which requires a sorted (ascending !!!) data identifier table */

const t_ReadDataIdCfgItem cs_ReadDataIdItem[] = {
/*  DID     Length  Fuction */
{   0x0100,  1,     ReadDataByIdentifier_0100_StatusInputOutputControl},
{   0x0102,  1,     ReadDataByIdentifier_0102_StatusRoutinen},
{   0x0103,  1,     ReadDataByIdentifier_0103_SecurityAccessCounter},
{   0x0286,  1,     ReadDataByIdentifier_0286_SpannungKlemme30},
{   0x0407,  2,     ReadDataByIdentifier_0407_LogicalSoftwareBlockCounterOfProgrammingAttempts},
{   0x040A,  1,     ReadDataByIdentifier_040A_Verlernzaehler},
{   0x040F,  2,     ReadDataByIdentifier_040F_LogicalBlockLockLimitValue},
{   0x04FC,  3,     ReadDataByIdentifier_04FC_ProductionModeDeactivate},
{   0x04FE,  3,     ReadDataByIdentifier_04FE_ProductionMode},
{   0x0500, 12,     ReadDataByIdentifier_0500_ParameterStrommessung},
{   0x0501, 31,     ReadDataByIdentifier_0501_BluetoothFriendlyName},
{   0x0505,  1,     ReadDataByIdentifier_0505_ProductionFlag},
{   0x0506,  8,     ReadDataByIdentifier_0506_TestBytes},
{   0x0600, 15,     ReadDataByIdentifier_0600_Kodierwert},
{   0xF101,  5,     ReadDataByIdentifier_F101_Zeitstempel},
{   0xF102,  3,     ReadDataByIdentifier_F102_Kilometerstand},
{   0xF103,  1,     ReadDataByIdentifier_F103_Pinzustaende},
{   0xF104,  1,     ReadDataByIdentifier_F104_Spannung},
{   0xF105,  1,     ReadDataByIdentifier_F105_Temperatur},
{   0xF106,  2,     ReadDataByIdentifier_F106_Betriebsdauer},
{   0xF15B, 10,     ReadDataByIdentifier_F15B_LogicalBlockProgrammingFingerprint},
{   0xF179,  4,     ReadDataByIdentifier_F179_ECUSupplierNumber},
{   0xF17B,  3,     ReadDataByIdentifier_F17B_TesterdatumKodierungLesen},
{   0xF17C, 23,     ReadDataByIdentifier_F17C_FazitIdentificationString},
{   0xF17D,  4,     ReadDataByIdentifier_F17D_ECUProductionTestSystemNumber},
{   0xF17E,  8,     ReadDataByIdentifier_F17E_ECUProductionChangeNumber},
{   0xF181, 46,     ReadDataByIdentifier_F181_StandardSoftwarePlattform},
{   0xF186,  1,     ReadDataByIdentifier_F186_ActiveDiagnosticSession},
{   0xF187, 11,     ReadDataByIdentifier_F187_SparePartNumber},
{   0xF188,  3,     ReadDataByIdentifier_F188_ApplikationSoftwareDatum},
{   0xF189,  4,     ReadDataByIdentifier_F189_SoftwareVersionNumber},
{   0xF18B,  3,     ReadDataByIdentifier_F18B_ECUManufacturingDate},
{   0xF18C, 14,     ReadDataByIdentifier_F18C_ECUSerialNumber},
{   0xF190, 17,     ReadDataByIdentifier_F190_Fahrgestellnummer},
{   0xF191, 11,     ReadDataByIdentifier_F187_SparePartNumber},
{   0xF197, 13,     ReadDataByIdentifier_F197_SystemnameOderMotortyp},
{   0xF198,  6,     ReadDataByIdentifier_F198_RepairShopCodeOrTesterSerialNumber},
{   0xF19A,  6,     ReadDataByIdentifier_F19A_TesterkennungKalibrierungLesen},
{   0xF19B,  3,     ReadDataByIdentifier_F19B_TesterdatumKalibrierungLesen},
{   0xF19E, 24,     ReadDataByIdentifier_F19E_ODXDiagnosticECUIdentifier},
{   0xF1A2,  6,     ReadDataByIdentifier_F1A2_ODXDiagnosticVersionIdentifier},
{   0xF1A3,  3,     ReadDataByIdentifier_F1A3_HardwareVersionNumber},
{   0xF1A4,  8,     ReadDataByIdentifier_F1A4_VehEquipCodePRNbr},
{   0xF1A5,  6,     ReadDataByIdentifier_F1A5_TesterkennungKodierungLesen},
{   0xF1AA,  4,     ReadDataByIdentifier_F1AA_VWWorkshopSystemName},
{   0xF1AB,  8,     ReadDataByIdentifier_F1AB_LogicalBlockSoftwareVersion},
{   0xF1AE,  1,     ReadDataByIdentifier_F1AE_NumberOfLogins},
{   0xF1DF,  2,     ReadDataByIdentifier_F1DF_SGProgrammierStatus}
};
/*----------------------------------------------------------------------------*/
/* Private Address Calculations                                               */
/*----------------------------------------------------------------------------*/
void ReadDataByIdentifier_0100_StatusInputOutputControl(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_0100_StatusInputOutputControl received");
    /* If Messwertblock implemented handle this parameter correct */
    resData[0] = 0x00;
    DIAG_vDiagnoseIdRequestDone();
}
void ReadDataByIdentifier_0102_StatusRoutinen(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_0102_StatusRoutinen received");
    /* If Messwertblock implemented handle this parameter correct */
    resData[0] = 0x00;
    DIAG_vDiagnoseIdRequestDone();
}
void ReadDataByIdentifier_040A_Verlernzaehler(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_040A_Verlernzaehler received");
    resData[0] = 0xFF;
    if(TRUE == APP_CAN_bIsDiagnose1MessageReceived())
    {
        resData[0] = (Uint8Type)IlGetRxDGN_Verlernzaehler();
    }
    DIAG_vDiagnoseIdRequestDone();
}
void ReadDataByIdentifier_0407_LogicalSoftwareBlockCounterOfProgrammingAttempts(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_0407_LogicalSoftwareBlockCounterOfProgrammingAttempts received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_AswSWCntProgrAttempts_LEN,
                                                EEPROM_LAYOUT_ENUM_AswSWCntProgrAttempts);
    DIAG_vDiagnoseIdRequestDone();
}
void ReadDataByIdentifier_040F_LogicalBlockLockLimitValue(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_040F_LogicalBlockLockLimitValue received");
    (void)memset(resData, 0x00, 2);
    DIAG_vDiagnoseIdRequestDone();
}
void ReadDataByIdentifier_F15B_LogicalBlockProgrammingFingerprint(DescMsg resData)
{
    (void)memset(resData, 0x00, 10);
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_ProgDate_LEN,
                                                EEPROM_LAYOUT_ENUM_ProgDate);
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F15B_LogicalBlockProgrammingFingerprint received");
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_0286_SpannungKlemme30(DescMsg resData)
{
    Uint16Type pwrValue = 0;
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_0286_SpannungKlemme30 received");
    pwrValue = MONITOR_ADC_u16GetMovingAverageADCValueUBatt();
    resData[0] = (0.28623 * pwrValue) + 5;
    DEBUG_VALUE1(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_0286_SpannungKlemme30: Spannung = %d V", resData[0]);
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_0500_ParameterStrommessung(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_0500_ParameterStrommessung received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_ParameterStrommessung_LEN,
                                                EEPROM_LAYOUT_ENUM_ParameterStrommessung);
    DEBUG_VALUE4(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_0500_ParameterStrommessung: ADIV high %x low %x SDARS high %x low %x",
                    resData[0],
                    resData[1],
                    resData[2],
                    resData[3]);
    DEBUG_VALUE4(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_0500_ParameterStrommessung: DAB high %x low %x GPS high %x low %x",
                    resData[4],
                    resData[5],
                    resData[6],
                    resData[7]);
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_04FC_ProductionModeDeactivate(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_04FC_ProductionModeDeactivate received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_ProductionMode_LEN,
                                                EEPROM_LAYOUT_ENUM_ProductionMode);
    DEBUG_VALUE4(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_04FC_ProductionModeDeactivate: Value %x %x %x %c",
                    resData[0],
                    resData[1],
                    resData[2],
                    ' ');
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_04FE_ProductionMode(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_04FE_ProductionMode received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_ProductionMode_LEN,
                                                EEPROM_LAYOUT_ENUM_ProductionMode);
    DEBUG_VALUE4(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_04FE_ProductionMode: Value %x %x %x %c",
                    resData[0],
                    resData[1],
                    resData[2],
                    ' ');
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_F1AA_VWWorkshopSystemName(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F1AA_VWWorkshopSystemName received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_VWWorkshopSystemName_LEN,
                                                EEPROM_LAYOUT_ENUM_VWWorkshopSystemName);
    DEBUG_VALUE4(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F1AA_VWWorkshopSystemName: Value %x %x %x %x",
                    resData[0],
                    resData[1],
                    resData[2],
                    resData[3]);
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_F1A4_VehEquipCodePRNbr(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F1A4_VehEquipCodePRNbr received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_VehEquipCodePRNbr_LEN,
                                                EEPROM_LAYOUT_ENUM_VehEquipCodePRNbr);
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_F106_Betriebsdauer(DescMsg resData)
{
    Uint8Type buffer[3];
    Uint32Type runTime = 0x00;
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F106_Betriebsdauer received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(buffer,
                                                PAG_DB_EE_ADDRESS_OperationTimeOverall_LEN,
                                                EEPROM_LAYOUT_ENUM_OperationTimeOverall);
    runTime = osGetSystemCounter() / SEC(60);
    runTime += ((buffer[2]<<16) | (buffer[1]<<8) | buffer[0]);
    DEBUG_VALUE1(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F106_Betriebsdauer: Time[min] = %d", runTime);
    runTime = runTime / 60;
    if (runTime > 0xFFFF)
    {
        runTime = 0xFFFF;
    }
    DEBUG_VALUE1(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F106_Betriebsdauer: Time[h] = %d", runTime);
    resData[0] = (Uint8Type)(runTime >> 8);
    resData[1] = (Uint8Type)(runTime & 0x00FF);
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_F105_Temperatur(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F105_Temperatur received");
    resData[0] = TEMPERATURE_u8GetTemperature() + 50;
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_F104_Spannung(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F104_Spannung received");
    resData[0] = 0x00;
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_F103_Pinzustaende(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F103_Pinzustände received");
    resData[0] = 0x00;
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_F102_Kilometerstand(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F102_Kilometerstand received");
    (void)memset(resData, 0xFF, 3);
    if(TRUE == APP_CAN_bIsDiagnose1MessageReceived())
    {
        //Uint32Type kilometer = IlGetRxKBI_Kilometerstand();
        resData[0] = (Uint8Type)(IlGetRxKBI_Kilometerstand() >> 16);
        resData[1] = (Uint8Type)(IlGetRxKBI_Kilometerstand() >> 8);
        resData[2] = (Uint8Type)IlGetRxKBI_Kilometerstand();
    }
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_F101_Zeitstempel(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F101_Zeitspempel received");
    (void)memset(resData, 0x00, 5);
    if(TRUE == APP_CAN_bIsDiagnose1MessageReceived())
    {
        resData[0] = IlGetRxUH_Jahr() << 1 | IlGetRxUH_Monat() >> 3;
        resData[1] = IlGetRxUH_Monat() << 5 | IlGetRxUH_Tag() >> 3;
        resData[2] = IlGetRxUH_Stunde() << 3 | IlGetRxUH_Minute() >> 5;
        resData[3] = IlGetRxUH_Minute() << 5 | IlGetRxUH_Sekunde() >> 1;
        resData[4] = IlGetRxUH_Sekunde() << 7;
    }
    DIAG_vDiagnoseIdRequestDone();
}
void ReadDataByIdentifier_0600_Kodierwert(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_0600_Kodierwert received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_VWCodingValue_LEN,
                                                EEPROM_LAYOUT_ENUM_VWCodingValue);
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_F18B_ECUManufacturingDate(DescMsg resData)
{
    Uint8Type buffer[23];
    (void)EEPROM_enGetByteSequenceFromRamMirror(buffer,
                                                PAG_DB_EE_ADDRESS_VWFAZITIdentificationString_LEN,
                                                EEPROM_LAYOUT_ENUM_VWFAZITIdentificationString);
    /* index of fazit string 
        7+8 day
        10+11 month
        13+14 year */
    buffer[15] = 0;
    resData[0] = atoi((const char *)&buffer[13]);
    buffer[12] = 0;
    resData[1] = atoi((const char *)&buffer[10]);
    buffer[9] = 0;
    resData[2] = atoi((const char *)&buffer[7]);
    DEBUG_VALUE4(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F18B_ECUManufacturingDate: %d.%d.%d %c", 
                    resData[2],
                    resData[1],
                    resData[0],
                    ' ');
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_F179_ECUSupplierNumber(DescMsg resData)
{
    Uint8Type buffer[23];
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F179_ECUSupplierNumber received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(buffer,
                                                PAG_DB_EE_ADDRESS_VWFAZITIdentificationString_LEN,
                                                EEPROM_LAYOUT_ENUM_VWFAZITIdentificationString);
    (void)memcpy(resData, (const void *)&buffer[23-4], 4);
    DIAG_vDiagnoseIdRequestDone();
}


void ReadDataByIdentifier_F17D_ECUProductionTestSystemNumber(DescMsg resData)
{
    Uint8Type buffer[23];
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F17D_ECUProductionTestSystemNumber received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(buffer,
                                                PAG_DB_EE_ADDRESS_VWFAZITIdentificationString_LEN,
                                                EEPROM_LAYOUT_ENUM_VWFAZITIdentificationString);
    (void)memcpy(resData, (const void *)&buffer[23-8], 4);
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_F17E_ECUProductionChangeNumber(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F17E_ECUProductionChangeNumber received");
    (void)memset(resData, 0x00, 8);
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_F198_RepairShopCodeOrTesterSerialNumber(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F198_RepairShopCodeOrTesterSerialNumber received");
    (void)memcpy((void *)resData, (const void *)gDiagnoseContext.au8FingerprintValue, 6);
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_0505_ProductionFlag(DescMsg resData)
{
    /* Porsche doesn't support Read/WriteByAddress in SOP software.
       Therefore change the function to Read/WriteByIdentifier */
	EEDeviceControlBlockType *pEEDcb = (EEDeviceControlBlockType *)getEEHostControl();

    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_0505_ProductionFlag received");
    if (COMMON_RSP_OK == EEPROM_sfRead(pEEDcb,
				                        PAG_DB_EE_ADDRESS_ProductionFlag,
				                        (Uint8Type *)resData,
				                        PAG_DB_EE_ADDRESS_ProductionFlag_LEN))
    {
        DIAG_vDiagnoseIdRequestDone();
    }
    else
    {
        // do it again
        DIAG_vDiagnoseIdPending();
    }
}

void ReadDataByIdentifier_0506_TestBytes(DescMsg resData)
{
	EEDeviceControlBlockType *pEEDcb = (EEDeviceControlBlockType *)getEEHostControl();

    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_0506_TestBytes received");
    if (COMMON_RSP_OK == EEPROM_sfRead(pEEDcb,
				                        PAG_DB_EE_ADDRESS_TestBytes,
				                        (Uint8Type *)resData,
				                        PAG_DB_EE_ADDRESS_TestBytes_LEN))
    {
        DIAG_vDiagnoseIdRequestDone();
    }
    else
    {
        // do it again
        DIAG_vDiagnoseIdPending();
    }
}

void ReadDataByIdentifier_0103_SecurityAccessCounter(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_0103_SecurityAccessCounter received");
    resData[0] = gDiagnoseContext.securityState & MASK_SEED_COUNTER;
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_F189_SoftwareVersionNumber(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "DataByIdentifier_F189_SoftwareVersionNumber received");
    (void)memcpy((void *)resData, (const void *)SoftwareVersion, 4);
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_F1A3_HardwareVersionNumber(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "DataByIdentifier_F1A3_HardwareVersionNumber received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_ECUHardwareVersionNbr_LEN,
                                                EEPROM_LAYOUT_ENUM_ECUHardwareVersionNbr);
    DIAG_vDiagnoseIdRequestDone();
}


void ReadDataByIdentifier_F18C_ECUSerialNumber(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "DataByIdentifier_F18C_ECUSerialNumber received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_ECUSerialNumber_LEN,
                                                EEPROM_LAYOUT_ENUM_ECUSerialNumber);
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_F17C_FazitIdentificationString(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "DataByIdentifier_F17C_FazitIdentificationString received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_VWFAZITIdentificationString_LEN,
                                                EEPROM_LAYOUT_ENUM_VWFAZITIdentificationString);
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_F187_SparePartNumber(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F187_SparePartNumber received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_VWSparePartNbr_LEN,
                                                EEPROM_LAYOUT_ENUM_VWSparePartNbr);
    DIAG_vDiagnoseIdRequestDone();
}


void ReadDataByIdentifier_F1A2_ODXDiagnosticVersionIdentifier(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "DataByIdentifier_F1A2_ODXDiagnosticVersionIdentifier received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_AsamOdxFileVersion_LEN,
                                                EEPROM_LAYOUT_ENUM_AsamOdxFileVersion);
    DIAG_vDiagnoseIdRequestDone();
}


void ReadDataByIdentifier_F19E_ODXDiagnosticECUIdentifier(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "DataByIdentifier_F19E_ODXDiagnosticECUIdentifier received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_AsamOdxFileID_LEN,
                                                EEPROM_LAYOUT_ENUM_AsamOdxFileID);
    DIAG_vDiagnoseIdRequestDone();
}


void ReadDataByIdentifier_F197_SystemnameOderMotortyp(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "DataByIdentifier_F197_SystemnameOderMotortyp received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_SysNameEngineType_LEN,
                                                EEPROM_LAYOUT_ENUM_SysNameEngineType);
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_F188_ApplikationSoftwareDatum(DescMsg resData)
{
    VERSION_vGetBuildDate(&resData[0], &resData[1], &resData[2]);
    DEBUG_VALUE4(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F188_ApplikationSoftwareDatum: %d.%d.%d %c",
                    resData[2],
                    resData[1],
                    resData[0],
                    ' ');
    DIAG_vDiagnoseIdRequestDone();
}
void ReadDataByIdentifier_F17B_TesterdatumKodierungLesen(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "DataByIdentifier_F17B_TesterdatumKodierungLesen received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_VWCodingDate_LEN,
                                                EEPROM_LAYOUT_ENUM_VWCodingDate);
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_F19B_TesterdatumKalibrierungLesen(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F19B_TesterdatumKalibrierungLesen received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_VWCalibrationDate_LEN,
                                                EEPROM_LAYOUT_ENUM_VWCalibrationDate);
    DIAG_vDiagnoseIdRequestDone();
}


void ReadDataByIdentifier_F1A5_TesterkennungKodierungLesen(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "DataByIdentifier_F1A5_TesterkennungKodierungLesen received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_VWCodingRepairShopCodeOrSerialNumber_LEN,
                                                EEPROM_LAYOUT_ENUM_VWCodingRepairShopCodeOrSerialNumber);
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_F19A_TesterkennungKalibrierungLesen(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F19A_TesterkennungKalibrierungLesen received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_VWCalibrationRepairShopCodeOrSerialNumber_LEN,
                                                EEPROM_LAYOUT_ENUM_VWCalibrationRepairShopCodeOrSerialNumber);
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_F1DF_SGProgrammierStatus(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "DataByIdentifier_F1DF_SGProgrammierStatus received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_ECUProgramInfo_LEN,
                                                EEPROM_LAYOUT_ENUM_ECUProgramInfo);
    DIAG_vDiagnoseIdRequestDone();
}
void ReadDataByIdentifier_F181_StandardSoftwarePlattform(DescMsg resData)
{
    (void)memcpy(resData, MOD_DIAG_SDS_VERSION_VALUES, ID_F181_STANDARD_SOFTWARE_PLATTFORM);
    DIAG_vDiagnoseIdRequestDone();
}
void ReadDataByIdentifier_F190_Fahrgestellnummer(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F190_Fahrgestellnummer received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_Fahrgestellnummer_LEN,
                                                EEPROM_LAYOUT_ENUM_Fahrgestellnummer);
    DIAG_vDiagnoseIdRequestDone();
}
void ReadDataByIdentifier_F1AB_LogicalBlockSoftwareVersion(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F1AB_LogicalBlockSoftwareVersion received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
				                        PAG_DB_EE_ADDRESS_BootSWLogicalBlockVersion_LEN,
				                        EEPROM_LAYOUT_ENUM_BootSWLogicalBlockVersion);
    (void)memcpy((void *)&resData[4], (const void *)SoftwareVersion, 4);
    DIAG_vDiagnoseIdRequestDone();
}
void ReadDataByIdentifier_F186_ActiveDiagnosticSession(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "DataByIdentifier_F186_ActiveDiagnosticSession received");
    resData[0] = ApplDescGetActiveDiagnosticSession();
    DIAG_vDiagnoseIdRequestDone();
}
void ReadDataByIdentifier_F1AE_NumberOfLogins(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "ReadDataByIdentifier_F1AE_NumberOfLogins received");
    resData[0] = NUMBER_OF_LOGIN_METHODS_IMPLEMETED;
    DIAG_vDiagnoseIdRequestDone();
}

void ReadDataByIdentifier_0501_BluetoothFriendlyName(DescMsg resData)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "DataByIdentifier_0501_BluetoothFriendlyName received");
    (void)EEPROM_enGetByteSequenceFromRamMirror(resData,
                                                PAG_DB_EE_ADDRESS_UniversalPreparationForMobileTelephone_LEN,
                                                EEPROM_LAYOUT_ENUM_UniversalPreparationForMobileTelephone);
    DIAG_vDiagnoseIdRequestDone();
}

void DIAG_vDiagnoseIdRequestDone(void)
{
    gDiagnoseContext.DiagnoseRequestState = DIAG_REQ_NEXT_DID_STATE;
    (void)APP_COMMON_UTILS_stSetOsekRelAlarm(CTA_HOST_HANDLE_DIAG_REQ, MSEC(5), 0);
}


void DIAG_vDiagnoseIdPending(void)
{
    gDiagMsgContext.counter += 1;
    gDiagnoseContext.DiagnoseRequestState = DIAG_REQ_SEARCHING_DID_STATE;
    (void)APP_COMMON_UTILS_stSetOsekRelAlarm(CTA_HOST_HANDLE_DIAG_REQ, MSEC(5), 0);
}

/* End Of File APP_CAN_C1.c */
