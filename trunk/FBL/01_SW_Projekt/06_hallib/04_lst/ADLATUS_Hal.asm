;******************************************************************************
;* TMS470 C/C++ Codegen                                       PC Version 2.71 *
;* Date/Time created: Tue Jan 24 12:32:24 2012                                *
;******************************************************************************
	.state16

DWCU	.dwtag  DW_TAG_compile_unit
	.dwattr DWCU, DW_AT_name("ADLATUS_Hal.c")
	.dwattr DWCU, DW_AT_producer("TMS470 C/C++ Codegen PC Version 2.71 Copyright (c) 1996-2008 Texas Instruments Incorporated")
	.dwattr DWCU, DW_AT_stmt_list(0x00)
	.dwattr DWCU, DW_AT_TI_VERSION(0x01)

DW$1	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCtim_SystemTimerCheck_V"), DW_AT_symbol_name("$FUN_CCtim_SystemTimerCheck_V")
	.dwattr DW$1, DW_AT_declaration(0x01)
	.dwattr DW$1, DW_AT_external(0x01)
DW$2	.dwtag  DW_TAG_variable, DW_AT_name("RAMHAL"), DW_AT_symbol_name("_RAMHAL")
	.dwattr DW$2, DW_AT_type(*DWT$1052)
	.dwattr DW$2, DW_AT_declaration(0x01)
	.dwattr DW$2, DW_AT_external(0x01)
DW$3	.dwtag  DW_TAG_variable, DW_AT_name("ROMHAL"), DW_AT_symbol_name("_ROMHAL")
	.dwattr DW$3, DW_AT_type(*DWT$1052)
	.dwattr DW$3, DW_AT_declaration(0x01)
	.dwattr DW$3, DW_AT_external(0x01)
DW$4	.dwtag  DW_TAG_variable, DW_AT_name("e_SARCIM_ST"), DW_AT_symbol_name("_e_SARCIM_ST")
	.dwattr DW$4, DW_AT_type(*DWT$1074)
	.dwattr DW$4, DW_AT_declaration(0x01)
	.dwattr DW$4, DW_AT_external(0x01)
DW$5	.dwtag  DW_TAG_variable, DW_AT_name("e_SARSYS_ST"), DW_AT_symbol_name("_e_SARSYS_ST")
	.dwattr DW$5, DW_AT_type(*DWT$1078)
	.dwattr DW$5, DW_AT_declaration(0x01)
	.dwattr DW$5, DW_AT_external(0x01)
DW$6	.dwtag  DW_TAG_variable, DW_AT_name("e_SARRTI_ST"), DW_AT_symbol_name("_e_SARRTI_ST")
	.dwattr DW$6, DW_AT_type(*DWT$1095)
	.dwattr DW$6, DW_AT_declaration(0x01)
	.dwattr DW$6, DW_AT_external(0x01)
DW$7	.dwtag  DW_TAG_variable, DW_AT_name("c_CCconprj_ClockFrequency_UL"), DW_AT_symbol_name("_c_CCconprj_ClockFrequency_UL")
	.dwattr DW$7, DW_AT_type(*DWT$1052)
	.dwattr DW$7, DW_AT_declaration(0x01)
	.dwattr DW$7, DW_AT_external(0x01)
DW$8	.dwtag  DW_TAG_variable, DW_AT_name("c_CCconprj_DisableReset_UB"), DW_AT_symbol_name("_c_CCconprj_DisableReset_UB")
	.dwattr DW$8, DW_AT_type(*DWT$1026)
	.dwattr DW$8, DW_AT_declaration(0x01)
	.dwattr DW$8, DW_AT_external(0x01)

	.sect	".const"
	.align	2
_c_VerSMART_Hallib_V111_UW:
	.field  	273,16			; _c_VerSMART_Hallib_V111_UW @ 0

	.sect	".text"
	.global	_c_VerSMART_Hallib_V111_UW
DW$9	.dwtag  DW_TAG_variable, DW_AT_name("c_VerSMART_Hallib_V111_UW"), DW_AT_symbol_name("_c_VerSMART_Hallib_V111_UW")
	.dwattr DW$9, DW_AT_type(*DWT$1035)
	.dwattr DW$9, DW_AT_location[DW_OP_addr _c_VerSMART_Hallib_V111_UW]
	.dwattr DW$9, DW_AT_external(0x01)
	.global	_t_CChal_HalCtrl_ST
	.bss	_t_CChal_HalCtrl_ST,20,4
DW$10	.dwtag  DW_TAG_variable, DW_AT_name("t_CChal_HalCtrl_ST"), DW_AT_symbol_name("_t_CChal_HalCtrl_ST")
	.dwattr DW$10, DW_AT_type(*DWT$1098)
	.dwattr DW$10, DW_AT_location[DW_OP_addr _t_CChal_HalCtrl_ST]
	.dwattr DW$10, DW_AT_external(0x01)
;	C:\CCStudio_v3.3\tms470\cgtools_271\bin\opt470.exe -v1 -q -s -O2 -e r:/06_hallib/04_lst/ADLATUS_Hal.if r:/06_hallib/04_lst/ADLATUS_Hal.opt -w r:/06_hallib/04_lst 

	.sect	".text:v$0"
	.clink
	.global	_FUN_CChal_InitHAL_V

DW$11	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_InitHAL_V"), DW_AT_symbol_name("_FUN_CChal_InitHAL_V")
	.dwattr DW$11, DW_AT_veneer(0x01)
	.dwattr DW$11, DW_AT_low_pc(_FUN_CChal_InitHAL_V)
	.dwattr DW$11, DW_AT_high_pc(0x00)
	.dwattr DW$11, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CChal_InitHAL_V                                     *
;*****************************************************************************
_FUN_CChal_InitHAL_V:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FUN_CChal_InitHAL_V+1, 32
	.state16
	.dwendtag DW$11



	.sect	".text"
	.clink
	.global	$FUN_CChal_InitHAL_V

DW$12	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_InitHAL_V"), DW_AT_symbol_name("$FUN_CChal_InitHAL_V")
	.dwattr DW$12, DW_AT_low_pc($FUN_CChal_InitHAL_V)
	.dwattr DW$12, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_Hal.c",149,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 148 | void FUN_CChal_InitHAL_V (const HALINTERFACE_ST* t_HalInterface_PST)   
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CChal_InitHAL_V                                        *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,SR                                      *
;*   Regs Used         : A1,A2,A3,A4,SR                                      *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CChal_InitHAL_V:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
;* A1    assigned to _t_HalInterface_PST
DW$13	.dwtag  DW_TAG_formal_parameter, DW_AT_name("t_HalInterface_PST"), DW_AT_symbol_name("_t_HalInterface_PST")
	.dwattr DW$13, DW_AT_type(*DWT$1060)
	.dwattr DW$13, DW_AT_location[DW_OP_reg0]
;* A2    assigned to C$1
DW$14	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$14, DW_AT_type(*DWT$1100)
	.dwattr DW$14, DW_AT_location[DW_OP_reg1]
;* A1    assigned to _t_HalInterface_PST
DW$15	.dwtag  DW_TAG_variable, DW_AT_name("t_HalInterface_PST"), DW_AT_symbol_name("_t_HalInterface_PST")
	.dwattr DW$15, DW_AT_type(*DWT$1064)
	.dwattr DW$15, DW_AT_location[DW_OP_reg0]
;* A2    assigned to _t_HALRAM_PUB
DW$16	.dwtag  DW_TAG_variable, DW_AT_name("t_HALRAM_PUB"), DW_AT_symbol_name("_t_HALRAM_PUB")
	.dwattr DW$16, DW_AT_type(*DWT$1027)
	.dwattr DW$16, DW_AT_location[DW_OP_reg1]
;* A1    assigned to _t_HALFlash_PUB
DW$17	.dwtag  DW_TAG_variable, DW_AT_name("t_HALFlash_PUB"), DW_AT_symbol_name("_t_HALFlash_PUB")
	.dwattr DW$17, DW_AT_type(*DWT$1027)
	.dwattr DW$17, DW_AT_location[DW_OP_reg0]
;* A3    assigned to L$1
DW$18	.dwtag  DW_TAG_variable, DW_AT_name("L$1"), DW_AT_symbol_name("L$1")
	.dwattr DW$18, DW_AT_type(*DWT$11)
	.dwattr DW$18, DW_AT_location[DW_OP_reg2]
;----------------------------------------------------------------------
; 150 | UWORD  t_Counter_UW;                                                   
; 151 | UWORD  t_HALSize_UW;                                                   
; 152 | UBYTE* t_HALRAM_PUB;                                                   
; 153 | UBYTE* t_HALFlash_PUB;                                                 
;----------------------------------------------------------------------
;** 167	-----------------------    C$1 = &t_CChal_HalCtrl_ST;
	.dwpsn	"ADLATUS_Hal.c",167,3
;----------------------------------------------------------------------
; 167 | t_CChal_HalCtrl_ST.IntClockFrequency_UL      = *t_HalInterface_PST->Int
;     | ClkFrequency_UL;                                                       
;----------------------------------------------------------------------
        LDR       A2, CON1              ; |167| 
