/******   STARTSINGLE_OF_MULTIPLE_COMMENT    ******/


/*****************************************************************************/
/**
 * \file  SIP_VERS.C
 * \brief Vector SIP (Software Integration Package) version check
 *
 *  \pre 
 *  The purpose of this file is to:
 *  1) Check that all currently compiled files in the system have the correct 
 *     versions according to the delivered software integration package (SIP).
 *  2) Provide the SIP version as ROM constants for e.g. diagnostic purposes.
 *
 *-----------------------------------------------------------------------------
 *
 *  Usage hints: What to do when a compiler error occurs within this file?
 *               If a compiler error occurs within this file, a wrong version
 *               for the notified module has been detected. 
 *               Please check, if
 *               a) The module is part of your project and the include path is 
 *                  set correct (if not, the compiler may assume 0 for the 
 *                  version number comparison)
 *               b) The used module may have an incorrect version for this
 *                  project. Proof carefully, if a newer (or older) version
 *                  of the notified component is already available on your site
 *                  and an erroneous version mixup had occurred. See the required
 *                  module's main and bugfix version above of the error message.
 *               c) This may be the wrong SIP version check file for the project.
 *                  Proof carefully, if the file has been exchanged together with
 *                  the latest change of a component (e.g. an bugfix delivery), 
 *                  too.
 *               In case none of the above mention points is true, please contact 
 *               your Vector's contact person for further help.
 *
 *****************************************************************************
 *
 *  Background information: Each Vector software component checks its own header
 *               and code files for version consistency. With this, a version  
 *               mixup within each component could be detected during compilation.
 *               To detect the mixup of different components in a project, too,
 *               this version check file has been introduced.
 *                                
 *****************************************************************************
 *               C O P Y R I G H T
 *****************************************************************************
 * Copyright (c) 2011 by Vector Informatik GmbH.           All rights reserved.
 *
 *                    Alle Rechte an der Software verbleiben bei der
 *                    Vector Informatik GmbH.
 *                    Vector Informatik GmbH räumt dem Lizenznehmer das unwider-
 *                    rufliche, geographisch und zeitlich nicht beschränkte,
 *                    jedoch nicht ausschließliche Nutzungsrecht innerhalb des
 *                    Lizenznehmers ein. Die Weitergabe des Nutzungsrechts
 *                    durch den Lizenznehmers ist auf dessen Zulieferer
 *                    beschränkt. Die Zulieferer sind zu verpflichten, die
 *                    Software nur im Rahmen von Projekten für den Lizenznehmer
 *                    zu verwenden; weitere Rechte der Zulieferer sind
 *                    auszuschließen.
 *
 *     Use of this source code is subject to the License Agreement "license.txt"
 *     distributed with this file. You may not use this source code unless you
 *     agree to the terms of the License Agreement.
 *
 *     REMOVAL OF THESE COMMENTS IS A VIOLATION OF THE LICENSE AGREEMENT.
 *
 *****************************************************************************
 *               A U T H O R   I D E N T I T Y
 *****************************************************************************
 * Initials     Name                      Company
 * ********     *********************     ************************************
 * Ra           Andreas Raisch            Vector Informatik GmbH
 * Hgo          Hua Guo                   Vector Informatik GmbH
 * Abc/visabc   Alexander Becker          Vector Informatik GmbH
 * Bwr          Bernhard Wissinger        Vector Informatik GmbH
 * Fr           Markus Feninger           Vector Informatik GmbH
 * visdbr       Daniela Brenner           Vector Informatik GmbH
 * visagh       Alexander Gronbach        Vector Informatik GmbH
 * Stu          Bernd Stumpf              Vector Informatik GmbH
 * Ntr          Nam Trinh                 Vector Informatik GmbH
 * visget       Matthias Gette            Vector Informatik GmbH
 * visbwa       Benjamin Walter           Vector Informatik GmbH
 * viskrt       Kerstin Thim              Vector Informatik GmbH
 * visoh        Oliver Hornung            Vector Informatik GmbH
 * visjy        Junwei Ye                 Vector Informatik GmbH
 * vishkh       Hagen Keinath             Vector Informatik GmbH
 * visbch       Christoph Breuer          Vector Informatik GmbH
 *****************************************************************************
 *               R E V I S I O N   H I S T O R Y
 *****************************************************************************
 * Date         Version Author  Description
 * ********     ************** ***********************************************
 * 02-11-14     1.00.00 Ra      First template version, based on proposal by Hp
 * 07-11-07     2.00.00 Hgo     use v_ver.h to automatically check SIP Version
 * 07-11-16     2.01.00 Abc     sip_vers OEM independent
 * 07-11-19     2.01.01 Abc     different bugfixes
 * 08-01-31     2.01.02 Bwr     adaption for TMS470HeccScc
 * 08-03-10     2.01.03 Hgo     correct diag
 * 08-03-12     2.01.04 Hgo     correct Tp_ISO_SCS bugfix version check
 * 08-03-12     2.01.05 Fr      SipVersion declaration included
 * 08-03-13     2.01.06 Hgo     COMMENT rule for GW_AS_DC added
 * 08-03-13     2.01.07 Et      GenTool (release => bugfix version) + DIAG modifications
 *                              _GENTOOL_CANGEN_VERSION / _GENTOOL_CANGEN_RELEASE_VERSION
 * 08-03-14     2.01.08 Hgo     DBKomGEN version check added
 *                              both release and bugfix version names supported
 * 08-03-17     2.01.09 Et      corrected GenTool CANgen/DBKOMgen version support
 * 08-04-04     2.01.10 Hgo     ESCAN00025852
 *                              added the check for some components, if it is used
 * 08-04-17     2.01.11 Dbr     adaption for TMS470HeccScc ARM
 * 08-04-23     2.01.12 visagh  added Mpc55xx_Flexcan2 with GHS and corrected VWTP20
 *                              COMMENT rule for GENy, CANgen and DBKOMgen added
 * 08-04-28     2.01.13 Hgo     added H8S RCAN and HCAN1 support
 * 08-04-28     2.01.14 visbwr  fixed GMLAN and FJ16FX support
 * 08-05-07     2.01.15 visbwr  added TP_MCAN support
 * 08-05-07     2.01.16 Dbr     added LIN for MPC55XX GHS Flexcan2
 * 08-05-08     2.01.17 Dbr     added CanDrv R32C/Renesas
 * 08-05-08     2.01.18 Hgo     added gw_sig, gw_msg
 * 08-05_13     2.01.19 Stu     added CanDrv Stm8a/Cosmic
 * 08-05-19     3.00.00 Hgo     added Asr Componente
 *                              added Lib check
 *                              added Version Check for not-Vector Component
 *                              supported version check for mpc55xx from version 2.09.xx
 * 08-05-29     3.00.01 Hgo     filted the lib check for canbedded delivery
 * 08-05-29     3.00.02 Hgo     changed for _COMMON Key
 *                              added Issm and Vmm
 * 08-05-30     3.00.03 Hgo     canceled the version check of Comstacktypes and stdtypes
 * 08-05-30     3.00.04 Hgo     canceled the version check of CommonAsr
 * 08-05-30     3.00.05 Hgo     corrected the header relation
 * 08-06-02     3.00.06 visagh  changed include of NmDirOsek
 * 08-06-03     3.00.07 visagh  corrected include of NmDirOsek
 * 08-06-20     3.00.08 viset   support "old" and "new" NmDirOsek versions
 * 08-06-26     3.00.09 abc     added VGEN_ENABLE_DIAG_ASR_DCM for DCM v1.x.x
 * 08-06-27     3.00.10 visagh  support Ccl_Vector for non Vector OEMs
 * 08-06-30     3.00.11 abc     support for automatic scan of Ccl_CclCom version
 * 08-07-02     3.00.12 visagh  fixed XC2000 and BF5XX support
 *                              different bugfixes related to formatting
 * 08-07-29     3.00.13 Ntr     added Mpc55xx_Flexcan2 with Diabdata
 * 08-07-29     3.00.14 Rna     added DSPIC33FECANHLL added
 * 08-08-04     3.00.15 Tri     AUTOSAR naming convention applied
 * 08-08-06     3.00.16 visagh  corrected support of VWTP20
 * 08-08-08     3.00.17 visbwr  added support of C_COMP_QCC_TMS320ARM
 * 08-08-14     3.00.18 visget  corrected VStdLib lib check (SH2)
 * 08-08-22     3.00.19 viset   avoid compiler warnings for M16C with Mitsubishi
 * 08-08-25     3.00.20 Hgo     corrected include for the dependence of NmDirOsek
 * 08-08-26     3.00.21 viset   corrected V3.00.19 modification (M16C instead of  M32C)
 * 08-08-26     3.00.22 viset   corrected V3.00.19 modification (main/sub version name)
 * 08-08-28     3.00.23 Ntr     corrected DrvCAN check (C_COMP_IAR_78K0)
 * 08-08-29     3.00.24 Rna     LIN Drv TMS470 added
 * 08-09-04     3.00.25 Hgo     corrected the include filter for NM_DIROSEKEXT_DC
 * 08-09-11     3.00.26 Abc     CAN Drv TMS470DCAN added
 * 08-09-18     3.00.27 Rna     Version defines for V850 changed
 * 08-10-08     3.00.28 Abc     Added CANbedded support for C_COMP_MICROSOFT_TMS320ARM
 * 08-10-27     3.00.29 Abc     Version check for V850 corrected:
 *                              C_PROCESSOR_AVALON / DRVCAN_V85XDCANIDX added
 * 08-11-11     3.00.30 viset   avoid compiler warnings for M32R with Mitsubishi
 * 08-11-19     3.00.31 visagh  corrected check of TMS320ARM
 * 08-11-24     3.00.32 visagh  added include of Frfm header file
 * 08-12-18     3.00.33 viset   Nm_DirOsekUserdata_Dc supported by GenTool_Geny only
 * 08-12-22     3.00.34 vishgo  Cancelled the check, if all deliveried modules in one project are used.
 * 08-12-22     3.00.35 vishgo  extended version check from VolvoAb to all postbuild delivery
 *                              added the check, if all deliveried modules in a postbuild project are used.
 * 09-01-02     3.00.36 viset   added missing #endif for VGEN_ENABLE_IF_ASRIFMEM filter rule (postbuild)
 * 09-01-08             visfmi  changed library version check switch to SIPVERSIONCHECK_CHECKLIBVERSION
 * 09-01-14             visdbr  changed defines for FJ16FX, VGEN_ENABLE_DRVCANTRANS_TJA1041ASR, VGEN_ENABLE_CCL_ASRCOMM and VGEN_ENABLE_CCL_ASRSMCAN
 * 09-01-21     3.00.37 viset   support CANdrv SH2 HCAN2 (RI 1.5)
 * 09-01-27     3.01.00 vishgo  added Asr makefile
 * 09-01-28     3.01.01 vislo   Add VGEN_ENABLE for all MCAL components
 * 09-01-29     3.01.02 vislo   Adapt version in header
 * 09-02-18     3.01.03 visagh  added support of C_COMP_MTRWRKS_MPC5X00_MSCAN
 * 09-02-18     3.01.04 visagh  Version defines for MPC5X00 VStdLib changed
 * 09-03-13     3.01.05 vismfi  Remove DIAG_ASRDEM__CORE_LIB_SYMBOL, the dependence of the Dem to the Lib is obsolete
 * 09-03-18             visagh  Restructured CanDrv's and Nm's with different version defines to fix compiler warnings and wrong errors
 * 09-03-31     3.01.06 visagh  added support of C_COMP_RENESAS_M16C_RCAN2
 * 09-04-07     3.01.07 viset   support C_COMP_MATSUSHITA_MN101E_CCAN
 * 09-04-29     3.01.08 visagh  support C_COMP_ARM_TCC800X_CCAN
 * 09-05-06     3.01.09 visagh  support C_COMP_IAR_M16C_RCAN2
 * 09-05-13     3.01.10 vishgo  fixed AsrFrTp version check
 *                              checked the version between generated and static files
 * 09-05-14     3.01.11 visbwa  fixed SysService_AsrCrc version check (removed 'V_')
 * 09-05-29     3.01.12 vishgo  deleted the error for Lib, if the module in the license but not used by customer.
 * 09-06-02     3.01.13 viset   support C_COMP_GAIO_SH2_RCAN
 * 09-06-19     3.01.14 vihkh   changed include sequence of gdda.h and desc.h
 * 09-06-30     3.01.15 vishgo  changed DEM Name for Daimler from DC to DAIMLER
 * 09-07-23     3.01.16 visabc  added _CCL_DPM_DC_VERSION / _RELEASE_VERSION
 * 09-08-25     3.01.17 visagh  only check version of NmHighWrapper if NmHigh is enabled
 * 09-08-25     3.01.18 viskrt  Added VGEN_ENABLE switches
 * 09-08-26     3.01.19 viset   COMMON_SIPVERSIONCHECK_RELEASE_VERSION correction
 * 09-08-28     3.01.20 viskrt  Changed name of J1939 include files
 *                      visbwr  Added QCC_MPC5X00, QNX components
 * 09-09-07     3.01.21 visard  Fix Tmsx70 DCAN / HECCSCC defines
 * 09-09-18     3.01.22 visagh  Fixed an error
 * 09-09-30     3.01.23 visabc  Added support of C_COMP_IAR_AVR32_CANIF
 *                              added support of Il_Vector_Gm
 * 09-10-06     3.01.24 visagh  added C_COMP_RENESAS_SH4_RCAN and C_COMP_GHS_SH4_RCAN2
 * 09-10-13     3.01.25 visdbr  adapted SYSSERVICE_ISSM to SYSSERVICE_ISSM_VOLVO_AB
 * 09-10-14     3.01.26 visoh   Added XcpOnCan
 * 09-10-14     3.01.27 visntr  support C_COMP_GAIO_SH2_RCAN for Hll CAN-Driver
 * 09-10-30     3.01.28 visjy   support C_COMP_ARM_STM32_BXCAN for Hll CAN-Driver
 * 09-11-13     3.01.29 vishkh  support for C_COMP_GNU_TX49 CAN-Driver
 * 09-11-24     3.01.30 visjy   Add vstdlib check for STM32
 * 09-12-03     3.01.31 visagh  Add new V85X VStdLib version defines
 *                              removed LIB check HW dependency (VStdLib, Can, Lin)
 * 09-12-11     3.01.32 visbwr  Add C_COMP_GNU_IMX_FLEXCAN2
 * 09-12-14     3.01.33 vishkh  Add C_COMP_METROWERKS_MPC55XX_FLEXCAN2
 * 09-12-21     3.01.34 visjy   Add C_COMP_GHS_V85X_FCN
 * 10-01-11     3.01.35 visagh  corrected DRVCAN_BF5XXXHLL_VERSION
 * 10-01-25     3.01.36 visagh  avoid compiler warnings for DPM
 * 10-01-27     3.01.37 visjy   Add C_COMP_GHS_KEIL_SJA2020
 * 10-01-27     3.01.38 visjy   Add DRVLIN_MPC56xx for lin driver
 * 10-04-23     3.01.39 visntr  corrected DRVLIN_MPC5500SCICTRLASR_VERSION
 * 10-05-04     3.01.40 visdbr  CORRECTED DRVLIN_MPC5500SCICTRLASR_VERSION for DIAB
 * 10-05-26     3.01.41 visjy   support C_COMP_QCC_MB86R0X_CCAN
 * 10-06-07     3.01.42 vishgo  ESCAN00043187
 * 10-06-07     3.01.43 vishgo  deleted VGEN_ENABLE_VDEF macro for VDEF
 * 10-06-08     3.01.44 vishgo  fixed VGEN_ENABLE_IF_ASRIFFEE for Fee version check
 * 10-06-08     3.01.45 vishgo  added SchM_Cfg.h include
 * 10-06-09     3.01.46 vishgo  added C_COMP_IAR_SH2_RCAN
 * 10-06-09     3.01.47 vishkh  added C_COMP_GNU_MPC55XX
 * 10-06-14     3.01.48 visabc  added C_COMP_QCC_SH4_RCAN
 * 10-07-21     3.01.49 visabc  added C_COMP_IAR_78K0R
 * 10-07-26     3.01.50 visbch  corrected Lib-check for Gw PduR
 * 10-07-30     3.01.51 vishkh  added C_COMP_GNU_IMX_FLEXCAN2
 * 10-10-11     3.01.52 visagh  added C_COMP_RENESAS_V85X_FCN
 * 10-10-28     3.01.53 visstu  added C_COMP_KEIL_XC800
 * 10-12-16     3.01.54 visaar  added C_COMP_RENESAS_78K0R
 * 11-02-24     3.01.55 visagh  removed PAG specific Tp_Iso15765 errors
 * 11-03-28     3.01.56 vishgo  added AsrFrIf version check
 * 11-04-05     3.01.57 vishgo  ESCAN00049838 
 * 11-04-07     3.01.58 vadhda  added C_COMP_GNU_ST30_CCAN
 * 11-04-12     3.01.59 visagh  added C_COMP_RENESAS_V85X_AFCAN
 * 11-04-19     3.01.60 vidbr   support  ASR4 components
 * 11-04-21     3.01.61 vidbr   DCM not filtered correctly
 * 11-04-21     3.01.62 vidbr   NmDirOsek not filtered correctly
 * 11-04-26     3.01.63 viset   modified CCL filter rule to support AR4 components
 * 11-05-02     3.01.64 visabc  added C_COMP_ARM_TX03_TXCAN
 * 11-05-04     3.01.65 visstu  added C_COMP_IAR_V85X_FCN
 * 11-05-04     3.01.66 visjy   added C_COMP_GAIO_MPC55XX_FLEXCAN2 for Drv can HLL
 * 11-07-21     3.01.67 visagh  added C_COMP_TI_TMS320C64X_HECCSCC (HLL-CAN & VStdLib)
 *                      visjy   added C_COMP_GNU_SH2_RCAN  (HLL-CAN & VStdLib)
 * 11-08-11     3.01.68 visagh  support Mcs12x LIN driver with and without XGate
 *****************************************************************************/


