/* PRQA S 0883 EOF */ /* this file is intentionally included multiple times */
/* file: tcb.h, automatically generated by GENTMS470.EXE, Version: 3.10 */
/* from: F:\PROJECTS\ADR-PORSCHE\PORSCHE_ADR_DEVELOPMENT_TRUNK\MOD\MOD_OSEK_DYN\CFG\PAG_ADR.oil */
/* at  : Wed Feb 22 07:46:34 2012 */
/* License 2400100185 for S1nn GmbH u. Co. KG, Infotainment and Connectivity */
/* Implementation: TMS470R1 */
/* Version of general code: 3.54b */

#if defined USE_QUOTE_INCLUDES
 #include "vrm.h"
#else
 #include <vrm.h>
#endif
#define osdVrmGenMajRelNum 3
#define osdVrmGenMinRelNum 10
#if defined USE_QUOTE_INCLUDES
 #include "vrm.h"
#else
 #include <vrm.h>
#endif

#if osdPreTCB
#ifndef _PRE_TCB_H
#define _PRE_TCB_H

#define osdCompiler osdCompilerTIARM7

#define osdLib 0
#define CC ECC1

#define STATUS_LEVEL EXTENDED_STATUS

#define osdFullPreempt 0
#define osdMixedPreempt 1
#define osdNonPreempt 0

#define osdNumberOfAllTasks 6
#define osdNumberOfBasicTasks 0
#define osdNumberOfExtendedTasks 6
#define osdNumberOfPriorities 14
#define osdNumberOfAllResources 8
#define osdNumberOfTaskResources 8
#define osdNumberOfInterruptResources 0
#define osdNumberOfInternalResources 0
#define osdNumberOfAlarms 14
#define osdNumberOfSysAlarms 14
#define osdNumberOfVarAlarms 14
#define osdNumberOfVarHeapAlarms 14
#define osdNumberOfStatHeapAlarms 0
#define osdNumberOfAlarmCallback 3
#define osdNumberOfAlarmSetEvent 11
#define osdNumberOfAlarmActivateTask 0
#define osdNumberOfCounters 1
#define osdUseCounterAPI 0
#define osdStackCheck 1

#define osdSuppressFilenames 1

#define osdEnableAssertions 1

#define osdORTIDebug 0
#define osdORTIVersion 210

#define osdORTIEnabled 0

#define osdGHSDebugSupport 0


#ifndef osdTcbDefinesOnly
typedef uint16 EventMaskType;
#define osdEventMaskTypeSize 2

#endif

#define osdEnableProcedures 0

#define osdEnableContextOverlay 0

#define osdNumberOfAppModes 1

#define OSDEFAULTAPPMODE 0x01

#define osdOSEK2_2 1

#define osdOSEKVersionSpec 220

#define osdGetServiceIdMacros 1
#define osdParameterAccessMacros 0

#define osdNumberOfSemaphores 0

#define osdTasksInUserMode 0
#define osdUseAsmIntFuncs 0
#define osdStartupStack _osTaskStack0
#define osdStartupStackSize 600
#define osdSystemStackSize 300

#define osdSupervisorStackSize 200

#define osdRegisterOpt 0

#define osdRTICMP 0xffffff10UL
#define osdRTICmpFlag 0x80
#define osdRTICmpENA 0x20
#define osdSysTimer 1
#define osdRTICNTR 0xffffff00UL
#define osdRTIPCTL 0xffffff04UL
#define osdRTICINT 0xffffff18UL
#define osdRTICNTEN 0xffffff1CUL
#define osdFIRQPR 0xffffff2CUL
#define osdINTREQ 0xffffff30UL
#define osdREQMASK 0xffffff34UL
#define osdTMS470PVF24 0
#define osdTMS470R1_SE 0
#define osdTMS470R1 1
#define osdTMS470_PL2002EX 0
#define osdIEM 0
#define osdEnableIntNesting 0
#define osdRTIIntFlag 0x00000004
#define osdThumbMode 0
#define osdIRQMaxNesting 4

#define osdIrqStackSize 380

#define osdApplSWIHandler _osUnhandledException
#define osOwnApplSWIHandler 0
#define osdUseHighResolutionTimer 0
#define osdUserDefinedSystemTimer 0
#define osdClockReloadReg 30000
#define osdClockDividerReg 1
#define OSTICKDURATION 1000000UL   /* actual duration of a system counter tick in nanoseconds */

