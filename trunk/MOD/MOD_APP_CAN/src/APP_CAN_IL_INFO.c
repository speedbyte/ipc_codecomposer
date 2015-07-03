/******************************************************************************/
/*****************  Copyright (c) 2010 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
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
#include "il_inc.h"

#include "deh.h"
#include "DEH_DTC_CFG.h"
#include "APP_CAN_IL.h"
#include "APP_CAN_IL_INFO.id"
#include "TRACE.h"


/*----------------------------------------------------------------------------*/
/* Prototypes of file local Methods                                           */
/*----------------------------------------------------------------------------*/

extern AppCanContextType gAppCanContext;
static CanResponses_INFO_MsgType    CanResponses_INFO_IL_MsgData;
static CanRequests_INFO_MsgType     CanRequests_IL_APP_INFO_MsgData;
/*----------------------------------------------------------------------------*/
/* File local Variables                                                       */

/*----------------------------------------------------------------------------*/


void APP_CAN_IL_InitSignalReception_INFO(void)
{
}


void APP_CAN_IL_CheckSignalReception_INFO(void)
{
    /* Gateway_01 0x3C3 */
    if (IlGetESP_v_SignalDataChanged())
    {
        if (0xFFFF == IlGetRxESP_v_Signal())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.esp.Bits.sigESP_v_Signal = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12085_SIGNALFEHLER_PSM, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.esp.Bits.sigESP_v_Signal = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.esp.espSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12085_SIGNALFEHLER_PSM, FALSE);
            }
        }
        IlClrESP_v_SignalDataChanged();
    }
    if (IlGetMO_Drehzahl_01DataChanged())
    {
        if (0xFFFF == IlGetRxMO_Drehzahl_01())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.motor.Bits.sigMO_Drehzahl_01 = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12080_SIGNALFEHLER_MOTORSTEUERUNG, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.motor.Bits.sigMO_Drehzahl_01 = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.motor.motorSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12080_SIGNALFEHLER_MOTORSTEUERUNG, FALSE);
            }
        }
        IlClrMO_Drehzahl_01DataChanged();
    }
    if (IlGetGE_WaehlhebelDataChanged())
    {
        if (0xF == IlGetRxGE_Waehlhebel())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.getriebe.Bits.sigGE_Waehlhebel = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12082_SIGNALFEHLER_GETRIEBESTEUERUNG, TRUE);
            }
        }
        else
        {
            if (0x6 == IlGetRxGE_Waehlhebel()) /* Rückwärtsgang */
            {
                //TODO: Inform OMAP that the rear shift active
            }
            gAppCanContext.canSelfDiagSigError.getriebe.Bits.sigGE_Waehlhebel = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.getriebe.getriebeSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12082_SIGNALFEHLER_GETRIEBESTEUERUNG, FALSE);
            }
        }
        IlClrGE_WaehlhebelDataChanged();
    }

    /* Getriebe_03 0x102 */
    if (IlGetGE_ZielgangDataChanged())
    {
        if (0xF == IlGetRxGE_Zielgang())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.getriebe.Bits.sigGE_Zielgang = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12082_SIGNALFEHLER_GETRIEBESTEUERUNG, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.getriebe.Bits.sigGE_Zielgang = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.getriebe.getriebeSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12082_SIGNALFEHLER_GETRIEBESTEUERUNG, FALSE);
            }
        }
        IlClrGE_ZielgangDataChanged();
    }


    /* GW_Mmi_06_PAG 0x5EB */
    if (IlGetLWI_LenkradwinkelDataChanged())
    {
        if (0x1FFF == IlGetRxLWI_Lenkradwinkel())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                (void)DEH_AdditionalReportEvent(DTC_C12089_SIGNALFEHLER_LWS, TRUE);
            }
        }
        else
        {
            (void)DEH_AdditionalReportEvent(DTC_C12089_SIGNALFEHLER_LWS, FALSE);
        }
        IlClrLWI_LenkradwinkelDataChanged();
    }

    /* HVLM_05 0x594 */
    if (IlGetHVLM_Restladezeit_HV_Bat_02DataChanged())
    {
        if (0x1FF == IlGetRxHVLM_Restladezeit_HV_Bat_02())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Restladezeit_HV_Bat_02 = 1;
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Restladezeit_HV_Bat_02 = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.onBoardLader.onBoardLaderSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, FALSE);
            }
        }
        IlClrHVLM_Restladezeit_HV_Bat_02DataChanged();
    }

    /* HVLM_07_PAG 0x575 */
    if (IlGetHVLM_Status_Timer_1_MinuteIndication())
    {
        if (0x3F == IlGetRxHVLM_Status_Timer_1_Minute())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_1_Minute = 1;
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_1_Minute = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.onBoardLader.onBoardLaderSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, FALSE);
            }
        }
        IlClrHVLM_Status_Timer_1_MinuteIndication();
    }
    if (IlGetHVLM_Status_Timer_1_StundeIndication())
    {
        if (0x1F == IlGetRxHVLM_Status_Timer_1_Stunde())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_1_Stunde = 1;
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_1_Stunde = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.onBoardLader.onBoardLaderSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, FALSE);
            }
        }
        IlClrHVLM_Status_Timer_1_StundeIndication();
    }
    if (IlGetHVLM_Status_Timer_1_MonatIndication())
    {
        if (0xF == IlGetRxHVLM_Status_Timer_1_Monat())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_1_Monat = 1;
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_1_Monat = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.onBoardLader.onBoardLaderSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, FALSE);
            }
        }
        IlClrHVLM_Status_Timer_1_MonatIndication();
    }

    if (IlGetHVLM_Status_Timer_2_MinuteIndication())
    {
        if (0x3F == IlGetRxHVLM_Status_Timer_2_Minute())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_2_Minute = 1;
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_2_Minute = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.onBoardLader.onBoardLaderSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, FALSE);
            }
        }
        IlClrHVLM_Status_Timer_2_MinuteIndication();
    }
    if (IlGetHVLM_Status_Timer_2_StundeIndication())
    {
        if (0x1F == IlGetRxHVLM_Status_Timer_1_Stunde())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_2_Stunde = 1;
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_2_Stunde = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.onBoardLader.onBoardLaderSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, FALSE);
            }
        }
        IlClrHVLM_Status_Timer_2_StundeIndication();
    }
    if (IlGetHVLM_Status_Timer_2_MonatIndication())
    {
        if (0xF == IlGetRxHVLM_Status_Timer_2_Monat())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_2_Monat = 1;
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_2_Monat = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.onBoardLader.onBoardLaderSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, FALSE);
            }
        }
        IlClrHVLM_Status_Timer_2_MonatIndication();
    }

    if (IlGetHVLM_Status_Timer_3_MinuteIndication())
    {
        if (0x3F == IlGetRxHVLM_Status_Timer_3_Minute())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_3_Minute = 1;
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_3_Minute = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.onBoardLader.onBoardLaderSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, FALSE);
            }
        }
        IlClrHVLM_Status_Timer_3_MinuteIndication();
    }
    if (IlGetHVLM_Status_Timer_3_StundeIndication())
    {
        if (0x1F == IlGetRxHVLM_Status_Timer_3_Stunde())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_3_Stunde = 1;
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_3_Stunde = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.onBoardLader.onBoardLaderSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, FALSE);
            }
        }
        IlClrHVLM_Status_Timer_3_StundeIndication();
    }
    if (IlGetHVLM_Status_Timer_3_MonatIndication())
    {
        if (0xF == IlGetRxHVLM_Status_Timer_3_Monat())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_3_Monat = 1;
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_3_Monat = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.onBoardLader.onBoardLaderSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, FALSE);
            }
        }
        IlClrHVLM_Status_Timer_3_MonatIndication();
    }
    if (IlGetHVLM_Status_Timer_4_MinuteIndication())
    {
        if (0x3F == IlGetRxHVLM_Status_Timer_4_Minute())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_4_Minute = 1;
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_4_Minute = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.onBoardLader.onBoardLaderSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, FALSE);
            }
        }
        IlClrHVLM_Status_Timer_4_MinuteIndication();
    }
    if (IlGetHVLM_Status_Timer_4_StundeIndication())
    {
        if (0x1F == IlGetRxHVLM_Status_Timer_4_Stunde())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_4_Stunde = 1;
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_4_Stunde = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.onBoardLader.onBoardLaderSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, FALSE);
            }
        }
        IlClrHVLM_Status_Timer_4_StundeIndication();
    }
    if (IlGetHVLM_Status_Timer_4_MonatIndication())
    {
        if (0xF == IlGetRxHVLM_Status_Timer_4_Monat())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_4_Monat = 1;
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_4_Monat = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.onBoardLader.onBoardLaderSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, FALSE);
            }
        }
        IlClrHVLM_Status_Timer_4_MonatIndication();
    }
    if (IlGetHVLM_Status_Timer_7_MinuteIndication())
    {
        if (0x3F == IlGetRxHVLM_Status_Timer_7_Minute())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_7_Minute = 1;
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_7_Minute = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.onBoardLader.onBoardLaderSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, FALSE);
            }
        }
        IlClrHVLM_Status_Timer_7_MinuteIndication();
    }
    if (IlGetHVLM_Status_Timer_7_StundeIndication())
    {
        if (0x1F == IlGetRxHVLM_Status_Timer_7_Stunde())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_7_Stunde = 1;
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_7_Stunde = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.onBoardLader.onBoardLaderSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, FALSE);
            }
        }
        IlClrHVLM_Status_Timer_7_StundeIndication();
    }
    if (IlGetHVLM_Status_Timer_7_MonatIndication())
    {
        if (0xF == IlGetRxHVLM_Status_Timer_7_Monat())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_7_Monat = 1;
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.onBoardLader.Bits.HVLM_Status_Timer_7_Monat = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.onBoardLader.onBoardLaderSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER, FALSE);
            }
        }
        IlClrHVLM_Status_Timer_7_MonatIndication();
    }


    /* Kombi_02 0x6B7 */
    if (IlGetKBI_Aussen_Temp_gefDataChanged())
    {
        CanRequests_IL_APP_INFO_MsgData.InfoID_Rq = KOMBI_02_OUTSIDE_TEMPERATURE_RQ;
        CanRequests_IL_APP_INFO_MsgData.Kombi_02_Status.Aussen_Temp_status = IlGetRxKBI_Aussen_Temp_gef();
        DEBUG_VALUE1(APP_CAN_SWI_TRC, MOD_APP_CAN, "Send KBI_Aussen_Temp_gef %x", CanRequests_IL_APP_INFO_MsgData.Kombi_02_Status.Aussen_Temp_status); //lint !e641
        (void)SendMessage(msgInfo_Requests, &CanRequests_IL_APP_INFO_MsgData);
        if (0xFF == IlGetRxKBI_Aussen_Temp_gef())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_Aussen_Temp_gef = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_Aussen_Temp_gef = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.kombi.kombiSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, FALSE);
            }
        }
        IlClrKBI_Aussen_Temp_gefDataChanged();
    }

    /* Kombi_11_PAG 0x6BD */
    if (IlGetKBI_FotosensorDataChanged())
    {
        if (0xFF == IlGetRxKBI_Fotosensor())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_Fotosensor = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_Fotosensor = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.kombi.kombiSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, FALSE);
            }
        }
        IlClrKBI_FotosensorDataChanged();
    }
    if (IlGetKBI_KL58sDataChanged())
    {
        if (0x7F == IlGetRxKBI_KL58s())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_KL58s = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_KL58s = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.kombi.kombiSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, FALSE);
            }
        }
        IlClrKBI_KL58sDataChanged();
    }

    /* Kombi_13_PAG 0x11A */
    if (IlGetKBI_E_RestreichweiteDataChanged())
    {
        if (0xFFF == IlGetRxKBI_E_Restreichweite())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_E_Restreichweite = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_E_Restreichweite = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.kombi.kombiSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, FALSE);
            }
        }
        IlClrKBI_E_RestreichweiteDataChanged();
    }

    /* Kombi_14_PAG 0x533 */
    if (IlGetKBI_Trip_Reset_MinDataChanged())
    {
        if (0x3F == IlGetRxKBI_Trip_Reset_Min())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_Trip_Reset_Min = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_Trip_Reset_Min = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.kombi.kombiSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, FALSE);
            }
        }
        IlClrKBI_Trip_Reset_MinDataChanged();
    }
    if (IlGetKBI_Trip_Reset_StdDataChanged())
    {
        if (0x1F == IlGetRxKBI_Trip_Reset_Std())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_Trip_Reset_Std = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_Trip_Reset_Std = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.kombi.kombiSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, FALSE);
            }
        }
        IlClrKBI_Trip_Reset_StdDataChanged();
    }

    /* Kombi_EV_01_PAG 0x53F */
    if (IlGetKBI_Trip_E_Strecke_seitDataChanged())
    {
        if (0x1FFFF == IlGetRxKBI_Trip_E_Strecke_seit())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_Trip_E_Strecke_seit = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_Trip_E_Strecke_seit = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.kombi.kombiSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, FALSE);
            }
        }
        IlClrKBI_Trip_E_Strecke_seitDataChanged();
    }
    if (IlGetKBI_Trip_E_Strecke_fortlDataChanged())
    {
        if (0x1FFFF == IlGetRxKBI_Trip_E_Strecke_fortl())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_Trip_E_Strecke_fortl = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_Trip_E_Strecke_fortl = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.kombi.kombiSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, FALSE);
            }
        }
        IlClrKBI_Trip_E_Strecke_fortlDataChanged();
    }
    if (IlGetKBI_Trip_E_Verbr_seitDataChanged())
    {
        if (0x3FF == IlGetRxKBI_Trip_E_Verbr_seit())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_Trip_E_Verbr_seit = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_Trip_E_Verbr_seit = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.kombi.kombiSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, FALSE);
            }
        }
        IlClrKBI_Trip_E_Verbr_seitDataChanged();
    }
    if (IlGetKBI_Trip_E_Verbr_fortlDataChanged())
    {
        if (0x3FF == IlGetRxKBI_Trip_E_Verbr_fortl())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_Trip_E_Verbr_fortl = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_Trip_E_Verbr_fortl = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.kombi.kombiSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, FALSE);
            }
        }
        IlClrKBI_Trip_E_Verbr_fortlDataChanged();
    }

    /* Lift_01 0x529 */
    if (IlGetLift_StatusDataChanged())
    {
        if (0x7 == IlGetRxLift_Status())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                (void)DEH_AdditionalReportEvent(DTC_C120B1_SIGNALFEHLER_LIFT_VA, TRUE);
            }
        }
        else
        {
            (void)DEH_AdditionalReportEvent(DTC_C120B1_SIGNALFEHLER_LIFT_VA, FALSE);
        }
        IlClrLift_StatusDataChanged();
    }

    /* Miko_01_PAG 0xC1 */
    if (IlGetMiko_Volume_pressDataChanged())
    {
        if (0x3 == IlGetRxMiko_Volume_press())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                (void)DEH_AdditionalReportEvent(DTC_C120B5_SIGNALFEHLER_MITTELKONSOLE, TRUE);
            }
        }
        else
        {
            (void)DEH_AdditionalReportEvent(DTC_C120B5_SIGNALFEHLER_MITTELKONSOLE, FALSE);
        }
        IlClrMiko_Volume_pressDataChanged();
    }

    /* Motor_02_sek 0x7E */
    if (IlGetEnrgfluss_State_sekDataChanged())
    {
        if (0x3 == IlGetRxEnrgfluss_State_sek())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.motor.Bits.sigEnrgfluss_State_sek = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12080_SIGNALFEHLER_MOTORSTEUERUNG, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.motor.Bits.sigEnrgfluss_State_sek = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.motor.motorSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12080_SIGNALFEHLER_MOTORSTEUERUNG, FALSE);
            }
        }
        IlClrEnrgfluss_State_sekDataChanged();
    }
    if (IlGetEnrgfluss_State_BNDataChanged())
    {
        if (0x3 == IlGetRxEnrgfluss_State_BN())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.motor.Bits.sigEnrgfluss_State_BN = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12080_SIGNALFEHLER_MOTORSTEUERUNG, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.motor.Bits.sigEnrgfluss_State_BN = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.motor.motorSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12080_SIGNALFEHLER_MOTORSTEUERUNG, FALSE);
            }
        }
        IlClrEnrgfluss_State_BNDataChanged();
    }

    /* Motor_15_PAG 0x3A5 */
    if (IlGetLadezustandDataChanged())
    {
        if (0xFF == IlGetRxLadezustand())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.motor.Bits.sigLadezustand = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12080_SIGNALFEHLER_MOTORSTEUERUNG, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.motor.Bits.sigLadezustand = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.motor.motorSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12080_SIGNALFEHLER_MOTORSTEUERUNG, FALSE);
            }
        }
        IlClrLadezustandDataChanged();
    }
    if (IlGetEnrgfluss_StateDataChanged())
    {
        if (0xFF == IlGetRxEnrgfluss_State())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.motor.Bits.sigEnrgfluss_State = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12080_SIGNALFEHLER_MOTORSTEUERUNG, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.motor.Bits.sigEnrgfluss_State = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.motor.motorSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12080_SIGNALFEHLER_MOTORSTEUERUNG, FALSE);
            }
        }
        IlClrEnrgfluss_StateDataChanged();
    }

    if (IlGetMiko_T_SourceDataChanged())
    {
        CanRequests_IL_APP_INFO_MsgData.InfoID_Rq = MIKO_BUTTON_RQ;
        CanRequests_IL_APP_INFO_MsgData.Miko_Status.Miko_T_Source = IlGetRxMiko_T_Source();
        DEBUG_TEXT(APP_CAN_SWI_TRC, MOD_APP_CAN, "Send Button Press"); //lint !e641
        (void)SendMessage(msgInfo_Requests, &CanRequests_IL_APP_INFO_MsgData);
        IlClrMiko_T_SourceDataChanged();
    }
    if(IlGetMiko_T_AC_MenueDataChanged())
    {
        IlClrMiko_T_AC_MenueDataChanged();
    }
    if(IlGetMiko_T_PhoneDataChanged())
    {
        IlClrMiko_T_PhoneDataChanged();
    }
    if(IlGetMiko_T_MediaDataChanged())
    {
        IlClrMiko_T_MediaDataChanged();
    }
    if(IlGetMiko_T_TunerDataChanged())
    {
        IlClrMiko_T_TunerDataChanged();
    }
    if(IlGetMiko_T_BackDataChanged())
    {
        IlClrMiko_T_BackDataChanged();
    }
    if(IlGetMiko_T_OptionDataChanged())
    {
        IlClrMiko_T_OptionDataChanged();
    }
    if(IlGetMiko_T_CarDataChanged())
    {
        IlClrMiko_T_CarDataChanged();
    }
    if(IlGetMiko_T_InfoDataChanged())
    {
        IlClrMiko_T_InfoDataChanged();
    }
    if(IlGetMiko_T_NaviDataChanged())
    {
        IlClrMiko_T_NaviDataChanged();
    }
    if(IlGetMiko_Volume_pressDataChanged())
    {
        IlClrMiko_Volume_pressDataChanged();
    }
    if(IlGetMiko_ADR_UltralongPressDataChanged())
    {
        IlClrMiko_ADR_UltralongPressDataChanged();
    }
}