;** 167	-----------------------    C$1->IntClockFrequency_UL = *t_HalInterface_PST->IntClkFrequency_UL;
        LDR       A3, [A1, #0]          ; |167| 
        LDR       A3, [A3, #0]          ; |167| 
        STR       A3, [A2, #0]          ; |167| 
;** 168	-----------------------    C$1->IntWatchdogTriggerTime_UW = *t_HalInterface_PST->IntWdtTimeout_UW;
	.dwpsn	"ADLATUS_Hal.c",168,3
;----------------------------------------------------------------------
; 168 | t_CChal_HalCtrl_ST.IntWatchdogTriggerTime_UW = *t_HalInterface_PST->Int
;     | WdtTimeout_UW;                                                         
;----------------------------------------------------------------------
        LDR       A1, [A1, #4]          ; |168| 
        LDRH      A1, [A1, #0]          ; |168| 
        STRH      A1, [A2, #4]          ; |168| 
;** 170	-----------------------    C$1->HWTimerValue_UW = 0;
	.dwpsn	"ADLATUS_Hal.c",170,3
;----------------------------------------------------------------------
; 170 | t_CChal_HalCtrl_ST.HWTimerValue_UW = 0u;                               
; 174 | t_HALFlash_PUB = (UBYTE*) ((ULONG) &ROMHAL);                   /*l_int
;     | !e923 */                                                               
; 176 | t_HALRAM_PUB   = (UBYTE*) ((ULONG) &RAMHAL);                   /*l_int
;     | !e923 */                                                               
; 182 | t_HALSize_UW   = 0x00A0u;                                              
;----------------------------------------------------------------------
        MOV       A1, #0                ; |170| 
        STRH      A1, [A2, #8]          ; |170| 
;**  	-----------------------    #pragma MUST_ITERATE(160, 160, 160)
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;** 187	-----------------------    L$1 = 80;
	.dwpsn	"ADLATUS_Hal.c",187,9
;----------------------------------------------------------------------
; 187 | for ( t_Counter_UW = 0x0000u;                                          
; 188 |       t_Counter_UW < t_HALSize_UW;                                     
; 189 |       t_Counter_UW ++ )                                                
;----------------------------------------------------------------------
        MOV       A3, #80               ; |187| 
;** 174	-----------------------    t_HALFlash_PUB = (unsigned char *)(unsigned)&ROMHAL;
	.dwpsn	"ADLATUS_Hal.c",174,3
        LDR       A1, CON2              ; |174| 
;** 176	-----------------------    t_HALRAM_PUB = (unsigned char *)(unsigned)&RAMHAL;
	.dwpsn	"ADLATUS_Hal.c",176,3
        LDR       A2, CON3              ; |176| 
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L1
;*
;*   Loop source line                : 187
;*   Loop closing brace source line  : 195
;*   Known Minimum Trip Count        : 160
;*   Known Maximum Trip Count        : 160
;*   Known Max Trip Count Factor     : 160
;* --------------------------------------------------------------------------*
L1:    
DWL$$FUN_CChal_InitHAL_V$2$B:
;**	-----------------------g2:
;** 191	-----------------------    *t_HALRAM_PUB = *t_HALFlash_PUB;
	.dwpsn	"ADLATUS_Hal.c",191,5
;----------------------------------------------------------------------
; 191 | *t_HALRAM_PUB = *t_HALFlash_PUB;                                       
;----------------------------------------------------------------------
        LDRB      A4, [A1, #0]          ; |191| 
        STRB      A4, [A2, #0]          ; |191| 
;** 191	-----------------------    *(++t_HALRAM_PUB) = *(++t_HALFlash_PUB);
        LDRB      A4, [A1, #1]          ; |191| 
        ADD       A1, #1                ; |191| 
        STRB      A4, [A2, #1]          ; |191| 
        ADD       A2, #1                ; |191| 
;** 192	-----------------------    ++t_HALRAM_PUB;
	.dwpsn	"ADLATUS_Hal.c",192,5
;----------------------------------------------------------------------
; 192 | t_HALRAM_PUB++;                                                        
;----------------------------------------------------------------------
        ADD       A2, #1                ; |192| 
;** 193	-----------------------    ++t_HALFlash_PUB;
	.dwpsn	"ADLATUS_Hal.c",193,5
;----------------------------------------------------------------------
; 193 | t_HALFlash_PUB++;                                                      
;----------------------------------------------------------------------
        ADD       A1, #1                ; |193| 
;** 195	-----------------------    if ( --L$1 ) goto g2;
	.dwpsn	"ADLATUS_Hal.c",195,3
;----------------------------------------------------------------------
; 197 | return ;                                                               
;----------------------------------------------------------------------
        SUB       A3, #1                ; |195| 
        BNE       L1                    ; |195| 
        ; |195| 
;**  	-----------------------    return;
DWL$$FUN_CChal_InitHAL_V$2$E:
;* --------------------------------------------------------------------------*
	.dwpsn	"ADLATUS_Hal.c",199,1
        BX        LR

DW$19	.dwtag  DW_TAG_loop
	.dwattr DW$19, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_Hal.asm:L1:1:1327404744")
	.dwattr DW$19, DW_AT_begin_file("ADLATUS_Hal.c")
	.dwattr DW$19, DW_AT_begin_line(0xbb)
	.dwattr DW$19, DW_AT_end_line(0xc3)
DW$20	.dwtag  DW_TAG_loop_range
	.dwattr DW$20, DW_AT_low_pc(DWL$$FUN_CChal_InitHAL_V$2$B)
	.dwattr DW$20, DW_AT_high_pc(DWL$$FUN_CChal_InitHAL_V$2$E)
	.dwendtag DW$19

	.dwendentry
	.dwendtag DW$12




	.sect	".text:v$1"
	.clink
	.global	_FUN_CChal_DisGlobalInterrupt_V

DW$21	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_DisGlobalInterrupt_V"), DW_AT_symbol_name("_FUN_CChal_DisGlobalInterrupt_V")
	.dwattr DW$21, DW_AT_veneer(0x01)
	.dwattr DW$21, DW_AT_low_pc(_FUN_CChal_DisGlobalInterrupt_V)
	.dwattr DW$21, DW_AT_high_pc(0x00)
	.dwattr DW$21, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CChal_DisGlobalInterrupt_V                          *
;*****************************************************************************
_FUN_CChal_DisGlobalInterrupt_V:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FUN_CChal_DisGlobalInterrupt_V+1, 32
	.state16
	.dwendtag DW$21



	.sect	".text"
	.clink
	.global	$FUN_CChal_DisGlobalInterrupt_V

DW$22	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_DisGlobalInterrupt_V"), DW_AT_symbol_name("$FUN_CChal_DisGlobalInterrupt_V")
	.dwattr DW$22, DW_AT_low_pc($FUN_CChal_DisGlobalInterrupt_V)
	.dwattr DW$22, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_Hal.c",218,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 217 | void FUN_CChal_DisGlobalInterrupt_V ( void)                            
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CChal_DisGlobalInterrupt_V                             *
;*                                                                           *
;*   Regs Modified     : A1,A2,SR                                            *
;*   Regs Used         : A1,A2,SR                                            *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CChal_DisGlobalInterrupt_V:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
;* A1    assigned to C$1
DW$23	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$23, DW_AT_type(*DWT$1075)
	.dwattr DW$23, DW_AT_location[DW_OP_reg0]
;* A2    assigned to C$2
DW$24	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$24, DW_AT_type(*DWT$10)
	.dwattr DW$24, DW_AT_location[DW_OP_reg1]
;** 221	-----------------------    C$1 = &e_SARCIM_ST;
	.dwpsn	"ADLATUS_Hal.c",221,3
;----------------------------------------------------------------------
; 221 | e_SARCIM_ST.Reqmask_UL = 0ul;                                          
;----------------------------------------------------------------------
        LDR       A1, CON4              ; |221| 
;** 221	-----------------------    C$1->Reqmask_UL = C$2 = 0u;
        MOV       A2, #0                ; |221| 
        STR       A2, [A1, #20]         ; |221| 
;** 224	-----------------------    C$1->Firqpr_UL = C$2;
	.dwpsn	"ADLATUS_Hal.c",224,3
;----------------------------------------------------------------------
; 224 | e_SARCIM_ST.Firqpr_UL  = 0ul;                                          
;----------------------------------------------------------------------
        STR       A2, [A1, #12]         ; |224| 
;** 226	-----------------------    return;
	.dwpsn	"ADLATUS_Hal.c",226,3
;----------------------------------------------------------------------
; 226 | return ;                                                               
;----------------------------------------------------------------------
	.dwpsn	"ADLATUS_Hal.c",228,1
        BX        LR
	.dwendentry
	.dwendtag DW$22




	.sect	".text:v$2"
	.clink
	.global	_FUN_CChal_InitHardwareTimer_V

DW$25	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_InitHardwareTimer_V"), DW_AT_symbol_name("_FUN_CChal_InitHardwareTimer_V")
	.dwattr DW$25, DW_AT_veneer(0x01)
	.dwattr DW$25, DW_AT_low_pc(_FUN_CChal_InitHardwareTimer_V)
	.dwattr DW$25, DW_AT_high_pc(0x00)
	.dwattr DW$25, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CChal_InitHardwareTimer_V                           *
;*****************************************************************************
_FUN_CChal_InitHardwareTimer_V:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $FUN_CChal_InitHardwareTimer_V
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$25



	.sect	".text"
	.clink
	.global	$FUN_CChal_InitHardwareTimer_V

DW$26	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_InitHardwareTimer_V"), DW_AT_symbol_name("$FUN_CChal_InitHardwareTimer_V")
	.dwattr DW$26, DW_AT_low_pc($FUN_CChal_InitHardwareTimer_V)
	.dwattr DW$26, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_Hal.c",248,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 247 | void FUN_CChal_InitHardwareTimer_V (void)                              
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CChal_InitHardwareTimer_V                              *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,SP,LR,SR                                *
;*   Regs Used         : A1,A2,A3,A4,SP,LR,SR                                *
;*   Local Frame Size  : 0 Args + 0 Auto + 4 Save = 4 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CChal_InitHardwareTimer_V:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
        PUSH      {LR}
	.dwcfa	0x0e, 4
	.dwcfa	0x80, 14, 1
	.dwcfa	0x0e, 4
;* A3    assigned to C$1
DW$27	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$27, DW_AT_type(*DWT$1100)
	.dwattr DW$27, DW_AT_location[DW_OP_reg2]
;* A1    assigned to C$2
DW$28	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$28, DW_AT_type(*DWT$1081)
	.dwattr DW$28, DW_AT_location[DW_OP_reg0]
;** 262	-----------------------    C$1 = &t_CChal_HalCtrl_ST;
	.dwpsn	"ADLATUS_Hal.c",262,3
;----------------------------------------------------------------------
; 262 | t_CChal_HalCtrl_ST.TimerTicksForOneMilliSecond_UL =                    
; 263 |                                     (c_CCconprj_ClockFrequency_UL/(2000
;     | ul));                                                                  
;----------------------------------------------------------------------
        LDR       A3, CON1              ; |262| 
;** 262	-----------------------    C$1->TimerTicksForOneMilliSecond_UL = c_CCconprj_ClockFrequency_UL/2000u;
        LDR       A1, CON5              ; |262| 
        LDR       A1, [A1, #0]          ; |262| 
        MOV       A2, #125
        LSL       A2, A2, #4
        BL        U$DIV                 ; |262| 
        ; |262| 
        STR       A2, [A3, #16]         ; |262| 
;** 276	-----------------------    C$2 = &e_SARRTI_ST;
	.dwpsn	"ADLATUS_Hal.c",276,3
;----------------------------------------------------------------------
; 276 | e_SARRTI_ST.DRTIPCTL_UN.DRTIPCTL_ST.PREDL_B11 = 0x0001u;               
;----------------------------------------------------------------------
        LDR       A1, CON7              ; |276| 
;** 276	-----------------------    ((volatile unsigned short *)C$2)[3] = ((volatile unsigned short *)C$2)[3]&0xf800u|1u;
        LDRH      A2, [A1, #6]          ; |276| 
        LSR       A2, A2, #11           ; |276| 
        LSL       A4, A2, #11           ; |276| 
        MOV       A2, #1                ; |276| 
        ORR       A2, A4                ; |276| 
        STRH      A2, [A1, #6]          ; |276| 
;** 279	-----------------------    *((volatile struct $$fake6 *)C$2+31) &= 0xfcu;
	.dwpsn	"ADLATUS_Hal.c",279,3
;----------------------------------------------------------------------
; 279 | e_SARRTI_ST.DRTICNTEN_UN.DRTICNTEN_ST.CNTEN_B2 = 0x00u;                
;----------------------------------------------------------------------
        LDRB      A4, [A1, #31]         ; |279| 
        MOV       A2, #252              ; |279| 
        AND       A2, A4                ; |279| 
        STRB      A2, [A1, #31]         ; |279| 
;** 282	-----------------------    C$1->OldTimerValue_UL = *(volatile unsigned *)C$2>>11;
	.dwpsn	"ADLATUS_Hal.c",282,3
;----------------------------------------------------------------------
; 282 | t_CChal_HalCtrl_ST.OldTimerValue_UL = e_SARRTI_ST.DRTICNTR_UN.DRTICNTR_
;     | ST.DRTICNTR_B21;                                                       
;----------------------------------------------------------------------
        LDR       A1, [A1, #0]          ; |282| 
        LSR       A1, A1, #11           ; |282| 
        STR       A1, [A3, #12]         ; |282| 
;** 284	-----------------------    return;
	.dwpsn	"ADLATUS_Hal.c",284,3
;----------------------------------------------------------------------
; 284 | return;                                                                
;----------------------------------------------------------------------
	.dwpsn	"ADLATUS_Hal.c",286,1
	.dwcfa	0x0e, 4
        POP       {PC}
	.dwendentry
	.dwendtag DW$26




	.sect	".text:v$3"
	.clink
	.global	_FUN_CChal_GetHWTimerValue_UW

DW$29	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_GetHWTimerValue_UW"), DW_AT_symbol_name("_FUN_CChal_GetHWTimerValue_UW")
	.dwattr DW$29, DW_AT_veneer(0x01)
	.dwattr DW$29, DW_AT_low_pc(_FUN_CChal_GetHWTimerValue_UW)
	.dwattr DW$29, DW_AT_high_pc(0x00)
	.dwattr DW$29, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CChal_GetHWTimerValue_UW                            *
;*****************************************************************************
_FUN_CChal_GetHWTimerValue_UW:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FUN_CChal_GetHWTimerValue_UW+1, 32
	.state16
	.dwendtag DW$29



	.sect	".text"
	.clink
	.global	$FUN_CChal_GetHWTimerValue_UW

DW$30	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_GetHWTimerValue_UW"), DW_AT_symbol_name("$FUN_CChal_GetHWTimerValue_UW")
	.dwattr DW$30, DW_AT_low_pc($FUN_CChal_GetHWTimerValue_UW)
	.dwattr DW$30, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_Hal.c",307,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 306 | UWORD FUN_CChal_GetHWTimerValue_UW (void )                             
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CChal_GetHWTimerValue_UW                               *
;*                                                                           *
;*   Regs Modified     : A1,A2,SR                                            *
;*   Regs Used         : A1,A2,SR                                            *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CChal_GetHWTimerValue_UW:
;* --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 308 | UWORD t_TimerValue_UW;                                                 
;----------------------------------------------------------------------
	.dwcfa	0x09, 26, 14
;* A2    assigned to C$1
DW$31	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$31, DW_AT_type(*DWT$1100)
	.dwattr DW$31, DW_AT_location[DW_OP_reg1]
;* A1    assigned to _t_TimerValue_UW
DW$32	.dwtag  DW_TAG_variable, DW_AT_name("t_TimerValue_UW"), DW_AT_symbol_name("_t_TimerValue_UW")
	.dwattr DW$32, DW_AT_type(*DWT$1021)
	.dwattr DW$32, DW_AT_location[DW_OP_reg0]
;* A1    assigned to U$3
DW$33	.dwtag  DW_TAG_variable, DW_AT_name("U$3"), DW_AT_symbol_name("U$3")
	.dwattr DW$33, DW_AT_type(*DWT$1021)
	.dwattr DW$33, DW_AT_location[DW_OP_reg0]
;* A2    assigned to K$2
DW$34	.dwtag  DW_TAG_variable, DW_AT_name("K$2"), DW_AT_symbol_name("K$2")
	.dwattr DW$34, DW_AT_type(*DWT$1099)
	.dwattr DW$34, DW_AT_location[DW_OP_reg1]
;** 311	-----------------------    C$1 = &t_CChal_HalCtrl_ST;
	.dwpsn	"ADLATUS_Hal.c",311,3
;----------------------------------------------------------------------
; 311 | if (t_CChal_HalCtrl_ST.HWTimerValue_UW == 0u)                          
;----------------------------------------------------------------------
        LDR       A2, CON1              ; |311| 
;** 311	-----------------------    if ( U$3 = C$1->HWTimerValue_UW ) goto g2;
        LDRH      A1, [A2, #8]          ; |311| 
        CMP       A1, #0                ; |311| 
        BNE       L2                    ; |311| 
        ; |311| 
;* --------------------------------------------------------------------------*
;** 311	-----------------------    K$2 = C$1;
;** 313	-----------------------    t_TimerValue_UW = K$2->OldTimerValue_UL;
	.dwpsn	"ADLATUS_Hal.c",313,5
;----------------------------------------------------------------------
; 313 | t_TimerValue_UW = (UWORD)t_CChal_HalCtrl_ST.OldTimerValue_UL;          
;----------------------------------------------------------------------
        LDRH      A1, [A2, #14]         ; |313| 
;** 314	-----------------------    goto g3;
	.dwpsn	"ADLATUS_Hal.c",314,3
;----------------------------------------------------------------------
; 315 | else                                                                   
;----------------------------------------------------------------------
        BX        LR
;* --------------------------------------------------------------------------*
L2:    
;**	-----------------------g2:
;** 317	-----------------------    t_TimerValue_UW = U$3;
	.dwpsn	"ADLATUS_Hal.c",317,5
;----------------------------------------------------------------------
; 317 | t_TimerValue_UW = t_CChal_HalCtrl_ST.HWTimerValue_UW;                  
;----------------------------------------------------------------------
;**	-----------------------g3:
;** 320	-----------------------    return t_TimerValue_UW;
	.dwpsn	"ADLATUS_Hal.c",320,3
;----------------------------------------------------------------------
; 320 | return (t_TimerValue_UW);                                              
;----------------------------------------------------------------------
	.dwpsn	"ADLATUS_Hal.c",322,1
        BX        LR
	.dwendentry
	.dwendtag DW$30




	.sect	".text:v$4"
	.clink
	.global	_FUN_CChal_StoreHwTimerValue_V

DW$35	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_StoreHwTimerValue_V"), DW_AT_symbol_name("_FUN_CChal_StoreHwTimerValue_V")
	.dwattr DW$35, DW_AT_veneer(0x01)
	.dwattr DW$35, DW_AT_low_pc(_FUN_CChal_StoreHwTimerValue_V)
	.dwattr DW$35, DW_AT_high_pc(0x00)
	.dwattr DW$35, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CChal_StoreHwTimerValue_V                           *
;*****************************************************************************
_FUN_CChal_StoreHwTimerValue_V:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FUN_CChal_StoreHwTimerValue_V+1, 32
	.state16
	.dwendtag DW$35



	.sect	".text"
	.clink
	.global	$FUN_CChal_StoreHwTimerValue_V

DW$36	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_StoreHwTimerValue_V"), DW_AT_symbol_name("$FUN_CChal_StoreHwTimerValue_V")
	.dwattr DW$36, DW_AT_low_pc($FUN_CChal_StoreHwTimerValue_V)
	.dwattr DW$36, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_Hal.c",343,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 342 | void FUN_CChal_StoreHwTimerValue_V (void )                             
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CChal_StoreHwTimerValue_V                              *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,SR                                         *
;*   Regs Used         : A1,A2,A3,SR                                         *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CChal_StoreHwTimerValue_V:
;* --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 344 | ULONG t_TimerValue_UL;                                                 
;----------------------------------------------------------------------
	.dwcfa	0x09, 26, 14
;* A1    assigned to _t_TimerValue_UL
DW$37	.dwtag  DW_TAG_variable, DW_AT_name("t_TimerValue_UL"), DW_AT_symbol_name("_t_TimerValue_UL")
	.dwattr DW$37, DW_AT_type(*DWT$1019)
	.dwattr DW$37, DW_AT_location[DW_OP_reg0]
;** 349	-----------------------    t_TimerValue_UL = *&e_SARRTI_ST>>11;
	.dwpsn	"ADLATUS_Hal.c",349,3
;----------------------------------------------------------------------
; 349 | t_TimerValue_UL = e_SARRTI_ST.DRTICNTR_UN.DRTICNTR_ST.DRTICNTR_B21;    
;----------------------------------------------------------------------
        LDR       A1, CON7              ; |349| 
        LDR       A1, [A1, #0]          ; |349| 
        LSR       A1, A1, #11           ; |349| 
;** 354	-----------------------    t_CChal_HalCtrl_ST.HWTimerValue_UW += ~t_TimerValue_UL;
	.dwpsn	"ADLATUS_Hal.c",354,3
;----------------------------------------------------------------------
; 354 | t_CChal_HalCtrl_ST.HWTimerValue_UW += (UWORD)~t_TimerValue_UL;         
;----------------------------------------------------------------------
        LDR       A3, CON1              ; |354| 
        LDRH      A2, [A3, #8]          ; |354| 
        MVN       A1, A1                ; |354| 
        ADD       A1, A1, A2            ; |354| 
        STRH      A1, [A3, #8]          ; |354| 
;** 356	-----------------------    return;
	.dwpsn	"ADLATUS_Hal.c",356,3
;----------------------------------------------------------------------
; 356 | return;                                                                
;----------------------------------------------------------------------
	.dwpsn	"ADLATUS_Hal.c",358,1
        BX        LR
	.dwendentry
	.dwendtag DW$36




	.sect	".text:v$5"
	.clink
	.global	_FUN_CChal_SWReset_V

DW$38	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_SWReset_V"), DW_AT_symbol_name("_FUN_CChal_SWReset_V")
	.dwattr DW$38, DW_AT_veneer(0x01)
	.dwattr DW$38, DW_AT_low_pc(_FUN_CChal_SWReset_V)
	.dwattr DW$38, DW_AT_high_pc(0x00)
	.dwattr DW$38, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CChal_SWReset_V                                     *
;*****************************************************************************
_FUN_CChal_SWReset_V:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FUN_CChal_SWReset_V+1, 32
	.state16
	.dwendtag DW$38



	.sect	".text"
	.clink
	.global	$FUN_CChal_SWReset_V

DW$39	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_SWReset_V"), DW_AT_symbol_name("$FUN_CChal_SWReset_V")
	.dwattr DW$39, DW_AT_low_pc($FUN_CChal_SWReset_V)
	.dwattr DW$39, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_Hal.c",379,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 378 | void FUN_CChal_SWReset_V (void )                                       
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CChal_SWReset_V                                        *
;*                                                                           *
;*   Regs Modified     : A1,A2,SR                                            *
;*   Regs Used         : A1,A2,SR                                            *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CChal_SWReset_V:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
;** 381	-----------------------    if ( c_CCconprj_DisableReset_UB == 90 ) goto g2;
	.dwpsn	"ADLATUS_Hal.c",381,3
;----------------------------------------------------------------------
; 381 | if (d_CCglo_ResetViaWdt == c_CCconprj_DisableReset_UB)         /*lint !
;     | e506 */                                                                
; 384 |   while(1)                                                             
; 386 |      ;                                                                 
; 389 | else                                                                   
;----------------------------------------------------------------------
        LDR       A1, CON9              ; |381| 
        LDRB      A1, [A1, #0]          ; |381| 
        CMP       A1, #90               ; |381| 
        BEQ       L3                    ; |381| 
        ; |381| 
;* --------------------------------------------------------------------------*
;** 392	-----------------------    e_SARSYS_ST.SysECR_UW = 49152;
	.dwpsn	"ADLATUS_Hal.c",392,5
;----------------------------------------------------------------------
; 392 | e_SARSYS_ST.SysECR_UW = 0xc000u;                                       
;----------------------------------------------------------------------
        MOV       A2, #3
        LSL       A2, A2, #14
        LDR       A1, CON10             ; |392| 
        STRH      A2, [A1, #0]          ; |392| 
;** 392	-----------------------    return;
        BX        LR
;**	-----------------------g2:
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L3
;*
;*   Loop source line                : 384
;*   Loop closing brace source line  : 387
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L3:    
DWL$$FUN_CChal_SWReset_V$3$B:
;**	-----------------------g4:
;** 387	-----------------------    goto g4;
	.dwpsn	"ADLATUS_Hal.c",387,5
        B         L3                    ; |387| 
        ; |387| 
DWL$$FUN_CChal_SWReset_V$3$E:
;* --------------------------------------------------------------------------*

DW$40	.dwtag  DW_TAG_loop
	.dwattr DW$40, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_Hal.asm:L3:1:1327404744")
	.dwattr DW$40, DW_AT_begin_file("ADLATUS_Hal.c")
	.dwattr DW$40, DW_AT_begin_line(0x180)
	.dwattr DW$40, DW_AT_end_line(0x183)
DW$41	.dwtag  DW_TAG_loop_range
	.dwattr DW$41, DW_AT_low_pc(DWL$$FUN_CChal_SWReset_V$3$B)
	.dwattr DW$41, DW_AT_high_pc(DWL$$FUN_CChal_SWReset_V$3$E)
	.dwendtag DW$40

	.dwendentry
	.dwendtag DW$39




	.sect	".text:v$6"
	.clink
	.global	_FUN_CChal_InitIntWatchdog_V

DW$42	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_InitIntWatchdog_V"), DW_AT_symbol_name("_FUN_CChal_InitIntWatchdog_V")
	.dwattr DW$42, DW_AT_veneer(0x01)
	.dwattr DW$42, DW_AT_low_pc(_FUN_CChal_InitIntWatchdog_V)
	.dwattr DW$42, DW_AT_high_pc(0x00)
	.dwattr DW$42, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CChal_InitIntWatchdog_V                             *
;*****************************************************************************
_FUN_CChal_InitIntWatchdog_V:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FUN_CChal_InitIntWatchdog_V+1, 32
	.state16
	.dwendtag DW$42



	.sect	".text"
	.clink
	.global	$FUN_CChal_InitIntWatchdog_V

DW$43	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_InitIntWatchdog_V"), DW_AT_symbol_name("$FUN_CChal_InitIntWatchdog_V")
	.dwattr DW$43, DW_AT_low_pc($FUN_CChal_InitIntWatchdog_V)
	.dwattr DW$43, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_Hal.c",413,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 412 | void FUN_CChal_InitIntWatchdog_V (void )                               
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CChal_InitIntWatchdog_V                                *
;*                                                                           *
;*   Regs Modified     : A1,A2,SR                                            *
;*   Regs Used         : A1,A2,SR                                            *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CChal_InitIntWatchdog_V:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
;* A1    assigned to C$1
DW$44	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$44, DW_AT_type(*DWT$1096)
	.dwattr DW$44, DW_AT_location[DW_OP_reg0]
;** 415	-----------------------    C$1 = &e_SARRTI_ST;
	.dwpsn	"ADLATUS_Hal.c",415,3
;----------------------------------------------------------------------
; 415 | e_SARRTI_ST.WKEY_UL = (UBYTE) 0xE5u;                                   
;----------------------------------------------------------------------
        LDR       A1, CON7              ; |415| 
;** 415	-----------------------    C$1->WKEY_UL = 229u;
        MOV       A2, #229              ; |415| 
        STR       A2, [A1, #12]         ; |415| 
;** 416	-----------------------    C$1->WKEY_UL = 163u;
	.dwpsn	"ADLATUS_Hal.c",416,3
;----------------------------------------------------------------------
; 416 | e_SARRTI_ST.WKEY_UL = (UBYTE) 0xA3u;                                   
;----------------------------------------------------------------------
        MOV       A2, #163              ; |416| 
        STR       A2, [A1, #12]         ; |416| 
;** 418	-----------------------    return;
	.dwpsn	"ADLATUS_Hal.c",418,3
;----------------------------------------------------------------------
; 418 | return;                                                                
;----------------------------------------------------------------------
	.dwpsn	"ADLATUS_Hal.c",420,1
        BX        LR
	.dwendentry
	.dwendtag DW$43




	.sect	".text:v$7"
	.clink
	.global	_FUN_CChal_DisableIntWatchdog_V

DW$45	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_DisableIntWatchdog_V"), DW_AT_symbol_name("_FUN_CChal_DisableIntWatchdog_V")
	.dwattr DW$45, DW_AT_veneer(0x01)
	.dwattr DW$45, DW_AT_low_pc(_FUN_CChal_DisableIntWatchdog_V)
	.dwattr DW$45, DW_AT_high_pc(0x00)
	.dwattr DW$45, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CChal_DisableIntWatchdog_V                          *
;*****************************************************************************
_FUN_CChal_DisableIntWatchdog_V:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FUN_CChal_DisableIntWatchdog_V+1, 32
	.state16
	.dwendtag DW$45



	.sect	".text"
	.clink
	.global	$FUN_CChal_DisableIntWatchdog_V

DW$46	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_DisableIntWatchdog_V"), DW_AT_symbol_name("$FUN_CChal_DisableIntWatchdog_V")
	.dwattr DW$46, DW_AT_low_pc($FUN_CChal_DisableIntWatchdog_V)
	.dwattr DW$46, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_Hal.c",439,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 438 | void FUN_CChal_DisableIntWatchdog_V (void )                            
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CChal_DisableIntWatchdog_V                             *
;*                                                                           *
;*   Regs Modified     :                                                     *
;*   Regs Used         :                                                     *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CChal_DisableIntWatchdog_V:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
;** 440	-----------------------    return;
	.dwpsn	"ADLATUS_Hal.c",440,3
;----------------------------------------------------------------------
; 440 | return;                                                                
;----------------------------------------------------------------------
	.dwpsn	"ADLATUS_Hal.c",441,1
        BX        LR
	.dwendentry
	.dwendtag DW$46




	.sect	".text:v$8"
	.clink
	.global	_FUN_CChal_EnableIntWatchdog_V

DW$47	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_EnableIntWatchdog_V"), DW_AT_symbol_name("_FUN_CChal_EnableIntWatchdog_V")
	.dwattr DW$47, DW_AT_veneer(0x01)
	.dwattr DW$47, DW_AT_low_pc(_FUN_CChal_EnableIntWatchdog_V)
	.dwattr DW$47, DW_AT_high_pc(0x00)
	.dwattr DW$47, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CChal_EnableIntWatchdog_V                           *
;*****************************************************************************
_FUN_CChal_EnableIntWatchdog_V:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FUN_CChal_EnableIntWatchdog_V+1, 32
	.state16
	.dwendtag DW$47



	.sect	".text"
	.clink
	.global	$FUN_CChal_EnableIntWatchdog_V

DW$48	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_EnableIntWatchdog_V"), DW_AT_symbol_name("$FUN_CChal_EnableIntWatchdog_V")
	.dwattr DW$48, DW_AT_low_pc($FUN_CChal_EnableIntWatchdog_V)
	.dwattr DW$48, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_Hal.c",460,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 459 | void FUN_CChal_EnableIntWatchdog_V (void )                             
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CChal_EnableIntWatchdog_V                              *
;*                                                                           *
;*   Regs Modified     : A1,A2,SR                                            *
;*   Regs Used         : A1,A2,SR                                            *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CChal_EnableIntWatchdog_V:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
;* A1    assigned to C$1
DW$49	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$49, DW_AT_type(*DWT$1096)
	.dwattr DW$49, DW_AT_location[DW_OP_reg0]
;** 462	-----------------------    C$1 = &e_SARRTI_ST;
	.dwpsn	"ADLATUS_Hal.c",462,3
;----------------------------------------------------------------------
; 462 | e_SARRTI_ST.WKEY_UL = (UBYTE) 0xE5u;                                   
;----------------------------------------------------------------------
        LDR       A1, CON7              ; |462| 
;** 462	-----------------------    C$1->WKEY_UL = 229u;
        MOV       A2, #229              ; |462| 
        STR       A2, [A1, #12]         ; |462| 
;** 463	-----------------------    C$1->WKEY_UL = 163u;
	.dwpsn	"ADLATUS_Hal.c",463,3
;----------------------------------------------------------------------
; 463 | e_SARRTI_ST.WKEY_UL = (UBYTE) 0xA3u;                                   
;----------------------------------------------------------------------
        MOV       A2, #163              ; |463| 
        STR       A2, [A1, #12]         ; |463| 
;** 465	-----------------------    return;
	.dwpsn	"ADLATUS_Hal.c",465,3
;----------------------------------------------------------------------
; 465 | return;                                                                
;----------------------------------------------------------------------
	.dwpsn	"ADLATUS_Hal.c",467,1
        BX        LR
	.dwendentry
	.dwendtag DW$48




	.sect	".text:v$9"
	.clink
	.global	_FUN_CChal_GetPerformanceCounter_UL

DW$50	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_GetPerformanceCounter_UL"), DW_AT_symbol_name("_FUN_CChal_GetPerformanceCounter_UL")
	.dwattr DW$50, DW_AT_veneer(0x01)
	.dwattr DW$50, DW_AT_low_pc(_FUN_CChal_GetPerformanceCounter_UL)
	.dwattr DW$50, DW_AT_high_pc(0x00)
	.dwattr DW$50, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CChal_GetPerformanceCounter_UL                      *
;*****************************************************************************
_FUN_CChal_GetPerformanceCounter_UL:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FUN_CChal_GetPerformanceCounter_UL+1, 32
	.state16
	.dwendtag DW$50



	.sect	".text"
	.clink
	.global	$FUN_CChal_GetPerformanceCounter_UL

DW$51	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_GetPerformanceCounter_UL"), DW_AT_symbol_name("$FUN_CChal_GetPerformanceCounter_UL")
	.dwattr DW$51, DW_AT_low_pc($FUN_CChal_GetPerformanceCounter_UL)
	.dwattr DW$51, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_Hal.c",490,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 489 | ULONG  FUN_CChal_GetPerformanceCounter_UL (void)                       
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CChal_GetPerformanceCounter_UL                         *
;*                                                                           *
;*   Regs Modified     : A1,SR                                               *
;*   Regs Used         : A1,SR                                               *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CChal_GetPerformanceCounter_UL:
;* --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 491 | ULONG t_return_UL;                                                     
;----------------------------------------------------------------------
	.dwcfa	0x09, 26, 14
;* A1    assigned to _t_return_UL
DW$52	.dwtag  DW_TAG_variable, DW_AT_name("t_return_UL"), DW_AT_symbol_name("_t_return_UL")
	.dwattr DW$52, DW_AT_type(*DWT$1019)
	.dwattr DW$52, DW_AT_location[DW_OP_reg0]
;** 494	-----------------------    t_return_UL = *&e_SARRTI_ST&0xfffff800u;
	.dwpsn	"ADLATUS_Hal.c",494,3
;----------------------------------------------------------------------
; 494 | t_return_UL = e_SARRTI_ST.DRTICNTR_UN.DRTICNTR_ST.DRTICNTR_B21 << 0x0Bu
;     | ;                                                                      
;----------------------------------------------------------------------
        LDR       A1, CON7              ; |494| 
        LDR       A1, [A1, #0]          ; |494| 
        ASR       A1, A1, #11           ; |496| 
        LSL       A1, A1, #11           ; |496| 
;** 496	-----------------------    return t_return_UL;
	.dwpsn	"ADLATUS_Hal.c",496,3
;----------------------------------------------------------------------
; 496 | return t_return_UL;                                                    
;----------------------------------------------------------------------
	.dwpsn	"ADLATUS_Hal.c",497,1
        BX        LR
	.dwendentry
	.dwendtag DW$51




	.sect	".text:v$10"
	.clink
	.global	_FUN_CChal_GetPerfCntTicks_UL

DW$53	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_GetPerfCntTicks_UL"), DW_AT_symbol_name("_FUN_CChal_GetPerfCntTicks_UL")
	.dwattr DW$53, DW_AT_veneer(0x01)
	.dwattr DW$53, DW_AT_low_pc(_FUN_CChal_GetPerfCntTicks_UL)
	.dwattr DW$53, DW_AT_high_pc(0x00)
	.dwattr DW$53, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CChal_GetPerfCntTicks_UL                            *
;*****************************************************************************
_FUN_CChal_GetPerfCntTicks_UL:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FUN_CChal_GetPerfCntTicks_UL+1, 32
	.state16
	.dwendtag DW$53



	.sect	".text"
	.clink
	.global	$FUN_CChal_GetPerfCntTicks_UL

DW$54	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_GetPerfCntTicks_UL"), DW_AT_symbol_name("$FUN_CChal_GetPerfCntTicks_UL")
	.dwattr DW$54, DW_AT_low_pc($FUN_CChal_GetPerfCntTicks_UL)
	.dwattr DW$54, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_Hal.c",517,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 516 | ULONG  FUN_CChal_GetPerfCntTicks_UL (void)                             
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CChal_GetPerfCntTicks_UL                               *
;*                                                                           *
;*   Regs Modified     : A1,SR                                               *
;*   Regs Used         : A1,SR                                               *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CChal_GetPerfCntTicks_UL:
;* --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 518 | ULONG t_return_UL;                                                     
; 522 | t_return_UL = (t_CChal_HalCtrl_ST.TimerTicksForOneMilliSecond_UL) << 11
;     | ;                                                                      
;----------------------------------------------------------------------
	.dwcfa	0x09, 26, 14
;** 525	-----------------------    return t_CChal_HalCtrl_ST.TimerTicksForOneMilliSecond_UL<<11;
	.dwpsn	"ADLATUS_Hal.c",525,3
;----------------------------------------------------------------------
; 525 | return t_return_UL;                                                    
;----------------------------------------------------------------------
        LDR       A1, CON1              ; |525| 
        LDR       A1, [A1, #16]         ; |525| 
        LSL       A1, A1, #11           ; |525| 
	.dwpsn	"ADLATUS_Hal.c",526,1
        BX        LR
	.dwendentry
	.dwendtag DW$54




	.sect	".text:v$11"
	.clink
	.global	_FUN_CChal_WaitTime_V

DW$55	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_WaitTime_V"), DW_AT_symbol_name("_FUN_CChal_WaitTime_V")
	.dwattr DW$55, DW_AT_veneer(0x01)
	.dwattr DW$55, DW_AT_low_pc(_FUN_CChal_WaitTime_V)
	.dwattr DW$55, DW_AT_high_pc(0x00)
	.dwattr DW$55, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CChal_WaitTime_V                                    *
;*****************************************************************************
_FUN_CChal_WaitTime_V:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $FUN_CChal_WaitTime_V
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$55



	.sect	".text"
	.clink
	.global	$FUN_CChal_WaitTime_V

DW$56	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_WaitTime_V"), DW_AT_symbol_name("$FUN_CChal_WaitTime_V")
	.dwattr DW$56, DW_AT_low_pc($FUN_CChal_WaitTime_V)
	.dwattr DW$56, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_Hal.c",546,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 545 | void FUN_CChal_WaitTime_V(UWORD t_Time_UW, BOOL t_Unit_B) /* FIXME: is
;     | the method of handling an underflow of the t_Time_UL variable the best 
;     | one? */                                                                
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CChal_WaitTime_V                                       *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V1,V2,V3,V4,V9,SP,LR,SR                 *
;*   Regs Used         : A1,A2,A3,A4,V1,V2,V3,V4,V9,SP,LR,SR                 *
;*   Local Frame Size  : 0 Args + 0 Auto + 20 Save = 20 byte                 *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CChal_WaitTime_V:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
        PUSH      {V1, V2, V3, V4, LR}
	.dwcfa	0x0e, 4
	.dwcfa	0x80, 14, 1
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 7, 2
	.dwcfa	0x0e, 12
	.dwcfa	0x80, 6, 3
	.dwcfa	0x0e, 16
	.dwcfa	0x80, 5, 4
	.dwcfa	0x0e, 20
	.dwcfa	0x80, 4, 5
	.dwcfa	0x0e, 20
;* A1    assigned to _t_Time_UW
DW$57	.dwtag  DW_TAG_formal_parameter, DW_AT_name("t_Time_UW"), DW_AT_symbol_name("_t_Time_UW")
	.dwattr DW$57, DW_AT_type(*DWT$1021)
	.dwattr DW$57, DW_AT_location[DW_OP_reg0]
;* A2    assigned to _t_Unit_B
DW$58	.dwtag  DW_TAG_formal_parameter, DW_AT_name("t_Unit_B"), DW_AT_symbol_name("_t_Unit_B")
	.dwattr DW$58, DW_AT_type(*DWT$1018)
	.dwattr DW$58, DW_AT_location[DW_OP_reg1]
;* V2    assigned to _t_Time_UL
DW$59	.dwtag  DW_TAG_variable, DW_AT_name("t_Time_UL"), DW_AT_symbol_name("_t_Time_UL")
	.dwattr DW$59, DW_AT_type(*DWT$1019)
	.dwattr DW$59, DW_AT_location[DW_OP_reg5]
;* V3    assigned to _t_TimerTicksPerDivision_UL
DW$60	.dwtag  DW_TAG_variable, DW_AT_name("t_TimerTicksPerDivision_UL"), DW_AT_symbol_name("_t_TimerTicksPerDivision_UL")
	.dwattr DW$60, DW_AT_type(*DWT$1019)
	.dwattr DW$60, DW_AT_location[DW_OP_reg6]
;* A1    assigned to _t_ActualTime_UL
DW$61	.dwtag  DW_TAG_variable, DW_AT_name("t_ActualTime_UL"), DW_AT_symbol_name("_t_ActualTime_UL")
	.dwattr DW$61, DW_AT_type(*DWT$1019)
	.dwattr DW$61, DW_AT_location[DW_OP_reg0]
;* V1    assigned to _t_StartTime_UL
DW$62	.dwtag  DW_TAG_variable, DW_AT_name("t_StartTime_UL"), DW_AT_symbol_name("_t_StartTime_UL")
	.dwattr DW$62, DW_AT_type(*DWT$1019)
	.dwattr DW$62, DW_AT_location[DW_OP_reg4]
;* A2    assigned to _t_Unit_B
DW$63	.dwtag  DW_TAG_variable, DW_AT_name("t_Unit_B"), DW_AT_symbol_name("_t_Unit_B")
	.dwattr DW$63, DW_AT_type(*DWT$1024)
	.dwattr DW$63, DW_AT_location[DW_OP_reg1]
;* V4    assigned to _t_Time_UW
DW$64	.dwtag  DW_TAG_variable, DW_AT_name("t_Time_UW"), DW_AT_symbol_name("_t_Time_UW")
	.dwattr DW$64, DW_AT_type(*DWT$1035)
	.dwattr DW$64, DW_AT_location[DW_OP_reg7]
;----------------------------------------------------------------------
; 547 | ULONG t_StartTime_UL;                                                  
; 548 | ULONG t_ActualTime_UL;                                                 
; 549 | ULONG t_TimerTicksPerDivision_UL;                                      
; 550 | ULONG t_TimeSetting_UL = (ULONG) t_Time_UW;                            
;----------------------------------------------------------------------
        MOV       V4, A1
;** 551	-----------------------    t_Time_UL = t_Time_UW-1u;
	.dwpsn	"ADLATUS_Hal.c",551,9
;----------------------------------------------------------------------
; 551 | ULONG t_Time_UL = (ULONG) t_Time_UW-1;                                 
;----------------------------------------------------------------------
        SUB       V2, V4, #1            ; |551| 
;** 556	-----------------------    if ( t_Unit_B ) goto g2;
	.dwpsn	"ADLATUS_Hal.c",556,3
;----------------------------------------------------------------------
; 556 | if (d_CChal_Unit100us_B == t_Unit_B)                                   
;----------------------------------------------------------------------
        CMP       A2, #0                ; |556| 
        BNE       L4                    ; |556| 
        ; |556| 
;* --------------------------------------------------------------------------*
;** 561	-----------------------    t_TimerTicksPerDivision_UL = FUN_CChal_GetPerfCntTicks_UL();
	.dwpsn	"ADLATUS_Hal.c",561,5
;----------------------------------------------------------------------
; 561 | t_TimerTicksPerDivision_UL = FUN_CChal_GetPerfCntTicks_UL();           
;----------------------------------------------------------------------
        BL        $FUN_CChal_GetPerfCntTicks_UL ; |561| 
        ; |561| 
;** 562	-----------------------    t_TimerTicksPerDivision_UL /= 10u;
	.dwpsn	"ADLATUS_Hal.c",562,5
;----------------------------------------------------------------------
; 562 | t_TimerTicksPerDivision_UL = t_TimerTicksPerDivision_UL / 10ul;        
;----------------------------------------------------------------------
        MOV       A2, #10               ; |562| 
        BL        U$DIV                 ; |562| 
        ; |562| 
        MOV       V3, A2
;** 564	-----------------------    goto g3;
	.dwpsn	"ADLATUS_Hal.c",564,3
;----------------------------------------------------------------------
; 568 | else                                                                   
;----------------------------------------------------------------------
        B         L5                    ; |564| 
        ; |564| 
;* --------------------------------------------------------------------------*
L4:    
;**	-----------------------g2:
;** 573	-----------------------    t_TimerTicksPerDivision_UL = FUN_CChal_GetPerfCntTicks_UL();
	.dwpsn	"ADLATUS_Hal.c",573,5
;----------------------------------------------------------------------
; 573 | t_TimerTicksPerDivision_UL = FUN_CChal_GetPerfCntTicks_UL();           
;----------------------------------------------------------------------
        BL        $FUN_CChal_GetPerfCntTicks_UL ; |573| 
        ; |573| 
        MOV       V3, A1
;* --------------------------------------------------------------------------*
L5:    
;**	-----------------------g3:
;** 580	-----------------------    t_StartTime_UL = FUN_CChal_GetPerformanceCounter_UL();
	.dwpsn	"ADLATUS_Hal.c",580,3
;----------------------------------------------------------------------
; 580 | t_StartTime_UL = FUN_CChal_GetPerformanceCounter_UL();                 
;----------------------------------------------------------------------
        BL        $FUN_CChal_GetPerformanceCounter_UL ; |580| 
        ; |580| 
        MOV       V1, A1
;**  	-----------------------    #pragma LOOP_FLAGS(5120u)
;** 585	-----------------------    goto g8;
	.dwpsn	"ADLATUS_Hal.c",585,3
;----------------------------------------------------------------------
; 585 | while(t_Time_UL <= t_TimeSetting_UL)                                   
;----------------------------------------------------------------------
        B         L9                    ; |585| 
        ; |585| 
;* --------------------------------------------------------------------------*
L6:    
DWL$$FUN_CChal_WaitTime_V$5$B:
;**	-----------------------g4:
;** 590	-----------------------    t_ActualTime_UL = FUN_CChal_GetPerformanceCounter_UL();
	.dwpsn	"ADLATUS_Hal.c",590,5
;----------------------------------------------------------------------
; 590 | t_ActualTime_UL = FUN_CChal_GetPerformanceCounter_UL();                
;----------------------------------------------------------------------
        BL        $FUN_CChal_GetPerformanceCounter_UL ; |590| 
        ; |590| 
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;** 595	-----------------------    goto g6;
	.dwpsn	"ADLATUS_Hal.c",595,5
;----------------------------------------------------------------------
; 595 | while ( (t_ActualTime_UL - t_StartTime_UL) > t_TimerTicksPerDivision_UL
;     | )                                                                      
;----------------------------------------------------------------------
        B         L8                    ; |595| 
        ; |595| 
DWL$$FUN_CChal_WaitTime_V$5$E:
;* --------------------------------------------------------------------------*
L7:    
DWL$$FUN_CChal_WaitTime_V$6$B:
;**	-----------------------g5:
;** 600	-----------------------    t_StartTime_UL += t_TimerTicksPerDivision_UL;
	.dwpsn	"ADLATUS_Hal.c",600,7
;----------------------------------------------------------------------
; 600 | t_StartTime_UL += t_TimerTicksPerDivision_UL;                          
;----------------------------------------------------------------------
        ADD       V1, V3, V1            ; |600| 
;** 605	-----------------------    --t_Time_UL;
	.dwpsn	"ADLATUS_Hal.c",605,7
;----------------------------------------------------------------------
; 605 | t_Time_UL--;                                                           
;----------------------------------------------------------------------
        SUB       V2, #1                ; |605| 
DWL$$FUN_CChal_WaitTime_V$6$E:
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L8
;* --------------------------------------------------------------------------*
L8:    
DWL$$FUN_CChal_WaitTime_V$7$B:
;**	-----------------------g6:
;** 605	-----------------------    if ( t_ActualTime_UL-t_StartTime_UL > t_TimerTicksPerDivision_UL ) goto g5;
        SUB       A2, A1, V1            ; |605| 
        CMP       A2, V3                ; |605| 
        BHI       L7                    ; |605| 
        ; |605| 
DWL$$FUN_CChal_WaitTime_V$7$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CChal_WaitTime_V$8$B:
;** 612	-----------------------    FUN_CCtim_SystemTimerCheck_V();
	.dwpsn	"ADLATUS_Hal.c",612,5
;----------------------------------------------------------------------
; 612 | FUN_CCtim_SystemTimerCheck_V();                                        
;----------------------------------------------------------------------
        BL        $FUN_CCtim_SystemTimerCheck_V ; |612| 
        ; |612| 
DWL$$FUN_CChal_WaitTime_V$8$E:
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L9
;* --------------------------------------------------------------------------*
L9:    
DWL$$FUN_CChal_WaitTime_V$9$B:
;**	-----------------------g8:
;** 614	-----------------------    if ( t_Time_UL <= t_Time_UW ) goto g4;
	.dwpsn	"ADLATUS_Hal.c",614,3
;----------------------------------------------------------------------
; 619 | return;                                                                
;----------------------------------------------------------------------
        CMP       V2, V4                ; |614| 
        BLS       L6                    ; |614| 
        ; |614| 
;**  	-----------------------    return;
DWL$$FUN_CChal_WaitTime_V$9$E:
;* --------------------------------------------------------------------------*
	.dwpsn	"ADLATUS_Hal.c",621,1
	.dwcfa	0x0e, 20
        POP       {V1, V2, V3, V4, PC}

DW$65	.dwtag  DW_TAG_loop
	.dwattr DW$65, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_Hal.asm:L9:1:1327404744")
	.dwattr DW$65, DW_AT_begin_file("ADLATUS_Hal.c")
	.dwattr DW$65, DW_AT_begin_line(0x249)
	.dwattr DW$65, DW_AT_end_line(0x266)
DW$66	.dwtag  DW_TAG_loop_range
	.dwattr DW$66, DW_AT_low_pc(DWL$$FUN_CChal_WaitTime_V$9$B)
	.dwattr DW$66, DW_AT_high_pc(DWL$$FUN_CChal_WaitTime_V$9$E)
DW$67	.dwtag  DW_TAG_loop_range
	.dwattr DW$67, DW_AT_low_pc(DWL$$FUN_CChal_WaitTime_V$5$B)
	.dwattr DW$67, DW_AT_high_pc(DWL$$FUN_CChal_WaitTime_V$5$E)
DW$68	.dwtag  DW_TAG_loop_range
	.dwattr DW$68, DW_AT_low_pc(DWL$$FUN_CChal_WaitTime_V$8$B)
	.dwattr DW$68, DW_AT_high_pc(DWL$$FUN_CChal_WaitTime_V$8$E)

DW$69	.dwtag  DW_TAG_loop
	.dwattr DW$69, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_Hal.asm:L8:2:1327404744")
	.dwattr DW$69, DW_AT_begin_file("ADLATUS_Hal.c")
	.dwattr DW$69, DW_AT_begin_line(0x253)
	.dwattr DW$69, DW_AT_end_line(0x25d)
DW$70	.dwtag  DW_TAG_loop_range
	.dwattr DW$70, DW_AT_low_pc(DWL$$FUN_CChal_WaitTime_V$7$B)
	.dwattr DW$70, DW_AT_high_pc(DWL$$FUN_CChal_WaitTime_V$7$E)
DW$71	.dwtag  DW_TAG_loop_range
	.dwattr DW$71, DW_AT_low_pc(DWL$$FUN_CChal_WaitTime_V$6$B)
	.dwattr DW$71, DW_AT_high_pc(DWL$$FUN_CChal_WaitTime_V$6$E)
	.dwendtag DW$69

	.dwendtag DW$65

	.dwendentry
	.dwendtag DW$56




	.sect	".text:v$12"
	.clink
	.global	_FUN_CChal_TimeoutStart_V

DW$72	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_TimeoutStart_V"), DW_AT_symbol_name("_FUN_CChal_TimeoutStart_V")
	.dwattr DW$72, DW_AT_veneer(0x01)
	.dwattr DW$72, DW_AT_low_pc(_FUN_CChal_TimeoutStart_V)
	.dwattr DW$72, DW_AT_high_pc(0x00)
	.dwattr DW$72, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CChal_TimeoutStart_V                                *
;*****************************************************************************
_FUN_CChal_TimeoutStart_V:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $FUN_CChal_TimeoutStart_V
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$72



	.sect	".text"
	.clink
	.global	$FUN_CChal_TimeoutStart_V

DW$73	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_TimeoutStart_V"), DW_AT_symbol_name("$FUN_CChal_TimeoutStart_V")
	.dwattr DW$73, DW_AT_low_pc($FUN_CChal_TimeoutStart_V)
	.dwattr DW$73, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_Hal.c",640,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 639 | void FUN_CChal_TimeoutStart_V(ULONG* t_StartTime_PUL)                  
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CChal_TimeoutStart_V                                   *
;*                                                                           *
;*   Regs Modified     : A1,A2,SP,LR,SR                                      *
;*   Regs Used         : A1,A2,SP,LR,SR                                      *
;*   Local Frame Size  : 0 Args + 0 Auto + 4 Save = 4 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CChal_TimeoutStart_V:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
        PUSH      {LR}
	.dwcfa	0x0e, 4
	.dwcfa	0x80, 14, 1
	.dwcfa	0x0e, 4
;* A1    assigned to _t_StartTime_PUL
DW$74	.dwtag  DW_TAG_formal_parameter, DW_AT_name("t_StartTime_PUL"), DW_AT_symbol_name("_t_StartTime_PUL")
	.dwattr DW$74, DW_AT_type(*DWT$1020)
	.dwattr DW$74, DW_AT_location[DW_OP_reg0]
;* A2    assigned to _t_StartTime_PUL
DW$75	.dwtag  DW_TAG_variable, DW_AT_name("t_StartTime_PUL"), DW_AT_symbol_name("_t_StartTime_PUL")
	.dwattr DW$75, DW_AT_type(*DWT$1050)
	.dwattr DW$75, DW_AT_location[DW_OP_reg1]
        MOV       A2, A1
;** 644	-----------------------    *t_StartTime_PUL = FUN_CChal_GetPerformanceCounter_UL();
	.dwpsn	"ADLATUS_Hal.c",644,3
;----------------------------------------------------------------------
; 644 | (*t_StartTime_PUL) = FUN_CChal_GetPerformanceCounter_UL();             
;----------------------------------------------------------------------
        BL        $FUN_CChal_GetPerformanceCounter_UL ; |644| 
        ; |644| 
        STR       A1, [A2, #0]          ; |644| 
;** 649	-----------------------    return;
	.dwpsn	"ADLATUS_Hal.c",649,3
;----------------------------------------------------------------------
; 649 | return;                                                                
;----------------------------------------------------------------------
	.dwpsn	"ADLATUS_Hal.c",651,1
	.dwcfa	0x0e, 4
        POP       {PC}
	.dwendentry
	.dwendtag DW$73




	.sect	".text:v$13"
	.clink
	.global	_FUN_CChal_TimeoutOccured_B

DW$76	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_TimeoutOccured_B"), DW_AT_symbol_name("_FUN_CChal_TimeoutOccured_B")
	.dwattr DW$76, DW_AT_veneer(0x01)
	.dwattr DW$76, DW_AT_low_pc(_FUN_CChal_TimeoutOccured_B)
	.dwattr DW$76, DW_AT_high_pc(0x00)
	.dwattr DW$76, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CChal_TimeoutOccured_B                              *
;*****************************************************************************
_FUN_CChal_TimeoutOccured_B:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $FUN_CChal_TimeoutOccured_B
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$76



	.sect	".text"
	.clink
	.global	$FUN_CChal_TimeoutOccured_B

DW$77	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_TimeoutOccured_B"), DW_AT_symbol_name("$FUN_CChal_TimeoutOccured_B")
	.dwattr DW$77, DW_AT_low_pc($FUN_CChal_TimeoutOccured_B)
	.dwattr DW$77, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_Hal.c",673,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 672 | BOOL FUN_CChal_TimeoutOccured_B(ULONG* t_StartTime_PUL, UWORD* t_Timeou
;     | tMs_PUW)                                                               
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CChal_TimeoutOccured_B                                 *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V1,V2,V3,V9,SP,LR,SR                    *
;*   Regs Used         : A1,A2,A3,A4,V1,V2,V3,V9,SP,LR,SR                    *
;*   Local Frame Size  : 0 Args + 0 Auto + 16 Save = 16 byte                 *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CChal_TimeoutOccured_B:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
        PUSH      {V1, V2, V3, LR}
	.dwcfa	0x0e, 4
	.dwcfa	0x80, 14, 1
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 6, 2
	.dwcfa	0x0e, 12
	.dwcfa	0x80, 5, 3
	.dwcfa	0x0e, 16
	.dwcfa	0x80, 4, 4
	.dwcfa	0x0e, 16
;* A1    assigned to _t_StartTime_PUL
DW$78	.dwtag  DW_TAG_formal_parameter, DW_AT_name("t_StartTime_PUL"), DW_AT_symbol_name("_t_StartTime_PUL")
	.dwattr DW$78, DW_AT_type(*DWT$1020)
	.dwattr DW$78, DW_AT_location[DW_OP_reg0]
;* A2    assigned to _t_TimeoutMs_PUW
DW$79	.dwtag  DW_TAG_formal_parameter, DW_AT_name("t_TimeoutMs_PUW"), DW_AT_symbol_name("_t_TimeoutMs_PUW")
	.dwattr DW$79, DW_AT_type(*DWT$1022)
	.dwattr DW$79, DW_AT_location[DW_OP_reg1]
;* A2    assigned to C$1
DW$80	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$80, DW_AT_type(*DWT$10)
	.dwattr DW$80, DW_AT_location[DW_OP_reg1]
;* A2    assigned to V$0
DW$81	.dwtag  DW_TAG_variable, DW_AT_name("V$0"), DW_AT_symbol_name("V$0")
	.dwattr DW$81, DW_AT_type(*DWT$10)
	.dwattr DW$81, DW_AT_location[DW_OP_reg1]
;* A4    assigned to V$1
DW$82	.dwtag  DW_TAG_variable, DW_AT_name("V$1"), DW_AT_symbol_name("V$1")
	.dwattr DW$82, DW_AT_type(*DWT$8)
	.dwattr DW$82, DW_AT_location[DW_OP_reg3]
;* A3    assigned to _t_TimerTicksPerMillisec_UL
DW$83	.dwtag  DW_TAG_variable, DW_AT_name("t_TimerTicksPerMillisec_UL"), DW_AT_symbol_name("_t_TimerTicksPerMillisec_UL")
	.dwattr DW$83, DW_AT_type(*DWT$1019)
	.dwattr DW$83, DW_AT_location[DW_OP_reg2]
;* A1    assigned to _t_ActualTime_UL
DW$84	.dwtag  DW_TAG_variable, DW_AT_name("t_ActualTime_UL"), DW_AT_symbol_name("_t_ActualTime_UL")
	.dwattr DW$84, DW_AT_type(*DWT$1019)
	.dwattr DW$84, DW_AT_location[DW_OP_reg0]
;* V1    assigned to _t_TimeoutMs_PUW
DW$85	.dwtag  DW_TAG_variable, DW_AT_name("t_TimeoutMs_PUW"), DW_AT_symbol_name("_t_TimeoutMs_PUW")
	.dwattr DW$85, DW_AT_type(*DWT$1033)
	.dwattr DW$85, DW_AT_location[DW_OP_reg4]
;* V2    assigned to _t_StartTime_PUL
DW$86	.dwtag  DW_TAG_variable, DW_AT_name("t_StartTime_PUL"), DW_AT_symbol_name("_t_StartTime_PUL")
	.dwattr DW$86, DW_AT_type(*DWT$1050)
	.dwattr DW$86, DW_AT_location[DW_OP_reg5]
;----------------------------------------------------------------------
; 674 | ULONG t_ActualTime_UL;                                                 
; 675 | ULONG t_TimerTicksPerMillisec_UL;                                      
; 676 | BOOL  t_ReturnValue_B;                                                 
;----------------------------------------------------------------------
        MOV       V1, A2
        MOV       V2, A1
;** 681	-----------------------    FUN_CCtim_SystemTimerCheck_V();
	.dwpsn	"ADLATUS_Hal.c",681,3
;----------------------------------------------------------------------
; 681 | FUN_CCtim_SystemTimerCheck_V();                                        
;----------------------------------------------------------------------
        BL        $FUN_CCtim_SystemTimerCheck_V ; |681| 
        ; |681| 
;** 686	-----------------------    t_TimerTicksPerMillisec_UL = FUN_CChal_GetPerfCntTicks_UL();
	.dwpsn	"ADLATUS_Hal.c",686,3
;----------------------------------------------------------------------
; 686 | t_TimerTicksPerMillisec_UL = FUN_CChal_GetPerfCntTicks_UL();           
;----------------------------------------------------------------------
        BL        $FUN_CChal_GetPerfCntTicks_UL ; |686| 
        ; |686| 
        MOV       A3, A1
;** 691	-----------------------    t_ActualTime_UL = FUN_CChal_GetPerformanceCounter_UL();
	.dwpsn	"ADLATUS_Hal.c",691,3
;----------------------------------------------------------------------
; 691 | t_ActualTime_UL = FUN_CChal_GetPerformanceCounter_UL();                
;----------------------------------------------------------------------
        BL        $FUN_CChal_GetPerformanceCounter_UL ; |691| 
        ; |691| 
;** 696	-----------------------    C$1 = *t_StartTime_PUL;
	.dwpsn	"ADLATUS_Hal.c",696,3
;----------------------------------------------------------------------
; 696 | while ( ((t_ActualTime_UL - (*t_StartTime_PUL)) > t_TimerTicksPerMillis
;     | ec_UL) && \                                                            
; 697 |         (0x00u < (*t_TimeoutMs_PUW)) )                                 
; 702 |   (*t_StartTime_PUL) += t_TimerTicksPerMillisec_UL;                    
; 703 |   (*t_TimeoutMs_PUW) -= 0x01u;                                         
;----------------------------------------------------------------------
        LDR       A2, [V2, #0]          ; |696| 
;** 696	-----------------------    if ( t_ActualTime_UL-C$1 <= t_TimerTicksPerMillisec_UL ) goto g6;
        SUB       A4, A1, A2            ; |696| 
        CMP       A4, A3                ; |696| 
        BLS       L11                   ; |696| 
        ; |696| 
;* --------------------------------------------------------------------------*
;**  	-----------------------    V$1 = *t_TimeoutMs_PUW;
        LDRH      A4, [V1, #0]
;**  	-----------------------    V$0 = C$1;
;**  	-----------------------    #pragma LOOP_FLAGS(4352u)
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L10
;*
;*   Loop source line                : 696
;*   Loop closing brace source line  : 705
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L10:    
DWL$$FUN_CChal_TimeoutOccured_B$3$B:
;**	-----------------------g3:
;** 705	-----------------------    if ( !V$1 ) goto g8;
	.dwpsn	"ADLATUS_Hal.c",705,3
        CMP       A4, #0                ; |705| 
        BEQ       L12                   ; |705| 
        ; |705| 
DWL$$FUN_CChal_TimeoutOccured_B$3$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CChal_TimeoutOccured_B$4$B:
;** 702	-----------------------    V$0 += t_TimerTicksPerMillisec_UL;
	.dwpsn	"ADLATUS_Hal.c",702,5
        ADD       A2, A3, A2            ; |702| 
;** 703	-----------------------    V$1 = (unsigned short)(V$1-1u);
	.dwpsn	"ADLATUS_Hal.c",703,5
        SUB       A4, A4, #1            ; |703| 
        LSL       A4, A4, #16           ; |714| 
        LSR       A4, A4, #16           ; |714| 
;** 703	-----------------------    if ( t_ActualTime_UL-V$0 > t_TimerTicksPerMillisec_UL ) goto g3;
        SUB       V3, A1, A2            ; |703| 
        CMP       V3, A3                ; |703| 
        BHI       L10                   ; |703| 
        ; |703| 
DWL$$FUN_CChal_TimeoutOccured_B$4$E:
;* --------------------------------------------------------------------------*
;**  	-----------------------    *t_StartTime_PUL = V$0;
        STR       A2, [V2, #0]
;**  	-----------------------    *t_TimeoutMs_PUW = V$1;
        STRH      A4, [V1, #0]
;* --------------------------------------------------------------------------*
L11:    
;**	-----------------------g6:
;** 710	-----------------------    if ( !*t_TimeoutMs_PUW ) goto g9;
	.dwpsn	"ADLATUS_Hal.c",710,3
;----------------------------------------------------------------------
; 710 | if(0x00u == (*t_TimeoutMs_PUW))                                        
; 712 |   t_ReturnValue_B = (BOOL)~FALSE;                                      
; 718 | else                                                                   
;----------------------------------------------------------------------
        LDRH      A1, [V1, #0]          ; |710| 
        CMP       A1, #0                ; |710| 
        BEQ       L13                   ; |710| 
        ; |710| 
;* --------------------------------------------------------------------------*
;** 720	-----------------------    return 0;
	.dwpsn	"ADLATUS_Hal.c",720,5
;----------------------------------------------------------------------
; 720 | t_ReturnValue_B = FALSE;                                               
; 727 | return  (t_ReturnValue_B);                                             
;----------------------------------------------------------------------
        MOV       A1, #0                ; |720| 
        POP       {V1, V2, V3, PC}
;* --------------------------------------------------------------------------*
L12:    
;**	-----------------------g8:
;**  	-----------------------    *t_StartTime_PUL = V$0;
        STR       A2, [V2, #0]
;**  	-----------------------    *t_TimeoutMs_PUW = V$1;
        STRH      A4, [V1, #0]
;* --------------------------------------------------------------------------*
L13:    
;**	-----------------------g9:
;** 714	-----------------------    return 255;
	.dwpsn	"ADLATUS_Hal.c",714,3
        MOV       A1, #255              ; |714| 
	.dwpsn	"ADLATUS_Hal.c",729,1
	.dwcfa	0x0e, 16
        POP       {V1, V2, V3, PC}

DW$87	.dwtag  DW_TAG_loop
	.dwattr DW$87, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_Hal.asm:L10:1:1327404744")
	.dwattr DW$87, DW_AT_begin_file("ADLATUS_Hal.c")
	.dwattr DW$87, DW_AT_begin_line(0x2b8)
	.dwattr DW$87, DW_AT_end_line(0x2c1)
DW$88	.dwtag  DW_TAG_loop_range
	.dwattr DW$88, DW_AT_low_pc(DWL$$FUN_CChal_TimeoutOccured_B$3$B)
	.dwattr DW$88, DW_AT_high_pc(DWL$$FUN_CChal_TimeoutOccured_B$3$E)
DW$89	.dwtag  DW_TAG_loop_range
	.dwattr DW$89, DW_AT_low_pc(DWL$$FUN_CChal_TimeoutOccured_B$4$B)
	.dwattr DW$89, DW_AT_high_pc(DWL$$FUN_CChal_TimeoutOccured_B$4$E)
	.dwendtag DW$87

	.dwendentry
	.dwendtag DW$77



;******************************************************************************
;* CONSTANT TABLE                                                             *
;******************************************************************************
	.sect	".text"
	.align	4
CON1:	.field  	_t_CChal_HalCtrl_ST,32
	.align	4
CON2:	.field  	_ROMHAL,32
	.align	4
CON3:	.field  	_RAMHAL,32
	.align	4
CON4:	.field  	_e_SARCIM_ST,32
	.align	4
CON5:	.field  	_c_CCconprj_ClockFrequency_UL,32
	.align	4
CON7:	.field  	_e_SARRTI_ST,32
	.align	4
CON9:	.field  	_c_CCconprj_DisableReset_UB,32
	.align	4
CON10:	.field  	_e_SARSYS_ST+18,32
;******************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                              *
;******************************************************************************
	.global	$FUN_CCtim_SystemTimerCheck_V
	.global	_RAMHAL
	.global	_ROMHAL
	.global	_e_SARCIM_ST
	.global	_e_SARSYS_ST
	.global	_e_SARRTI_ST
	.global	_c_CCconprj_ClockFrequency_UL
	.global	_c_CCconprj_DisableReset_UB
	.global	U$DIV

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************
DWT$1018	.dwtag  DW_TAG_typedef, DW_AT_name("BOOL"), DW_AT_type(*DWT$6)
	.dwattr DWT$1018, DW_AT_language(DW_LANG_C)

DWT$1023	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DWT$1018)
	.dwattr DWT$1023, DW_AT_language(DW_LANG_C)
DW$90	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1020)
DW$91	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1022)
	.dwendtag DWT$1023

DWT$1024	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1018)
DWT$1026	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1025)
DWT$1027	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1025)
	.dwattr DWT$1027, DW_AT_address_class(0x20)
DWT$8	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned short")
	.dwattr DWT$8, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$8, DW_AT_byte_size(0x02)
DWT$1021	.dwtag  DW_TAG_typedef, DW_AT_name("UWORD"), DW_AT_type(*DWT$8)
	.dwattr DWT$1021, DW_AT_language(DW_LANG_C)
DWT$1022	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1021)
	.dwattr DWT$1022, DW_AT_address_class(0x20)
DWT$1033	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1022)

DWT$1034	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DWT$1021)
	.dwattr DWT$1034, DW_AT_language(DW_LANG_C)
DWT$1035	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1021)
DWT$11	.dwtag  DW_TAG_base_type, DW_AT_name("int")
	.dwattr DWT$11, DW_AT_encoding(DW_ATE_signed)
	.dwattr DWT$11, DW_AT_byte_size(0x04)
DWT$10	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned int")
	.dwattr DWT$10, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$10, DW_AT_byte_size(0x04)
DWT$1019	.dwtag  DW_TAG_typedef, DW_AT_name("ULONG"), DW_AT_type(*DWT$12)
	.dwattr DWT$1019, DW_AT_language(DW_LANG_C)
DWT$1020	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1019)
	.dwattr DWT$1020, DW_AT_address_class(0x20)
DWT$1050	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1020)

DWT$1051	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DWT$1019)
	.dwattr DWT$1051, DW_AT_language(DW_LANG_C)
DWT$1052	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1019)

DWT$1053	.dwtag  DW_TAG_subroutine_type
	.dwattr DWT$1053, DW_AT_language(DW_LANG_C)

DWT$1061	.dwtag  DW_TAG_subroutine_type
	.dwattr DWT$1061, DW_AT_language(DW_LANG_C)
DW$92	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1060)
	.dwendtag DWT$1061


DWT$1062	.dwtag  DW_TAG_subroutine_type
	.dwattr DWT$1062, DW_AT_language(DW_LANG_C)
DW$93	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1021)
DW$94	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1018)
	.dwendtag DWT$1062


DWT$1063	.dwtag  DW_TAG_subroutine_type
	.dwattr DWT$1063, DW_AT_language(DW_LANG_C)
DW$95	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1020)
	.dwendtag DWT$1063

DWT$1060	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1059)
	.dwattr DWT$1060, DW_AT_address_class(0x20)
DWT$1064	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1060)
DWT$1074	.dwtag  DW_TAG_typedef, DW_AT_name("SARCIM_ST"), DW_AT_type(*DWT$1073)
	.dwattr DWT$1074, DW_AT_language(DW_LANG_C)
DWT$1075	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1073)
	.dwattr DWT$1075, DW_AT_address_class(0x20)
DWT$1078	.dwtag  DW_TAG_typedef, DW_AT_name("SARSYS_ST"), DW_AT_type(*DWT$1077)
	.dwattr DWT$1078, DW_AT_language(DW_LANG_C)
DWT$1081	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1080)
	.dwattr DWT$1081, DW_AT_address_class(0x20)
DWT$1095	.dwtag  DW_TAG_typedef, DW_AT_name("SARRTI_ST"), DW_AT_type(*DWT$1094)
	.dwattr DWT$1095, DW_AT_language(DW_LANG_C)
DWT$1096	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1094)
	.dwattr DWT$1096, DW_AT_address_class(0x20)
DWT$1098	.dwtag  DW_TAG_typedef, DW_AT_name("HALCONTROL_ST"), DW_AT_type(*DWT$1097)
	.dwattr DWT$1098, DW_AT_language(DW_LANG_C)
DWT$1099	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1098)
	.dwattr DWT$1099, DW_AT_address_class(0x20)
DWT$1100	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1097)
	.dwattr DWT$1100, DW_AT_address_class(0x20)
DWT$6	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned char")
	.dwattr DWT$6, DW_AT_encoding(DW_ATE_unsigned_char)
	.dwattr DWT$6, DW_AT_byte_size(0x01)
DWT$1025	.dwtag  DW_TAG_typedef, DW_AT_name("UBYTE"), DW_AT_type(*DWT$6)
	.dwattr DWT$1025, DW_AT_language(DW_LANG_C)
DWT$12	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned long")
	.dwattr DWT$12, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$12, DW_AT_byte_size(0x04)
DWT$1059	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1058)
DWT$1073	.dwtag  DW_TAG_volatile_type, DW_AT_type(*DWT$1072)
DWT$1077	.dwtag  DW_TAG_volatile_type, DW_AT_type(*DWT$1076)
DWT$1080	.dwtag  DW_TAG_volatile_type, DW_AT_type(*DWT$1079)
DWT$1094	.dwtag  DW_TAG_volatile_type, DW_AT_type(*DWT$1093)

DWT$1097	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1097, DW_AT_name("_HALCONTROL")
	.dwattr DWT$1097, DW_AT_byte_size(0x14)
DW$96	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1019)
	.dwattr DW$96, DW_AT_name("IntClockFrequency_UL"), DW_AT_symbol_name("_IntClockFrequency_UL")
	.dwattr DW$96, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$96, DW_AT_accessibility(DW_ACCESS_public)
DW$97	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1021)
	.dwattr DW$97, DW_AT_name("IntWatchdogTriggerTime_UW"), DW_AT_symbol_name("_IntWatchdogTriggerTime_UW")
	.dwattr DW$97, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$97, DW_AT_accessibility(DW_ACCESS_public)
DW$98	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1021)
	.dwattr DW$98, DW_AT_name("IntWtdTimerReloadValue_UW"), DW_AT_symbol_name("_IntWtdTimerReloadValue_UW")
	.dwattr DW$98, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr DW$98, DW_AT_accessibility(DW_ACCESS_public)
DW$99	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1021)
	.dwattr DW$99, DW_AT_name("HWTimerValue_UW"), DW_AT_symbol_name("_HWTimerValue_UW")
	.dwattr DW$99, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$99, DW_AT_accessibility(DW_ACCESS_public)
DW$100	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1019)
	.dwattr DW$100, DW_AT_name("OldTimerValue_UL"), DW_AT_symbol_name("_OldTimerValue_UL")
	.dwattr DW$100, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$100, DW_AT_accessibility(DW_ACCESS_public)
DW$101	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1019)
	.dwattr DW$101, DW_AT_name("TimerTicksForOneMilliSecond_UL"), DW_AT_symbol_name("_TimerTicksForOneMilliSecond_UL")
	.dwattr DW$101, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$101, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1097

DWT$1058	.dwtag  DW_TAG_typedef, DW_AT_name("HALINTERFACE_ST"), DW_AT_type(*DWT$1057)
	.dwattr DWT$1058, DW_AT_language(DW_LANG_C)

DWT$1072	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1072, DW_AT_byte_size(0x18)
DW$102	.dwtag  DW_TAG_member, DW_AT_type(*DWT$6)
	.dwattr DW$102, DW_AT_name("IrqIVec_UB"), DW_AT_symbol_name("_IrqIVec_UB")
	.dwattr DW$102, DW_AT_data_member_location[DW_OP_plus_uconst 0x3]
	.dwattr DW$102, DW_AT_accessibility(DW_ACCESS_public)
DW$103	.dwtag  DW_TAG_member, DW_AT_type(*DWT$6)
	.dwattr DW$103, DW_AT_name("FiqIVec_UB"), DW_AT_symbol_name("_FiqIVec_UB")
	.dwattr DW$103, DW_AT_data_member_location[DW_OP_plus_uconst 0x7]
	.dwattr DW$103, DW_AT_accessibility(DW_ACCESS_public)
DW$104	.dwtag  DW_TAG_member, DW_AT_type(*DWT$6)
	.dwattr DW$104, DW_AT_name("CimIVec_UB"), DW_AT_symbol_name("_CimIVec_UB")
	.dwattr DW$104, DW_AT_data_member_location[DW_OP_plus_uconst 0xb]
	.dwattr DW$104, DW_AT_accessibility(DW_ACCESS_public)
DW$105	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$105, DW_AT_name("Firqpr_UL"), DW_AT_symbol_name("_Firqpr_UL")
	.dwattr DW$105, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$105, DW_AT_accessibility(DW_ACCESS_public)
DW$106	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$106, DW_AT_name("Intreq_UL"), DW_AT_symbol_name("_Intreq_UL")
	.dwattr DW$106, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$106, DW_AT_accessibility(DW_ACCESS_public)
DW$107	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$107, DW_AT_name("Reqmask_UL"), DW_AT_symbol_name("_Reqmask_UL")
	.dwattr DW$107, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr DW$107, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1072


DWT$1076	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1076, DW_AT_byte_size(0x30)
DW$108	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$108, DW_AT_name("ClkCntl_UW"), DW_AT_symbol_name("_ClkCntl_UW")
	.dwattr DW$108, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$108, DW_AT_accessibility(DW_ACCESS_public)
DW$109	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$109, DW_AT_name("CramCR_UW"), DW_AT_symbol_name("_CramCR_UW")
	.dwattr DW$109, DW_AT_data_member_location[DW_OP_plus_uconst 0xa]
	.dwattr DW$109, DW_AT_accessibility(DW_ACCESS_public)
DW$110	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$110, DW_AT_name("GlbCtrl_UW"), DW_AT_symbol_name("_GlbCtrl_UW")
	.dwattr DW$110, DW_AT_data_member_location[DW_OP_plus_uconst 0xe]
	.dwattr DW$110, DW_AT_accessibility(DW_ACCESS_public)
DW$111	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$111, DW_AT_name("SysECR_UW"), DW_AT_symbol_name("_SysECR_UW")
	.dwattr DW$111, DW_AT_data_member_location[DW_OP_plus_uconst 0x12]
	.dwattr DW$111, DW_AT_accessibility(DW_ACCESS_public)
DW$112	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$112, DW_AT_name("SysESR_UW"), DW_AT_symbol_name("_SysESR_UW")
	.dwattr DW$112, DW_AT_data_member_location[DW_OP_plus_uconst 0x16]
	.dwattr DW$112, DW_AT_accessibility(DW_ACCESS_public)
DW$113	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$113, DW_AT_name("AbrtESR_UW"), DW_AT_symbol_name("_AbrtESR_UW")
	.dwattr DW$113, DW_AT_data_member_location[DW_OP_plus_uconst 0x1a]
	.dwattr DW$113, DW_AT_accessibility(DW_ACCESS_public)
DW$114	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$114, DW_AT_name("GlbStat_UW"), DW_AT_symbol_name("_GlbStat_UW")
	.dwattr DW$114, DW_AT_data_member_location[DW_OP_plus_uconst 0x1e]
	.dwattr DW$114, DW_AT_accessibility(DW_ACCESS_public)
DW$115	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$115, DW_AT_name("Dev_UW"), DW_AT_symbol_name("_Dev_UW")
	.dwattr DW$115, DW_AT_data_member_location[DW_OP_plus_uconst 0x22]
	.dwattr DW$115, DW_AT_accessibility(DW_ACCESS_public)
DW$116	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$116, DW_AT_name("Ssif_UW"), DW_AT_symbol_name("_Ssif_UW")
	.dwattr DW$116, DW_AT_data_member_location[DW_OP_plus_uconst 0x2a]
	.dwattr DW$116, DW_AT_accessibility(DW_ACCESS_public)
DW$117	.dwtag  DW_TAG_member, DW_AT_type(*DWT$8)
	.dwattr DW$117, DW_AT_name("Ssir_UW"), DW_AT_symbol_name("_Ssir_UW")
	.dwattr DW$117, DW_AT_data_member_location[DW_OP_plus_uconst 0x2e]
	.dwattr DW$117, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1076


DWT$1079	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1079, DW_AT_byte_size(0x04)
DW$118	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$118, DW_AT_name("RTIM_B3"), DW_AT_symbol_name("_RTIM_B3")
	.dwattr DW$118, DW_AT_bit_offset(0x12), DW_AT_bit_size(0x03)
	.dwattr DW$118, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$118, DW_AT_accessibility(DW_ACCESS_public)
DW$119	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$119, DW_AT_name("PREDL_B11"), DW_AT_symbol_name("_PREDL_B11")
	.dwattr DW$119, DW_AT_bit_offset(0x15), DW_AT_bit_size(0x0b)
	.dwattr DW$119, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$119, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1079


DWT$1093	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1093, DW_AT_name("rti")
	.dwattr DWT$1093, DW_AT_byte_size(0x20)
DW$120	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1086)
	.dwattr DW$120, DW_AT_name("DRTICNTR_UN"), DW_AT_symbol_name("_DRTICNTR_UN")
	.dwattr DW$120, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$120, DW_AT_accessibility(DW_ACCESS_public)
DW$121	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1087)
	.dwattr DW$121, DW_AT_name("DRTIPCTL_UN"), DW_AT_symbol_name("_DRTIPCTL_UN")
	.dwattr DW$121, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$121, DW_AT_accessibility(DW_ACCESS_public)
DW$122	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1089)
	.dwattr DW$122, DW_AT_name("DRTICNTL_UN"), DW_AT_symbol_name("_DRTICNTL_UN")
	.dwattr DW$122, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$122, DW_AT_accessibility(DW_ACCESS_public)
DW$123	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$123, DW_AT_name("WKEY_UL"), DW_AT_symbol_name("_WKEY_UL")
	.dwattr DW$123, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$123, DW_AT_accessibility(DW_ACCESS_public)
DW$124	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$124, DW_AT_name("RTICR1_UL"), DW_AT_symbol_name("_RTICR1_UL")
	.dwattr DW$124, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$124, DW_AT_accessibility(DW_ACCESS_public)
DW$125	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$125, DW_AT_name("RTICR2_UL"), DW_AT_symbol_name("_RTICR2_UL")
	.dwattr DW$125, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr DW$125, DW_AT_accessibility(DW_ACCESS_public)
DW$126	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1091)
	.dwattr DW$126, DW_AT_name("DRTICINT_UN"), DW_AT_symbol_name("_DRTICINT_UN")
	.dwattr DW$126, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr DW$126, DW_AT_accessibility(DW_ACCESS_public)
DW$127	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1092)
	.dwattr DW$127, DW_AT_name("DRTICNTEN_UN"), DW_AT_symbol_name("_DRTICNTEN_UN")
	.dwattr DW$127, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr DW$127, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1093


DWT$1057	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1057, DW_AT_name("_HALINTERFACE")
	.dwattr DWT$1057, DW_AT_byte_size(0x08)
DW$128	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1055)
	.dwattr DW$128, DW_AT_name("IntClkFrequency_UL"), DW_AT_symbol_name("_IntClkFrequency_UL")
	.dwattr DW$128, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$128, DW_AT_accessibility(DW_ACCESS_public)
DW$129	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1056)
	.dwattr DW$129, DW_AT_name("IntWdtTimeout_UW"), DW_AT_symbol_name("_IntWdtTimeout_UW")
	.dwattr DW$129, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$129, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1057


DWT$1086	.dwtag  DW_TAG_union_type
	.dwattr DWT$1086, DW_AT_byte_size(0x04)
DW$130	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$130, DW_AT_name("DRTICNTR_UL"), DW_AT_symbol_name("_DRTICNTR_UL")
	.dwattr DW$130, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$130, DW_AT_accessibility(DW_ACCESS_public)
DW$131	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1085)
	.dwattr DW$131, DW_AT_name("DRTICNTR_ST"), DW_AT_symbol_name("_DRTICNTR_ST")
	.dwattr DW$131, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$131, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1086


DWT$1087	.dwtag  DW_TAG_union_type
	.dwattr DWT$1087, DW_AT_byte_size(0x04)
DW$132	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$132, DW_AT_name("DRTIPCTL_UL"), DW_AT_symbol_name("_DRTIPCTL_UL")
	.dwattr DW$132, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$132, DW_AT_accessibility(DW_ACCESS_public)
DW$133	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1079)
	.dwattr DW$133, DW_AT_name("DRTIPCTL_ST"), DW_AT_symbol_name("_DRTIPCTL_ST")
	.dwattr DW$133, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$133, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1087


