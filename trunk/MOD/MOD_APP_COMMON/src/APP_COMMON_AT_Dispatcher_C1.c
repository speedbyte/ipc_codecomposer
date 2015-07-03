/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     APP_COMMON_UTILS_C1.c
*-----------------------------------------------------------------------------
* Module Name:    Common Application
*-----------------------------------------------------------------------------
* Description:    contains some helper functions common for all applications
*-----------------------------------------------------------------------------
* $Date: 2010-03-03 16:10:23 +0100 (Mi, 03 Mrz 2010) $
* $Rev: 11318 $
* $Author: brust $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/MOD/MOD_APP_COMMON/trunk/src/APP_COMMON_Utils_C1.c $
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
/*----------------------------------------------------------------------------*/
#include "Common.h"
#include "APP_COMMON_AT_Dispatcher.h"
#include "APP_COMMON_AT_Dispatcher_C1.id"
#include "Trace.h"
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
\brief	description of the type
*/

/*----------------------------------------------------------------------------*/
/* Prototypes of file local Methods                                           */
/*----------------------------------------------------------------------------*/
/**
\brief	description of the method
*/

/*----------------------------------------------------------------------------*/
/* File local Code Macros                                                     */
/*----------------------------------------------------------------------------*/
/**
\brief	description of the macros
*/

/*----------------------------------------------------------------------------*/
/* File local Variables                                                       */
/*----------------------------------------------------------------------------*/
/**
\brief	description of the private variable
*/

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
/* Function    : APP_COMMON_UTILS_u16GetBapString                             */
/**
    \brief      Extracts a BAP string from a byte sequence


    \param      pBufferBegin
                const Uint8Type*

    \param      pStringBegin
                Uint8Type**

    \return     Uint16Type
*/
/*----------------------------------------------------------------------------*/
void APP_COMMON_vHandleEvents( EventMaskType event )
{
    static BooleanType Test = BT_TRUE;
    CanResponses_INFO_MsgType    CanResponses_INFO_IL_MsgData;
    if (Test == BT_TRUE)
    {
        CanResponses_INFO_IL_MsgData.InfoID_Res = ADR_01_PAG_LED_BUTTON_CHANGE;
        CanResponses_INFO_IL_MsgData.ADR_01_PAG_ButtonStatus.ADR_01_PAG_Adr_AC_Menue_LED_an = 1;
        CanResponses_INFO_IL_MsgData.ADR_01_PAG_ButtonStatus.ADR_01_PAG_Adr_Phone_LED_an    = 0;
        CanResponses_INFO_IL_MsgData.ADR_01_PAG_ButtonStatus.ADR_01_PAG_Adr_Media_LED_an    = 0;
        CanResponses_INFO_IL_MsgData.ADR_01_PAG_ButtonStatus.ADR_01_PAG_Adr_Tuner_LED_an    = 0;
        CanResponses_INFO_IL_MsgData.ADR_01_PAG_ButtonStatus.ADR_01_PAG_Adr_Car_LED_an      = 0;
        CanResponses_INFO_IL_MsgData.ADR_01_PAG_ButtonStatus.ADR_01_PAG_Adr_Info_LED_an     = 0;
        CanResponses_INFO_IL_MsgData.ADR_01_PAG_ButtonStatus.ADR_01_PAG_Adr_Navi_LED_an     = 0;
        SendMessage(msgInfo_Responses, &CanResponses_INFO_IL_MsgData);
        Test = BT_FALSE;
    }
    if( event & evAppTaskApplResponse )
    {
        // clear only if all msg received
        (void)ClearEvent(evAppTaskApplResponse);
    }
}

/* End Of File APP_COMMON_UTILS_C1.c */