#include "v_cfg.h"
#include "v_ver.h"
#include "v_def.h"
#if defined( VGEN_GENY )
 #include "v_inc.h"
#endif

/* ---------------------------------------------------------------------------
 * Can Driver
 * --------------------------------------------------------------------------*/
#if defined( VGEN_ENABLE_CAN_DRV )
#include "can_inc.h"
#endif

/* ---------------------------------------------------------------------------
 * CCL
 * --------------------------------------------------------------------------*/
#if defined( VGEN_ENABLE_CCL )
#include "ccl_inc.h"
#endif

/*----------------------------------------------------------------------------
  DIAG_candesc_basic_uds
  ---------------------------------------------------------------------------*/
#if defined( VGEN_ENABLE_DIAG_CANDESC_BASIC_UDS )
#include "desc.h"
#endif

/* ---------------------------------------------------------------------------
 * IL Vector
 * --------------------------------------------------------------------------*/
#if defined( VGEN_ENABLE_IL_VECTOR )
#include "il_inc.h"
#include "il_def.h"
#endif

/* ---------------------------------------------------------------------------
 * NMHigh
 * --------------------------------------------------------------------------*/
#if defined( VGEN_ENABLE_NMHIGH )
 #include "nmh.h" 
 #include "nmh_can.h" 
