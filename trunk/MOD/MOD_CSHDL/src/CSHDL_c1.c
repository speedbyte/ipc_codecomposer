/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/**
 * \file 	CSHDL_C1.c
 * \brief	this module administers the power handling between parrot, tms and radio.
 * \brief	This file fulfills the following requirements:
 * 			1. Power handling between Parrot and TMS.
 * 			2. Power handling between TMS and Radio.
 * 			3. Inform Application about state changes.
 *          5. The document also is written in the file and is generated over doxygen tool.
 */
/*-----------------------------------------------------------------------------
 * $Date: 2011-09-19 14:52:14 +0200 (Mo, 19 Sep 2011) $
 * $Rev: 21831 $
 * $Author: weber $
 * $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_CSHDL/trunk/src/CSHDL_c1.c $
 *-----------------------------------------------------------------------------
*/
/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/
#include <osek.h>
#include <osekext.h>        // vector

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
#include "Common.h"
#include "Startup.h"
#include "OSEK_SystemTask_H1.h"
#include "CSHDL_CI.h"
#include "SYS_INIT.h"
#include "CSHDL.h"
#include "PWRMGR.h"
#include "CSHDL_c1.id"
#include "CSHDL_c1.h"
#include "TRACE.h"
#include "EEPROM_LAYOUT_CFG.h"

#include "CCL.h"
/*----------------------------------------------------------------------------*/
/* pragma Directives                                                          */
/*----------------------------------------------------------------------------*/

typedef enum
{
    CSHDL_ON_OFF_STATE_IDLE = 0,
    CSHDL_ON_OFF_STATE_WRITE_OPERATION_TIME,
    CSHDL_ON_OFF_STATE_WAIT,
    CSHDL_ON_OFF_STATE_SYSTEM_POWERDOWN
}CSHDL_OnOff_StateMachineType;


/*----------------------------------------------------------------------------*/
/* Global Variables Definitions (avoid as much as possible!)                  */
/*----------------------------------------------------------------------------*/
static TickType  _CSHDL_u32OnOffStateTime;

static BooleanType _CSHDL_bIsWaitBusSleepActive = BT_FALSE;
static BooleanType _CSHDL_bChangeToPowerDown = BT_FALSE;

static CanRequests_CSHDL_MsgType CanRequests_IL_CSHDl_MsgData;
static CSHDL_ENUM_REQUEST_TO_CAN Can_Cshdl_SendMsgData;

static CSHDL_ENUM_CAN_COMMUNICATION_STATES _CSHDL_enCanState;
static CSHDL_ENUM_ONOFF_STATES _CSHDL_enOnOffStateCurrent;
static CSHDL_ENUM_ONOFF_STATES _CSHDL_enOnOffStateCurrentPrevious;


// interne Zustaende
static CSHDL_ST_InternalStates _CSHDL_ST_InternalStates;

static CSHDL_OnOff_StateMachineType onOffStateMaschine = CSHDL_ON_OFF_STATE_IDLE;

/*----------------------------------------------------------------------------*/
/* Private Manifest Constant Definitions                                      */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Private Types                                                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Prototypes of file local Methods                                           */
/*----------------------------------------------------------------------------*/
static void SystemPowerdown(void);
static void _CSHDL_vOnOff_ChangeState (CSHDL_ENUM_ONOFF_STATES newOnOffState);

/*----------------------------------------------------------------------------*/
/* File local const Definitions                                               */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Private Address Calculations                                               */
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* Function    : SystemPowerdown			                                  */
/**
    \brief      function to handle the system shutoff

    \brief      Description:
                function to manage the system shutoff or initiated the restart
                if Pin INH = High will be detected.

    \param      void
    \return     void
 */
/*----------------------------------------------------------------------------*/
static void SystemPowerdown(void)
{
	Uint32Type u32WdToggleTimer = 0;

    DEBUG_TEXT(CSHDL_SWI_TRC, MOD_CSHDL, "SystemPowerdown");


    /* Switch Power supply off */
    GIO_vPinWrite(PORT_MON_PWRHOLD, HIGH, GIOD);

    DEBUG_TEXT(CSHDL_SWI_TRC, MOD_CSHDL, "Pulling Power Hold to Low, Complete power off in around 100 ms !!!!");
/*
    u32WdToggleTimer = osGetSystemCounter() + 2;
    for (;;)
    {
        if (u32WdToggleTimer <= osGetSystemCounter())
        {
            (void)WD_u8ToggleWD();
            /***** ANFANG: Wenn dieser Code aktiviert ist, funktioniert der Shutdown nicht mehr! *****/
//            if (TRUE != GIO_u8PinRead(PORT_CAN_INHIBIT, GIOA))
//            {
//                /* software reset */
//                c_int00();
//            }
            /***** ENDE: Wenn dieser Code aktiviert ist, funktioniert der Shutdown nicht mehr! *****/
//            u32WdToggleTimer = osGetSystemCounter() + 2;
//        }
//    }
}



