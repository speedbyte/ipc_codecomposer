/******   STARTSINGLE_OF_MULTIPLE_COMMENT    ******/


/******************************************************************************
 | Project Name: Network Management for Powertrain
 |    File Name: nmh.c
 |
 |  Description: Implementation of Powertrain Network Management.
 |               Can also be used on other busses.
 |
 |               Project for Volkswagen/Audi.
 |
 |------------------------------------------------------------------------------
 |               C O P Y R I G H T
 |------------------------------------------------------------------------------
 | Copyright (c) 2004-2010 by Vector Informatik GmbH.          All rights reserved.
 |
 |       This software is copyright protected and 
 |       proprietary to Vector Informatik GmbH.
 |       Vector Informatik GmbH grants to you only
 |       those rights as set out in the license conditions.
 |       All other rights remain with Vector Informatik GmbH.
 | 
 |       Diese Software ist urheberrechtlich geschuetzt. 
 |       Vector Informatik GmbH raeumt Ihnen an dieser Software nur 
 |       die in den Lizenzbedingungen ausdruecklich genannten Rechte ein.
 |       Alle anderen Rechte verbleiben bei Vector Informatik GmbH.
 |
 |------------------------------------------------------------------------------
 |               A U T H O R   I D E N T I T Y
 |------------------------------------------------------------------------------
 | Initials     Name                      Company
 | --------     ---------------------     --------------------------------------
 | Hp           Armin Happel              Vector Informatik GmbH
 | Tri          Frank Triem               Vector Informatik GmbH
 | vismdr       Markus Drescher           Vector Informatik GmbH
 | visoh        Oliver Hornung            Vector Informatik GmbH
 |------------------------------------------------------------------------------
 |               R E V I S I O N   H I S T O R Y
 |------------------------------------------------------------------------------
 | Date         Ver      Author  Description
 | ----------   -------  ------  -----------------------------------------------
 | 2004-06-21   1.00.00  Hp,Tri  ESCAN00007396: Creation of module
 |                               ESCAN00008109: Added service that retrieves the internal state of the NM
 | 2004-07-09   1.01.00   Tri    ESCAN00008806: Tx Observe Mechanism might not recognize a timeout
 |                               ESCAN00008807: Timing of NM-message is incorrect after BusOff
 | 2004-09-16   1.02.00   Tri    ESCAN00009499: Apply PSC naming conventions of version definitions
 | 2004-12-01   1.03.00   Tri    ESCAN00010383: Support multi channel indexed API
 |                               ESCAN00009792: Implement API call types
 |                               ESCAN00008723: Use new memory qualifier
 |                               ESCAN00010496: NmhIntBusOffRxRestore not called
 | 2005-03-18   1.04.00   Tri    ESCAN00010075: Bus communication request for external networks
 |                               ESCAN00010803: Update of NM-message data
 | 2005-04-07   1.05.00   Tri    ESCAN00011756: Compiler error if 'Timeout Time' longer than 'NM-message Tx Timeout Time'
 | 2005-04-15   1.06.00   Tri    ESCAN00011837: NmhIntActiveFailed() gets called even if transmission is not damaged
 |                               ESCAN00011928: Add explicit type cast before negations
 |                               ESCAN00012997: Include structure revised
 | 2006-05-11   1.07.00   Tri    ESCAN00016281: Initialization in Bus-Sleep Mode
 |                               ESCAN00016320: Restore receive capability after BusOff one task cycle earlier
 |                               ESCAN00016323: Stop BusOff recovery when entering Bus-Sleep Mode
 | 2006-09-08   1.08.00   Tri    ESCAN00016580: Allow Repeat Message to be greater than Timeout Time
 |                               ESCAN00016795: Support multi channel indexed API with indirection
 |                               ESCAN00017026: Support for TxObserve shall be permanently disabled for OEM Porsche
 |                               ESCAN00017048: Support of 'restart during shutdown'
 |                               ESCAN00017402: Support of PAG BusOff algorithm
 | 2006-10-27   1.09.00   Tri    ESCAN00018084: Compilation issue in function NmhTxObjConfirmed()
 |                               ESCAN00017730: Resolve compiler warnings
 | 2006-12-19   1.10.00   Tri    ESCAN00018387: Initialization with wrong channel handle
 | 2007-03-13   1.11.00   visoh  ESCAN00019446: No changes.
 | 2007-06-04   1.12.00   visoh  ESCAN00020886: Fix problem with asynchronous shutdown due to not considered confirmation.
 | 2007-08-06   1.12.01   visoh  ESCAN00021788: Timing Checks in single channel case encapsulated correctly.
 | 2008-03-05   1.12.02   visoh  ESCAN00025113: Code Optimizations in case of CCL is used.
 |                               ESCAN00025439: Resolved Compiler Warning
 | 2009-01-23   1.12.03   visoh  ESCAN00032240: Resolved Compiler Error (Metroworks)
 | 2010-08-27   1.12.04   vismdr ESCAN00028173: No changes.
 |                               ESCAN00034994: Reworked memory attributes for function parameters
 |                               ESCAN00038064: Improved MISRA compliance.
 |*****************************************************************************/
#define NMH_SOURCE_MODULE

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "nmh.h"


/******************************************************************************/
/* Version check                                                              */
/******************************************************************************/
#if ( NM_PWRTRAIN_VAG_VERSION != 0x0112u )   /* compare file header version   */
  #error "wrong version of file header nmh.h included incompatible with nmh.c version"
#endif                                       /* legal file header version     */
#if ( NM_PWRTRAIN_VAG_RELEASE_VERSION != 0x04u )
  #error "Source and Header file are inconsistent!"
#endif


/******************************************************************************/
/* Defines                                                                    */
/******************************************************************************/

#if defined ( NMH_ENABLE_CHANNEL_INDIRECTION )
  #define NmhNmToCanChannel( channel )   kNmhNmToCanIndirection[(channel)]  /* PRQA S 3453 */ /* MD_CBD_19.7 */
  #define NmhCanToNmChannel( channel )   kNmhCanToNmIndirection[(channel)]  /* PRQA S 3453 */ /* MD_CBD_19.7 */
#else 
  #define NmhNmToCanChannel( channel )   (channel) /* PRQA S 3453 */ /* MD_CBD_19.7 */
  #define NmhCanToNmChannel( channel )   (channel) /* PRQA S 3453 */ /* MD_CBD_19.7 */
#endif


#if defined ( NMH_ENABLE_INDEXED_NM )
  #if defined ( NMH_ENABLE_CHANNEL_INDIRECTION )
    #define NMH_CHANNEL_IDX       nmhChannel
    #define kNmhFieldSize         kNmhNumberOfChannels
    #define NMH_CHANNEL_IDX_IND   NmhCanToNmChannel( NMH_CHANNEL_SYSTEMPARA_ONLY )

    #define NMH_CHANNEL_SYSTEMPARA_IND_ONLY     NmhNmToCanChannel(NMH_CHANNEL_IDX)
    #define NMH_CHANNEL_SYSTEMPARA_IND_FIRST    NmhNmToCanChannel(NMH_CHANNEL_IDX),
  #else
    #define NMH_CHANNEL_IDX       channel
    #define kNmhFieldSize         kNmhNumberOfChannels
    #define NMH_CHANNEL_IDX_IND   NMH_CHANNEL_SYSTEMPARA_ONLY

    #define NMH_CHANNEL_SYSTEMPARA_IND_ONLY     channel
    #define NMH_CHANNEL_SYSTEMPARA_IND_FIRST    channel,
  #endif
#else
  /* Per default the NM is mapped to system channel 0. */
  #define NMH_CHANNEL_IDX         0u
  #define kNmhFieldSize           1u
  #define NMH_CHANNEL_IDX_IND     0u

  #define NMH_CHANNEL_SYSTEMPARA_IND_ONLY
  #define NMH_CHANNEL_SYSTEMPARA_IND_FIRST
#endif


#if defined ( FALSE )
#else
  #define FALSE   0u
#endif

#if defined ( TRUE )
#else
  #define TRUE    1u
#endif


/* Definition of the number of states and events for the state machine. */
#define kNmhStateMachineStates 5u
#define kNmhStateMachineEvents 8u


#if defined ( NMH_ENABLE_INDEXED_NM )
/*---------- data type for post-compile configuration parameters -------------*/

  #define kNmhMsgCycleTimeCounter          NmhConfiguration[NMH_CHANNEL_IDX].kNmhMsgCycleTime
  #define kNmhTimeoutTimeCounter           NmhConfiguration[NMH_CHANNEL_IDX].kNmhTimeoutTime
  #define kNmhWaitBusSleepTimeCounter      NmhConfiguration[NMH_CHANNEL_IDX].kNmhWaitBusSleepTime
  #define kNmhPrepareSleepTimeCounter      NmhConfiguration[NMH_CHANNEL_IDX].kNmhPrepareSleepTime
  #define kNmhMsgTimeoutCounter            NmhConfiguration[NMH_CHANNEL_IDX].kNmhMsgTimeout
  #define kNmhBusOffRecoveryTimeCounter1   NmhConfiguration[NMH_CHANNEL_IDX].kNmhBusOffRecoveryTime1
  #define kNmhBusOffRecoveryTimeCounter2   NmhConfiguration[NMH_CHANNEL_IDX].kNmhBusOffRecoveryTime2
  #define kNmhRepeatMsgCounts              NmhConfiguration[NMH_CHANNEL_IDX].kNmhRepeatMsgCountsPara

