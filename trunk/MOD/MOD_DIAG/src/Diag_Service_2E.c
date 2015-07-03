/******************************************************************************/
/*****************  Copyright (c) 2011 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     Diag_Service_2E.c
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

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*---------------------------------------------------------------------------- */

#include "Common.h"
#include "Version.h"
#include "desc.h"
#include "OSEK_HostTask_H1.h"
#include "Diag_Service_2E.h"
#include "APP_COMMON_Utils.h"
#include "APP_DESC.h"
#include "Diag_ReqHandling.h"
#include "EEPROM.h"
#include "EEPROM_LAYOUT_CFG.h"
#include "TRACE.h"
#include "Diag_Service_2E.id"
/*----------------------------------------------------------------------------*/
/* pragma Directives                                                          */
/*----------------------------------------------------------------------------*/

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
void DIAG_vWriteProductionFlag_Cb(CommonResponseCodeType rC);
void DIAG_vWriteTestBytes_Cb(CommonResponseCodeType rC);

/*----------------------------------------------------------------------------*/
/* File local Code Macros                                                     */
/*----------------------------------------------------------------------------*/
/**
\brief	description of the macros
*/

extern DiagnoseContextType gDiagnoseContext;
/*----------------------------------------------------------------------------*/
/* File local Variables                                                       */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* File local const Definitions                                               */
/*----------------------------------------------------------------------------*/
/**
\brief	description of the private constant
*/

/************** A T T E N T I O N *****************************
   because of speed optimization binary search algorithm is used
   which requires a sorted (ascending !!!) data identifier table */

const t_WriteDataIdCfgItem cs_WriteDataIdItem[] =
{/*  DID        Min-Length     Max-Length      Function */
{   0x04FC,         3,             3,          WriteDataByIdentifier_04FC_ProductionModeDeactivate},
{   0x04FE,         3,             3,          WriteDataByIdentifier_04FE_ProductionMode},
{   0x0500,         8,            12,          WriteDataByIdentifier_0500_ParameterStrommessung},
{   0x0501,         1,            31,          WriteDataByIdentifier_0501_BluetoothFriendlyName},
{   0x0505,         1,             1,          WriteDataByIdentifier_0505_ProductionFlag},
{   0x0506,         8,             8,          WriteDataByIdentifier_0506_TestBytes},
{   0x0600,        19,            19,          WriteDataByIdentifier_0600_Kodierwert},
{   0xF190,         7,            17,          WriteDataByIdentifier_F190_Fahrgestellnummer},
{   0xF198,         6,             6,          WriteDataByIdentifier_F198_RepairShopCodeOrTesterSerialNumber},
{   0xF199,         3,             3,          WriteDataByIdentifier_F199_ProgrammingDate},
{   0xF1A0,         1,            11,          WriteDataByIdentifier_F1A0_VWDataSetNumberOrECUDataContainerNumber},
{   0xF1A1,         4,             4,          WriteDataByIdentifier_F1A1_VWDataSetVersionNumber},
{   0xF1A4,         2,            12,          WriteDataByIdentifier_F1A4_VehicleEquipmentCodeAndPRNumberCombination},
{   0xF1F0,         1,             1,          WriteDataByIdentifier_F1F0_AktivierungNetzwerkpowermgmt}
};
/*----------------------------------------------------------------------------*/
/* Private Address Calculations                                               */
/*----------------------------------------------------------------------------*/

void WriteDataByIdentifier_04FC_ProductionModeDeactivate(DescMsg reqData, vuint8 length)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "WriteDataByIdentifier_04FC_ProductionModeDeactivate received");
    if ((gDiagnoseContext.securityState & MASK_SEC_ACTIVE) != MASK_SEC_ACTIVE)
    {
        DescSetNegResponse(kDescNrcAccessDenied);
    }
    else
    {
        if(BT_FALSE == gDiagnoseContext.bFingerprintValueIsReceived)
        {
            DescSetNegResponse(kDescNrcRequestSequenceError);
        }
        else
        {
            (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8FingerprintValue, EEPROM_LAYOUT_ENUM_VWCalibrationRepairShopCodeOrSerialNumber );
            if(BT_TRUE == gDiagnoseContext.bProgrammingDateIsReceived)
            {
                (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8ProgrammingDate, EEPROM_LAYOUT_ENUM_VWCalibrationDate );
            }
            (void)EEPROM_sfRamWriteOnly(reqData, EEPROM_LAYOUT_ENUM_ProductionMode);
        }
    }
    DescProcessingDone();
}

