/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name: 	MOD_SYS_INIT_CE.h
*-----------------------------------------------------------------------------
* Module Name:	MOD_SYS_INIT
*-----------------------------------------------------------------------------
* Description:	configuration Header for external configuration of the system
*-----------------------------------------------------------------------------
* $Date: 2011-02-01 14:39:02 +0100 (Di, 01 Feb 2011) $
* $Rev: 17599 $
* $Author: weber $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_SYS_INIT/trunk/inc/MOD_SYS_Init_CE.h $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

#ifndef _MOD_SYS_INIT_CE_H
#define _MOD_SYS_INIT_CE_H

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/
#include "Common.h"

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Manifest Constant Definitions                                       */
/*----------------------------------------------------------------------------*/
#undef ISYS_COMPLETEINIT /* CONFIGURATE EXPORT INTERFACE(ISYS_COMPLETEINIT) */
#define ISYS_PARTINIT 100 /* CONFIGURATE EXPORT INTERFACE(ISYS_PARTINIT) */

/*----------------------------------------------------------------------------*/
/* Import configuration                                                       */
/*----------------------------------------------------------------------------*/
/**
\brief	description of configured interface
*/
#define ISYS_INIT_CFG 100
#if (ISYS_INIT_CFG != (ISYS_COMPLETEINIT | ISYS_PARTINIT))
	#error ("Incompatible interface: configured ifc = %d, reference ifc = %d!!!" ,ISYS_INIT_CFG, ISYSINIT1)
#endif

/***************************START Configuration Section************************/

/* Hardware init configuration section */
#define SYS_INIT_SUPPORT_PORT_IO
#define	SYS_INIT_SUPPORT_WD
//#define	SYS_INIT_SUPPORT_CAN_TRANSCEIVER
/* Peripheral init configuration section */
#define	SYS_INIT_SUPPORT_ADC
#define SYS_INIT_SUPPORT_UART
#define	SYS_INIT_SUPPORT_SPI
#undef 	SYS_INIT_SUPPORT_I2C
#undef	SYS_INIT_SUPPORT_EEPROM
/* Software init configuration section */
#define SYS_INIT_SUPPORT_CCL
#define SYS_INIT_SUPPORT_APP_DIAG
#undef  SYS_INIT_SUPPORT_POOL
#define SYS_INIT_SUPPORT_DEBUG_TRACE_CLIENT
#define SYS_INIT_SUPPORT_TEMPERATURE
#define SYS_INIT_SUPPORT_CRC
#define SYS_INIT_SUPPORT_MONITOR_ADC
#define SYS_INIT_SUPPORT_APP_DTC

/*----------------------------------------------------------------------------*/
/* Ports part                                                                 */
/*----------------------------------------------------------------------------*/
#ifdef SYS_INIT_SUPPORT_PORT_IO

#include "GIO.h"
#include "PORT.h"
/**
\brief	macro to define the Port initialization
*/
#define SYS_INIT_PORT               PORT_vInit()

#endif

/*----------------------------------------------------------------------------*/
/* Watchdog part                                                              */
/*----------------------------------------------------------------------------*/
#ifdef SYS_INIT_SUPPORT_WD

#include "WD_C1.h"
/**
\brief	macro to define the Port initialization
*/
#define SYS_INIT_WD		(SuccessFailType)WD_u8Init()

#define SYS_INIT_WD		(SuccessFailType)WD_u8Init()
#endif

/*----------------------------------------------------------------------------*/
/* ADC part                                                                   */
/*----------------------------------------------------------------------------*/
#ifdef SYS_INIT_SUPPORT_ADC

#include "ADC.h"
/**
\brief	macro to define the ADC initialization
*/
#define SYS_INIT_ADC		ADC_sfInit(ADC1)

#endif

/*----------------------------------------------------------------------------*/
/* UART part                                                                  */
/*----------------------------------------------------------------------------*/
#ifdef SYS_INIT_SUPPORT_UART

#include "UART.h"
/**
\brief	macro to define the first UART initialization
*/
#define SYS_INIT_UART1		UART_sfInit(UART1)
/**
\brief	macro to define the second UART initialization
*/
#define SYS_INIT_UART2 		UART_sfInit(UART2)

#endif

/*----------------------------------------------------------------------------*/
/* SPI part                                                                   */
/*----------------------------------------------------------------------------*/
#ifdef SYS_INIT_SUPPORT_SPI

