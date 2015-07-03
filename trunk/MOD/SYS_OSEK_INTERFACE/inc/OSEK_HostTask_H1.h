/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:   OSEK_HostTask_H1.h
*-----------------------------------------------------------------------------
* Module Name:  MOD_OSEK
*-----------------------------------------------------------------------------
* Description:  Interface header for the HostTask_10ms
*-----------------------------------------------------------------------------
* $Date: 2011-05-10 16:51:31 +0200 (Di, 10 Mai 2011) $
* $Rev: 19588 $
* $Author: kolozsvary $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/SYS_OSEK_INTERFACE/trunk/inc/OSEK_HostTask_H1.h $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

#ifndef _HOSTTASK_H1
#define _HOSTTASK_H1

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
#include "EEPROM.h"
/*----------------------------------------------------------------------------*/
/* Public Manifest Constant Definitions                                       */
/*----------------------------------------------------------------------------*/
#define BUSOFF_DEBOUNCE_TIME 2
/*----------------------------------------------------------------------------*/
/* Public Types                                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global Variables Declarations (avoid as much as possible!)                 */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global const Declarations                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Methods                                                             */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Code Macros                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function    : getEEHostControl                                             */
/** 
    \brief      Register the adress on the structure for EEcontrol for the \n
                database task

    \return     EEDeviceControlBlockType*

   */
/*----------------------------------------------------------------------------*/
EEDeviceControlBlockType* getEEHostControl(void);


/*----------------------------------------------------------------------------*/
/* Function    : InitHostTask                                                 */
/** 
    \brief      Callback function for initialization of OsHostTask_10ms
  
    \brief      Description:\n
				Callback function to initialize the OsHostTask_10ms, \n
				this function will be only called one time during first \n
                activation of OsHostTask_10ms \n

    \return     SuccessFailType
    			Status of function run
    			SUCCESS, FAIL
   */
/*----------------------------------------------------------------------------*/
SuccessFailType InitHostTask(void);


/*----------------------------------------------------------------------------*/
/* Function    : HostTask_10ms                                                */
/** 
    \brief      Callback function for OsHostTask_10ms
  
    \brief      Description:\n
                Callback function from the OsHostTask_10ms this function will \n
				be cyclic called all 10ms  \n

    \return     void
   */
/*----------------------------------------------------------------------------*/
void HostTask_10ms(void);

#endif /* _HOSTTASK_H1 */

/* End Of File OSEK_HostTask_H1.h */
