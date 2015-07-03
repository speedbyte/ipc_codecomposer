/******************************************************************************/
/*****************  Copyright (c) 2011 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/
/**
 * \file 	deh_cfg.c
 * \brief	this module manage is the application part of DEH
 * Detailed description found below.
 * \brief	Detailed description of the file.
*/
/*-----------------------------------------------------------------------------
* $Date: 2010-10-08 11:11:48 +0200 (Fr, 08 Okt 2010) $
* $Rev: 15681 $
* $Author: agrawal $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/VW_UHV-NAR/SW/MOD/MOD_APP_DTC/trunk/src/APP_DTC_C1.c $
*-----------------------------------------------------------------------------
*/
/*==============================================================================
                      Diagnostic Event Handler  (DEH)
                     ---------------------------------
                      Version 1.2.5
                      Author: Ingo Gensert/ IAV GmbH
                      Date:   29.01.2008
                      Modul:  deh_cfg.c

Revison History:
----------------
Rev.                        Comments
------------------------------------------------------------------------------
V1.2.5   Change StatusOfDTC Flags after DEH_ClearEvent()
=======  =====================================================================
  KWP2000: clear event within the error memory BUT NO change of readiness bit
           and set to PASSIVE (NOT STORED)
  UDS:     bit7 - MIL ........................ => RESET to OFF
           bit6 - Test Not Compl This Op Cycle => reset to NOT TESTED THIS OP.
                                                  CYCLE
           bit5 - Test Failed Since Last Clear => NO CHANGE 
           bit4 - Test Not Complete SLC ...... => NO CHANGE 
           bit3 - Conf DTC ................... => Reset to NO CONFIRMED DTC
           bit2 - Pending DTC ................ => NO CHANGE
           bit1 - Test Failed This OP Cycle .. => Reset to TEST NOT FAILED
           bit0 - Test Current State ......... => reset to PASSIVE
        

V1.2.4   Bugfix DEH_ReadDTCExtDataRecord()
=======  =====================================================================
  1. priority test for the current event with correct event index
==============================================================================

V1.2.3   NOT ERASABLE EVENTS handling
=======  =====================================================================
  1. All state bits (StatusOfDTC) for NOT erasable events are not reset or 
     cleared with the function DEH_ClearDiagnosticInformation() if the current 
     diagnostic session NOT equal to Developper Session OR Programmer Session 
==============================================================================

V1.2.2   Extend Prio 9 / Change Locked DTC handling / Extend DEFECT ECU errors
=======  =====================================================================
  1. Change state from ACTIVE - NOT STORED events after call 
     DEH_ControlDTCSetting(ON) back to PASSIVE state. This is necesarry to 
     start a normal debouncing and storage after new error detection.
  2. Priority 9 events are only erasable within the developer diagnosis 
     session.
  3. DEH_ClearDiagnosticInformation() in all other diagnosis session
     (NOT developer session) has no influence to the Status Of DTC flags for 
     Prio 9 Events.
  4. ECU defect events are now erasable within the diagnosis programmer session.
  5. Bugfix:: DEH_ReadDTCExtDataRecord()-> StatusOfDTC return value now correct
     (former only for event with the number 0!)
  6. clear unused variable DEH_stActiveEvents_mb
  7. support the variable DEH_StEV_chgState_mu8 only if compiler switch 
    (DEH_SUP_DETECT_CHANGE_EV_STATE) is set
  8. new state for unlearn algorithm state machine (to avoid unlearn blocking 
     after a new DEH_Init(..))
==============================================================================

V1.2.1   PRIORITY 9 Event support
=======  ========================
  events with priority 9 have no influence to the CAN event state bit
  (macro DEH_GET_CAN_EVENT_BIT (variable DEH_stCANEventBit_mb)) and no
  influence to the warning lamp state(macro DEH_GET_LAMP_INFO
  (variable DEH_stWarnLamp_mu8)

  KWP2000:
  --------
  The function DEH_ReadIdentifiedEvents(..) and DEH_GetNumberOfIdentEvents(..)
  read out the events with priority 9 only in diagnosis session
  DEH_ENTW_DIAG_SESSION (0x86 => developer session) in all other diagnosis session
  this events will be ignored.

  UDS:
  ----
  The function DEH_ReadDTCByStatus(..) and DEH_ReadDTCExtDataRecord(..)
  read out the events with priority 9 only in diagnosis session
  DEH_ENTW_DIAG_SESSION (0x4F => developer session) in all other diagnosis session
  this events will be ignored.
==============================================================================

V1.2.0
======

KWP2000
-------
  1) new Readyness Bit Handling to fullfill OBD requirements
  ----------------------------------------------------------
  The readiness bit is permanent set to tested (value 0) after
  the first received test report for an special DTC. The service
  DEH_ClearDiagnosticInformation(clear error memory) reset all
  readiness bits to NOT tested (value 1).

     - I)   DEH_StoreStatusOfDTCInfos()
              function to inform the DEH about system shutt off and to store the
              internal Readiness Bit into a EEPROM Byte - array
     - II)  APL_DEH_WriteStatusOfDTC(..)
              function from application for the DEH to write readiness information
              status bytes in the EEPROM byte array
     - III) APL_DEH_ReadStatusOfDTC(..)
              function from application for the DEH to read readiness information
              status bytes from the EEPROM byte array

UDS/KWP2000
-----------
  2) new unlearn counter handling if no valid unlearn counter available
  ---------------------------------------------------------------------
  - store 0xFF as valid value to the error memory if the application delivered this value
  - NO unlearn of a PASSIVE error with unlearn counter 0xFF in the error memory

  3) DEH_E_INIT for all SDS service function if DEH NOT initialized

UDS
---
  4) function DEH_ReadDTCExtDataRecord
  ------------------------------------
  - return value DEH_OK, if DTC NOT stored
  - return value numOfBytes = 0, if DTC NOT stored

  5) ControllDTC and Pending Bits
  -------------------------------
  - NO support of the Pending Status Bits after ControlDTC with 
    parameter DTC_OFF (0x02)
    
  6) DEH_ReadDTCExtDataRecord new data layout
  -------------------------------------------
  - no central aging counter included in the service answer
================================================================================
V1.1.3
1) new feature -> deactivate all blocked DTCs after diagnostic session change
                  with function DEH_SetDiagnosticSession(..)

2) new feature -> Control DTC NOT possible if UDS support and diagnostic session
                  is OBDII&VWDefaultDiagnosticSession (0x01) in function 
                  DEH_ControlDTCSetting(..)

3) bugfix      -> change logical reaction for the parameter DEH_SET_DTC_ON and 
                  DEH_SET_DTC_OFF within function DEH_ControlDTCSetting(..)

4) bugfix      -> variables DEH_stCANEventBit_mb/DEH_stWarnLamp_mu8 NOT static
                  
5) bugfix      -> change Freeze Frame Structure for option without reading
                  AddFreezeFrames 
6) feature     -> change datatypes for STOFDTC_STORAGE_BLOCK_SIZE to uint16_t
================================================================================
V1.1.2  
1) new Test Failed Last State Specification
  - Test Failed Last State is NOT debounced error state which are stored into 
    the EEPROM for next driving cycle
    
2) new include structure

3) aprove CAN-Event State Bit and Warning Lamp State after aging

4) read FREEZE FRAMES if error entry with activated Freeze Frame Update Bit 
    - for error with Event Debounced 1 
      (and Freeze Frame Update Period is not reached)
=================================================================================  

V1.1.1   First Revision with full UDS-Support 
         ===================================
if UDS and OR OBD supported (dependant on defines):::

1) new application function to read and store the StatusOfDTC flags in buffer
   from the application
    - APL_DEH_ReadStatusOfDTC()
    - APL_DEH_WriteStatusOfDTC()

2) new function to read back all StatusOfTDC flags to application buffer if the
   application going to sleep
    - DEH_StoreStatusOfDTCInfos()

3) update funciton APL_DEH_ReadAddFF() with new data defines 

4) support APL_DEH_ReadDTCSnapshotRecord() to read Snap shot data from application

5) inform the application for DEH state canges APL_DEH_SnapShotDatenInit()
   
6) extend the service DEH_ReadDTCExtDataRecord() with Record Numbers::
  - 0x70-0x7F : Extended Record Datas
  - 0xFF      : AllDTCExtendedDataRecords
============================================================================*/

