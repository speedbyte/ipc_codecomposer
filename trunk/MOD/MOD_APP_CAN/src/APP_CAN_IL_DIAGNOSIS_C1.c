/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     APP_CAN_IL_DIAGNOSIS_C1.c
*-----------------------------------------------------------------------------
* Module Name:    APP_CAN_IL_DIAGNOSIS_C1
*-----------------------------------------------------------------------------
* Description:    Handle CAN related doings for the diagnosis application
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
/*----------------------------------------------------------------------------*/
#include "il_inc.h"
#include "deh.h"
#include "DEH_DTC_CFG.h"

#include "APP_CAN_IL.h"
#include "APP_CAN_IL_DIAGNOSIS_C1.id"
#include "TRACE.h"
#include "desc.h"



/*----------------------------------------------------------------------------*/
/* pragma Directives                                                          */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Global Variables Definitions (avoid as much as possible!)                  */
/*----------------------------------------------------------------------------*/
extern AppCanContextType gAppCanContext;
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

/* Function :   APP_CAN_IL_InitSignalReception_DIAGNOSIS                      */
/**
  \brief        Init APP IL Diagnosis variables

  \return       void

 */
/*----------------------------------------------------------------------------*/
void APP_CAN_IL_InitSignalReception_DIAGNOSIS( )
{
}

/*----------------------------------------------------------------------------*/

/* Function :   APP_CAN_IL_CheckSignalReception_DIAGNOSIS                     */
/**
  \brief        Cyclic called function for Diagnosis relevant CAN msg checking

  \return       void

 */
/*----------------------------------------------------------------------------*/
void APP_CAN_IL_CheckSignalReception_DIAGNOSIS()
{
    if (IlGetKBI_KilometerstandDataChanged())
    {
        if (0xFFFFFF == IlGetRxKBI_Kilometerstand())
        {
            if (BT_TRUE == APP_CAN_bEigenDiagDTCStore())
            {
                gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_Kilometerstand = 1;
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, TRUE);
            }
        }
        else
        {
            gAppCanContext.canSelfDiagSigError.kombi.Bits.sigKBI_Kilometerstand = 0;
            if (0 == gAppCanContext.canSelfDiagSigError.kombi.kombiSigError)
            {
                (void)DEH_AdditionalReportEvent(DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT, FALSE);
            }
        }
        IlClrKBI_KilometerstandDataChanged();
    }
    if (IlGetSI_NWDF_gueltigIndication())
    {
        DEBUG_VALUE2(APP_CAN_SWI_TRC, MOD_APP_CAN, "Status NWDF_gueltig: %d NWDF: %d", IlGetRxSI_NWDF_gueltig(), IlGetRxSI_NWDF());
        if (TRUE == IlGetRxSI_NWDF_gueltig())
        {
            DEBUG_TEXT(APP_CAN_SWI_DBG, MOD_APP_CAN, "mSystemInfo_1: NWDF gueltige Bit set to 1");
            if((BT_FALSE == gAppCanContext.bNWDFdet) && (BT_TRUE == IlGetRxSI_NWDF()))
            {
                DEBUG_TEXT(APP_CAN_SWI_DBG, MOD_APP_CAN, "mSystemInfo_1: NWDF Bit set to 1");
                // Start timeoutwatching
                //IlRxRelease();
                //APP_CAN_sfReInitTOVariables();
            }
            gAppCanContext.bNWDFdet = (BooleanType) IlGetRxSI_NWDF();
        }
        else
        {
            //Stop timeout watching
            gAppCanContext.bNWDFdet = BT_TRUE;
        }
        IlClrSI_NWDF_gueltigIndication();
    }
}

/*----------------------------------------------------------------------------*/

/* Function :   APP_CAN_IL_DIAGNOSIS_Get_DD00_Global_Real_Time                */
/**
  \brief        Called from Diagnosis to get a specific DID

  \return       void

 */
/*----------------------------------------------------------------------------*/
void APP_CAN_IL_DIAGNOSIS_Get_Global_Real_Time( Uint8Type* pDD00Data )
{
//    (void)memcpy( pDD00Data, CAN_IL_Diagnosis_Data.u8DD00Data, sizeof(CAN_IL_Diagnosis_Data.u8DD00Data) );
//    DEBUG_VALUE4(ISOTP_SWI_TRC, MOD_ISOTP, "Date_Month_Year_Hour_Minute_Second %02d_%02d_%04d_%02d", CAN_IL_Diagnosis_Data.u8DD00Data[2], CAN_IL_Diagnosis_Data.u8DD00Data[1], CAN_IL_Diagnosis_Data.u8DD00Data[0], CAN_IL_Diagnosis_Data.u8DD00Data[3]);
}

/* End Of File APP_CAN_IL_DIAGNOSIS_C1.c */
