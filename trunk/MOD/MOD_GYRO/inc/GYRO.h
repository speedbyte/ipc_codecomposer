/******************************************************************************/
/*****************  Copyright (c) 2008 by S1nn GmbH & Co. KG  *****************/
/***************************  All Rights Reserved  ****************************/
/******************************************************************************/

/******************************************************************************/
/* File Name:     GYRO.h
*-----------------------------------------------------------------------------
* Module Name:	  MOD_GYRO
*-----------------------------------------------------------------------------
* Description:	  Gyro Driver header file
*-----------------------------------------------------------------------------
* $Date: 2010-05-14 17:11:24 +0200 (Fr, 14 Mai 2010) $
* $Rev: 13085 $
* $Author: agrawal $
* $URL: http://subversion-01/svn/SW_HW_System/Plattform/TMS470/MOD/MOD_EEPROM/tags/MOD_EEPROM_B_10.23_pre/inc/EEPROM.h $
*-----------------------------------------------------------------------------
*/
/******************************************************************************/

#ifndef _GYRO_H
#define _GYRO_H

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/
#include "Common.h"
#include "tms470r1.h"
/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
#include "GYRO_CE.h"
/*----------------------------------------------------------------------------*/
/* Public Manifest Constant Definitions                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Types                                                               */
/*----------------------------------------------------------------------------*/
#define GYRO_WRITE_MEMORY_SHIFT     (1 << 7)  /* Write in Progress            */

#define ValBit(VAR,Place)         (VAR & (1<<Place))
#define BIT(x) ( (x) )
#define MEMS_SET                                0x01
#define MEMS_RESET                              0x00

typedef enum
{
  MEMS_ENABLE			=		0x01,
  MEMS_DISABLE			=		0x00
}State_Type;

typedef enum
{
  ODR_100Hz_BW_12_5     =		0x00,
  ODR_100Hz_BW_25		=		0x01,
  ODR_200Hz_BW_12_5     =		0x04,
  ODR_200Hz_BW_25		=		0x05,
  ODR_200Hz_BW_50		=		0x06,
  ODR_200Hz_BW_70		=		0x07,
  ODR_400Hz_BW_20		=		0x08,
  ODR_400Hz_BW_25		=		0x09,
  ODR_400Hz_BW_50		=		0x0A,
  ODR_400Hz_BW_110      =		0x0B,
  ODR_800Hz_BW_30		=		0x0C,
  ODR_800Hz_BW_35		=		0x0D,
  ODR_800Hz_BW_50		=		0x0E,
  ODR_800Hz_BW_110      =		0x0F
} ODR_Type;

typedef enum
{
  POWER_DOWN        =		0x00,
  SLEEP		        =		0x01,
  NORMAL			=		0x02
} Mode_Type;

typedef enum
{
  HPM_NORMAL_MODE_RES           =               0x00,
  HPM_REF_SIGNAL                =               0x01,
  HPM_NORMAL_MODE               =               0x02,
  HPM_AUTORESET_INT             =               0x03
} HPFMode_Type;

typedef enum
{
  HPFCF_0                       =               0x00,
  HPFCF_1                       =               0x01,
  HPFCF_2                       =               0x02,
  HPFCF_3                       =               0x03,
  HPFCF_4                       =               0x04,
  HPFCF_5                       =               0x05,
  HPFCF_6                       =               0x06,
  HPFCF_7                       =               0x07,
  HPFCF_8                       =               0x08,
  HPFCF_9                       =               0x09
} HPFCutOffFreq_Type;

typedef enum
{
  PUSH_PULL                     =               0x00,
  OPEN_DRAIN                    =               0x01
} IntPinMode_Type;

typedef Uint8Type Int1PinConf_Type;
typedef Uint8Type Int2PinConf_Type;
typedef Uint8Type Axis_Type;

typedef enum
{
  FULLSCALE_250                 =               0x00,
  FULLSCALE_500                 =               0x01,
  FULLSCALE_2000                =               0x02
} Fullscale_Type;

typedef enum
{
  BLE_LSB			=		0x00,
  BLE_MSB			=		0x01
} Endianess_Type;

typedef enum
{
  SELF_TEST_DISABLE             =               0x00,
  SELF_TEST_0                   =               0x01,
  SELF_TEST_1                   =               0x03
} SelfTest_Type;

typedef Uint8Type Int1Conf_Type;

typedef enum
{
  THS_X                         =               0x00,
  THS_Y                         =               0x01,
  THS_Z                         =               0x02
} IntThsAxis;

typedef enum
{
  FIFO_DISABLE                  =               0x05,
  FIFO_BYPASS_MODE              =               0x00,
  FIFO_MODE                     =               0x01,
  FIFO_STREAM_MODE              =               0x02,
  FIFO_STREAM_TO_FIFO_MODE      =               0x03,
  FIFO_BYPASS_TO_STREAM_MODE    =               0x04 
} FifoMode_Type;

