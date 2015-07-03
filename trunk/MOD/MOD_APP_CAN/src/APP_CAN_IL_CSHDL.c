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
#include "ccl_inc.h"

#include "APP_CAN_IL.h"
#include "APP_CAN_IL_CSHDL.id"
#include "TRACE.h"


/*----------------------------------------------------------------------------*/
/* Prototypes of file local Methods                                           */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* File local Variables                                                       */
/*----------------------------------------------------------------------------*/

void APP_CAN_IL_InitSignalReception_CSHDL(void)
{
}

#ifdef UHV_BLUETOOTH_ZERTIFIZIERUNG_PBTESTMODE
#undef IlGetRxHEC_IgnitionPos()
#undef IlGetRxHMI_HMIMode_St()
#define IlGetRxHEC_IgnitionPos()             2
#define IlGetRxHMI_HMIMode_St()              2

static Uint8Type u8BTTestCount = 0x05;
#endif

/*----------------------------------------------------------------------------*/
/* Function    : APP_CAN_IL_CheckSignalReception_CSHDL                                              */
/**
    \brief      CSHDL

    \brief      Description:
                This function is called cyclically and informs the CSHDL about the current
                status.

    \param      void
    \return     void
 */
/*----------------------------------------------------------------------------*/
void APP_CAN_IL_CheckSignalReception_CSHDL(void)
{
	CanRequests_CSHDL_MsgType canRequestCshdlMsg;

	// KLS
    if (IlGetZAS_Kl_SDataChanged())
    {
        DEBUG_VALUE1(APP_CAN_SWI_TRC, MOD_APP_CAN, "Status KL S: %d", IlGetRxZAS_Kl_S());
        canRequestCshdlMsg.CshdlID_Rq = IGNITION_STATUS_S_RQ;
        canRequestCshdlMsg.APP_CAN_UnionCanToCshdl.Klemmen_Status_Requests.ZAS_KL_S = IlGetRxZAS_Kl_S();
        SendMessage(msgCshdl_Requests, &canRequestCshdlMsg);
        IlClrZAS_Kl_SDataChanged();
    }

    // KL15
    if (IlGetZAS_Kl_15DataChanged())
    {
        DEBUG_VALUE1(APP_CAN_SWI_TRC, MOD_APP_CAN, "Status KL 15: %d", IlGetRxZAS_Kl_15());
        canRequestCshdlMsg.CshdlID_Rq = IGNITION_STATUS_15_RQ;
        canRequestCshdlMsg.APP_CAN_UnionCanToCshdl.Klemmen_Status_Requests.ZAS_KL_15 = IlGetRxZAS_Kl_15();
        SendMessage(msgCshdl_Requests, &canRequestCshdlMsg);
        if (1 == IlGetRxZAS_Kl_15())
        {
            CclSet_KL_15();
        }
        else
        {
            CclRel_KL_15();
        }
        IlClrZAS_Kl_15DataChanged();
    }

    // BEM Abschaltstufe
    if(IlGetBEM_02_AbschaltstufenDataChanged())
    {
    	DEBUG_VALUE1(APP_CAN_SWI_TRC, MOD_APP_CAN, "BEM Abschaltstufe: %d", IlGetRxBEM_02_Abschaltstufen());
		canRequestCshdlMsg.CshdlID_Rq = BEM_ABSCHALTSTUFEN_RQ;
		canRequestCshdlMsg.APP_CAN_UnionCanToCshdl.BEM_Abschaltstufen_Status_Requests.BEM_Abschaltstufe = IlGetRxBEM_02_Abschaltstufen();
		SendMessage(msgCshdl_Requests, &canRequestCshdlMsg);
        IlClrBEM_02_AbschaltstufenDataChanged();
    }

    // Tuer geoeffnet
    if(IlGetFT_Tuer_geoeffnetDataChanged())
    {
    	DEBUG_VALUE1(APP_CAN_SWI_TRC, MOD_APP_CAN, "FT_Tuer_geoeffnet: %d", IlGetRxFT_Tuer_geoeffnet());
        canRequestCshdlMsg.CshdlID_Rq = FT_TUER_GEOEFFNET_RQ;
        canRequestCshdlMsg.APP_CAN_UnionCanToCshdl.FT_Tuer_Geoeffnet_Status_Request.FT_Tuer_geoeffnet = IlGetRxFT_Tuer_geoeffnet();
        SendMessage(msgCshdl_Requests, &canRequestCshdlMsg);
        IlClrFT_Tuer_geoeffnetDataChanged();
    }

    // Diebstahlwarnanlage (DWA)
    if(IlGetBCM2_DWA_aktivDataChanged())
    {
    	DEBUG_VALUE1(APP_CAN_SWI_TRC, MOD_APP_CAN, "BCM2_DWA_aktiv: %d", IlGetRxBCM2_DWA_aktiv());
        canRequestCshdlMsg.CshdlID_Rq = LOCKING_DWA_RQ;
        canRequestCshdlMsg.APP_CAN_UnionCanToCshdl.Locking_Status_Request.LOCK_DWA_active = IlGetRxBCM2_DWA_aktiv();
        SendMessage(msgCshdl_Requests, &canRequestCshdlMsg);
        IlClrBCM2_DWA_aktivDataChanged();
    }

    // Zentralverriegelung extern verriegelt
    if(IlGetZV_verriegelt_extern_istDataChanged())
    {
    	DEBUG_VALUE1(APP_CAN_SWI_TRC, MOD_APP_CAN, "ZV_verriegelt_extern_ist: %d", IlGetRxZV_verriegelt_extern_ist());
        canRequestCshdlMsg.CshdlID_Rq = LOCKING_ZV_EXTERN_RQ;
        canRequestCshdlMsg.APP_CAN_UnionCanToCshdl.Locking_Status_Request.LOCK_ZV_Extern = IlGetRxZV_verriegelt_extern_ist();
        SendMessage(msgCshdl_Requests, &canRequestCshdlMsg);
        IlClrZV_verriegelt_extern_istDataChanged();
    }

    // Getriebe Zielgang
    if (IlGetGE_ZielgangDataChanged())
    {
    	DEBUG_VALUE1(APP_CAN_SWI_TRC, MOD_APP_CAN, "GE_Zielgang: %d", IlGetRxGE_Zielgang());
        canRequestCshdlMsg.CshdlID_Rq = ZIELGANG_RQ;
        canRequestCshdlMsg.APP_CAN_UnionCanToCshdl.Getriebe_Status_Request.GE_Zielgang = IlGetRxGE_Zielgang();
        SendMessage(msgCshdl_Requests, &canRequestCshdlMsg);
        IlClrGE_ZielgangDataChanged();
    }

    // Ultralongpress
    if (IlGetMiko_ADR_UltralongPressDataChanged())
    {
    	DEBUG_VALUE1(APP_CAN_SWI_TRC, MOD_APP_CAN, "Miko_ADR_UltralongPress: %d", IlGetRxMiko_ADR_UltralongPress());
        canRequestCshdlMsg.CshdlID_Rq = ULTRA_LONG_PRESS_RQ;
        canRequestCshdlMsg.APP_CAN_UnionCanToCshdl.Mittelkonsole_Status_Request.Miko_UltraLongPress = IlGetRxMiko_ADR_UltralongPress();
        SendMessage(msgCshdl_Requests, &canRequestCshdlMsg);
        IlClrMiko_ADR_UltralongPressDataChanged();
    }
}

/* End Of File APP_CAN_C1.c */