void WriteDataByIdentifier_04FE_ProductionMode(DescMsg reqData, vuint8 length)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "WriteDataByIdentifier_04FE_ProductionMode received");
    if ((gDiagnoseContext.securityState & MASK_SEC_ACTIVE) != MASK_SEC_ACTIVE)
    {
        DescSetNegResponse(kDescNrcAccessDenied);
    }
    else
    {
        if(BT_FALSE == gDiagnoseContext.bFingerprintValueIsReceived)
        {
            DescSetNegResponse(kDescNrcRequestSequenceError);
        }
        else
        {
            (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8FingerprintValue, EEPROM_LAYOUT_ENUM_VWCalibrationRepairShopCodeOrSerialNumber );
            if(BT_TRUE == gDiagnoseContext.bProgrammingDateIsReceived)
            {
                (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8ProgrammingDate, EEPROM_LAYOUT_ENUM_VWCalibrationDate );
            }
            (void)EEPROM_sfRamWriteOnly(reqData, EEPROM_LAYOUT_ENUM_ProductionMode);
        }
    }
    DescProcessingDone();
}


void WriteDataByIdentifier_0505_ProductionFlag(DescMsg reqData, vuint8 length)
{
	EEDeviceControlBlockType    *pEEDcb = (EEDeviceControlBlockType *)getEEHostControl();

    if ((gDiagnoseContext.securityState & MASK_SEC_ACTIVE) != MASK_SEC_ACTIVE)
    {
        DescSetNegResponse(kDescNrcAccessDenied);
    }
    else
    {
        if(BT_FALSE == gDiagnoseContext.bFingerprintValueIsReceived)
        {
            DescSetNegResponse(kDescNrcRequestSequenceError);
        }
        else
        {
            (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8FingerprintValue, EEPROM_LAYOUT_ENUM_VWCalibrationRepairShopCodeOrSerialNumber );
            if(BT_TRUE == gDiagnoseContext.bProgrammingDateIsReceived)
            {
                (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8ProgrammingDate, EEPROM_LAYOUT_ENUM_VWCalibrationDate );
            }
	        if (COMMON_RSP_OK == EEPROM_LAYOUT_rcWrite(pEEDcb,
                                           PAG_DB_EE_ADDRESS_ProductionFlag,
                                           (Uint8Type *) reqData,
                                           PAG_DB_EE_ADDRESS_ProductionFlag_LEN,
                                           DIAG_vWriteProductionFlag_Cb))
	        {
                // wait of EEPROM callback to return finished
                //DescProcessingDone();
	        }
	        else
	        {
                // sending busy on the CAN bus
	        }
        }
    }
}

void WriteDataByIdentifier_0506_TestBytes(DescMsg reqData, vuint8 length)
{
	EEDeviceControlBlockType    *pEEDcb = (EEDeviceControlBlockType *)getEEHostControl();
    if ((gDiagnoseContext.securityState & MASK_SEC_ACTIVE) != MASK_SEC_ACTIVE)
    {
        DescSetNegResponse(kDescNrcAccessDenied);
    }
    else
    {
        if(BT_FALSE == gDiagnoseContext.bFingerprintValueIsReceived)
        {
            DescSetNegResponse(kDescNrcRequestSequenceError);
        }
        else
        {
            (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8FingerprintValue, EEPROM_LAYOUT_ENUM_VWCalibrationRepairShopCodeOrSerialNumber );
            if(BT_TRUE == gDiagnoseContext.bProgrammingDateIsReceived)
            {
                (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8ProgrammingDate, EEPROM_LAYOUT_ENUM_VWCalibrationDate );
            }
	        if (COMMON_RSP_OK == EEPROM_LAYOUT_rcWrite(pEEDcb,
                                           PAG_DB_EE_ADDRESS_TestBytes,
                                           (Uint8Type *) reqData,
                                           PAG_DB_EE_ADDRESS_TestBytes_LEN,
                                           DIAG_vWriteTestBytes_Cb))
	        {
                // wait of EEPROM callback to return finished
                //DescProcessingDone();
	        }
	        else
	        {
                // sending busy on the CAN bus
	        }
        }
    }
}

