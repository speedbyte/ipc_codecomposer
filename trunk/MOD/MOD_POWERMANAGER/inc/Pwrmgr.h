/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     Pwrmgr.h
*-----------------------------------------------------------------------------
* Module Name:
*-----------------------------------------------------------------------------
* Description:
*-----------------------------------------------------------------------------
* $Date: 2011-07-14 10:41:44 +0200 (Do, 14 Jul 2011) $
* $Rev: 20868 $
* $Author: ntchoumi $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_POWERMANAGER/trunk/inc/Pwrmgr.h $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

#ifndef _PWRMGR_H
#define _PWRMGR_H



/*--------------------------------------------------------------------------*/
/* Battery Voltage Defaults                                                 */
/*--------------------------------------------------------------------------*/
/* interpretation: U(KL30_INT) = (0.028623 * ADC_KL_30) + 0.5
 *                 ADC_KL_30 = (U(KL30_INT)+ 0.5) / 0.028623 */

#define BATTERY_VOLTAGE_NORMAL_LOW                          /* 8.5 V                */  \
                        (314)
#define BATTERY_VOLTAGE_NORMAL_LOW_RECOVER                  /* 9.0 V                */  \
                        (332)
#define BATTERY_VOLTAGE_NORMAL_HIGH_RECOVER                 /* 15.0 V               */  \
                        (542)
#define BATTERY_VOLTAGE_NORMAL_HIGH                         /* 15.5 V               */  \
                        (559)

#define BATTERY_VOLTAGE_EIGENDIAG_LOW                       /* 9.0 V               */  \
                        (332)
#define BATTERY_VOLTAGE_EIGENDIAG_LOW_RECOVER               /* 10.0 V               */  \
                        (367)
#define BATTERY_VOLTAGE_EIGENDIAG_HIGH_RECOVER				/* 16.5 V               */  \
                        (594)
#define BATTERY_VOLTAGE_EIGENDIAG_HIGH						/* 17.0 V               */  \
                        (611)

/*--------------------------------------------------------------------------*/
/* Typedefs                                                                 */
/*--------------------------------------------------------------------------*/
/**
    \brief      symbolic names for the different Voltage states
*/
typedef enum {
/** \brief device in valid Power state */
    PWMGR_NormalVoltage,
/** \brief device in under Power state */
    PWMGR_NormalLowVoltage,
/** \brief device in valid Power state, comming from under voltage. DTC are blocked (hysteresis) */
    PWMGR_NormalLowRecoverVoltage,
/** \brief device in over Power state */
    PWMGR_NormalHighVoltage,
/** \brief device in valid Power state, comming from over voltage. DTC are blocked (hysteresis) */
    PWMGR_NormalHighRecoverVoltage
}PWMGR_enVoltageStates;

typedef enum
{
    PWRMGR_STATE_NORMAL,
    PWRMGR_STATE_NORMAL_LOW_RECOVER,
    PWRMGR_STATE_HIGH_RECOVER,
    PWRMGR_STATE_NORMAL_HIGH,
    PWRMGR_STATE_NORMAL_LOW,
    PWRMGR_STATE_SHUTDOWN,
    PWRMGR_STATE_IS_SHUTDOWN
} PwrmgrStateType;


/*--------------------------------------------------------------------------*/
/* Method Protoypes                                                         */
/*--------------------------------------------------------------------------*/


SuccessFailType Pwrmgr_Manager(void);
SuccessFailType Pwrmgr_Manager_Handler_For_Rapid_Voltage_Changes(void);


SuccessFailType Pwrmgr_Init(void);
SuccessFailType Pwrmgr_Handler_Init_For_Rapid_Voltage_Changes(void);


PwrmgrStateType Pwrmgr_GetPowerManagerState(void);


FlagType Pwrmgr_GetCurrentScope(void);
FlagType Pwrmgr_GetCurrentScopeEigenDiag(void);


PWMGR_enVoltageStates Pwrmgr_GetVoltageState(void);
Uint16Type Pwrmgr_GetRapidPwrmgrVoltage(void);

#endif
