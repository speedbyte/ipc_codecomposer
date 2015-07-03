/*
 * GPIO Map: 7 A ( Interrupt Enabled )  + 1 A Interrupt Enabled and only Input + 8 B +8 C + 4 D
 */
#include "Common.h"
#include "GIO.h"
#include "PORT.h"
#include "SPI.h"
#include "MONITOR_ADC.h"
#include "HET.h"
/* Dead Code. For future implementation. - VA --------*/
#define WD_PORT GIOD
#define WD_PIN PIN2
#define PORT_vPinModify(WD_PORT, WD_PIN, x) GIO_vPinModify(WD_PORT, WD_PIN, x)
/* --------------------- */
inline void _PORT_vInitGIO(void);

#if (defined(PROCESSOR_TMS470R1VF55BA) || defined(PROCESSOR_TMS470R1SF55BA))

void CAN_vPortSet(CAN_ST *pstCan, Uint8Type PIN )
{
    if (RX == PIN)
    {
        pstCan->RIOC_UN.RIOC_ST.RxFunc_B1 = 0;
        pstCan->RIOC_UN.RIOC_ST.RxDir_B1 = 1;
        pstCan->RIOC_UN.RIOC_ST.RxOut_B1 = 1;
    }
    else if (TX == PIN)
    {
        pstCan->TIOC_UN.TIOC_ST.TxFunc_B1 = 0;
        pstCan->TIOC_UN.TIOC_ST.TxDir_B1 = 1;
        pstCan->TIOC_UN.TIOC_ST.TxOut_B1 = 1;

    }
    else
    {
    }
    return;
}

void CAN_vPortClear(CAN_ST *pstCan, Uint8Type PIN )
{
    if ( RX == PIN )
    {
        pstCan->RIOC_UN.RIOC_ST.RxFunc_B1 = 0;
        pstCan->RIOC_UN.RIOC_ST.RxDir_B1 = 1;
        pstCan->RIOC_UN.RIOC_ST.RxOut_B1 = 0;
    }
    else if (TX == PIN)
    {
        pstCan->TIOC_UN.TIOC_ST.TxFunc_B1 = 0;
        pstCan->TIOC_UN.TIOC_ST.TxDir_B1 = 1;
        pstCan->TIOC_UN.TIOC_ST.TxOut_B1 = 0;
    }
    else
    {
    }
    return;
}


#endif


void PORT_vInit()
{
	_PORT_vInitGIO();
}


inline void _PORT_vInitGIO()
{
    HET_vPinModify(HET_9V_ENABLE, HetIoOutHigh);

    /* Enable AD Multiplexer */
    HET_vPinModify(HET_MUX_EN, HetIoOutLow);

    /* Set MUX_A0 - MUX_A2 as output */
    HET_vPinModify(HET_MUX_A0, HetIoOut);
    HET_vPinModify(HET_MUX_A1, HetIoOut);
    HET_vPinModify(HET_MUX_A2, HetIoOut);

	GIO_vPinModify(GIOA, PORT_NOTUSED_PIN0_GIOA, PortIoOutLow);
	GIO_vPinModify(GIOA, PORT_CAN_ERROR, PortIoIn);
    /* Set the CANInh Pin as a Input */
    GIO_vPinModify(GIOA, PORT_CAN_INHIBIT, PortIoIn);

    /* set Pin as Input, Power Info OMAP */
	GIO_vPinModify(GIOA, PORT_IS_OMAP_SHUTDOWN, PortIoIn);


    /*set explicit to low*/
    GIO_vPinModify(GIOA, PORT_NOTUSED_PIN1_GIOA, PortIoOutLow);
    GIO_vPinModify(GIOA, PORT_NOTUSED_PIN4_GIOA, PortIoOutLow);
    GIO_vPinModify(GIOA, PORT_NOTUSED_PIN6_GIOA, PortIoOutLow);
    GIO_vPinModify(GIOA, PORT_NOTUSED_PIN7_GIOA, PortIoOutLow);

	GIO_vPinModify(GIOB, PORT_FLASH_EN, PortIoOutHigh);
	/* set OMAP reset to high output */
	GIO_vPinModify(GIOB, PORT_OMAP_RESET, PortIoOutHigh);
	AUDIO_DIAG_END

	GIO_vPinModify(GIOB, PORT_NOTUSED_PIN2_GIOB, PortIoOutHigh);

    SPI_vPinModify(SPI5, SpiEnablePin, PortIoOutLow);   /* CAN_EN */
	CAN_vPortClear(CAN3, RX);                             /* CAN_STB */

	GIO_vPinModify(GIOD, PORT_MON_WATCHDOG, PortIoOutHigh);
	GIO_vPinModify(GIOD, PORT_U_GPS_EN, PortIoOutHigh);
	GIO_vPinModify(GIOD, PORT_MIC_EN, PortIoOutHigh);
	GIO_vPinModify(GIOD, PORT_MON_PWRHOLD, PortIoOutHigh);

	//5V, USB 1
	GIO_vPinModify(GIOC, USB_HOST1_VBUS_EN, PortIoOutHigh);
	//5V, USB 2
	GIO_vPinModify(GIOC, USB_HOST2_VBUS_EN, PortIoOutHigh);

	//OMAP Power On
	GIO_vPinModify(GIOC, PORT_OMAP_PWRON, PortIoOutLow);


    /*switch Trancseiver to power on mode*/
    SPI_vPinModify(SPI5, SpiEnablePin, PortIoOutLow);   /* CAN_EN */
	CAN_vPortSet(CAN3, RX);                             /* CAN_STB */

    /* Tuner enable */
    HET_vPinModify(HET_MASTER_RESET, HetIoOutHigh);
    HET_vPinModify(HET_TUNER_ENABLE, HetIoOutHigh);

    HET_vPinModify(HET_U_FM1_EN, HetIoOutHigh);
    HET_vPinModify(HET_U_FM2_EN, HetIoOutHigh);
    HET_vPinModify(HET_U_ANT_ON_EN, HetIoOutHigh);
    HET_vPinModify(HET_U_CAM_EN, HetIoOutHigh);
    HET_vPinModify(HET_SDARS_EN, HetIoOutHigh);
}
