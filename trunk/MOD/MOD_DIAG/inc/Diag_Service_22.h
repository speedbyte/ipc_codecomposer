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
#ifndef _DIAG_SERVICE_22
#define _DIAG_SERVICE_22

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
  vuint16 DataId;                   /* data id */
  vuint16 Len;                      /* length of data */
  void (* Address)(DescMsg );       /* data address or index in data table */
} t_ReadDataIdCfgItem;

/*----------------------------------------------------------------------------*/
/* Public Methods                                                             */
/*----------------------------------------------------------------------------*/
void ReadDataByIdentifier_0103_SecurityAccessCounter(DescMsg resData);
void ReadDataByIdentifier_F187_SparePartNumber(DescMsg resData);
void ReadDataByIdentifier_F17C_FazitIdentificationString(DescMsg resData);
void ReadDataByIdentifier_F189_SoftwareVersionNumber(DescMsg resData);
void ReadDataByIdentifier_F1A3_HardwareVersionNumber(DescMsg resData);
void ReadDataByIdentifier_F18C_ECUSerialNumber(DescMsg resData);
void ReadDataByIdentifier_F1A2_ODXDiagnosticVersionIdentifier(DescMsg resData);
void ReadDataByIdentifier_F19E_ODXDiagnosticECUIdentifier(DescMsg resData);
void ReadDataByIdentifier_F197_SystemnameOderMotortyp(DescMsg resData);
void ReadDataByIdentifier_F188_ApplikationSoftwareDatum(DescMsg resData);
void ReadDataByIdentifier_F17B_TesterdatumKodierungLesen(DescMsg resData);
void ReadDataByIdentifier_F1A5_TesterkennungKodierungLesen(DescMsg resData);
void ReadDataByIdentifier_F1DF_SGProgrammierStatus(DescMsg resData);
void ReadDataByIdentifier_F181_StandardSoftwarePlattform(DescMsg resData);
void ReadDataByIdentifier_F190_Fahrgestellnummer(DescMsg resData);
void ReadDataByIdentifier_F1AB_LogicalBlockSoftwareVersion(DescMsg resData);
void ReadDataByIdentifier_F186_ActiveDiagnosticSession(DescMsg resData);
void ReadDataByIdentifier_0501_BluetoothFriendlyName(DescMsg resData);
void ReadDataByIdentifier_0505_ProductionFlag(DescMsg resData);
void ReadDataByIdentifier_0506_TestBytes(DescMsg resData);
void ReadDataByIdentifier_F1AE_NumberOfLogins(DescMsg resData);
void ReadDataByIdentifier_F198_RepairShopCodeOrTesterSerialNumber(DescMsg resData);
void ReadDataByIdentifier_F19A_TesterkennungKalibrierungLesen(DescMsg resData);
void ReadDataByIdentifier_F19B_TesterdatumKalibrierungLesen(DescMsg resData);
void ReadDataByIdentifier_F179_ECUSupplierNumber(DescMsg resData);
void ReadDataByIdentifier_F17D_ECUProductionTestSystemNumber(DescMsg resData);
void ReadDataByIdentifier_F17E_ECUProductionChangeNumber(DescMsg resData);
void ReadDataByIdentifier_F18B_ECUManufacturingDate(DescMsg resData);
void ReadDataByIdentifier_0600_Kodierwert(DescMsg resData);
void ReadDataByIdentifier_F101_Zeitstempel(DescMsg resData);
void ReadDataByIdentifier_F106_Betriebsdauer(DescMsg resData);
void ReadDataByIdentifier_F105_Temperatur(DescMsg resData);
void ReadDataByIdentifier_F104_Spannung(DescMsg resData);
void ReadDataByIdentifier_F103_Pinzustaende(DescMsg resData);
void ReadDataByIdentifier_F102_Kilometerstand(DescMsg resData);
void ReadDataByIdentifier_F1AA_VWWorkshopSystemName(DescMsg resData);
void ReadDataByIdentifier_F1A4_VehEquipCodePRNbr(DescMsg resData);
void ReadDataByIdentifier_04FE_ProductionMode(DescMsg resData);
void ReadDataByIdentifier_04FC_ProductionModeDeactivate(DescMsg resData);
void ReadDataByIdentifier_0500_ParameterStrommessung(DescMsg resData);
void ReadDataByIdentifier_0286_SpannungKlemme30(DescMsg resData);
void ReadDataByIdentifier_0407_LogicalSoftwareBlockCounterOfProgrammingAttempts(DescMsg resData);
void ReadDataByIdentifier_040F_LogicalBlockLockLimitValue(DescMsg resData);
void ReadDataByIdentifier_F15B_LogicalBlockProgrammingFingerprint(DescMsg resData);
void ReadDataByIdentifier_040A_Verlernzaehler(DescMsg resData);
void ReadDataByIdentifier_0100_StatusInputOutputControl(DescMsg resData);
void ReadDataByIdentifier_0102_StatusRoutinen(DescMsg resData);
void DIAG_vDiagnoseIdRequestDone(void);
void DIAG_vDiagnoseIdPending(void);
/*----------------------------------------------------------------------------*/
/* Public Code Macros                                                         */
/*----------------------------------------------------------------------------*/


extern const t_ReadDataIdCfgItem cs_ReadDataIdItem[48];
/*----------------------------------------------------------------------------*/


#endif /* _DIAG_SERVICE_22 */

/* End Of File Diag_Service_22.h */


