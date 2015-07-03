/*-----------------------------------------------------------------------------+
|            ____    ___            ____    _____           ____               |
|           |    |  |   \   |      |    |     |    |    |  |                   |
|           |____|  |    |  |      |____|     |    |    |  |____               |
|           |    |  |    |  |      |    |     |    |    |       |              |
|           |    |  |___/   |____  |    |     |    |____|   ____|              |
|                                                                              |
|           T H E   S M A R T   E M B E D D E D   S O L U T I O N              |
|                                                                              |
+------------------------------------------------------------------------------+
| F I L E   I N F O R M A T I O N                                              |
+------------------------------------------------------------------------------+
|                                                                              |
|  Filename:  ADLATUS_ConfigAdlatus.c                                          |
|                                                                              |
|  Comment:   This file includes the complete configuration data for the       |
|             SMART ADLATUS.                                                   |
|                                                                              |
+------------------------------------------------------------------------------+
| R E V I S I O N   H I S T O R Y                                              |
+------------------------------------------------------------------------------+
|
| Subversion Info:
| $Id: ADLATUS_ConfigAdlatus.c 4396 2008-11-04 09:26:32Z maennel $
| $HeadURL: http://smartsvn/svn/adlatusrepository/auslieferungen/S1NN/086350-S1NN-ADLATUS-TMS470R-MucSuc/20081201_S1NN_TMS470R_BlfIso-Source_V1.00/01_SW_Projekt/08_corelib/02_src/ADLATUS_ConfigAdlatus.c $
|
+------------------------------------------------------------------------------+
|      (c) SMART ELECTRONIC DEVELOPMENT GMBH - all rights reserved             |
+-----------------------------------------------------------------------------*/

/* ========================================================================== */
/* (1)  I N C L U D E S                                                       */
/* -------------------------------------------------------------------------- */
/*      C O N S T A N T   D E F I N I T I O N   F I L E S  (CDF)              */
/* ========================================================================== */
#include "ADLATUS_CompilerSwitches_cdf.h"    /* must be the first CDF-include */
#include "ADLATUS_Global_cdf.h"
#include "ADLATUS_ConfigSystem_cdf.h"

/* ========================================================================== */
/* (2)  I N C L U D E S                                                       */
/* -------------------------------------------------------------------------- */
/*      T Y P E   D E F I N I T I O N   F I L E S  (TDF)                      */
/* ========================================================================== */
#include "ADLATUS_Types_tdf.h"         /* must be the first include           */
#include "ADLATUS_ConfigProject_tdf.h" /* Project specific configuration      */
#include "ADLATUS_ConfigSystem_tdf.h"  /* System specific configuration       */
#include "ADLATUS_ConfigAdlatus_tdf.h" /* System specific configuration       */
#include "ADLATUS_Tp_TDF.h"			   /* TP-Timer							  */

/* ========================================================================== */
/* (3)  C O M P I L E R   S W I T C H   S E T T I N G S                       */
/* -------------------------------------------------------------------------- */
/*      O N L Y   F O R   T H I S   M O D U L                                 */
/* ========================================================================== */
/* Global Compiler switch settings are done at ADLATUS_CompilerSwitches_CDF.h */
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Local compiler switches: No Entry                                          */
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* ========================================================================== */
/* (4)  D A T A   S E C T I O N   D I R E C T I V E S                         */
/* -------------------------------------------------------------------------- */
/*      O N L Y   F O R   T H I S   M O D U L                                 */
/* ========================================================================== */
/* NO ENTRY                                                                   */

/* ========================================================================== */
/* (5)  L O C A L   D E F I N E S                                             */
/* -------------------------------------------------------------------------- */
/*      O N L Y   F O R   T H I S   M O D U L                                 */
/* ========================================================================== */
/* NO ENTRY                                                                   */

/* ========================================================================== */
/* (6)  L O C A L  T Y P E   D E F I N E S                                    */
/* -------------------------------------------------------------------------- */
/*      O N L Y   F O R   T H I S   M O D U L                                 */
/* ========================================================================== */
/* NO ENTRY                                                                   */

/* ========================================================================== */
/* (7)  L O C A L   V A R I A B L E S  / C O N S T A N T S                    */
/* -------------------------------------------------------------------------- */
/*      O N L Y   F O R   T H I S   M O D U L                                 */
/* ========================================================================== */


/******************************************************************************/
/******************************************************************************/
/**                                                                          **/
/**     APPLICATION AREA   Sys.05                                            **/
/**     ----------------------------------------------------------------     **/
/**     S Y S T E M   C O N F I G U R A T I O N                              **/
/**     ----------------------------------------------------------------     **/
/**     Initialization Interface for Module: System                          **/
/**                                                                          **/
/**                                                                          **/
/******************************************************************************/
/******************************************************************************/

