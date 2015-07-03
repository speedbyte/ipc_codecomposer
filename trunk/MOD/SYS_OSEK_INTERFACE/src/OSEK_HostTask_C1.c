/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     OSEK_HostTask_C1.c
*-----------------------------------------------------------------------------
* Module Name:    MOD_OSEK
*-----------------------------------------------------------------------------
* Description:    file to provide the Init and Task body for the
*                 HostTask_10ms.
*-----------------------------------------------------------------------------
* $Date: 2011-07-19 13:19:03 +0200 (Di, 19 Jul 2011) $
* $Rev: 20942 $
* $Author: weber $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/SYS_OSEK_INTERFACE/trunk/src/OSEK_HostTask_C1.c $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/
#include <osek.h>

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
#include "Common.h"
#include "ISRMask_CB.h"
#include "SYS_INIT.h"
#include "OSEK_HostTask_H1.h"
#include "il_inc.h"
#include "NM_CB.h"
#include "APP_CAN.h"
#include "OSEK_HostTask_C1.id"
#include "EEPROM_LAYOUT.h"
#include "EEPROM_LAYOUT_CFG.h"
#include "deh.h"
#include "deh_cfg.h"
#include "TRACE.h"
#include "APP_CAN_IL.h"
#include "CCL.h"
#include "ccl_inc.h"
#include "APP_DESC.h"
#include "Diag_ReqHandling.h"
#include "nmh_appl.h"
/*----------------------------------------------------------------------------*/
/* pragma Directives                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global Variables Definitions (avoid as much as possible!)                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global const Definitions                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Manifest Constant Definitions                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Types                                                              */
/*----------------------------------------------------------------------------*/
EEDeviceControlBlockType EEHostControl;

/*----------------------------------------------------------------------------*/
/* Prototypes of private Methods                                              */
/*----------------------------------------------------------------------------*/
//static void vHostTask_PrintStackUsage();
/*----------------------------------------------------------------------------*/
/* Private Code Macros                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private const Definitions                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Variables                                                          */
/*----------------------------------------------------------------------------*/
static CSHDL_ENUM_REQUEST_TO_CAN Can_Cshdl_ReceivedMsgData;
/*----------------------------------------------------------------------------*/
/* Private Address Calculations                                               */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Function    : getEEHostControl                                             */
/**
    \brief      Register the adress on the structure for EEcontrol for the
                database task

    \return     EEDeviceControlBlockType*

   */
/*----------------------------------------------------------------------------*/
EEDeviceControlBlockType* getEEHostControl(void)
{
    return &EEHostControl;
}

/*----------------------------------------------------------------------------*/
/* Function    : InitHostTask                                                 */
/**
    \brief      Callback function for initialization of OsHostTask_10ms

    \brief      Description:
				Callback function to initialize the OsHostTask_10ms,
				this function will be only called one time during first
                activation of OsHostTask_10ms

    \return     SuccessFailType
    			Status of function run
    			SUCCESS, FAIL
   */
