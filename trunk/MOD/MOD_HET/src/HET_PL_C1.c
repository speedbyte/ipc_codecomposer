/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/
/** 
 * \file 	GIO_PL_C1.c
 * \brief	This file consists of functions that are used internally by 
 * the modules to initialise GIO Ports, to read the GIO channels, and write the
 * GIO channels. Detailed description found below.
 * \brief	Detailed description of the file.
*/
/*-----------------------------------------------------------------------------
* $Date: 2009-05-29 09:25:06 +0200 (Fr, 29 Mai 2009) $
* $Rev: 6395 $
* $Author: rammelt $
* $URL: http://subversion-01/svn/SW_HW_System/Plattform/TMS470/MOD/MOD_GIO/tags/MOD_GIO_B_10.10_pre/src/GIO_PL_C1.c $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
#include "HET.h"

/*----------------------------------------------------------------------------*/
/* pragma Directives                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global Variables Definitions (avoid as much as possible!)                  */
/*----------------------------------------------------------------------------*/
static HET_ST *pstHet    = (HET_PST)HET_BASE;
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
/* File local Code Macros                                                     */
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
/* Function    : GIO_vPinModify                                */
/** 
    \brief      Modify functionaly of one or more pins of a given port
  
    \brief      Description:\n
				Detail: Effected Register: GIODIR
				0 Output buffer is disabled.
				1 Output buffer is enabled. 

    \param      PinMask_N
    			Uint32Type
    			pins to be modified    
    \param      PinQual_N
    			Uint32Type
    			operation to be performed                          
				
    \return     void
*/
/*----------------------------------------------------------------------------*/
void HET_vPinModify(Uint32Type PinMask_N, HETQUAL PinQual_N )
{
	if (HetIoIn == PinQual_N)
    {
        pstHet->CCDir_UL  &= ~(unsigned long)PinMask_N;
    }
    else if (HetIoOut == PinQual_N)
    {
        pstHet->CCDir_UL  |= (unsigned long)PinMask_N;
    }
    else if (HetIoOutHigh == PinQual_N)
    {
        pstHet->CCDir_UL |= (unsigned long)PinMask_N;
        pstHet->CCDwr_UL |= (unsigned long)PinMask_N;
    }
    else if (HetIoOutLow == PinQual_N)
    {
        pstHet->CCDir_UL  |= (unsigned long)PinMask_N;
        pstHet->CCDwr_UL &= ~(unsigned long)PinMask_N;
    }
    else
    {
    }
    return;
}
/*----------------------------------------------------------------------------*/
/* Function    : GIO_u32PortRead                                			  */
/** 
    \brief      This function gets the value from the Data
				input Register ( GIODIN )
  
    \brief      Description:\n
				Detail: Effected Register: GIODIN

    \param      void
				
    \return     Uint32Type
    			TRUE if one or more if the bits is set, otherwise FALSE.
*/
/*----------------------------------------------------------------------------*/
Uint32Type HET_u32PortRead(void)
{
    return (pstHet->CCDin_UL);
}
/*----------------------------------------------------------------------------*/
/* Function    : GIO_PinRead_B                                				  */
/** 
    \brief      This function gets the value from the Data
				input Register ( GIODIN )
  
    \brief      Description:\n
				Detail: Effected Register: GIODIN

    \param      PinMask_N
    			Uint8Type
				port to be modified
    \param      Dev_N
    			Uint8Type
				port to be read
				
    \return     Uint8Type
    			TRUE if one or more if the bits is set, otherwise FALSE.
*/
/*----------------------------------------------------------------------------*/
Uint8Type HET_u8PinRead(Uint32Type PinMask_N)
{
	return pstHet->CCDin_UL & (unsigned long)PinMask_N ? TRUE : FALSE;
}
/*----------------------------------------------------------------------------*/
/* Function    : GIO_vPinWrite                                                */
/** 
    \brief      Write to a single Port pin 
  
    \brief      Description:\n
				Detail: Effected Register: GIODIR
				0 Output buffer is disabled.
				1 Output buffer is enabled. 

    \param      PinMask_N
    			Uint32Type
    			Pin to be written to    
    \param      PinData_B
    			Uint8Type
    			New value for specified pin                          
				
    \return     void
*/
/*----------------------------------------------------------------------------*/
void HET_vPinWrite(Uint32Type PinMask_N, Uint8Type PinData_B)
{
	Uint32Type u8PortValue;
	u8PortValue = (Uint32Type)pstHet->CCDwr_UL;
	if (PinData_B)
	{
		u8PortValue |= PinMask_N;
	}
	else
	{
		u8PortValue &= ~PinMask_N;
	}
	pstHet->CCDwr_UL = u8PortValue;
}
/*----------------------------------------------------------------------------*/
/* Function    : GIO_vPortSet                                */
/** 
    \brief      Set the Output port. 
  
    \brief      Description:\n
				This function sets the Data output register
				Effected Reg: GIODSET

    \param      PinMask_N
    			Uint32Type
    			Pin to be written to    
				
    \return     void
*/
/*----------------------------------------------------------------------------*/
void HET_vPortSet(Uint32Type PinMask_N)
{
	pstHet->CCDSet_UL = PinMask_N;
	return;
}
/*----------------------------------------------------------------------------*/
/* Function    : GIO_vPortClear                                */
/** 
    \brief      clears the Output port. 
  
    \brief      Description:\n
				This function sets the Data output register
				Effected Reg: GIODCLR

    \param      PinMask_N
    			Uint32Type
    			Pin to be written to    
				
    \return     void
*/
/*----------------------------------------------------------------------------*/
void HET_vPortClear(Uint32Type PinMask_N)
{
	pstHet->CCDClr_UL = PinMask_N;
	return;
}
/* End Of File GIO_PL_C1.c */