#endif



/* ---------------------------------------------------------------------------
 * TPMC
 * --------------------------------------------------------------------------*/
#if defined( VGEN_ENABLE_TP_ISO_MC )
#include "tpmc.h"
#endif

/* ---------------------------------------------------------------------------
 * Description: VSTDLIB.H includes the Vector Standard Library header.
 *--------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_VSTDLIB )
  #include "vstdlib.h"
#endif


#include "sip_vers.h"



/******************************************************************************
| version check
|*****************************************************************************/
/* Used to check source against header. This is NOT the SIP version! */
#if ( SIP_VERS_VERSION != _COMMON_SIPVERSIONCHECK_VERSION )
  #error "SipCheck: Different main/sub version in header and source!"
#endif
#if ( SIP_VERS_RELEASE_VERSION != _COMMON_SIPVERSIONCHECK_RELEASE_VERSION )
  #error "SipCheck: Different release versions header and source!"
#endif


/******************************************************************************
| check components (presence, versions, functionalities)
|*****************************************************************************/

/*----------------------------------------------------------------------------
  Can Driver
  ---------------------------------------------------------------------------*/
#if defined( VGEN_ENABLE_CAN_DRV )
#if defined( C_COMP_TI_TMS470 )
 #if defined ( CAN_DRIVER_VERSION )
  #if(( CAN_DRIVER_VERSION == _DRVCAN_HW_VERSION) && ( CAN_BUGFIX_VERSION == _DRVCAN_HW_RELEASE_VERSION))
   #define CAN_DRIVER_VERSION_CORRECT
  #endif
 #endif
