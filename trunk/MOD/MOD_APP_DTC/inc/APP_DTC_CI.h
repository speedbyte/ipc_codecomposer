/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/
/** 
 * \file 	APP_DTC_CI.h
 * \brief	CI - Configuration Internal File.  Detailed description found below.
 * \brief	This file comprises of constants to switch on or off the interfaces that
 * are used internally within the module. It also contains various constants that can be 
 * configured by the module owner.
*/
/*-----------------------------------------------------------------------------
* $Date: 2011-03-07 08:54:45 +0100 (Mo, 07 Mrz 2011) $
* $Rev: 18354 $
* $Author: kolozsvary $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_APP_DTC/trunk/inc/APP_DTC_CI.h $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

#ifndef _APP_DTC_CI_H
#define _APP_DTC_CI_H

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Manifest Constant Definitions                                       */
/*----------------------------------------------------------------------------*/
#define IAPP_DTC_PL
#define APP_DTC_U7V5_CORR_VALUE   (668 << 4)  // Korrekturfaktor für die Referenzspannung U7V5
/*----------------------------------------------------------------------------*/
/* Import configuration                                                       */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Synonym adaptions                                    */
/*----------------------------------------------------------------------------*/
typedef enum
{
	enAppDtcStartMonitoringCodierung,
	enAppDtcReadValuesOnStartUp,
	enAppDtcInitialize
} APP_DTC_ENUM_START_SEQUENCE;

typedef struct {
    Sint8Type  Temperature;
    Uint16Type ADC;
} TEMPERATURE_TableType;

/*----------------------------------------------------------------------------*/
/* Prototypes of module global methods                                        */
/*----------------------------------------------------------------------------*/
/** 
\brief	description of the method
*/

/*----------------------------------------------------------------------------*/
/* Module global code macros                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Module global variables                                                    */
/*----------------------------------------------------------------------------*/
/** 
\brief	description of the module global variable
*/

/*----------------------------------------------------------------------------*/
/* Module global const definitions                                                  */
/*----------------------------------------------------------------------------*/
#define TEMPERATURE_HIGH     80  // bei soll der DTC eingetragen werden
#define TEMPERATURE_LOW     -10
#define TEMPERATURE_COUNTER  40  // nur alle 2000ms (50ms x 40) die Temperatur prüfen
                                 // so will es die DTC Spec

#endif /* _APP_DTC_CI_H */

/* End Of File APP_DTC_CI.h */