DWT$1089	.dwtag  DW_TAG_union_type
	.dwattr DWT$1089, DW_AT_byte_size(0x04)
DW$134	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$134, DW_AT_name("DRTICNTL_UL"), DW_AT_symbol_name("_DRTICNTL_UL")
	.dwattr DW$134, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$134, DW_AT_accessibility(DW_ACCESS_public)
DW$135	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1088)
	.dwattr DW$135, DW_AT_name("DRTICNTL_ST"), DW_AT_symbol_name("_DRTICNTL_ST")
	.dwattr DW$135, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$135, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1089


DWT$1091	.dwtag  DW_TAG_union_type
	.dwattr DWT$1091, DW_AT_byte_size(0x04)
DW$136	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$136, DW_AT_name("DRTICINT_UL"), DW_AT_symbol_name("_DRTICINT_UL")
	.dwattr DW$136, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$136, DW_AT_accessibility(DW_ACCESS_public)
DW$137	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1090)
	.dwattr DW$137, DW_AT_name("DRTICINT_ST"), DW_AT_symbol_name("_DRTICINT_ST")
	.dwattr DW$137, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$137, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1091


DWT$1092	.dwtag  DW_TAG_union_type
	.dwattr DWT$1092, DW_AT_byte_size(0x04)
DW$138	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$138, DW_AT_name("DRTICNTEN_UL"), DW_AT_symbol_name("_DRTICNTEN_UL")
	.dwattr DW$138, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$138, DW_AT_accessibility(DW_ACCESS_public)