#if 0
const SYSTEMINTERFACE_ST c_CCconsys_SystemInterface_ST = \
{
  /* ------------------------------------------------------------------------ */
  /*   System Buffer Configuration                                            */
  /* ------------------------------------------------------------------------ */
  &c_CCconsys_BufferConfig_AST[0],

  /* ------------------------------------------------------------------------ */
  /*   Communication Stack Table                                              */
  /* ------------------------------------------------------------------------ */
  &c_CCconsys_ComStackFunctions_AST[0],

  /* ------------------------------------------------------------------------ */
  /*   Communication HAL Function Table                                       */
  /* ------------------------------------------------------------------------ */
  &c_CCconsys_ComHALFunctions_AST[0],

  /* ------------------------------------------------------------------------ */
  /*   Event Handler Function Table                                           */
  /* ------------------------------------------------------------------------ */
  &c_CCconsys_EventProcessingFkt_AST[0]


}; /*-+- END OF TABLE -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
#endif

/******************************************************************************/
/* -- -- END OF APPLICATION AREA   Sys.05  - -- -- -- -- -- -- -- -- -- -- -- */
/******************************************************************************/






/******************************************************************************/
/******************************************************************************/
/**                                                                          **/
/**     APPLICATION AREA   Time.03                                           **/
/**     ----------------------------------------------------------------     **/
/**     S Y S T E M   C O N F I G U R A T I O N                              **/
/**     ----------------------------------------------------------------     **/
/**     Initialization interface for modul: Timer                            **/
/**                                                                          **/
/**                                                                          **/
/******************************************************************************/
/******************************************************************************/
const SWTIMERHANDLERINTERFACE_ST c_CCconsys_SWTimerHandlerInterface_ST = \
{
  /* ------------------------------------------------------------------------ */
  /*   Pointer to SW Timer function map                                       */
  /* ------------------------------------------------------------------------ */
  &c_CCtim_SWTimerFunctions_APFUN[0]

}; /* ---- END OF SW-TIMER-INTERFACE -----------------------------------------*/

/******************************************************************************/
/* -- -- END OF APPLICATION AREA   Time.03 -- -- -- -- -- -- -- -- -- -- -- --*/
/******************************************************************************/





/* ========================================================================== */
/* (8)  L O C A L   F U N C T I O N   P R O T O T Y P E S                     */
/* -------------------------------------------------------------------------- */
/*      O N L Y   F O R   T H I S   M O D U L                                 */
/* ========================================================================== */
/* NO ENTRY                                                                   */

/* ========================================================================== */
/* (9)  G L O B A L   V A R I A B L E S                                       */
/* -------------------------------------------------------------------------- */
/*      D E F I N E D   W I T H I N   T H I S   M O D U L                     */
/* ========================================================================== */
/* NO ENTRY                                                                   */

/* ========================================================================== */
/* (10) F U N C T I O N   D E F I N I T I O N S                               */
/* -------------------------------------------------------------------------- */
/*      F O R   T H I S   M O D U L                                           */
/* ========================================================================== */