#else   /* defined ( NMH_ENABLE_INDEXED_NM ) */

/*-- Calculate counter value for timer ---------------------------------------*/

  #define kNmhMsgCycleTimeCounter        ( ((kNmhMsgCycleTime        + kNmhCycleTime)-1u) / kNmhCycleTime )
  #define kNmhTimeoutTimeCounter         ( ((kNmhTimeoutTime         + kNmhCycleTime)-1u) / kNmhCycleTime )
  #define kNmhWaitBusSleepTimeCounter    ( ((kNmhWaitBusSleepTime    + kNmhCycleTime)-1u) / kNmhCycleTime )
  #define kNmhPrepareSleepTimeCounter    ( ((kNmhPrepareSleepTime    + kNmhCycleTime)-1u) / kNmhCycleTime )
  #define kNmhMsgTimeoutCounter          ( ((kNmhMsgTimeout          + kNmhCycleTime)-1u) / kNmhCycleTime )
  #define kNmhBusOffRecoveryTimeCounter1 ( ((kNmhBusOffRecoveryTime1 + kNmhCycleTime)-1u) / kNmhCycleTime )
  #define kNmhBusOffRecoveryTimeCounter2 ( ((kNmhBusOffRecoveryTime2 + kNmhCycleTime)-1u) / kNmhCycleTime )

#endif  /* defined ( NMH_ENABLE_INDEXED_NM ) */


/* Message data */
#define kNmhSystemByte            0u
#define kNmhUserData              1u
#define kNmhUserDataByte0         1u
#define kNmhUserDataByte1         2u
#define kNmhUserDataByte2         3u
#define kNmhUserDataByte3         4u
#define kNmhUserDataByte4         5u
#define kNmhUserDataByte5         6u

/* System Byte Mask */
#define kNmhNmStateMask           0x0Fu
#define kNmhReserved0Mask         0x30u
#define kNmhCarWakeUpMask         0x40u
#define kNmhReserved1Mask         0x80u

#define kNmhInverseNmStateMask    0xF0u /* ~(vuint8)kNmhNmStateMask */
#define kNmhInverseCarWakeUpMask  0xBFu /* ~(vuint8)kNmhCarWakeUpMask */

/*******************************************************************************
 * Macros
*******************************************************************************/

#define NMH_EVENT_FINISH_REPEAT_MSG ( (commState == NMH_NORMAL_OPERATION) ? kNmhEventFinishRepeatMsgNormalOperation : kNmhEventFinishRepeatMsgReadySleep )
#define NMH_EVENT_COMM_STATE        ( (commState == NMH_NORMAL_OPERATION) ? kNmhEventCommStateNormalOperation : kNmhEventCommStateReadySleep )


/*******************************************************************************
 * Typedef and Struct definitions
*******************************************************************************/

/* Events for state transitions. */
typedef enum
{
  kNmhEventCommStateReadySleep            = 0u,
  kNmhEventCommStateNormalOperation       = 1u,
  kNmhEventWakeUp                         = 2u,
  kNmhEventTimeoutTtimeout                = 3u,
  kNmhEventTimeoutTwbs                    = 4u,
  kNmhEventFinishRepeatMsgReadySleep      = 5u,
  kNmhEventFinishRepeatMsgNormalOperation = 6u,
  kNmhEventNmhMessageReceived             = 7u
} tNmhEventType;

#if defined ( NMH_ENABLE_CAR_WUP )
/* State of the CarWakeUp request. */
typedef enum
{
  kNmhCwupStateOff                = 0u,
  kNmhCwupStateRequest            = 1u,
  kNmhCwupStateRelease            = 2u,
  kNmhCwupStateRequestTransmitted = 3u,
  kNmhCwupStateReleaseTransmitted = 4u
} tNmhCarWupRequestStateType;
#endif

/* Type of the timer/counters. */
#if defined ( NMH_ENABLE_INDEXED_NM )
  #define NMH_DISABLE_TIMER_8BIT
  #define NMH_ENABLE_TIMER_16BIT
#else
    #if ( kNmhWaitBusSleepTimeCounter    < 0xFFu ) && ( kNmhTimeoutTimeCounter   < 0xFFu ) && \
        ( kNmhPrepareSleepTimeCounter    < 0xFFu ) && ( kNmhMsgCycleTimeCounter  < 0xFFu ) && \
        ( ((kNmhRepeatMsgCounts - 1u) * kNmhMsgCycleTimeCounter ) < 0xFFu )                && \
        ( kNmhMsgTimeoutCounter          < 0xFFu ) && \
        ( kNmhBusOffRecoveryTimeCounter1 < 0xFFu ) && ( kNmhBusOffRecoveryTimeCounter2 < 0xFFu )
      #define NMH_ENABLE_TIMER_8BIT
      #define NMH_DISABLE_TIMER_16BIT
    #else
      #define NMH_DISABLE_TIMER_8BIT
      #define NMH_ENABLE_TIMER_16BIT
    #endif
#endif  /* defined ( NMH_ENABLE_INDEXED_NM ) */

/* On 16/32 Bit microcontroller the performance of vuintx might be better than of vuint8.
   Therefore it should be taken in consideration to use vuintx on 16/32 bit micros. */
#if defined ( NMH_ENABLE_TIMER_8BIT )
typedef V_MEMRAM1_NEAR vuint8 V_MEMRAM2_NEAR   tNmhTimerCounterType;
#else
typedef V_MEMRAM1_NEAR vuint16 V_MEMRAM2_NEAR  tNmhTimerCounterType;
#endif

/* Values for disabling timers. */
#if defined ( NMH_ENABLE_TIMER_8BIT )
  #define kNmhBusOffCounterMax            0xFFu /* Maximum allowed value of the BusOff counter. */
#else
  #define kNmhBusOffCounterMax            0xFFFFu /* Maximum allowed value of the BusOff counter. */  
#endif


/***************************************************************************/
/* Prototypes for local functions                                          */
/***************************************************************************/

/* State transition functions of the state machine. */
static void NMH_INTERNAL_CALL_TYPE NmhStateTransition( NMH_CHANNEL_NMTYPE_FIRST  tNmhEventType event );

/* State enter functions, that are executed prior to the change to the belonging state. */
/* A pointer to each function is stored in kNmhEnterStateFctMatrix[].                    */
static void NMH_INTERNAL_CALL_TYPE NmhEnterStateRepeatMsg( NMH_CHANNEL_NMTYPE_ONLY );
static void NMH_INTERNAL_CALL_TYPE NmhEnterStateNormalMode( NMH_CHANNEL_NMTYPE_ONLY );
static void NMH_INTERNAL_CALL_TYPE NmhEnterStateReadySleep( NMH_CHANNEL_NMTYPE_ONLY );
static void NMH_INTERNAL_CALL_TYPE NmhEnterStatePrepareSleep( NMH_CHANNEL_NMTYPE_ONLY );
static void NMH_INTERNAL_CALL_TYPE NmhEnterStateSleep( NMH_CHANNEL_NMTYPE_ONLY );

/* State exit functions, that are executed before leaving the belonging state. */
/* A pointer to each function is stored in kNmhExitStateFctMatrix[].            */
static void NMH_INTERNAL_CALL_TYPE NmhExitStateRepeatMsg( NMH_CHANNEL_NMTYPE_ONLY );
static void NMH_INTERNAL_CALL_TYPE NmhExitStateNormalMode( NMH_CHANNEL_NMTYPE_ONLY );
static void NMH_INTERNAL_CALL_TYPE NmhExitStateReadySleep( NMH_CHANNEL_NMTYPE_ONLY );
static void NMH_INTERNAL_CALL_TYPE NmhExitStatePrepareSleep( NMH_CHANNEL_NMTYPE_ONLY );
static void NMH_INTERNAL_CALL_TYPE NmhExitStateSleep( NMH_CHANNEL_NMTYPE_ONLY );


/****************************************************************************/
/* Local Constants                                                          */
/****************************************************************************/


/* State matrix of the NM-High state machine. */
/* The usage of the tNmhStateType (int) instead of vuint8 wastes, on 16/32 bit microcontrollers, ROM space.
   But due to type checks this drawback is accepted. On the other hand can the performance of int be higher than of vuint8. */
/* Violation to MISRA rule 22 (declaration of objects should be at function scope ...) due to ESCAN00032240.
   For non code doubled configurations is the following field only used within the function: NmhStateTransition. */
