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
#include "APP_CAN_IL_Klima.id"
#include "TRACE.h"


/*----------------------------------------------------------------------------*/
/* Prototypes of file local Methods                                           */
/*----------------------------------------------------------------------------*/

extern AppCanContextType gAppCanContext;
/*----------------------------------------------------------------------------*/
/* File local Variables                                                       */
/*----------------------------------------------------------------------------*/

void APP_CAN_IL_InitSignalReception_Klima(void)
{
}


void APP_CAN_IL_CheckSignalReception_Klima(void)
{
    /* Klima_02 0x664 */
    if (IlGetKL_Geblaese_StatusDataChanged())
    {
        if (0xF == IlGetRxKL_Geblaese_Status())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                (void)DEH_AdditionalReportEvent(DTC_C12097_SIGNALFEHLER_BEDIEN_UND_KLIMAREGELUNG, TRUE);
            }
        }
        else
        {
            (void)DEH_AdditionalReportEvent(DTC_C12097_SIGNALFEHLER_BEDIEN_UND_KLIMAREGELUNG, FALSE);
        }
        IlClrKL_Geblaese_StatusDataChanged();
    }
    /* Klima_03 0x66E */
    if (IlGetKL_Geblaese_StatusDataChanged())
    {
        IlClrKL_Geblaese_StatusDataChanged();
    }
    /* Klima_13 0x37F */
    if(IlGetKL_LVT_O_LED_anDataChanged())
    {
        IlClrKL_LVT_O_LED_anDataChanged();
    }
    if(IlGetKL_LVT_M_LED_anDataChanged())
    {
        IlClrKL_LVT_M_LED_anDataChanged();
    }
    if(IlGetKL_LVT_U_LED_anDataChanged())
    {
        IlClrKL_LVT_U_LED_anDataChanged();
    }
}


void APP_CAN_IL_Send_PHONE_Signals(void)
{
}

/* End Of File APP_CAN_C1.c */