#define TICKTYPE_MAX 0xffffffffU

/* max(number of priority,number of tasks) */

#define osdRTSize 1

#define osdErrorHook 1
#define osdPreTaskHook 0
#define osdPostTaskHook 0
#define osdStartupHook 1
#define osdShutdownHook 0
#endif /* _PRE_TCB_H (double include preventer) */
#endif /* osdPreTCB */

/* Start of invariant part */
#if osdPostTCB
/* (POST because types have to be defined in OSEK.H) */

#if (osdRTSize > 1)
   extern osqRAM1 osqRAM2 osPrioFlagType osqRAM3 osQReadyPrios[osdRTSize];
#else
   extern osqRAM1 osqRAM2 osPrioFlagType osqRAM3 osQReadyPrios;
#endif

   extern osqTcbRAM1 osqTcbRAM2 EventMaskType osqTcbRAM3 osTcbWaitEventMask[osdNumberOfExtendedTasks];



#if (CC==BCC2) || (CC==ECC2)
   #if (osdNumberOfPriorities > 0)
      extern osqTcbRAM1 osqTcbRAM2 osQEntryCountType osqTcbRAM3 osQReadyTaskHead[osdNumberOfPriorities];
      extern osqTcbRAM1 osqTcbRAM2 osQEntryCountType osqTcbRAM3 osQReadyTaskTail[osdNumberOfPriorities];
      osqROM0 extern osqROM1 const osqROM2 osQEntryCountType osqROM3 oskQMaxActivations[osdNumberOfPriorities];
   #else
      extern osqTcbRAM1 osqTcbRAM2 osQEntryCountType osqTcbRAM3 osQReadyTaskHead[1];
      extern osqTcbRAM1 osqTcbRAM2 osQEntryCountType osqTcbRAM3 osQReadyTaskTail[1];
      osqROM0 extern osqROM1 const osqROM2 osQEntryCountType osqROM3 oskQMaxActivations[1];
   #endif
#else
   #if (osdNumberOfPriorities > 0)
      extern osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQReadyTask[osdNumberOfPriorities];
   #else
      extern osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQReadyTask[1];
   #endif
#endif


#if (osdNumberOfAllTasks > 0)
   #if osdMixedPreempt
     osqROM0 extern osqROM1 const osqROM2 osTaskPreemptionType osqROM3 oskTcbTaskPreemption[osdNumberOfAllTasks];
   #endif
   #if osdEnableProcedures
     osqROM0 extern osqROM1 const osqROM2 osContextOverlayType osqROM3 oskTcbContextOverlay[osdNumberOfAllTasks];
   #endif

  osqROM0 extern osqROM1 const osqROM2 osTaskFlagType osqROM3 oskTcbTaskFlags[osdNumberOfAllTasks];
#if (osdNumberOfExtendedTasks > 0) || osdLib
   extern osqTcbRAM1 osqTcbRAM2 EventMaskType osqTcbRAM3 osTcbSetEventMask[osdNumberOfExtendedTasks];
#endif
#else
   #if osdMixedPreempt
      osqROM0 extern osqROM1 const osqROM2 osTaskPreemptionType osqROM3 oskTcbTaskPreemption[1];
   #endif
   #if osdEnableProcedures
      osqROM0 extern osqROM1 const osqROM2 osContextOverlayType osqROM3 oskTcbContextOverlay[1];
   #endif
   #if STATUS_LEVEL == EXTENDED_STATUS
      osqROM0 extern osqROM1 const osqROM2 osTaskFlagType osqROM3 oskTcbTaskFlags[1];
   #endif
#if (osdNumberOfExtendedTasks > 0) || osdLib
      extern osqTcbRAM1 osqTcbRAM2 EventMaskType osqTcbRAM3 osTcbSetEventMask[1];
#endif                                                 
#endif

#if ((CC == BCC2) || (CC == ECC2))
   #if (osdNumberOfPriorities > 0)
      extern osqROM0 osqPTcbRAM1 osqPTcbRAM2 TaskType osqPTcbRAM3 * osqROM1 const osqROM2 osqROM3 oskQActivationQueues[osdNumberOfPriorities];
   #else
      extern osqROM0 osqPTcbRAM1 osqPTcbRAM2 TaskType osqPTcbRAM3 * osqROM1 const osqROM2 osqROM3 oskQActivationQueues[1];
   #endif

   #if (osdNumberOfAllTasks > 0)
      extern osqTcbRAM1 osqTcbRAM2 osActivationCountType osqTcbRAM3 osTcbActivationCount[osdNumberOfAllTasks];
   #else
      extern osqTcbRAM1 osqTcbRAM2 osActivationCountType osqTcbRAM3 osTcbActivationCount[1];
   #endif
