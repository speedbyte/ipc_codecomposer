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
#include "APP_CAN_IL_Navigation.id"
#include "TRACE.h"

/*----------------------------------------------------------------------------*/
/* Prototypes of file local Methods                                           */
/*----------------------------------------------------------------------------*/

extern AppCanContextType gAppCanContext;
/*----------------------------------------------------------------------------*/
/* File local Variables                                                       */
/*----------------------------------------------------------------------------*/

void APP_CAN_IL_InitSignalReception_Navigation(void)
{
}


void APP_CAN_IL_CheckSignalReception_Navigation(void)
{
    /* ESP_02 0x101 */
    if (IlGetESP_LaengsbeschlDataChanged())
    {
        if (0x3FF == IlGetRxESP_Laengsbeschl())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.esp.Bits.sigESP_Laengsbeschl = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12085_SIGNALFEHLER_PSM, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.esp.Bits.sigESP_Laengsbeschl = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.esp.espSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12085_SIGNALFEHLER_PSM, FALSE);
            }
        }
        IlClrESP_LaengsbeschlDataChanged();
    }

    /* ESP_10 0x116 */
    if (IlGetESP_Wegimpuls_VLDataChanged())
    {
        if (0x3FF == IlGetRxESP_Wegimpuls_VL())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.esp.Bits.sigESP_Wegimpuls_VL = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12085_SIGNALFEHLER_PSM, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.esp.Bits.sigESP_Wegimpuls_VL = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.esp.espSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12085_SIGNALFEHLER_PSM, FALSE);
            }
        }
        IlClrESP_Wegimpuls_VLDataChanged();
    }
    if (IlGetESP_Wegimpuls_VRDataChanged())
    {
        if (0x3FF == IlGetRxESP_Wegimpuls_VR())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.esp.Bits.sigESP_Wegimpuls_VR = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12085_SIGNALFEHLER_PSM, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.esp.Bits.sigESP_Wegimpuls_VR = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.esp.espSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12085_SIGNALFEHLER_PSM, FALSE);
            }
        }
        IlClrESP_Wegimpuls_VRDataChanged();
    }
    if (IlGetESP_Wegimpuls_HLDataChanged())
    {
        if (0x3FF == IlGetRxESP_Wegimpuls_HL())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.esp.Bits.sigESP_Wegimpuls_HL = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12085_SIGNALFEHLER_PSM, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.esp.Bits.sigESP_Wegimpuls_HL = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.esp.espSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12085_SIGNALFEHLER_PSM, FALSE);
            }
        }
        IlClrESP_Wegimpuls_HLDataChanged();
    }
    if (IlGetESP_Wegimpuls_HRDataChanged())
    {
        if (0x3FF == IlGetRxESP_Wegimpuls_HR())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.esp.Bits.sigESP_Wegimpuls_HR = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12085_SIGNALFEHLER_PSM, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.esp.Bits.sigESP_Wegimpuls_HR = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.esp.espSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12085_SIGNALFEHLER_PSM, FALSE);
            }
        }
        IlClrESP_Wegimpuls_HRDataChanged();
    }
    /* ESP_01 0x100 */
    if(IlGetASR_Tastung_passivDataChanged())
    {
        IlClrASR_Tastung_passivDataChanged();
    }
    /* ESP_02 0x101 */
    if(IlGetESP_LaengsbeschlDataChanged())
    {
        IlClrESP_LaengsbeschlDataChanged();
    }
    /* ESP_10 0x116 */
    if(IlGetESP_QBit_Wegimpuls_VLDataChanged())
    {
        IlClrESP_QBit_Wegimpuls_VLDataChanged();
    }
    if(IlGetESP_QBit_Wegimpuls_VRDataChanged())
    {
        IlClrESP_QBit_Wegimpuls_VRDataChanged();
    }
    if(IlGetESP_QBit_Wegimpuls_HLDataChanged())
    {
        IlClrESP_QBit_Wegimpuls_HLDataChanged();
    }
    if(IlGetESP_QBit_Wegimpuls_HRDataChanged())
    {
        IlClrESP_QBit_Wegimpuls_HRDataChanged();
    }
    if(IlGetESP_Wegimpuls_VLDataChanged())
    {
        IlClrESP_Wegimpuls_VLDataChanged();
    }
    if(IlGetESP_Wegimpuls_VRDataChanged())
    {
        IlClrESP_Wegimpuls_VRDataChanged();
    }
    if(IlGetESP_Wegimpuls_HLDataChanged())
    {
        IlClrESP_Wegimpuls_HLDataChanged();
    }
    if(IlGetESP_Wegimpuls_HRDataChanged())
    {
        IlClrESP_Wegimpuls_HRDataChanged();
    }
    if(IlGetESP_VL_FahrtrichtungDataChanged())
    {
        IlClrESP_VL_FahrtrichtungDataChanged();
    }
    if(IlGetESP_VR_FahrtrichtungDataChanged())
    {
        IlClrESP_VR_FahrtrichtungDataChanged();
    }
    if(IlGetESP_HL_FahrtrichtungDataChanged())
    {
        IlClrESP_HL_FahrtrichtungDataChanged();
    }
    if(IlGetESP_HR_FahrtrichtungDataChanged())
    {
        IlClrESP_HR_FahrtrichtungDataChanged();
    }
    /* GW_Mmi_05_PAG 0x38C */
    if (IlGetESP_Querbeschleunigung_OffsetDataChanged())
    {
        if (0x1FF == IlGetRxESP_Querbeschleunigung_Offset())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.esp.Bits.sigESP_Querbeschleunigung_Offset = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12085_SIGNALFEHLER_PSM, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.esp.Bits.sigESP_Querbeschleunigung_Offset = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.esp.espSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12085_SIGNALFEHLER_PSM, FALSE);
            }
        }
        IlClrESP_Querbeschleunigung_OffsetDataChanged();
    }
    if (IlGetESP_Querbeschleunigung_RohDataChanged())
    {
        if (0x3F == IlGetRxESP_Querbeschleunigung_Roh())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.esp.Bits.sigESP_Querbeschleunigung_Roh = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12085_SIGNALFEHLER_PSM, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.esp.Bits.sigESP_Querbeschleunigung_Roh = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.esp.espSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12085_SIGNALFEHLER_PSM, FALSE);
            }
        }
        IlClrESP_Querbeschleunigung_RohDataChanged();
    }
    if(IlGetESP_Off_LampeDataChanged())
    {
        IlClrESP_Off_LampeDataChanged();
    }
    if(IlGetESP_StillstandsflagDataChanged())
    {
        IlClrESP_StillstandsflagDataChanged();
    }
}

void APP_CAN_IL_Send_Navigation_Signals(void)
{
}

/* End Of File APP_CAN_IL_MDI.c */

