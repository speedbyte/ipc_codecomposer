/******************************************************************************/
/*****************  Copyright (c) 2012 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     GYRO_C1.c
*-----------------------------------------------------------------------------
* Module Name:		MOD_GYRO
*-----------------------------------------------------------------------------
* Description:
*-----------------------------------------------------------------------------
* $Date: 2010-09-15 14:57:24 +0200 (Mi, 15 Sep 2010) $
* $Rev: 15173 $
* $Author: agrawal $
* $URL: http://subversion-01/svn/SW_HW_System/Plattform/TMS470/MOD/MOD_EEPROM/tags/MOD_EEPROM_B_10.23_pre/src/EEPROM_C1.c $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/
#include <osek.h>
#include <osekext.h>
/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/
#include "Common.h"
#include "TRACE.h"
#include "GYRO_C1.id"
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

/*----------------------------------------------------------------------------*/
/* File local Code Macros                                                        */
/*----------------------------------------------------------------------------*/
/** 
\brief	description of the macros
*/

/*----------------------------------------------------------------------------*/
/* File local Variables                                                       */
/*----------------------------------------------------------------------------*/

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
/* Function    : GYRO_bSetODR                                                 */
/** 
    \brief      Sets L3G4200D Output Data Rate 
  
    \param      ODR_Type
                Output Data Rate

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bSetODR(ODR_Type odr)
{
    Uint8Type value;

    if( BT_FALSE == GYRO_bHwReadBlock(CTRL_REG1, &value, 1) )
    {
        return BT_FALSE;
    }
    value &= 0x0f;
    value |= odr<<4;
    if (BT_FALSE == GYRO_bHwWriteBlock(CTRL_REG1, &value, 1))
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}
/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bSetMode                                                 */
/** 
    \brief      Sets L3G4200D Operating Mode 
  
    \param      Mode_Type
                Modality (NORMAL, SLEEP, POWER_DOWN)

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bSetMode(Mode_Type mode)
{
    Uint8Type value;
    if( BT_FALSE == GYRO_bHwReadBlock(CTRL_REG1, &value, 1) )
    {
        return BT_FALSE;
    }
    switch(mode)
    {
        case POWER_DOWN:
            value &= 0xF7;
            value |= (MEMS_RESET<<PD);
            break;
        case NORMAL:
            value &= 0xF7;
            value |= (MEMS_SET<<PD);
            break;
        case SLEEP:
            value &= 0xF0;
            value |= ( (MEMS_SET<<PD) | (MEMS_RESET<<ZEN) | (MEMS_RESET<<YEN) | (MEMS_RESET<<XEN) );
            break;
        default:
            return BT_FALSE;
    }
    if (BT_FALSE == GYRO_bHwWriteBlock(CTRL_REG1, &value, 1))
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}

/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bSetAxis                                                 */
/** 
    \brief      Enable/Disable L3G4200D Axis 
  
    \param      Axis_Type
                X_ENABLE/X_DISABLE | Y_ENABLE/Y_DISABLE | Z_ENABLE/Z_DISABLE

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bSetAxis(Axis_Type axis)
{
    Uint8Type value;
    if( BT_FALSE == GYRO_bHwReadBlock(CTRL_REG1, &value, 1) )
    {
        return BT_FALSE;
    }
    value &= 0xf8;
    value |= axis;
    if (BT_FALSE == GYRO_bHwWriteBlock(CTRL_REG1, &value, 1))
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bSetFullScale                                                 */
/** 
    \brief      Sets the L3G4200D FullScale 
  
    \param      Fullscale_Type
                FS_250/FS_500/FS_2000

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bSetFullScale(Fullscale_Type fs)
{
    Uint8Type value;
    if( BT_FALSE == GYRO_bHwReadBlock(CTRL_REG4, &value, 1) )
    {
        return BT_FALSE;
    }
    value &= 0xCF;
    value |= (fs<<FS);
    if (BT_FALSE == GYRO_bHwWriteBlock(CTRL_REG4, &value, 1))
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bSetBDU                                                 */
/** 
    \brief      Enable/Disable Block Data Update Functionality 
  
    \param      State_Type
                ENABLE/DISABLE

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bSetBDU(State_Type bdu)
{
    Uint8Type value;
    if( BT_FALSE == GYRO_bHwReadBlock(CTRL_REG4, &value, 1) )
    {
        return BT_FALSE;
    }
    value &= 0x7F;
    value |= (bdu<<BDU);

    if (BT_FALSE == GYRO_bHwWriteBlock(CTRL_REG4, &value, 1))
    {
        return BT_FALSE;
    }

    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bSetBLE                                                 */
