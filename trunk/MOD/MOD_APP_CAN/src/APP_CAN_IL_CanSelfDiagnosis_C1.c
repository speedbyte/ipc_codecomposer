/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     APP_CAN_IL_ISO_TP_C1.c
*-----------------------------------------------------------------------------
* Module Name:    APP_CAN_TP
*-----------------------------------------------------------------------------
* Description:    Handle CAN TP related doings for the applications
*-----------------------------------------------------------------------------
* $Date: 2010-09-09 16:44:51 +0200 (Do, 09 Sep 2010) $
* $Rev: 14956 $
* $Author: braun $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_APP_CAN/trunk/src/APP_CAN_IL_ISO_TP_C1.c $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/
#include <osek.h>           // vector
#include <osekext.h>        // vector

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*---------------------------------------------------------------------------- */
#include "ccl_inc.h"
#include "APP_CAN_IL.h"
#include "deh.h"
#include "DEH_DTC_CFG.h"
#include "APP_CAN_IL_CanSelfDiagnosis_C1.id"
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
/**
\brief	TP TX send buffer
*/

extern AppCanContextType gAppCanContext;
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
/*----------------------------------------------------------------------------*/
/* File local const Definitions                                               */
/*----------------------------------------------------------------------------*/
/**
\brief	description of the private constant
*/

/*----------------------------------------------------------------------------*/
/* Private Address Calculations                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

/* Function :   APP_CAN_IL_ISO_TP_Init                                 */
/**
  \brief        Init APP TP variables

  \return       void

 */