V_MEMROM0 static V_MEMROM1 tNmhStateType V_MEMROM2 kNmhStateMatrix[kNmhStateMachineStates][kNmhStateMachineEvents] = /* PRQA S 3218 */ /* MD_Nmh_3218 */
{
  /* state: \ event: */  /* No Comm needed,        Comm needed,         Wake Up,               Timeout Ttimeout,      Timeout Twbs,          RepeatedMsgNoCommNeeded,   RepeatedMsgCommNeeded,    NMH-Msg. received */       /* event: / state: */ 
  /*  Repeat Message */  {  kNmhStateRepeatMsg,    kNmhStateRepeatMsg,  kNmhStateRepeatMsg,    kNmhStateRepeatMsg,    kNmhStateRepeatMsg,    kNmhStateReadySleep,       kNmhStateNormalMode,      kNmhStateRepeatMsg,    },  /*  Repeat Message */
  /*  Normal Mode    */  {  kNmhStateReadySleep,   kNmhStateNormalMode, kNmhStateNormalMode,   kNmhStateNormalMode,   kNmhStateNormalMode,   kNmhStateNormalMode,       kNmhStateNormalMode,      kNmhStateNormalMode,   },  /*  Normal Mode    */
  /*  Ready Sleep    */  {  kNmhStateReadySleep,   kNmhStateNormalMode, kNmhStateReadySleep,   kNmhStatePrepareSleep, kNmhStateReadySleep,   kNmhStateReadySleep,       kNmhStateReadySleep,      kNmhStateReadySleep,   },  /*  Ready Sleep    */
  /*  Prepare Sleep  */  {  kNmhStatePrepareSleep, kNmhStateRepeatMsg,  kNmhStatePrepareSleep, kNmhStatePrepareSleep, kNmhStateSleep,        kNmhStatePrepareSleep,     kNmhStatePrepareSleep,    kNmhStateRepeatMsg,    },  /*  Prepare Sleep  */
  /*  Sleep          */  {  kNmhStateSleep,        kNmhStateRepeatMsg,  kNmhStateRepeatMsg,    kNmhStateSleep,        kNmhStateSleep,        kNmhStateSleep,            kNmhStateSleep,           kNmhStateRepeatMsg     }   /*  Sleep          */
};

/* Array of state enter functions. */
/* Violation to MISRA rule 22 (declaration of objects should be at function scope ...) due to ESCAN00032240.
   For non code doubled configurations is the following field only used within the function: NmhStateTransition. */
V_MEMROM0 static V_MEMROM1 void (* V_MEMROM2 kNmhEnterStateFctMatrix[5])( NMH_CHANNEL_NMTYPE_ONLY ) = { /* PRQA S 3218 */ /* MD_Nmh_3218 */
  NmhEnterStateRepeatMsg,     /*  State: Repeat Message */
  NmhEnterStateNormalMode,    /*  State: Normal Mode    */
  NmhEnterStateReadySleep,    /*  State: Ready Sleep    */
  NmhEnterStatePrepareSleep,  /*  State: Prepare Sleep  */
  NmhEnterStateSleep          /*  State: Sleep          */
};

/* Array of state exit functions. */
/* Violation to MISRA rule 22 (declaration of objects should be at function scope ...) due to ESCAN00032240.
   For non code doubled configurations is the following field only used within the function: NmhStateTransition. */
V_MEMROM0 static V_MEMROM1 void (* V_MEMROM2 kNmhExitStateFctMatrix[5])( NMH_CHANNEL_NMTYPE_ONLY ) = { /* PRQA S 3218 */ /* MD_Nmh_3218 */
  NmhExitStateRepeatMsg,     /*  State: Repeat Message */
  NmhExitStateNormalMode,    /*  State: Normal Mode    */
  NmhExitStateReadySleep,    /*  State: Ready Sleep    */
  NmhExitStatePrepareSleep,  /*  State: Prepare Sleep  */
  NmhExitStateSleep          /*  State: Sleep          */
};

/*==========================================================================*/
/* Driver Version for Diagnostics                                           */
/*==========================================================================*/
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kNmhMainVersion     = (vuint8)(NM_PWRTRAIN_VAG_VERSION >> 8);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kNmhSubVersion      = (vuint8)(NM_PWRTRAIN_VAG_VERSION  & 0x00FFu);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kNmhReleaseVersion  = (vuint8)(NM_PWRTRAIN_VAG_RELEASE_VERSION);



/******************************************************************************/
/* Data definitions                                                           */
/******************************************************************************/


/* Internal flags of the NM-High */
V_MEMRAM0 static volatile V_MEMRAM1_NEAR vuint8 V_MEMRAM2_NEAR nmhMsgReceivedFlag[kNmhFieldSize];  /* Network Management Message received flag. */
V_MEMRAM0 static volatile V_MEMRAM1_NEAR vuint8 V_MEMRAM2_NEAR nmhMsgConfirmedFlag[kNmhFieldSize]; /* Network Management Message transmit confirmation flag. */
V_MEMRAM0 static volatile V_MEMRAM1      vuint8 V_MEMRAM2      nmhWakeUpFlag[kNmhFieldSize];       /* Wake-up request flag. */
#if defined ( NMH_ENABLE_CAR_WUP )
V_MEMRAM0 static volatile V_MEMRAM1 tNmhCarWupRequestStateType V_MEMRAM2 nmhCarWakeUpState[kNmhFieldSize]; /* State of Wake-up request for external networks. */
#endif

/* The usage of the tNmhStateType (int) instead of vuint8 wastes on 16/32 bit microcontrollers ROM space.
   But due to type checks this drawback is accepted. On the other hand can the performance of int be higher than of vuint8. */
V_MEMRAM0 static V_MEMRAM1 tNmhStateType V_MEMRAM2 nmhState[kNmhFieldSize]; /* Current state of the state machine. */

/* Timer/Counter */
V_MEMRAM0 static tNmhTimerCounterType nmhTimeoutTimer[kNmhFieldSize];           /* Timer for Time 'Timeout'. */
V_MEMRAM0 static tNmhTimerCounterType nmhWaitBusSleepTimer[kNmhFieldSize];      /* Timer for Time 'Wait Bus Sleep'. */ 
V_MEMRAM0 static tNmhTimerCounterType nmhNmMsgTimer[kNmhFieldSize];             /* Timer for transmission of the Network Management Message. */
V_MEMRAM0 static tNmhTimerCounterType nmhRepeatMsgTimer[kNmhFieldSize];         /* Timer for state Repeat Message (transmission of a certai number of NM-messages). */

V_MEMRAM0 static V_MEMRAM1 tNmhCommStateType V_MEMRAM2 nmhCommState[kNmhFieldSize];     /* Internal state for the application's need for communication. */
V_MEMRAM0 static V_MEMRAM1 tNmhCommStateType V_MEMRAM2 nmhLastCommState[kNmhFieldSize]; /* Store the last communication state,              */
                                                                                            /* to recognize changes of the communication state. */


V_MEMRAM0 static volatile tNmhTimerCounterType nmhBusOffRecoveryTimer[kNmhFieldSize];      /* Timer for the BusOff recovery time. */
V_MEMRAM0 static volatile tNmhTimerCounterType nmhBusOffCounter[kNmhFieldSize];            /* Counter for consecutive BusOff events. */

V_MEMRAM0 static V_MEMRAM1 tNmhMsgDataType V_MEMRAM2 nmhMsgData[kNmhFieldSize];                /* NM-message data buffer. */





#if defined ( NM_TYPE_NMHIGH )


/******************************************************************************
*
*
*           Code-Part for NM_TYPE_NMHIGH 
*
*
*******************************************************************************/


/*******************************************************************************
** Function:    NmhInitPowerOn
**
** Purpose:     Power-On initialization of the Network Management High.
**
**  Called by:  Application
**
**  Parameter:  
**              nmhInitState : Initialization state of Network Management
**                             (ESCAN00016281)
**
**  Returncode: -
*******************************************************************************/
void NMH_API_CALL_TYPE NmhInitPowerOn( tNmhInitType nmhInitState )
{
#if defined ( NMH_ENABLE_INDEXED_NM )
  NmhChannelHandle NMH_CHANNEL_IDX;

  for ( NMH_CHANNEL_IDX = (NmhChannelHandle)0u; NMH_CHANNEL_IDX < (NmhChannelHandle)kNmhFieldSize; NMH_CHANNEL_IDX++ )
  {
    /* Initialization of the Network Management High. */  
    NmhInit( NMH_CHANNEL_SYSTEMPARA_IND_FIRST  nmhInitState );
  }
#else
  /* Initialization of the Network Management High. */  
  NmhInit( nmhInitState );
#endif /* defined ( NMH_ENABLE_INDEXED_NM ) */
}