void WriteDataByIdentifier_0500_ParameterStrommessung(DescMsg reqData, vuint8 length)
{
    Uint8Type buffer[12];
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "WriteDataByIdentifier_0500_ParameterStrommessung received");
    (void)memset(buffer, 0, sizeof(buffer));
    if ((gDiagnoseContext.securityState & MASK_SEC_ACTIVE) != MASK_SEC_ACTIVE)
    {
        DescSetNegResponse(kDescNrcAccessDenied);
    }
    else
    {
        if(BT_FALSE == gDiagnoseContext.bFingerprintValueIsReceived)
        {
            DescSetNegResponse(kDescNrcRequestSequenceError);
        }
        else
        {
            (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8FingerprintValue, EEPROM_LAYOUT_ENUM_VWCalibrationRepairShopCodeOrSerialNumber );
            (void)memcpy(buffer, reqData, length);
            (void)EEPROM_sfRamWriteOnly(buffer, EEPROM_LAYOUT_ENUM_ParameterStrommessung);
        }
    }
    DescProcessingDone();
}

void WriteDataByIdentifier_0501_BluetoothFriendlyName(DescMsg reqData, vuint8 length)
{
    Uint8Type buffer[31];
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "WriteDataByIdentifier_0501_BluetoothFriendlyName received");
    if ((gDiagnoseContext.securityState & MASK_SEC_ACTIVE) != MASK_SEC_ACTIVE)
    {
        DescSetNegResponse(kDescNrcAccessDenied);
    }
    else
    {
        if(BT_FALSE == gDiagnoseContext.bFingerprintValueIsReceived)
        {
            DescSetNegResponse(kDescNrcRequestSequenceError);
        }
        else
        {
            (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8FingerprintValue, EEPROM_LAYOUT_ENUM_VWCalibrationRepairShopCodeOrSerialNumber );
            if(BT_TRUE == gDiagnoseContext.bProgrammingDateIsReceived)
            {
                (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8ProgrammingDate, EEPROM_LAYOUT_ENUM_VWCalibrationDate );
            }
            if(length == 31)
            {
                (void)EEPROM_sfRamWriteOnly((Uint8Type *)&reqData, EEPROM_LAYOUT_ENUM_UniversalPreparationForMobileTelephone);
            }
            else
            {
                (void)memset(buffer, 0, sizeof(buffer));
                (void)memcpy(buffer, reqData, length);
                (void)EEPROM_sfRamWriteOnly(buffer, EEPROM_LAYOUT_ENUM_UniversalPreparationForMobileTelephone);
            }
        }
    }
    DescProcessingDone();
}