/*----------------------------------------------------------------------------*/
/* Function    : SystemPowerdown			                                  */
/**
    \brief      function to handle the system shutoff

    \brief      Description:
                function to manage the system shutoff or initiated the restart
                if Pin INH = High will be detected.

    \param      void
    \return     void
 */
/*----------------------------------------------------------------------------*/
static void _CSHDL_vOnOff_ChangeState (CSHDL_ENUM_ONOFF_STATES newOnOffState)
{
	DEBUG_TEXT(CSHDL_SWI_TRC, MOD_CSHDL, "_CSHDL_vOnOff_ChangeState");

    _CSHDL_enOnOffStateCurrentPrevious = _CSHDL_enOnOffStateCurrent;
    _CSHDL_enOnOffStateCurrent = newOnOffState;
    _CSHDL_u32OnOffStateTime = osGetSystemCounter();

    DEBUG_STATE2(CSHDL_SWI_TRC, MOD_CSHDL, "OnOffState: $CSHDL_ENUM_ONOFF_STATES$ %d -> $CSHDL_ENUM_ONOFF_STATES$ %d",_CSHDL_enOnOffStateCurrentPrevious, _CSHDL_enOnOffStateCurrent);
}

/*----------------------------------------------------------------------------*/
/* Function    : SystemPowerdown			                                  */
/**
    \brief      function to handle the system shutoff

    \brief      Description:
                function to manage the system shutoff or initiated the restart
                if Pin INH = High will be detected.

    \param      void
    \return     void
 */
/*----------------------------------------------------------------------------*/
static void CSHDL_vOnOff_StateMachine(void)
{
	static Uint16Type time = 0;
    Uint32Type runTime = 0;
    Uint8Type buffer[3];
    static Uint8Type shutDownCount=0;
	unsigned int * pFlashRequest = (unsigned int *) 0x400000ul;
	void (*go2Bootloader) (void) = 0x00000000ul;

	EEDeviceControlBlockType    *pEEDcb = (EEDeviceControlBlockType *)getEESystemControl();

	if(CAN_NMH_off == _CSHDL_ST_InternalStates.CanNmh)
	{
		if((BT_FALSE == _CSHDL_bChangeToPowerDown) && (osGetSystemCounter() - time >= 500))
		{
			_CSHDL_bChangeToPowerDown = BT_TRUE;
			DEBUG_TEXT(CSHDL_SWI_TRC, MOD_CSHDL, "CAN-Bus in Schlafmodus, TMS470 Power Off");
            onOffStateMaschine = CSHDL_ON_OFF_STATE_WRITE_OPERATION_TIME;

		}
	}



	/***** TEST für Bootloader *****/
	if(_CSHDL_ST_InternalStates.BEM_AS == BEM_ABSCHALTSTUFE_RUHESTROMMESSMODUS)
	{
		_CSHDL_ST_InternalStates.BEM_AS = BEM_ABSCHALTSTUFE_0;

		DEBUG_TEXT(CSHDL_SWI_TRC, MOD_CSHDL, "SystemReset");
		*pFlashRequest = 0x55AAF00Ful;
		/*c_int00();*/
		go2Bootloader();
	}
	/***** TEST für Bootloader *****/


    switch (onOffStateMaschine)
    {
        case CSHDL_ON_OFF_STATE_IDLE:
            // do nothing ... wait
            break;
        case CSHDL_ON_OFF_STATE_WRITE_OPERATION_TIME:
            shutDownCount=0;
            (void)EEPROM_enGetByteSequenceFromRamMirror(buffer,
                                                        PAG_DB_EE_ADDRESS_OperationTimeOverall_LEN,
                                                        EEPROM_LAYOUT_ENUM_OperationTimeOverall);
            runTime = osGetSystemCounter() / SEC(60);
            runTime += ((buffer[2] << 16) | (buffer[1] << 8) | buffer[0]);
            DEBUG_VALUE1(CSHDL_SWI_TRC, MOD_CSHDL, "Write operation time[min] %d", runTime);
            buffer[0] = (Uint8Type)runTime;
            buffer[1] = (Uint8Type)(runTime>>8);
            buffer[2] = (Uint8Type)(runTime>>16);
            (void)EEPROM_sfRamWriteOnly(buffer, EEPROM_LAYOUT_ENUM_OperationTimeOverall );
            onOffStateMaschine = CSHDL_ON_OFF_STATE_WAIT;
            break;
        case CSHDL_ON_OFF_STATE_WAIT:
            if (shutDownCount >= 3)
            {
                onOffStateMaschine = CSHDL_ON_OFF_STATE_SYSTEM_POWERDOWN;
            }
            else
            {
                shutDownCount+=1;
            }
            /* waiting */
            break;
        case CSHDL_ON_OFF_STATE_SYSTEM_POWERDOWN:
            if (TRUE != GIO_u8PinRead(PORT_IS_OMAP_SHUTDOWN, GIOA))
            {
                onOffStateMaschine = CSHDL_ON_OFF_STATE_IDLE;
	            SystemPowerdown();
            }
            break;
        default:
            break;
    }


    switch (_CSHDL_enOnOffStateCurrent )
    {
        default:
        	break;
    }
}


