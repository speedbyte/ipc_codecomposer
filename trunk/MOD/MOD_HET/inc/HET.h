/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/
/**
 * \file 	GIO.h
 * \brief	Module Header File.
 * 			This file must be included by the application/system in order to use
 * 			the interfaces provided by this module. Detailed description found below.
 * \brief	This file mainly contains:
 * 			1. prototypes of all the functions that can be used by other modules.
 * 			2. enum, structure, constant definition etc. that can be used by other
 * 			modules.
*/
/*-----------------------------------------------------------------------------
* $Date: 2010-11-17 07:43:24 +0100 (Mi, 17 Nov 2010) $
* $Rev: 16328 $
* $Author: weber $
* $URL: http://subversion-01/svn/SW_HW_System/Plattform/TMS470/MOD/MOD_GIO/tags/MOD_GIO_B_10.10_pre/inc/GIO.h $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

#ifndef _HET_H
#define _HET_H

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/
#include "common.h"
#include "tms470r1.h"
/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Manifest Constant Definitions                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Types                                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global Variables Declarations (avoid as much as possible!)                 */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global const Declarations                                                  */
/*----------------------------------------------------------------------------*/

#define HET_PIN0  0x00000001
#define HET_PIN1  0x00000002
#define HET_PIN2  0x00000004
#define HET_PIN3  0x00000008
#define HET_PIN4  0x00000010
#define HET_PIN5  0x00000020
#define HET_PIN6  0x00000040
#define HET_PIN7  0x00000080
#define HET_PIN8  0x00000100
#define HET_PIN9  0x00000200
#define HET_PIN10 0x00000400
#define HET_PIN11 0x00000800
#define HET_PIN12 0x00001000
#define HET_PIN13 0x00002000
#define HET_PIN14 0x00004000
#define HET_PIN15 0x00008000
#define HET_PIN16 0x00010000
#define HET_PIN17 0x00020000
#define HET_PIN18 0x00040000
#define HET_PIN19 0x00080000
#define HET_PIN20 0x00100000
#define HET_PIN21 0x00200000
#define HET_PIN22 0x00400000
#define HET_PIN23 0x00800000
#define HET_PIN24 0x01000000
#define HET_PIN25 0x02000000
#define HET_PIN26 0x04000000
#define HET_PIN27 0x08000000
#define HET_PIN28 0x10000000
#define HET_PIN29 0x20000000
#define HET_PIN30 0x40000000
#define HET_PIN31 0x80000000


typedef enum
{
    HetIoIn,
    HetIoOut,
    HetIoOutHigh,
    HetIoOutLow
}HETQUAL;

/*----------------------------------------------------------------------------*/
/* Public Methods                                                             */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Code Macros                                                         */
/*----------------------------------------------------------------------------*/


Uint8Type HET_u8PinRead(Uint32Type PinMask_N);

Uint32Type HET_u32PortRead(void);
/*----------------------------------------------------------------------------*/


void HET_vPinModify(Uint32Type PinMask_N, HETQUAL PinQual_N );

void HET_vPinWrite(Uint32Type PinMask_N, Uint8Type PinData_B);

void HET_vPortSet(Uint32Type PinMask_N);

void HET_vPortClear(Uint32Type PinMask_N);

#endif /* _HET_H */

/* End Of File HET.h */