void WriteDataByIdentifier_0600_Kodierwert(DescMsg reqData, vuint8 length)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "WriteDataByIdentifier_0600_Kodierwert received");
    if ((gDiagnoseContext.securityState & MASK_SEC_ACTIVE) != MASK_SEC_ACTIVE)
    {
        DescSetNegResponse(kDescNrcAccessDenied);
    }
    else
    {
        if(BT_FALSE == gDiagnoseContext.bFingerprintValueIsReceived)
        {
            DescSetNegResponse(kDescNrcRequestSequenceError);
        }
        else
        {
            if (BT_FALSE == DIAG_bCodingParameterCheck((CodingBitMaskType *)reqData))
            {
                DEBUG_TEXT(DIAG_SWI_ERR, MOD_DIAG, "WriteDataByIdentifier_0600_Kodierwert: invalid coding parameter");
                DescSetNegResponse(kDescNrcInvalidFormat);
            }
            else
            {
                (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8FingerprintValue, EEPROM_LAYOUT_ENUM_VWCodingRepairShopCodeOrSerialNumber );
                if(BT_TRUE == gDiagnoseContext.bProgrammingDateIsReceived)
                {
                    (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8ProgrammingDate, EEPROM_LAYOUT_ENUM_VWCodingDate );
                }
                (void)EEPROM_sfRamWriteOnly(reqData, EEPROM_LAYOUT_ENUM_VWCodingValue);
                DIAG_vWriteCodingParameterInPersistentData((CodingBitMaskType *)reqData);
                SetEvent(OsHostTask_10ms, evHostTaskSendingCodingData);
            }
        }
    }
    DescProcessingDone();
}
void WriteDataByIdentifier_F190_Fahrgestellnummer(DescMsg reqData, vuint8 length)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "WriteDataByIdentifier_F190_Fahrgestellnummer received");
    if ((gDiagnoseContext.securityState & MASK_SEC_ACTIVE) != MASK_SEC_ACTIVE)
    {
        DescSetNegResponse(kDescNrcAccessDenied);
    }
    else
    {
        if(BT_FALSE == gDiagnoseContext.bFingerprintValueIsReceived)
        {
            DescSetNegResponse(kDescNrcRequestSequenceError);
        }
        else
        {
            (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8FingerprintValue, EEPROM_LAYOUT_ENUM_VWCodingRepairShopCodeOrSerialNumber );
            if(BT_TRUE == gDiagnoseContext.bProgrammingDateIsReceived)
            {
                (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8ProgrammingDate, EEPROM_LAYOUT_ENUM_VWCodingDate );
            }
            (void)EEPROM_sfRamWriteOnly(reqData, EEPROM_LAYOUT_ENUM_Fahrgestellnummer);
        }
    }
    DescProcessingDone();
}
void WriteDataByIdentifier_F198_RepairShopCodeOrTesterSerialNumber(DescMsg reqData, vuint8 length)
{
    (void)memcpy((void*)&gDiagnoseContext.au8FingerprintValue, (const void *)reqData, sizeof(gDiagnoseContext.au8FingerprintValue));
    DEBUG_VALUE4(DIAG_SWI_TRC, MOD_DIAG, "WriteDataByIdentifier_F198_RepairShopCodeOrTesterSerialNumber 0x%x 0x%x 0x%x 0x%x",
                    gDiagnoseContext.au8FingerprintValue[0],
                    gDiagnoseContext.au8FingerprintValue[1],
                    gDiagnoseContext.au8FingerprintValue[2],
                    gDiagnoseContext.au8FingerprintValue[3]);
    gDiagnoseContext.bFingerprintValueIsReceived = BT_TRUE;
    DescProcessingDone();
}
void WriteDataByIdentifier_F199_ProgrammingDate(DescMsg reqData, vuint8 length)
{
    (void)memcpy((void*)&gDiagnoseContext.au8ProgrammingDate, (const void *)reqData, sizeof(gDiagnoseContext.au8ProgrammingDate));
    DEBUG_VALUE4(DIAG_SWI_TRC, MOD_DIAG, "WriteDataByIdentifier_F199_ProgrammingDate 0x%x 0x%x 0x%x %c",
                    gDiagnoseContext.au8ProgrammingDate[0],
                    gDiagnoseContext.au8ProgrammingDate[1],
                    gDiagnoseContext.au8ProgrammingDate[2],
                    ' ');
    gDiagnoseContext.bProgrammingDateIsReceived = BT_TRUE;
    DescProcessingDone();
}
void WriteDataByIdentifier_F1A0_VWDataSetNumberOrECUDataContainerNumber(DescMsg reqData, vuint8 length)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "WriteDataByIdentifier_F1A0_VWDataSetNumberOrECUDataContainerNumber received");
    if ((gDiagnoseContext.securityState & MASK_SEC_ACTIVE) != MASK_SEC_ACTIVE)
    {
        DescSetNegResponse(kDescNrcAccessDenied);
    }
    else
    {
        if(BT_FALSE == gDiagnoseContext.bFingerprintValueIsReceived)
        {
            DescSetNegResponse(kDescNrcRequestSequenceError);
        }
        else
        {
            (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8FingerprintValue, EEPROM_LAYOUT_ENUM_VWCodingRepairShopCodeOrSerialNumber );
            if(BT_TRUE == gDiagnoseContext.bProgrammingDateIsReceived)
            {
                (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8ProgrammingDate, EEPROM_LAYOUT_ENUM_VWCodingDate );
            }
        }
    }
    DescProcessingDone();
}
void WriteDataByIdentifier_F1A1_VWDataSetVersionNumber(DescMsg reqData, vuint8 length)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "WriteDataByIdentifier_F1A1_VWDataSetVersionNumber received");
    if ((gDiagnoseContext.securityState & MASK_SEC_ACTIVE) != MASK_SEC_ACTIVE)
    {
        DescSetNegResponse(kDescNrcAccessDenied);
    }
    else
    {
        if(BT_FALSE == gDiagnoseContext.bFingerprintValueIsReceived)
        {
            DescSetNegResponse(kDescNrcRequestSequenceError);
        }
        else
        {
            (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8FingerprintValue, EEPROM_LAYOUT_ENUM_VWCodingRepairShopCodeOrSerialNumber );
            if(BT_TRUE == gDiagnoseContext.bProgrammingDateIsReceived)
            {
                (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8ProgrammingDate, EEPROM_LAYOUT_ENUM_VWCodingDate );
            }
        }
    }
    DescProcessingDone();
}
void WriteDataByIdentifier_F1A4_VehicleEquipmentCodeAndPRNumberCombination(DescMsg reqData, vuint8 length)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "WriteDataByIdentifier_F1A4_VehicleEquipmentCodeAndPRNumberCombination received");
    if ((gDiagnoseContext.securityState & MASK_SEC_ACTIVE) != MASK_SEC_ACTIVE)
    {
        DescSetNegResponse(kDescNrcAccessDenied);
    }
    else
    {
        if(BT_FALSE == gDiagnoseContext.bFingerprintValueIsReceived)
        {
            DescSetNegResponse(kDescNrcRequestSequenceError);
        }
        else
        {
            (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8FingerprintValue, EEPROM_LAYOUT_ENUM_VWCodingRepairShopCodeOrSerialNumber );
            if(BT_TRUE == gDiagnoseContext.bProgrammingDateIsReceived)
            {
                (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8ProgrammingDate, EEPROM_LAYOUT_ENUM_VWCodingDate );
            }
        }
    }
    DescProcessingDone();
}
void WriteDataByIdentifier_F1F0_AktivierungNetzwerkpowermgmt(DescMsg reqData, vuint8 length)
{
    DEBUG_TEXT(DIAG_SWI_TRC, MOD_DIAG, "WriteDataByIdentifier_F1F0_AktivierungNetzwerkpowermgmt received");
    if ((gDiagnoseContext.securityState & MASK_SEC_ACTIVE) != MASK_SEC_ACTIVE)
    {
        DescSetNegResponse(kDescNrcAccessDenied);
    }
    else
    {
        if(BT_FALSE == gDiagnoseContext.bFingerprintValueIsReceived)
        {
            DescSetNegResponse(kDescNrcRequestSequenceError);
        }
        else
        {
            (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8FingerprintValue, EEPROM_LAYOUT_ENUM_VWCodingRepairShopCodeOrSerialNumber );
            if(BT_TRUE == gDiagnoseContext.bProgrammingDateIsReceived)
            {
                (void)EEPROM_sfRamWriteOnly(gDiagnoseContext.au8ProgrammingDate, EEPROM_LAYOUT_ENUM_VWCodingDate );
            }
        }
    }
    DescProcessingDone();
}



