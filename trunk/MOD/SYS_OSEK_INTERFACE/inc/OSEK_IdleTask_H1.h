/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:   OSEK_IdleTask_H1.h
*-----------------------------------------------------------------------------
* Module Name:  MOD_OSEK
*-----------------------------------------------------------------------------
* Description:  Interface header for the IdleTask_bg
*-----------------------------------------------------------------------------
* $Date: 2009-03-17 10:33:33 +0100 (Di, 17 Mrz 2009) $
* $Rev: 5312 $
* $Author: rammelt $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/SYS_OSEK_INTERFACE/trunk/inc/OSEK_IdleTask_H1.h $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

#ifndef _IDLETASK_H1
#define _IDLETASK_H1

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Manifest Constant Definitions                                       */
/*----------------------------------------------------------------------------*/

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
/* Function    : InitIdleTask                                                 */
/** 
    \brief      Callback function for initialization of OsIdleTask_bg
  
    \brief      Description:\n
				Callback function to initialize the OsIdleTask_bg this
				function will be only called one time during first activation \n
				of OsIdleTask_bg \n

    \return     SuccessFailType
    			Status of function run
    			SUCCESS, FAIL
   */
/*----------------------------------------------------------------------------*/
SuccessFailType InitIdleTask(void);


/*----------------------------------------------------------------------------*/
/* Function    : IdleTask_bg                                                  */
/** 
    \brief      Callback function for OsIdleTask_bg
  
    \brief      Description:\n
                Callback function from the OsIdleTask_bg this function will \n
				be run in the background and supported the watchdog and the \n
				runtime debugging \n

    \return     void
   */
/*----------------------------------------------------------------------------*/
void IdleTask_bg(void);


#endif /* _IDLETASK_H1 */

/* End Of File OSEK_IdleTask_H1.h */