/* ========================================================================== */
/* Project Includes                                                           */
/* ========================================================================== */

#include "deh.h"
#include "DEH_DTC_CFG.h"
#include "OSEK_HostTask_H1.h"
#include "CSHDL.h"
#include "EEPROM_LAYOUT_CFG.h"
#include "ccl_inc.h"
#include "TRACE.h"
#include "deh_cfg.id"

/* ========================================================================== */
/* Global Variables                                                           */
/* ========================================================================== */
Union_EEPEventDataBlock EE_EventMemoryBlockArray;

/* =========== EVENT DATAS ================================================== */
const tDEH_EventPathParameter DEH_EventPathParameter[DEH_MAX_NUMBER_OF_EVENTPATHS];

/* =========== FREEZE FRAME TABLE =========================================== */

#ifndef  DEH_TEST
#if (DEH_MAX_NUMBER_FF>0)
  uint8_t DEH_FreezeFrameTable[DEH_MAX_NUMBER_FF_IDX][DEH_MAX_NUMBER_FF]; 
#endif
#endif

#define DEH_TIME_DEBOUNCED               0x00
#define DEH_EVENT_DEBOUNCED              0x01

#define DEH_UNLEARN_NOT_LOCKED           0x00
#define DEH_UNLEARN_LOCKED               0x02

#define DEH_STATE_CHANGE_REPORT_ACTIVE   0x00
#define DEH_STATE_CHANGE_REPORT_DEACTIVE 0x04

#define DEH_DELETE_EVENT_POSSIBLE        0x00
#define DEH_DELETE_EVENT_IMPOSSIBLE      0x08

#define MAX_EEPROM_WRITE_RETRIES_DEH     1000 //used for Diagnose 2E Write E2P direct, numbers of retries to write in EEPROM
static TriStateType_DEH_EE  SucessfulRegisterDataToEEprom = DEH_EE_NOTHING_TODO;
static uint16_t _APL_DEH_u16EEpromWriting_W_Control= 0;

static uint8_t EE_UnlearnCouner_u8 = 0xFF;

/* -------------------------------------------------------------------------- */
/* Example for an event dataset with two events                               */
/* -------------------------------------------------------------------------- */
/*  desc:              "event 1";                                                      */   
/*  DTC:               0x1234;                                                         */
/*  EventParameter:    0b000; -> time debounced                                        */
/*  EventSymPrio:      0x12;  -> symptom = 2; priority = 1;                            */
/*  QualEvent:         2.0;   -> 2 seconds (100 ms cyclic task -> 20 dez => 14 hex)    */
/*  DeQualEvent:       1.0;   -> 2 seconds (100 ms cyclic task -> 10 dez => 0A hex)    */
/*  LampParameter:     0b00000011; -> event is connected to lamp 0; flashing is active */
/*  IndexFFrameTable:  0;          -> freeze frames from line 0 in freeze frame table  */

/*  desc:              "event 2";                                                       */   
/*  DTC:               0x5678;                                                          */
/*  EventParameter:    0b001; -> event debounced                                        */
/*  EventSymPrio:      0x34;  -> symptom = 4; priority = 3;                             */
/*  QualEvent:         7.0;   -> 07 events for defect detection                         */
/*  DeQualEvent:       3.0;   -> 03 events to change to PASSIVE state                   */
/*  LampParameter:     0b00001000; -> event is connected to lamp 1; flashing NOT active */
/*  IndexFFrameTable:  0xFF        -> read no freeze frames                             */

/* further conditions:                                                        */
/*----------------------------------------------------------------------------*/
/* I)  freeze frame table with one line                                       */
/* II) only one freeze frame (only standard FF)                               */

/* #define DEH_MAX_NUMBER_OF_EVENTPATHS 2                                     */
/* #define DEH_MAX_NUMBER_FF            2                                     */
/* #define DEH_MAX_NUMBER_FF_IDX        1                                     */

uint8_t DEH_FreezeFrameTable[DEH_MAX_NUMBER_FF_IDX][DEH_MAX_NUMBER_FF] =
                                                          {STD_FF_NUMBER};

