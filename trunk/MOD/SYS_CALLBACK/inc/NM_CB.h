/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     NM_CB.h
*-----------------------------------------------------------------------------
* Module Name:	  MOD_NM
*-----------------------------------------------------------------------------
* Description:	  callback header for the module MOD_NM
*-----------------------------------------------------------------------------
* $Date: 2011-05-10 16:51:31 +0200 (Di, 10 Mai 2011) $
* $Rev: 19588 $
* $Author: kolozsvary $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/SYS_CALLBACK/trunk/inc/NM_CB.h $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

#ifndef NM_CB_H_
#define NM_CB_H_

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/
#include "Common.h"
#include "NM_CB_cfg.h"

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Manifest Constant Definitions                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Code Macros                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Constants                                                           */
/*----------------------------------------------------------------------------*/

extern void cylicNM(void);
extern void DiagnosisNMStateMonitoring( void );
extern void HWLoopcheckStateMonitoring( void );
/*----------------------------------------------------------------------------*/
/* Function    : DiagNmGetHistoryStatus                                             */
/**
    \brief      Provide the NM history state byte from the specified position \n
                There are 5 positions available

    \return     uint8 NmStatus

   */
/*----------------------------------------------------------------------------*/
uint8 DiagNmGetHistoryStatus(uint8 u8HistoryPosition);

#endif /* _NM_CB_H */

/* End Of File NM_CB.h */
