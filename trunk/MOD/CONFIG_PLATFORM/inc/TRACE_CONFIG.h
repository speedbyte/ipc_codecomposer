/******************************************************************************/
/*****************  Copyright (c) 2010 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

#ifndef _TRACE_CONFIG_H
#define _TRACE_CONFIG_H


/* DEFINE MAXIMUM 64 TRACE MODULES, VALID ID'S ARE 0-63 */


typedef enum
{
  MOD_ADC                   =  0,
  MOD_APP_CAN               =  1,
  MOD_APP_COMMON            =  2,
  MOD_APP_CSHDL             =  3,
  MOD_APP_CONNECTION        =  4,
  MOD_EEPROM_LAYOUT_CFG     =  5,
  MOD_APP_DTC               =  6,
  MOD_APP_INFO              =  7,
  MOD_APP_MDI_RX_CAN        =  8,
  MOD_APP_PHONE             =  9,
  MOD_IPC                   = 10,
  MOD_APP_MDI_TX_CAN        = 11,
  MOD_APP_PHONE_RX_CAN      = 12,
  MOD_APP_PHONE_TX_CAN      = 13,
  MOD_APP_SMS               = 14,
  MOD_ASR                   = 15,
  MOD_AT_CMD_HANDLER        = 16,
  MOD_AT_PARSER             = 17,
  MOD_BAP                   = 18,
  MOD_BAP_DISPATCHER        = 19,
  MOD_CAN_DYN               = 20,
  MOD_APP_CONNECTION_RX_CAN = 21,
  MOD_APP_CONNECTION_TX_CAN = 22,
  MOD_CRC                   = 23,
  MOD_CSHDL                 = 24,
  MOD_DEH                   = 25,
  MOD_DIAG                  = 26,
  MOD_EEPROM                = 27,
  MOD_GPS_UBX               = 28,
  MOD_FBL_DATA              = 29,
  MOD_GIO                   = 30,
  MOD_ISOTP                 = 31,
  MOD_KPB                   = 32,
  MOD_LED                   = 33,
  MOD_LOGI_BUT_MAN          = 34,
  MOD_MFL_MGR               = 35,
  MOD_MONITOR_ADC           = 36,
  MOD_UART                  = 37,
  MOD_NM                    = 38,
  MOD_OSEK_DYN              = 39,
  MOD_OSEK_ST               = 40,
  MOD_PHY_BUT_DRV           = 41,
  MOD_POOL                  = 42,
  MOD_PORT                  = 43,
  MOD_POWERMANAGER          = 44,
  MOD_SDS_UDS               = 45,
  MOD_APP_DEVICE            = 46,
  MOD_SPI                   = 47,
  MOD_SYS_INIT              = 48,
  MOD_TEMPERATURE           = 49,
  MOD_VCR_RX_CAN            = 50,
  MOD_VCR_TX_CAN            = 51,
  MOD_VCR                   = 52,
  MOD_WD                    = 53,
  MOD_CALLBACK              = 54,
  MOD_OSEK_INTERFACE        = 55,
  MOD_MAIN                  = 56,
  MOD_TRACE                 = 57,
  MOD_EEPROM_LAYOUT         = 58,
  MOD_SCM_CONFIG_RX_CAN     = 59,
  MOD_SCM_CONFIG_TX_CAN     = 60,
  MOD_AUDIO_MANAGER         = 61,
  MOD_AUDIO_MANAGER_RX_CAN  = 62,
  MOD_AUDIO_MANAGER_TX_CAN  = 63       /* 63 = THIS IS THE LAST ONE !!!  */
} TRACE_MODULES;

#include "TRACE_CONFIG_GENERATED.h"

#endif /* _TRACE_CONFIG_H */

/* End Of File _TRACE_CONFIG_H */