const tDEH_EventPathParameter DEH_EventPathParameter[DEH_MAX_NUMBER_OF_EVENTPATHS]=
{
    /****************************************************************************/
    /*       DEH_EVENT_0.DTC                                                    */
    {
    0xC12000, /* DTC_C12000_BUS_OFF_FEHLER  */
    /*       DEH_EVENT_0.EventParameter                                         */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_0.EventSymPrio                                           */
    0x20,      /* UDS  */
    /*       DEH_EVENT_0.QualEvent                                              */
    0x0002,
    /*       DEH_EVENT_0.DeQualEvent                                            */
    0x0001,    /* No Dequalification  */
    /*       DEH_EVENT_0.LampParameter                                          */
    0x00,      /* Lamp1 with no blinking */
    /*       DEH_EVENT_0.IndexFFrameTable                                       */
    0x00     /* only 1 freezeframetabel-line -> 0x00 */
    },
    /****************************************************************************/
    /*       DEH_EVENT_1.DTC                                                    */
    {0xC12001, /* DTC_C12001_EINDRAHT_FEHLER */
    /*       DEH_EVENT_1.EventParameter                                         */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_1.EventSymPrio                                           */
    0x20,      /* UDS  */
    /*       DEH_EVENT_1.QualEvent                                              */
    0x0014,
    /*       DEH_EVENT_1.DeQualEvent                                            */
    0x0001,
    /*       DEH_EVENT_1.LampParameter                                          */
    0x00,
    /*       DEH_EVENT_1.IndexFFrameTable                                       */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_2.DTC                                                    */
    {0xC12002, /* DTC_C12002_TIMEOUT_MOTORSTEUERUNG */
    /*       DEH_EVENT_2.EventParameter                                         */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_2.EventSymPrio                                           */
    0x60,      /* UDS  */
    /*       DEH_EVENT_2.QualEvent                                              */
    0x0001,
    /*       DEH_EVENT_2.DeQualEvent                                            */
    0x0001,
    /*       DEH_EVENT_2.LampParameter                                          */
    0x00,
    /*       DEH_EVENT_2.IndexFFrameTable                                       */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_3.DTC                                                    */
    {0xC12004, /* DTC_C12004_TIMEOUT_GERTIEBESTEUERUNG */
    /*       DEH_EVENT_3.EventParameter                                         */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_3.EventSymPrio                                           */
    0x60,      /* UDS  */
    /*       DEH_EVENT_3.QualEvent                                              */
    0x0001,
    /*       DEH_EVENT_3.DeQualEvent                                            */
    0x0001,
    /*       DEH_EVENT_3.LampParameter                                          */
    0x00,
    /*       DEH_EVENT_3.IndexFFrameTable                                       */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_4.DTC                                                    */
    {0xC12007, /* DTC_C12007_TIMEOUT_PSM */
    /*       DEH_EVENT_4.EventParameter                                         */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_4.EventSymPrio                                           */
    0x60,      /* UDS  */
    /*       DEH_EVENT_4.QualEvent                                              */
    0x0001,
    /*       DEH_EVENT_4.DeQualEvent                                            */
    0x0001,
    /*       DEH_EVENT_4.LampParameter                                          */
    0x00,
    /*       DEH_EVENT_4.IndexFFrameTable                                       */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_5.DTC                                                    */
    {0xC12008, /* DTC_C12008_TIMEOUT_ELEKTRISCHE_PARKBREMSE */
    /*       DEH_EVENT_5.EventParameter                                         */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_5.EventSymPrio                                           */
    0x60,      /* UDS  */
    /*       DEH_EVENT_5.QualEvent                                              */
    0x0001,
    /*       DEH_EVENT_5.DeQualEvent                                            */
    0x0001,
    /*       DEH_EVENT_5.LampParameter                                          */
    0x00,
    /*       DEH_EVENT_5.IndexFFrameTable                                       */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_6.DTC                                                    */
    {0xC1200B, /* DTC_C1200B_TIMEOUT_LWS */
    /*       DEH_EVENT_6.EventParameter                                         */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_6.EventSymPrio                                           */
    0x60,      /* UDS  */
    /*       DEH_EVENT_6.QualEvent                                              */
    0x0001,
    /*       DEH_EVENT_6.DeQualEvent                                            */
    0x0001,
    /*       DEH_EVENT_6.LampParameter                                          */
    0x00,
    /*       DEH_EVENT_6.IndexFFrameTable                                       */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_7.DTC                                                    */
    {0xC1200C, /* DTC_C1200C_TIMEOUT_PASM */
    /*       DEH_EVENT_7.EventParameter                                         */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_7.EventSymPrio                                           */
    0x60,      /* UDS  */
    /*       DEH_EVENT_7.QualEvent                                              */
    0x0001,
    /*       DEH_EVENT_7.DeQualEvent                                            */
    0x0001,
    /*       DEH_EVENT_7.LampParameter                                          */
    0x00,
    /*       DEH_EVENT_7.IndexFFrameTable                                       */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_8.DTC                                                    */
    {0xC1200F, /* DTC_C1200F_TIMEOUT_SMLS */
    /*       DEH_EVENT_8.EventParameter                                         */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_8.EventSymPrio                                           */
    0x60,      /* UDS  */
    /*       DEH_EVENT_8.QualEvent                                              */
    0x0001,
    /*       DEH_EVENT_8.DeQualEvent                                            */
    0x0001,
    /*       DEH_EVENT_8.LampParameter                                          */
    0x00,
    /*       DEH_EVENT_8.IndexFFrameTable                                       */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_9.DTC                                                    */
    {0xC12013, /* DTC_C12013_TIMEOUT_TUERSTEUERGERAET_FAHRER */
    /*       DEH_EVENT_9.EventParameter                                         */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_9.EventSymPrio                                           */
    0x60,      /* UDS  */
    /*       DEH_EVENT_9.QualEvent                                              */
    0x0001,
    /*       DEH_EVENT_9.DeQualEvent                                            */
    0x0001,
    /*       DEH_EVENT_9.LampParameter                                          */
    0x00,
    /*       DEH_EVENT_9.IndexFFrameTable                                       */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_10.DTC                                                   */
    {0xC12015, /* DTC_C12015_TIMEOUT_RDK */
    /*       DEH_EVENT_10.EventParameter                                        */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_10.EventSymPrio                                          */
    0x60,      /* UDS  */
    /*       DEH_EVENT_10.QualEvent                                             */
    0x0001,
    /*       DEH_EVENT_10.DeQualEvent                                           */
    0x0001,
    /*       DEH_EVENT_10.LampParameter                                         */
    0x00,
    /*       DEH_EVENT_10.IndexFFrameTable                                      */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_11.DTC                                                   */
    {0xC12016, /* DTC_C12016_TIMEOUT_BCM_VORNE */
    /*       DEH_EVENT_11.EventParameter                                        */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_11.EventSymPrio                                          */
    0x60,      /* UDS  */
    /*       DEH_EVENT_11.QualEvent                                             */
    0x0001,
    /*       DEH_EVENT_11.DeQualEvent                                           */
    0x0001,
    /*       DEH_EVENT_11.LampParameter                                         */
    0x00,
    /*       DEH_EVENT_11.IndexFFrameTable                                      */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_12.DTC                                                   */
    {0xC12017, /* DTC_C12017_TIMEOUT_BCM_HINTEN */
    /*       DEH_EVENT_12.EventParameter                                        */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_12.EventSymPrio                                          */
    0x60,      /* UDS  */
    /*       DEH_EVENT_12.QualEvent                                             */
    0x0001,
    /*       DEH_EVENT_12.DeQualEvent                                           */
    0x0001,
    /*       DEH_EVENT_12.LampParameter                                         */
    0x00,
    /*       DEH_EVENT_12.IndexFFrameTable                                      */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_13.DTC                                                   */
    {0xC12018, /* DTC_C12018_TIMEOUT_KOMBIINSTRUMENT */
    /*       DEH_EVENT_13.EventParameter                                        */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_13.EventSymPrio                                          */
    0x60,      /* UDS  */
    /*       DEH_EVENT_13.QualEvent                                             */
    0x0001,
    /*       DEH_EVENT_13.DeQualEvent                                           */
    0x0001,
    /*       DEH_EVENT_13.LampParameter                                         */
    0x00,
    /*       DEH_EVENT_13.IndexFFrameTable                                      */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_14.DTC                                                   */
    {0xC12019, /* DTC_C12019_TIMEOUT_BEDIEN_UND_KLIMAREGELUNG */
    /*       DEH_EVENT_14.EventParameter                                        */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_14.EventSymPrio                                          */
    0x60,      /* UDS  */
    /*       DEH_EVENT_14.QualEvent                                             */
    0x0001,
    /*       DEH_EVENT_14.DeQualEvent                                           */
    0x0001,
    /*       DEH_EVENT_14.LampParameter                                         */
    0x00,
    /*       DEH_EVENT_14.IndexFFrameTable                                      */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_15.DTC                                                   */
    {0xC1201F, /* DTC_C1201F_TIMEOUT_CAN_CAN_GATEWAY */
    /*       DEH_EVENT_15.EventParameter                                        */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_15.EventSymPrio                                          */
    0x60,      /* UDS  */
    /*       DEH_EVENT_15.QualEvent                                             */
    0x0001,
    /*       DEH_EVENT_15.DeQualEvent                                           */
    0x0001,
    /*       DEH_EVENT_15.LampParameter                                         */
    0x00,
    /*       DEH_EVENT_15.IndexFFrameTable                                      */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_16.DTC                                                   */
    {0xC12037, /* DTC_C12037_TIMEOUT_ON_BOARD_LADER */
    /*       DEH_EVENT_16.EventParameter                                        */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_16.EventSymPrio                                          */
    0x60,      /* UDS  */
    /*       DEH_EVENT_16.QualEvent                                             */
    0x0001,
    /*       DEH_EVENT_16.DeQualEvent                                           */
    0x0001,
    /*       DEH_EVENT_16.LampParameter                                         */
    0x00,
    /*       DEH_EVENT_16.IndexFFrameTable                                      */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_17.DTC                                                   */
    {0xC12039, /* DTC_C12039_TIMEOUT_LIFT_VA */
    /*       DEH_EVENT_17.EventParameter                                        */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_17.EventSymPrio                                          */
    0x60,      /* UDS  */
    /*       DEH_EVENT_17.QualEvent                                             */
    0x0001,
    /*       DEH_EVENT_17.DeQualEvent                                           */
    0x0001,
    /*       DEH_EVENT_17.LampParameter                                         */
    0x00,
    /*       DEH_EVENT_17.IndexFFrameTable                                      */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_18.DTC                                                   */
    {0xC1207F, /* DTC_C1207F_TIMEOUT_MITTELKONSOLE */
    /*       DEH_EVENT_18.EventParameter                                        */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_18.EventSymPrio                                          */
    0x60,      /* UDS  */
    /*       DEH_EVENT_18.QualEvent                                             */
    0x0001,
    /*       DEH_EVENT_18.DeQualEvent                                           */
    0x0001,
    /*       DEH_EVENT_18.LampParameter                                         */
    0x00,
    /*       DEH_EVENT_18.IndexFFrameTable                                      */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_19.DTC                                                   */
    {0xC12080, /* DTC_C12080_SIGNALFEHLER_MOTORSTEUERUNG */
    /*       DEH_EVENT_19.EventParameter                                        */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_19.EventSymPrio                                          */
    0x60,      /* UDS  */
    /*       DEH_EVENT_19.QualEvent                                             */
    0x0001,
    /*       DEH_EVENT_19.DeQualEvent                                           */
    0x0001,
    /*       DEH_EVENT_19.LampParameter                                         */
    0x00,
    /*       DEH_EVENT_19.IndexFFrameTable                                      */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_20.DTC                                                   */
    {0xC12082, /* DTC_C12082_SIGNALFEHLER_GETRIEBESTEUERUNG */
    /*       DEH_EVENT_20.EventParameter                                        */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_20.EventSymPrio                                          */
    0x60,      /* UDS  */
    /*       DEH_EVENT_20.QualEvent                                             */
    0x0001,
    /*       DEH_EVENT_20.DeQualEvent                                           */
    0x0001,
    /*       DEH_EVENT_20.LampParameter                                         */
    0x00,
    /*       DEH_EVENT_20.IndexFFrameTable                                      */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_21.DTC                                                   */
    {0xC12085, /* DTC_C12085_SIGNALFEHLER_PSM */
    /*       DEH_EVENT_21.EventParameter                                        */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_21.EventSymPrio                                          */
    0x60,      /* UDS  */
    /*       DEH_EVENT_21.QualEvent                                             */
    0x0001,
    /*       DEH_EVENT_21.DeQualEvent                                           */
    0x0001,
    /*       DEH_EVENT_21.LampParameter                                         */
    0x00,
    /*       DEH_EVENT_21.IndexFFrameTable                                      */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_22.DTC                                                   */
    {0xC12089, /* DTC_C12089_SIGNALFEHLER_LWS */
    /*       DEH_EVENT_22.EventParameter                                        */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_22.EventSymPrio                                          */
    0x60,      /* UDS  */
    /*       DEH_EVENT_22.QualEvent                                             */
    0x0001,
    /*       DEH_EVENT_22.DeQualEvent                                           */
    0x0001,
    /*       DEH_EVENT_22.LampParameter                                         */
    0x00,
    /*       DEH_EVENT_22.IndexFFrameTable                                      */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_23.DTC                                                   */
    {0xC12096, /* DTC_C12096_SIGNALFEHLER_KOMBIINSTRUMENT */
    /*       DEH_EVENT_23.EventParameter                                        */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_23.EventSymPrio                                          */
    0x60,      /* UDS  */
    /*       DEH_EVENT_23.QualEvent                                             */
    0x0001,
    /*       DEH_EVENT_23.DeQualEvent                                           */
    0x0001,
    /*       DEH_EVENT_23.LampParameter                                         */
    0x00,
    /*       DEH_EVENT_23.IndexFFrameTable                                      */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_24.DTC                                                   */
    {0xC12097, /* DTC_C12097_SIGNALFEHLER_BEDIEN_UND_KLIMAREGELUNG */
    /*       DEH_EVENT_24.EventParameter                                        */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_24.EventSymPrio                                          */
    0x60,      /* UDS  */
    /*       DEH_EVENT_24.QualEvent                                             */
    0x0001,
    /*       DEH_EVENT_24.DeQualEvent                                           */
    0x0001,
    /*       DEH_EVENT_24.LampParameter                                         */
    0x00,
    /*       DEH_EVENT_24.IndexFFrameTable                                      */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_25.DTC                                                   */
    {0xC120AF, /* DTC_C120AF_SIGNALFEHLER_ON_BOARD_LADER */
    /*       DEH_EVENT_25.EventParameter                                        */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_25.EventSymPrio                                          */
    0x60,      /* UDS  */
    /*       DEH_EVENT_25.QualEvent                                             */
    0x0001,
    /*       DEH_EVENT_25.DeQualEvent                                           */
    0x0001,
    /*       DEH_EVENT_25.LampParameter                                         */
    0x00,
    /*       DEH_EVENT_25.IndexFFrameTable                                      */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_26.DTC                                                   */
    {0xC120B1, /* DTC_C120B1_SIGNALFEHLER_LIFT_VA */
    /*       DEH_EVENT_26.EventParameter                                        */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_26.EventSymPrio                                          */
    0x60,      /* UDS  */
    /*       DEH_EVENT_26.QualEvent                                             */
    0x0001,
    /*       DEH_EVENT_26.DeQualEvent                                           */
    0x0001,
    /*       DEH_EVENT_26.LampParameter                                         */
    0x00,
    /*       DEH_EVENT_26.IndexFFrameTable                                      */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_27.DTC                                                   */
    {0xC120B5, /* DTC_C120B5_SIGNALFEHLER_MITTELKONSOLE */
    /*       DEH_EVENT_27.EventParameter                                        */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_27.EventSymPrio                                          */
    0x60,      /* UDS  */
    /*       DEH_EVENT_27.QualEvent                                             */
    0x0001,
    /*       DEH_EVENT_27.DeQualEvent                                           */
    0x0001,
    /*       DEH_EVENT_27.LampParameter                                         */
    0x00,
    /*       DEH_EVENT_27.IndexFFrameTable                                      */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_28.DTC                                                    */
    {0xC11000,  /* DTC_C11000_UNTERSPANNUNG */
    /*       DEH_EVENT_28.EventParameter                                         */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_28.EventSymPrio                                           */
    0x30,      /* UDS  */
    /*       DEH_EVENT_28.QualEvent                                              */
    0x1F,
    /*       DEH_EVENT_28.DeQualEvent                                            */
    0x1F,
    /*       DEH_EVENT_28.LampParameter                                          */
    0x00,
    /*       DEH_EVENT_28.IndexFFrameTable                                       */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_29.DTC                                                    */
    {0xC11001,  /* DTC_C11001_UEBERSPANNUNG */
    /*       DEH_EVENT_29.EventParameter                                        */
    DEH_EVENT_DEBOUNCED | DEH_UNLEARN_NOT_LOCKED |
    DEH_STATE_CHANGE_REPORT_DEACTIVE | DEH_DELETE_EVENT_POSSIBLE,
    /*       DEH_EVENT_29.EventSymPrio                                           */
    0x30,      /* UDS  */
    /*       DEH_EVENT_29.QualEvent                                              */
    0x1F,
    /*       DEH_EVENT_29.DeQualEvent                                            */
    0x1F,
    /*       DEH_EVENT_29.LampParameter                                          */
    0x00,
    /*       DEH_EVENT_29.IndexFFrameTable                                       */
    0x00
    },
    /****************************************************************************/
    /*       DEH_EVENT_11.DTC                                                    */
    {0xC11002,  /* DTC_C11002_UNTERTEMPERATUR */
    /*       DEH_EVENT_11.EventParameter                                         */
    0x01,
    /*       DEH_EVENT_11.EventSymPrio                                           */
    0x30,      /* UDS  */
    /*       DEH_EVENT_11.QualEvent                                              */
    0x001F,
    /*       DEH_EVENT_11.DeQualEvent                                            */
    0x001F,
    /*       DEH_EVENT_11.LampParameter                                          */
    0x00,
    /*       DEH_EVENT_11.IndexFFrameTable                                       */
    0x00},
    /****************************************************************************/
    /*       DEH_EVENT_11.DTC                                                    */
    {0xC11003,  /* DTC_C11003_UEBERTEMPERATUR */
    /*       DEH_EVENT_11.EventParameter                                         */
    0x01,
    /*       DEH_EVENT_11.EventSymPrio                                           */
    0x30,      /* UDS  */
    /*       DEH_EVENT_11.QualEvent                                              */
    0x001F,
    /*       DEH_EVENT_11.DeQualEvent                                            */
    0x001F,
    /*       DEH_EVENT_11.LampParameter                                          */
    0x00,
    /*       DEH_EVENT_11.IndexFFrameTable                                       */
    0x00}
    /****************************************************************************/
};

/* ========================================================================= */


/* ========================================================================== */
/* Prototypes local functions                                                 */
/* ========================================================================== */
tDEH_Return APL_DEH_EEPWriteEventData ( uint16_t  BlockPosition_u16, uint16_t BlockSize_u16, uint8_t *Buffer_u8);
tDEH_Return APL_DEH_EEPReadEventData  ( uint16_t  BlockPosition_u16, uint16_t BlockSize_u16, uint8_t *Buffer_u8);
tDEH_Return APL_DEH_ReadStdFF(tDEH_StdFreezeFrame *pStdDestination);

#if defined(DEH_SUP_KWP2000)
  #ifdef DEH_READ_ADD_FF 
    tDEH_Return APL_DEH_ReadAddFF(tDEH_FreezeFrameNumber FF_Number, tDEH_AddFreezeFrame *pAddDestination);
  #endif
#elif defined(DEH_SUP_UDS)
  #ifdef DEH_READ_ADD_FF 
    tDEH_Return APL_DEH_ReadAddFF(tDEH_FreezeFrameNumber FF_Number, uint8_t BuffSize, uint8_t *pNumOfBytes, uint8_t *pAddFFrame);
  #endif
  #ifdef DEH_SUP_SNAP_SHOT_DATA
    tDEH_Return APL_DEH_ReadDTCSnapshotRecord(tDEH_DTC DTC, uint16_t BuffSize_u16, uint16_t *pNumOfBytes_u16, uint8_t *pDestBuffer);
    void        APL_DEH_SnapShotDatenInit(uint8_t mode);
  #endif
  tDEH_Return APL_DEH_ReadStatusOfDTC(uint16_t BlockSize_u16, uint8_t *Buffer_u8);
  tDEH_Return APL_DEH_WriteStatusOfDTC(uint16_t BlockSize_u16, uint8_t *Buffer_u8);

#endif
uint8_t     APL_DEH_ReadUnlearnCounter(void);


/* ========================================================================== */

/* ========================================================================== */

  /* --------------------------------------------------------------------- */
  /* if the flag DEH_SUP_DETECT_CHANGE_EV_STATE == TRUE then should be     */
  /* all event states cahnges reportetd via this function.                 */
  /* The application is responsible for the relevant actions and responses */
  /* The DEH user is responsible for the content of this function.         */
  /* Here is only the empty function body for programming purpose          */
  /* --------------------------------------------------------------------- */

#ifndef  DEH_TEST
#ifdef DEH_SUP_DETECT_CHANGE_EV_STATE
/* ============================================================================
function name    :   APL_DEH_ReportChgEventState(tDEH_EventNumber EventNum_uT,
                                                 uint8_t          state_u8)
input parameter  :   tDEH_EventNumber EventNum_uT : current event number
                     uint8_t          state_u8    : current event state
output parameter :   
globals          :   
return value     :   no
description      :   Callback which is called if a event state has been changed 
------------------------------------------------------------------------------
date        short    change description
------------------------------------------------------------------------------
08.11.03    GIGE    built base version 
============================================================================ */
  void APL_DEH_ReportChgEventState(tDEH_EventNumber EventNum_uT, uint8_t state_u8)
  {

    switch (EventNum_uT)
    {
      default:
      break;
    }
    return;
  }

#endif
#endif


/* ============================================================================
function name    :   APL_DEH_SnapShotDatenInit()
input parameter  :   mode  : current special mode of DEH
output parameter :   
globals          :   
return value     :   no
description      :   Function to inform the application about special DEH states 
------------------------------------------------------------------------------
date        short    change description
------------------------------------------------------------------------------
27.11.06    GIGE    built base version 
============================================================================ */
#ifdef DEH_SUP_SNAP_SHOT_DATA
void APL_DEH_SnapShotDatenInit(uint8_t mode)
{
    /* ==================================================================== */
    /* DEH is started with function DEH_Init()                              */
    /* ==================================================================== */
    if (mode == DEH_INIT)
  {
                
  }
    /* ==================================================================== */
    /* Event Memory is cleared with function DEH_ClearDiagnsotciInformation */
    /* ==================================================================== */
  else if (mode == DEH_CLEAR_EVENT_MEMORY)
  {
  
  }
return;
}
#endif


/* ============================================================================
function name    :   DEH_InitEEPROM()
input parameter  :   
output parameter :   
globals          :   
return value     :   no
description      :   Function for initializing the DTC EEPROM area once 
------------------------------------------------------------------------------
date        short    change description
------------------------------------------------------------------------------
27.11.06    GIGE    built base version 
============================================================================ */

/**--------------------------------------------------------------------------*
* Function:       InitDEHFaultData                                           *
* Description:    Load the Faults from the EEprom                            *
* Parameters:     void                                                       *
* Returns:        void                                                       *
*                                                                            *
*---------------------------------------------------------------------------**/
void InitDEHFaultData(void)
{
	EEDeviceControlBlockType *pEEDcb = (EEDeviceControlBlockType *)getEEHostControl();
	CommonResponseCodeType retVal_E2P = COMMON_RSP_OK;

	/* first UnlearnCounter from RAM Mirror */
	(void)EEPROM_enGetSingleByteFromRamMirror(&EE_UnlearnCouner_u8, EEPROM_LAYOUT_ENUM_DEH_UnclearCounter);
    DEBUG_VALUE1(DEH_SWI_TRC, MOD_DEH, "Read DEH_UnlearnCounter from eeprom = %d",EE_UnlearnCouner_u8);
    /* DEH manager of VW standard software init event memory block with data  - from EEProm */
	retVal_E2P = EEPROM_sfRead(pEEDcb,
				PAG_DB_EE_ADDRESS_DTCs,
				(Uint8Type *)EE_EventMemoryBlockArray.AllString,
				PAG_DB_EE_ADDRESS_DTCs_LEN);
	if(retVal_E2P != COMMON_RSP_OK)
	{
		DEBUG_TEXT(DEH_SWI_ERR, MOD_DEH,"E2P Read FAIL");
		DEH_InitEEPROM();
	}
    return;
}

void DEH_InitEEPROM(void)     /* damit wird der DTC-EEPROM-Bereich einmalig mit 0xFF vorbelegt */
{
    DEBUG_TEXT(DEH_SWI_TRC, MOD_DEH, "DEH_InitEEPROM");
    (void)memcpy((void *)EE_EventMemoryBlockArray.AllString, (const void *)0xFF, (EMB_BLOCK_SIZE * DEH_MAX_NUMBER_EV_MEM));
}

/*============================================================================
function name    :  APL_DEH_EEPReadEventData()
input parameter  :  BlockPosition : read position in Byte-Array 
                    BlockSize     : size of bytes to read from memeory 
                    Buffer        : pointer to write all  read values

output parameter :   -
globals          :   
return value     :  tDEH_Return
description      :  Function to read stored information in the event memory 
                    buffer. The Caller informs the function about the position 
                    where the needed data are located. From this position will 
                    be read the wanted bytes (blocksize) into the buffer.
------------------------------------------------------------------------------
date        short     change description
------------------------------------------------------------------------------
08.11.03    GIGE    built base version 

============================================================================*/
tDEH_Return APL_DEH_EEPReadEventData ( uint16_t  BlockPosition_u16, uint16_t BlockSize_u16, uint8_t *Buffer_u8)
{
    tDEH_Return retVal = DEH_OK;

    (void)memcpy(Buffer_u8, &EE_EventMemoryBlockArray.AllString[BlockPosition_u16],BlockSize_u16);
    
    return (retVal);
} /* end function APL_DEH_EEPReadEventData */


/*============================================================================
function name    :  APL_DEH_EEPWriteEventData()
input parameter  :  BlockPosition : write position in Byte-Array 
                    BlockSize     : size of bytes to read from memeory 
                    Buffer        : pointer where the source bytes are standing.

output parameter :   -
globals          :   
return value     :  tDEH_Return
description      :  Function to write new information in the event memory 
                    buffer. The Caller informs the function about the position 
                    where the needed data are located. From this position will 
                    be read the wanted bytes (blocksize) into the event memory.
------------------------------------------------------------------------------
date        short     change description
------------------------------------------------------------------------------
08.11.03    GIGE    built base version 

============================================================================*/
tDEH_Return APL_DEH_EEPWriteEventData( uint16_t  BlockPosition_u16, uint16_t BlockSize_u16, uint8_t *Buffer_u8)
{
	#define DTC_Nbr     ((Buffer_u8[1] << 8) + Buffer_u8[0])
    #define DTC_Status  (Buffer_u8[2] & 1)
	tDEH_Return retVal = DEH_OK;
	CommonResponseCodeType rC = COMMON_RSP_OK;
	EEDeviceControlBlockType    *pEEDcb = (EEDeviceControlBlockType *)getEEHostControl();

	DEBUG_VALUE2(DEH_SWI_DBG, MOD_DEH, "Set Failure Memory at Position: %d,Size %d",BlockPosition_u16,BlockSize_u16);
	(void)memcpy(&EE_EventMemoryBlockArray.AllString[BlockPosition_u16],Buffer_u8,BlockSize_u16);
	DEBUG_VALUE2(DEH_SWI_TRC, MOD_DEH, "Internal DTC-NBR %d, Status %d",DTC_Nbr, DTC_Status);
	/* (rC_E2P == COMMON_RSP_OK) - successful register to write E2P but write is not complete done !! */
	/* Complete DEH Ram Array write to eeprom 130 Bytes                                               */
	rC = EEPROM_LAYOUT_rcWrite(pEEDcb,
                                   PAG_DB_EE_ADDRESS_DTCs,
                                   (uint8_t *) EE_EventMemoryBlockArray.AllString,
                                   PAG_DB_EE_ADDRESS_DTCs_LEN,
                                   NULL);
	if (COMMON_RSP_OK == rC)
	{
		SucessfulRegisterDataToEEprom = DEH_EE_REGISTER;
		_APL_DEH_u16EEpromWriting_W_Control= 0;
		return (retVal);
	}
	else
	{
		DEBUG_TEXT(DEH_SWI_TRC, MOD_DEH, "EEPROM Write for DEH is busy for Error Memory Entries");
		/* DEH not handle a complete retry mechanisms in all cases to write data to eeprom          */
		/* Set flag that data from DEH was not register to write data to eeprom                     */
		/* The data of DEH is now write outside the DEH context to eeprom if above write was not OK */
		SucessfulRegisterDataToEEprom = DEH_EE_NOT_REGISTER;
		return (retVal);
	}




} /* end function APL_DEH_EEPWriteEventData */

/*----------------------------------------------------------------------------*/
/* Function    :  APL_DEH_EEPWriteHandleRetries                               */
/**
    \brief      E2P handle retry mechanism for DEH outside DEH context

    \param      void

	\return

*/
/*----------------------------------------------------------------------------*/
void APL_DEH_EEPWriteHandleRetries(void)
{
	CommonResponseCodeType rC = COMMON_RSP_OK;
	EEDeviceControlBlockType    *pEEDcb = (EEDeviceControlBlockType *)getEEHostControl();

	if(DEH_EE_NOT_REGISTER == SucessfulRegisterDataToEEprom)
	{
		/* (rC_E2P == COMMON_RSP_OK) - successful register to write E2P but write is not complete done !! */
		/* Complete DEH Ram Array write to eeprom  130 Bytes                                             */
		rC = EEPROM_LAYOUT_rcWrite(pEEDcb,
                                   PAG_DB_EE_ADDRESS_DTCs,
                                   (uint8_t *) EE_EventMemoryBlockArray.AllString,
                                   PAG_DB_EE_ADDRESS_DTCs_LEN,
                                   NULL);
		if (COMMON_RSP_OK == rC)
		{
			SucessfulRegisterDataToEEprom = DEH_EE_REGISTER;
			_APL_DEH_u16EEpromWriting_W_Control= 0;
			DEBUG_TEXT(DEH_SWI_TRC, MOD_DEH, "EEPROM DEH Write register was OK in retry part");
		}
		else
		{
			_APL_DEH_u16EEpromWriting_W_Control++;
			SucessfulRegisterDataToEEprom = DEH_EE_NOT_REGISTER;
			DEBUG_VALUE1(DEH_SWI_TRC, MOD_DEH, "EEPROM DEH Write not register. Try: %d",_APL_DEH_u16EEpromWriting_W_Control);

		}
		if (MAX_EEPROM_WRITE_RETRIES_DEH < _APL_DEH_u16EEpromWriting_W_Control)
		{
			SucessfulRegisterDataToEEprom = DEH_EE_NOTHING_TODO;
			_APL_DEH_u16EEpromWriting_W_Control= 0;
			DEBUG_TEXT(DEH_SWI_TRC, MOD_DEH, "MAX EEPROM WRITE RETRIES reached for DEH - Stop.");
			/* MAX EEPROM WRITE RETRIES - write not work -> Stop */
			/* No additional error handling available here       */
		}

	}
	else if (DEH_EE_REGISTER == SucessfulRegisterDataToEEprom)
	{
		SucessfulRegisterDataToEEprom = DEH_EE_NOTHING_TODO;
		_APL_DEH_u16EEpromWriting_W_Control= 0;
	}
	else  /* DEH_EE_NOTHING_TODO  */
	{
		;
	}
}  /* end function APL_DEH_EEPWriteHandleRetries */

/*----------------------------------------------------------------------------*/
/* Function    :  APL_DEH_IsDEHData_SuccessfulRegisterToEEprom                 */
/**
    \brief      Is DEH data successful register to EEprom

    \param      void

	\return     SucessfulRegisterDataToEEprom

*/
/*----------------------------------------------------------------------------*/
TriStateType_DEH_EE APL_DEH_IsDEHData_SuccessfulRegisterToEEprom(void)
{
   return(SucessfulRegisterDataToEEprom);
}

/*============================================================================
function name    :  APL_DEH_ReadStdFF()
input parameter  :  pStdDestination : pointer to struct for Standard Freeze 
                    Frame with type tDEH_StdFreezeFrame.


output parameter :  -
globals          :  -
return value     :  tDEH_Return
description      :  Read Standard Freeze Frames from system.

------------------------------------------------------------------------------
date        short     change description
------------------------------------------------------------------------------
08.11.03    GIGE    built base version 

============================================================================*/
#ifdef DEH_READ_STD_FF
tDEH_Return APL_DEH_ReadStdFF(tDEH_StdFreezeFrame *pStdDestination)
{
    tDEH_Return retVal = DEH_OK;
    if(TRUE == APP_CAN_bIsDiagnose1MessageReceived())
    {
        pStdDestination->StdFF[0] = IlGetRxKBI_Kilometerstand() << 16;
        pStdDestination->StdFF[1] = IlGetRxKBI_Kilometerstand() << 8;
        pStdDestination->StdFF[2] = IlGetRxKBI_Kilometerstand();
        pStdDestination->StdFF[3] = IlGetRxUH_Jahr() >> 6;
        pStdDestination->StdFF[4] = (IlGetRxUH_Jahr() << 2) | (IlGetRxUH_Monat() >> 2);
        pStdDestination->StdFF[5] = (IlGetRxUH_Monat() << 6) | (IlGetRxUH_Tag() << 1) | (IlGetRxUH_Stunde() >> 8);
        pStdDestination->StdFF[6] = (IlGetRxUH_Stunde() << 4) | (IlGetRxUH_Minute() >> 2);
        pStdDestination->StdFF[7] = (IlGetRxUH_Minute() << 6) | IlGetRxUH_Sekunde();
    }
    else
    {
        pStdDestination->StdFF[0] = 0xFF;
        pStdDestination->StdFF[1] = 0xFF;
        pStdDestination->StdFF[2] = 0xFF;
        pStdDestination->StdFF[3] = 0xFF;
        pStdDestination->StdFF[4] = 0xFF;
        pStdDestination->StdFF[5] = 0xFF;
        pStdDestination->StdFF[6] = 0xFF;
        pStdDestination->StdFF[7] = 0xFF;
    }
    return (retVal);
}
#endif


/*============================================================================
function name    :  APL_DEH_ReadAddFF()
input parameter  :  FF_Number       : additional freeze frame number
                    pAddDestination : pointer to struct for Additional Freeze 
                    Frame with type tDEH_AddFreezeFrame (only in KWP2000 variant).
                    
                    BuffSize        : size of destination buffer for for an  
                    Additional Freeze Frame (only in UDS variant).
                    pNumOfBytes     : pointer to a value for a number of copied bytes
                    pAddFFrame      : pointer to destination buffer

output parameter :  -
globals          :  -
return value     :  tDEH_Return
description      :  read addional freeze frames from system.

------------------------------------------------------------------------------
date        short     change description
------------------------------------------------------------------------------
08.11.03    GIGE    built base version 

============================================================================*/
#ifdef DEH_READ_ADD_FF
tDEH_Return APL_DEH_ReadAddFF
(
  tDEH_FreezeFrameNumber  FF_Number,
#if defined(DEH_SUP_KWP2000)
  tDEH_AddFreezeFrame     *pAddDestination
#elif defined(DEH_SUP_UDS)
  uint8_t                 BuffSize,
  uint8_t                 *pNumOfBytes,
  uint8_t                 *pAddFFrame
#endif
)
{
  tDEH_Return retVal = DEH_OK;
  
#ifdef DEH_SUP_UDS
  *pNumOfBytes = (uint8_t) 0;
#endif  

  return (retVal);
}
#endif


/*============================================================================
function name    :  APL_DEH_ReadUnlearnCounter()
input parameter  : -

output parameter :  -
globals          :  -
return value     :  tDEH_Return
description      :  read addional freeze frames from system.

------------------------------------------------------------------------------
date        short     change description
------------------------------------------------------------------------------
08.11.03    GIGE    built base version

============================================================================*/
uint8_t APL_DEH_ReadUnlearnCounter(void)
{
    uint8_t verlernzaehler;
    if(BT_TRUE == APP_CAN_bIsDiagnose1MessageReceived())
    {
        /* Gateway ZVZ  get with Diagnose 1 message */
        verlernzaehler = IlGetRxDGN_Verlernzaehler();
        /* gatway ZVZ not available */
        if (0xFF == verlernzaehler)
        {
            verlernzaehler = EE_UnlearnCouner_u8;
        }
        if (verlernzaehler != EE_UnlearnCouner_u8)
        {
             DEBUG_VALUE1(DEH_SWI_TRC, MOD_DEH, "Diagnose1 Verlernzaehler %d", verlernzaehler);
             EE_UnlearnCouner_u8 = verlernzaehler;
             (void)EEPROM_sfRamWriteOnly((Uint8Type*)&EE_UnlearnCouner_u8,
                                          EEPROM_LAYOUT_ENUM_DEH_UnclearCounter);
        }
    }
    else
    {
       /* Gateway ZVZ not available */
       verlernzaehler = EE_UnlearnCouner_u8;
       //DEBUG_VALUE1(DEH_SWI_TRC, MOD_DEH, "No mDiagnose_1 message received, load last saved Verlernzaehler %d",verlernzaehler);
    }
    return (verlernzaehler);
}



#ifdef DEH_SUP_SNAP_SHOT_DATA
/*============================================================================
function name    :   APL_DEH_ReadDTCSnapshotRecord()
input parameter  :   DTC         : DTC to read the snapshot records
                     BuffSize    : size of destination buffer for snapshot records
                     pNumOfBytes : pointer to a value for a number of copied bytes
                     pDestBuffer : pointer to destination buffer
output parameter :   
globals          :   
return value     :   tDEH_Return
description      :   Function to read stored snapshot records for a DTC. 
------------------------------------------------------------------------------
date        short    change description
------------------------------------------------------------------------------
18.10.06    GAFR    built base version 
============================================================================*/
tDEH_Return APL_DEH_ReadDTCSnapshotRecord(tDEH_DTC DTC, uint16_t BuffSize, uint16_t *pNumOfBytes, uint8_t *pDestBuffer)
{
  tDEH_Return retVal = DEH_OK;
  
  return (retVal);
}
#endif

/*============================================================================
function name    :   APL_DEH_ReadStatusOfDTC()
input parameter  :   BlockSize_u16  : number of bytes to read
                     Buffer_u8     : pointer to destination buffer
output parameter :   
globals          :   
return value     :   tDEH_Return
description      :   Function to read stored DTC status information
------------------------------------------------------------------------------
date        short    change description
------------------------------------------------------------------------------
14.11.06    GIGE    built base version 
============================================================================*/
tDEH_Return APL_DEH_ReadStatusOfDTC(uint16_t BlockSize_u16, uint8_t *Buffer_u8)
{

  /* Only call in Init Part of DEH - we use an other mechanism to init DEH*/
  tDEH_Return retVal = DEH_OK;

  return (retVal);

}

/*============================================================================
function name    :   APL_DEH_WriteStatusOfDTC()
input parameter  :   BlockSize_u16  : number of bytes to write
                     Buffer_u8     : pointer to source buffer
output parameter :   
globals          :   
return value     :   tDEH_Return
description      :   Function to write the DTC status information into EEPROM
------------------------------------------------------------------------------
date        short    change description
------------------------------------------------------------------------------
14.11.06    GIGE    built base version 
============================================================================*/
tDEH_Return APL_DEH_WriteStatusOfDTC(uint16_t BlockSize_u16, uint8_t *Buffer_u8)  
{
    /* Only call in Init Part of DEH - we use an other mechanism to init DEH*/
	tDEH_Return retVal = DEH_OK;

  return (retVal);
}

/*============================================================================
function name    :   DEH_AdditionalReportEvent()
input parameter  :   tDEH_EventNumber EventNum_uT              : current event number
                     _Bool            DEH_StEV_stRepEvent_mu8  : current event state
output parameter :   
globals          :   
return value     :   tDEH_Return
description      :   Function to write the DTC Event information into EEPROM
------------------------------------------------------------------------------
date        short    change description
------------------------------------------------------------------------------
14.11.06    GIGE    built base version 
============================================================================*/
tDEH_Return DEH_AdditionalReportEvent (tDEH_EventNumber DEH_EventNumber_muT, _Bool DEH_StEV_stRepEvent_mu8)
{
  tDEH_Return  retVal_u8 =  DEH_OK;
  retVal_u8 = DEH_ReportEvent(DEH_EventNumber_muT, DEH_StEV_stRepEvent_mu8);

  if (DEH_StEV_stRepEvent_mu8 == TRUE)
  {
	  DEBUG_VALUE2(DEH_SWI_DBG, MOD_DEH, "DEH_EventNumber_muT: %d, DEH_StEV_stRepEvent_mu8: %d",DEH_EventNumber_muT, DEH_StEV_stRepEvent_mu8);
  }
  if (retVal_u8 != DEH_OK)
  {
	  DEBUG_VALUE1(DEH_SWI_ERR, MOD_DEH, "Attention: DTC 0x%08X isn#t stored !",DEH_EventNumber_muT);
  }
  return (retVal_u8);
}