/*----------------------------------------------------------------------------*/
SuccessFailType InitHostTask(void)
{
    SuccessFailType sF = SUCCESS;
    EEDeviceControlBlockType    *pEEHost;
//    CommonResponseCodeType retval = COMMON_RSP_OK;
    tCclNmInitParaListType brsMainCclNmInitList;

    /* IMPORTANT: Init Peripherals first !!!! */
    /* initialize the Peripheral parts of the System. */
    sF = SYSINIT_sfPeripheralsInit();
    pEEHost = (EEDeviceControlBlockType *)getEEHostControl();
    getEEHostControl()->priority = EEPromHIGH_PRIORITY;

    /* DEM initialization */
//    (void)Dem_InitMemory();
//    (void)Dem_PreInit();

    sF = EEPROM_sfInit(pEEHost);

    /* initialize the Software parts of the System. */
    sF = SYSINIT_sfSwInit();

    /* Dont change the sequence of EEPROM Reads. Please consider the starting address ( 2nd parameter in EEPROM_Read ) in
     * case of adding more functions.*/
    EEPROM_vLayoutInit();
    EEPROM_vLayoutCfgInit();


	/* activate OSEK-Tasks */
	(void)ActivateTask(OsAppTask_event_100ms);        /* activation for OsAppTask_event_100ms */
	(void)ActivateTask(OsDatabaseTask_event);   /* activation for DatabaseTask_event */
	(void)ActivateTask(OsSystemTask_event);         /* activation for SystemTask_event */

	/* initialize interrupt flag register */
	ApplInterruptFlagMask();

    //retval = EEPROM_sfRead(pEEHost, FODB_EE_ADDDRESS_DEM_DATA, (Uint8Type *)&Dem_NvData, sizeof(Dem_NonVolatileDataType));
    //retval = retval;
    /* TODO: Check return value */

//    (void)Dem_Init();
	/* Read the unlearncounter from EEProm and Function for initializing the DTC EEPROM area once  */
	InitDEHFaultData();

	if(DEH_Init() != DEH_OK)
	{
		DEH_InitEEPROM();
		(void)DEH_Init();
	}

    brsMainCclNmInitList.cclNmInit_0 = kCclNmInitNormal;
    CclInitPowerOn(&brsMainCclNmInitList);
    /* call init for modul APPCan */
    APP_CAN_IL_Init();
    
    DiagInit();

    /* TODO: call e.g. for Klemmenwechsel */
    /* TODO: check return value */
//    if( Dem_SetOperationCycleState(DEM_POWER, DEM_CYCLE_STATE_START) != E_OK )
//    {
//        // Something went wrong
//    }
    return(sF);
}
#ifdef epromRewrite
/*----------------------------------------------------------------------------*/
/* Function    : WriteToROM                                                   */
/**
    \brief      Writing the initial data to the ROM

    \brief      Description:
                Callback function from the OsHostTask_10ms this function will
				be cyclic called all 10ms
   */
/*----------------------------------------------------------------------------*/
Uint16Type initDataHex [27] = {
		0x000,
		0x00B,
		0x00F,
		0x01A,
		0x01D,
		0x035,
		0x03B,
		0x046,
		0x04A,
		0x04F,
		0x057,
		0x058,
		0x065,
		0x066,
		0x074,
        0x075,
        0x08C,
        0x0AA,
        0x0AB,
        0x0B1,
        0x0B4,
        0x0BA,
        0x0BD,
        0x0DC,
        0x0E2,
        0x0E5,
        0x0E7
};
char initDataText [27][24] = {"91864217000",
		"X001",
		"91864217000",
		"H01",
		"AnzeigeDomainRechner",
		"001000",
		"91864217000",
		"0001",
		"J000",
		"0000000000000000",
		"40",
		"ADR",
		"0",
		"00000000000001",
		"0",
		"SJA-00104.10.8100011234",
		"0",
		"8",
		"000000000000",
		"000000",
		"000000000000",
		"000000",
		"ADR",
		"00000000",
		"00000000",
		"0001",
		"0001"
};
int counterE2P = 0;

void WriteToROM (void)
{
	if (counterE2P < 27){
	EEPROM_rcWrite(getEEHostControl(),
			(EEAddressType) initDataHex[counterE2P],
			(Uint8Type *)initDataText[counterE2P],
			strlen( initDataText[counterE2P] ),
			NULL);
	counterE2P++;
	}
}
#endif

/*----------------------------------------------------------------------------*/
/* Function    : HostTask_10ms                                                */
/**
    \brief      Callback function for OsHostTask_10ms

    \brief      Description:
                Callback function from the OsHostTask_10ms this function will
				be cyclic called all 10ms

    \return     void
   */