#endif

#if (osdNumberOfAllTasks > 0)
   extern osqTcbRAM1 osqTcbRAM2 osTaskStateType osqTcbRAM3 osTcbTaskState[osdNumberOfAllTasks];
   extern osStackPtrType osqTcbRAM1 osqTcbRAM2 osqTcbRAM3 osTcbSP[osdNumberOfAllTasks];
   #if osdORTIDebug
    extern osqTcbRAM1 osqTcbRAM2 osPrioType osqTcbRAM3 osTcbActualPrio[osdNumberOfAllTasks];
    extern osqTcbRAM1 osqTcbRAM2 uint8 osqTcbRAM3 osTcbORTIServiceId[osdNumberOfAllTasks];
   #endif
   #if STATUS_LEVEL == EXTENDED_STATUS
    #if (osdNumberOfInternalResources > 0) || (osdNumberOfInterruptResources > 0)
     extern osqTcbRAM1 osqTcbRAM2 uint8 osqTcbRAM3 osTcbResourceCounter[osdNumberOfAllTasks];
    #endif
   #endif
   #if osdEnableContextOverlay
    extern osqTcbRAM1 osqTcbRAM2 uint8 osqTcbRAM3 osTcbReturnAddressState[osdNumberOfAllTasks];
   #endif

   osqROM0 extern osStackPtrType osqROM1 const osqROM2 osqROM3 oskTcbStackTop[osdNumberOfAllTasks];
#if osdStackCheck
   osqROM0 extern osStackPtrType osqROM1 const osqROM2 osqROM3 oskTcbStackBottom[osdNumberOfAllTasks];
#endif

   osqROM0 extern osTaskFctType osqROM1 const osqROM2 osqROM3 oskTcbTaskStartAddress[osdNumberOfAllTasks];
   osqROM0 extern osqROM1 const osqROM2 osPrioType osqROM3 oskTcbHomePrio[osdNumberOfAllTasks];
   osqROM0 extern osqROM1 const osqROM2 osActivationCountType osqROM3 oskTcbAllowedActivations[osdNumberOfAllTasks];

   osqROM0 extern osqROM1 const osqROM2 osPrioFlagType osqROM3 oskTcbReadyPrioMask[osdNumberOfAllTasks];
   
   #if (osdRTSize > 1)
      osqROM0 extern osqROM1 const osqROM2 osPrioOffsetType osqROM3 oskTcbReadyPrioOffset[osdNumberOfAllTasks];
   #endif

#else
   extern osqTcbRAM1 osqTcbRAM2 osTaskStateType osqTcbRAM3 osTcbTaskState[1];
   extern osStackPtrType osqTcbRAM1 osqTcbRAM2 osqTcbRAM3 osTcbSP[1];
   #if osdORTIDebug
   extern osqTcbRAM1 osqTcbRAM2 osPrioType osqTcbRAM3 osTcbActualPrio[1];
   extern osqTcbRAM1 osqTcbRAM2 uint8 osqTcbRAM3 osTcbORTIServiceId[1];
   #endif

   #if STATUS_LEVEL == EXTENDED_STATUS
   #if (osdNumberOfInternalResources > 0) || (osdNumberOfInterruptResources > 0)
   extern osqTcbRAM1 osqTcbRAM2 uint8 osqTcbRAM3 osTcbResourceCounter[1];
   #endif
   #endif
   #if osdEnableContextOverlay
   extern osqTcbRAM1 osqTcbRAM2 uint8 osqTcbRAM3 osTcbReturnAddressState[1];
   #endif
   osqROM0 extern osTaskFctType osqROM1 const osqROM2 osqROM3 oskTcbTaskStartAddress[1];
   osqROM0 extern osStackPtrType osqROM1 const osqROM2 osqROM3 oskTcbStackTop[1];
#if osdStackCheck
   osqROM0 extern osStackPtrType osqROM1 const osqROM2 osqROM3 oskTcbStackBottom[1];
