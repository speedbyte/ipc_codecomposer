/******************************************************************************/
/*****************  Copyright (c) 2011 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     Diag_Service_22.h
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
#ifndef _DIAG_SERVICE_2E
#define _DIAG_SERVICE_2E

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
/* include the export configuration file */

/*----------------------------------------------------------------------------*/
/* Public Manifest Constant Definitions                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Types                                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global Variables Declarations (avoid as much as possible!)                 */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global const Declarations                                                  */
/*----------------------------------------------------------------------------*/
/* return values of the function SDSext_WriteUserAndIOData() */
/* */

typedef struct
{
  vuint16 DataId;                       /* data id */
  vuint16 LenMin;                       /* length of minimum data */
  vuint16 LenMax;                       /* length of maximum data */
  void (* Address)(DescMsg , vuint8);   /* data address or index in data table */
} t_WriteDataIdCfgItem;
/*----------------------------------------------------------------------------*/
/* Public Methods                                                             */
/*----------------------------------------------------------------------------*/
void WriteDataByIdentifier_0500_ParameterStrommessung(DescMsg reqData, vuint8 length);
void WriteDataByIdentifier_0501_BluetoothFriendlyName(DescMsg reqData, vuint8 length);
void WriteDataByIdentifier_0505_ProductionFlag(DescMsg reqData, vuint8 length);
void WriteDataByIdentifier_0506_TestBytes(DescMsg reqData, vuint8 length);
void WriteDataByIdentifier_0600_Kodierwert(DescMsg reqData, vuint8 length);
void WriteDataByIdentifier_F190_Fahrgestellnummer(DescMsg reqData, vuint8 length);
void WriteDataByIdentifier_F198_RepairShopCodeOrTesterSerialNumber(DescMsg reqData, vuint8 length);
void WriteDataByIdentifier_F199_ProgrammingDate(DescMsg reqData, vuint8 length);
void WriteDataByIdentifier_F1A0_VWDataSetNumberOrECUDataContainerNumber(DescMsg reqData, vuint8 length);
void WriteDataByIdentifier_F1A1_VWDataSetVersionNumber(DescMsg reqData, vuint8 length);
void WriteDataByIdentifier_F1A4_VehicleEquipmentCodeAndPRNumberCombination(DescMsg reqData, vuint8 length);
void WriteDataByIdentifier_F1F0_AktivierungNetzwerkpowermgmt(DescMsg reqData, vuint8 length);
void WriteDataByIdentifier_04FE_ProductionMode(DescMsg reqData, vuint8 length);
void WriteDataByIdentifier_04FC_ProductionModeDeactivate(DescMsg reqData, vuint8 length);
/*----------------------------------------------------------------------------*/
/* Public Code Macros                                                         */
/*----------------------------------------------------------------------------*/


extern const t_WriteDataIdCfgItem cs_WriteDataIdItem[14];
/*----------------------------------------------------------------------------*/

extern BooleanType DIAG_2E_bWriteDiagnosisLengthCheck(Uint16Type u16ReceivedLen, const t_WriteDataIdCfgItem* DataIdItem);

#endif /* _DIAG_SERVICE_2E */

/* End Of File Diag_Service_2E.h */