void DIAG_vWriteProductionFlag_Cb(CommonResponseCodeType rC)
{
    DEBUG_VALUE1(DIAG_SWI_TRC, MOD_DIAG, "DIAG_vWriteProductionFlag_Cb finished rsp = %d", rC);
    if( COMMON_RSP_OK == rC )
    {
        DescProcessingDone();
    }
    else
    {
        // write again
    }
}

void DIAG_vWriteTestBytes_Cb(CommonResponseCodeType rC)
{
    DEBUG_VALUE1(DIAG_SWI_TRC, MOD_DIAG, "DIAG_vWriteTestBytes_Cb finished rsp = %d", rC);
    if( COMMON_RSP_OK == rC )
    {
        DescProcessingDone();
    }
    else
    {
        // write again
    }
}


/*----------------------------------------------------------------------------*/
/* Function    : _SDS_UDS_bWriteDiagnosisLengthCheck                                                 */
/**
 \brief      Write diagnosis length check

 \brief      Description:
 this function check the length send by the VAS tester

 \param      u16ReceivedLen
 length from VAS tester

 \param      DataIdItem
 ID struct

 \return     BT_TRUE: length is okay
 BT_FALSE: length is not okay
 */
/*----------------------------------------------------------------------------*/
BooleanType DIAG_2E_bWriteDiagnosisLengthCheck(Uint16Type u16ReceivedLen, const t_WriteDataIdCfgItem* DataIdItem)
{
	BooleanType bRetVal = BT_TRUE;

	if ((u16ReceivedLen >= DataIdItem->LenMin) && (u16ReceivedLen <= DataIdItem->LenMax))
	{
		bRetVal = BT_TRUE;
		DEBUG_VALUE2(DIAG_SWI_TRC, MOD_DIAG,"2E WriteServ.: LengthCheckforID=%04X with length %d OK",DataIdItem->DataId,u16ReceivedLen);
		DEBUG_VALUE2(DIAG_SWI_DBG, MOD_DIAG,"min len=%d,max len=%d",DataIdItem->LenMin,DataIdItem->LenMax);
	}
	else
	{
		bRetVal = BT_FALSE;
		DEBUG_VALUE2(DIAG_SWI_TRC, MOD_DIAG,"2E-WriteServ.: LengthCheckforID=%04X with length %d not okay",DataIdItem->DataId,u16ReceivedLen);
		DEBUG_VALUE2(DIAG_SWI_DBG, MOD_DIAG,"min len=%d,max len=%d",DataIdItem->LenMin,DataIdItem->LenMax);
	}
	return (bRetVal);
}

/* End Of File APP_CAN_C1.c */
