/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/
/**
 * \file	MONITOR_ADC_CE.h
 * \brief	CE - Configuration External File. Detailed description found below.
 * \brief	This file mainly contains:
 * 			1. constants to switch on or off the exported interfaces.
 * 			2. configurable constants.
*/
/*-----------------------------------------------------------------------------
* $Date: 2011-02-08 11:12:29 +0100 (Di, 08 Feb 2011) $
* $Rev: 17726 $
* $Author: agrawal $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_MONITOR_ADC/trunk/inc/MONITOR_ADC_CE.h $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

#ifndef _MONITOR_ADC_CE_H
#define _MONITOR_ADC_CE_H

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/

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
    \brief	description of the type
*/
#define IMONITOR_ADC_READ
#define IMONITOR_ADC_INIT
#define IMONITOR_ADC_TASK
/*----------------------------------------------------------------------------*/
/* Public Code Macros                                                         */
/*----------------------------------------------------------------------------*/
#if (defined(PROCESSOR_TMS470R1VF55BA) || defined(PROCESSOR_TMS470R1SF55BA))

#define AUDIO_DIAG_START HET_vPinModify(HET_AUDIO_DIAG_EN, HetIoOutHigh);
#define AUDIO_DIAG_END HET_vPinModify(HET_AUDIO_DIAG_EN, HetIoOutLow);

#endif

/*----------------------------------------------------------------------------*/
/* Public Constants                                                           */
/*----------------------------------------------------------------------------*/

#endif
/* _MONITOR_ADC_CE_H */

/* End Of File MONITOR_ADC_CE.h */