typedef enum
{
  NONE                          =               0x00,
  HPF                           =               0x01,
  LPF2                          =               0x02,
  HPFLPF2                       =               0x03
} HPF_LPF2_Enable;

typedef struct
{
  Sint16Type x;
  Sint16Type y;
  Sint16Type z;
} AngRateRaw_Type;

typedef enum {
  SPI_4_WIRE                    =               0x00,
  SPI_3_WIRE                    =               0x01
} SPIMode_Type;

typedef enum
{
  X_ENABLE                      =               0x04,
  X_DISABLE                     =               0x00,
  Y_ENABLE                      =               0x02,
  Y_DISABLE                     =               0x00,
  Z_ENABLE                      =               0x01,
  Z_DISABLE                     =               0x00
} AXISenable_Type;

/*----------------------------------------------------------------------------*/
/* Global Variables Declarations (avoid as much as possible!)                 */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Global const Declarations                                                  */
/*----------------------------------------------------------------------------*/
//Register Definition
#define WHO_AM_I				0x0F // device identification register

// CONTROL REGISTER 1
#define CTRL_REG1				0x20
#define ODRR					BIT(4)
#define PD					BIT(3)
#define ZEN					BIT(2)
#define YEN					BIT(1)
#define XEN					BIT(0)

//CONTROL REGISTER 2
#define CTRL_REG2				0x21
#define HPM					BIT(4)
#define HPFC3					BIT(3)
#define HPFC2					BIT(2)
#define HPFC1					BIT(1)
#define HPFC0					BIT(0)

//CONTROL REGISTER 3
#define CTRL_REG3				0x22
#define I1_INT					BIT(7)
#define I1_BOOT					BIT(6)
#define H_LACTIVE				BIT(5)
#define PP_OD					BIT(4)
#define I2_DRDY					BIT(3)
#define I2_WTM					BIT(2)
#define I2_ORUN					BIT(1)
#define I2_EMPTY				BIT(0)

#define I1_ON_PIN_INT1_ENABLE                   0x80
#define I1_ON_PIN_INT1_DISABLE                  0x00
#define I1_BOOT_ON_INT1_ENABLE                  0x40
#define I1_BOOT_ON_INT1_DISABLE                 0x00
#define INT1_ACTIVE_HIGH                        0x00
#define INT1_ACTIVE_LOW                         0x20

#define I2_DRDY_ON_INT2_ENABLE                  0x08
#define I2_DRDY_ON_INT2_DISABLE                 0x00
#define WTM_ON_INT2_ENABLE                      0x04
#define WTM_ON_INT2_DISABLE                     0x00
#define OVERRUN_ON_INT2_ENABLE                  0x02
#define OVERRUN_ON_INT2_DISABLE                 0x00
#define EMPTY_ON_INT2_ENABLE                    0x01
#define EMPTY_ON_INT2_DISABLE                   0x00

//CONTROL REGISTER 4
#define CTRL_REG4				0x23
#define BDU					BIT(7)
#define BLE					BIT(6)
#define FS					BIT(4)
#define SELF_TEST				BIT(1)
#define SIM					BIT(0)

//CONTROL REGISTER 5
#define CTRL_REG5				0x24
#define FIFO_EN                                 BIT(6)
#define HPEN                                    BIT(4)
#define INT1_SEL1                               BIT(3)
#define INT1_SEL0                               BIT(2)
#define OUT_SEL1                                BIT(1)
#define OUT_SEL0                                BIT(0)

//INTERRUPT 1 CONFIGURATION
#define INT1_CFG				0x30
#define LIR                                     BIT(6)
#define ANDOR                                   BIT(7)
#define ZHIE                                    BIT(5)
#define ZLIE                                    BIT(4)
#define YHIE                                    BIT(3)
#define YLIE                                    BIT(2)
#define XHIE                                    BIT(1)
#define XLIE                                    BIT(0)


#define INT1_AND                                0x80
#define INT1_OR                                 0x00
#define INT1_LIR_ENABLE                         0x40
#define INT1_LIR_DISABLE                        0x00
#define INT1_ZHIE_ENABLE                        0x20
#define INT1_ZHIE_DISABLE                       0x00
#define INT1_ZLIE_ENABLE                        0x10
#define INT1_ZLIE_DISABLE                       0x00
#define INT1_YHIE_ENABLE                        0x08
#define INT1_YHIE_DISABLE                       0x00
#define INT1_YLIE_ENABLE                        0x04
#define INT1_YLIE_DISABLE                       0x00
#define INT1_XHIE_ENABLE                        0x02
#define INT1_XHIE_DISABLE                       0x00
#define INT1_XLIE_ENABLE                        0x01
#define INT1_XLIE_DISABLE                       0x00

#define INT1_THS_XH                             0x32
#define INT1_THS_XL                             0x33
#define INT1_THS_YH                             0x34
#define INT1_THS_YL                             0x35
#define INT1_THS_ZH                             0x36
#define INT1_THS_ZL                             0x37