#endif
#if defined( C_COMP_TI_TMS470 )  
 #if defined DRVCAN_TMS470HECCSCCHLL_VERSION
  #if(( DRVCAN_TMS470HECCSCCHLL_VERSION == _DRVCAN_HW_VERSION ) && ( DRVCAN_TMS470HECCSCCHLL_RELEASE_VERSION == _DRVCAN_HW_RELEASE_VERSION ))
   #define CAN_DRIVER_VERSION_CORRECT
  #endif
 #endif
#endif
#if defined( C_COMP_TI_TMS470_DCAN ) 
 #if defined DRVCAN_TMS470DCANHLL_VERSION
  #if(( DRVCAN_TMS470DCANHLL_VERSION == _DRVCAN_HW_VERSION ) && ( DRVCAN_TMS470DCANHLL_RELEASE_VERSION == _DRVCAN_HW_RELEASE_VERSION ))
   #define CAN_DRIVER_VERSION_CORRECT
  #endif
 #endif
#endif
#if !defined( CAN_DRIVER_VERSION_CORRECT )
  #error "Can_Drv: Source and Header file are inconsistent for this SIP!"
#endif
#endif

/*----------------------------------------------------------------------------
  Ccl
  ---------------------------------------------------------------------------*/
#if defined( VGEN_ENABLE_CCL )
 #if( CCL__CORE_VERSION != _CCL__CORE_VERSION )
  #error "Ccl: Wrong main/sub version detected for this SIP delivery!"
 #endif
 #if( CCL__CORE_RELEASE_VERSION != _CCL__CORE_RELEASE_VERSION )
  #error "Ccl: Wrong release version detected for this SIP delivery!"
 #endif

 #if (CCL_PAG_VERSION != _CCL_OEM_VERSION)
  #error "CCL_Oem: Source and Header file are inconsistent for this SIP!"
 #endif
 #if (CCL_PAG_RELEASE_VERSION != _CCL_OEM_RELEASE_VERSION)
  #error "CCL_Oem: Source and Header file are inconsistent for this SIP!"
 #endif