/*******************************************************************************
** Function:    NmhInit
**
** Purpose:     Initialization of the Network Management High.
**
**  Called by:  NmhInitPowerOn, Application
**
**  Parameter:  
**              nmhInitState : Initialization state of Network Management
**                             (ESCAN00016281)
**
**  Returncode: -
*******************************************************************************/
void NMH_API_CALL_TYPE NmhInit( NMH_CHANNEL_SYSTEMTYPE_FIRST  tNmhInitType nmhInitState )
{
#if defined ( NMH_ENABLE_CHANNEL_INDIRECTION )
  V_MEMRAM0 V_MEMRAM1 NmhChannelHandle V_MEMRAM2 nmhChannel = NmhCanToNmChannel( NMH_CHANNEL_SYSTEMPARA_ONLY );
#endif

  /* Reset all flags. */
  nmhMsgReceivedFlag[NMH_CHANNEL_IDX]  = (vuint8)FALSE;
  nmhMsgConfirmedFlag[NMH_CHANNEL_IDX] = (vuint8)FALSE;
  nmhWakeUpFlag[NMH_CHANNEL_IDX]       = (vuint8)FALSE;
#if defined ( NMH_ENABLE_CAR_WUP )
  nmhCarWakeUpState[NMH_CHANNEL_IDX]       = kNmhCwupStateOff;
#endif

  /* The communication state is initially set to sleep indication. */  
  nmhCommState[NMH_CHANNEL_IDX]     = NMH_READY_SLEEP;
  nmhLastCommState[NMH_CHANNEL_IDX] = NMH_READY_SLEEP;


  /* Initialize the BusOff timer and counter. */
  nmhBusOffRecoveryTimer[NMH_CHANNEL_IDX] = (tNmhTimerCounterType)0u;
  nmhBusOffCounter[NMH_CHANNEL_IDX]       = (tNmhTimerCounterType)0u;


  /* Initialize the 'system byte'. */
  nmhMsgData[NMH_CHANNEL_IDX][kNmhSystemByte] = (vuint8)0x00u;

  /* Initialize the user data */
  nmhMsgData[NMH_CHANNEL_IDX][kNmhUserDataByte0] = (vuint8)0x00u;
  nmhMsgData[NMH_CHANNEL_IDX][kNmhUserDataByte1] = (vuint8)0x00u;
  nmhMsgData[NMH_CHANNEL_IDX][kNmhUserDataByte2] = (vuint8)0x00u;
  nmhMsgData[NMH_CHANNEL_IDX][kNmhUserDataByte3] = (vuint8)0x00u;
  nmhMsgData[NMH_CHANNEL_IDX][kNmhUserDataByte4] = (vuint8)0x00u;
  nmhMsgData[NMH_CHANNEL_IDX][kNmhUserDataByte5] = (vuint8)0x00u;

  /* State machine initialization. */
  /* If the initialization state is Network Mode, start with a transition from Sleep Mode to network mode (sub-state Repeat Message). */
  /* If the initialization state is Bus-Sleep Mode, start with a transition from Prepare Bus-Sleep Mode to Bus-Sleep Mode. */
  nmhState[NMH_CHANNEL_IDX] = ( nmhInitState == NMH_INIT_NORMAL ) ? kNmhStateSleep : kNmhStatePrepareSleep;
  NmhStateTransition( NMH_CHANNEL_NMPARA_FIRST  (( nmhInitState == NMH_INIT_NORMAL ) ? kNmhEventNmhMessageReceived : kNmhEventTimeoutTwbs) );
}


/*******************************************************************************
** Function:    NmhTask
**
** Purpose:     The cyclic task is used to increment the counters.
**
**  Called by:  Application
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
void NMH_API_CALL_TYPE NmhTask( NMH_CHANNEL_SYSTEMTYPE_ONLY )
{
#if defined ( NMH_ENABLE_CHANNEL_INDIRECTION )
  V_MEMRAM0 V_MEMRAM1 NmhChannelHandle V_MEMRAM2 nmhChannel = NmhCanToNmChannel( NMH_CHANNEL_SYSTEMPARA_ONLY );
#endif

#if defined ( NMH_ENABLE_CAR_WUP )
  vuint8 carWakeUpRequestFlag;        /* local flag. */
