/******************************************************************************/
/*****************  Copyright (c) 2011 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     Diag_Service_22.h
*-----------------------------------------------------------------------------
* Module Name:    DIAG
*-----------------------------------------------------------------------------
* Description:    Handle Diagnose Service 22
*-----------------------------------------------------------------------------
* $Date: 2011-07-20 16:38:51 +0200 (Mi, 20 Jul 2011) $
* $Rev: 20971 $
* $Author: weber $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_APP_CAN/trunk/src/APP_CAN_C1.c $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/
#ifndef _DIAG_REQHANDLING
#define _DIAG_REQHANDLING

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
/* include the export configuration file */

/*----------------------------------------------------------------------------*/
/* Public Manifest Constant Definitions                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Types                                                               */
/*----------------------------------------------------------------------------*/
typedef enum
{
    DIAG_REQ_SEARCHING_DID_STATE = 0,
    DIAG_REQ_WAITING_UNTIL_FUNC_IS_FINISHED_STATE,
    DIAG_REQ_NEXT_DID_STATE,
    DIAG_REQ_FINISHED_STATE
}DiagRequestStateType;


typedef struct
{
    DiagRequestStateType    DiagnoseRequestState;
    DescStateGroup          activeDiagnosticSession;
    Uint8Type               au8FingerprintValue[6];
    BooleanType             bFingerprintValueIsReceived;
    Uint8Type               au8ProgrammingDate[3];
    BooleanType             bProgrammingDateIsReceived;
    Uint8Type               au8Seed[4];
    Uint8Type               au8Key[4];
    Uint8Type               securityState;
    Uint16Type              timerSecurityAccess;
    Uint8Type               resetControl;
}DiagnoseContextType;
/*----------------------------------------------------------------------------*/
/* Global Variables Declarations (avoid as much as possible!)                 */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global const Declarations                                                  */
/*----------------------------------------------------------------------------*/
/* return values of the function SDSext_WriteUserAndIOData() */
/* */

/*----------------------------------------------------------------------------*/
/* Public Methods                                                             */
/*----------------------------------------------------------------------------*/

void DIAG_vGenerateSecurityAccessKey(void);
extern void DIAG_ReqHandler(void);
extern void DiagInit(void);
extern void Diag_vTask(void);
BooleanType DIAG_bCodingParameterCheck(CodingBitMaskType *codingMask);
void DIAG_vWriteCodingParameterInPersistentData(CodingBitMaskType *codingMask);
/*----------------------------------------------------------------------------*/
/* Public Code Macros                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/


#endif /* _DIAG_REQHANDLING */

/* End Of File Diag_Service_22.h */