#endif

/*----------------------------------------------------------------------------
  DIAG_candesc_basic_uds
  ---------------------------------------------------------------------------*/
#if defined( VGEN_ENABLE_DIAG_CANDESC_BASIC_UDS )
 #if( DESC_VERSION != _DIAG_CANDESC__COREBASE_VERSION )
  #error "Diag_CanDesc_Basic: Wrong main/sub version detected for this SIP delivery!"
 #endif
 #if( DESC_RELEASE_VERSION != _DIAG_CANDESC__COREBASE_RELEASE_VERSION)
  #error "Diag_CanDesc_Basic: Wrong release version detected for this SIP delivery!"
 #endif
#endif

/*----------------------------------------------------------------------------
  Il_Vector
  ---------------------------------------------------------------------------*/ 
#if defined( VGEN_ENABLE_IL_VECTOR)
 #if( IL_VECTOR_VERSION != _IL_VECTOR_VERSION )
  #error "IL: Wrong main/sub version detected for this SIP delivery!"
 #endif
 #if( IL_VECTOR_RELEASE_VERSION != _IL_VECTOR_RELEASE_VERSION )
  #error "IL: Wrong release version detected for this SIP delivery!"
 #endif
#endif




/*----------------------------------------------------------------------------
  NMHIGH
  ---------------------------------------------------------------------------*/ 