DW$139	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1082)
	.dwattr DW$139, DW_AT_name("DRTICNTEN_ST"), DW_AT_symbol_name("_DRTICNTEN_ST")
	.dwattr DW$139, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$139, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1092

DWT$1056	.dwtag  DW_TAG_typedef, DW_AT_name("FAR_PTR_UWORD"), DW_AT_type(*DWT$1022)
	.dwattr DWT$1056, DW_AT_language(DW_LANG_C)
DWT$1055	.dwtag  DW_TAG_typedef, DW_AT_name("FAR_PTR_ULONG"), DW_AT_type(*DWT$1020)
	.dwattr DWT$1055, DW_AT_language(DW_LANG_C)

DWT$1082	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1082, DW_AT_byte_size(0x04)
DW$140	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$140, DW_AT_name("CNTEN_B2"), DW_AT_symbol_name("_CNTEN_B2")
	.dwattr DW$140, DW_AT_bit_offset(0x1e), DW_AT_bit_size(0x02)
	.dwattr DW$140, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$140, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1082


DWT$1085	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1085, DW_AT_byte_size(0x04)
DW$141	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$141, DW_AT_name("DRTICNTR_B21"), DW_AT_symbol_name("_DRTICNTR_B21")
	.dwattr DW$141, DW_AT_bit_offset(0x00), DW_AT_bit_size(0x15)
	.dwattr DW$141, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$141, DW_AT_accessibility(DW_ACCESS_public)