/*-----------------------------------------------------------------------------+
|    F U N C T I O N   I N F O R M A T I O N                                   |
+------------------------------------------------------------------------------+
|                                                                              |
|  Function Name:  FUN_CCconsys_InitAllSystemBuffer_V                          |
|                                                                              |
|  Prototype at:   ADLATUS_ConfigAdlatus_tdf.h                                 |
|                                                                              |
|  Description:    Initialisation for the buffer of the SMART ADLATUS System.  |
|                                                                              |
|  Parameter:      -                                                           |
|                                                                              |
|  Return Value:   -                                                           |
|                                                                              |
+-----------------------------------------------------------------------------*/
#if 0
#define cs_CCsys_SingleChannelSystem
void FUN_CCconsys_InitAllSystemBuffer_V (void)
{

/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/*                                                                            */
/* S I N G L E   C H A N N E L   S Y S T E M                                  */
/*                                                                            */
/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
#ifdef cs_CCsys_SingleChannelSystem /* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/*----------------------------------------------------------------------------*/

  PTR_BUFFER_UB t_PtrToBuffer_PBUF;
  
  UBYTE t_Counter_UB;
  
  /*==========================================================================*/
  /*                                                                          */
  /* -1- Config all buffers of channel 00                                     */
  /*                                                                          */
  /*==========================================================================*/
  for (t_Counter_UB = 0;t_Counter_UB < 0x06;t_Counter_UB++)
  {
    /* -----------------------------------------------------------------------*/
    /* Init the BufferPointer                                                 */
    /* -----------------------------------------------------------------------*/
    t_PtrToBuffer_PBUF = c_CCconsys_BufferConfig_AST[d_CCglo_Channel00].Line_PBUF[t_Counter_UB];
    /* -----------------------------------------------------------------------*/
    /*      B U F F E R   S T A T E                                           */
    /* -----------------------------------------------------------------------*/
    t_PtrToBuffer_PBUF[d_CCglo_BufferState] = c_CCcon_BufferInit_ST[d_CCglo_Channel00][t_Counter_UB].Config_UB;
    /* -----------------------------------------------------------------------*/
    /*      B U F F E R   C H A N N E L                                       */
    /* -----------------------------------------------------------------------*/
    t_PtrToBuffer_PBUF[d_CCglo_ChannelNbr] = c_CCcon_BufferInit_ST[d_CCglo_Channel00][t_Counter_UB].ChannelInf_UB;
    /* -----------------------------------------------------------------------*/
    /*      B U F F E R   L E N G T H                                         */
    /* -----------------------------------------------------------------------*/
    t_PtrToBuffer_PBUF[d_CCglo_MaxBufferLength] = c_CCcon_BufferInit_ST[d_CCglo_Channel00][t_Counter_UB].Length_UB;
    /* -----------------------------------------------------------------------*/
    /*      B U F F E R   D L C                                               */
    /* -----------------------------------------------------------------------*/
    t_PtrToBuffer_PBUF[d_CCglo_DLC] = d_CCglo_00Byte;

  } /* -1- END OF for (..) ---------------------------------------------------*/

  return;

/*----------------------------------------------------------------------------*/
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */
/*                                                                            */
/*      E N D   O F   S I N G L E   C H A N N E L   S Y S T E M               */
/*                                                                            */
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */
#else /* cs_CCsys_SingleChannelSystem  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/*                                                                            */
/*      M U L T I   C H A N N E L   S Y S T E M                               */
/*                                                                            */
/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
/*----------------------------------------------------------------------------*/

  PTR_BUFFER_UB t_PtrToBuffer_PBUF;
  UBYTE         t_Counter_UB;
  UBYTE         t_Channel_UB;

  /*==========================================================================*/
  /* -1- Init all channels                                                    */
  /*==========================================================================*/
  for (t_Channel_UB = 0; t_Channel_UB < d_CCconsys_NbrOfLogChannel; t_Channel_UB++)
  {
    /*========================================================================*/
    /* -2- Config all buffers of channel                                      */
    /*========================================================================*/
    for (t_Counter_UB = 0;t_Counter_UB < 0x06;t_Counter_UB++)
    {
      /* ---------------------------------------------------------------------*/
      /* Init the BufferPointer  -> RxMsgObj                                  */
      /* ---------------------------------------------------------------------*/
      t_PtrToBuffer_PBUF = c_CCconsys_BufferConfig_AST[t_Channel_UB].Line_PBUF[t_Counter_UB];


      /* ---------------------------------------------------------------------*/
      /*      B U F F E R   S T A T E                                         */
      /* ---------------------------------------------------------------------*/
      t_PtrToBuffer_PBUF[d_CCglo_BufferState] = c_CCcon_BufferInit_ST[t_Channel_UB][t_Counter_UB].Config_UB;
      /* ---------------------------------------------------------------------*/
      /*      B U F F E R   C H A N N E L                                     */
      /* ---------------------------------------------------------------------*/
      t_PtrToBuffer_PBUF[d_CCglo_ChannelNbr] = c_CCcon_BufferInit_ST[t_Channel_UB][t_Counter_UB].ChannelInf_UB;
      /* ---------------------------------------------------------------------*/
      /*      B U F F E R   L E N G T H                                       */
      /* ---------------------------------------------------------------------*/
      t_PtrToBuffer_PBUF[d_CCglo_MaxBufferLength] = c_CCcon_BufferInit_ST[t_Channel_UB][t_Counter_UB].Length_UB;
      /* ---------------------------------------------------------------------*/
      /*      B U F F E R   D L C                                             */
      /* ---------------------------------------------------------------------*/
      t_PtrToBuffer_PBUF[d_CCglo_DLC] = d_CCglo_00Byte;
  
    } /* -2- END OF for (..) -------------------------------------------------*/
  } /* ---1- END OF for (..) -------------------------------------------------*/

  return;

/* ---------------------------------------------------------------------------*/
#endif /*                                                                     */
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */
/*                                                                            */
/*      E N D   O F   M  U L T I   C H A N N E L   S Y S T E M                */
/*                                                                            */
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

} /*-+- END OF FUNCTION 'FUN_CCconsys_InitAllSystemBuffer_V' -+-+-+-+-+-+-+-+-*/
#endif




/* ========================================================================== */
/*      E N D   O F   F I L E                                                 */
/* ========================================================================== */