#if defined( VGEN_ENABLE_NMHIGH )
 #if( NM_PWRTRAIN_VAG_VERSION  != _NM_PWRTRAIN_VAG_VERSION )
  #error "nmh: Wrong main/sub version detected for this SIP delivery!"
 #endif
 #if( NM_PWRTRAIN_VAG_RELEASE_VERSION != _NM_PWRTRAIN_VAG_RELEASE_VERSION )
  #error "nmh: Wrong release version detected for this SIP delivery!"
 #endif
 #if( NM_PWRTRAINWRAPPEREXT_VAG_VERSION  != _NM_PWRTRAINWRAPPEREXT_VAG_VERSION )
  #error "nmh_can: Wrong main/sub version detected for this SIP delivery!"
 #endif
 #if( NM_PWRTRAINWRAPPEREXT_VAG_RELEASE_VERSION != _NM_PWRTRAINWRAPPEREXT_VAG_RELEASE_VERSION )
  #error "nmh_can: Wrong release version detected for this SIP delivery!"
 #endif
#endif

/*----------------------------------------------------------------------------
  Tp_ISO_MC
  ---------------------------------------------------------------------------*/
#if defined( VGEN_ENABLE_TP_ISO_MC )
 #if( TP_ISO15765_VERSION != _TP_ISO15765_VERSION )
  #error "Tp_Iso15765: Wrong main/sub version detected for this SIP delivery!"
 #endif
 #if( TP_ISO15765_RELEASE_VERSION != _TP_ISO15765_RELEASE_VERSION )
  #error "Tp_Iso15765: Wrong release version detected for this SIP delivery!"
 #endif
