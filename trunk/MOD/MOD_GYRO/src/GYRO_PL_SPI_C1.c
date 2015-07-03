/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     	EEPROM_PL_SPI_C1.c
*-----------------------------------------------------------------------------
* Module Name:		MOD_EEPROM
*-----------------------------------------------------------------------------
* Description:		Specialisation of EEPROM HW Interface for SPI 
*-----------------------------------------------------------------------------
* $Date: 2010-03-12 14:59:02 +0100 (Fr, 12 Mrz 2010) $
* $Rev: 11515 $
* $Author: agrawal $
* $URL: http://subversion-01/svn/SW_HW_System/Plattform/TMS470/MOD/MOD_EEPROM/tags/MOD_EEPROM_B_10.23_pre/src/EEPROM_PL_SPI_C1.c $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/
#include "SPI.h"
/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
#include "GYRO.h"
#include "GYRO_PL_SPI.h"

/*----------------------------------------------------------------------------*/
/* pragma Directives                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global Variables Definitions (avoid as much as possible!)                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Manifest Constant Definitions                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Private Types                                                              */
/*----------------------------------------------------------------------------*/
/** 
\brief	description of the type
*/

/*----------------------------------------------------------------------------*/
/* Prototypes of file local Methods                                           */
/*----------------------------------------------------------------------------*/
/** 
\brief	description of the method
*/

/*----------------------------------------------------------------------------*/
/* File local Code Macros                                                        */
/*----------------------------------------------------------------------------*/
/** 
\brief	description of the macros
*/

/*----------------------------------------------------------------------------*/
/* File local Variables                                                       */
/*----------------------------------------------------------------------------*/
/** 
\brief	description of the private variable
*/

/*----------------------------------------------------------------------------*/
/* File local const Definitions                                               */
/*----------------------------------------------------------------------------*/
/** 
\brief	description of the private constant
*/
/*----------------------------------------------------------------------------*/
/* Private Address Calculations                                               */
/*----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------*/
/* Function    : EEPROM_sfHwWriteBlock                                                 */
/** 
    \brief      Writes at the given address the sepcified amount of bytes.
    			All work is done in one Chip Select Cycle.
  
    \brief      Description:
    			The write commands are enqueued but only one command pending is allowed per client.
				Write at the given address the specified amount of bytes   
                from the given adress. The command is asynchron. It just   
                post a request which is handled wihtin EEPROM_vManager
                A write over several pages may be interrupted through another write
                operation if its priority is higher. As the progress about the flashing
                is stored within the client object, we can do that.
                Precondition: Once has to  habe been regsistered calling EEPROM_sfInit()
                Before calling that method.
 
    \param      selectionAddress
                Uint8Type
    \param      data
                Uint8Type *
                pointer to the data to be read starting at the given address.
    \param      length
                Uint16Type
                The data to be stored starting at the given address.

    \return     SuccessFailType
                It returns TRUE whether the request has been successfully  *
                written to EEPROM, FALSE otherwise  
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bHwWriteBlock(Uint8Type selectionAddress, const Uint8Type *data, Uint16Type length)
{
    // The address where the data has to be written and the data to be written should be
	// passed in one CHIP Select Cycle.
	BooleanType bT = BT_TRUE;
    Uint8Type buffer[GYRO_MAXDATALENGTHTOBESEND + SIZEOF_GYRO_HDR];
	/* Write header                                                 */
    buffer[0] = GYRO_WRITE_MEMORY_SHIFT;
    buffer[0] += selectionAddress;

    (void)memcpy(&buffer[SIZEOF_GYRO_HDR],(const void*) data, length);
    /* Write data                                                   */
    if (SUCCESS != SPI_sfWriteBlock(GYRO_SPI, (Uint16Type)(length+SIZEOF_GYRO_HDR), buffer, DISABLE))
    {
        bT = BT_FALSE;
    }
    return (bT);
}
/*----------------------------------------------------------------------------*/
/* Function    : EEPROM_sfHwReadBlock                                                 */
/** 
    \brief      Reads at the given address the sepcified amount of bytes.
    			All work is done in one CS Cycle.
  
    \brief      Description:
                The read command is performed "synchronously" through the client.
                Precondition: Once has to  habe been regsistered calling EEPROM_sfinit()
                Before calling that method.
 
    \param      selectionAddress
                Uint16Type
                First Low Byte and then High Byte.
    \param      data
                Uint8Type *
                pointer to the data to be read starting at the given address.
    \param      length
                Uint16Type
                The data to be stored starting at the given address.

    \return     SuccessFailType
                It returns TRUE whether the address has been successfully  *
                read to EEPROM, FALSE otherwise  
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bHwReadBlock(Uint8Type selectionAddress, Uint8Type *data, Uint16Type length)
{
	BooleanType bT = BT_TRUE;
    Uint8Type buffer[SIZEOF_GYRO_HDR];
    buffer[0] = selectionAddress;

    if (SUCCESS != SPI_sfWriteBlock(GYRO_SPI, (Uint16Type)SIZEOF_GYRO_HDR, buffer, ENABLE))
    {
        bT = BT_FALSE;
    }
    if ( BT_TRUE == bT )
	{
        if(SUCCESS != SPI_sfExchangeBlock(GYRO_SPI, (Uint16Type)length, data))
        {
            bT = BT_FALSE;
        }
	}
    return (bT);
}
/* End Of File EEPROM_PL_SPI_C1.c */