DW$142	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$142, DW_AT_name("DRTIMOD_B11"), DW_AT_symbol_name("_DRTIMOD_B11")
	.dwattr DW$142, DW_AT_bit_offset(0x15), DW_AT_bit_size(0x0b)
	.dwattr DW$142, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$142, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1085


DWT$1088	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1088, DW_AT_byte_size(0x04)
DW$143	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$143, DW_AT_name("RTIF_B1"), DW_AT_symbol_name("_RTIF_B1")
	.dwattr DW$143, DW_AT_bit_offset(0x18), DW_AT_bit_size(0x01)
	.dwattr DW$143, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$143, DW_AT_accessibility(DW_ACCESS_public)
DW$144	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$144, DW_AT_name("RTIE_B1"), DW_AT_symbol_name("_RTIE_B1")
	.dwattr DW$144, DW_AT_bit_offset(0x19), DW_AT_bit_size(0x01)
	.dwattr DW$144, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$144, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1088


DWT$1090	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1090, DW_AT_byte_size(0x04)
DW$145	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$145, DW_AT_name("CF1_B1"), DW_AT_symbol_name("_CF1_B1")
	.dwattr DW$145, DW_AT_bit_offset(0x18), DW_AT_bit_size(0x01)
	.dwattr DW$145, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$145, DW_AT_accessibility(DW_ACCESS_public)