#endif  
  tNmhCommStateType commState;        /* local copy of the global communication state. */

  /* Copy of the global communication state. */
  commState = nmhCommState[NMH_CHANNEL_IDX];

  /* Check whether the wake-up flag is set. */
  if ( nmhWakeUpFlag[NMH_CHANNEL_IDX] == (vuint8)TRUE )
  {
    /* Reset the global Wake-Up flag. */
    nmhWakeUpFlag[NMH_CHANNEL_IDX] = (vuint8)FALSE;

    /* A wake-up event has occured... */
    /* ...perform state transition. */
    NmhStateTransition( NMH_CHANNEL_NMPARA_FIRST  kNmhEventWakeUp );
  }

  
  /* Check whether the NM-message received flag is set. */
  if ( nmhMsgReceivedFlag[NMH_CHANNEL_IDX] == (vuint8)TRUE )
  {
    /* Reset the global Message received flag. */
    nmhMsgReceivedFlag[NMH_CHANNEL_IDX] = (vuint8)FALSE;
    
    /* A Network Management Message has been received... */
    /* ...perform state transition. */
    NmhStateTransition( NMH_CHANNEL_NMPARA_FIRST  kNmhEventNmhMessageReceived );
  
    /* ... and reset the Timout Time Counter whenever a Network Management Message has been received. */  
    nmhTimeoutTimer[NMH_CHANNEL_IDX] = (tNmhTimerCounterType)kNmhTimeoutTimeCounter + (tNmhTimerCounterType)1u;
  }


  /* Check whether the communication state has been changed. */
  /* Attention: It can yet not be recognized, if the communication state has been changed more than once. */
  if ( commState != nmhLastCommState[NMH_CHANNEL_IDX] )
  {
    /* Store the current communictaion state. */
    nmhLastCommState[NMH_CHANNEL_IDX] = commState;

    /* Notify application that a wake-up has been requested by the application. */
    /* If state is still Bus Sleep then wakeup flag is not TRUE */
    if ( nmhState[NMH_CHANNEL_IDX] == kNmhStateSleep ) {
      NmhIntWakeUp( NMH_CHANNEL_SYSTEMPARA_ONLY );
    }

    /* The communication state has changed... */
    /* ...perform state transition. */
    NmhStateTransition( NMH_CHANNEL_NMPARA_FIRST  NMH_EVENT_COMM_STATE );
  }



  /* BusOff handling. */
  if ( nmhBusOffRecoveryTimer[NMH_CHANNEL_IDX] > (tNmhTimerCounterType)0u )
  {

    /* Restore CAN message reception as soon as possible (ESCAN00016320). */
    if ( ( ( nmhBusOffRecoveryTimer[NMH_CHANNEL_IDX] == (tNmhTimerCounterType)kNmhBusOffRecoveryTimeCounter1 ) &&
           ( nmhBusOffCounter[NMH_CHANNEL_IDX] == (tNmhTimerCounterType )1u) ) ||
         ( ( nmhBusOffRecoveryTimer[NMH_CHANNEL_IDX] == (tNmhTimerCounterType)kNmhBusOffRecoveryTimeCounter2 ) &&
           ( nmhBusOffCounter[NMH_CHANNEL_IDX] > (tNmhTimerCounterType)1u ) )
       )
    {
      NmhIntBusOffRxRestore( NMH_CHANNEL_SYSTEMPARA_ONLY );
    }

    /* - The BusOff recovery timer is decremented before calling NmhIntBusoffEnd to avoid interrupt locks.
         Therefore the BusOff recovery timer has to be incremented upon starting (in NmhBusCriticalFailure).
       - No interrupt lock is necessary here due to the message transmission is not possible during BusOff recovery. */
    nmhBusOffRecoveryTimer[NMH_CHANNEL_IDX]--;

    /* Stop the BusOff handling after T[Bo_Recovery]. */
    if ( nmhBusOffRecoveryTimer[NMH_CHANNEL_IDX] == (tNmhTimerCounterType)0u )
    {
      NmhIntBusOffEnd( NMH_CHANNEL_SYSTEMPARA_ONLY );
    }
  }


  /* Perform timer/counter handling depending on the current state. */

  switch ( nmhState[NMH_CHANNEL_IDX] )
  {
    /* Handling of the Timeout timer and Message timer. */
    /* The Message timer is reset whenever a NM-message has been transmitted. */
    /* The Timeout timer is reset when leaving state 'Repeat Message' and 
       when a NM-message has been received or transmitted.                    */
    /* The 'Repeat Message' timer is reset when entering state 'Repeat Message'. */
    case kNmhStateRepeatMsg:
    case kNmhStateNormalMode:
   
#if defined ( NMH_ENABLE_CAR_WUP )
      /* Set / Reset the communication state for external networks. */
      if ( nmhCarWakeUpState[NMH_CHANNEL_IDX] == kNmhCwupStateRequest )
      {
        /* Set the appropriate bit in the 'system byte'. */
        nmhMsgData[NMH_CHANNEL_IDX][kNmhSystemByte] |= (vuint8)kNmhCarWakeUpMask;

        /* Request an immediate network management transmission. */
        carWakeUpRequestFlag = (vuint8)TRUE;
      }
      else
      {
        if ( nmhCarWakeUpState[NMH_CHANNEL_IDX] == kNmhCwupStateRelease )
        {
          /* Reset the appropriate bit in the 'system byte'. */
          nmhMsgData[NMH_CHANNEL_IDX][kNmhSystemByte] &= (vuint8)kNmhInverseCarWakeUpMask; /* ESCAN00011928 */

          /* Request an immediate network management transmission. */
          carWakeUpRequestFlag = (vuint8)TRUE;
        }
        else
        {
          carWakeUpRequestFlag = (vuint8)FALSE;
        }
      }

      if ( carWakeUpRequestFlag == (vuint8)TRUE )
      {
        /* Cancel the current NM-message request.. */
        NmhIntCancelMsgRequest( NMH_CHANNEL_SYSTEMPARA_ONLY );
        
        /* ..and trigger an immediate NM-message transmisson. */
        nmhNmMsgTimer[NMH_CHANNEL_IDX] = (tNmhTimerCounterType)0u;        
      }
#endif
    
      /* Reset the NM-message timeout timer and the NM-message cycle timer, if the flag is set. */
      if ( nmhMsgConfirmedFlag[NMH_CHANNEL_IDX] == (vuint8)TRUE )
      {
        nmhMsgConfirmedFlag[NMH_CHANNEL_IDX] = (vuint8)FALSE;
        nmhTimeoutTimer[NMH_CHANNEL_IDX]     = (tNmhTimerCounterType)kNmhTimeoutTimeCounter;

#if defined ( NMH_ENABLE_CAR_WUP )        
        if ( carWakeUpRequestFlag == (vuint8)FALSE )
        {
#endif
          nmhNmMsgTimer[NMH_CHANNEL_IDX] = (tNmhTimerCounterType)(kNmhMsgCycleTimeCounter - 1u);
#if defined ( NMH_ENABLE_CAR_WUP )
          /* Confirm the application (CarWupManager) about the first successful transmission */
          /* of a NM-message with set/reset 'external wakeup request bit' */
          if  ( nmhCarWakeUpState[NMH_CHANNEL_IDX] == kNmhCwupStateRequestTransmitted )
          {
            nmhCarWakeUpState[NMH_CHANNEL_IDX] = kNmhCwupStateOff;
            NmhIntCarWupRequestConfirmation( NMH_CHANNEL_SYSTEMPARA_ONLY );
          }
          else
          {
            if ( nmhCarWakeUpState[NMH_CHANNEL_IDX] == kNmhCwupStateReleaseTransmitted )
            {
              nmhCarWakeUpState[NMH_CHANNEL_IDX] = kNmhCwupStateOff;
              NmhIntCarWupReleaseConfirmation( NMH_CHANNEL_SYSTEMPARA_ONLY );
            }
          }
          
        } /* ( carWakeUpRequestFlag == (vuint8)FALSE ) */
#endif
      }

      /* Request to transmit a NM-message */
      if (nmhNmMsgTimer[NMH_CHANNEL_IDX] == (tNmhTimerCounterType)0u)
      {
        if ( NmhIntMsgRequest( NMH_CHANNEL_SYSTEMPARA_FIRST  (tNmhMsgDataType *)(&nmhMsgData[NMH_CHANNEL_IDX]) ) == (vuint8)kNmhTxRequestOk )
        {
          /* NM-message transmit request was successful. */

#if defined ( NMH_ENABLE_CAR_WUP )
          /* Set / Reset the communication state for external networks. */
          /* And set the CarWakeUp State to transmitted. */
          if  ( nmhCarWakeUpState[NMH_CHANNEL_IDX] == kNmhCwupStateRequest )
          {
            nmhCarWakeUpState[NMH_CHANNEL_IDX] = kNmhCwupStateRequestTransmitted;
          }
          else
          {
            if  ( nmhCarWakeUpState[NMH_CHANNEL_IDX] == kNmhCwupStateRelease )
            {
              nmhCarWakeUpState[NMH_CHANNEL_IDX] = kNmhCwupStateReleaseTransmitted;
            }
          }
#endif
        }
        else
        {
          /* NM-message transmit request was not successful. */
        }    
      } /* if (nmhNmMsgTimer[NMH_CHANNEL_IDX] == (tNmhTimerCounterType)0u) */
      else
      {
        nmhNmMsgTimer[NMH_CHANNEL_IDX]--;
      }

      /* Handling of the NM timeout timer (Normal Mode) */
      if ( nmhState[NMH_CHANNEL_IDX] == kNmhStateNormalMode )
      {
        /* Ensure that the message timeout timer does not underrun. */
        if ( nmhTimeoutTimer[NMH_CHANNEL_IDX] > (tNmhTimerCounterType)0u)
        {
            nmhTimeoutTimer[NMH_CHANNEL_IDX]--;  
        }

        /* Active failed mechanism. */
        /* Notify the application if NM-messages cannot be transmitted for a certain time. */
        if ( nmhTimeoutTimer[NMH_CHANNEL_IDX] == (tNmhTimerCounterType)(kNmhTimeoutTimeCounter - kNmhMsgTimeoutCounter) )
        {
          NmhIntActiveFailed( NMH_CHANNEL_SYSTEMPARA_ONLY );
        }
      }
      else
      {
        /* Handling of the Repeat Message Timer (state Repeat Message). */

        /* Check whether the Network Management Message has been sent 5 times. */        
        if (nmhRepeatMsgTimer[NMH_CHANNEL_IDX] == (tNmhTimerCounterType)0u)
        {
          NmhStateTransition( NMH_CHANNEL_NMPARA_FIRST  NMH_EVENT_FINISH_REPEAT_MSG );
        }
        else
        {
          /* Decrement the Repeat Message Timer. */
          nmhRepeatMsgTimer[NMH_CHANNEL_IDX]--;
        }
      }
      break;


    /* Handling of the Timeout timer. */
    /* The Timeout timer is reset when leaving state 'Repeat Message' and when a NM-message has been received. */
    case kNmhStateReadySleep:
      /* ESCAN00020886 */
      if ( nmhMsgConfirmedFlag[NMH_CHANNEL_IDX] == (vuint8)TRUE )
      {
        nmhMsgConfirmedFlag[NMH_CHANNEL_IDX] = (vuint8)FALSE;
        nmhTimeoutTimer[NMH_CHANNEL_IDX]     = (tNmhTimerCounterType)kNmhTimeoutTimeCounter;
      }
      /* Decrease Timeout Timer. */
      nmhTimeoutTimer[NMH_CHANNEL_IDX]--;
      /* Perform a state transition, when the Timeout Timer has expired. */
      if (nmhTimeoutTimer[NMH_CHANNEL_IDX] == (tNmhTimerCounterType)0u)
      {
        NmhStateTransition( NMH_CHANNEL_NMPARA_FIRST  kNmhEventTimeoutTtimeout );
      }
      break;


    /* Handling of the 'Wait Bus Sleep' timer. */
    /* The 'Wait Bus Sleep' timer is reset when entering Prepare Sleep Mode. */
    case kNmhStatePrepareSleep:
      nmhWaitBusSleepTimer[NMH_CHANNEL_IDX]--;
      
      /* Go to Sleep Mode, when the 'Wait Bus Sleep' timer has expired. */
      if ( nmhWaitBusSleepTimer[NMH_CHANNEL_IDX] == (tNmhTimerCounterType)0u )
      {
        NmhStateTransition( NMH_CHANNEL_NMPARA_FIRST  kNmhEventTimeoutTwbs );

        /* ESCAN00025113 */
#if defined ( VGEN_ENABLE_CCL )
#else
        /* Check for restart request (only needed when no CCL is available). */
        if ( nmhWakeUpFlag[NMH_CHANNEL_IDX] == (vuint8)TRUE )
        {
          nmhWakeUpFlag[NMH_CHANNEL_IDX] = (vuint8)FALSE;
          NmhStateTransition( NMH_CHANNEL_NMPARA_FIRST  kNmhEventWakeUp );
        }
        else
        {
          if ( nmhMsgReceivedFlag[NMH_CHANNEL_IDX] == (vuint8)TRUE )
          {
            nmhMsgReceivedFlag[NMH_CHANNEL_IDX] = (vuint8)FALSE;
            NmhStateTransition( NMH_CHANNEL_NMPARA_FIRST  kNmhEventNmhMessageReceived );
          }
        }
#endif

      }
      else
      {
        /* Call the callback function NmhIntPrepareSleep, after the 'prepare sleep time' has elapsed. */
        if (nmhWaitBusSleepTimer[NMH_CHANNEL_IDX] == (tNmhTimerCounterType)((tNmhTimerCounterType)kNmhWaitBusSleepTimeCounter-(tNmhTimerCounterType)kNmhPrepareSleepTimeCounter) )
        {
           NmhIntPrepareSleep( NMH_CHANNEL_SYSTEMPARA_ONLY );
        }
      }
      break;


    /* must be case kNmhStateSleep */
    default:
#if defined ( NMH_ENABLE_INDEXED_NM )
      NmhIntAssert( NMH_CHANNEL_SYSTEMPARA_ONLY, (vuint8)(nmhState[NMH_CHANNEL_IDX] == kNmhStateSleep), (vuint8)kNmhErrorStateOutOfRange );
#else
      NmhIntAssert( (vuint8)(nmhState[NMH_CHANNEL_IDX] == kNmhStateSleep), (vuint8)kNmhErrorStateOutOfRange );
#endif
      break;

  }
} /* PRQA S 4700 */ /* MD_Nmh_4700 */