void APP_CAN_IL_Send_INFO_Signals(void)
{
    if(ReceiveMessage(msgInfo_Responses, &CanResponses_INFO_IL_MsgData) == E_OK)
    {
        DEBUG_VALUE1(APP_CAN_SWI_TRC, MOD_APP_CAN, "Send Info Signals: %d",
                     CanResponses_INFO_IL_MsgData.InfoID_Res); //lint !e641
        switch (CanResponses_INFO_IL_MsgData.InfoID_Res)
        {
            case ADR_01_PAG_LED_BUTTON_CHANGE:
                IlPutTxAdr_AC_Menue_LED_an(CanResponses_INFO_IL_MsgData.ADR_01_PAG_ButtonStatus.ADR_01_PAG_Adr_AC_Menue_LED_an);
                IlPutTxAdr_Phone_LED_an(CanResponses_INFO_IL_MsgData.ADR_01_PAG_ButtonStatus.ADR_01_PAG_Adr_Phone_LED_an);
                IlPutTxAdr_Media_LED_an(CanResponses_INFO_IL_MsgData.ADR_01_PAG_ButtonStatus.ADR_01_PAG_Adr_Media_LED_an);
                IlPutTxAdr_Tuner_LED_an(CanResponses_INFO_IL_MsgData.ADR_01_PAG_ButtonStatus.ADR_01_PAG_Adr_Tuner_LED_an);
                IlPutTxAdr_Car_LED_an(CanResponses_INFO_IL_MsgData.ADR_01_PAG_ButtonStatus.ADR_01_PAG_Adr_Car_LED_an);
                IlPutTxAdr_Info_LED_an(CanResponses_INFO_IL_MsgData.ADR_01_PAG_ButtonStatus.ADR_01_PAG_Adr_Info_LED_an);
                IlPutTxAdr_Navi_LED_an(CanResponses_INFO_IL_MsgData.ADR_01_PAG_ButtonStatus.ADR_01_PAG_Adr_Navi_LED_an);
            break;
            default:
                DEBUG_VALUE1(APP_CAN_SWI_TRC, MOD_APP_CAN, "Send Info Signals: no valid send reason %d",
                             CanResponses_INFO_IL_MsgData.InfoID_Res); //lint !e641
            break;
        }
    }
}

/* End Of File APP_CAN_IL_INFO.c */