#endif
   osqROM0 extern osqROM1 const osqROM2 osPrioType osqROM3 oskTcbHomePrio[1];
   osqROM0 extern osqROM1 const osqROM2 osPrioFlagType osqROM3 oskTcbReadyPrioMask[1];
   osqROM0 extern osqROM1 const osqROM2 osActivationCountType osqROM3 oskTcbAllowedActivations[1];
#endif

/* resources */

#if ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed)))
#if (osdNumberOfAllResources > 0)
   extern osqTcbRAM1 osqTcbRAM2 osPrioType osqTcbRAM3 osResSavedPrio[osdNumberOfAllResources];
   #if STATUS_LEVEL == EXTENDED_STATUS
      extern osqTcbRAM1 osqTcbRAM2 osResCounterType osqTcbRAM3 osResOccupationCounter[osdNumberOfAllResources];
   #endif
   #if ((STATUS_LEVEL == EXTENDED_STATUS) && osdEnableAssertions) || osdORTIDebug
      extern osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osResActualTask[osdNumberOfAllResources];
   #endif
   
   osqROM0 extern osqROM1 const osqROM2 osPrioType osqROM3 oskResCeilingPrio[osdNumberOfAllResources];
   #if (osdRTSize > 1)
      osqROM0 extern osqROM1 const osqROM2 osPrioOffsetType osqROM3 oskResCeilingPrioOffset[osdNumberOfTaskResources];
   #endif
   osqROM0 extern osqROM1 const osqROM2 osPrioFlagType osqROM3 oskResCeilingPrioMask[osdNumberOfTaskResources];
#else
   extern osqTcbRAM1 osqTcbRAM2 osPrioType osqTcbRAM3 osResSavedPrio[1];
   #if STATUS_LEVEL == EXTENDED_STATUS
      extern osqTcbRAM1 osqTcbRAM2 osResCounterType osqTcbRAM3 osResOccupationCounter[1];
   #endif
   #if ((STATUS_LEVEL == EXTENDED_STATUS) && osdEnableAssertions) || osdORTIDebug
      extern osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osResActualTask[1];
   #endif
   
   osqROM0 extern osqROM1 const osqROM2 osPrioType osqROM3 oskResCeilingPrio[1];
   osqROM0 extern osqROM1 const osqROM2 osPrioFlagType osqROM3 oskResCeilingPrioMask[1];
#endif

#endif  /* ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed))) */

#if (osdNumberOfInternalResources > 0)
   osqROM0 extern osqROM1 const osqROM2 osPrioType osqROM3 oskResInternalCeilingPrio[osdNumberOfAllTasks];
   osqROM0 extern osqROM1 const osqROM2 osPrioFlagType osqROM3 oskResInternalCeilingPrioMask[osdNumberOfAllTasks];
   #if (osdRTSize > 1)
      osqROM0 extern osqROM1 const osqROM2 osPrioOffsetType osqROM3 oskResInternalCeilingPrioOffset[osdNumberOfAllTasks];
   #endif
#endif
/* alarms */

#if (osdNumberOfAlarms > 0)
   extern osqTcbRAM1 osqTcbRAM2 TickType osqTcbRAM3 osAlarmTime[osdNumberOfAlarms];
   #ifndef osdUseGeneratedFastAlarm
      extern osqTcbRAM1 osqTcbRAM2 uint8 osqTcbRAM3 osAlarmActivated[osdNumberOfAlarms];
      extern osqTcbRAM1 osqTcbRAM2 osHeapType osqTcbRAM3 osAlarmHeap[osdNumberOfAlarms+1];    /* Minimum Heap */
   #endif

   #if (osdNumberOfVarAlarms > 0)
   extern osqTcbRAM1 osqTcbRAM2 TickType osqTcbRAM3 osAlarmCycleTime[osdNumberOfVarAlarms];
   #endif

   osqROM0 extern osqROM1 const osqROM2 AlarmBaseType osqROM3 oskAlarmDefinitions;

   #if (osdNumberOfAlarms > 0)   
      osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskStaticAlarmTime[osdNumberOfAlarms];
      osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskStaticAlarmCycleTime[osdNumberOfAlarms];
   #endif

   #ifndef osdUseGeneratedFastAlarm
      osqROM0 extern osqROM1 const osqROM2 TaskType osqROM3 oskAlarmTask[osdNumberOfAlarms];
      #if (osdNumberOfAlarmSetEvent > 0)
        osqROM0 extern osqROM1 const osqROM2 EventMaskType osqROM3 oskAlarmEvent[osdNumberOfAlarms];
      #endif
      #if (osdNumberOfAlarmSetEvent > 0) || (osdNumberOfAlarmCallback > 0)
        osqROM0 extern osqROM1 const osqROM2 uint8 osqROM3 oskAlarmAction[osdNumberOfAlarms];
      #endif
      #if (osdNumberOfAlarmCallback > 0)
        osqROM0 extern osAlarmCallbackType osqROM1 const osqROM2 osqROM3 oskAlarmCallback[osdNumberOfAlarms];
      #endif
   #endif
