/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/
/**
 * \file 	DEM_DTC_CB_C1.c
 * \brief	this module include the polynom to create a CRC checksum. Detailed description found below.
 * \brief	Detailed description of the file.
*/
/*-----------------------------------------------------------------------------
* $Date: 2009-03-29 23:01:17 +0200 (So, 29 Mrz 2009) $
* $Rev: 5655 $
* $Author: zyla $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_CRC/trunk/src/Crc_C1.c $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/


/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/
//#include "Platform_Types.h"
//#include "Compiler.h"
//#include "Std_Types.h"
//#include "Det.h"
//#include "NvM.h"
//#include "Dem.h"
//#include "Dem_Lcfg.h"
#include "OSEK_HostTask_H1.h"
/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
#include "Common.h"
#include "EEPROM_LAYOUT.h"
#include "APP_CAN_IL_DIAGNOSIS.h"

#include "DEM_DTC_CB_C1.id"
#include "TRACE.h"


/*----------------------------------------------------------------------------*/
/* pragma Directives                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global Variables Definitions (avoid as much as possible!)                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Manifest Constant Definitions                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Types                                                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Prototypes of file local Methods                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* File local Code Macros                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* File local Variables                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* File local const Definitions                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Address Calculations                                               */
/*----------------------------------------------------------------------------*/

#if 0
void Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId)
{
}

void NvM_SetRamBlockStatus(NvM_BlockIdType BlockId, boolean BlockChanged)
{
    static boolean ProdFlagReadDone = FALSE;
    static vuint8 u8EEPROM_ProductionFlag = 0x00;

    CommonResponseCodeType retVal = COMMON_RSP_OK;
    EEDeviceControlBlockType    *pEEHost = (EEDeviceControlBlockType *)getEEHostControl();

    if (TRUE == BlockChanged)
    {
        /*check Production Mode*/
        // 2010-12-22,YSR: Remove UnNeccessary Cyclic reads of the ProductionFlag:
        if(ProdFlagReadDone == FALSE)
        {
          DEBUG_TEXT(APP_DTC_SWI_ERR, MOD_APP_DTC, "Read ProdMode flag once per a powerup cycle");
          (void)EEPROM_sfRead(pEEHost, FODB_EE_ADDDRESS_ProductionFlag, (Uint8Type *)&u8EEPROM_ProductionFlag, FODB_EE_ADDDRESS_ProductionFlag_LEN);
          ProdFlagReadDone = TRUE;
        }

        if( 0x80 != (u8EEPROM_ProductionFlag & 0x80) )
        {// Production Flag not set => allow write EEP via direct access ...
            retVal = EEPROM_rcWrite( pEEHost, FODB_EE_ADDDRESS_DEM_DATA, (Uint8Type *)&Dem_NvData,
                                    sizeof(Dem_NonVolatileDataType), (void (*)(CommonResponseCodeType))NULL );
            // TODO: check return value and implement callback
        }
    }
}

void NvM_GetErrorStatus(NvM_BlockIdType BlockId, uint8* RequestResultPtr)
{
    /* TODO: check if asynchron readout finished */
    *RequestResultPtr = NVM_REQ_OK;
}

FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_0xdd00(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer)
{
    APP_CAN_IL_DIAGNOSIS_Get_Global_Real_Time( (uint8*)DemDataValueByDataIDBuffer );
    return E_OK;
}

FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_0xdd01(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer)
{
    APP_CAN_IL_DIAGNOSIS_Get_DD01_Total_Distance( (uint8*)DemDataValueByDataIDBuffer );
    return E_OK;
}

FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_0xdd02(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer)
{
    APP_CAN_IL_DIAGNOSIS_Get_DD02_Main_ECU_Voltage_Supply( (uint8*)DemDataValueByDataIDBuffer );
    return E_OK;
}

FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_0xdd04(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer)
{
    APP_CAN_IL_DIAGNOSIS_Get_DD04_In_Car_temperature( (uint8*)DemDataValueByDataIDBuffer );
    return E_OK;
}

FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_0xdd05(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer)
{
    APP_CAN_IL_DIAGNOSIS_Get_DD05_Outside_temperature( (uint8*)DemDataValueByDataIDBuffer );
    return E_OK;
}

FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_0xdd06(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer)
{
    APP_CAN_IL_DIAGNOSIS_Get_DD06_Power_Mode( (uint8*)DemDataValueByDataIDBuffer );
    return E_OK;
}
#endif