/** 
    \brief      Set Endianess (MSB/LSB) 
  
    \param      Endianess_Type
                BLE_LSB / BLE_MSB

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bSetBLE(Endianess_Type ble)
{
    Uint8Type value;
    if( BT_FALSE == GYRO_bHwReadBlock(CTRL_REG4, &value, 1) )
    {
        return BT_FALSE;
    }
    value &= 0xBF;
    value |= (ble<<BLE);
    if (BT_FALSE == GYRO_bHwWriteBlock(CTRL_REG4, &value, 1))
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bSetSelfTest                                                 */
/** 
    \brief      Set Self Test Modality 
  
    \param      SelfTest_Type
                ST_NORMAL_MODE/ST_0/ST_1

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bSetSelfTest(SelfTest_Type st)
{
    Uint8Type value;
    if( BT_FALSE == GYRO_bHwReadBlock(CTRL_REG4, &value, 1) )
    {
        return BT_FALSE;
    }
    value &= 0xF9;
    value |= (st<<SELF_TEST);
    if (BT_FALSE == GYRO_bHwWriteBlock(CTRL_REG4, &value, 1))
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bHPFEnable                                                 */
/** 
    \brief      Enable/Disable High Pass Filter 
  
    \param      State_Type
                ENABLE/DISABLE

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bHPFEnable(State_Type hpf)
{
    Uint8Type value;
    if( BT_FALSE == GYRO_bHwReadBlock(CTRL_REG5, &value, 1) )
    {
        return BT_FALSE;
    }
    value &= 0xEF;
    value |= (hpf<<HPEN);
    if (BT_FALSE == GYRO_bHwWriteBlock(CTRL_REG5, &value, 1))
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bSetHPFMode                                                 */
/** 
    \brief      Set High Pass Filter Modality 
  
    \param      HPFMode_Type
                HPM_NORMAL_MODE_RES/HPM_REF_SIGNAL/HPM_NORMAL_MODE/HPM_AUTORESET_INT

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bSetHPFMode(HPFMode_Type hpf)
{
    Uint8Type value;
    if( BT_FALSE == GYRO_bHwReadBlock(CTRL_REG2, &value, 1) )
    {
        return BT_FALSE;
    }
    value &= 0xCF;
    value |= (hpf<<HPM);
    if (BT_FALSE == GYRO_bHwWriteBlock(CTRL_REG2, &value, 1))
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bSetHPFCutOFF                                                 */
/** 
    \brief      Set High Pass CUT OFF Freq 
  
    \param      HPFCutOffFreq_Type
                HPFCF_0,HPFCF_1,HPFCF_2... See Table 27 of the datasheet

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bSetHPFCutOFF(HPFCutOffFreq_Type hpf)
{
    Uint8Type value;
    if( BT_FALSE == GYRO_bHwReadBlock(CTRL_REG2, &value, 1) )
    {
        return BT_FALSE;
    }
    value &= 0xF0;
    value |= (hpf<<HPFC0);
    if (BT_FALSE == GYRO_bHwWriteBlock(CTRL_REG2, &value, 1))
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bSetIntPinMode                                                 */
/** 
    \brief      Set Interrupt Pin Modality (push pull or Open drain) 
  
    \param      IntPinMode_Type
                PUSH_PULL/OPEN_DRAIN

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bSetIntPinMode(IntPinMode_Type pm)
{
    Uint8Type value;
    if( BT_FALSE == GYRO_bHwReadBlock(CTRL_REG3, &value, 1) )
    {
        return BT_FALSE;
    }
    value &= 0xEF;
    value |= (pm<<PP_OD);
    if (BT_FALSE == GYRO_bHwWriteBlock(CTRL_REG3, &value, 1))
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bSetInt1Pin                                                 */
/** 
    \brief      Set Interrupt1 pin Function 
  
    \param      Int1PinConf_Type
                I1_ON_PIN_INT1_ENABLE | I1_BOOT_ON_INT1 | INT1_ACTIVE_HIGH
                example: SetInt1Pin(I1_ON_PIN_INT1_ENABLE | I1_BOOT_ON_INT1_ENABLE | INT1_ACTIVE_LOW) 
                         to enable Interrupt 1 or Bootsatus on interrupt 1 pin

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bSetInt1Pin(Int1PinConf_Type pinConf)
{
    Uint8Type value;
    if( BT_FALSE == GYRO_bHwReadBlock(CTRL_REG3, &value, 1) )
    {
        return BT_FALSE;
    }
    value &= 0x1F;
    value |= pinConf;
    if (BT_FALSE == GYRO_bHwWriteBlock(CTRL_REG3, &value, 1))
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bSetInt2Pin                                                 */
/** 
    \brief      Set Interrupt2 pin Function 
  
    \param      Int2PinConf_Type
                I2_DRDY_ON_INT2_ENABLE/DISABLE |
                WTM_ON_INT2_ENABLE/DISABLE | 
                OVERRUN_ON_INT2_ENABLE/DISABLE | 
                EMPTY_ON_INT2_ENABLE/DISABLE

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bSetInt2Pin(Int2PinConf_Type pinConf)
{
    Uint8Type value;
    if( BT_FALSE == GYRO_bHwReadBlock(CTRL_REG3, &value, 1) )
    {
        return BT_FALSE;
    }
    value &= 0xF0;
    value |= pinConf;
    if (BT_FALSE == GYRO_bHwWriteBlock(CTRL_REG3, &value, 1))
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bInt1LatchEnable                                                 */
/** 
    \brief      Enable Interrupt 1 Latching function 
  
    \param      State_Type
                ENABLE/DISABLE

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bInt1LatchEnable(State_Type latch)
{
    Uint8Type value;
    if( BT_FALSE == GYRO_bHwReadBlock(INT1_CFG, &value, 1) )
    {
        return BT_FALSE;
    }
    value &= 0xBF;
    value |= latch<<LIR;
    if (BT_FALSE == GYRO_bHwWriteBlock(INT1_CFG, &value, 1))
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bResetInt1Latch                                                 */
/** 
    \brief      Reset Interrupt 1 Latching function 
  
    \param      none

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bResetInt1Latch(void)
{
    Uint8Type value;
    if( BT_FALSE == GYRO_bHwReadBlock(INT1_SRC, &value, 1) )
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bSetIntConfiguration                                                 */
/** 
    \brief      Interrupt 1 Configuration 
  
    \param      Int1Conf_Type
                AND/OR, INT1_LIR ZHIE_ENABLE/DISABLE | INT1_ZLIE_ENABLE/DISABLE...

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bSetIntConfiguration(Int1Conf_Type ic)
{
    Uint8Type value;
    value = ic;

    if (BT_FALSE == GYRO_bHwWriteBlock(INT1_CFG, &value, 1))
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bSetInt1Threshold                                                 */
/** 
    \brief      Sets Interrupt 1 Threshold 
  
    \param      IntThsAxis

    \param      Uint16Type

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bSetInt1Threshold(IntThsAxis axis, Uint16Type ths)
{
    Uint8Type value;
    switch (axis)
    {
        case THS_X:
            //write the threshold LSB
            value = (Uint8Type)( ths & 0x00ff);
            if (BT_FALSE == GYRO_bHwWriteBlock(INT1_THS_XL, &value, 1))
            {
                return BT_FALSE;
            }
            //write the threshold LSB
            value = (Uint8Type)( ths >> 8);
            if (BT_FALSE == GYRO_bHwWriteBlock(INT1_THS_XH, &value, 1))
            {
                return BT_FALSE;
            }
            break;
        case THS_Y:
            //write the threshold LSB
            value = (Uint8Type)( ths & 0x00ff);
            if (BT_FALSE == GYRO_bHwWriteBlock(INT1_THS_YL, &value, 1))
            {
                return BT_FALSE;
            }
            //write the threshold LSB
            value = (Uint8Type)( ths >> 8);
            if (BT_FALSE == GYRO_bHwWriteBlock(INT1_THS_YH, &value, 1))
            {
                return BT_FALSE;
            }
            break;
        case THS_Z:
            //write the threshold LSB
            value = (Uint8Type)( ths & 0x00ff);
            if (BT_FALSE == GYRO_bHwWriteBlock(INT1_THS_ZL, &value, 1))
            {
                return BT_FALSE;
            }
            //write the threshold LSB
            value = (Uint8Type)( ths >> 8);
            if (BT_FALSE == GYRO_bHwWriteBlock(INT1_THS_ZH, &value, 1))
            {
                return BT_FALSE;
            }
            break;
        default:
            return BT_FALSE;
    }
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bSetInt1Duration                                                 */
/** 
    \brief      Sets Interrupt 1 Duration 
  
    \param      Int1Conf_Type

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bSetInt1Duration(Int1Conf_Type id)
{
    if (id > 127)
    {
      return BT_FALSE;
    }
    if (BT_FALSE == GYRO_bHwWriteBlock(INT1_DURATION, &id, 1))
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bFIFOModeEnable                                                 */
/** 
    \brief      Sets Fifo Modality 
  
    \param      FifoMode_Type

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bFIFOModeEnable(FifoMode_Type fm)
{
    Uint8Type value;

    if(fm == FIFO_DISABLE)
    {
        if( BT_FALSE == GYRO_bHwReadBlock(CTRL_REG5, &value, 1) )
        {
            return BT_FALSE;
        }
        value &= 0xBF;

        if (BT_FALSE == GYRO_bHwWriteBlock(CTRL_REG5, &value, 1))
        {
            return BT_FALSE;
        }
    }
    else
    {
        if( BT_FALSE == GYRO_bHwReadBlock(CTRL_REG5, &value, 1) )
        {
            return BT_FALSE;
        }
        value &= 0xBF;
        value |= MEMS_SET<<FIFO_EN;

        if (BT_FALSE == GYRO_bHwWriteBlock(CTRL_REG5, &value, 1))
        {
            return BT_FALSE;
        }

        if( BT_FALSE == GYRO_bHwReadBlock(FIFO_CTRL_REG, &value, 1) )
        {
            return BT_FALSE;
        }
        value &= 0x1f;
        value |= (fm<<FM0);

        if (BT_FALSE == GYRO_bHwWriteBlock(FIFO_CTRL_REG, &value, 1))
        {
            return BT_FALSE;
        }
    }

    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bSetWaterMark                                                 */