#endif

#if (osdNumberOfSemaphores > 0)
   extern osqTcbRAM1 osqTcbRAM2 uint8 osqTcbRAM3 osSemaphoreState[osdNumberOfSemaphores];
   #if (osdNumberOfExtendedTasks == 0) && osdLib
   extern osqTcbRAM1 osqTcbRAM2 SemaphoreType osqTcbRAM3 osTcbWaitForSemaphore[1];
   #else
   extern osqTcbRAM1 osqTcbRAM2 SemaphoreType osqTcbRAM3 osTcbWaitForSemaphore[osdNumberOfExtendedTasks];
   #endif
#endif

#ifdef osdTestMacros
   #define osTestMacrosPreTaskHook       osPreTaskHook
   #define osTestMacrosPostTaskHook      osPostTaskHook
#else
#if osdLib
   #define osInterPreTaskHook            osPreTaskHook
   #define osInterPostTaskHook           osPostTaskHook
#else
   #define PreTaskHook                   osPreTaskHook
   #define PostTaskHook                  osPostTaskHook
#endif
#endif

#if osdLib
   #define osrRTSize                     oskRTSize 
   #define osrNumberOfPriorities         oskNumberOfPriorities
   #define osrNumberOfAllTasks           oskNumberOfAllTasks
   #define osrNumberOfAllResources       oskNumberOfAllResources
   #define osrNumberOfTaskResources      oskNumberOfTaskResources
   #define osrNumberOfInterruptResources oskNumberOfInterruptResources
   #define osrNumberOfInternalResources  oskNumberOfInternalResources
   #define osrNumberOfExtendedTasks      oskNumberOfExtendedTasks
   #define osrNumberOfAlarms             oskNumberOfAlarms
   #define osrNumberOfVarAlarms          oskNumberOfVarAlarms
   #define osrNumberOfVarHeapAlarms      oskNumberOfVarHeapAlarms
   #define osrNumberOfStatHeapAlarms     oskNumberOfStatHeapAlarms

   extern const osRTSizeType               oskRTSize;
   extern const osTaskIndexType            oskNumberOfAllTasks;
   extern const osTaskIndexType            oskNumberOfExtendedTasks;
   extern const osPrioType                 oskNumberOfPriorities;
   extern const osResourceIndexType        oskNumberOfAllResources;
   extern const osResourceIndexType        oskNumberOfTaskResources;
   extern const osResourceIndexType        oskNumberOfInterruptResources;
   extern const osResourceIndexType        oskNumberOfInternalResources;

   extern const osAlarmIndexType           oskNumberOfAlarms;
   extern const osAlarmIndexType           oskNumberOfVarAlarms;
   extern const osAlarmIndexType           oskNumberOfVarHeapAlarms;
   extern const osAlarmIndexType           oskNumberOfStatHeapAlarms;

   extern const TickType                   oskMaxAllowedValue;
   extern const TickType                   oskTicksPerBase;
   extern const TickType                   oskMinCycle;
   extern const uint8                      oskAlarmAutoStart[];

   extern const uint8                      oskTcbAutoStart[];


   extern const osVersionVariantCodingType oskLibVersionVariant;
   /* in library variant provide prototypes for interHook-functions */
   extern void osInterPreTaskHook(void);
   extern void osInterPostTaskHook(void);
   extern void osInterStartupHook(void);
   extern void osInterShutdownHook(StatusType Error);
   extern void osInterErrorHook(StatusType Error);