/*----------------------------------------------------------------------------*/
void APP_CAN_IL_CheckSignalSelfDiagnosisAltBitReception(void)
{
	CanRequests_CSHDL_MsgType canRequestCshdlMsg;
    if (IlGetKombi_02_altIndication())
    {
        if (TRUE == IlGetRxKombi_02_alt())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagMsgError.kombi.Bits.altKombi_02_alt = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagMsgError.kombi.Bits.altKombi_02_alt = 0;
            if (0 == gAppCanContext.canSelfDiagMsgError.kombi.kombiError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, FALSE);
            }
        }
        IlClrKombi_02_altIndication();
    }
    if (IlGetUhrzeit_01_altIndication())
    {
        if (TRUE == IlGetRxUhrzeit_01_alt())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagMsgError.kombi.Bits.altUhrzeit_01_alt = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagMsgError.kombi.Bits.altUhrzeit_01_alt = 0;
            if (0 == gAppCanContext.canSelfDiagMsgError.kombi.kombiError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, FALSE);
            }
        }
        IlClrUhrzeit_01_altIndication();
    }
    if (IlGetMotor_06_altIndication())
    {
        if (TRUE == IlGetRxMotor_06_alt())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagMsgError.motor.Bits.altMotor_06_alt = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12002_TIMEOUT_MOTORSTEUERUNG, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagMsgError.motor.Bits.altMotor_06_alt = 0;
            if(0 == gAppCanContext.canSelfDiagMsgError.motor.motorError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12002_TIMEOUT_MOTORSTEUERUNG, FALSE);
            }
        }
        IlClrMotor_06_altIndication();
    }
    if (IlGetF_LWI_01_MmiIndication())
    {
        if (TRUE == IlGetRxF_LWI_01_Mmi())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                (void)DEH_AdditionalReportEvent(DTC_C1200B_TIMEOUT_LWS, TRUE);
            }
        }
        else
        {
            (void)DEH_AdditionalReportEvent(DTC_C1200B_TIMEOUT_LWS, TRUE);
        }
        IlClrF_LWI_01_MmiIndication();
    }
    if (IlGetF_BCM2_02_MmiIndication())
    {
        if (TRUE == IlGetRxF_BCM2_02_Mmi())
        {
            canRequestCshdlMsg.CshdlID_Rq = LOCKING_GUELTIG_RQ;
            canRequestCshdlMsg.APP_CAN_UnionCanToCshdl.Locking_Status_Request.LOCK_gueltig = IlGetRxF_BCM2_02_Mmi();
            SendMessage(msgCshdl_Requests, &canRequestCshdlMsg);
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagMsgError.bcmVorne.Bits.altF_BCM2_02_Mmi = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12016_TIMEOUT_BCM_VORNE, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagMsgError.bcmVorne.Bits.altF_BCM2_02_Mmi = 0;
            if(0 == gAppCanContext.canSelfDiagMsgError.bcmVorne.bcmVorneError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12016_TIMEOUT_BCM_VORNE, FALSE);
            }
        }
        IlClrF_BCM2_02_MmiIndication();
    }
    if (IlGetMotor_03_altIndication())
    {
        if (TRUE == IlGetRxMotor_03_alt())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagMsgError.motor.Bits.altMotor_03_alt = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12002_TIMEOUT_MOTORSTEUERUNG, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagMsgError.motor.Bits.altMotor_03_alt = 0;
            if(0 == gAppCanContext.canSelfDiagMsgError.motor.motorError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12002_TIMEOUT_MOTORSTEUERUNG, FALSE);
            }
        }
        IlClrMotor_03_altIndication();
    }
    if (IlGetGetriebe_03_altIndication())
    {
        if (TRUE == IlGetRxGetriebe_03_alt())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagMsgError.getriebe.Bits.altGetriebe_03_alt = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12004_TIMEOUT_GERTIEBESTEUERUNG, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagMsgError.getriebe.Bits.altGetriebe_03_alt = 0;
            if(0 == gAppCanContext.canSelfDiagMsgError.getriebe.getriebeError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12004_TIMEOUT_GERTIEBESTEUERUNG, FALSE);
            }
        }
        IlClrGetriebe_03_altIndication();
    }
    if (IlGetEPB_01_altIndication())
    {
        if (TRUE == IlGetRxEPB_01_alt())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                (void)DEH_AdditionalReportEvent(DTC_C12008_TIMEOUT_ELEKTRISCHE_PARKBREMSE, TRUE);
            }
        }
        else
        {
            (void)DEH_AdditionalReportEvent(DTC_C12008_TIMEOUT_ELEKTRISCHE_PARKBREMSE, FALSE);
        }
        IlClrEPB_01_altIndication();
    }
    if (IlGetESP_01_altIndication())
    {
        if (TRUE == IlGetRxESP_01_alt())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagMsgError.esp.Bits.altESP_01_alt = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12007_TIMEOUT_PSM, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagMsgError.esp.Bits.altESP_01_alt = 0;
            if (0 == gAppCanContext.canSelfDiagMsgError.esp.espError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12007_TIMEOUT_PSM, FALSE);
            }
        }
        IlClrESP_01_altIndication();
    }
    if (IlGetF_BCM1_01_MmiIndication())
    {
        if (TRUE == IlGetRxF_BCM1_01_Mmi())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagMsgError.bcmVorne.Bits.altF_BCM1_01_Mmi = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12016_TIMEOUT_BCM_VORNE, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagMsgError.bcmVorne.Bits.altF_BCM1_01_Mmi = 0;
            if(0 == gAppCanContext.canSelfDiagMsgError.bcmVorne.bcmVorneError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12016_TIMEOUT_BCM_VORNE, FALSE);
            }
        }
        IlClrF_BCM1_01_MmiIndication();
    }
    if (IlGetF_ESP_04_MmiIndication())
    {
        if (TRUE == IlGetRxF_ESP_04_Mmi())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagMsgError.esp.Bits.altF_ESP_04_Mmi = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12007_TIMEOUT_PSM, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagMsgError.esp.Bits.altF_ESP_04_Mmi = 0;
            if (0 == gAppCanContext.canSelfDiagMsgError.esp.espError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12007_TIMEOUT_PSM, FALSE);
            }
        }
        IlClrF_ESP_04_MmiIndication();
    }
    if (IlGetF_ESP_02_MmiIndication())
    {
        if (TRUE == IlGetRxF_ESP_02_Mmi())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagMsgError.esp.Bits.altF_ESP_02_Mmi = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12007_TIMEOUT_PSM, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagMsgError.esp.Bits.altF_ESP_02_Mmi = 0;
            if (0 == gAppCanContext.canSelfDiagMsgError.esp.espError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12007_TIMEOUT_PSM, FALSE);
            }
        }
        IlClrF_ESP_02_MmiIndication();
    }
    if (IlGetF_ESP_13_MmiIndication())
    {
        if (TRUE == IlGetRxF_ESP_13_Mmi())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagMsgError.esp.Bits.altF_ESP_13_Mmi = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12007_TIMEOUT_PSM, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagMsgError.esp.Bits.altF_ESP_13_Mmi = 0;
            if (0 == gAppCanContext.canSelfDiagMsgError.esp.espError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12007_TIMEOUT_PSM, FALSE);
            }
        }
        IlClrF_ESP_13_MmiIndication();
    }
    if (IlGetF_Daempfer_01_FR_MmiIndication())
    {
        if (TRUE == IlGetRxF_Daempfer_01_FR_Mmi())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                (void)DEH_AdditionalReportEvent(DTC_C1200C_TIMEOUT_PASM, TRUE);
            }
        }
        else
        {
            (void)DEH_AdditionalReportEvent(DTC_C1200C_TIMEOUT_PASM, TRUE);
        }
        IlClrF_Daempfer_01_FR_MmiIndication();
    }
    if (IlGetF_Motor_Hybrid_01_MmiIndication())
    {
        if (TRUE == IlGetRxF_Motor_Hybrid_01_Mmi())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagMsgError.motor.Bits.altF_Motor_Hybrid_01_Mmi = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12002_TIMEOUT_MOTORSTEUERUNG, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagMsgError.motor.Bits.altF_Motor_Hybrid_01_Mmi = 0;
            if(0 == gAppCanContext.canSelfDiagMsgError.motor.motorError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12002_TIMEOUT_MOTORSTEUERUNG, FALSE);
            }
        }
        IlClrF_Motor_Hybrid_01_MmiIndication();
    }
    if (IlGetF_TSG_FT_01_MmiIndication())
    {
        if (TRUE == IlGetRxF_TSG_FT_01_Mmi())
        {
            canRequestCshdlMsg.CshdlID_Rq = FT_TUER_GULTIG_RQ;
            canRequestCshdlMsg.APP_CAN_UnionCanToCshdl.FT_Tuer_Geoeffnet_Status_Request.FT_Tuer_gueltig = IlGetRxF_BCM2_02_Mmi();
            SendMessage(msgCshdl_Requests, &canRequestCshdlMsg);
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                (void)DEH_AdditionalReportEvent(DTC_C12013_TIMEOUT_TUERSTEUERGERAET_FAHRER, TRUE);
            }
        }
        else
        {
            (void)DEH_AdditionalReportEvent(DTC_C12013_TIMEOUT_TUERSTEUERGERAET_FAHRER, FALSE);
        }
        IlGetClrF_TSG_FT_01_MmiIndication();
    }

}