/** 
    \brief      Sets Watermark Value 
  
    \param      Uint8Type
                Watermark = [0,31]

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bSetWaterMark(Uint8Type wtm)
{
    Uint8Type value;

    if(wtm > 31)
    {
        return BT_FALSE;
    }
    if( BT_FALSE == GYRO_bHwReadBlock(FIFO_CTRL_REG, &value, 1) )
    {
        return BT_FALSE;
    }
    value &= 0xE0;
    value |= wtm;
    if (BT_FALSE == GYRO_bHwWriteBlock(FIFO_CTRL_REG, &value, 1))
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}

/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bGetStatusReg                                        */
/** 
    \brief      Read the status register 
  
    \param      Uint8Type
                Pointer to data

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bGetStatusReg(Uint8Type* buf)
{
    if( BT_FALSE == GYRO_bHwReadBlock(STATUS_REG, buf, 1) )
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bGetAngRateRaw                                        */
/** 
    \brief      Read the Angular Rate Registers 
  
    \param      Uint8Type
                Pointer to data

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bGetAngRateRaw(AngRateRaw_Type* buf)
{
    Uint8Type valueL;
    Uint8Type valueH;

    if( BT_FALSE == GYRO_bHwReadBlock(OUT_X_L, &valueL, 1) )
    {
        return BT_FALSE;
    }
    if( BT_FALSE == GYRO_bHwReadBlock(OUT_X_H, &valueH, 1) )
    {
        return BT_FALSE;
    }
    buf->x = (Sint16Type)( (valueH << 8) | valueL );
    if( BT_FALSE == GYRO_bHwReadBlock(OUT_Y_L, &valueL, 1) )
    {
        return BT_FALSE;
    }
    if( BT_FALSE == GYRO_bHwReadBlock(OUT_Y_H, &valueH, 1) )
    {
        return BT_FALSE;
    }
    buf->y = (Sint16Type)( (valueH << 8) | valueL );
    if( BT_FALSE == GYRO_bHwReadBlock(OUT_Z_L, &valueL, 1) )
    {
        return BT_FALSE;
    }
    if( BT_FALSE == GYRO_bHwReadBlock(OUT_Z_H, &valueH, 1) )
    {
        return BT_FALSE;
    }
    buf->z = (Sint16Type)( (valueH << 8) | valueL );
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bGetInt1Src                                        */
/** 
    \brief      Reset Interrupt 1 Latching function 
  
    \param      Uint8Type
                Pointer to data

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bGetInt1Src(Uint8Type* buf)
{
    if( BT_FALSE == GYRO_bHwReadBlock(INT1_SRC, buf, 1) )
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bGetFifoSourceReg                                        */
/** 
    \brief      Read Fifo source Register 
  
    \param      Uint8Type
                Pointer to data

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bGetFifoSourceReg(Uint8Type* buf)
{
    if( BT_FALSE == GYRO_bHwReadBlock(FIFO_SRC_REG, buf, 1) )
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bSetOutputDataAndFifoFilters                                        */
/** 
    \brief      ENABLE/DISABLE HIGH PASS and LOW PASS filters applied to output and fifo registers
*               See Table 8 of AN3393 for more details 
  
    \param      HPF_LPF2_Enable
                NONE, HPH, LPF2, HPFLPF2

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bSetOutputDataAndFifoFilters(HPF_LPF2_Enable hpf)
{
    Uint8Type value;
    //HPF
    if( BT_FALSE == GYRO_bHwReadBlock(CTRL_REG5, &value, 1) )
    {
        return BT_FALSE;
    }
    switch(hpf)
    {
        case NONE:
            value &= 0xfc;
            value |= 0x00; //hpen = x, Out_sel_1 = 0, Out_sel_0 = 0
            break;
        case HPF:
            value &= 0xfc;
            value |= 0x01; //hpen = x, Out_sel_1 = 0, Out_sel_0 = 1
            break;
        case LPF2:
            value &= 0xed;
            value |= 0x02; //hpen = 0, Out_sel_1 = 1, Out_sel_0 = x
            break;
        case HPFLPF2:
            value &= 0xed;
            value |= 0x12; //hpen = 1, Out_sel_1 = 1, Out_sel_0 = x
            break;
    }
    if (BT_FALSE == GYRO_bHwWriteBlock(CTRL_REG5, &value, 1))
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bSetInt1Filters                                        */
/** 
    \brief      ENABLE/DISABLE HIGH PASS and LOW PASS filters applied to Int1 circuitery
                See Table 9 of AN3393 for more details 
  
    \param      HPF_LPF2_Enable
                NONE, HPH, LPF2, HPFLPF2

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bSetInt1Filters(HPF_LPF2_Enable hpf)
{
    Uint8Type value;
    //HPF
    if( BT_FALSE == GYRO_bHwReadBlock(CTRL_REG5, &value, 1) )
    {
        return BT_FALSE;
    }
    switch(hpf)
    {
        case NONE:
            value &= 0xf3;
            value |= 0x00<<INT1_SEL0; //hpen = x, Int1_sel_1 = 0, Int1_sel_0 = 0
            break;
        case HPF:
            value &= 0xf3;
            value |= 0x01<<INT1_SEL0; //hpen = x, Int1_sel_1 = 0, Int1_sel_0 = 1
            break;
        case LPF2:
            value &= 0xe7;
            value |= 0x02<<INT1_SEL0; //hpen = 0, Int1_sel_1 = 1, Int1_sel_0 = x
            break;
        case HPFLPF2:
            value &= 0xe7;
            value |= 0x01<<HPEN;
            value |= 0x02<<INT1_SEL0; //hpen = 1, Int1_sel_1 = 1, Int1_sel_0 = x
            break;
    }
    if (BT_FALSE == GYRO_bHwWriteBlock(CTRL_REG5, &value, 1))
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}


/*----------------------------------------------------------------------------*/
/* Function    : GYRO_bSetSPIInterface                                        */
/** 
    \brief      Set SPI mode: 3 Wire Interface OR 4 Wire Interface 
  
    \param      SPIMode_Type
                SPI_3_WIRE, SPI_4_WIRE

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bSetSPIInterface(SPIMode_Type spi)
{
    Uint8Type value;
    if( BT_FALSE == GYRO_bHwReadBlock(CTRL_REG4, &value, 1) )
    {
        return BT_FALSE;
    }
    value &= 0xFE;
    value |= spi<<SIM;
    if (BT_FALSE == GYRO_bHwWriteBlock(CTRL_REG4, &value, 1))
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}

/*----------------------------------------------------------------------------*/
/* Function    : GYRO_u8GetWhoAmI                                                 */
/** 
    \brief      Get who am I 
  
    \param      Uint8Type
                Pointer to data

    \return     BooleanType
                Returns BT_TRUE whether register was correct set
                FALSE otherwise
*/
/*----------------------------------------------------------------------------*/
BooleanType GYRO_bGetWhoAmI(Uint8Type *value)
{
    if( BT_FALSE == GYRO_bHwReadBlock(WHO_AM_I, value, 1) )
    {
        return BT_FALSE;
    }
    return BT_TRUE;
}

/* End Of File GYRO_C1.c */