#endif

/*----------------------------------------------------------------------------
  Common_VStdLib
  ---------------------------------------------------------------------------*/
#if defined( VGEN_ENABLE_VSTDLIB )
#if defined ( C_COMP_TI_TMS470 )
 #if( VSTDLIB_ARM7_VERSION != _VSTDLIB_HW_VERSION )
  #error "VStdLib: Wrong main/sub version detected for this SIP delivery!"
 #endif
 #if( VSTDLIB_ARM7_RELEASE_VERSION != _VSTDLIB_HW_RELEASE_VERSION )
  #error "VStdLib: Wrong release version detected for this SIP delivery!"
 #endif
#endif
#if defined ( C_COMP_TI_TMS470_DCAN )
 #if( VSTDLIB_ARM7_VERSION != _VSTDLIB_HW_VERSION )
  #error "VStdLib: Wrong main/sub version detected for this SIP delivery!"
 #endif
 #if( VSTDLIB_ARM7_RELEASE_VERSION != _VSTDLIB_HW_RELEASE_VERSION )
  #error "VStdLib: Wrong release version detected for this SIP delivery!"
 #endif
#endif
#endif

/*----------------------------------------------------------------------------
  V_DEF
  ---------------------------------------------------------------------------*/
#if ( COMMON_VDEF_VERSION != _COMMON_VDEF_VERSION   )
  #error "V_Def: Wrong version detected for this SIP delivery!"