#else
   #define osrRTSize                      osdRTSize 
   #define osrNumberOfPriorities          osdNumberOfPriorities 
   #define osrNumberOfAllTasks            osdNumberOfAllTasks
   #define osrNumberOfAllResources        osdNumberOfAllResources
   #define osrNumberOfTaskResources       osdNumberOfTaskResources
   #define osrNumberOfInterruptResources  osdNumberOfInterruptResources
   #define osrNumberOfInternalResources   osdNumberOfInternalResources
   #define osrNumberOfExtendedTasks       osdNumberOfExtendedTasks
   #define osrNumberOfAlarms              osdNumberOfAlarms
   #define osrNumberOfVarAlarms           osdNumberOfVarAlarms
   #define osrNumberOfVarHeapAlarms       osdNumberOfVarHeapAlarms
   #define osrNumberOfStatHeapAlarms      osdNumberOfStatHeapAlarms
   /* in source code variant map hook routines directly to user functions */
   #define osInterStartupHook             StartupHook
   #define osInterShutdownHook            ShutdownHook
   #define osInterErrorHook               ErrorHook
#endif

#if osdLib
extern osStackDataType osSystemStack[];
extern osStackDataType osSupervisorStack[];
#else
extern osStackDataType osSystemStack[75];
extern osStackDataType osSupervisorStack[50];
#endif

void CanIsr_0(void);

void UART1_TxISR(void);

void UART1_RxISR(void);

void UART2_TxISR(void);

void UART2_RxISR(void);

void UART_ErrorISR(void);

void osTimerInt(void);
#endif /* osdPostTCB */
/* End of invariant part */
#if osdPostTCB
#ifndef _POST_TCB_H
#define _POST_TCB_H


/* task start functions (only for call tree) */
#if defined osdCPlusPlus
   extern "C"{
#endif
void OsHostTask_10msfunc(void);
void OsAppTask_event_100msfunc(void);
void OsSystemTask_eventfunc(void);
void OsDriverTask_1msfunc(void);
void OsMonitorTask_50msfunc(void);
void OsDatabaseTask_eventfunc(void);
#if defined osdCPlusPlus
   }
#endif

/* Tasks */
#define OsHostTask_10ms ((TaskType)0)
#define OsAppTask_event_100ms ((TaskType)1)
#define OsSystemTask_event ((TaskType)2)
#define OsDriverTask_1ms ((TaskType)3)
#define OsMonitorTask_50ms ((TaskType)4)
#define OsDatabaseTask_event ((TaskType)5)


/* Resources */

#define CK5050_WRITE_Resource ((ResourceType)0)
#define EEPROM_LockResource ((ResourceType)1)
#define UART_LockResource ((ResourceType)2)
#define CRC_LockResource ((ResourceType)3)
#define POOL_LockResource ((ResourceType)4)
#define DEH_LockResource ((ResourceType)5)
#define EEPROM_LAYOUT_LockResource ((ResourceType)6)
#define RES_SCHEDULER ((ResourceType)7)


#if ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed))) && osdEnableAssertions
osqROM0 extern osqROM1 const osqROM2 osResAccessMaskType osqROM3 oskResAccessMask[osdNumberOfAllResources][1];


#endif

/* Counter */

#define SystemTimer 0

#define OSMAXALLOWEDVALUE_SystemTimer OSMAXALLOWEDVALUE
#define OSTICKSPERBASE_SystemTimer OSTICKSPERBASE
#define OSMINCYCLE_SystemTimer OSMINCYCLE


/* Events */

#define evActivateHostTask_10ms ((EventMaskType)(0x0001))/* AUTO */
#define evActivateMonitorTask_50ms ((EventMaskType)(0x0001))/* AUTO */
#define evActivateDriverTask_1ms ((EventMaskType)(0x0001))/* AUTO */
#define evActivateAppTask_event_100ms ((EventMaskType)(0x0001))/* AUTO */
#define evDatabaseCyclicEepromWrite ((EventMaskType)(0x0001))/* AUTO */
#define evActivateSystemTask_event ((EventMaskType)(0x0001))/* AUTO */
#define evSystemTaskShutdown ((EventMaskType)(0x0002))/* AUTO */
#define evSystemTaskVoltageState ((EventMaskType)(0x0004))/* AUTO */
#define evSystemTask_CSHDL_Request ((EventMaskType)(0x0008))/* AUTO */
#define evAppTaskERMPending ((EventMaskType)(0x0002))/* AUTO */
#define evTriggerWD ((EventMaskType)(0x0002))/* AUTO */
#define evHostTaskDiagnoseResponse ((EventMaskType)(0x0002))/* AUTO */
#define evAppTaskDiagnoseRequest ((EventMaskType)(0x0004))/* AUTO */
#define evMonitorTask_MonitorAudio_for_DTC ((EventMaskType)(0x0002))/* AUTO */
#define evAppTaskDeviceFctPending ((EventMaskType)(0x0008))/* AUTO */
#define evAppTaskVCRSupervisor ((EventMaskType)(0x0010))/* AUTO */
#define evAppTaskSystemStates ((EventMaskType)(0x0020))/* AUTO */
#define evSystemTaskCallbackShutdown ((EventMaskType)(0x0010))/* AUTO */
#define evAppTaskApplResponse ((EventMaskType)(0x0040))/* AUTO */
#define evHostTaskOnCshdlRequestToCan ((EventMaskType)(0x0004))/* AUTO */
#define evHostTaskHandleDiagReq ((EventMaskType)(0x0008))/* AUTO */
#define evHostTask_INFO_Response ((EventMaskType)(0x0010))/* AUTO */
#define evAppTask_INFO_Request ((EventMaskType)(0x0080))/* AUTO */
#define evHostTaskSendingCodingData ((EventMaskType)(0x0020))/* AUTO */
/* Alarms */