DW$146	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$146, DW_AT_name("CF2_B1"), DW_AT_symbol_name("_CF2_B1")
	.dwattr DW$146, DW_AT_bit_offset(0x19), DW_AT_bit_size(0x01)
	.dwattr DW$146, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$146, DW_AT_accessibility(DW_ACCESS_public)
DW$147	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$147, DW_AT_name("CE1_B1"), DW_AT_symbol_name("_CE1_B1")
	.dwattr DW$147, DW_AT_bit_offset(0x1a), DW_AT_bit_size(0x01)
	.dwattr DW$147, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$147, DW_AT_accessibility(DW_ACCESS_public)
DW$148	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$148, DW_AT_name("CR2_B1"), DW_AT_symbol_name("_CR2_B1")
	.dwattr DW$148, DW_AT_bit_offset(0x1b), DW_AT_bit_size(0x01)
	.dwattr DW$148, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$148, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1090


	.dwattr DW$22, DW_AT_external(0x01)
	.dwattr DW$46, DW_AT_external(0x01)
	.dwattr DW$48, DW_AT_external(0x01)
	.dwattr DW$30, DW_AT_external(0x01)
	.dwattr DW$30, DW_AT_type(*DWT$1021)
	.dwattr DW$54, DW_AT_external(0x01)
	.dwattr DW$54, DW_AT_type(*DWT$1019)
	.dwattr DW$51, DW_AT_external(0x01)
	.dwattr DW$51, DW_AT_type(*DWT$1019)
	.dwattr DW$12, DW_AT_external(0x01)
	.dwattr DW$26, DW_AT_external(0x01)
	.dwattr DW$43, DW_AT_external(0x01)
	.dwattr DW$39, DW_AT_external(0x01)
	.dwattr DW$36, DW_AT_external(0x01)
	.dwattr DW$77, DW_AT_external(0x01)
	.dwattr DW$77, DW_AT_type(*DWT$1018)
	.dwattr DW$73, DW_AT_external(0x01)
	.dwattr DW$56, DW_AT_external(0x01)
	.dwattr DWCU, DW_AT_language(DW_LANG_C)

