/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     APP_CSHDL_C1.c
*-----------------------------------------------------------------------------
* Module Name:    AppTask part of CSHDL
*-----------------------------------------------------------------------------
* Description:    manage KL15 on / off and CK5050 shutdown preparation
*-----------------------------------------------------------------------------
* $Date$
* $Rev$
* $Author$
* $URL$
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/
#include "osek.h"
/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
#include "APP_INFO.h"
#include "APP_INFO_CI.h"
#include "IPC.h"

#include "APP_INFO_C1.id"
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

void callback_IPC(Uint8Type * response, Uint8Type lengthOfResponse)
{
    DEBUG_VALUE1(APP_INFO_SWI_TRC, MOD_APP_INFO, "Callback: %d", lengthOfResponse);   
}

/*----------------------------------------------------------------------------*/
/* Function    : APP_CSHDL_sfInitApp                                         */
/**
    \brief      Callback function for initialization of App Cshdl

    \brief      Description:

    \return     SuccessFailType
    			Status of function run
    			SUCCESS, FAIL
*/
/*----------------------------------------------------------------------------*/
SuccessFailType APP_INFO_sfInitApp(void)
{
    return SUCCESS;
}
static CanRequests_INFO_MsgType     CanRequests_APP_INFO_MsgData;
/*----------------------------------------------------------------------------*/
/* Function    : APP_INFO_vHandleEvents                                        */
/**
    \brief      Task Function to handle CAN events for connection Application

    \param      event
                EventMaskType
                Bitmask containing all unhandled events

    \return     void
*/
/*----------------------------------------------------------------------------*/
void APP_INFO_vHandleEvents(EventMaskType event)
{
	Uint8Type u8TempCtrlCommandValue[3] =  {0,0,0};
    // wait for interesting events
    // **************************************
    // look for events from CSHDL in HostTask
    // **************************************
    if( event & evAppTask_INFO_Request )
    {
        (void)ReceiveMessage(msgInfo_Requests ,&CanRequests_APP_INFO_MsgData);
        DEBUG_VALUE1(APP_INFO_SWI_TRC, MOD_APP_INFO, "MSG ID = %d", CanRequests_APP_INFO_MsgData.InfoID_Rq);

        switch (CanRequests_APP_INFO_MsgData.InfoID_Rq)
        {
            case MIKO_BUTTON_RQ:
    	        u8TempCtrlCommandValue[0] = 0x77;
    	        u8TempCtrlCommandValue[1] = 0x00;
                u8TempCtrlCommandValue[2] = 0x01;
                if(0 == IPC_u16WriteBlock(enIpcChannelCtrlCommands, u8TempCtrlCommandValue, 3, callback_IPC))
                {
                    DEBUG_VALUE1(APP_CAN_SWI_TRC, MOD_APP_CAN, "BEM Abschaltstufe: IPC channel busy %d", enIpcChannelCtrlCommands);
                }
                break;
            case KOMBI_02_OUTSIDE_TEMPERATURE_RQ:
                DEBUG_VALUE1(APP_INFO_SWI_TRC, MOD_APP_INFO, "Outside Temperature = %x", CanRequests_APP_INFO_MsgData.Kombi_02_Status.Aussen_Temp_status);
    	        u8TempCtrlCommandValue[0] = 0x77;
    	        u8TempCtrlCommandValue[1] = 0x00;
                u8TempCtrlCommandValue[2] = CanRequests_APP_INFO_MsgData.Kombi_02_Status.Aussen_Temp_status;
                if(0 == IPC_u16WriteBlock(enIpcChannelCtrlCommands, u8TempCtrlCommandValue, 3, NULL))
                {
                    DEBUG_VALUE1(APP_CAN_SWI_TRC, MOD_APP_CAN, "BEM Abschaltstufe: IPC channel busy %d", enIpcChannelCtrlCommands);
                }
                break;
            default:
            {
                break;
            }
        }

        if( E_COM_NOMSG == GetMessageStatus(msgInfo_Requests))
        {
            // clear only if all msg received
            (void)ClearEvent(evAppTask_INFO_Request);
        }
    }

}



/* End Of File APP_CSHDL_C1.c */