/*----------------------------------------------------------------------------*/
/* Function    : SystemPowerdown			                                  */
/**
    \brief      function to handle the system shutoff

    \brief      Description:
                function to manage the system shutoff or initiated the restart
                if Pin INH = High will be detected.

    \param      void
    \return     void
 */
/*----------------------------------------------------------------------------*/
void CSHDL_manager(void)
{
	static Uint32Type tmpval=0;
	EventMaskType eventMask;  /* received event */

    /* process event */
    (void)GetEvent(OsSystemTask_event,&eventMask);

    if(eventMask & evSystemTask_CSHDL_Request)
    {
        if(ReceiveMessage(msgCshdl_Requests, &CanRequests_IL_CSHDl_MsgData) == E_OK)
        {
        	// Statemachine, reaction on a CAN-Message
        	switch (CanRequests_IL_CSHDl_MsgData.CshdlID_Rq)
        	{
        		case IGNITION_STATUS_S_RQ:
					tmpval = CanRequests_IL_CSHDl_MsgData.APP_CAN_UnionCanToCshdl.Klemmen_Status_Requests.ZAS_KL_S;
					if (1 == tmpval)
					{
						_CSHDL_ST_InternalStates.ignitionKLS = IGNITION_KLS_ON;
					}
					else
					{
						_CSHDL_ST_InternalStates.ignitionKLS = IGNITION_KLS_OFF;
					}
					DEBUG_VALUE1(CRC_SWI_TRC, MOD_CSHDL,"Ignition KLS: %d", _CSHDL_ST_InternalStates.ignitionKLS);
					break;

        		case IGNITION_STATUS_15_RQ:
        			tmpval = CanRequests_IL_CSHDl_MsgData.APP_CAN_UnionCanToCshdl.Klemmen_Status_Requests.ZAS_KL_15;
        			if (1 == tmpval)
        			{
        				_CSHDL_ST_InternalStates.ignitionKL15 = IGNITION_KL15_ON;
        			}
        			else
        			{
        				_CSHDL_ST_InternalStates.ignitionKL15 = IGNITION_KL15_OFF;
        			}
        			DEBUG_VALUE1(CRC_SWI_TRC, MOD_CSHDL,"Ignition KL15: %d", _CSHDL_ST_InternalStates.ignitionKL15);
        			break;

        		case BEM_ABSCHALTSTUFEN_RQ:
        			tmpval = CanRequests_IL_CSHDl_MsgData.APP_CAN_UnionCanToCshdl.BEM_Abschaltstufen_Status_Requests.BEM_Abschaltstufe;
					switch(tmpval)
					{
						case BEM_ABSCHALTSTUFE_0:
							_CSHDL_ST_InternalStates.BEM_AS = BEM_ABSCHALTSTUFE_0;
							break;

						case BEM_ABSCHALTSTUFE_1:
							_CSHDL_ST_InternalStates.BEM_AS = BEM_ABSCHALTSTUFE_1;
							break;

						case BEM_ABSCHALTSTUFE_2:
							_CSHDL_ST_InternalStates.BEM_AS = BEM_ABSCHALTSTUFE_2;
							break;

						case BEM_ABSCHALTSTUFE_3:
							_CSHDL_ST_InternalStates.BEM_AS = BEM_ABSCHALTSTUFE_3;
							break;

						case BEM_ABSCHALTSTUFE_TRANSPORTMODUS:
							_CSHDL_ST_InternalStates.BEM_AS = BEM_ABSCHALTSTUFE_TRANSPORTMODUS;
							break;

						case BEM_ABSCHALTSTUFE_RUHESTROMMESSMODUS:
							_CSHDL_ST_InternalStates.BEM_AS = BEM_ABSCHALTSTUFE_RUHESTROMMESSMODUS;
							break;

						default:
							_CSHDL_ST_InternalStates.BEM_AS = BEM_ABSCHALTSTUFE_0;
							break;
					}
					DEBUG_VALUE1(CRC_SWI_TRC, MOD_CSHDL,"BEM Abschaltstufe: %d", _CSHDL_ST_InternalStates.BEM_AS);
					break;

				case FT_TUER_GEOEFFNET_RQ:
					tmpval = CanRequests_IL_CSHDl_MsgData.APP_CAN_UnionCanToCshdl.FT_Tuer_Geoeffnet_Status_Request.FT_Tuer_geoeffnet;
					if (1 == tmpval)
					{
						_CSHDL_ST_InternalStates.FT_Door = FT_DOOR_OPEN;
					}
					else
					{
						_CSHDL_ST_InternalStates.FT_Door = FT_DOOR_CLOSE;
					}
					DEBUG_VALUE1(CRC_SWI_TRC, MOD_CSHDL,"FT Tuer: %d", _CSHDL_ST_InternalStates.FT_Door);
					break;

				case LOCKING_DWA_RQ:
					tmpval = CanRequests_IL_CSHDl_MsgData.APP_CAN_UnionCanToCshdl.Locking_Status_Request.LOCK_DWA_active;
					if (1 == tmpval)
					{
						_CSHDL_ST_InternalStates.DWA_Locking = DWA_LOCKING_ACTIV;
					}
					else
					{
						_CSHDL_ST_InternalStates.DWA_Locking = DWA_LOCKING_INACTIV;
					}
					DEBUG_VALUE1(CRC_SWI_TRC, MOD_CSHDL,"DWA Locking: %d", _CSHDL_ST_InternalStates.DWA_Locking);
					break;

				case LOCKING_ZV_EXTERN_RQ:
					tmpval = CanRequests_IL_CSHDl_MsgData.APP_CAN_UnionCanToCshdl.Locking_Status_Request.LOCK_ZV_Extern;
					if (1 == tmpval)
					{
						_CSHDL_ST_InternalStates.ZV_extern = ZV_EXTERN_LOCKING_ACTIV;
					}
					else
					{
						_CSHDL_ST_InternalStates.ZV_extern = ZV_EXTERN_LOCKING_INACTIV;
					}
					DEBUG_VALUE1(CRC_SWI_TRC, MOD_CSHDL,"ZV extern: %d", _CSHDL_ST_InternalStates.ZV_extern);
					break;

				case ZIELGANG_RQ:
					tmpval = CanRequests_IL_CSHDl_MsgData.APP_CAN_UnionCanToCshdl.Getriebe_Status_Request.GE_Zielgang;
					if(GE_ZIELGANG_R == tmpval)
					{
						_CSHDL_ST_InternalStates.GE_Gear = GE_ZIELGANG_R;
						DEBUG_TEXT(CSHDL_SWI_TRC, MOD_CSHDL, "GE Zielgang: Rueckwaerts");
					}
					DEBUG_VALUE1(CRC_SWI_TRC, MOD_CSHDL,"GE Zielgang: %d", tmpval);
					break;

				case ULTRA_LONG_PRESS_RQ:
					tmpval = CanRequests_IL_CSHDl_MsgData.APP_CAN_UnionCanToCshdl.Mittelkonsole_Status_Request.Miko_UltraLongPress;
					if (1 == tmpval)
					{
						_CSHDL_ST_InternalStates.UltraLongPress = ULTRA_LONG_PRESS_ACTIVE;
					}
					else
					{
						_CSHDL_ST_InternalStates.UltraLongPress = ULTRA_LONG_PRESS_INACTIVE;
					}
					DEBUG_VALUE1(CRC_SWI_TRC, MOD_CSHDL,"UltraLongPress: %d", _CSHDL_ST_InternalStates.UltraLongPress);
					break;

				case NETWORKMANAGEMENT_ST_RQ:
					if (0x00 == CanRequests_IL_CSHDl_MsgData.APP_CAN_UnionCanToCshdl.BusStatus_Requests.BusStatus)
					{
						_CSHDL_enCanState = CAN_COMMUNICATION_CAN_BUS_SLEEP;
						DEBUG_TEXT(CSHDL_SWI_TRC, MOD_CSHDL, "!! BUS SLEEP EVENT RECVD!!");

						_CSHDL_ST_InternalStates.CanNmh = CAN_NMH_off;
					}
					else if (0x01 == CanRequests_IL_CSHDl_MsgData.APP_CAN_UnionCanToCshdl.BusStatus_Requests.BusStatus)
					{
						_CSHDL_enCanState = CAN_COMMUNICATION_CANBUS_ACTIVE;
						DEBUG_TEXT(CSHDL_SWI_TRC, MOD_CSHDL, "!! BUS WAKEUP EVENT RECVD!!");

						_CSHDL_ST_InternalStates.CanNmh = CAN_NMH_ready;
						_CSHDL_bChangeToPowerDown = BT_FALSE;
					}
					else if (0x02 == CanRequests_IL_CSHDl_MsgData.APP_CAN_UnionCanToCshdl.BusStatus_Requests.BusStatus)
					{
						_CSHDL_enCanState = CAN_COMMUNICATION_CANBUS_ACTIVE;
						DEBUG_TEXT(CSHDL_SWI_TRC, MOD_CSHDL, "!! BUS RESUME EVENT RECVD!!");
						_CSHDL_ST_InternalStates.CanNmh = CAN_NMH_init;
					}
					else if( 0x03 == CanRequests_IL_CSHDl_MsgData.APP_CAN_UnionCanToCshdl.BusStatus_Requests.BusStatus )
					{
						_CSHDL_bIsWaitBusSleepActive = BT_FALSE;
						DEBUG_TEXT(CSHDL_SWI_TRC, MOD_CSHDL, "!! WAIT BUS SLEEP EVENT FINISHED!!");
					}
					else if( 0x04 == CanRequests_IL_CSHDl_MsgData.APP_CAN_UnionCanToCshdl.BusStatus_Requests.BusStatus )
					{
						_CSHDL_bIsWaitBusSleepActive = BT_TRUE;
						DEBUG_TEXT(CSHDL_SWI_TRC, MOD_CSHDL, "!! WAIT BUS SLEEP EVENT RECVD!!");
					}
					DEBUG_VALUE1(CRC_SWI_TRC, MOD_CSHDL,"Can NM High: %d", _CSHDL_ST_InternalStates.CanNmh);
					break;

        		default:
        			break;
        	}

        }
        if(GetMessageStatus(msgCshdl_Requests) == E_COM_NOMSG)
        {
            // clear only if all msg received
            (void)ClearEvent(evSystemTask_CSHDL_Request);
            //DEBUG_TEXT(CSHDL_SWI_TRC, MOD_CSHDL, "clear event if all msg received");
        }
    }


    CSHDL_vOnOff_StateMachine();
}


