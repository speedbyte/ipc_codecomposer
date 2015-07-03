/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:  CSHDL_CI.h
*-----------------------------------------------------------------------------
* Module Name: CSHDL (Central state handler)
*-----------------------------------------------------------------------------
* Description: managing the system states for the TMS470 and Bluetooth module
*-----------------------------------------------------------------------------
* $Date: 2011-05-11 09:29:27 +0200 (Mi, 11 Mai 2011) $
* $Rev: 19603 $
* $Author: agrawal $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_CSHDL/trunk/inc/CSHDL_CI.h $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

#ifndef _CSHDL_CI_H
#define _CSHDL_CI_H

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/
#include "common.h"

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Manifest Constant Definitions                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Import configuration                                                       */
/*----------------------------------------------------------------------------*/
/**
\brief	description of configured interface
*/


/*----------------------------------------------------------------------------*/
/* Synonym adaptions                                                          */
/*----------------------------------------------------------------------------*/
/**
\brief	Interface function
*/

/*----------------------------------------------------------------------------*/
/* Prototypes of module global methods                                        */
/*----------------------------------------------------------------------------*/
/**
\brief	description of the method
*/


/*----------------------------------------------------------------------------*/
/* Module global code macros                                                  */
/*----------------------------------------------------------------------------*/
/**
\brief	description of the macros
*/

/*----------------------------------------------------------------------------*/
/* Module global variables                                                    */
/*----------------------------------------------------------------------------*/
/**
\brief	description of the module global variable
*/
typedef union
{
    Uint8Type   systemStates;
    struct
    {
        Uint8Type   s0  :1; /* b0 0:state not triggered   1:state triggered   */
        Uint8Type   s1  :1; /* b1 0:state not triggered   1:state triggered   */
        Uint8Type   s2  :1; /* b2 0:state not triggered   1:state triggered   */
        Uint8Type   s3  :1; /* b3 0:state not triggered   1:state triggered   */
        Uint8Type   s4  :1; /* b4 0:state not triggered   1:state triggered   */
        Uint8Type   s5  :1; /* b5 0:state not triggered   1:state triggered   */
        Uint8Type   s6  :1; /* b6 0:state not triggered   1:state triggered   */
        Uint8Type   s7  :1; /* b7 0:state not triggered   1:state triggered   */
    } state;
} CSHDL_SystemStateWorkFlowType;

/*----------------------------------------------------------------------------*/
/* Module global const definitions                                            */
/*----------------------------------------------------------------------------*/
typedef enum
{
	IGNITION_KL15_OFF = 0,
	IGNITION_KL15_ON
} CSHDL_ENUM_KL15_IgnitionState;


typedef enum
{
	IGNITION_KLS_OFF = 0,
	IGNITION_KLS_ON
} CSHDL_ENUM_KLS_IgnitionState;


typedef enum
{
	BEM_ABSCHALTSTUFE_0	= 0,
	BEM_ABSCHALTSTUFE_1,
	BEM_ABSCHALTSTUFE_2,
	BEM_ABSCHALTSTUFE_3,
	BEM_ABSCHALTSTUFE_TRANSPORTMODUS,
	BEM_ABSCHALTSTUFE_RUHESTROMMESSMODUS = 7
} CSHDL_ENUM_Abschaltstufen;


typedef enum
{
	FT_DOOR_CLOSE = 0,
	FT_DOOR_OPEN
} CSHDL_ENUM_FT_DoorState;


typedef enum
{
	DWA_LOCKING_INACTIV = 0,
	DWA_LOCKING_ACTIV
} CSHDL_ENUM_DWA_LockingState;


typedef enum
{
	ZV_EXTERN_LOCKING_INACTIV = 0,
	ZV_EXTERN_LOCKING_ACTIV
} CSHDL_ENUM_ZV_extern_LockingState;


typedef enum
{
	GE_ZIELGANG_NP = 0,
	GE_ZIELGANG_1,
	GE_ZIELGANG_2,
	GE_ZIELGANG_3,
	GE_ZIELGANG_4,
	GE_ZIELGANG_5,
	GE_ZIELGANG_6,
	GE_ZIELGANG_7,
	GE_ZIELGANG_R,
	GE_ZIELGANG_8 = 11,
	GE_ZIELGANG_9,
	GE_ZIELGANG_NotDefined = 14,
	GE_ZIELGANG_Error
} CSHDL_ENUM_GE_Zielgang;


typedef enum
{
	ULTRA_LONG_PRESS_INACTIVE = 0,
	ULTRA_LONG_PRESS_ACTIVE
}CSHDL_ENUM_UltraLongPressState;


typedef enum
{
    CAN_NMH_off = 0,
    CAN_NMH_init,
    CAN_NMH_ready
} CSHDL_ENUM_CAN_NMH_State;


typedef struct
{
	CSHDL_ENUM_KL15_IgnitionState 		ignitionKL15;
	CSHDL_ENUM_KLS_IgnitionState  		ignitionKLS;
	CSHDL_ENUM_Abschaltstufen			BEM_AS;
	CSHDL_ENUM_FT_DoorState				FT_Door;
	CSHDL_ENUM_DWA_LockingState			DWA_Locking;
	CSHDL_ENUM_ZV_extern_LockingState	ZV_extern;
	CSHDL_ENUM_GE_Zielgang				GE_Gear;
	CSHDL_ENUM_UltraLongPressState		UltraLongPress;
	CSHDL_ENUM_CAN_NMH_State			CanNmh;
}CSHDL_ST_InternalStates;





typedef enum
{
    CSHDL_Poff = 0,
    CSHDL_SYSinit,
    CSHDL_TMS470ready,
    CSHDL_SYSrun,
    CSHDL_BTSWupdate
} CSHDL_GesSystemStateType;


typedef enum
{
    ON_OFF_INIT = 0,
    CAN_TRAFFIC,
    IDLE_BUS_SLEEP_INDICATION,
    MEDIA_CONDITION_UPDATE,
    ACTIVE_DEVICE_DETECTION_BUS_SLEEP_INDICATION,
    PHONE_CONDITION_UPDATE,
    START_MODES,
    ONE_HOUR_MODE_STATE,
    ONOFF_WAIT_SAVE_EEPROM_TIME,
    ENTER_NORMALPOWER_MODE_RESEND_STATUS,
    PREPARE_COMPLETE_SHUTDOWN,
    SOFTWARE_DOWNLOAD,
    ENTER_NORMALPOWER_MODE_USB,
    EXIT_NORMALPOWER_MODE_USB,
    ENTER_NORMALPOWER_MODE_DTC,
    EXIT_NORMALPOWER_MODE_DTC,
    ENTER_NORMALPOWER_MODE_CAN,
    EXIT_NORMALPOWER_MODE_CAN
}CSHDL_ENUM_ONOFF_STATES;


typedef enum
{
    CAN_COMMUNICATION_NOT_STARTED=0,       // Init after Reset of TMS
    CAN_COMMUNICATION_CANBUS_ACTIVE,       // after ?
    CAN_COMMUNICATION_CAN_BUS_SLEEP        // after Callback ApplCclSleep
}CSHDL_ENUM_CAN_COMMUNICATION_STATES;


#endif /* _CSHDL_CI_H */

/* End Of File CSHDL_CI.h */