/*----------------------------------------------------------------------------*/
void HostTask_10ms(void)
{
    EventMaskType events;

#ifdef epromRewrite
    static Uint8Type i_write = 5;
#endif
    /* wait for event ... */
	(void)WaitEvent(evActivateHostTask_10ms |
                    evHostTaskDiagnoseResponse |
                    evHostTaskOnCshdlRequestToCan |
                    evHostTaskHandleDiagReq |
                    evHostTaskSendingCodingData |
                    evHostTask_INFO_Response
                    );


    (void)GetEvent(OsHostTask_10ms, &events);

    if( events & evActivateHostTask_10ms)
    {
        /* CCL */
        CclScheduleTask();

        /*HW loopcheck monitoring*/
        HWLoopcheckStateMonitoring();

        (void)ClearEvent(evActivateHostTask_10ms);

        /* check DataChanged Flags of Interaction Layer */

        APP_CAN_vSelfDiagnosisDtcCheck();
        APP_CAN_IL_CheckSignalReception();

        DEH_ProcessDiagEventHandler();
        /* Outside handling for DEH EEprom write retry handling */
        APL_DEH_EEPWriteHandleRetries();
#ifdef epromRewrite
        if (i_write == 5)
        {
            WriteToROM();
            i_write = 1;
        }
        else
        {
            i_write += 1;
        }
#endif
        Diag_vTask();
        NMH_vNmCyclicTask();
        cylicNM();
    }
    if ( events & evHostTaskOnCshdlRequestToCan )
    {
	    (void)ClearEvent(evHostTaskOnCshdlRequestToCan);
	    (void)ReceiveMessage(msgCshdlRequestToCan, &Can_Cshdl_ReceivedMsgData);
	    //if ( Can_Cshdl_ReceivedMsgData == RequestCanCommunication )
	    //{
		//    DEBUG_TEXT(OSEK_INTERFACE_SWI_TRC, MOD_OSEK_INTERFACE, "Wake up Network Management");
		//    (void)CclRequestCommunication(CCL_CSHDL);
	    //}
	    //else if ( Can_Cshdl_ReceivedMsgData == ReleaseCanCommunication )
	    //{
		//    DEBUG_TEXT(OSEK_INTERFACE_SWI_TRC, MOD_OSEK_INTERFACE, "Sleep Network Management");
		//    CclReleaseCommunication(CCL_CSHDL);
	    //}
	    //else if ( Can_Cshdl_ReceivedMsgData == DisableCanCommunication )
	    //{
		//    DEBUG_TEXT(OSEK_INTERFACE_SWI_TRC, MOD_OSEK_INTERFACE, "Disable CAN Hardware");
		//    CclReleaseCommunication(CCL_CSHDL);
	    //}
        //else if ( Can_Cshdl_ReceivedMsgData == FastShutDownCanCommunication )
        //{
        //    DEBUG_TEXT(OSEK_INTERFACE_SWI_ERR, MOD_OSEK_INTERFACE, "FAST SHUT DOWN !!!!!!!");
        //    DEBUG_TEXT(OSEK_INTERFACE_SWI_ERR, MOD_OSEK_INTERFACE, "FAST SHUT DOWN !!!!!!!");
        //    DEBUG_TEXT(OSEK_INTERFACE_SWI_ERR, MOD_OSEK_INTERFACE, "FAST SHUT DOWN !!!!!!!");
        //    DEBUG_TEXT(OSEK_INTERFACE_SWI_ERR, MOD_OSEK_INTERFACE, "FAST SHUT DOWN !!!!!!!");
        //    DEBUG_TEXT(OSEK_INTERFACE_SWI_ERR, MOD_OSEK_INTERFACE, "FAST SHUT DOWN !!!!!!!");
        //    ApplCclSleepTrcv();
        //}
    }
    if (events & evHostTaskHandleDiagReq)
    {
	    (void)ClearEvent(evHostTaskHandleDiagReq);
        DIAG_ReqHandler();
    }

    if (events & evHostTaskDiagnoseResponse)
    {
        /*Diagnosis App Resp handler*/
        //DIAG_DESC_AppRespHandler();
    }

    APP_CAN_IL_HandleEvents(events);

    return;
}

/* End Of File OSEK_HostTask_C1.c */