/*----------------------------------------------------------------------------*/
/* Function    : CSHDL_init					                                  */
/**
    \brief      function to initalize the CSHDL-Manager

    \brief      Description:
                tbd

    \param      void
    \return     void
 */
/*----------------------------------------------------------------------------*/
SuccessFailType CSHDL_init(void)
{
    _CSHDL_u32OnOffStateTime = osGetSystemCounter();

    _CSHDL_enOnOffStateCurrentPrevious = _CSHDL_enOnOffStateCurrent = ON_OFF_INIT;

    (void)memset (&CanRequests_IL_CSHDl_MsgData, 0, sizeof (CanRequests_IL_CSHDl_MsgData));

    Can_Cshdl_SendMsgData = RequestCanCommunication;
    (void)SendMessage(msgCshdlRequestToCan, &Can_Cshdl_SendMsgData);


    return(SUCCESS);
}


/*----------------------------------------------------------------------------*/
/* Function    : CSHDL_bIsHMI_ModeOn			                                  */
/**
    \brief      function to read the status of HMI Mode.

    \brief      Description:
                Read the status of HMI Mode.

    \param      void
    \return     BooleanType
 */
/*----------------------------------------------------------------------------*/
BooleanType CSHDL_bIsHMI_ModeOn(void)
{
	DEBUG_TEXT(CSHDL_SWI_TRC, MOD_CSHDL, "CSHDL_bIsHMI_ModeOn");

    return BT_FALSE;
}


/*----------------------------------------------------------------------------*/
/* Function    : CSHDL_cbAlarmCallbackOneHourModeOver			                          */
/**
    \brief      This function will be called when one hour is over.

    \brief      Description:

    \param      void
    \return     void
 */
/*----------------------------------------------------------------------------*/
ALARMCALLBACK(CSHDL_cbAlarmCallbackOneHourModeOver)
{
	DEBUG_TEXT(CSHDL_SWI_TRC, MOD_CSHDL, "CSHDL_cbAlarmCallbackOneHourModeOver");
}



/* End Of File CSHDL_c1.c */