/* message timeout handling */
void ApplSysteminfo_01MsgTimeout(void)
{
    /* No DTC, only for NWDF behavior */
    gAppCanContext.bNWDFdet = BT_TRUE;
}

void ApplKombi_11_PAGMsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.kombi.Bits.msgKombi_11_PAG = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, TRUE);
}

void ApplKombi_02MsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.kombi.Bits.msgKombi_02 = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, TRUE);
}

void ApplVIN_01MsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.bcmVorne.Bits.msgVIN_01 = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12016_TIMEOUT_BCM_VORNE, TRUE);
}

void ApplDiagnose_01MsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgDiagnose_01 = 1;
    (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, TRUE);
}

void ApplLAD_02MsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.onBoardLader.Bits.msgLAD_02 = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12037_TIMEOUT_ON_BOARD_LADER, TRUE);
}

void ApplRDK_02_PAGMsgTimeout(void)
{
    (void)DEH_AdditionalReportEvent(DTC_C12015_TIMEOUT_RDK, TRUE);
}

void ApplKlima_03MsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.klima.Bits.msgKlima_03 = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12019_TIMEOUT_BEDIEN_UND_KLIMAREGELUNG, TRUE);
}

void ApplGateway_03MsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgGateway_03 = 1;
    (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, TRUE);
}

void ApplKlima_02MsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.klima.Bits.msgKlima_02 = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12019_TIMEOUT_BEDIEN_UND_KLIMAREGELUNG, TRUE);
}

void ApplBEM_02MsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgBEM_02 = 1;
    (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, TRUE);
}

void ApplBCM1_02MsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.bcmVorne.Bits.msgBCM1_02 = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12016_TIMEOUT_BCM_VORNE, TRUE);
}