/*******************************************************************************
** Function:    NmhMsgIndication
**
** Purpose:     Indidcation function, that a Network Management message 
**              has been received.
**
**  Called by:  Data link layer
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
void NMH_API_CALL_TYPE NmhMsgIndication( NMH_CHANNEL_SYSTEMTYPE_ONLY )
{
  /* Set NM-message received flag at reception of Network Management Message. */
  /* This function is not reentrant! */
  nmhMsgReceivedFlag[NMH_CHANNEL_IDX_IND] = (vuint8)TRUE;
}


/*******************************************************************************
** Function:    NmhWakeUpRequest
**
** Purpose:     Notification about wake-up event. 
**              I.d. any message on CAN-bus that is sleeping.
**
**  Called by:  Data link layer
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
void NMH_API_CALL_TYPE NmhWakeUpRequest( NMH_CHANNEL_SYSTEMTYPECAN_ONLY )
{
  /* Set wake-up flag. */
  nmhWakeUpFlag[NMH_CHANNEL_IDX_IND] = (vuint8)TRUE;
}


/*******************************************************************************
** Function:    NmhBusCriticalFailure
**
** Purpose:     Notification of a critical error on the bus.
**
**  Called by:  Data link layer
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
void NMH_API_CALL_TYPE NmhBusCriticalFailure( NMH_CHANNEL_SYSTEMTYPECAN_ONLY )
{
#if defined ( NMH_ENABLE_CHANNEL_INDIRECTION )
  V_MEMRAM0 V_MEMRAM1 NmhChannelHandle V_MEMRAM2 nmhChannel = NmhCanToNmChannel( NMH_CHANNEL_SYSTEMPARA_ONLY );
#endif

  /* Do not start the BusOff recovery if it is still in BusOff recovery.
     This does normally not happen, due to no message is sent during BusOff recovery.
     However the CAN-Driver of some micros could alert a BusOff twice.
  */
  if ( nmhBusOffRecoveryTimer[NMH_CHANNEL_IDX] == (tNmhTimerCounterType)0u )
  {
    /* BusOff handling of data link layer. */  
    NmhIntBusOffStart( NMH_CHANNEL_SYSTEMPARA_FIRST  (vuint8)(nmhBusOffCounter[NMH_CHANNEL_IDX]) );

    /* Count consecutive BusOffs and ensure that the counter does not overflow. */
    if ( nmhBusOffCounter[NMH_CHANNEL_IDX] != (tNmhTimerCounterType)(kNmhBusOffCounterMax) )
    {
      nmhBusOffCounter[NMH_CHANNEL_IDX]++;
    }

    if ( nmhBusOffCounter[NMH_CHANNEL_IDX] == (tNmhTimerCounterType)1u )
    {
      /* First BusOff. */  
      nmhBusOffRecoveryTimer[NMH_CHANNEL_IDX] = (tNmhTimerCounterType)(kNmhBusOffRecoveryTimeCounter1 + 1u);
    }
    else
    {
      /* Consecutive BusOff. */
      nmhBusOffRecoveryTimer[NMH_CHANNEL_IDX] = (tNmhTimerCounterType)(kNmhBusOffRecoveryTimeCounter2 + 1u);
    }
  }
}


/*******************************************************************************
** Function:    NmhRequestCommState
**
** Purpose:     Request to change the bus-communication state.
**
**  Called by:  Data link layer
**
**  Parameter:  
**              commState : Current/new communication state.
**                          Valid values are: NMH_READY_SLEEP, NMH_NORMAL_OPERATION    
**
**  Returncode: -
**
**  Misc:       This function is re-entrant!
*******************************************************************************/
void NMH_API_CALL_TYPE NmhRequestCommState( NMH_CHANNEL_SYSTEMTYPE_FIRST  tNmhCommStateType commState )
{
  /* Set the communication state. */
  nmhCommState[NMH_CHANNEL_IDX_IND] = commState;
}


#if defined ( NMH_ENABLE_CAR_WUP )
/*******************************************************************************
** Function:    NmhCarWupRequest
**
** Purpose:     Request to wake up the external networks.
**
**  Called by:  Application / CarWakeUpManager
**
**  Parameter:  
**              carWupState : current/new communication state for external networks.
**                            Valid values are: NMH_READY_SLEEP, NMH_NORMAL_OPERATION    
**
**  Returncode: -
**
**  Misc:       This function is re-entrant!
*******************************************************************************/
void NMH_API_CALL_TYPE NmhCarWupRequest( NMH_CHANNEL_SYSTEMTYPE_FIRST  tNmhCommStateType carWupState )
{
#if defined ( NMH_ENABLE_CHANNEL_INDIRECTION )
  V_MEMRAM0 V_MEMRAM1 NmhChannelHandle V_MEMRAM2 nmhChannel = NmhCanToNmChannel( NMH_CHANNEL_SYSTEMPARA_ONLY );
#endif

  /* Set the flag for communication state for external networks. */
  if ( carWupState == NMH_NORMAL_OPERATION )
  {
    nmhCarWakeUpState[NMH_CHANNEL_IDX] = kNmhCwupStateRequest;
  }
  else
  {
    /* carWupState == NMH_READY_SLEEP */
    nmhCarWakeUpState[NMH_CHANNEL_IDX] = kNmhCwupStateRelease;
  }
}
#endif


/*******************************************************************************
** Function:    NmhMsgConfirmation
**
** Purpose:     Confirmation of the successful transmission of a NM-message.
**
**  Called by:  Data link layer
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
void NMH_API_CALL_TYPE NmhMsgConfirmation( NMH_CHANNEL_SYSTEMTYPE_ONLY )
{
  /* The NM-message has been transmitted successfully 
     and the NM-message Timeout Timer has to be reset by the NmhTask. */
  nmhMsgConfirmedFlag[NMH_CHANNEL_IDX_IND]  = (vuint8)TRUE;
}



/*******************************************************************************
** Function:    NmhTxObjConfirmed
**
** Purpose:     Confirmation of sucessful transmission of any message.
**
**  Called by:  Data link layer
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
void NMH_API_CALL_TYPE NmhTxObjConfirmed( NMH_CHANNEL_SYSTEMTYPE_ONLY )
{
  /* Break into consecutive BusOff events. */
  nmhBusOffCounter[NMH_CHANNEL_IDX_IND] = (tNmhTimerCounterType)0u;
}



/*******************************************************************************
** Function:    NmhGetState
**
** Purpose:     Return the internal state of the network management.
**
**  Called by:  Application
**
**  Parameter:  -
**
**  Returncode: State of Network Management
*******************************************************************************/
tNmhStateType NMH_API_CALL_TYPE NmhGetState( NMH_CHANNEL_SYSTEMTYPE_ONLY )
{
  return nmhState[NMH_CHANNEL_IDX_IND];
}


/*******************************************************************************
** Function:    NmhValidateShutdown
**
** Purpose:     Validation of network shutdown.
**              Detection of passive restart requests during network shutdown.
**
**  Called by:  Application
**
**  Parameter:  -
**
**  Returncode: 
**              NMH_SHUTDOWN_VALID  : Network shutdown is still valid
**              NMH_RESTART_REQ     : Network restart request is pending
**              NMH_SHUTDOWN_FAILED : Network shutdown has been aborted
*******************************************************************************/
tNmhShutdownType NMH_API_CALL_TYPE NmhValidateShutdown( NMH_CHANNEL_SYSTEMTYPE_ONLY )
{
#if defined ( NMH_ENABLE_CHANNEL_INDIRECTION )
  V_MEMRAM0 V_MEMRAM1 NmhChannelHandle V_MEMRAM2 nmhChannel = NmhCanToNmChannel( NMH_CHANNEL_SYSTEMPARA_ONLY );
#endif

  tNmhShutdownType state;

  if ( nmhState[NMH_CHANNEL_IDX] == kNmhStateSleep )
  {
    if (( nmhWakeUpFlag[NMH_CHANNEL_IDX] == (vuint8)TRUE ) || (  nmhMsgReceivedFlag[NMH_CHANNEL_IDX] == (vuint8)TRUE ))
    {
      state = NMH_RESTART_REQ;
    }
    else
    {
      state = NMH_SHUTDOWN_VALID;
    }
  }
  else
  {
    state = NMH_SHUTDOWN_FAILED;
  }

  return state;
}