//INTERRUPT 1 SOURCE REGISTER
#define INT1_SRC				0x31

//FIFO CONTROL REGISTER
#define FIFO_CTRL_REG                           0x2E
#define FM0                                     BIT(5)

//OUTPUT REGISTER
#define OUT_X_L					0x28
#define OUT_X_H					0x29
#define OUT_Y_L					0x2A
#define OUT_Y_H					0x2B
#define OUT_Z_L					0x2C
#define OUT_Z_H					0x2D


//STATUS REGISTER
#define STATUS_REG                              0x27
#define STATUS_REG_ZYXOR                        0x07    // 1	:	new data set has over written the previous one
							// 0	:	no overrun has occurred (default)	
#define STATUS_REG_ZOR                          0x06    // 0	:	no overrun has occurred (default)
							// 1	:	new Z-axis data has over written the previous one
#define STATUS_REG_YOR                          0x05    // 0	:	no overrun has occurred (default)
							// 1	:	new Y-axis data has over written the previous one
#define STATUS_REG_XOR                          0x04    // 0	:	no overrun has occurred (default)
							// 1	:	new X-axis data has over written the previous one
#define STATUS_REG_ZYXDA                        0x03    // 0	:	a new set of data is not yet avvious one
                                                        // 1	:	a new set of data is available 
#define STATUS_REG_ZDA                          0x02    // 0	:	a new data for the Z-Axis is not availvious one
                                                        // 1	:	a new data for the Z-Axis is available
#define STATUS_REG_YDA                          0x01    // 0	:	a new data for the Y-Axis is not available
                                                        // 1	:	a new data for the Y-Axis is available
#define STATUS_REG_XDA                          0x00    // 0	:	a new data for the X-Axis is not available

#define DATAREADY_BIT                           STATUS_REG_ZYXDA

#define I_AM_L3G4200D			        0xD3 

//FIFO REGISTERS
#define FIFO_CTRL_REG			        0x2E
#define FIFO_SRC_REG			        0x2F

//INT1 REGISTERS
#define INT1_TSH_XH				0x32
#define INT1_TSH_XL				0x33
#define INT1_TSH_YH				0x34
#define INT1_TSH_YL				0x35
#define INT1_TSH_ZH				0x36
#define INT1_TSH_ZL				0x37
#define INT1_DURATION			0x38




/*----------------------------------------------------------------------------*/
/* Public Methods                                                             */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Code Macros                                                         */
/*----------------------------------------------------------------------------*/

//Sensor Configuration Functions
BooleanType GYRO_bSetODR(ODR_Type ov);
BooleanType GYRO_bSetMode(Mode_Type md);
BooleanType GYRO_bSetAxis(Axis_Type axis);
BooleanType GYRO_bSetFullScale(Fullscale_Type fs);
BooleanType GYRO_bSetBDU(State_Type bdu);
BooleanType GYRO_bSetBLE(Endianess_Type ble);
BooleanType GYRO_bSetSelfTest(SelfTest_Type st);

//Filtering Functions
BooleanType GYRO_bHPFEnable(State_Type hpf);
BooleanType GYRO_bSetHPFMode(HPFMode_Type hpf);
BooleanType GYRO_bSetHPFCutOFF(HPFCutOffFreq_Type hpf);
BooleanType GYRO_bSetOutputDataAndFifoFilters(HPF_LPF2_Enable hpf);
BooleanType GYRO_bSetInt1Filters(HPF_LPF2_Enable hpf);

//Interrupt Functions
BooleanType GYRO_bSetIntPinMode(IntPinMode_Type pm);
BooleanType GYRO_bSetInt1Pin(Int1PinConf_Type pinConf);
BooleanType GYRO_bSetInt2Pin(Int2PinConf_Type pinConf);
BooleanType GYRO_bInt1LatchEnable(State_Type latch);
BooleanType GYRO_bResetInt1Latch(void);
BooleanType GYRO_bSetIntConfiguration(Int1Conf_Type ic);
BooleanType GYRO_bSetInt1Threshold(IntThsAxis axis, Uint16Type ths);
BooleanType GYRO_bSetInt1Duration(Int1Conf_Type id);

//FIFO Functions
BooleanType GYRO_bFIFOModeEnable(FifoMode_Type fm);
BooleanType GYRO_bSetWaterMark(Uint8Type wtm);

//Reading Functions
BooleanType GYRO_bGetStatusReg(Uint8Type* buff);
BooleanType GYRO_bGetAngRateRaw(AngRateRaw_Type* buff);
BooleanType GYRO_bGetInt1Src(Uint8Type* buff);
BooleanType GYRO_bGetFifoSourceReg(Uint8Type* buff);
BooleanType GYRO_bGetWhoAmI(Uint8Type *value);

#endif /* _GYRO_H */

/* End Of File GYRO.h */
