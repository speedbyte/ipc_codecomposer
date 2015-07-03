#ifndef PORT_H_
#define PORT_H_

#include "PORT_CE.h"
#include "CAN_CB_cfg.h"

typedef enum
{
    PortFunctional,
    PortIoIn,
    PortIoOut,
    PortIoOutHigh,
    PortIoOutLow
}PORTQUAL;

#if (defined(PROCESSOR_TMS470R1VF55BA) || defined(PROCESSOR_TMS470R1SF55BA))
#define CAN3  (CAN_PST)HECC3_BASE
#define RX      1
#define TX      2
#endif

void PORT_vInit(void);

#if (defined(PROCESSOR_TMS470R1VF55BA) || defined(PROCESSOR_TMS470R1SF55BA))
void CAN_vPortSet(CAN_ST *pstCan, Uint8Type PIN);
void CAN_vPortClear(CAN_ST *pstCan, Uint8Type PIN );
#endif

/* Interface for MOD_APP_MDI to Set/Reset AppleIC Port
 * Needed for Parrot module iPod handling
 */
#define PORT_APPLEIC_SET          GIO_vPinModify(GIOC, PORT_APPLEIC_EN, PortIoOutHigh)
#define PORT_APPLEIC_RESET        GIO_vPinModify(GIOC, PORT_APPLEIC_EN, PortIoOutLow)

#endif /*PORT_H_*/
