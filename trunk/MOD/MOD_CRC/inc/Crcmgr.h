/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/
/** 
 * \file 	CRCMGR.h
 * \brief	This file contains prototypes of all the functions that can be used
 * by other modules. Detailed description found below. 
 * \brief	It also contains enum, structure, constant definition etc. that can 
 * be used by other modules. The application/system must include this file 
 * in order to use the interfaces provided by this module.
*/
/*-----------------------------------------------------------------------------
* $Date: 2011-02-22 19:46:31 +0100 (Di, 22 Feb 2011) $
* $Rev: 18115 $
* $Author: kolozsvary $
* $URL: http://subversion-01/svn/SW_HW_System/Projects/Ford_SCM/SW/MOD/MOD_CRC/trunk/inc/Crcmgr.h $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/
#ifndef _CRCMGR_H
#define _CRCMGR_H

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Manifest Constant Definitions                                       */
/*----------------------------------------------------------------------------*/
#define CRCINITVALUE   0xFFFFFFFF
#define CRC32WORD_LEN  4 


/* Backup definitions */
#define D_EE_ADDDRESS_START_DATAREGION  0
#define D_EE_ADDDRESS_END_DATAREGION    0
#define D_EE_ADDDRESS_START_BACKUP      0
#define D_EE_ADDDRESS_END_BACKUP        0
#define D_EE_BACKUP_DELTA               D_EE_ADDDRESS_START_BACKUP - D_EE_ADDDRESS_START_DATAREGION


/*----------------------------------------------------------------------------*/
/* Public Types                                                               */
/*----------------------------------------------------------------------------*/
#include "EEPROM.h"

typedef struct {
    EEAddressType data;
    EEAddressType CRC;
    Uint8Type     datalength;
} CRCLookup;


typedef enum
{
    CRC_BACKUP_NORMALMODE_NO_CRC_ERROR=0,  
    CRC_BACKUP_READ_BACKUPDATA,  
    CRC_BACKUP_RESET_CRC, 
    CRC_BACKUP_WRITE_BACKUPDATA,  
    CRC_BACKUP_CALULATE_NEW_CRC,  
    CRC_BACKUP_CHECK_RECOVER_DATA_AGAINST_NEW_CRC
} CrcmgrBackupStatesType;

/*----------------------------------------------------------------------------*/
/* Global Variables Declarations (avoid as much as possible!)                 */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global const Declarations                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Methods                                                             */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Code Macros                                                         */
/*----------------------------------------------------------------------------*/


void CrcManager(void);
void StartCRCJob(void);
Uint8Type CompleteEECrcCheckDone(void);
FlagType CRCIsAnyJobPending(void);
SuccessFailType CRC_sfManagerInit(void);



#endif
