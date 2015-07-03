
#ifndef _IPC_H
#define _IPC_H

/*----------------------------------------------------------------------------*/
/* System Includes                                                            */
/*----------------------------------------------------------------------------*/
#include "Common.h"

/*----------------------------------------------------------------------------*/
/* Libraries from external Vendors                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Own Header Files                                                           */
/*----------------------------------------------------------------------------*/
/* include the export configuration file */
#include "IPC_CE.h"

/*----------------------------------------------------------------------------*/
/* Public Manifest Constant Definitions                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Types                                                               */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Global Variables Declarations (avoid as much as possible!)                 */
/*----------------------------------------------------------------------------*/
static const Uint8Type _IPC_au8TestBytes[1] =     {0x11};
/*----------------------------------------------------------------------------*/
/* Global const Declarations                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Public Methods                                                             */
/*----------------------------------------------------------------------------*/
#ifdef OSEK_SUPPORTED_OS
extern void IPC_vProcessCommands(void);
#else
extern void IPC_vProcessCommands(int fd, int getCount);
#endif
#ifdef OSEK_SUPPORTED_OS
extern void IPC_vMonitorCommunication(void);
#else
extern void IPC_vMonitorCommunication(int fd);
#endif
#ifdef OSEK_SUPPORTED_OS
extern void IPC_vWriteManager(void);
#else
extern void IPC_vWriteManager(int fd);
#endif

extern SuccessFailType IPC_sfInit(IPC_ENUM_CHANNEL channel);

extern Uint16Type IPC_u16WriteBlock(IPC_ENUM_CHANNEL channel, const Uint8Type *block, Uint8Type sizeofBlock, void(*cb)(Uint8Type *, Uint8Type));

extern Uint16Type IPC_u16WriteResponseBlock(IPC_ENUM_CHANNEL channel, const Uint8Type *block, Uint8Type sizeofBlock, void (*cb)(Uint8Type *, Uint8Type));
/*----------------------------------------------------------------------------*/
/* Public Code Macros                                                         */
/*----------------------------------------------------------------------------*/



#endif /* _IPC_H */

/* End Of File IPC.h */