void ApplKombi_19_PAGMsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.kombi.Bits.msgKombi_19_PAG = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, TRUE);
}

void ApplGW_Mmi_07_PAGMsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgGW_Mmi_07_PAG = 1;
    (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, TRUE);
}

void ApplGW_Mmi_06_PAGMsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgGW_Mmi_06_PAG = 1;
    (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, TRUE);
}

void ApplMFL_Tasten_Kon_01MsgTimeout(void)
{
    (void)DEH_AdditionalReportEvent(DTC_C1200F_TIMEOUT_SMLS, TRUE);
}

void ApplHVLM_05MsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.onBoardLader.Bits.msgHVLM_05 = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12037_TIMEOUT_ON_BOARD_LADER, TRUE);
}

void ApplHVLM_07_PAGMsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.onBoardLader.Bits.msgHVLM_07_PAG = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12037_TIMEOUT_ON_BOARD_LADER, TRUE);
}

void ApplKombi_EV_01_PAGMsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.kombi.Bits.msgKombi_EV_01_PAG = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, TRUE);
}

void ApplKombi_14_PAGMsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.kombi.Bits.msgKombi_14_PAG = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, TRUE);
}

void ApplLift_01MsgTimeout(void)
{
    (void)DEH_AdditionalReportEvent(DTC_C12039_TIMEOUT_LIFT_VA, TRUE);
}

void ApplNPM_01_PAGMsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgNPM_01_PAG = 1;
    (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, TRUE);
}

void ApplGW_Mmi_10_PAGMsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgGW_Mmi_10_PAG = 1;
    (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, TRUE);
}

void ApplMotor_06MsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.motor.Bits.msgMotor_06 = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12002_TIMEOUT_MOTORSTEUERUNG, TRUE);
}

void ApplGateway_01MsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgGateway_01 = 1;
    (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, TRUE);
}

void ApplKlemmen_Status_01MsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.bcmVorne.Bits.msgKlemmen_Status_01 = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12016_TIMEOUT_BCM_VORNE, TRUE);
}

void ApplMotor_15_PAGMsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.motor.Bits.msgMotor_15_PAG = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12002_TIMEOUT_MOTORSTEUERUNG, TRUE);
}

void ApplMotor_K_02MsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.motor.Bits.msgMotor_K_02 = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12002_TIMEOUT_MOTORSTEUERUNG, TRUE);
}

void ApplKombi_17_PAGMsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.kombi.Bits.msgKombi_17_PAG = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, TRUE);
}

void ApplKombi_16_PAGMsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.kombi.Bits.msgKombi_16_PAG = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, TRUE);
}

void ApplGW_Mmi_01_PAGMsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgGW_Mmi_01_PAG = 1;
    (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, TRUE);
}

void ApplGW_Mmi_05_PAGMsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgGW_Mmi_05_PAG = 1;
    (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, TRUE);
}

void ApplBCM2_03_PAGMsgTimeout(void)
{
    (void)DEH_AdditionalReportEvent(DTC_C12017_TIMEOUT_BCM_HINTEN, TRUE);
}

void ApplKlima_13_PAGMsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.klima.Bits.msgKlima_13_PAG = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12019_TIMEOUT_BEDIEN_UND_KLIMAREGELUNG, TRUE);
}

void ApplGW_Mmi_04_PAGMsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgGW_Mmi_04_PAG = 1;
    (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, TRUE);
}

void ApplKombi_10_PAGMsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.kombi.Bits.msgKombi_10_PAG = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, TRUE);
}

void ApplKombi_13_PAGMsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.kombi.Bits.msgKombi_13_PAG = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, TRUE);
}

void ApplESP_10MsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.esp.Bits.msgESP_10 = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12007_TIMEOUT_PSM, TRUE);
}

void ApplGetriebe_03MsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.getriebe.Bits.msgGetriebe_03 = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12004_TIMEOUT_GERTIEBESTEUERUNG, TRUE);
}

void ApplESP_02MsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.esp.Bits.msgESP_02 = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12007_TIMEOUT_PSM, TRUE);
}

void ApplESP_01MsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.esp.Bits.msgESP_01 = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12007_TIMEOUT_PSM, TRUE);
}