;***************************************************************
;* DWARF CIE ENTRIES                                           *
;***************************************************************

DW$CIE	.dwcie 1, 26
	.dwcfa	0x0c, 13, 0
	.dwcfa	0x07, 0
	.dwcfa	0x07, 1
	.dwcfa	0x07, 2
	.dwcfa	0x07, 3
	.dwcfa	0x08, 4
	.dwcfa	0x08, 5
	.dwcfa	0x08, 6
	.dwcfa	0x08, 7
	.dwcfa	0x08, 8
	.dwcfa	0x08, 9
	.dwcfa	0x08, 10
	.dwcfa	0x08, 11
	.dwcfa	0x07, 12
	.dwcfa	0x07, 13
	.dwcfa	0x07, 14
	.dwcfa	0x07, 15
	.dwcfa	0x07, 16
	.dwcfa	0x07, 17
	.dwcfa	0x07, 18
	.dwcfa	0x07, 19
	.dwcfa	0x07, 20
	.dwcfa	0x07, 21
	.dwcfa	0x07, 22
	.dwcfa	0x07, 23
	.dwcfa	0x07, 24
	.dwcfa	0x07, 25
	.dwcfa	0x07, 26

;***************************************************************
;* DWARF REGISTER MAP                                          *
;***************************************************************

