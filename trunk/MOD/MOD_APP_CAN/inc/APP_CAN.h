/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/
/******************************************************************************/
/* File Name:     APP_CAN.h
*-----------------------------------------------------------------------------
* Module Name:    APP_CAN
*-----------------------------------------------------------------------------
* Description:    Handle CAN related doings for the applications
*-----------------------------------------------------------------------------
* $Date: 2011-07-20 16:38:51 +0200 (Mi, 20 Jul 2011) $
* $Rev: 20971 $
* $Author: weber $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_APP_CAN/trunk/inc/APP_CAN.h $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

#ifndef _APP_CAN_H
#define _APP_CAN_H

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
#include "APP_CAN_CE.h"
#include "APP_CAN_CI.h"

#include "APP_CAN_IL.h"
/*----------------------------------------------------------------------------*/
/* Public Manifest Constant Definitions                                       */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Public Types                                                               */
/*----------------------------------------------------------------------------*/
typedef enum
{
    APP_CAN_SELF_DIAGNOSIS_START_TIMER = 0,
    APP_CAN_SELF_DIAGNOSIS_TIMER_WAITING,
    APP_CAN_SELF_DIAGNOSIS_ENABLE_SELF_DIAG,
    APP_CAN_SELF_DIAGNOSIS_ENABLE_SELF_DIAG_WAITING
}AppCANSelfDiagStateType;


typedef struct
{
    BooleanType bDiagnose_1_MsgReceived;
    BooleanType bNWDFdet;
    CanSelfDiagnosisMsgErrorType canSelfDiagMsgError;
    CanSelfDiagnosisSignalErrorType canSelfDiagSigError;
    AppCANSelfDiagStateType selfDiagnosisStatusState;
    BooleanType selfDiagnosisDtcStatus;
    Uint16Type sleepDelayTimer;

}AppCanContextType;

/*----------------------------------------------------------------------------*/
/* Global Variables Declarations (avoid as much as possible!)                 */
/*----------------------------------------------------------------------------*/
typedef enum {
    RSP_WITH_DATA = 1,
    RSP_WITHOUT_DATA
} RspDataIndicationEnum;

typedef struct {
    Uint32Type         identifier;
    RspDataIndicationEnum dataInd;
    /* NOTE: common part within data is duplicate to common above to allow
     * easy access for the application */
    Uint8Type            data[8];
} ApplRspMessageType;
/*----------------------------------------------------------------------------*/
/* Public Methods                                                             */
/*----------------------------------------------------------------------------*/
void APP_CAN_vInit(void);
BooleanType APP_CAN_bDTCStore(void);
BooleanType APP_CAN_bEigenDiagDTCStore(void);
BooleanType APP_CAN_bGetNWDF(void);
BooleanType APP_CAN_bIsDiagnose1MessageReceived(void);
Uint16Type APP_CAN_SleepDelayTimer(void);
void APP_CAN_vSelfDiagnosisDtcCheck(void);
Uint8Type APP_CAN_u8Klemme15Status(void);
/*----------------------------------------------------------------------------*/
/* Public Code Macros                                                         */
/*----------------------------------------------------------------------------*/

#endif /* _APP_CAN_H */

/* End Of File APP_CAN.h */