void ApplMiko_01_PAGMsgTimeout(void)
{
    (void)DEH_AdditionalReportEvent(DTC_C1207F_TIMEOUT_MITTELKONSOLE, TRUE);
}

void ApplMotor_02_sekMsgTimeout(void)
{
    gAppCanContext.canSelfDiagMsgError.motor.Bits.msgMotor_02_sek = 1;
    (void)DEH_AdditionalReportEvent(DTC_C12002_TIMEOUT_MOTORSTEUERUNG, TRUE);
}


void BCM1_02_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.bcmVorne.Bits.msgBCM1_02 = 0;
    if(0 == gAppCanContext.canSelfDiagMsgError.bcmVorne.bcmVorneError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12016_TIMEOUT_BCM_VORNE, FALSE);
    }
}

void BCM2_03_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    (void)DEH_AdditionalReportEvent(DTC_C12017_TIMEOUT_BCM_HINTEN, FALSE);
}

void BEM_02_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgBEM_02 = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.gateway.gatewayError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, FALSE);
    }
}

void ESP_01_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.esp.Bits.msgESP_01 = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.esp.espError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12007_TIMEOUT_PSM, FALSE);
    }
}

void ESP_02_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.esp.Bits.msgESP_02 = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.esp.espError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12007_TIMEOUT_PSM, FALSE);
    }
}

void ESP_10_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.esp.Bits.msgESP_10 = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.esp.espError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12007_TIMEOUT_PSM, FALSE);
    }
}

void GW_Mmi_01_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgGW_Mmi_01_PAG = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.gateway.gatewayError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, FALSE);
    }
}

void GW_Mmi_04_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgGW_Mmi_04_PAG = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.gateway.gatewayError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, FALSE);
    }
}

void Klima_02_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.klima.Bits.msgKlima_02 = 0;
    if(0 == gAppCanContext.canSelfDiagMsgError.klima.klimaError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12019_TIMEOUT_BEDIEN_UND_KLIMAREGELUNG, TRUE);
    }
}

void Klima_03_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.klima.Bits.msgKlima_03 = 0;
    if(0 == gAppCanContext.canSelfDiagMsgError.klima.klimaError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12019_TIMEOUT_BEDIEN_UND_KLIMAREGELUNG, TRUE);
    }
}

void Klima_13_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.klima.Bits.msgKlima_13_PAG = 0;
    if(0 == gAppCanContext.canSelfDiagMsgError.klima.klimaError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12019_TIMEOUT_BEDIEN_UND_KLIMAREGELUNG, TRUE);
    }
}

void Kombi_02_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.kombi.Bits.msgKombi_02 = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.kombi.kombiError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, FALSE);
    }
}

void Kombi_10_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.kombi.Bits.msgKombi_10_PAG = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.kombi.kombiError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, FALSE);
    }
}

void Kombi_11_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.kombi.Bits.msgKombi_11_PAG = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.kombi.kombiError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, FALSE);
    }
}

void Kombi_13_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.kombi.Bits.msgKombi_13_PAG = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.kombi.kombiError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, FALSE);
    }
}

void Kombi_14_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.kombi.Bits.msgKombi_14_PAG = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.kombi.kombiError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, FALSE);
    }
}

void Kombi_16_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.kombi.Bits.msgKombi_16_PAG = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.kombi.kombiError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, FALSE);
    }
}

void Kombi_17_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.kombi.Bits.msgKombi_17_PAG = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.kombi.kombiError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, FALSE);
    }
}

void Kombi_19_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.kombi.Bits.msgKombi_19_PAG = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.kombi.kombiError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, FALSE);
    }
}

void Kombi_EV_01_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.kombi.Bits.msgKombi_EV_01_PAG = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.kombi.kombiError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12018_TIMEOUT_KOMBIINSTRUMENT, FALSE);
    }
}

void LAD_02_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.onBoardLader.Bits.msgLAD_02 = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.onBoardLader.onBoardLaderError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12037_TIMEOUT_ON_BOARD_LADER, FALSE);
    }
}

void Lift_01_RxMsg(CanReceiveHandle rcvObject)
{
    (void)DEH_AdditionalReportEvent(DTC_C12039_TIMEOUT_LIFT_VA, FALSE);
}