DW$149	.dwtag  DW_TAG_assign_register, DW_AT_name("A1")
	.dwattr DW$149, DW_AT_location[DW_OP_reg0]
DW$150	.dwtag  DW_TAG_assign_register, DW_AT_name("A2")
	.dwattr DW$150, DW_AT_location[DW_OP_reg1]
DW$151	.dwtag  DW_TAG_assign_register, DW_AT_name("A3")
	.dwattr DW$151, DW_AT_location[DW_OP_reg2]
DW$152	.dwtag  DW_TAG_assign_register, DW_AT_name("A4")
	.dwattr DW$152, DW_AT_location[DW_OP_reg3]
DW$153	.dwtag  DW_TAG_assign_register, DW_AT_name("V1")
	.dwattr DW$153, DW_AT_location[DW_OP_reg4]
DW$154	.dwtag  DW_TAG_assign_register, DW_AT_name("V2")
	.dwattr DW$154, DW_AT_location[DW_OP_reg5]
DW$155	.dwtag  DW_TAG_assign_register, DW_AT_name("V3")
	.dwattr DW$155, DW_AT_location[DW_OP_reg6]
DW$156	.dwtag  DW_TAG_assign_register, DW_AT_name("V4")
	.dwattr DW$156, DW_AT_location[DW_OP_reg7]
DW$157	.dwtag  DW_TAG_assign_register, DW_AT_name("V5")
	.dwattr DW$157, DW_AT_location[DW_OP_reg8]
DW$158	.dwtag  DW_TAG_assign_register, DW_AT_name("V6")
	.dwattr DW$158, DW_AT_location[DW_OP_reg9]
DW$159	.dwtag  DW_TAG_assign_register, DW_AT_name("V7")
	.dwattr DW$159, DW_AT_location[DW_OP_reg10]
DW$160	.dwtag  DW_TAG_assign_register, DW_AT_name("V8")
	.dwattr DW$160, DW_AT_location[DW_OP_reg11]
DW$161	.dwtag  DW_TAG_assign_register, DW_AT_name("V9")
	.dwattr DW$161, DW_AT_location[DW_OP_reg12]
DW$162	.dwtag  DW_TAG_assign_register, DW_AT_name("SP")
	.dwattr DW$162, DW_AT_location[DW_OP_reg13]
DW$163	.dwtag  DW_TAG_assign_register, DW_AT_name("LR")
	.dwattr DW$163, DW_AT_location[DW_OP_reg14]
DW$164	.dwtag  DW_TAG_assign_register, DW_AT_name("PC")
	.dwattr DW$164, DW_AT_location[DW_OP_reg15]
DW$165	.dwtag  DW_TAG_assign_register, DW_AT_name("C0")
	.dwattr DW$165, DW_AT_location[DW_OP_reg16]
DW$166	.dwtag  DW_TAG_assign_register, DW_AT_name("C1")
	.dwattr DW$166, DW_AT_location[DW_OP_reg17]
DW$167	.dwtag  DW_TAG_assign_register, DW_AT_name("C2")
	.dwattr DW$167, DW_AT_location[DW_OP_reg18]
DW$168	.dwtag  DW_TAG_assign_register, DW_AT_name("C3")
	.dwattr DW$168, DW_AT_location[DW_OP_reg19]
DW$169	.dwtag  DW_TAG_assign_register, DW_AT_name("C4")
	.dwattr DW$169, DW_AT_location[DW_OP_reg20]
DW$170	.dwtag  DW_TAG_assign_register, DW_AT_name("C5")
	.dwattr DW$170, DW_AT_location[DW_OP_reg21]
DW$171	.dwtag  DW_TAG_assign_register, DW_AT_name("C6")
	.dwattr DW$171, DW_AT_location[DW_OP_reg22]
DW$172	.dwtag  DW_TAG_assign_register, DW_AT_name("C7")
	.dwattr DW$172, DW_AT_location[DW_OP_reg23]
DW$173	.dwtag  DW_TAG_assign_register, DW_AT_name("AP")
	.dwattr DW$173, DW_AT_location[DW_OP_reg24]
DW$174	.dwtag  DW_TAG_assign_register, DW_AT_name("SR")
	.dwattr DW$174, DW_AT_location[DW_OP_reg25]
DW$175	.dwtag  DW_TAG_assign_register, DW_AT_name("CIE_RETA")
	.dwattr DW$175, DW_AT_location[DW_OP_reg26]
	.dwendtag DWCU