/*******************************************************************************
** Function:    NmhGetUserDataBuffer
**
** Purpose:     Get access to user data buffer.
**
**  Called by:  Application
**
**  Parameter:  -
**
**  Returncode: Pointer to user data buffer.
*******************************************************************************/
vuint8* NMH_API_CALL_TYPE NmhGetUserDataBuffer( NMH_CHANNEL_SYSTEMTYPE_ONLY )
{
  return ( &nmhMsgData[NMH_CHANNEL_IDX_IND][kNmhUserData] );
}


/*******************************************************************************
** Function:    NmhRxObjReceived
**
** Purpose:     Indication function for the reception of CAN messages.
**
**  Called by:  Data link layer
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
void NMH_API_CALL_TYPE NmhRxObjReceived( NMH_CHANNEL_SYSTEMTYPE_ONLY )
{
  /* Break into consecutive BusOff events. */
  nmhBusOffCounter[NMH_CHANNEL_IDX_IND] = (tNmhTimerCounterType)0u;
}





/*******************************************************************************
**
** local functions
**
*******************************************************************************/



/*******************************************************************************
** Function:    NmhStateTransition
**
** Purpose:     Perform a transition to another state of the state machine.
**              This function is not re-entrant.
**
**  Called by:  NmhTask(), NmhInit
**
**  Parameter:  
**
**              event : An event that has occured.
**
**  Returncode: -
**
**  Misc:       The usage of the tNmhEventType (int) instead of vuint8 wastes, 
**              on 16/32 bit microcontrollers, ROM space.
**              But due to type checks this drawback is accepted. 
**              On the other hand can the performance of int be higher than of vuint8.
*******************************************************************************/
static void NMH_INTERNAL_CALL_TYPE NmhStateTransition( NMH_CHANNEL_NMTYPE_FIRST  tNmhEventType event )
{
  tNmhStateType LastState;        /* Last state of the state machine. */

  /* Store the current state and acquire a new state. */
  LastState                  = nmhState[NMH_CHANNEL_IDX];
  nmhState[NMH_CHANNEL_IDX]  = kNmhStateMatrix[nmhState[NMH_CHANNEL_IDX]][event];
  
  /* Execute 'state enter' and 'state exit' functions, if the state has changed. */
  if (LastState != nmhState[NMH_CHANNEL_IDX])
  {
    kNmhExitStateFctMatrix[LastState]( NMH_CHANNEL_NMPARA_ONLY );
    kNmhEnterStateFctMatrix[nmhState[NMH_CHANNEL_IDX]]( NMH_CHANNEL_NMPARA_ONLY );
  }
  else
  {
    /* Check whether an invalid state has been reached. */
    
    /* .. */
    
  }

}


/*******************************************************************************
** Function:    NmhEnterStateRepeatMsg()
**
** Purpose:     State transition function, that is executed prior to entering
**              the state Repeat Message.
**
**  Called by:  NmhStateTransition()
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
static void NMH_INTERNAL_CALL_TYPE NmhEnterStateRepeatMsg( NMH_CHANNEL_NMTYPE_ONLY )
{
  /* Timer/Counter handling */
  /* Reset the 'Repeat Message' timer. */
  nmhRepeatMsgTimer[NMH_CHANNEL_IDX] = (tNmhTimerCounterType)((kNmhRepeatMsgCounts - 1u) * kNmhMsgCycleTimeCounter);

  /* Transmit a NM-message when entering the Repeat Message state. */
  nmhNmMsgTimer[NMH_CHANNEL_IDX] = (tNmhTimerCounterType)0u;

  /* Notify the application, that the network mode was started. */
  NmhIntNetStart( NMH_CHANNEL_SYSTEMPARA_IND_ONLY );

  /* Reset the Timeout Time timer */
  nmhTimeoutTimer[NMH_CHANNEL_IDX] = (tNmhTimerCounterType)kNmhTimeoutTimeCounter;
}  


/*******************************************************************************
** Function:    NmhExitStateRepeatMsg()
**
** Purpose:     State transition function, that is executed before leaving
**              the state Repeat Message.
**
**  Called by:  NmhStateTransition()
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
static void NMH_INTERNAL_CALL_TYPE NmhExitStateRepeatMsg( NMH_CHANNEL_NMTYPE_ONLY )
{
  /* Setting of the network management state that is transmitted by the NM-message. */
  nmhMsgData[NMH_CHANNEL_IDX][kNmhSystemByte] &= (vuint8)kNmhInverseNmStateMask; /* ESCAN00011928 */
  nmhMsgData[NMH_CHANNEL_IDX][kNmhSystemByte] |= (vuint8)(kNmhNormalOperationFromStart & kNmhNmStateMask);
}


/*******************************************************************************
** Function:    NmhEnterStateNormalMode()
**
** Purpose:     State transition function, that is executed prior to entering
**              the state Normal Mode.
**
**  Called by:  NmhStateTransition()
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
static void NMH_INTERNAL_CALL_TYPE NmhEnterStateNormalMode( NMH_CHANNEL_NMTYPE_ONLY )
{
  /* Reset the Timeout Time timer */ /* ESCAN00011837 */
  nmhTimeoutTimer[NMH_CHANNEL_IDX] = (tNmhTimerCounterType)kNmhTimeoutTimeCounter;
}


/*******************************************************************************
** Function:    NmhExitStateNormalMode()
**
** Purpose:     State transition function, that is executed before leaving
**              state Normal Mode.
**
**  Called by:  NmhStateTransition()
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
static void NMH_INTERNAL_CALL_TYPE NmhExitStateNormalMode( NMH_CHANNEL_NMTYPE_ONLY )
{
  /* Ensure that nmhTimeoutTimer cannot underrun */
  if (nmhTimeoutTimer[NMH_CHANNEL_IDX] == (tNmhTimerCounterType)0u)
  {
    nmhTimeoutTimer[NMH_CHANNEL_IDX] = 1;
  }

#if defined ( NMH_ENABLE_INDEXED_NM ) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  /* Dummy statement to avoid compiler warnings. */
  if ( NMH_CHANNEL_NMPARA_ONLY == (vuint8)0u )
  {
  }
#endif
}


/*******************************************************************************
** Function:    NmhEnterStateReadySleep()
**
** Purpose:     State transition function, that is executed prior to entering
**              the state 'Ready Sleep'.
**
**  Called by:  NmhStateTransition()
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
static void NMH_INTERNAL_CALL_TYPE NmhEnterStateReadySleep( NMH_CHANNEL_NMTYPE_ONLY )
{
  /* .. nothing to do .. */

#if defined ( NMH_ENABLE_INDEXED_NM ) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  /* Dummy statement to avoid compiler warnings. */
  if ( NMH_CHANNEL_NMPARA_ONLY == (vuint8)0u )
  {
  }
#endif
}


/*******************************************************************************
** Function:    NmhExitStateReadySleep()
**
** Purpose:     State transition function, that is executed before leaving
**              the state 'Ready Sleep'.
**
**  Called by:  NmhStateTransition()
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
static void NMH_INTERNAL_CALL_TYPE NmhExitStateReadySleep( NMH_CHANNEL_NMTYPE_ONLY )
{
  /* Reset the NM-message confirmation flag. */
  nmhMsgConfirmedFlag[NMH_CHANNEL_IDX] = (vuint8)FALSE;

  /* Reset the NM-message timer in order to transmit a NM-message when entering Normal Mode */
  nmhNmMsgTimer[NMH_CHANNEL_IDX] = (tNmhTimerCounterType)0u;

  /* Setting of the network management state that is transmitted by the NM-message. */
  nmhMsgData[NMH_CHANNEL_IDX][kNmhSystemByte] &= (vuint8)kNmhInverseNmStateMask;
  nmhMsgData[NMH_CHANNEL_IDX][kNmhSystemByte] |= (vuint8)(kNmhNormalOperationFromReadySleep & kNmhNmStateMask);
}


/*******************************************************************************
** Function:    NmhEnterStatePrepareSleep()
**
** Purpose:     State transition function, that is executed prior to entering
**              the state 'Prepare Sleep'.
**
**  Called by:  NmhStateTransition()
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
static void NMH_INTERNAL_CALL_TYPE NmhEnterStatePrepareSleep( NMH_CHANNEL_NMTYPE_ONLY )
{
  /* Notify the application, that the network mode was stopped. */
  NmhIntNetStop( NMH_CHANNEL_SYSTEMPARA_IND_ONLY );

  /* Reset the Bus Sleep Time timer. */  
  nmhWaitBusSleepTimer[NMH_CHANNEL_IDX] = (tNmhTimerCounterType)kNmhWaitBusSleepTimeCounter;
}