void MFL_Tasten_Kon_01_RxMsg(CanReceiveHandle rcvObject)
{
    (void)DEH_AdditionalReportEvent(DTC_C1200F_TIMEOUT_SMLS, FALSE);
}

void Miko_01_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    (void)DEH_AdditionalReportEvent(DTC_C1207F_TIMEOUT_MITTELKONSOLE, FALSE);
}

void Motor_02_sek_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.motor.Bits.msgMotor_02_sek = 0;
    if(0 == gAppCanContext.canSelfDiagMsgError.motor.motorError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12002_TIMEOUT_MOTORSTEUERUNG, FALSE);
    }
}

void Motor_06_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.motor.Bits.msgMotor_06 = 0;
    if(0 == gAppCanContext.canSelfDiagMsgError.motor.motorError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12002_TIMEOUT_MOTORSTEUERUNG, FALSE);
    }
}

void Motor_15_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.motor.Bits.msgMotor_15_PAG = 0;
    if(0 == gAppCanContext.canSelfDiagMsgError.motor.motorError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12002_TIMEOUT_MOTORSTEUERUNG, FALSE);
    }
}

void Motor_K_02_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.motor.Bits.msgMotor_K_02 = 0;
    if(0 == gAppCanContext.canSelfDiagMsgError.motor.motorError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12002_TIMEOUT_MOTORSTEUERUNG, FALSE);
    }
}

void NPM_01_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgNPM_01_PAG = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.gateway.gatewayError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, FALSE);
    }
}

void RDK_02_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    (void)DEH_AdditionalReportEvent(DTC_C12015_TIMEOUT_RDK, FALSE);
}

void Systeminfo_01_RxMsg(CanReceiveHandle rcvObject)
{
    // no DTC check
}

void VIN_01_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.bcmVorne.Bits.msgVIN_01 = 0;
    if(0 == gAppCanContext.canSelfDiagMsgError.bcmVorne.bcmVorneError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12016_TIMEOUT_BCM_VORNE, FALSE);
    }
}

void GW_Mmi_05_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgGW_Mmi_05_PAG = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.gateway.gatewayError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, FALSE);
    }
}

void GW_Mmi_06_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgGW_Mmi_06_PAG = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.gateway.gatewayError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, FALSE);
    }
}

void GW_Mmi_07_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgGW_Mmi_07_PAG = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.gateway.gatewayError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, FALSE);
    }
}

void GW_Mmi_10_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgGW_Mmi_10_PAG = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.gateway.gatewayError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, FALSE);
    }
}

void Gateway_01_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgGateway_01 = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.gateway.gatewayError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, FALSE);
    }
}

void Gateway_03_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgGateway_03 = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.gateway.gatewayError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, FALSE);
    }
}

void Getriebe_03_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.getriebe.Bits.msgGetriebe_03 = 0;
    if(0 == gAppCanContext.canSelfDiagMsgError.getriebe.getriebeError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12004_TIMEOUT_GERTIEBESTEUERUNG, FALSE);
    }
}

void HVLM_05_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.onBoardLader.Bits.msgHVLM_05 = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.onBoardLader.onBoardLaderError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12037_TIMEOUT_ON_BOARD_LADER, FALSE);
    }
}

void HVLM_07_PAG_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.onBoardLader.Bits.msgHVLM_07_PAG = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.onBoardLader.onBoardLaderError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12037_TIMEOUT_ON_BOARD_LADER, FALSE);
    }
}

void Klemmen_Status_01_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.canSelfDiagMsgError.bcmVorne.Bits.msgKlemmen_Status_01 = 0;
    if(0 == gAppCanContext.canSelfDiagMsgError.bcmVorne.bcmVorneError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C12016_TIMEOUT_BCM_VORNE, FALSE);
    }
}

void Diagnose_01_RxMsg(CanReceiveHandle rcvObject)
{
    gAppCanContext.bDiagnose_1_MsgReceived = BT_TRUE;
    gAppCanContext.canSelfDiagMsgError.gateway.Bits.msgDiagnose_01 = 0;
    if (0 == gAppCanContext.canSelfDiagMsgError.gateway.gatewayError)
    {
        (void)DEH_AdditionalReportEvent(DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY, FALSE);
    }
}



/* End Of File APP_CAN_IL_ISO_TP_C1.c */