#include "SPI.h"
/**
\brief	macro to define the first SPI initialization
*/
#define SYS_INIT_SPI1		SPI_sfInit(SPI1)
/**
\brief	macro to define the second SPI initialization
*/
#define SYS_INIT_SPI2 		SPI_sfInit(SPI2)
/**
\brief	macro to define the third SPI initialization
*/
#define SYS_INIT_SPI3 		SPI_sfInit(SPI3)
/**
\brief	macro to define the 4th SPI initialization
*/
#define SYS_INIT_SPI4 		SPI_sfInit(SPI4)
/**
\brief	macro to define the 5th SPI initialization
*/
#define SYS_INIT_SPI5 		SPI_sfInit(SPI5)
#endif

/*----------------------------------------------------------------------------*/
/* I2C part                                                                   */
/*----------------------------------------------------------------------------*/
#ifdef SYS_INIT_SUPPORT_I2C

#include "I2C.h"
/**
\brief	macro to define the first I2C initialization
*/
#define SYS_INIT_I2C1		I2C_sfInit(I2C1)
/**
\brief	macro to define the second I2C initialization
*/
#define SYS_INIT_I2C2 		I2C_sfInit(I2C2)

#endif

/*----------------------------------------------------------------------------*/
/* EEPROM part                                                                */
/*----------------------------------------------------------------------------*/
#ifdef SYS_INIT_SUPPORT_EEPROM

#include "EEPROM.h"
/**
\brief	macro to define the EEPROM initialization
*/
#define SYS_INIT_EEPROM		EEPROM_sfInit()

#endif

/*----------------------------------------------------------------------------*/
/* CAN part                                                                   */
/*----------------------------------------------------------------------------*/
#ifdef SYS_INIT_SUPPORT_CCL

#include "APP_CAN.h"
/**
\brief	macro to define the first CAN part initialization
*/
#define SYS_INIT_CCL		APP_CAN_vInit()


#endif

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* standard diagnosis Services part                                           */
/*----------------------------------------------------------------------------*/
#ifdef SYS_INIT_SUPPORT_APP_DIAG

#include "APP_DIAG.h"
/**
\brief	macro to define the standard diagnosis Services initialization
*/
#define SYS_INIT_APP_DIAG		(void)APP_DIAG_sfInit()

#endif

/*----------------------------------------------------------------------------*/
/* Pool Handler part                                                          */
/*----------------------------------------------------------------------------*/
#ifdef SYS_INIT_SUPPORT_POOL

#include "POOL.h"

#define SYS_INIT_POOL       (void)POOL_sfInit()

#endif


/*----------------------------------------------------------------------------*/
/* Debug part                                                                 */
/*----------------------------------------------------------------------------*/
#ifdef SYS_INIT_SUPPORT_DEBUG_TRACE_CLIENT

#include "TRACE.h"

#define SYS_INIT_DEBUG_TRACE_CLIENT  (void)Trace_vInit()

#endif

/*----------------------------------------------------------------------------*/
/* Temperature part                                                           */
/*----------------------------------------------------------------------------*/
#ifdef SYS_INIT_SUPPORT_TEMPERATURE

#include "TEMPERATURE.h"

#define SYS_INIT_TEMPERATURE           (void)TEMPERATURE_sfInit()

#endif


/*----------------------------------------------------------------------------*/
/* CRC manager part                                                           */
/*----------------------------------------------------------------------------*/
#ifdef SYS_INIT_SUPPORT_CRC

#include "CRCMGR.h"

#define SYS_INIT_CRC           (void)CRC_sfManagerInit()

#endif

/*----------------------------------------------------------------------------*/
/* Monitor ADC                                                            */
/*----------------------------------------------------------------------------*/
#ifdef SYS_INIT_SUPPORT_MONITOR_ADC

#include "MONITOR_ADC.h"

#define SYS_INIT_MONITOR_ADC           (void)MONITOR_ADC_sfInit()

#endif

/*----------------------------------------------------------------------------*/
/* APP DTC                                                                */
/*----------------------------------------------------------------------------*/
#ifdef SYS_INIT_SUPPORT_APP_DTC

#include "APP_DTC.h"

#define SYS_INIT_APP_DTC           (void)APP_DTC_sfInit()

#endif

#endif /* _MOD_SYS_INIT_CE_H */

/* End Of File MOD_SYS_INIT_CE.h */