#endif
#if ( COMMON_VDEF_RELEASE_VERSION != _COMMON_VDEF_RELEASE_VERSION )
  #error "V_Def: Wrong version detected for this SIP delivery!"
#endif

/*----------------------------------------------------------------------------
  PreConfiguration Files
  ---------------------------------------------------------------------------*/
#if defined( VGEN_OEM_PRECONFIG_PAG_SLP3_Generic )
  #if ( VGEN_OEM_PRECONFIG_VERSION != 0x0100 )
    #error "OEM-PreConfig: Wrong main/sub version detected for this SIP delivery! "
  #endif
  #if ( VGEN_OEM_PRECONFIG_RELEASE_VERSION != 0x00 )
    #error "OEM-PreConfig: Wrong release version detected for this SIP delivery! "
  #endif
#else
  #error "OEM-PreConfig: Expected define not generated. Please check your OEM preconfiguration file."
#endif

#if defined( VGEN_USER_PRECONFIG_PAG_SLP3_BodyBusECU )
  #if ( VGEN_USER_PRECONFIG_VERSION != 0x0100 )
    #error "User-PreConfig: Wrong main/sub version detected for this SIP delivery! "
  #endif
  #if ( VGEN_USER_PRECONFIG_RELEASE_VERSION != 0x00 )
    #error "User-PreConfig: Wrong release version detected for this SIP delivery! "
  #endif
#endif
#if defined( VGEN_USER_PRECONFIG_PAG_SLP3_HighSpeedCanWithoutWakeUp )
  #if ( VGEN_USER_PRECONFIG_VERSION != 0x0100 )
    #error "User-PreConfig: Wrong main/sub version detected for this SIP delivery! "
  #endif
  #if ( VGEN_USER_PRECONFIG_RELEASE_VERSION != 0x00 )
    #error "User-PreConfig: Wrong release version detected for this SIP delivery! "
  #endif
#endif
#if defined( VGEN_USER_PRECONFIG_PAG_SLP3_HighSpeedCanWithWakeUp )
  #if ( VGEN_USER_PRECONFIG_VERSION != 0x0100 )
    #error "User-PreConfig: Wrong main/sub version detected for this SIP delivery! "
  #endif
  #if ( VGEN_USER_PRECONFIG_RELEASE_VERSION != 0x00 )
    #error "User-PreConfig: Wrong release version detected for this SIP delivery! "
  #endif
#endif
#if defined( VGEN_GENY )
#endif



/******************************************************************************
| check the version between generated and static files
|*****************************************************************************/
#if(VGEN_DELIVERY_VERSION_BYTE_0 != (_VECTOR_SIP_VERSION & 0xff00)>>8) 
 #error "Generated and static files are not from the same delivery SIP main version is different"
#endif
#if(VGEN_DELIVERY_VERSION_BYTE_1 != (_VECTOR_SIP_VERSION & 0x00ff)) 
 #error "Generated and static files are not from the same delivery SIP sub version is different"
#endif
#if(VGEN_DELIVERY_VERSION_BYTE_2 != _VECTOR_SIP_RELEASE_VERSION) 
 #error "Generated and static files are not from the same delivery SIP bug version is different"
#endif

/******************************************************************************
| Store additional SIP information in ROM constants
|*****************************************************************************/
/* ROM CATEGORY 4 START*/
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kSipMainVersion   = (vuint8)(VGEN_DELIVERY_VERSION_BYTE_0);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kSipSubVersion    = (vuint8)(VGEN_DELIVERY_VERSION_BYTE_1);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kSipBugFixVersion = (vuint8)(VGEN_DELIVERY_VERSION_BYTE_2);
/* ROM CATEGORY 4 END*/
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