/*******************************************************************************
** Function:    NmhExitStatePrepareSleep()
**
** Purpose:     State transition function, that is executed before leaving
**              the state 'Prepare Sleep'.
**
**  Called by:  NmhStateTransition()
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
static void NMH_INTERNAL_CALL_TYPE NmhExitStatePrepareSleep( NMH_CHANNEL_NMTYPE_ONLY )
{
  /* Setting of the network management state that is transmitted by the NM-message. */
  nmhMsgData[NMH_CHANNEL_IDX][kNmhSystemByte] &= (vuint8)kNmhInverseNmStateMask; /* ESCAN00011928 */
  nmhMsgData[NMH_CHANNEL_IDX][kNmhSystemByte] |= (vuint8)(kNmhStartFromPrepareSleep & kNmhNmStateMask);
}


/*******************************************************************************
** Function:    NmhEnterStateSleep()
**
** Purpose:     State transition function, that is executed prior to entering
**              the state 'Sleep'.
**
**  Called by:  NmhStateTransition()
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
static void NMH_INTERNAL_CALL_TYPE NmhEnterStateSleep( NMH_CHANNEL_NMTYPE_ONLY )
{
#if defined ( NMH_ENABLE_CHANNEL_INDIRECTION )
  V_MEMRAM0 V_MEMRAM1 NmhChannelHandle V_MEMRAM2 channel    = NmhNmToCanChannel( NMH_CHANNEL_IDX );
#endif

  /* Stop BusOff handling when entering bus-sleep mode. */
  if ( nmhBusOffRecoveryTimer[NMH_CHANNEL_IDX] > (tNmhTimerCounterType)0u )
  {
    /* Restore CAN message reception as soon as possible. */
    if ( ( ( nmhBusOffRecoveryTimer[NMH_CHANNEL_IDX] >= (tNmhTimerCounterType)kNmhBusOffRecoveryTimeCounter1 ) &&
           ( nmhBusOffCounter[NMH_CHANNEL_IDX] == (tNmhTimerCounterType )1u) ) ||
         ( ( nmhBusOffRecoveryTimer[NMH_CHANNEL_IDX] >= (tNmhTimerCounterType)kNmhBusOffRecoveryTimeCounter2 ) &&
           ( nmhBusOffCounter[NMH_CHANNEL_IDX] > (tNmhTimerCounterType)1u ) )
       )
    {
      NmhIntBusOffRxRestore( NMH_CHANNEL_SYSTEMPARA_ONLY );
    }

    /* Reset BusOff recovery. */
    nmhBusOffRecoveryTimer[NMH_CHANNEL_IDX] = (tNmhTimerCounterType)0u;
    nmhBusOffCounter[NMH_CHANNEL_IDX]       = (tNmhTimerCounterType)0u;
    /* Stop BusOff handling. */
    NmhIntBusOffEnd( NMH_CHANNEL_SYSTEMPARA_ONLY );
  }

  /* Notify application about state change. */
  NmhIntSleep( NMH_CHANNEL_SYSTEMPARA_ONLY );
}


/*******************************************************************************
** Function:    NmhExitStateSleep()
**
** Purpose:     State transition function, that is executed before leaving
**              the state 'Sleep'.
**
**  Called by:  NmhStateTransition()
**
**  Parameter:  -
**
**  Returncode: -
*******************************************************************************/
static void NMH_INTERNAL_CALL_TYPE NmhExitStateSleep( NMH_CHANNEL_NMTYPE_ONLY )
{
  /* Setting of the network management state that is transmitted by the NM-message. */
  nmhMsgData[NMH_CHANNEL_IDX][kNmhSystemByte] &= (vuint8)kNmhInverseNmStateMask; /* ESCAN00011928 */
  nmhMsgData[NMH_CHANNEL_IDX][kNmhSystemByte] |= (vuint8)(kNmhStartFromSleep & kNmhNmStateMask);
}


/*******************************************************************************
  Consistency checks
*******************************************************************************/

/* Check consistency of NMH_xxx_TESTDEBUG */

#if defined ( NMH_ENABLE_TESTDEBUG ) || defined ( NMH_DISABLE_TESTDEBUG )
#else
  #error "NM-High consistency error: NMH_xxx_TESTDEBUG must be enabled or disabled."
#endif
#if defined ( NMH_ENABLE_TESTDEBUG ) && defined ( NMH_DISABLE_TESTDEBUG )
  #error "NM-High consistency error: NMH_xxx_TESTDEBUG must be either enabled or disabled."
#endif

/* Check consistency of NMH_xxx_INDEXED_NM */

#if defined ( NMH_ENABLE_INDEXED_NM ) || defined ( NMH_DISABLE_INDEXED_NM )
#else
  #error "NM-High consistency error: NMH_xxx_INDEXED_NM must be enabled or disabled."
#endif
#if defined ( NMH_ENABLE_INDEXED_NM ) && defined ( NMH_DISABLE_INDEXED_NM )
  #error "NM-High consistency error: NMH_xxx_INDEXED_NM must be either enabled or disabled."
#endif


/*******************************************************************************
  Verify the configuration of defines
*******************************************************************************/

#if defined ( NMH_ENABLE_INDEXED_NM )
#else

  /* Compare ranges of the PrepareSleepTime and WaitBusSleepTime. */
  #if ( kNmhPrepareSleepTime >= kNmhWaitBusSleepTime )
    #error "NM-High configuration error: kNmhPrepareSleepTime has to be less kNmhWaitBusSleepTime."
  #endif

  /* Compare ranges of the NM-Msg Rx/Tx Timeout and NM-Msg Tx Timeout. */
  #if (  kNmhMsgTimeout > kNmhTimeoutTime )
    #error "NM-High configuration error: kNmhMsgTimeoutTime has to be less or equal kNmhTimeoutTime."
  #endif

  /* Compare ranges of the NM Message Timer and NM Message Timeout Timer. */
  #if ( kNmhMsgCycleTime >= kNmhMsgTimeout )
    #error "NM-High configuration error: the NM Message Timeout Time has to be greater than the NM Message Cycle Time."
  #endif

  /* All time definitions must be a multiple of the NmhTask() cycle time. */
  #if ( (kNmhMsgCycleTime % kNmhCycleTime) != 0u)
    #error "NM-High configuration error: NM-message cycle time has to be a multiple of the NmhTask() cycle."
  #endif
  #if ( (kNmhTimeoutTime % kNmhCycleTime) != 0u)
    #error "NM-High configuration error: NM-message Timeout time has to be a multiple of the NmhTask() cycle."
  #endif
  #if ( (kNmhWaitBusSleepTime % kNmhCycleTime) != 0u)
    #error "NM-High configuration error: Wait Bus Sleep time has to be a multiple of the NmhTask() cycle."
  #endif
  #if ( (kNmhPrepareSleepTime % kNmhCycleTime) != 0u)
    #error "NM-High configuration error: Prepare Sleep time has to be a multiple of the NmhTask() cycle."
  #endif
  #if ( (kNmhMsgTimeout % kNmhCycleTime) != 0u)
    #error "NM-High configuration error: NM-message timeout time has to be a multiple of the NmhTask() cycle."
  #endif
  #if ( (kNmhBusOffRecoveryTime1 % kNmhCycleTime) != 0u)
    #error "NM-High configuration error: BusOff recovery time 1 has to be a multiple of the NmhTask() cycle."
  #endif
  #if ( (kNmhBusOffRecoveryTime2 % kNmhCycleTime) != 0u)
    #error "NM-High configuration error: BusOff recovery time 2 has to be a multiple of the NmhTask() cycle."
  #endif

#endif /* defined ( NMH_ENABLE_INDEXED_NM ) */

#endif /* NM_TYPE_NMHIGH */


/*******************************************************************************
* Organi check
*******************************************************************************/


/* module specific MISRA deviations:
   MD_Nmh_0883:
     Reason:     Preprocessor code is filtered anyway. No need for multiple-include protection.
     Risk:       Header file is being included multiple times.
     Prevention: Assert correct usage during review.
   MD_Nmh_3218:
     Reason:     Not all compilers can cope with static const at function scope (ESCAN00032240).
     Risk:       Developer is tempted to use static const variables in other functions although it is not designated.
     Prevention: Assert that the variables are used in one function only during review.
   MD_Nmh_3451:
     Reason:     Function may be multiply defined due to historical reasons.
     Risk:       Deviations between the declaration.
     Prevention: Covered by code review.
   MD_Nmh_4700:
     Reason:     Metric serves only as information.
     Risk:       Component becomes too complex.
     Prevention: Component complexity is covered by reviews.
*/

/*****   STOPSINGLE_OF_MULTIPLE_COMMENT    ******/
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
