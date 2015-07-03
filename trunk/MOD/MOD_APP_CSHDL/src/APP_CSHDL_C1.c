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
#include "CSHDL_c1.h"
/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
#include "APP_CSHDL.h"
#include "APP_CSHDL_CI.h"

#include "APP_CSHDL_C1.id"
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
SuccessFailType APP_CSHDL_sfInitApp(void)
{
    return SUCCESS;
}

/*----------------------------------------------------------------------------*/
/* Function    : APP_CSHDL_vHandleEvents                                      */
/**
    \brief      Task Function to handle events for Application part of CSHDL

    \brief      Description:
                Task Function called from APP_Task in 10ms cycle to handle events for Application part of CSHDL

    \param      event
                EventMaskType
                Bitmask containing all unhandled events

    \return     void
*/
/*----------------------------------------------------------------------------*/
void APP_CSHDL_vHandleEvents(EventMaskType event)
{
    // wait for interesting events
    // **************************************
    // look for events from CSHDL in HostTask
    // **************************************
    if( event & evAppTaskSystemStates )
    {
	    // check for new response messages from AT_Cmd_Parser
        CSHDL_enSystemStates App_SystemState;

        (void)ReceiveMessage(msgAppTaskSystemStates ,&App_SystemState);
        DEBUG_STATE1(APP_CSHDL_SWI_TRC, MOD_APP_CSHDL, "$CSHDL_enSystemStates$ %d", App_SystemState );

        switch (App_SystemState)
        {
            default:
            {
                break;
            }
        }

        if( E_COM_NOMSG == GetMessageStatus(msgAppTaskSystemStates))
        {
            // clear only if all msg received
            (void)ClearEvent(evAppTaskSystemStates);
        }
    }

}


/*----------------------------------------------------------------------------*/
/* Function    : CSHDL_bIsHMI_ModeOn                                              */
/**
    \brief      function to read the status of HMI Mode.

    \brief      Description:
                Read the status of HMI Mode.

    \param      void
    \return     BooleanType
 */
/*----------------------------------------------------------------------------*/
Uint32Type APP_CSHDL_u32GetAppCshdlState(void)
{
    return(0);

}


/* End Of File APP_CSHDL_C1.c */