/* Maximum possible allowed value of the system counter in ticks */
#define OSMAXALLOWEDVALUE 0x7fffffffUL

/* Minimum allowed number of ticks for a cyclic alarm */
#define OSMINCYCLE 1

/* Number of ticks required to reach specific unit of the system counter */
#define OSTICKSPERBASE 1

#define USEC(x) ( ((TickType)(((((uint32)(x))) + ( 1000UL  / 2 )) / 1000UL ))) /*	valid range for x: 0..4294966795	*/
#define MSEC(x) ( ((TickType)(((((uint32)(x))))))) /*	valid range for x: 0..2147483647	*/
#define SEC(x) ( ((TickType)(((((uint32)(x)) * 1000UL ))))) /*	valid range for x: 0..2147483	*/
#define CTA_HOST ((AlarmType)0)
#define CTA_MONITOR ((AlarmType)1)
#define CTA_DRIVER ((AlarmType)2)
#define CTA_DATABASE_EEPROM_WRITE ((AlarmType)3)
#define CTA_APP ((AlarmType)4)
#define CTA_SYSTEM ((AlarmType)5)
#define CTA_ERM_PENDING ((AlarmType)6)
#define CTA_WD ((AlarmType)7)
#define CTA_MONITOR_AUDIO ((AlarmType)8)
#define CTA_ONE_HOUR_MODE ((AlarmType)9)
#define CTA_APP_DIAG_WAIT_FOR_APP_CB ((AlarmType)10)
#define CTA_APP_DIAG_RETRY_BUSY ((AlarmType)11)
#define CTA_HOST_HANDLE_DIAG_REQ ((AlarmType)12)
#define CTA_HOST_SELF_DIAG_TIMER ((AlarmType)13)


#if (osdNumberOfAlarms > 0)
osqROM0 extern osqROM1 const osqROM2 uint8 osqROM3 oskAlarmAutoStart[osdNumberOfAlarms];
#endif

#if (osdNumberOfAllTasks > 0)
osqROM0 extern osqROM1 const osqROM2 uint8 osqROM3 oskTcbAutoStart[osdNumberOfAllTasks];
#endif

/* prototypes for alarm callback functions */
void CSHDL_cbAlarmCallbackOneHourModeOver(void);
void APP_DIAG_vHandlePendingResponseFromApplication(void);
void APP_CAN_cbHostSelfDiagnosisTimer(void);

/* ISRs */

#define osdIsrCanIsr_0Cat 2
#define osdIsrUART1_TxISRCat 1
#define osdIsrUART1_RxISRCat 1
#define osdIsrUART2_TxISRCat 1
#define osdIsrUART2_RxISRCat 1
#define osdIsrUART_ErrorISRCat 1
#define osdIsrosTimerIntCat 2


/* externals for assertions */
#if osdEnableProcedures
#if osdEnableAssertions
#if osdNumberOfAllTasks > 0 
   extern osqBOOL1 osqBOOL2 osBoolArrayBaseType osqBOOL3 osIsInProcedure[osdNumberOfAllTasks];
#endif
#endif
#endif


#endif /* _POST_TCB_H (double include preventer) */
#endif /* osdPostTCB */


/* END OF F:\PROJECTS\ADR-PORSCHE\PORSCHE_ADR_DEVELOPMENT_TRUNK\MOD\MOD_OSEK_DYN\CFG\tcb\tcb.h */
