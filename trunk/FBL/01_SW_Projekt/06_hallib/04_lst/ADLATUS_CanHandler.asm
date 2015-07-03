;******************************************************************************
;* TMS470 C/C++ Codegen                                       PC Version 2.71 *
;* Date/Time created: Fri Dec 09 13:08:58 2011                                *
;******************************************************************************
	.state16

DWCU	.dwtag  DW_TAG_compile_unit
	.dwattr DWCU, DW_AT_name("ADLATUS_CanHandler.c")
	.dwattr DWCU, DW_AT_producer("TMS470 C/C++ Codegen PC Version 2.71 Copyright (c) 1996-2008 Texas Instruments Incorporated")
	.dwattr DWCU, DW_AT_stmt_list(0x00)
	.dwattr DWCU, DW_AT_TI_VERSION(0x01)

DW$1	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCtim_SystemTimerCheck_V"), DW_AT_symbol_name("$FUN_CCtim_SystemTimerCheck_V")
	.dwattr DW$1, DW_AT_declaration(0x01)
	.dwattr DW$1, DW_AT_external(0x01)
DW$2	.dwtag  DW_TAG_variable, DW_AT_name("e_SCC_ST"), DW_AT_symbol_name("_e_SCC_ST")
	.dwattr DW$2, DW_AT_type(*DWT$1144)
	.dwattr DW$2, DW_AT_declaration(0x01)
	.dwattr DW$2, DW_AT_external(0x01)
DW$3	.dwtag  DW_TAG_variable, DW_AT_name("e_CAN_MB"), DW_AT_symbol_name("_e_CAN_MB")
	.dwattr DW$3, DW_AT_type(*DWT$1179)
	.dwattr DW$3, DW_AT_declaration(0x01)
	.dwattr DW$3, DW_AT_external(0x01)

	.sect	".const"
	.align	4
_c_CCcan_TestPattern_AUB:
	.field  	90,8			; _c_CCcan_TestPattern_AUB[0] @ 0
	.field  	165,8			; _c_CCcan_TestPattern_AUB[1] @ 8
	.field  	0,8			; _c_CCcan_TestPattern_AUB[2] @ 16

	.sect	".text"
	.global	_c_CCcan_TestPattern_AUB
DW$4	.dwtag  DW_TAG_variable, DW_AT_name("c_CCcan_TestPattern_AUB"), DW_AT_symbol_name("_c_CCcan_TestPattern_AUB")
	.dwattr DW$4, DW_AT_type(*DWT$1027)
	.dwattr DW$4, DW_AT_location[DW_OP_addr _c_CCcan_TestPattern_AUB]
	.dwattr DW$4, DW_AT_external(0x01)

	.sect	".const"
	.align	4
_c_CCcan_BaudrateTable_AUL:
	.field  	638,32			; _c_CCcan_BaudrateTable_AUL[0] @ 0
	.field  	131667,32			; _c_CCcan_BaudrateTable_AUL[1] @ 32
	.field  	0,32			; _c_CCcan_BaudrateTable_AUL[2] @ 64
	.field  	328275,32			; _c_CCcan_BaudrateTable_AUL[3] @ 96
	.field  	328307,32			; _c_CCcan_BaudrateTable_AUL[4] @ 128
	.field  	0,32			; _c_CCcan_BaudrateTable_AUL[5] @ 160
	.field  	0,32			; _c_CCcan_BaudrateTable_AUL[6] @ 192
	.field  	0,32			; _c_CCcan_BaudrateTable_AUL[7] @ 224
	.field  	721475,32			; _c_CCcan_BaudrateTable_AUL[8] @ 256
	.field  	918099,32			; _c_CCcan_BaudrateTable_AUL[9] @ 288
	.field  	1114707,32			; _c_CCcan_BaudrateTable_AUL[10] @ 320

	.sect	".text"
	.global	_c_CCcan_BaudrateTable_AUL
DW$5	.dwtag  DW_TAG_variable, DW_AT_name("c_CCcan_BaudrateTable_AUL"), DW_AT_symbol_name("_c_CCcan_BaudrateTable_AUL")
	.dwattr DW$5, DW_AT_type(*DWT$1056)
	.dwattr DW$5, DW_AT_location[DW_OP_addr _c_CCcan_BaudrateTable_AUL]
	.dwattr DW$5, DW_AT_external(0x01)
	.global	_t_CCcan_CanFifoBuffer_AUB
	.bss	_t_CCcan_CanFifoBuffer_AUB,48,4
DW$6	.dwtag  DW_TAG_variable, DW_AT_name("t_CCcan_CanFifoBuffer_AUB"), DW_AT_symbol_name("_t_CCcan_CanFifoBuffer_AUB")
	.dwattr DW$6, DW_AT_type(*DWT$1029)
	.dwattr DW$6, DW_AT_location[DW_OP_addr _t_CCcan_CanFifoBuffer_AUB]
	.dwattr DW$6, DW_AT_external(0x01)
	.global	_CanCtrl_ST
	.bss	_CanCtrl_ST,36,4
DW$7	.dwtag  DW_TAG_variable, DW_AT_name("CanCtrl_ST"), DW_AT_symbol_name("_CanCtrl_ST")
	.dwattr DW$7, DW_AT_type(*DWT$1183)
	.dwattr DW$7, DW_AT_location[DW_OP_addr _CanCtrl_ST]
	.dwattr DW$7, DW_AT_external(0x01)
	.bss	_t_MsgObjNbr_UB$1,1,1
DW$8	.dwtag  DW_TAG_variable, DW_AT_name("t_MsgObjNbr_UB"), DW_AT_symbol_name("_t_MsgObjNbr_UB$1")
	.dwattr DW$8, DW_AT_type(*DWT$1018)
	.dwattr DW$8, DW_AT_location[DW_OP_addr _t_MsgObjNbr_UB$1]
;	C:\CCStudio_v3.3\tms470\cgtools_271\bin\opt470.exe -v1 -q -s -O2 -e r:/06_hallib/04_lst/ADLATUS_CanHandler.if r:/06_hallib/04_lst/ADLATUS_CanHandler.opt -w r:/06_hallib/04_lst 

	.sect	".text:v$0"
	.clink
	.global	_FUN_CCcan_Waitconf_V

DW$9	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_Waitconf_V"), DW_AT_symbol_name("_FUN_CCcan_Waitconf_V")
	.dwattr DW$9, DW_AT_veneer(0x01)
	.dwattr DW$9, DW_AT_low_pc(_FUN_CCcan_Waitconf_V)
	.dwattr DW$9, DW_AT_high_pc(0x00)
	.dwattr DW$9, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CCcan_Waitconf_V                                    *
;*****************************************************************************
_FUN_CCcan_Waitconf_V:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FUN_CCcan_Waitconf_V+1, 32
	.state16
	.dwendtag DW$9



	.sect	".text"
	.clink
	.global	$FUN_CCcan_Waitconf_V

DW$10	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_Waitconf_V"), DW_AT_symbol_name("$FUN_CCcan_Waitconf_V")
	.dwattr DW$10, DW_AT_low_pc($FUN_CCcan_Waitconf_V)
	.dwattr DW$10, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_CanHandler.c",244,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 243 | void FUN_CCcan_Waitconf_V(void)                                        
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CCcan_Waitconf_V                                       *
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
$FUN_CCcan_Waitconf_V:
;* --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 245 | while(!(e_SCC_ST.CANES_UN.CANES_ST.CCE_B1))                            
; 247 |   ;                                                                    
;----------------------------------------------------------------------
	.dwcfa	0x09, 26, 14
;* A2    assigned to K$0
DW$11	.dwtag  DW_TAG_variable, DW_AT_name("K$0"), DW_AT_symbol_name("K$0")
	.dwattr DW$11, DW_AT_type(*DWT$1134)
	.dwattr DW$11, DW_AT_location[DW_OP_reg1]
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;**  	-----------------------    K$0 = &e_SCC_ST+51;
        LDR       A2, CON1
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L1
;*
;*   Loop source line                : 245
;*   Loop closing brace source line  : 248
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L1:    
DWL$$FUN_CCcan_Waitconf_V$2$B:
;**	-----------------------g2:
;** 248	-----------------------    if ( !(*(volatile unsigned char *)K$0&0x10u) ) goto g2;
	.dwpsn	"ADLATUS_CanHandler.c",248,4
        LDRB      A1, [A2, #0]          ; |248| 
        LSR       A1, A1, #5            ; |248| 
        BCC       L1                    ; |248| 
        ; |248| 
;**  	-----------------------    return;
DWL$$FUN_CCcan_Waitconf_V$2$E:
;* --------------------------------------------------------------------------*
	.dwpsn	"ADLATUS_CanHandler.c",250,1
        BX        LR

DW$12	.dwtag  DW_TAG_loop
	.dwattr DW$12, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L1:1:1323432538")
	.dwattr DW$12, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$12, DW_AT_begin_line(0xf5)
	.dwattr DW$12, DW_AT_end_line(0xf8)
DW$13	.dwtag  DW_TAG_loop_range
	.dwattr DW$13, DW_AT_low_pc(DWL$$FUN_CCcan_Waitconf_V$2$B)
	.dwattr DW$13, DW_AT_high_pc(DWL$$FUN_CCcan_Waitconf_V$2$E)
	.dwendtag DW$12

	.dwendentry
	.dwendtag DW$10




	.sect	".text:v$1"
	.clink
	.global	_FUN_CCcan_Waitconfx_V

DW$14	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_Waitconfx_V"), DW_AT_symbol_name("_FUN_CCcan_Waitconfx_V")
	.dwattr DW$14, DW_AT_veneer(0x01)
	.dwattr DW$14, DW_AT_low_pc(_FUN_CCcan_Waitconfx_V)
	.dwattr DW$14, DW_AT_high_pc(0x00)
	.dwattr DW$14, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CCcan_Waitconfx_V                                   *
;*****************************************************************************
_FUN_CCcan_Waitconfx_V:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FUN_CCcan_Waitconfx_V+1, 32
	.state16
	.dwendtag DW$14



	.sect	".text"
	.clink
	.global	$FUN_CCcan_Waitconfx_V

DW$15	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_Waitconfx_V"), DW_AT_symbol_name("$FUN_CCcan_Waitconfx_V")
	.dwattr DW$15, DW_AT_low_pc($FUN_CCcan_Waitconfx_V)
	.dwattr DW$15, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_CanHandler.c",253,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 252 | void FUN_CCcan_Waitconfx_V(void)                                       
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CCcan_Waitconfx_V                                      *
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
$FUN_CCcan_Waitconfx_V:
;* --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 255 | while((e_SCC_ST.CANES_UN.CANES_ST.CCE_B1 != 0u))                       
; 257 |   ;                                                                    
;----------------------------------------------------------------------
	.dwcfa	0x09, 26, 14
;* A2    assigned to K$0
DW$16	.dwtag  DW_TAG_variable, DW_AT_name("K$0"), DW_AT_symbol_name("K$0")
	.dwattr DW$16, DW_AT_type(*DWT$1134)
	.dwattr DW$16, DW_AT_location[DW_OP_reg1]
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;**  	-----------------------    K$0 = &e_SCC_ST+51;
        LDR       A2, CON1
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L2
;*
;*   Loop source line                : 255
;*   Loop closing brace source line  : 258
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L2:    
DWL$$FUN_CCcan_Waitconfx_V$2$B:
;**	-----------------------g2:
;** 258	-----------------------    if ( *(volatile unsigned char *)K$0&0x10u ) goto g2;
	.dwpsn	"ADLATUS_CanHandler.c",258,4
        LDRB      A1, [A2, #0]          ; |258| 
        LSR       A1, A1, #5            ; |258| 
        BCS       L2                    ; |258| 
        ; |258| 
;**  	-----------------------    return;
DWL$$FUN_CCcan_Waitconfx_V$2$E:
;* --------------------------------------------------------------------------*
	.dwpsn	"ADLATUS_CanHandler.c",260,1
        BX        LR

DW$17	.dwtag  DW_TAG_loop
	.dwattr DW$17, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L2:1:1323432538")
	.dwattr DW$17, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$17, DW_AT_begin_line(0xff)
	.dwattr DW$17, DW_AT_end_line(0x102)
DW$18	.dwtag  DW_TAG_loop_range
	.dwattr DW$18, DW_AT_low_pc(DWL$$FUN_CCcan_Waitconfx_V$2$B)
	.dwattr DW$18, DW_AT_high_pc(DWL$$FUN_CCcan_Waitconfx_V$2$E)
	.dwendtag DW$17

	.dwendentry
	.dwendtag DW$15




	.sect	".text:v$2"
	.clink
	.global	_FUN_CCcan_Wait_V

DW$19	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_Wait_V"), DW_AT_symbol_name("_FUN_CCcan_Wait_V")
	.dwattr DW$19, DW_AT_veneer(0x01)
	.dwattr DW$19, DW_AT_low_pc(_FUN_CCcan_Wait_V)
	.dwattr DW$19, DW_AT_high_pc(0x00)
	.dwattr DW$19, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CCcan_Wait_V                                        *
;*****************************************************************************
_FUN_CCcan_Wait_V:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FUN_CCcan_Wait_V+1, 32
	.state16
	.dwendtag DW$19



	.sect	".text"
	.clink
	.global	$FUN_CCcan_Wait_V

DW$20	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_Wait_V"), DW_AT_symbol_name("$FUN_CCcan_Wait_V")
	.dwattr DW$20, DW_AT_low_pc($FUN_CCcan_Wait_V)
	.dwattr DW$20, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_CanHandler.c",263,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 262 | void FUN_CCcan_Wait_V(void)                                            
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CCcan_Wait_V                                           *
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
$FUN_CCcan_Wait_V:
;* --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 264 | while (e_SCC_ST.CANTRS_UL != 0ul)                                      
; 266 |   ;                                                                    
;----------------------------------------------------------------------
	.dwcfa	0x09, 26, 14
;* A2    assigned to K$1
DW$21	.dwtag  DW_TAG_variable, DW_AT_name("K$1"), DW_AT_symbol_name("K$1")
	.dwattr DW$21, DW_AT_type(*DWT$1145)
	.dwattr DW$21, DW_AT_location[DW_OP_reg1]
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;**  	-----------------------    K$1 = &e_SCC_ST;
        LDR       A2, CON1
        SUB       A2, #51
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L3
;*
;*   Loop source line                : 264
;*   Loop closing brace source line  : 267
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L3:    
DWL$$FUN_CCcan_Wait_V$2$B:
;**	-----------------------g2:
;** 267	-----------------------    if ( K$1->CANTRS_UL ) goto g2;
	.dwpsn	"ADLATUS_CanHandler.c",267,4
        LDR       A1, [A2, #8]          ; |267| 
        CMP       A1, #0                ; |267| 
        BNE       L3                    ; |267| 
        ; |267| 
;**  	-----------------------    return;
DWL$$FUN_CCcan_Wait_V$2$E:
;* --------------------------------------------------------------------------*
	.dwpsn	"ADLATUS_CanHandler.c",268,1
        BX        LR

DW$22	.dwtag  DW_TAG_loop
	.dwattr DW$22, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L3:1:1323432538")
	.dwattr DW$22, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$22, DW_AT_begin_line(0x108)
	.dwattr DW$22, DW_AT_end_line(0x10b)
DW$23	.dwtag  DW_TAG_loop_range
	.dwattr DW$23, DW_AT_low_pc(DWL$$FUN_CCcan_Wait_V$2$B)
	.dwattr DW$23, DW_AT_high_pc(DWL$$FUN_CCcan_Wait_V$2$E)
	.dwendtag DW$22

	.dwendentry
	.dwendtag DW$20




	.sect	".text:v$3"
	.clink
	.global	_FUN_CCcan_CheckMsgObjBuffer_UB

DW$24	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_CheckMsgObjBuffer_UB"), DW_AT_symbol_name("_FUN_CCcan_CheckMsgObjBuffer_UB")
	.dwattr DW$24, DW_AT_veneer(0x01)
	.dwattr DW$24, DW_AT_low_pc(_FUN_CCcan_CheckMsgObjBuffer_UB)
	.dwattr DW$24, DW_AT_high_pc(0x00)
	.dwattr DW$24, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CCcan_CheckMsgObjBuffer_UB                          *
;*****************************************************************************
_FUN_CCcan_CheckMsgObjBuffer_UB:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $FUN_CCcan_CheckMsgObjBuffer_UB
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$24



	.sect	".text"
	.clink
	.global	$FUN_CCcan_CheckMsgObjBuffer_UB

DW$25	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_CheckMsgObjBuffer_UB"), DW_AT_symbol_name("$FUN_CCcan_CheckMsgObjBuffer_UB")
	.dwattr DW$25, DW_AT_low_pc($FUN_CCcan_CheckMsgObjBuffer_UB)
	.dwattr DW$25, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_CanHandler.c",286,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 285 | UBYTE  FUN_CCcan_CheckMsgObjBuffer_UB (void)                           
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CCcan_CheckMsgObjBuffer_UB                             *
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
$FUN_CCcan_CheckMsgObjBuffer_UB:
;* --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 287 | UBYTE            t_CheckResult_UB;                                     
; 288 | UBYTE            t_CanNode_UB;                                         
; 289 | UBYTE            t_CanMsgObj_UB;                                       
; 290 | UBYTE            t_Index_UB;                                           
; 291 | UBYTE            t_PatternIndex_UB;                                    
; 296 | t_CheckResult_UB  = (d_CCVhnd_CheckOK | d_CCVhnd_Ready);               
;----------------------------------------------------------------------
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
;* V4    assigned to C$1
DW$26	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$26, DW_AT_type(*DWT$6)
	.dwattr DW$26, DW_AT_location[DW_OP_reg7]
;* LR    assigned to _t_CheckResult_UB
DW$27	.dwtag  DW_TAG_variable, DW_AT_name("t_CheckResult_UB"), DW_AT_symbol_name("_t_CheckResult_UB")
	.dwattr DW$27, DW_AT_type(*DWT$1018)
	.dwattr DW$27, DW_AT_location[DW_OP_reg14]
;* V9    assigned to _t_CanNode_UB
DW$28	.dwtag  DW_TAG_variable, DW_AT_name("t_CanNode_UB"), DW_AT_symbol_name("_t_CanNode_UB")
	.dwattr DW$28, DW_AT_type(*DWT$1018)
	.dwattr DW$28, DW_AT_location[DW_OP_reg12]
;* A4    assigned to L$3
DW$29	.dwtag  DW_TAG_variable, DW_AT_name("L$3"), DW_AT_symbol_name("L$3")
	.dwattr DW$29, DW_AT_type(*DWT$11)
	.dwattr DW$29, DW_AT_location[DW_OP_reg3]
;* V2    assigned to L$2
DW$30	.dwtag  DW_TAG_variable, DW_AT_name("L$2"), DW_AT_symbol_name("L$2")
	.dwattr DW$30, DW_AT_type(*DWT$11)
	.dwattr DW$30, DW_AT_location[DW_OP_reg5]
;* V3    assigned to L$1
DW$31	.dwtag  DW_TAG_variable, DW_AT_name("L$1"), DW_AT_symbol_name("L$1")
	.dwattr DW$31, DW_AT_type(*DWT$11)
	.dwattr DW$31, DW_AT_location[DW_OP_reg6]
;* A2    assigned to U$26
DW$32	.dwtag  DW_TAG_variable, DW_AT_name("U$26"), DW_AT_symbol_name("U$26")
	.dwattr DW$32, DW_AT_type(*DWT$1040)
	.dwattr DW$32, DW_AT_location[DW_OP_reg1]
;* V1    assigned to U$22
DW$33	.dwtag  DW_TAG_variable, DW_AT_name("U$22"), DW_AT_symbol_name("U$22")
	.dwattr DW$33, DW_AT_type(*DWT$1035)
	.dwattr DW$33, DW_AT_location[DW_OP_reg4]
;* A3    assigned to U$13
DW$34	.dwtag  DW_TAG_variable, DW_AT_name("U$13"), DW_AT_symbol_name("U$13")
	.dwattr DW$34, DW_AT_type(*DWT$1181)
	.dwattr DW$34, DW_AT_location[DW_OP_reg2]
;* A1    assigned to K$1
DW$35	.dwtag  DW_TAG_variable, DW_AT_name("K$1"), DW_AT_symbol_name("K$1")
	.dwattr DW$35, DW_AT_type(*DWT$10)
	.dwattr DW$35, DW_AT_location[DW_OP_reg0]
;** 301	-----------------------    e_SCC_ST.CANME_UL = K$1 = 0u;
	.dwpsn	"ADLATUS_CanHandler.c",301,3
;----------------------------------------------------------------------
; 301 | e_SCC_ST.CANME_UL = 0x00000000UL;                                      
;----------------------------------------------------------------------
        LDR       A1, CON1              ; |301| 
        SUB       A1, #51               ; |301| 
        MOV       A2, #0                ; |301| 
        STR       A2, [A1, #0]          ; |301| 
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;**  	-----------------------    U$13 = &e_CAN_MB[0];
        LDR       A1, CON3
        MOV       A3, A1
;** 296	-----------------------    t_CheckResult_UB = 0x81u;
	.dwpsn	"ADLATUS_CanHandler.c",296,3
        MOV       A1, #129              ; |296| 
        MOV       LR, A1
;** 306	-----------------------    t_CanNode_UB = 0u;
	.dwpsn	"ADLATUS_CanHandler.c",306,8
;----------------------------------------------------------------------
; 306 | for( t_CanNode_UB = 0x00; t_CanNode_UB < d_CCcan_MaxCanNodes; t_CanNode
;     | _UB++ )                                                                
;----------------------------------------------------------------------
        MOV       A1, A2
        MOV       V9, A1
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L4
;*
;*   Loop source line                : 306
;*   Loop closing brace source line  : 350
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L4:    
DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$2$B:
;**	-----------------------g2:
;** 308	-----------------------    U$13->MID_ST.l.CanMID_UL = K$1;
	.dwpsn	"ADLATUS_CanHandler.c",308,5
;----------------------------------------------------------------------
; 308 | e_CAN_MB[t_CanNode_UB].MID_ST.l.CanMID_UL = 0x00000000ul;              
;----------------------------------------------------------------------
        MOV       A1, #0                ; |301| 
        STR       A1, [A3, #0]          ; |308| 
;** 309	-----------------------    U$13->MCF_ST.l.CanMCF_UL = K$1;
	.dwpsn	"ADLATUS_CanHandler.c",309,5
;----------------------------------------------------------------------
; 309 | e_CAN_MB[t_CanNode_UB].MCF_ST.l.CanMCF_UL = 0x00000000ul;              
;----------------------------------------------------------------------
        STR       A1, [A3, #4]          ; |309| 
;**  	-----------------------    #pragma MUST_ITERATE(15, 15, 15)
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;**  	-----------------------    U$26 = &((volatile unsigned char *)e_CAN_MB)[0];
        LDR       A2, CON3
;** 314	-----------------------    L$1 = 15;
	.dwpsn	"ADLATUS_CanHandler.c",314,10
;----------------------------------------------------------------------
; 314 | for( t_CanMsgObj_UB = 0x00u; t_CanMsgObj_UB < d_CCcan_NbrOfMsgObjs; t_C
;     | anMsgObj_UB++ )                                                        
;----------------------------------------------------------------------
        MOV       V3, #15               ; |314| 
DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$2$E:
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L5
;*
;*   Loop source line                : 314
;*   Loop closing brace source line  : 349
;*   Known Minimum Trip Count        : 15
;*   Known Maximum Trip Count        : 15
;*   Known Max Trip Count Factor     : 15
;* --------------------------------------------------------------------------*
L5:    
DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$3$B:
;**	-----------------------g4:
;**  	-----------------------    #pragma MUST_ITERATE(8, 8, 8)
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;** 319	-----------------------    L$2 = 8;
	.dwpsn	"ADLATUS_CanHandler.c",319,12
;----------------------------------------------------------------------
; 319 | for (t_Index_UB = 0x00u; t_Index_UB < 0x08; t_Index_UB++ )             
;----------------------------------------------------------------------
        MOV       V2, #8                ; |319| 
DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$3$E:
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L6
;*
;*   Loop source line                : 319
;*   Loop closing brace source line  : 348
;*   Known Minimum Trip Count        : 8
;*   Known Maximum Trip Count        : 8
;*   Known Max Trip Count Factor     : 8
;* --------------------------------------------------------------------------*
L6:    
DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$4$B:
;**	-----------------------g6:
;**  	-----------------------    #pragma MUST_ITERATE(3, 3, 3)
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;** 324	-----------------------    L$3 = 3;
	.dwpsn	"ADLATUS_CanHandler.c",324,15
;----------------------------------------------------------------------
; 324 | for ( t_PatternIndex_UB = (UBYTE) 0x00u; \                             
; 325 |       t_PatternIndex_UB <= (UBYTE) 0x02u; \                            
; 326 |       t_PatternIndex_UB++ )                                            
;----------------------------------------------------------------------
        MOV       A4, #3                ; |324| 
;**  	-----------------------    U$22 = &c_CCcan_TestPattern_AUB[0];
        LDR       V1, CON4
DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$4$E:
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L7
;*
;*   Loop source line                : 324
;*   Loop closing brace source line  : 347
;*   Known Minimum Trip Count        : 3
;*   Known Maximum Trip Count        : 3
;*   Known Max Trip Count Factor     : 3
;* --------------------------------------------------------------------------*
L7:    
DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$5$B:
;**	-----------------------g8:
;** 331	-----------------------    U$26[8] = C$1 = *U$22;
	.dwpsn	"ADLATUS_CanHandler.c",331,11
;----------------------------------------------------------------------
; 331 | e_CAN_MB[t_CanMsgObj_UB].u.CanData_UB[t_Index_UB] =                    
; 332 | c_CCcan_TestPattern_AUB[t_PatternIndex_UB];                            
;----------------------------------------------------------------------
        LDRB      V4, [V1, #0]          ; |331| 
        STRB      V4, [A2, #8]          ; |331| 
;** 337	-----------------------    if ( U$26[8] == C$1 ) goto g10;
	.dwpsn	"ADLATUS_CanHandler.c",337,11
;----------------------------------------------------------------------
; 337 | if ( e_CAN_MB[t_CanMsgObj_UB].u.CanData_UB[t_Index_UB] !=              
; 338 |      c_CCcan_TestPattern_AUB[t_PatternIndex_UB])                       
;----------------------------------------------------------------------
        LDRB      A1, [A2, #8]          ; |337| 
        CMP       A1, V4                ; |337| 
        BEQ       L8                    ; |337| 
        ; |337| 
DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$5$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$6$B:
;** 344	-----------------------    t_CheckResult_UB = 1u;
	.dwpsn	"ADLATUS_CanHandler.c",344,13
;----------------------------------------------------------------------
; 344 | t_CheckResult_UB = d_CCglo_RamCheckError;                              
;----------------------------------------------------------------------
        MOV       A1, #1                ; |344| 
        MOV       LR, A1
DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$6$E:
;* --------------------------------------------------------------------------*
L8:    
DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$7$B:
;**	-----------------------g10:
;** 347	-----------------------    ++U$22;
	.dwpsn	"ADLATUS_CanHandler.c",347,9
        ADD       V1, #1                ; |347| 
;** 347	-----------------------    if ( --L$3 ) goto g8;
        SUB       A4, #1                ; |347| 
        BNE       L7                    ; |347| 
        ; |347| 
DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$7$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$8$B:
;** 348	-----------------------    ++U$26;
	.dwpsn	"ADLATUS_CanHandler.c",348,7
        ADD       A2, #1                ; |348| 
;** 348	-----------------------    if ( --L$2 ) goto g6;
        SUB       V2, #1                ; |348| 
        BNE       L6                    ; |348| 
        ; |348| 
DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$8$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$9$B:
;**  	-----------------------    U$26 += 8;
        ADD       A2, #8
;** 349	-----------------------    if ( --L$1 ) goto g4;
	.dwpsn	"ADLATUS_CanHandler.c",349,5
        SUB       V3, #1                ; |349| 
        BNE       L5                    ; |349| 
        ; |349| 
DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$9$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$10$B:
;** 350	-----------------------    U$13 += 16;
	.dwpsn	"ADLATUS_CanHandler.c",350,3
        ADD       A3, #16               ; |350| 
;** 350	-----------------------    if ( !(++t_CanNode_UB) ) goto g2;
        MOV       A1, V9
        ADD       A1, A1, #1            ; |350| 
        LSL       A1, A1, #24
        LSR       A1, A1, #24
        MOV       V9, A1
        BEQ       L4                    ; |350| 
        ; |350| 
DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$10$E:
;* --------------------------------------------------------------------------*
;** 352	-----------------------    return t_CheckResult_UB;
	.dwpsn	"ADLATUS_CanHandler.c",352,3
;----------------------------------------------------------------------
; 352 | return (t_CheckResult_UB);                                             
;----------------------------------------------------------------------
        MOV       A1, LR
	.dwpsn	"ADLATUS_CanHandler.c",354,1
	.dwcfa	0x0e, 20
        POP       {V1, V2, V3, V4, PC}

DW$36	.dwtag  DW_TAG_loop
	.dwattr DW$36, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L4:1:1323432538")
	.dwattr DW$36, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$36, DW_AT_begin_line(0x132)
	.dwattr DW$36, DW_AT_end_line(0x15e)
DW$37	.dwtag  DW_TAG_loop_range
	.dwattr DW$37, DW_AT_low_pc(DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$2$B)
	.dwattr DW$37, DW_AT_high_pc(DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$2$E)
DW$38	.dwtag  DW_TAG_loop_range
	.dwattr DW$38, DW_AT_low_pc(DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$10$B)
	.dwattr DW$38, DW_AT_high_pc(DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$10$E)

DW$39	.dwtag  DW_TAG_loop
	.dwattr DW$39, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L5:2:1323432538")
	.dwattr DW$39, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$39, DW_AT_begin_line(0x13a)
	.dwattr DW$39, DW_AT_end_line(0x15d)
DW$40	.dwtag  DW_TAG_loop_range
	.dwattr DW$40, DW_AT_low_pc(DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$3$B)
	.dwattr DW$40, DW_AT_high_pc(DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$3$E)
DW$41	.dwtag  DW_TAG_loop_range
	.dwattr DW$41, DW_AT_low_pc(DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$9$B)
	.dwattr DW$41, DW_AT_high_pc(DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$9$E)

DW$42	.dwtag  DW_TAG_loop
	.dwattr DW$42, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L6:3:1323432538")
	.dwattr DW$42, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$42, DW_AT_begin_line(0x13f)
	.dwattr DW$42, DW_AT_end_line(0x15c)
DW$43	.dwtag  DW_TAG_loop_range
	.dwattr DW$43, DW_AT_low_pc(DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$4$B)
	.dwattr DW$43, DW_AT_high_pc(DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$4$E)
DW$44	.dwtag  DW_TAG_loop_range
	.dwattr DW$44, DW_AT_low_pc(DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$8$B)
	.dwattr DW$44, DW_AT_high_pc(DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$8$E)

DW$45	.dwtag  DW_TAG_loop
	.dwattr DW$45, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L7:4:1323432538")
	.dwattr DW$45, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$45, DW_AT_begin_line(0x144)
	.dwattr DW$45, DW_AT_end_line(0x15b)
DW$46	.dwtag  DW_TAG_loop_range
	.dwattr DW$46, DW_AT_low_pc(DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$5$B)
	.dwattr DW$46, DW_AT_high_pc(DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$5$E)
DW$47	.dwtag  DW_TAG_loop_range
	.dwattr DW$47, DW_AT_low_pc(DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$6$B)
	.dwattr DW$47, DW_AT_high_pc(DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$6$E)
DW$48	.dwtag  DW_TAG_loop_range
	.dwattr DW$48, DW_AT_low_pc(DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$7$B)
	.dwattr DW$48, DW_AT_high_pc(DWL$$FUN_CCcan_CheckMsgObjBuffer_UB$7$E)
	.dwendtag DW$45

	.dwendtag DW$42

	.dwendtag DW$39

	.dwendtag DW$36

	.dwendentry
	.dwendtag DW$25




	.sect	".text:v$4"
	.clink
	.global	_FUN_CCcan_InitCan_V

DW$49	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_InitCan_V"), DW_AT_symbol_name("_FUN_CCcan_InitCan_V")
	.dwattr DW$49, DW_AT_veneer(0x01)
	.dwattr DW$49, DW_AT_low_pc(_FUN_CCcan_InitCan_V)
	.dwattr DW$49, DW_AT_high_pc(0x00)
	.dwattr DW$49, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CCcan_InitCan_V                                     *
;*****************************************************************************
_FUN_CCcan_InitCan_V:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $FUN_CCcan_InitCan_V
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$49



	.sect	".text"
	.clink
	.global	$FUN_CCcan_InitCan_V

DW$50	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_InitCan_V"), DW_AT_symbol_name("$FUN_CCcan_InitCan_V")
	.dwattr DW$50, DW_AT_low_pc($FUN_CCcan_InitCan_V)
	.dwattr DW$50, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_CanHandler.c",372,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 371 | void  FUN_CCcan_InitCan_V (const CANINTERFACE_ST* t_Interface_PST)     
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CCcan_InitCan_V                                        *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V9,SP,LR,SR                             *
;*   Regs Used         : A1,A2,A3,A4,V9,SP,LR,SR                             *
;*   Local Frame Size  : 0 Args + 0 Auto + 4 Save = 4 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CCcan_InitCan_V:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
        PUSH      {LR}
	.dwcfa	0x0e, 4
	.dwcfa	0x80, 14, 1
	.dwcfa	0x0e, 4
;* A1    assigned to _t_Interface_PST
DW$51	.dwtag  DW_TAG_formal_parameter, DW_AT_name("t_Interface_PST"), DW_AT_symbol_name("_t_Interface_PST")
	.dwattr DW$51, DW_AT_type(*DWT$1077)
	.dwattr DW$51, DW_AT_location[DW_OP_reg0]
;* A2    assigned to C$1
DW$52	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$52, DW_AT_type(*DWT$1185)
	.dwattr DW$52, DW_AT_location[DW_OP_reg1]
;* A1    assigned to _t_Interface_PST
DW$53	.dwtag  DW_TAG_variable, DW_AT_name("t_Interface_PST"), DW_AT_symbol_name("_t_Interface_PST")
	.dwattr DW$53, DW_AT_type(*DWT$1118)
	.dwattr DW$53, DW_AT_location[DW_OP_reg0]
;** 376	-----------------------    C$1 = &CanCtrl_ST;
	.dwpsn	"ADLATUS_CanHandler.c",376,3
;----------------------------------------------------------------------
; 376 | CanCtrl_ST.CanMsgObjConfig_PST    = (CANMSGOBJCONFIG_ST*) t_Interface_P
;     | ST->CanMsgObjConfig_PST;                                               
;----------------------------------------------------------------------
        LDR       A2, CON5              ; |376| 
;** 376	-----------------------    C$1->CanMsgObjConfig_PST = t_Interface_PST->CanMsgObjConfig_PST;
        LDR       A3, [A1, #0]          ; |376| 
        STR       A3, [A2, #0]          ; |376| 
;** 377	-----------------------    C$1->CanChannelTable_PST = t_Interface_PST->CanChannelTable_PST;
	.dwpsn	"ADLATUS_CanHandler.c",377,3
;----------------------------------------------------------------------
; 377 | CanCtrl_ST.CanChannelTable_PST    = (CANMSGOBJINFO_ST*)   t_Interface_P
;     | ST->CanChannelTable_PST;                                               
;----------------------------------------------------------------------
        LDR       A3, [A1, #4]          ; |377| 
        STR       A3, [A2, #4]          ; |377| 
;** 378	-----------------------    C$1->QuarzClockFrequency_UL = *t_Interface_PST->QuarzClockFrequency_PUL;
	.dwpsn	"ADLATUS_CanHandler.c",378,3
;----------------------------------------------------------------------
; 378 | CanCtrl_ST.QuarzClockFrequency_UL =                      *t_Interface_P
;     | ST->QuarzClockFrequency_PUL;                                           
;----------------------------------------------------------------------
        LDR       A3, [A1, #8]          ; |378| 
        LDR       A3, [A3, #0]          ; |378| 
        STR       A3, [A2, #8]          ; |378| 
;** 379	-----------------------    C$1->CanNode_UW = *t_Interface_PST->CanNode_PUW;
	.dwpsn	"ADLATUS_CanHandler.c",379,3
;----------------------------------------------------------------------
; 379 | CanCtrl_ST.CanNode_UW             =                      *t_Interface_P
;     | ST->CanNode_PUW;                                                       
;----------------------------------------------------------------------
        LDR       A3, [A1, #12]         ; |379| 
        LDRH      A3, [A3, #0]          ; |379| 
        STRH      A3, [A2, #12]         ; |379| 
;** 380	-----------------------    C$1->DefaultBaudrate_UB = *t_Interface_PST->DefaultBaudrate_PUW;
	.dwpsn	"ADLATUS_CanHandler.c",380,3
;----------------------------------------------------------------------
; 380 | CanCtrl_ST.DefaultBaudrate_UB     =  (UBYTE)             *t_Interface_P
;     | ST->DefaultBaudrate_PUW;                                               
;----------------------------------------------------------------------
        LDR       A3, [A1, #16]         ; |380| 
        LDRB      A3, [A3, #1]          ; |380| 
        STRB      A3, [A2, #14]         ; |380| 
;** 381	-----------------------    C$1->SelectedChannel_UB = 15u;
	.dwpsn	"ADLATUS_CanHandler.c",381,3
;----------------------------------------------------------------------
; 381 | CanCtrl_ST.SelectedChannel_UB     =                       d_CCglo_AllCh
;     | annels;                                                                
;----------------------------------------------------------------------
        MOV       A3, #15               ; |381| 
        STRB      A3, [A2, #15]         ; |381| 
;** 383	-----------------------    C$1->RepeatCounter_UB = 0u;
	.dwpsn	"ADLATUS_CanHandler.c",383,3
;----------------------------------------------------------------------
; 383 | CanCtrl_ST.RepeatCounter_UB       = d_CCcan_InitState;                 
;----------------------------------------------------------------------
        MOV       A3, #0                ; |383| 
        STRB      A3, [A2, #17]         ; |383| 
;** 384	-----------------------    C$1->MbUsedinRAM_UB = 0xffu;
	.dwpsn	"ADLATUS_CanHandler.c",384,3
;----------------------------------------------------------------------
; 384 | CanCtrl_ST.MbUsedinRAM_UB         = d_CCcan_NoMbforRamDefined;         
; 386 | #if defined (cs_CCTP20)                                                
; 389 | CanCtrl_ST.CCTP20_Subset_UB = 0u;                                      
; 390 | CanCtrl_ST.CCTP20_Status_UB = 0u;                                      
; 392 | FUN_CCcanInitTP20Data_V ();                                            
; 394 | #elif defined (cs_CCISO)                                               
; 395 | #if defined (cs_CCUDS_Audi)                                            
;----------------------------------------------------------------------
        MOV       A3, #255              ; |384| 
        STRB      A3, [A2, #16]         ; |384| 
;** 396	-----------------------    C$1->DiagResponseTG_PST = t_Interface_PST->DiagResponseTG_PST;
	.dwpsn	"ADLATUS_CanHandler.c",396,3
;----------------------------------------------------------------------
; 396 | CanCtrl_ST.DiagResponseTG_PST     = (DIAGRESPONSETG_ST*)  t_Interface_P
;     | ST->DiagResponseTG_PST;                                                
; 397 | #endif                                                                 
; 398 | #else                                                                  
; 399 | #error (undefined transport layer)                                     
; 400 | #endif                                                                 
;----------------------------------------------------------------------
        LDR       A1, [A1, #20]         ; |396| 
        STR       A1, [A2, #28]         ; |396| 
;** 406	-----------------------    FUN_CCcan_InitCanController_V();
	.dwpsn	"ADLATUS_CanHandler.c",406,3
;----------------------------------------------------------------------
; 406 | FUN_CCcan_InitCanController_V ();                                      
;----------------------------------------------------------------------
        BL        $FUN_CCcan_InitCanController_V ; |406| 
        ; |406| 
;** 408	-----------------------    return;
	.dwpsn	"ADLATUS_CanHandler.c",408,3
;----------------------------------------------------------------------
; 408 | return;                                                                
;----------------------------------------------------------------------
	.dwpsn	"ADLATUS_CanHandler.c",410,1
	.dwcfa	0x0e, 4
        POP       {PC}
	.dwendentry
	.dwendtag DW$50




	.sect	".text:v$5"
	.clink
	.global	_FUN_CCcan_InitCanController_V

DW$54	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_InitCanController_V"), DW_AT_symbol_name("_FUN_CCcan_InitCanController_V")
	.dwattr DW$54, DW_AT_veneer(0x01)
	.dwattr DW$54, DW_AT_low_pc(_FUN_CCcan_InitCanController_V)
	.dwattr DW$54, DW_AT_high_pc(0x00)
	.dwattr DW$54, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CCcan_InitCanController_V                           *
;*****************************************************************************
_FUN_CCcan_InitCanController_V:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $FUN_CCcan_InitCanController_V
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$54



	.sect	".text"
	.clink
	.global	$FUN_CCcan_InitCanController_V

DW$55	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_InitCanController_V"), DW_AT_symbol_name("$FUN_CCcan_InitCanController_V")
	.dwattr DW$55, DW_AT_low_pc($FUN_CCcan_InitCanController_V)
	.dwattr DW$55, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_CanHandler.c",429,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 428 | void  FUN_CCcan_InitCanController_V(void)                              
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CCcan_InitCanController_V                              *
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
$FUN_CCcan_InitCanController_V:
;* --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 430 | UBYTE t_MsgObjCounter_UB;                                              
; 431 | UBYTE t_BufferNbr_UB;                                                  
;----------------------------------------------------------------------
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
;* A1    assigned to C$1
DW$56	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$56, DW_AT_type(*DWT$1041)
	.dwattr DW$56, DW_AT_location[DW_OP_reg0]
;* A1    assigned to C$2
DW$57	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$57, DW_AT_type(*DWT$1084)
	.dwattr DW$57, DW_AT_location[DW_OP_reg0]
;* V1    assigned to C$3
DW$58	.dwtag  DW_TAG_variable, DW_AT_name("C$3"), DW_AT_symbol_name("C$3")
	.dwattr DW$58, DW_AT_type(*DWT$1185)
	.dwattr DW$58, DW_AT_location[DW_OP_reg4]
;* A3    assigned to C$4
DW$59	.dwtag  DW_TAG_variable, DW_AT_name("C$4"), DW_AT_symbol_name("C$4")
	.dwattr DW$59, DW_AT_type(*DWT$1137)
	.dwattr DW$59, DW_AT_location[DW_OP_reg2]
;* V2    assigned to C$5
DW$60	.dwtag  DW_TAG_variable, DW_AT_name("C$5"), DW_AT_symbol_name("C$5")
	.dwattr DW$60, DW_AT_type(*DWT$10)
	.dwattr DW$60, DW_AT_location[DW_OP_reg5]
;* A1    assigned to C$6
DW$61	.dwtag  DW_TAG_variable, DW_AT_name("C$6"), DW_AT_symbol_name("C$6")
	.dwattr DW$61, DW_AT_type(*DWT$1040)
	.dwattr DW$61, DW_AT_location[DW_OP_reg0]
;* A4    assigned to C$7
DW$62	.dwtag  DW_TAG_variable, DW_AT_name("C$7"), DW_AT_symbol_name("C$7")
	.dwattr DW$62, DW_AT_type(*DWT$10)
	.dwattr DW$62, DW_AT_location[DW_OP_reg3]
;* V3    assigned to Q$1
DW$63	.dwtag  DW_TAG_variable, DW_AT_name("Q$1"), DW_AT_symbol_name("Q$1")
	.dwattr DW$63, DW_AT_type(*DWT$1185)
	.dwattr DW$63, DW_AT_location[DW_OP_reg6]
;* A1    assigned to Q$2
DW$64	.dwtag  DW_TAG_variable, DW_AT_name("Q$2"), DW_AT_symbol_name("Q$2")
	.dwattr DW$64, DW_AT_type(*DWT$11)
	.dwattr DW$64, DW_AT_location[DW_OP_reg0]
;* A1    assigned to Q$3
DW$65	.dwtag  DW_TAG_variable, DW_AT_name("Q$3"), DW_AT_symbol_name("Q$3")
	.dwattr DW$65, DW_AT_type(*DWT$11)
	.dwattr DW$65, DW_AT_location[DW_OP_reg0]
;* V4    assigned to _t_MsgObjCounter_UB
DW$66	.dwtag  DW_TAG_variable, DW_AT_name("t_MsgObjCounter_UB"), DW_AT_symbol_name("_t_MsgObjCounter_UB")
	.dwattr DW$66, DW_AT_type(*DWT$1018)
	.dwattr DW$66, DW_AT_location[DW_OP_reg7]
;* A1    assigned to K$1
DW$67	.dwtag  DW_TAG_variable, DW_AT_name("K$1"), DW_AT_symbol_name("K$1")
	.dwattr DW$67, DW_AT_type(*DWT$1129)
	.dwattr DW$67, DW_AT_location[DW_OP_reg0]
;* A1    assigned to U$56
DW$68	.dwtag  DW_TAG_variable, DW_AT_name("U$56"), DW_AT_symbol_name("U$56")
	.dwattr DW$68, DW_AT_type(*DWT$1041)
	.dwattr DW$68, DW_AT_location[DW_OP_reg0]
;* V2    assigned to K$52
DW$69	.dwtag  DW_TAG_variable, DW_AT_name("K$52"), DW_AT_symbol_name("K$52")
	.dwattr DW$69, DW_AT_type(*DWT$11)
	.dwattr DW$69, DW_AT_location[DW_OP_reg5]
;* V1    assigned to K$14
DW$70	.dwtag  DW_TAG_variable, DW_AT_name("K$14"), DW_AT_symbol_name("K$14")
	.dwattr DW$70, DW_AT_type(*DWT$1184)
	.dwattr DW$70, DW_AT_location[DW_OP_reg4]
;* A1    assigned to U$45
DW$71	.dwtag  DW_TAG_variable, DW_AT_name("U$45"), DW_AT_symbol_name("U$45")
	.dwattr DW$71, DW_AT_type(*DWT$1080)
	.dwattr DW$71, DW_AT_location[DW_OP_reg0]
;** 434	-----------------------    FUN_CCcan_Wait_V();
	.dwpsn	"ADLATUS_CanHandler.c",434,4
;----------------------------------------------------------------------
; 434 | FUN_CCcan_Wait_V();                                                    
;----------------------------------------------------------------------
        BL        $FUN_CCcan_Wait_V     ; |434| 
        ; |434| 
;** 437	-----------------------    C$4 = &e_SCC_ST;
	.dwpsn	"ADLATUS_CanHandler.c",437,4
;----------------------------------------------------------------------
; 437 | e_SCC_ST.CANTIOC_UN.CANTIOC_ST.TXFUNC_B1 = 1u;                         
;----------------------------------------------------------------------
        LDR       A1, CON2              ; |437| 
        MOV       A3, A1
;** 437	-----------------------    C$6 = &((volatile unsigned char *)C$4)[87];
        MOV       A1, #87               ; |437| 
        ADD       A1, A1, A3            ; |437| 
;** 437	-----------------------    *C$6 |= C$7 = 8u;
        MOV       A4, #8                ; |437| 
        LDRB      A2, [A1, #0]          ; |437| 
        ORR       A2, A4                ; |437| 
        STRB      A2, [A1, #0]          ; |437| 
;** 439	-----------------------    C$6[4] |= C$7;
	.dwpsn	"ADLATUS_CanHandler.c",439,4
;----------------------------------------------------------------------
; 439 | e_SCC_ST.CANRIOC_UN.CANRIOC_ST.RXFUNC_B1 = 1u;                         
;----------------------------------------------------------------------
        LDRB      A2, [A1, #4]          ; |439| 
        ORR       A2, A4                ; |439| 
        STRB      A2, [A1, #4]          ; |439| 
;** 442	-----------------------    *((volatile struct $$fake0 *)C$4+(Q$2 = 42)) |= 0x10u;
	.dwpsn	"ADLATUS_CanHandler.c",442,4
;----------------------------------------------------------------------
; 442 | e_SCC_ST.CANMC_UN.CANMC_ST.CCR_B1 = 1u;                                
;----------------------------------------------------------------------
        MOV       A1, #42               ; |442| 
        ADD       A2, A1, A3            ; |442| 
        LDRB      A4, [A2, #0]          ; |442| 
        MOV       A1, #16               ; |442| 
        ORR       A1, A4                ; |442| 
        STRB      A1, [A2, #0]          ; |442| 
;** 445	-----------------------    FUN_CCcan_Waitconf_V();
	.dwpsn	"ADLATUS_CanHandler.c",445,4
;----------------------------------------------------------------------
; 445 | FUN_CCcan_Waitconf_V();                                                
;----------------------------------------------------------------------
        BL        $FUN_CCcan_Waitconf_V ; |445| 
        ; |445| 
;** 448	-----------------------    *((volatile struct $$fake0 *)C$4+(Q$3 = 43)) |= 0x20u;
	.dwpsn	"ADLATUS_CanHandler.c",448,4
;----------------------------------------------------------------------
; 448 | e_SCC_ST.CANMC_UN.CANMC_ST.SRES_B1 = 1u;                               
;----------------------------------------------------------------------
        MOV       A1, #43               ; |448| 
        ADD       A2, A1, A3            ; |448| 
        LDRB      A4, [A2, #0]          ; |448| 
        MOV       A1, #32               ; |448| 
        ORR       A1, A4                ; |448| 
        STRB      A1, [A2, #0]          ; |448| 
;** 451	-----------------------    C$3 = &CanCtrl_ST;
	.dwpsn	"ADLATUS_CanHandler.c",451,4
;----------------------------------------------------------------------
; 451 | e_SCC_ST.CANBTC_UL = c_CCcan_BaudrateTable_AUL[CanCtrl_ST.DefaultBaudra
;     | te_UB];                                                                
;----------------------------------------------------------------------
        LDR       V1, CON5              ; |451| 
;** 451	-----------------------    Q$1 = C$3+32;
        MOV       A1, #32               ; |451| 
        ADD       V3, A1, V1            ; |451| 
;** 451	-----------------------    ((volatile struct _scc_st *)C$4)->CANBTC_UL = c_CCcan_BaudrateTable_AUL[C$3->DefaultBaudrate_UB];
        LDRB      A1, [V1, #14]         ; |451| 
        LSL       A1, A1, #2            ; |451| 
        LDR       A2, CON6              ; |451| 
        LDR       A1, [A2, A1]          ; |451| 
        STR       A1, [A3, #44]         ; |451| 
;** 454	-----------------------    ((volatile struct _scc_st *)C$4)->CANMC_UN.CANMC_UW = 4224;
	.dwpsn	"ADLATUS_CanHandler.c",454,4
;----------------------------------------------------------------------
; 454 | e_SCC_ST.CANMC_UN.CANMC_UW  = 0x1080u;                                 
;----------------------------------------------------------------------
        MOV       A1, #33
        LSL       A1, A1, #7
        STRH      A1, [A3, #42]         ; |454| 
;** 457	-----------------------    ((volatile struct _scc_st *)C$4)->CANMIM_UL = C$5 = 0u;
	.dwpsn	"ADLATUS_CanHandler.c",457,4
;----------------------------------------------------------------------
; 457 | e_SCC_ST.CANMIM_UL = 0;                                                
;----------------------------------------------------------------------
        MOV       V2, #0                ; |457| 
        STR       V2, [A3, #72]         ; |457| 
;** 461	-----------------------    ((volatile struct _scc_st *)C$4)->CANGAM_UL = C$5;
	.dwpsn	"ADLATUS_CanHandler.c",461,4
;----------------------------------------------------------------------
; 461 | e_SCC_ST.CANGAM_UL = 0x00000000ul;                                     
;----------------------------------------------------------------------
        STR       V2, [A3, #36]         ; |461| 
;** 463	-----------------------    ((volatile struct _scc_st *)C$4)->CANME_UL = C$5;
	.dwpsn	"ADLATUS_CanHandler.c",463,4
;----------------------------------------------------------------------
; 463 | e_SCC_ST.CANME_UL = 0x00000000u;                                       
;----------------------------------------------------------------------
        STR       V2, [A3, #0]          ; |463| 
;** 466	-----------------------    ((volatile struct _scc_st *)C$4)->CANMD_UL = 0xffffffffu;
	.dwpsn	"ADLATUS_CanHandler.c",466,4
;----------------------------------------------------------------------
; 466 | e_SCC_ST.CANMD_UL = 0xFFFFFFFFul;                                      
; 473 | t_MsgObjCounter_UB =  0x00;                                            
;----------------------------------------------------------------------
        MOV       A1, #0                ; |466| 
        MVN       A1, A1                ; |466| 
        STR       A1, [A3, #4]          ; |466| 
;** 451	-----------------------    K$14 = C$3;
	.dwpsn	"ADLATUS_CanHandler.c",451,4
;** 478	-----------------------    C$2 = K$14->CanMsgObjConfig_PST;
	.dwpsn	"ADLATUS_CanHandler.c",478,3
;----------------------------------------------------------------------
; 478 | while ( d_CCglo_NoEntry != CanCtrl_ST.CanMsgObjConfig_PST[t_MsgObjCount
;     | er_UB].MsgObjectNbr_UB  )                                              
;----------------------------------------------------------------------
        LDR       A1, [V1, #0]          ; |478| 
;** 478	-----------------------    if ( C$2->MsgObjectNbr_UB == 255 ) goto g4;
        LDRB      A2, [A1, #0]          ; |478| 
        CMP       A2, #255              ; |478| 
        BEQ       L10                   ; |478| 
        ; |478| 
;* --------------------------------------------------------------------------*
;**  	-----------------------    #pragma LOOP_FLAGS(5120u)
;**  	-----------------------    U$45 = C$2;
;** 473	-----------------------    t_MsgObjCounter_UB = 0u;
	.dwpsn	"ADLATUS_CanHandler.c",473,3
        MOV       V4, V2
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L9
;*
;*   Loop source line                : 478
;*   Loop closing brace source line  : 484
;*   Known Minimum Trip Count        : 4
;*   Known Maximum Trip Count        : 4
;*   Known Max Trip Count Factor     : 4
;* --------------------------------------------------------------------------*
L9:    
DWL$$FUN_CCcan_InitCanController_V$3$B:
;**	-----------------------g3:
;** 481	-----------------------    FUN_CCcan_InitCanMsgObj_V(U$45, 0u);
	.dwpsn	"ADLATUS_CanHandler.c",481,5
;----------------------------------------------------------------------
; 481 | FUN_CCcan_InitCanMsgObj_V( &CanCtrl_ST.CanMsgObjConfig_PST[t_MsgObjCoun
;     | ter_UB], \                                                             
; 482 |                            (UWORD) 0u );                               
;----------------------------------------------------------------------
        MOV       A2, V2
        BL        $FUN_CCcan_InitCanMsgObj_V ; |481| 
        ; |481| 
;** 483	-----------------------    U$45 = (++t_MsgObjCounter_UB)*12+K$14->CanMsgObjConfig_PST;
	.dwpsn	"ADLATUS_CanHandler.c",483,5
;----------------------------------------------------------------------
; 483 | t_MsgObjCounter_UB++;                                                  
;----------------------------------------------------------------------
        ADD       A1, V4, #1            ; |483| 
        LSL       V4, A1, #24           ; |437| 
        LSR       V4, V4, #24           ; |437| 
        MOV       A1, #12               ; |483| 
        MUL       A1, V4                ; |483| 
        LDR       A2, [V1, #0]          ; |483| 
        ADD       A1, A2, A1            ; |483| 
;** 483	-----------------------    if ( U$45->MsgObjectNbr_UB != 255 ) goto g3;
        LDRB      A2, [A1, #0]          ; |483| 
        CMP       A2, #255              ; |483| 
        BNE       L9                    ; |483| 
        ; |483| 
DWL$$FUN_CCcan_InitCanController_V$3$E:
;* --------------------------------------------------------------------------*
L10:    
;**	-----------------------g4:
;**  	-----------------------    #pragma MUST_ITERATE(4, 4, 4)
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;** 489	-----------------------    C$1 = &t_CCcan_CanFifoBuffer_AUB[0];
	.dwpsn	"ADLATUS_CanHandler.c",489,8
;----------------------------------------------------------------------
; 489 | for (t_BufferNbr_UB = 0x00u; t_BufferNbr_UB < d_CCcan_NbrOfInternalCanB
;     | uffer; t_BufferNbr_UB++ )                                              
; 492 |   t_CCcan_CanFifoBuffer_AUB[t_BufferNbr_UB][d_CCglo_BufferState] = 0x00
;     | u;                                                                     
;----------------------------------------------------------------------
        LDR       A1, CON8              ; |489| 
;** 489	-----------------------    *C$1 = K$52 = 0;
        STRB      V2, [A1, #0]          ; |489| 
;** 493	-----------------------    U$56 = &C$1[12];
	.dwpsn	"ADLATUS_CanHandler.c",493,3
        ADD       A1, #12               ; |493| 
;** 492	-----------------------    *U$56 = K$52;
	.dwpsn	"ADLATUS_CanHandler.c",492,5
        STRB      V2, [A1, #0]          ; |492| 
;** 492	-----------------------    *(U$56 += 12) = K$52;
        STRB      V2, [A1, #12]         ; |492| 
        ADD       A1, #12               ; |492| 
;** 492	-----------------------    *(U$56 += 12) = K$52;
        STRB      V2, [A1, #12]         ; |492| 
;** 493	-----------------------    *((unsigned char *)Q$1+1) = K$52;
	.dwpsn	"ADLATUS_CanHandler.c",493,3
;----------------------------------------------------------------------
; 498 | CanCtrl_ST.ReadIndex_AUB  = 0x00u;                                     
;----------------------------------------------------------------------
        STRB      V2, [V3, #1]          ; |493| 
;** 499	-----------------------    *(unsigned char *)Q$1 = K$52;
	.dwpsn	"ADLATUS_CanHandler.c",499,3
;----------------------------------------------------------------------
; 499 | CanCtrl_ST.WriteIndex_AUB = 0x00u;                                     
;----------------------------------------------------------------------
        STRB      V2, [V3, #0]          ; |499| 
;** 504	-----------------------    K$14->SelectedChannel_UB = 15;
	.dwpsn	"ADLATUS_CanHandler.c",504,3
;----------------------------------------------------------------------
; 504 | CanCtrl_ST.SelectedChannel_UB =  d_CCglo_AllChannels;                  
;----------------------------------------------------------------------
        MOV       A1, #15               ; |504| 
        STRB      A1, [V1, #15]         ; |504| 
;** 437	-----------------------    K$1 = &e_SCC_ST;
	.dwpsn	"ADLATUS_CanHandler.c",437,4
        LDR       A1, CON2              ; |437| 
;** 507	-----------------------    ((volatile unsigned char *)K$1)[Q$2] &= 0xefu;
	.dwpsn	"ADLATUS_CanHandler.c",507,4
;----------------------------------------------------------------------
; 507 | e_SCC_ST.CANMC_UN.CANMC_ST.CCR_B1 = 0u;                                
;----------------------------------------------------------------------
        MOV       A2, #42               ; |442| 
        LDRB      A3, [A2, A1]          ; |507| 
        MOV       A2, #239              ; |507| 
        AND       A2, A3                ; |507| 
        MOV       A3, #42               ; |442| 
        STRB      A2, [A3, A1]          ; |507| 
;** 510	-----------------------    FUN_CCcan_Waitconfx_V();
	.dwpsn	"ADLATUS_CanHandler.c",510,4
;----------------------------------------------------------------------
; 510 | FUN_CCcan_Waitconfx_V();                                               
;----------------------------------------------------------------------
        BL        $FUN_CCcan_Waitconfx_V ; |510| 
        ; |510| 
;** 512	-----------------------    return;
	.dwpsn	"ADLATUS_CanHandler.c",512,3
;----------------------------------------------------------------------
; 512 | return;                                                                
;----------------------------------------------------------------------
	.dwpsn	"ADLATUS_CanHandler.c",513,1
	.dwcfa	0x0e, 20
        POP       {V1, V2, V3, V4, PC}

DW$72	.dwtag  DW_TAG_loop
	.dwattr DW$72, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L9:1:1323432538")
	.dwattr DW$72, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$72, DW_AT_begin_line(0x1de)
	.dwattr DW$72, DW_AT_end_line(0x1e4)
DW$73	.dwtag  DW_TAG_loop_range
	.dwattr DW$73, DW_AT_low_pc(DWL$$FUN_CCcan_InitCanController_V$3$B)
	.dwattr DW$73, DW_AT_high_pc(DWL$$FUN_CCcan_InitCanController_V$3$E)
	.dwendtag DW$72

	.dwendentry
	.dwendtag DW$55




	.sect	".text:v$6"
	.clink
	.global	_FUN_CCcan_StopCanController_V

DW$74	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_StopCanController_V"), DW_AT_symbol_name("_FUN_CCcan_StopCanController_V")
	.dwattr DW$74, DW_AT_veneer(0x01)
	.dwattr DW$74, DW_AT_low_pc(_FUN_CCcan_StopCanController_V)
	.dwattr DW$74, DW_AT_high_pc(0x00)
	.dwattr DW$74, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CCcan_StopCanController_V                           *
;*****************************************************************************
_FUN_CCcan_StopCanController_V:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FUN_CCcan_StopCanController_V+1, 32
	.state16
	.dwendtag DW$74



	.sect	".text"
	.clink
	.global	$FUN_CCcan_StopCanController_V

DW$75	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_StopCanController_V"), DW_AT_symbol_name("$FUN_CCcan_StopCanController_V")
	.dwattr DW$75, DW_AT_low_pc($FUN_CCcan_StopCanController_V)
	.dwattr DW$75, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_CanHandler.c",531,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 530 | void  FUN_CCcan_StopCanController_V ( void )                           
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CCcan_StopCanController_V                              *
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
$FUN_CCcan_StopCanController_V:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
;** 533	-----------------------    return;
	.dwpsn	"ADLATUS_CanHandler.c",533,3
;----------------------------------------------------------------------
; 533 | return;                                                                
;----------------------------------------------------------------------
	.dwpsn	"ADLATUS_CanHandler.c",535,1
        BX        LR
	.dwendentry
	.dwendtag DW$75




	.sect	".text:v$7"
	.clink
	.global	_FUN_CCcan_StartCanController_V

DW$76	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_StartCanController_V"), DW_AT_symbol_name("_FUN_CCcan_StartCanController_V")
	.dwattr DW$76, DW_AT_veneer(0x01)
	.dwattr DW$76, DW_AT_low_pc(_FUN_CCcan_StartCanController_V)
	.dwattr DW$76, DW_AT_high_pc(0x00)
	.dwattr DW$76, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CCcan_StartCanController_V                          *
;*****************************************************************************
_FUN_CCcan_StartCanController_V:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FUN_CCcan_StartCanController_V+1, 32
	.state16
	.dwendtag DW$76



	.sect	".text"
	.clink
	.global	$FUN_CCcan_StartCanController_V

DW$77	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_StartCanController_V"), DW_AT_symbol_name("$FUN_CCcan_StartCanController_V")
	.dwattr DW$77, DW_AT_low_pc($FUN_CCcan_StartCanController_V)
	.dwattr DW$77, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_CanHandler.c",554,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 553 | void  FUN_CCcan_StartCanController_V (void)                            
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CCcan_StartCanController_V                             *
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
$FUN_CCcan_StartCanController_V:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
;** 555	-----------------------    return;
	.dwpsn	"ADLATUS_CanHandler.c",555,3
;----------------------------------------------------------------------
; 555 | return;                                                                
;----------------------------------------------------------------------
	.dwpsn	"ADLATUS_CanHandler.c",557,1
        BX        LR
	.dwendentry
	.dwendtag DW$77




	.sect	".text:v$8"
	.clink
	.global	_FUN_CCcan_ActivateCanMsgObj_V

DW$78	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_ActivateCanMsgObj_V"), DW_AT_symbol_name("_FUN_CCcan_ActivateCanMsgObj_V")
	.dwattr DW$78, DW_AT_veneer(0x01)
	.dwattr DW$78, DW_AT_low_pc(_FUN_CCcan_ActivateCanMsgObj_V)
	.dwattr DW$78, DW_AT_high_pc(0x00)
	.dwattr DW$78, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CCcan_ActivateCanMsgObj_V                           *
;*****************************************************************************
_FUN_CCcan_ActivateCanMsgObj_V:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $FUN_CCcan_ActivateCanMsgObj_V
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$78



	.sect	".text"
	.clink
	.global	$FUN_CCcan_ActivateCanMsgObj_V

DW$79	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_ActivateCanMsgObj_V"), DW_AT_symbol_name("$FUN_CCcan_ActivateCanMsgObj_V")
	.dwattr DW$79, DW_AT_low_pc($FUN_CCcan_ActivateCanMsgObj_V)
	.dwattr DW$79, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_CanHandler.c",576,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 575 | void  FUN_CCcan_ActivateCanMsgObj_V( UBYTE t_MsgObjNbr_UB )            
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CCcan_ActivateCanMsgObj_V                              *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V9,SP,LR,SR                             *
;*   Regs Used         : A1,A2,A3,A4,V9,SP,LR,SR                             *
;*   Local Frame Size  : 0 Args + 0 Auto + 4 Save = 4 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CCcan_ActivateCanMsgObj_V:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
        PUSH      {LR}
	.dwcfa	0x0e, 4
	.dwcfa	0x80, 14, 1
	.dwcfa	0x0e, 4
;* A1    assigned to _t_MsgObjNbr_UB
DW$80	.dwtag  DW_TAG_formal_parameter, DW_AT_name("t_MsgObjNbr_UB"), DW_AT_symbol_name("_t_MsgObjNbr_UB")
	.dwattr DW$80, DW_AT_type(*DWT$1018)
	.dwattr DW$80, DW_AT_location[DW_OP_reg0]
;* A1    assigned to C$1
DW$81	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$81, DW_AT_type(*DWT$1084)
	.dwattr DW$81, DW_AT_location[DW_OP_reg0]
;* A1    assigned to _t_MsgObjNbr_UB
DW$82	.dwtag  DW_TAG_variable, DW_AT_name("t_MsgObjNbr_UB"), DW_AT_symbol_name("_t_MsgObjNbr_UB")
	.dwattr DW$82, DW_AT_type(*DWT$1026)
	.dwattr DW$82, DW_AT_location[DW_OP_reg0]
;** 578	-----------------------    C$1 = t_MsgObjNbr_UB*12+CanCtrl_ST.CanMsgObjConfig_PST;
	.dwpsn	"ADLATUS_CanHandler.c",578,3
;----------------------------------------------------------------------
; 578 | CanCtrl_ST.CanMsgObjConfig_PST[t_MsgObjNbr_UB].MsgObjState_UB = d_CCcan
;     | _Activate;                                                             
;----------------------------------------------------------------------
        MOV       A2, #12               ; |578| 
        MUL       A2, A1                ; |578| 
        LDR       A1, CON5              ; |578| 
        LDR       A1, [A1, #0]          ; |578| 
        ADD       A1, A1, A2            ; |578| 
;** 578	-----------------------    C$1->MsgObjState_UB = 1u;
        MOV       A2, #1                ; |578| 
        STRB      A2, [A1, #1]          ; |578| 
;** 580	-----------------------    FUN_CCcan_InitCanMsgObj_V(C$1, 0u);
	.dwpsn	"ADLATUS_CanHandler.c",580,3
;----------------------------------------------------------------------
; 580 | FUN_CCcan_InitCanMsgObj_V(&CanCtrl_ST.CanMsgObjConfig_PST[t_MsgObjNbr_U
;     | B], \                                                                  
; 581 |                              (UWORD) 0u );                             
;----------------------------------------------------------------------
        MOV       A2, #0                ; |580| 
        BL        $FUN_CCcan_InitCanMsgObj_V ; |580| 
        ; |580| 
;** 583	-----------------------    return;
	.dwpsn	"ADLATUS_CanHandler.c",583,2
;----------------------------------------------------------------------
; 583 | return;                                                                
;----------------------------------------------------------------------
	.dwpsn	"ADLATUS_CanHandler.c",585,1
	.dwcfa	0x0e, 4
        POP       {PC}
	.dwendentry
	.dwendtag DW$79




	.sect	".text:v$9"
	.clink
	.global	_FUN_CCcan_DeactivateCanMsgObj_V

DW$83	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_DeactivateCanMsgObj_V"), DW_AT_symbol_name("_FUN_CCcan_DeactivateCanMsgObj_V")
	.dwattr DW$83, DW_AT_veneer(0x01)
	.dwattr DW$83, DW_AT_low_pc(_FUN_CCcan_DeactivateCanMsgObj_V)
	.dwattr DW$83, DW_AT_high_pc(0x00)
	.dwattr DW$83, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CCcan_DeactivateCanMsgObj_V                         *
;*****************************************************************************
_FUN_CCcan_DeactivateCanMsgObj_V:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $FUN_CCcan_DeactivateCanMsgObj_V
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$83



	.sect	".text"
	.clink
	.global	$FUN_CCcan_DeactivateCanMsgObj_V

DW$84	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_DeactivateCanMsgObj_V"), DW_AT_symbol_name("$FUN_CCcan_DeactivateCanMsgObj_V")
	.dwattr DW$84, DW_AT_low_pc($FUN_CCcan_DeactivateCanMsgObj_V)
	.dwattr DW$84, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_CanHandler.c",607,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 606 | void  FUN_CCcan_DeactivateCanMsgObj_V(UBYTE t_MsgObjNbr_UB )           
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CCcan_DeactivateCanMsgObj_V                            *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V9,SP,LR,SR                             *
;*   Regs Used         : A1,A2,A3,A4,V9,SP,LR,SR                             *
;*   Local Frame Size  : 0 Args + 0 Auto + 4 Save = 4 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CCcan_DeactivateCanMsgObj_V:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
        PUSH      {LR}
	.dwcfa	0x0e, 4
	.dwcfa	0x80, 14, 1
	.dwcfa	0x0e, 4
;* A1    assigned to _t_MsgObjNbr_UB
DW$85	.dwtag  DW_TAG_formal_parameter, DW_AT_name("t_MsgObjNbr_UB"), DW_AT_symbol_name("_t_MsgObjNbr_UB")
	.dwattr DW$85, DW_AT_type(*DWT$1018)
	.dwattr DW$85, DW_AT_location[DW_OP_reg0]
;* A1    assigned to C$1
DW$86	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$86, DW_AT_type(*DWT$1084)
	.dwattr DW$86, DW_AT_location[DW_OP_reg0]
;* A1    assigned to _t_MsgObjNbr_UB
DW$87	.dwtag  DW_TAG_variable, DW_AT_name("t_MsgObjNbr_UB"), DW_AT_symbol_name("_t_MsgObjNbr_UB")
	.dwattr DW$87, DW_AT_type(*DWT$1026)
	.dwattr DW$87, DW_AT_location[DW_OP_reg0]
;** 608	-----------------------    C$1 = t_MsgObjNbr_UB*12+CanCtrl_ST.CanMsgObjConfig_PST;
	.dwpsn	"ADLATUS_CanHandler.c",608,3
;----------------------------------------------------------------------
; 608 | CanCtrl_ST.CanMsgObjConfig_PST[t_MsgObjNbr_UB].MsgObjState_UB = d_CCcan
;     | _Deactivate;                                                           
;----------------------------------------------------------------------
        MOV       A2, #12               ; |608| 
        MUL       A2, A1                ; |608| 
        LDR       A1, CON5              ; |608| 
        LDR       A1, [A1, #0]          ; |608| 
        ADD       A1, A1, A2            ; |608| 
;** 608	-----------------------    C$1->MsgObjState_UB = 0u;
        MOV       A2, #0                ; |608| 
        STRB      A2, [A1, #1]          ; |608| 
;** 610	-----------------------    FUN_CCcan_InitCanMsgObj_V(C$1, 0u);
	.dwpsn	"ADLATUS_CanHandler.c",610,3
;----------------------------------------------------------------------
; 610 | FUN_CCcan_InitCanMsgObj_V(&CanCtrl_ST.CanMsgObjConfig_PST[t_MsgObjNbr_U
;     | B], \                                                                  
; 611 |                              (UWORD) 0u );                             
;----------------------------------------------------------------------
        BL        $FUN_CCcan_InitCanMsgObj_V ; |610| 
        ; |610| 
;** 613	-----------------------    return;
	.dwpsn	"ADLATUS_CanHandler.c",613,3
;----------------------------------------------------------------------
; 613 | return;                                                                
;----------------------------------------------------------------------
	.dwpsn	"ADLATUS_CanHandler.c",615,1
	.dwcfa	0x0e, 4
        POP       {PC}
	.dwendentry
	.dwendtag DW$84




	.sect	".text:v$10"
	.clink
	.global	_FUN_CCcan_InitCanMsgObj_V

DW$88	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_InitCanMsgObj_V"), DW_AT_symbol_name("_FUN_CCcan_InitCanMsgObj_V")
	.dwattr DW$88, DW_AT_veneer(0x01)
	.dwattr DW$88, DW_AT_low_pc(_FUN_CCcan_InitCanMsgObj_V)
	.dwattr DW$88, DW_AT_high_pc(0x00)
	.dwattr DW$88, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CCcan_InitCanMsgObj_V                               *
;*****************************************************************************
_FUN_CCcan_InitCanMsgObj_V:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $FUN_CCcan_InitCanMsgObj_V
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$88



	.sect	".text"
	.clink
	.global	$FUN_CCcan_InitCanMsgObj_V

DW$89	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_InitCanMsgObj_V"), DW_AT_symbol_name("$FUN_CCcan_InitCanMsgObj_V")
	.dwattr DW$89, DW_AT_low_pc($FUN_CCcan_InitCanMsgObj_V)
	.dwattr DW$89, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_CanHandler.c",637,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 635 | void  FUN_CCcan_InitCanMsgObj_V( CANMSGOBJCONFIG_ST *CanMsgObjConfig_PS
;     | T, \                                                                   
; 636 | UWORD t_CanNode_UW )                                                   
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CCcan_InitCanMsgObj_V                                  *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V1,V2,SP,SR                             *
;*   Regs Used         : A1,A2,A3,A4,V1,V2,SP,LR,SR                          *
;*   Local Frame Size  : 0 Args + 0 Auto + 12 Save = 12 byte                 *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CCcan_InitCanMsgObj_V:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
        PUSH      {V1, V2, LR}
	.dwcfa	0x0e, 4
	.dwcfa	0x80, 14, 1
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 5, 2
	.dwcfa	0x0e, 12
	.dwcfa	0x80, 4, 3
	.dwcfa	0x0e, 12
;* A1    assigned to _CanMsgObjConfig_PST
DW$90	.dwtag  DW_TAG_formal_parameter, DW_AT_name("CanMsgObjConfig_PST"), DW_AT_symbol_name("_CanMsgObjConfig_PST")
	.dwattr DW$90, DW_AT_type(*DWT$1080)
	.dwattr DW$90, DW_AT_location[DW_OP_reg0]
;* A2    assigned to _t_CanNode_UW
DW$91	.dwtag  DW_TAG_formal_parameter, DW_AT_name("t_CanNode_UW"), DW_AT_symbol_name("_t_CanNode_UW")
	.dwattr DW$91, DW_AT_type(*DWT$1044)
	.dwattr DW$91, DW_AT_location[DW_OP_reg1]
;* A2    assigned to C$1
DW$92	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$92, DW_AT_type(*DWT$1146)
	.dwattr DW$92, DW_AT_location[DW_OP_reg1]
;* A3    assigned to C$2
DW$93	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$93, DW_AT_type(*DWT$1181)
	.dwattr DW$93, DW_AT_location[DW_OP_reg2]
;* A4    assigned to _t_MsgObjFlag_UB
DW$94	.dwtag  DW_TAG_variable, DW_AT_name("t_MsgObjFlag_UB"), DW_AT_symbol_name("_t_MsgObjFlag_UB")
	.dwattr DW$94, DW_AT_type(*DWT$1018)
	.dwattr DW$94, DW_AT_location[DW_OP_reg3]
;* V1    assigned to _t_MsgObjNbr_UB
DW$95	.dwtag  DW_TAG_variable, DW_AT_name("t_MsgObjNbr_UB"), DW_AT_symbol_name("_t_MsgObjNbr_UB")
	.dwattr DW$95, DW_AT_type(*DWT$1018)
	.dwattr DW$95, DW_AT_location[DW_OP_reg4]
;* A1    assigned to _CanMsgObjConfig_PST
DW$96	.dwtag  DW_TAG_variable, DW_AT_name("CanMsgObjConfig_PST"), DW_AT_symbol_name("_CanMsgObjConfig_PST")
	.dwattr DW$96, DW_AT_type(*DWT$1083)
	.dwattr DW$96, DW_AT_location[DW_OP_reg0]
;* A3    assigned to U$20
DW$97	.dwtag  DW_TAG_variable, DW_AT_name("U$20"), DW_AT_symbol_name("U$20")
	.dwattr DW$97, DW_AT_type(*DWT$1181)
	.dwattr DW$97, DW_AT_location[DW_OP_reg2]
;* A2    assigned to K$11
DW$98	.dwtag  DW_TAG_variable, DW_AT_name("K$11"), DW_AT_symbol_name("K$11")
	.dwattr DW$98, DW_AT_type(*DWT$1145)
	.dwattr DW$98, DW_AT_location[DW_OP_reg1]
;----------------------------------------------------------------------
; 639 | UBYTE t_MsgObjNbr_UB;                                                  
; 640 | UBYTE t_MsgObjFlag_UB;                                                 
;----------------------------------------------------------------------
;** 645	-----------------------    t_MsgObjNbr_UB = CanMsgObjConfig_PST->MsgObjectNbr_UB;
	.dwpsn	"ADLATUS_CanHandler.c",645,3
;----------------------------------------------------------------------
; 645 | t_MsgObjNbr_UB = CanMsgObjConfig_PST->MsgObjectNbr_UB;                 
;----------------------------------------------------------------------
        LDRB      V1, [A1, #0]          ; |645| 
;** 648	-----------------------    t_MsgObjFlag_UB = 1u<<t_MsgObjNbr_UB;
	.dwpsn	"ADLATUS_CanHandler.c",648,3
;----------------------------------------------------------------------
; 648 | t_MsgObjFlag_UB = 0x00000001UL << t_MsgObjNbr_UB;                      
;----------------------------------------------------------------------
        MOV       A2, #1                ; |648| 
        LSL       A2, V1                ; |648| 
        LSL       A4, A2, #24
        LSR       A4, A4, #24
;** 651	-----------------------    C$1 = &e_SCC_ST;
	.dwpsn	"ADLATUS_CanHandler.c",651,3
;----------------------------------------------------------------------
; 651 | e_SCC_ST.CANME_UL &= ((ULONG)(~t_MsgObjFlag_UB));                      
;----------------------------------------------------------------------
        LDR       A2, CON2              ; |651| 
;** 651	-----------------------    C$1->CANME_UL &= ~t_MsgObjFlag_UB;
        LDR       A3, [A2, #0]          ; |651| 
        BIC       A3, A4                ; |651| 
        STR       A3, [A2, #0]          ; |651| 
;** 654	-----------------------    C$2 = ((int)t_MsgObjNbr_UB<<4)+&e_CAN_MB;
	.dwpsn	"ADLATUS_CanHandler.c",654,3
;----------------------------------------------------------------------
; 654 | e_CAN_MB[t_MsgObjNbr_UB].MCF_ST.l.CanMCF_UL = 0x00000008ul;            
;----------------------------------------------------------------------
        LSL       A3, V1, #4            ; |654| 
        LDR       V1, CON3              ; |654| 
        ADD       A3, V1, A3            ; |654| 
;** 654	-----------------------    C$2->MCF_ST.l.CanMCF_UL = 8u;
        MOV       V1, #8                ; |654| 
        STR       V1, [A3, #4]          ; |654| 
;** 655	-----------------------    U$20 = C$2;
	.dwpsn	"ADLATUS_CanHandler.c",655,3
;----------------------------------------------------------------------
; 655 | e_CAN_MB[t_MsgObjNbr_UB].MID_ST.l.CanMID_UL = 0x00000000ul;            
;----------------------------------------------------------------------
;** 655	-----------------------    U$20->MID_ST.l.CanMID_UL = 0u;
        MOV       V1, #0                ; |655| 
        STR       V1, [A3, #0]          ; |655| 
;** 651	-----------------------    K$11 = C$1;
	.dwpsn	"ADLATUS_CanHandler.c",651,3
;** 657	-----------------------    if ( CanMsgObjConfig_PST->MsgObjDirection_UB == 1 ) goto g2;
	.dwpsn	"ADLATUS_CanHandler.c",657,3
;----------------------------------------------------------------------
; 657 | if (d_CCcan_Transmit == CanMsgObjConfig_PST->MsgObjDirection_UB )      
; 660 |     e_SCC_ST.CANMD_UL &= ((ULONG)(~t_MsgObjFlag_UB));                  
; 662 | else                                                                   
;----------------------------------------------------------------------
        LDRB      V1, [A1, #2]          ; |657| 
        CMP       V1, #1                ; |657| 
        BEQ       L11                   ; |657| 
        ; |657| 
;* --------------------------------------------------------------------------*
;** 665	-----------------------    K$11->CANMD_UL |= t_MsgObjFlag_UB;
	.dwpsn	"ADLATUS_CanHandler.c",665,7
;----------------------------------------------------------------------
; 665 | e_SCC_ST.CANMD_UL |= ((ULONG)(t_MsgObjFlag_UB));                       
; 671 | if (d_CCcan_11BitID == CanMsgObjConfig_PST->IDLength_UB )              
;----------------------------------------------------------------------
        LDR       V1, [A2, #4]          ; |665| 
        ORR       V1, A4                ; |665| 
        STR       V1, [A2, #4]          ; |665| 
;** 665	-----------------------    goto g3;
        B         L12                   ; |665| 
        ; |665| 
;* --------------------------------------------------------------------------*
L11:    
;**	-----------------------g2:
;** 660	-----------------------    K$11->CANMD_UL &= ~t_MsgObjFlag_UB;
	.dwpsn	"ADLATUS_CanHandler.c",660,7
        LDR       V1, [A2, #4]          ; |660| 
        BIC       V1, A4                ; |660| 
        STR       V1, [A2, #4]          ; |660| 
;* --------------------------------------------------------------------------*
L12:    
;**	-----------------------g3:
;** 661	-----------------------    if ( CanMsgObjConfig_PST->IDLength_UB ) goto g5;
	.dwpsn	"ADLATUS_CanHandler.c",661,3
        LDRB      V1, [A1, #3]          ; |661| 
        CMP       V1, #0                ; |661| 
        BNE       L13                   ; |661| 
        ; |661| 
;* --------------------------------------------------------------------------*
;** 673	-----------------------    U$20->MID_ST.l.CanMID_UL = (CanMsgObjConfig_PST->CanIdentifier_UL&0x7ffu)<<18;
	.dwpsn	"ADLATUS_CanHandler.c",673,5
;----------------------------------------------------------------------
; 673 | e_CAN_MB[t_MsgObjNbr_UB].MID_ST.l.CanMID_UL = ((CanMsgObjConfig_PST->Ca
;     | nIdentifier_UL << 18) & 0x1FFC0000UL);                                 
;----------------------------------------------------------------------
        LDR       V1, [A1, #4]          ; |673| 
        LSL       V1, V1, #21
        LSR       V1, V1, #3
        STR       V1, [A3, #0]          ; |673| 
;** 675	-----------------------    goto g6;
	.dwpsn	"ADLATUS_CanHandler.c",675,3
;----------------------------------------------------------------------
; 680 | else                                                                   
;----------------------------------------------------------------------
        B         L14                   ; |675| 
        ; |675| 
;* --------------------------------------------------------------------------*
L13:    
;**	-----------------------g5:
;** 683	-----------------------    U$20->MID_ST.l.CanMID_UL = CanMsgObjConfig_PST->CanIdentifier_UL&0x1fffffffu|0x80000000u;
	.dwpsn	"ADLATUS_CanHandler.c",683,5
;----------------------------------------------------------------------
; 683 | e_CAN_MB[t_MsgObjNbr_UB].MID_ST.l.CanMID_UL = ((CanMsgObjConfig_PST->Ca
;     | nIdentifier_UL & 0x9FFFFFFFul) | 0x80000000ul);                        
; 691 | if ( d_CCcan_Activate == CanMsgObjConfig_PST->MsgObjState_UB )         
; 694 | e_SCC_ST.CANME_UL |= ((ULONG)(t_MsgObjFlag_UB));                       
; 702 | else                                                                   
;----------------------------------------------------------------------
        LDR       V1, [A1, #4]          ; |683| 
        LSL       V1, V1, #3            ; |683| 
        LSR       V2, V1, #3            ; |683| 
        MOV       V1, #1
        LSL       V1, V1, #31
        ORR       V1, V2                ; |683| 
        STR       V1, [A3, #0]          ; |683| 
;* --------------------------------------------------------------------------*
L14:    
;**	-----------------------g6:
;** 683	-----------------------    if ( CanMsgObjConfig_PST->MsgObjState_UB == 1 ) goto g8;
        LDRB      A1, [A1, #1]          ; |683| 
        CMP       A1, #1                ; |683| 
        BEQ       L15                   ; |683| 
        ; |683| 
;* --------------------------------------------------------------------------*
;** 705	-----------------------    K$11->CANME_UL &= ~t_MsgObjFlag_UB;
	.dwpsn	"ADLATUS_CanHandler.c",705,7
;----------------------------------------------------------------------
; 705 | e_SCC_ST.CANME_UL &= ((ULONG)(~t_MsgObjFlag_UB));                      
; 708 | return;                                                                
;----------------------------------------------------------------------
        LDR       A1, [A2, #0]          ; |705| 
        BIC       A1, A4                ; |705| 
        STR       A1, [A2, #0]          ; |705| 
;** 705	-----------------------    goto g9;
        POP       {V1, V2, PC}
;* --------------------------------------------------------------------------*
L15:    
;**	-----------------------g8:
;** 694	-----------------------    K$11->CANME_UL |= t_MsgObjFlag_UB;
	.dwpsn	"ADLATUS_CanHandler.c",694,5
        LDR       A1, [A2, #0]          ; |694| 
        ORR       A1, A4                ; |694| 
        STR       A1, [A2, #0]          ; |694| 
;**	-----------------------g9:
;**  	-----------------------    return;
	.dwpsn	"ADLATUS_CanHandler.c",710,1
	.dwcfa	0x0e, 12
        POP       {V1, V2, PC}
	.dwendentry
	.dwendtag DW$89



;******************************************************************************
;* CONSTANT TABLE                                                             *
;******************************************************************************
	.sect	".text"
	.align	4
CON1:	.field  	_e_SCC_ST+51,32

	.sect	".text:v$11"
	.clink
	.global	_FUN_CCcan_CheckCanReceiver_UB

DW$99	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_CheckCanReceiver_UB"), DW_AT_symbol_name("_FUN_CCcan_CheckCanReceiver_UB")
	.dwattr DW$99, DW_AT_veneer(0x01)
	.dwattr DW$99, DW_AT_low_pc(_FUN_CCcan_CheckCanReceiver_UB)
	.dwattr DW$99, DW_AT_high_pc(0x00)
	.dwattr DW$99, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CCcan_CheckCanReceiver_UB                           *
;*****************************************************************************
_FUN_CCcan_CheckCanReceiver_UB:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $FUN_CCcan_CheckCanReceiver_UB
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$99



	.sect	".text"
	.clink
	.global	$FUN_CCcan_CheckCanReceiver_UB

DW$100	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_CheckCanReceiver_UB"), DW_AT_symbol_name("$FUN_CCcan_CheckCanReceiver_UB")
	.dwattr DW$100, DW_AT_low_pc($FUN_CCcan_CheckCanReceiver_UB)
	.dwattr DW$100, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_CanHandler.c",736,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 735 | UBYTE FUN_CCcan_CheckCanReceiver_UB (void)                             
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CCcan_CheckCanReceiver_UB                              *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V1,V2,V3,V4,V5,V6,V7,V9,SP,LR,SR        *
;*   Regs Used         : A1,A2,A3,A4,V1,V2,V3,V4,V5,V6,V7,V9,SP,LR,SR        *
;*   Local Frame Size  : 0 Args + 8 Auto + 32 Save = 40 byte                 *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CCcan_CheckCanReceiver_UB:
;* --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 738 | UBYTE t_Result_UB;              /* Result value of the function
;     |         */                                                             
; 739 | UBYTE t_State_UB;               /* temporary state of CheckCanReceiverF
;     | unction */                                                             
; 741 | UBYTE t_MsgObjNbr_UB;           /* temp MsgObjNbr for MsgObject evaluat
;     | ion     */                                                             
; 742 | UBYTE t_MsgObjFlag_UB;                                                 
; 743 | UBYTE t_TableLine_UB;           /* temp table line for MsgObject evalua
;     | tion    */                                                             
; 744 | UBYTE t_Index_UB;               /* Index for copy routine
;     |         */                                                             
; 745 | UBYTE t_WriteIndex_UB;          /* Index for the Fifo evaluation
;     |         */                                                             
; 747 | UBYTE t_Channel_UB;             /* temp channel number for MsgObject ev
;     | aluation */                                                            
; 748 | UBYTE t_SubSet_UB;              /* temp Subset number for MsgObject eva
;     | luation */                                                             
; 750 | UBYTE t_ReceivedDataLength_UB;  /* temp data lengt from rx data msg obj
;     | ect      */                                                            
; 752 | UBYTE t_TempBuffer[8];          /* Temp buffer vor data storrage during
;     |          */                                                            
; 755 | UBYTE t_MsgObjCounter_UB;                                              
; 759 | t_Result_UB             =  d_CCglo_Idle;                               
; 760 | t_MsgObjNbr_UB          = d_CCglo_InitToZero;                          
; 761 | t_State_UB              = d_CCglo_InitToZero;                          
; 762 | t_TableLine_UB          = d_CCglo_InitToZero;                          
; 763 | t_ReceivedDataLength_UB = d_CCglo_InitToZero;                          
;----------------------------------------------------------------------
	.dwcfa	0x09, 26, 14
        PUSH      {V1, V2, V3, V4, LR}
        MOV       A2, V5
        MOV       A3, V6
        MOV       A4, V7
        PUSH      {A2, A3, A4}
	.dwcfa	0x0e, 4
	.dwcfa	0x80, 14, 1
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 10, 2
	.dwcfa	0x0e, 12
	.dwcfa	0x80, 9, 3
	.dwcfa	0x0e, 16
	.dwcfa	0x80, 8, 4
	.dwcfa	0x0e, 20
	.dwcfa	0x80, 7, 5
	.dwcfa	0x0e, 24
	.dwcfa	0x80, 6, 6
	.dwcfa	0x0e, 28
	.dwcfa	0x80, 5, 7
	.dwcfa	0x0e, 32
	.dwcfa	0x80, 4, 8
        ADD       SP, #-8
	.dwcfa	0x0e, 40
;* A3    assigned to C$2
DW$101	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$101, DW_AT_type(*DWT$1038)
	.dwattr DW$101, DW_AT_location[DW_OP_reg2]
;* A1    assigned to C$3
DW$102	.dwtag  DW_TAG_variable, DW_AT_name("C$3"), DW_AT_symbol_name("C$3")
	.dwattr DW$102, DW_AT_type(*DWT$11)
	.dwattr DW$102, DW_AT_location[DW_OP_reg0]
;* V2    assigned to C$4
DW$103	.dwtag  DW_TAG_variable, DW_AT_name("C$4"), DW_AT_symbol_name("C$4")
	.dwattr DW$103, DW_AT_type(*DWT$11)
	.dwattr DW$103, DW_AT_location[DW_OP_reg5]
;* A2    assigned to C$5
DW$104	.dwtag  DW_TAG_variable, DW_AT_name("C$5"), DW_AT_symbol_name("C$5")
	.dwattr DW$104, DW_AT_type(*DWT$1099)
	.dwattr DW$104, DW_AT_location[DW_OP_reg1]
;* A3    assigned to C$6
DW$105	.dwtag  DW_TAG_variable, DW_AT_name("C$6"), DW_AT_symbol_name("C$6")
	.dwattr DW$105, DW_AT_type(*DWT$6)
	.dwattr DW$105, DW_AT_location[DW_OP_reg2]
;* A3    assigned to C$7
DW$106	.dwtag  DW_TAG_variable, DW_AT_name("C$7"), DW_AT_symbol_name("C$7")
	.dwattr DW$106, DW_AT_type(*DWT$1084)
	.dwattr DW$106, DW_AT_location[DW_OP_reg2]
;* A2    assigned to C$8
DW$107	.dwtag  DW_TAG_variable, DW_AT_name("C$8"), DW_AT_symbol_name("C$8")
	.dwattr DW$107, DW_AT_type(*DWT$1146)
	.dwattr DW$107, DW_AT_location[DW_OP_reg1]
;* V7    assigned to Q$1
DW$108	.dwtag  DW_TAG_variable, DW_AT_name("Q$1"), DW_AT_symbol_name("Q$1")
	.dwattr DW$108, DW_AT_type(*DWT$1185)
	.dwattr DW$108, DW_AT_location[DW_OP_reg10]
;* V9    assigned to U$16
DW$109	.dwtag  DW_TAG_variable, DW_AT_name("U$16"), DW_AT_symbol_name("U$16")
	.dwattr DW$109, DW_AT_type(*DWT$1080)
	.dwattr DW$109, DW_AT_location[DW_OP_reg12]
;* A2    assigned to K$7
DW$110	.dwtag  DW_TAG_variable, DW_AT_name("K$7"), DW_AT_symbol_name("K$7")
	.dwattr DW$110, DW_AT_type(*DWT$1145)
	.dwattr DW$110, DW_AT_location[DW_OP_reg1]
;* V4    assigned to U$45
DW$111	.dwtag  DW_TAG_variable, DW_AT_name("U$45"), DW_AT_symbol_name("U$45")
	.dwattr DW$111, DW_AT_type(*DWT$1181)
	.dwattr DW$111, DW_AT_location[DW_OP_reg7]
;* V4    assigned to U$54
DW$112	.dwtag  DW_TAG_variable, DW_AT_name("U$54"), DW_AT_symbol_name("U$54")
	.dwattr DW$112, DW_AT_type(*DWT$1040)
	.dwattr DW$112, DW_AT_location[DW_OP_reg7]
;* A3    assigned to U$56
DW$113	.dwtag  DW_TAG_variable, DW_AT_name("U$56"), DW_AT_symbol_name("U$56")
	.dwattr DW$113, DW_AT_type(*DWT$1041)
	.dwattr DW$113, DW_AT_location[DW_OP_reg2]
;* A1    assigned to K$15
DW$114	.dwtag  DW_TAG_variable, DW_AT_name("K$15"), DW_AT_symbol_name("K$15")
	.dwattr DW$114, DW_AT_type(*DWT$1184)
	.dwattr DW$114, DW_AT_location[DW_OP_reg0]
;* A3    assigned to U$116
DW$115	.dwtag  DW_TAG_variable, DW_AT_name("U$116"), DW_AT_symbol_name("U$116")
	.dwattr DW$115, DW_AT_type(*DWT$1041)
	.dwattr DW$115, DW_AT_location[DW_OP_reg2]
;* A4    assigned to U$120
DW$116	.dwtag  DW_TAG_variable, DW_AT_name("U$120"), DW_AT_symbol_name("U$120")
	.dwattr DW$116, DW_AT_type(*DWT$1041)
	.dwattr DW$116, DW_AT_location[DW_OP_reg3]
;* A1    assigned to U$106
DW$117	.dwtag  DW_TAG_variable, DW_AT_name("U$106"), DW_AT_symbol_name("U$106")
	.dwattr DW$117, DW_AT_type(*DWT$11)
	.dwattr DW$117, DW_AT_location[DW_OP_reg0]
;* A4    assigned to P$1
DW$118	.dwtag  DW_TAG_variable, DW_AT_name("P$1"), DW_AT_symbol_name("P$1")
	.dwattr DW$118, DW_AT_type(*DWT$11)
	.dwattr DW$118, DW_AT_location[DW_OP_reg3]
;* A4    assigned to L$1
DW$119	.dwtag  DW_TAG_variable, DW_AT_name("L$1"), DW_AT_symbol_name("L$1")
	.dwattr DW$119, DW_AT_type(*DWT$11)
	.dwattr DW$119, DW_AT_location[DW_OP_reg3]
;* A1    assigned to L$2
DW$120	.dwtag  DW_TAG_variable, DW_AT_name("L$2"), DW_AT_symbol_name("L$2")
	.dwattr DW$120, DW_AT_type(*DWT$11)
	.dwattr DW$120, DW_AT_location[DW_OP_reg0]
;* V3    assigned to _t_MsgObjCounter_UB
DW$121	.dwtag  DW_TAG_variable, DW_AT_name("t_MsgObjCounter_UB"), DW_AT_symbol_name("_t_MsgObjCounter_UB")
	.dwattr DW$121, DW_AT_type(*DWT$1018)
	.dwattr DW$121, DW_AT_location[DW_OP_reg6]
;* LR    assigned to _t_ReceivedDataLength_UB
DW$122	.dwtag  DW_TAG_variable, DW_AT_name("t_ReceivedDataLength_UB"), DW_AT_symbol_name("_t_ReceivedDataLength_UB")
	.dwattr DW$122, DW_AT_type(*DWT$1018)
	.dwattr DW$122, DW_AT_location[DW_OP_reg14]
;* A2    assigned to _t_Channel_UB
DW$123	.dwtag  DW_TAG_variable, DW_AT_name("t_Channel_UB"), DW_AT_symbol_name("_t_Channel_UB")
	.dwattr DW$123, DW_AT_type(*DWT$1018)
	.dwattr DW$123, DW_AT_location[DW_OP_reg1]
;* A1    assigned to _t_WriteIndex_UB
DW$124	.dwtag  DW_TAG_variable, DW_AT_name("t_WriteIndex_UB"), DW_AT_symbol_name("_t_WriteIndex_UB")
	.dwattr DW$124, DW_AT_type(*DWT$1018)
	.dwattr DW$124, DW_AT_location[DW_OP_reg0]
;* V2    assigned to _t_MsgObjFlag_UB
DW$125	.dwtag  DW_TAG_variable, DW_AT_name("t_MsgObjFlag_UB"), DW_AT_symbol_name("_t_MsgObjFlag_UB")
	.dwattr DW$125, DW_AT_type(*DWT$1018)
	.dwattr DW$125, DW_AT_location[DW_OP_reg5]
;* V4    assigned to _t_MsgObjNbr_UB
DW$126	.dwtag  DW_TAG_variable, DW_AT_name("t_MsgObjNbr_UB"), DW_AT_symbol_name("_t_MsgObjNbr_UB")
	.dwattr DW$126, DW_AT_type(*DWT$1018)
	.dwattr DW$126, DW_AT_location[DW_OP_reg7]
;* V1    assigned to _t_State_UB
DW$127	.dwtag  DW_TAG_variable, DW_AT_name("t_State_UB"), DW_AT_symbol_name("_t_State_UB")
	.dwattr DW$127, DW_AT_type(*DWT$1018)
	.dwattr DW$127, DW_AT_location[DW_OP_reg4]
;* V6    assigned to _t_Result_UB
DW$128	.dwtag  DW_TAG_variable, DW_AT_name("t_Result_UB"), DW_AT_symbol_name("_t_Result_UB")
	.dwattr DW$128, DW_AT_type(*DWT$11)
	.dwattr DW$128, DW_AT_location[DW_OP_reg9]
;* A1    assigned to _t_TableLine_UB
DW$129	.dwtag  DW_TAG_variable, DW_AT_name("t_TableLine_UB"), DW_AT_symbol_name("_t_TableLine_UB")
	.dwattr DW$129, DW_AT_type(*DWT$1018)
	.dwattr DW$129, DW_AT_location[DW_OP_reg0]
;* A1    assigned to _t_TableLine_UB
DW$130	.dwtag  DW_TAG_variable, DW_AT_name("t_TableLine_UB"), DW_AT_symbol_name("_t_TableLine_UB")
	.dwattr DW$130, DW_AT_type(*DWT$1018)
	.dwattr DW$130, DW_AT_location[DW_OP_reg0]
DW$131	.dwtag  DW_TAG_variable, DW_AT_name("t_TempBuffer"), DW_AT_symbol_name("_t_TempBuffer")
	.dwattr DW$131, DW_AT_type(*DWT$1020)
	.dwattr DW$131, DW_AT_location[DW_OP_breg13 0]
;** 765	-----------------------    t_TempBuffer[0] = 0;
	.dwpsn	"ADLATUS_CanHandler.c",765,3
;----------------------------------------------------------------------
; 765 | t_TempBuffer[0]         = d_CCglo_InitToZero;                          
;----------------------------------------------------------------------
        MOV       A1, SP
        MOV       A2, #0                ; |765| 
        STRB      A2, [A1, #0]          ; |765| 
;** 759	-----------------------    t_Result_UB = 0;
	.dwpsn	"ADLATUS_CanHandler.c",759,3
        MOV       A1, A2
        MOV       V6, A1
;** 769	-----------------------    C$8 = &e_SCC_ST;
	.dwpsn	"ADLATUS_CanHandler.c",769,3
;----------------------------------------------------------------------
; 769 | if(e_SCC_ST.CANRMP_UL != 0ul)                                          
;----------------------------------------------------------------------
        LDR       A2, CON2              ; |769| 
;** 769	-----------------------    if ( !C$8->CANRMP_UL ) goto g38;
        LDR       A1, [A2, #24]         ; |769| 
        CMP       A1, #0                ; |769| 
        BEQ       L33                   ; |769| 
        ; |769| 
;* --------------------------------------------------------------------------*
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;**  	-----------------------    K$15 = &CanCtrl_ST;
        LDR       A1, CON5
;**  	-----------------------    Q$1 = K$15+32;
        ADD       A1, #32
        MOV       V7, A1
;**  	-----------------------    U$16 = K$15->CanMsgObjConfig_PST;
        LDR       A1, CON5
        LDR       A1, [A1, #0]
        MOV       V9, A1
;** 760	-----------------------    t_MsgObjNbr_UB = 0u;
	.dwpsn	"ADLATUS_CanHandler.c",760,3
        MOV       V4, V6
;** 761	-----------------------    t_State_UB = 0u;
	.dwpsn	"ADLATUS_CanHandler.c",761,3
        MOV       V1, V6
;** 763	-----------------------    t_ReceivedDataLength_UB = 0u;
	.dwpsn	"ADLATUS_CanHandler.c",763,3
        MOV       LR, V1
;** 771	-----------------------    t_MsgObjCounter_UB = 0u;
	.dwpsn	"ADLATUS_CanHandler.c",771,5
;----------------------------------------------------------------------
; 771 | t_MsgObjCounter_UB =  d_CCglo_InitToZero;                              
; 777 | while ( d_CCcan_StopScan != (t_State_UB & d_CCcan_StopScan) )          
;----------------------------------------------------------------------
        MOV       V3, LR
;** 769	-----------------------    K$7 = C$8;
	.dwpsn	"ADLATUS_CanHandler.c",769,3
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L16
;*
;*   Loop source line                : 777
;*   Loop closing brace source line  : 860
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L16:    
DWL$$FUN_CCcan_CheckCanReceiver_UB$3$B:
;**	-----------------------g3:
;** 782	-----------------------    if ( U$16->MsgObjDirection_UB == 255 ) goto g14;
	.dwpsn	"ADLATUS_CanHandler.c",782,7
;----------------------------------------------------------------------
; 782 | if ( d_CCglo_NoEntry == CanCtrl_ST.CanMsgObjConfig_PST[t_TableLine_UB].
;     | MsgObjDirection_UB )                                                   
; 785 |   t_State_UB |= d_CCcan_StopScan;                                      
; 792 | else                                                                   
;----------------------------------------------------------------------
        MOV       A1, V9
        LDRB      A3, [A1, #2]          ; |782| 
        CMP       A3, #255              ; |782| 
        BEQ       L21                   ; |782| 
        ; |782| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$3$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_CheckCanReceiver_UB$4$B:
;** 795	-----------------------    C$7 = &U$16[t_MsgObjCounter_UB];
	.dwpsn	"ADLATUS_CanHandler.c",795,9
;----------------------------------------------------------------------
; 795 | t_MsgObjFlag_UB =                                                      
; 796 |   (0x00000001UL << CanCtrl_ST.CanMsgObjConfig_PST[t_MsgObjCounter_UB].M
;     | sgObjectNbr_UB );                                                      
;----------------------------------------------------------------------
        MOV       A3, #12               ; |795| 
        MUL       A3, V3                ; |795| 
        MOV       A4, A1
        ADD       A3, A4, A3            ; |795| 
;** 795	-----------------------    t_MsgObjFlag_UB = 1u<<C$7->MsgObjectNbr_UB;
        LDRB      V2, [A3, #0]          ; |795| 
        MOV       A4, #1                ; |795| 
        LSL       A4, V2                ; |795| 
        LSL       V2, A4, #24
        LSR       V2, V2, #24
;** 801	-----------------------    if ( C$7->MsgObjState_UB != 1 || C$7->MsgObjDirection_UB ) goto g15;
	.dwpsn	"ADLATUS_CanHandler.c",801,9
;----------------------------------------------------------------------
; 801 | if ((d_CCcan_Activate == CanCtrl_ST.CanMsgObjConfig_PST[t_MsgObjCounter
;     | _UB].MsgObjState_UB ) &&                                               
; 802 |   (d_CCcan_Receive ==   CanCtrl_ST.CanMsgObjConfig_PST[t_MsgObjCounter_
;     | UB].MsgObjDirection_UB ) &&                                            
; 803 |   ((e_SCC_ST.CANME_UL & (ULONG)t_MsgObjFlag_UB) == (ULONG)t_MsgObjFlag_
;     | UB) &&                                                                 
; 804 |   ((e_SCC_ST.CANRMP_UL & (ULONG)t_MsgObjFlag_UB) == (ULONG)t_MsgObjFlag
;     | _UB))                                                                  
;----------------------------------------------------------------------
        LDRB      A4, [A3, #1]          ; |801| 
        CMP       A4, #1                ; |801| 
        BNE       L22                   ; |801| 
        ; |801| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$4$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_CheckCanReceiver_UB$5$B:
        LDRB      A3, [A3, #2]          ; |801| 
        CMP       A3, #0                ; |801| 
        BNE       L22                   ; |801| 
        ; |801| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$5$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_CheckCanReceiver_UB$6$B:
;** 801	-----------------------    if ( (K$7->CANME_UL&t_MsgObjFlag_UB) != t_MsgObjFlag_UB ) goto g15;
        LDR       A3, [A2, #0]          ; |801| 
        AND       A3, V2                ; |801| 
        CMP       A3, V2                ; |801| 
        BNE       L22                   ; |801| 
        ; |801| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$6$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_CheckCanReceiver_UB$7$B:
;** 801	-----------------------    if ( (K$7->CANRMP_UL&t_MsgObjFlag_UB) != t_MsgObjFlag_UB ) goto g15;
        LDR       A3, [A2, #24]         ; |801| 
        AND       A3, V2                ; |801| 
        CMP       A3, V2                ; |801| 
        BNE       L22                   ; |801| 
        ; |801| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$7$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_CheckCanReceiver_UB$8$B:
;** 809	-----------------------    P$1 = (K$7->CANRML_UL&t_MsgObjFlag_UB) == t_MsgObjFlag_UB;
	.dwpsn	"ADLATUS_CanHandler.c",809,11
;----------------------------------------------------------------------
; 809 | if ((e_SCC_ST.CANRML_UL & (ULONG)t_MsgObjFlag_UB) == (ULONG)t_MsgObjFla
;     | g_UB)                                                                  
;----------------------------------------------------------------------
        MOV       A4, V6
        LDR       A3, [A2, #28]         ; |809| 
        AND       A3, V2                ; |809| 
        CMP       A3, V2                ; |809| 
        BNE       L17                   ; |809| 
        ; |809| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$8$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_CheckCanReceiver_UB$9$B:
        MOV       A4, #1                ; |809| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$9$E:
;* --------------------------------------------------------------------------*
L17:    
DWL$$FUN_CCcan_CheckCanReceiver_UB$10$B:
;**  	-----------------------    U$45 = ((int)t_MsgObjCounter_UB<<4)+&e_CAN_MB;
        LSL       V4, V3, #4
        LDR       A3, CON3
        ADD       V4, A3, V4
;** 809	-----------------------    if ( !P$1 ) goto g9;
        CMP       A4, #0                ; |809| 
        BEQ       L18                   ; |809| 
        ; |809| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$10$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_CheckCanReceiver_UB$11$B:
;** 812	-----------------------    K$7->CANRML_UL &= t_MsgObjFlag_UB;
	.dwpsn	"ADLATUS_CanHandler.c",812,13
;----------------------------------------------------------------------
; 812 | e_SCC_ST.CANRML_UL &= (ULONG)t_MsgObjFlag_UB;                          
;----------------------------------------------------------------------
        LDR       A4, [A2, #28]         ; |812| 
        AND       A4, V2                ; |812| 
        STR       A4, [A2, #28]         ; |812| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$11$E:
;* --------------------------------------------------------------------------*
L18:    
DWL$$FUN_CCcan_CheckCanReceiver_UB$12$B:
;**	-----------------------g9:
;** 819	-----------------------    if ( (t_ReceivedDataLength_UB = U$45->MCF_ST.bw.CanMCF) == 0u || t_ReceivedDataLength_UB > 8 ) goto g13;
	.dwpsn	"ADLATUS_CanHandler.c",819,11
;----------------------------------------------------------------------
; 819 | t_ReceivedDataLength_UB = e_CAN_MB[t_MsgObjCounter_UB].MCF_ST.bw.CanMCF
;     | ;                                                                      
; 824 | if ((t_ReceivedDataLength_UB >  (UBYTE) 0x00u) && \                    
; 825 |     (t_ReceivedDataLength_UB <= (UBYTE) 0x08u))                        
; 828 |   t_State_UB = d_CCcan_MsgReceived;                                    
; 833 |   for (t_Index_UB =  0x00u;                                            
; 834 |        t_Index_UB <  t_ReceivedDataLength_UB;                          
; 835 |        t_Index_UB ++ )                                                 
;----------------------------------------------------------------------
        LDRB      A4, [V4, #7]          ; |819| 
        MOV       LR, A4
        CMP       A4, #0                ; |819| 
        BEQ       L20                   ; |819| 
        ; |819| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$12$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_CheckCanReceiver_UB$13$B:
        CMP       A4, #8                ; |819| 
        BGT       L20                   ; |819| 
        ; |819| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$13$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_CheckCanReceiver_UB$14$B:
;** 833	-----------------------    #pragma MUST_ITERATE(1, 8, 1)
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;**  	-----------------------    U$54 = &((volatile unsigned char *)e_CAN_MB)[((int)t_MsgObjCounter_UB<<4)];
        LSL       A4, V3, #4
        ADD       V4, A3, A4
;** 838	-----------------------    L$1 = (int)t_ReceivedDataLength_UB;
	.dwpsn	"ADLATUS_CanHandler.c",838,15
;----------------------------------------------------------------------
; 838 | t_TempBuffer[t_Index_UB] = \                                           
;----------------------------------------------------------------------
        MOV       A4, LR
;**  	-----------------------    U$56 = &t_TempBuffer[0];
        MOV       A3, SP
;** 828	-----------------------    t_State_UB = 2u;
	.dwpsn	"ADLATUS_CanHandler.c",828,13
        MOV       V1, #2                ; |828| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$14$E:
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L19
;*
;*   Loop source line                : 833
;*   Loop closing brace source line  : 842
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 8
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L19:    
DWL$$FUN_CCcan_CheckCanReceiver_UB$15$B:
;**	-----------------------g12:
;** 838	-----------------------    *U$56 = U$54[8];
	.dwpsn	"ADLATUS_CanHandler.c",838,15
;----------------------------------------------------------------------
; 839 | e_CAN_MB[t_MsgObjCounter_UB].u.CanData_UB[t_Index_UB];                 
;----------------------------------------------------------------------
        LDRB      A1, [V4, #8]          ; |838| 
        STRB      A1, [A3, #0]          ; |838| 
;** 842	-----------------------    ++U$54;
	.dwpsn	"ADLATUS_CanHandler.c",842,13
        ADD       V4, #1                ; |842| 
;** 842	-----------------------    ++U$56;
        ADD       A3, #1                ; |842| 
;** 842	-----------------------    if ( --L$1 ) goto g12;
        SUB       A4, #1                ; |842| 
        BNE       L19                   ; |842| 
        ; |842| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$15$E:
;* --------------------------------------------------------------------------*
L20:    
DWL$$FUN_CCcan_CheckCanReceiver_UB$16$B:
;**	-----------------------g13:
;** 846	-----------------------    t_State_UB |= 1u;
	.dwpsn	"ADLATUS_CanHandler.c",846,11
;----------------------------------------------------------------------
; 846 | t_State_UB |= d_CCcan_StopScan;                                        
;----------------------------------------------------------------------
        MOV       A3, #1                ; |846| 
        ORR       A3, V1                ; |846| 
        LSL       V1, A3, #24
        LSR       V1, V1, #24
;** 849	-----------------------    t_MsgObjNbr_UB = t_MsgObjCounter_UB;
	.dwpsn	"ADLATUS_CanHandler.c",849,11
;----------------------------------------------------------------------
; 849 | t_MsgObjNbr_UB = t_MsgObjCounter_UB;                                   
;----------------------------------------------------------------------
        MOV       V4, V3
;** 854	-----------------------    K$7->CANRMP_UL |= t_MsgObjFlag_UB;
	.dwpsn	"ADLATUS_CanHandler.c",854,11
;----------------------------------------------------------------------
; 854 | e_SCC_ST.CANRMP_UL |= (ULONG)t_MsgObjFlag_UB;                          
;----------------------------------------------------------------------
        LDR       A3, [A2, #24]         ; |854| 
        ORR       A3, V2                ; |854| 
        STR       A3, [A2, #24]         ; |854| 
;** 854	-----------------------    goto g15;
        B         L22                   ; |854| 
        ; |854| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$16$E:
;* --------------------------------------------------------------------------*
L21:    
DWL$$FUN_CCcan_CheckCanReceiver_UB$17$B:
;**	-----------------------g14:
;** 785	-----------------------    t_State_UB |= 1u;
	.dwpsn	"ADLATUS_CanHandler.c",785,9
        MOV       A3, #1                ; |785| 
        ORR       A3, V1                ; |785| 
        LSL       V1, A3, #24
        LSR       V1, V1, #24
DWL$$FUN_CCcan_CheckCanReceiver_UB$17$E:
;* --------------------------------------------------------------------------*
L22:    
DWL$$FUN_CCcan_CheckCanReceiver_UB$18$B:
;**	-----------------------g15:
;** 858	-----------------------    ++t_MsgObjCounter_UB;
	.dwpsn	"ADLATUS_CanHandler.c",858,7
;----------------------------------------------------------------------
; 858 | t_MsgObjCounter_UB++;                                                  
;----------------------------------------------------------------------
        ADD       A1, V3, #1            ; |858| 
        LSL       V3, A1, #24
        LSR       V3, V3, #24
;** 858	-----------------------    if ( !(t_State_UB&1) ) goto g3;
        LSR       A3, V1, #1            ; |858| 
        BCC       L16                   ; |858| 
        ; |858| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$18$E:
;* --------------------------------------------------------------------------*
;** 867	-----------------------    if ( !(t_State_UB&2) ) goto g38;
	.dwpsn	"ADLATUS_CanHandler.c",867,5
;----------------------------------------------------------------------
; 867 | if ((t_State_UB & d_CCcan_MsgReceived) == d_CCcan_MsgReceived)         
;----------------------------------------------------------------------
        LSR       A1, V1, #2            ; |867| 
        BCC       L33                   ; |867| 
        ; |867| 
;* --------------------------------------------------------------------------*
;** 873	-----------------------    t_State_UB &= 0xfeu;
	.dwpsn	"ADLATUS_CanHandler.c",873,7
;----------------------------------------------------------------------
; 873 | t_State_UB     &= (UBYTE) ~d_CCcan_StopScan;                           
;----------------------------------------------------------------------
        MOV       A1, #254              ; |873| 
        AND       V1, A1                ; |873| 
;** 874	-----------------------    t_TableLine_UB = 0u;
	.dwpsn	"ADLATUS_CanHandler.c",874,7
;----------------------------------------------------------------------
; 874 | t_TableLine_UB  =  d_CCglo_InitToZero;                                 
;----------------------------------------------------------------------
        MOV       A1, V6
;** 879	-----------------------    goto g26;
	.dwpsn	"ADLATUS_CanHandler.c",879,7
;----------------------------------------------------------------------
; 879 | while (d_CCcan_StopScan != (t_State_UB & d_CCcan_StopScan))            
;----------------------------------------------------------------------
        B         L27                   ; |879| 
        ; |879| 
;* --------------------------------------------------------------------------*
L23:    
DWL$$FUN_CCcan_CheckCanReceiver_UB$21$B:
;**	-----------------------g18:
;** 884	-----------------------    C$5 = t_TableLine_UB*4+K$15->CanChannelTable_PST;
	.dwpsn	"ADLATUS_CanHandler.c",884,9
;----------------------------------------------------------------------
; 884 | if ( d_CCglo_NoEntry == CanCtrl_ST.CanChannelTable_PST[t_TableLine_UB].
;     | MsgObjectNbr_UB )                                                      
; 887 |   t_State_UB |= d_CCcan_StopScan;                                      
; 893 | else                                                                   
;----------------------------------------------------------------------
        LSL       A2, A1, #2            ; |884| 
        LDR       A3, CON5
        LDR       A3, [A3, #4]          ; |884| 
        ADD       A2, A3, A2            ; |884| 
;** 884	-----------------------    if ( (C$6 = C$5->MsgObjectNbr_UB) == 255 ) goto g25;
        LDRB      A3, [A2, #0]          ; |884| 
        CMP       A3, #255              ; |884| 
        BEQ       L26                   ; |884| 
        ; |884| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$21$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_CheckCanReceiver_UB$22$B:
;** 898	-----------------------    if ( t_MsgObjNbr_UB != C$6 ) goto g24;
	.dwpsn	"ADLATUS_CanHandler.c",898,11
;----------------------------------------------------------------------
; 898 | if ( t_MsgObjNbr_UB != CanCtrl_ST.CanChannelTable_PST[t_TableLine_UB].M
;     | sgObjectNbr_UB )                                                       
; 901 |   t_TableLine_UB ++;                                                   
; 907 | else                                                                   
;----------------------------------------------------------------------
        CMP       V4, A3                ; |898| 
        BNE       L25                   ; |898| 
        ; |898| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$22$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_CheckCanReceiver_UB$23$B:
;** 913	-----------------------    if ( !(C$5->AddIdByteInfo_UB&4) ) goto g23;
	.dwpsn	"ADLATUS_CanHandler.c",913,13
;----------------------------------------------------------------------
; 913 | if ( d_CCcan_AddIdentifier != (CanCtrl_ST.CanChannelTable_PST[t_TableLi
;     | ne_UB].AddIdByteInfo_UB & d_CCcan_AddIdentifier))                      
; 916 |   t_State_UB |= (d_CCcan_StopScan | d_CCcan_CorrectMsgEntryFound);     
; 922 | else                                                                   
;----------------------------------------------------------------------
        LDRB      A3, [A2, #2]          ; |913| 
        LSR       A3, A3, #3            ; |913| 
        BCC       L24                   ; |913| 
        ; |913| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$23$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_CheckCanReceiver_UB$24$B:
;** 925	-----------------------    t_State_UB |= 4u;
	.dwpsn	"ADLATUS_CanHandler.c",925,15
;----------------------------------------------------------------------
; 925 | t_State_UB |= d_CCcan_AddIdentifier;                                   
;----------------------------------------------------------------------
        MOV       A3, #4                ; |925| 
        ORR       A3, V1                ; |925| 
        LSL       V1, A3, #24
        LSR       V1, V1, #24
;** 931	-----------------------    if ( t_TempBuffer[0] != C$5->AddIdentifier_UB ) goto g24;
	.dwpsn	"ADLATUS_CanHandler.c",931,15
;----------------------------------------------------------------------
; 931 | if ( t_TempBuffer[d_AdditionalIdPossition] != \                        
; 932 |   CanCtrl_ST.CanChannelTable_PST[t_TableLine_UB].AddIdentifier_UB)     
; 935 |   t_TableLine_UB ++;                                                   
; 941 | else                                                                   
;----------------------------------------------------------------------
        LDRB      A3, [A2, #3]          ; |931| 
        MOV       A2, SP
        LDRB      A2, [A2, #0]          ; |931| 
        CMP       A2, A3                ; |931| 
        BNE       L25                   ; |931| 
        ; |931| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$24$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_CheckCanReceiver_UB$25$B:
;** 944	-----------------------    t_State_UB |= 0xdu;
	.dwpsn	"ADLATUS_CanHandler.c",944,17
;----------------------------------------------------------------------
; 944 | t_State_UB |= ( d_CCcan_StopScan | \                                   
; 945 |   d_CCcan_CorrectMsgEntryFound | \                                     
; 946 |   d_CCcan_AddIdentifier       );                                       
;----------------------------------------------------------------------
        MOV       A2, #13               ; |944| 
        ORR       A2, V1                ; |944| 
        LSL       V1, A2, #24
        LSR       V1, V1, #24
;** 944	-----------------------    goto g26;
        B         L27                   ; |944| 
        ; |944| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$25$E:
;* --------------------------------------------------------------------------*
L24:    
DWL$$FUN_CCcan_CheckCanReceiver_UB$26$B:
;**	-----------------------g23:
;** 916	-----------------------    t_State_UB |= 0x9u;
	.dwpsn	"ADLATUS_CanHandler.c",916,15
        MOV       A2, #9                ; |916| 
        ORR       A2, V1                ; |916| 
        LSL       V1, A2, #24
        LSR       V1, V1, #24
;** 917	-----------------------    goto g26;
	.dwpsn	"ADLATUS_CanHandler.c",917,13
        B         L27                   ; |917| 
        ; |917| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$26$E:
;* --------------------------------------------------------------------------*
L25:    
DWL$$FUN_CCcan_CheckCanReceiver_UB$27$B:
;**	-----------------------g24:
;** 901	-----------------------    ++t_TableLine_UB;
	.dwpsn	"ADLATUS_CanHandler.c",901,13
        ADD       A1, A1, #1            ; |901| 
        LSL       A1, A1, #24
        LSR       A1, A1, #24
;** 902	-----------------------    goto g26;
	.dwpsn	"ADLATUS_CanHandler.c",902,11
        B         L27                   ; |902| 
        ; |902| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$27$E:
;* --------------------------------------------------------------------------*
L26:    
DWL$$FUN_CCcan_CheckCanReceiver_UB$28$B:
;**	-----------------------g25:
;** 887	-----------------------    t_State_UB |= 1u;
	.dwpsn	"ADLATUS_CanHandler.c",887,11
        MOV       A2, #1                ; |887| 
        ORR       A2, V1                ; |887| 
        LSL       V1, A2, #24
        LSR       V1, V1, #24
DWL$$FUN_CCcan_CheckCanReceiver_UB$28$E:
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L27
;* --------------------------------------------------------------------------*
L27:    
DWL$$FUN_CCcan_CheckCanReceiver_UB$29$B:
;**	-----------------------g26:
;** 952	-----------------------    if ( !(t_State_UB&1) ) goto g18;
	.dwpsn	"ADLATUS_CanHandler.c",952,7
        LSR       A2, V1, #1            ; |952| 
        BCC       L23                   ; |952| 
        ; |952| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$29$E:
;* --------------------------------------------------------------------------*
;** 960	-----------------------    if ( !(t_State_UB&0x8) ) goto g38;
	.dwpsn	"ADLATUS_CanHandler.c",960,7
;----------------------------------------------------------------------
; 960 | if (d_CCcan_CorrectMsgEntryFound == (t_State_UB & d_CCcan_CorrectMsgEnt
;     | ryFound))                                                              
;----------------------------------------------------------------------
        LSR       A2, V1, #4            ; |960| 
        BCC       L33                   ; |960| 
        ; |960| 
;* --------------------------------------------------------------------------*
;** 965	-----------------------    C$4 = t_TableLine_UB*4;
	.dwpsn	"ADLATUS_CanHandler.c",965,9
;----------------------------------------------------------------------
; 965 | t_Channel_UB    = (CanCtrl_ST.CanChannelTable_PST[t_TableLine_UB].Chann
;     | elNbr_UB & d_CCglo_ChannelMask);                                       
; 966 | t_SubSet_UB     = (CanCtrl_ST.CanChannelTable_PST[t_TableLine_UB].Chann
;     | elNbr_UB & d_CCglo_SubSetMask );                                       
;----------------------------------------------------------------------
        LSL       V2, A1, #2            ; |965| 
;** 965	-----------------------    t_Channel_UB = (K$15->CanChannelTable_PST+C$4)->ChannelNbr_UB&0xf;
        LDR       A1, CON5
        LDR       A1, [A1, #4]          ; |965| 
        ADD       A1, V2, A1            ; |965| 
        LDRB      A1, [A1, #1]          ; |965| 
        LSL       A1, A1, #28           ; |965| 
        LSR       A2, A1, #28           ; |965| 
;** 967	-----------------------    t_WriteIndex_UB = *(unsigned char *)Q$1;
	.dwpsn	"ADLATUS_CanHandler.c",967,9
;----------------------------------------------------------------------
; 967 | t_WriteIndex_UB =  CanCtrl_ST.WriteIndex_AUB;                          
;----------------------------------------------------------------------
        MOV       A3, V7
        LDRB      A1, [A3, #0]          ; |967| 
;** 972	-----------------------    *(unsigned char *)Q$1 = t_WriteIndex_UB+1&3;
	.dwpsn	"ADLATUS_CanHandler.c",972,9
;----------------------------------------------------------------------
; 972 | CanCtrl_ST.WriteIndex_AUB++;                                           
; 973 | CanCtrl_ST.WriteIndex_AUB &= (UBYTE) 0x03u;                            
;----------------------------------------------------------------------
        ADD       A4, A1, #1            ; |972| 
        LSL       A4, A4, #30
        LSR       A4, A4, #30
        STRB      A4, [A3, #0]          ; |972| 
;** 979	-----------------------    C$3 = t_WriteIndex_UB*12;
	.dwpsn	"ADLATUS_CanHandler.c",979,9
;----------------------------------------------------------------------
; 979 | t_CCcan_CanFifoBuffer_AUB[t_WriteIndex_UB][d_CCglo_BufferState] |= \   
; 980 |   d_CCglo_BufferValid;                                                 
;----------------------------------------------------------------------
        MOV       A3, #12               ; |979| 
        MUL       A1, A3
;** 979	-----------------------    C$2 = &t_CCcan_CanFifoBuffer_AUB;
        LDR       A3, CON8              ; |979| 
;** 979	-----------------------    C$2[C$3] |= 0x80u;
        LDRB      V3, [A1, A3]          ; |979| 
        MOV       A4, #128              ; |979| 
        ORR       A4, V3                ; |979| 
        STRB      A4, [A1, A3]          ; |979| 
;** 984	-----------------------    C$2[C$3+1] = (K$15->CanChannelTable_PST+C$4)->ChannelNbr_UB;
	.dwpsn	"ADLATUS_CanHandler.c",984,9
;----------------------------------------------------------------------
; 984 | t_CCcan_CanFifoBuffer_AUB[t_WriteIndex_UB][d_CCglo_ChannelNbr] = \     
; 985 |   CanCtrl_ST.CanChannelTable_PST[t_TableLine_UB].ChannelNbr_UB;        
;----------------------------------------------------------------------
        LDR       A4, CON5
        LDR       A4, [A4, #4]          ; |984| 
        ADD       A4, V2, A4            ; |984| 
        LDRB      A4, [A4, #1]          ; |984| 
        ADD       V2, A1, A3            ; |984| 
        STRB      A4, [V2, #1]          ; |984| 
;** 989	-----------------------    U$106 = C$3;
	.dwpsn	"ADLATUS_CanHandler.c",989,9
;----------------------------------------------------------------------
; 989 | t_CCcan_CanFifoBuffer_AUB[t_WriteIndex_UB][d_CCglo_DLC] = \            
; 990 |   t_ReceivedDataLength_UB;                                             
;----------------------------------------------------------------------
;** 989	-----------------------    C$2[U$106+3] = t_ReceivedDataLength_UB;
        ADD       V2, A1, A3            ; |989| 
        MOV       A4, LR
        STRB      A4, [V2, #3]          ; |989| 
;** 995	-----------------------    if ( !t_ReceivedDataLength_UB ) goto g32;
	.dwpsn	"ADLATUS_CanHandler.c",995,14
;----------------------------------------------------------------------
; 995 | for (t_Index_UB =  0x00u;                                              
; 996 | t_Index_UB <  t_ReceivedDataLength_UB;                                 
; 997 | t_Index_UB ++ )                                                        
;----------------------------------------------------------------------
        CMP       A4, #0                ; |995| 
        BEQ       L29                   ; |995| 
        ; |995| 
;* --------------------------------------------------------------------------*
;**  	-----------------------    #pragma MUST_ITERATE(1, 256, 1)
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;**  	-----------------------    U$120 = &C$2[U$106];
        ADD       A4, A1, A3
;* 1000	-----------------------    L$2 = (int)t_ReceivedDataLength_UB;
	.dwpsn	"ADLATUS_CanHandler.c",1000,11
;----------------------------------------------------------------------
; 1000 | t_CCcan_CanFifoBuffer_AUB[t_WriteIndex_UB][d_CCglo_StartOfData + t_Inde
;     | x_UB] = \                                                              
; 1001 |   t_TempBuffer[t_Index_UB];                                            
;----------------------------------------------------------------------
        MOV       A1, LR
;**  	-----------------------    U$116 = &t_TempBuffer[0];
        MOV       A3, SP
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L28
;*
;*   Loop source line                : 995
;*   Loop closing brace source line  : 1003
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 256
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L28:    
DWL$$FUN_CCcan_CheckCanReceiver_UB$33$B:
;**	-----------------------g31:
;* 1000	-----------------------    U$120[4] = *U$116;
        LDRB      V2, [A3, #0]          ; |1000| 
        STRB      V2, [A4, #4]          ; |1000| 
;* 1003	-----------------------    ++U$116;
	.dwpsn	"ADLATUS_CanHandler.c",1003,9
        ADD       A3, #1                ; |1003| 
;* 1003	-----------------------    ++U$120;
        ADD       A4, #1                ; |1003| 
;* 1003	-----------------------    if ( --L$2 ) goto g31;
        SUB       A1, #1                ; |1003| 
        BNE       L28                   ; |1003| 
        ; |1003| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$33$E:
;* --------------------------------------------------------------------------*
L29:    
;**	-----------------------g32:
;* 1005	-----------------------    t_Result_UB = (unsigned char)(t_Channel_UB|0xffffff80);
	.dwpsn	"ADLATUS_CanHandler.c",1005,7
;----------------------------------------------------------------------
; 1005 | t_Result_UB = (d_CCglo_Ready | t_Channel_UB);                          
;----------------------------------------------------------------------
        MOV       A1, #127              ; |1005| 
        MVN       A1, A1                ; |1005| 
        ORR       A1, A2                ; |1005| 
        LSL       A1, A1, #24
        LSR       A1, A1, #24
        MOV       V6, A1
;* 1011	-----------------------    if ( K$15->SelectedChannel_UB != 15 ) goto g38;
	.dwpsn	"ADLATUS_CanHandler.c",1011,9
;----------------------------------------------------------------------
; 1011 | if ( d_CCglo_AllChannels == CanCtrl_ST.SelectedChannel_UB )            
;----------------------------------------------------------------------
        LDR       A1, CON5
        LDRB      A1, [A1, #15]         ; |1011| 
        CMP       A1, #15               ; |1011| 
        BNE       L33                   ; |1011| 
        ; |1011| 
;* --------------------------------------------------------------------------*
;* 1016	-----------------------    K$15->SelectedChannel_UB = t_Channel_UB;
	.dwpsn	"ADLATUS_CanHandler.c",1016,11
;----------------------------------------------------------------------
; 1016 | CanCtrl_ST.SelectedChannel_UB = t_Channel_UB;                          
;----------------------------------------------------------------------
        LDR       A1, CON5
        STRB      A2, [A1, #15]         ; |1016| 
;* 1021	-----------------------    t_State_UB &= 0xfeu;
	.dwpsn	"ADLATUS_CanHandler.c",1021,11
;----------------------------------------------------------------------
; 1021 | t_State_UB     &= (UBYTE) ~d_CCcan_StopScan;                           
;----------------------------------------------------------------------
        MOV       A1, #254              ; |1021| 
        AND       V1, A1                ; |1021| 
;* 1022	-----------------------    t_TableLine_UB = 0u;
	.dwpsn	"ADLATUS_CanHandler.c",1022,11
;----------------------------------------------------------------------
; 1022 | t_TableLine_UB  = d_CCglo_InitToZero;                                  
;----------------------------------------------------------------------
        MOV       A1, #0                ; |765| 
;* 1027	-----------------------    goto g37;
	.dwpsn	"ADLATUS_CanHandler.c",1027,11
;----------------------------------------------------------------------
; 1027 | while (d_CCcan_StopScan != (t_State_UB & d_CCcan_StopScan))            
;----------------------------------------------------------------------
        B         L32                   ; |1027| 
        ; |1027| 
;* --------------------------------------------------------------------------*
L30:    
DWL$$FUN_CCcan_CheckCanReceiver_UB$36$B:
;**	-----------------------g34:
;* 1032	-----------------------    if ( (t_TableLine_UB*4+K$15->CanChannelTable_PST)->MsgObjectNbr_UB == 255 ) goto g36;
	.dwpsn	"ADLATUS_CanHandler.c",1032,13
;----------------------------------------------------------------------
; 1032 | if ( d_CCglo_NoEntry == CanCtrl_ST.CanChannelTable_PST[t_TableLine_UB].
;     | MsgObjectNbr_UB )                                                      
; 1035 |   t_State_UB |= d_CCcan_StopScan;                                      
; 1042 | else                                                                   
;----------------------------------------------------------------------
        LSL       A2, A1, #2            ; |1032| 
        LDR       A3, CON5
        LDR       A3, [A3, #4]          ; |1032| 
        LDRB      A2, [A3, A2]          ; |1032| 
        CMP       A2, #255              ; |1032| 
        BEQ       L31                   ; |1032| 
        ; |1032| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$36$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_CheckCanReceiver_UB$37$B:
;* 1047	-----------------------    ++t_TableLine_UB;
	.dwpsn	"ADLATUS_CanHandler.c",1047,15
;----------------------------------------------------------------------
; 1047 | if (  CanCtrl_ST.SelectedChannel_UB == \                               
; 1048 |   (CanCtrl_ST.CanChannelTable_PST[t_TableLine_UB].ChannelNbr_UB & d_CCg
;     | lo_ChannelMask) )                                                      
; 1051 |   t_TableLine_UB ++;                                                   
;----------------------------------------------------------------------
        ADD       A1, A1, #1            ; |1047| 
        LSL       A1, A1, #24
        LSR       A1, A1, #24
;* 1053	-----------------------    goto g37;
	.dwpsn	"ADLATUS_CanHandler.c",1053,15
;----------------------------------------------------------------------
; 1058 | else                                                                   
; 1063 |   t_MsgObjNbr_UB = CanCtrl_ST.CanChannelTable_PST[t_TableLine_UB].MsgOb
;     | jectNbr_UB;                                                            
; 1072 |   t_TableLine_UB ++;                                                   
;----------------------------------------------------------------------
        B         L32                   ; |1053| 
        ; |1053| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$37$E:
;* --------------------------------------------------------------------------*
L31:    
DWL$$FUN_CCcan_CheckCanReceiver_UB$38$B:
;**	-----------------------g36:
;* 1035	-----------------------    t_State_UB |= 1u;
	.dwpsn	"ADLATUS_CanHandler.c",1035,15
        MOV       A2, #1                ; |1035| 
        ORR       A2, V1                ; |1035| 
        LSL       V1, A2, #24
        LSR       V1, V1, #24
DWL$$FUN_CCcan_CheckCanReceiver_UB$38$E:
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L32
;* --------------------------------------------------------------------------*
L32:    
DWL$$FUN_CCcan_CheckCanReceiver_UB$39$B:
;**	-----------------------g37:
;* 1076	-----------------------    if ( !(t_State_UB&1) ) goto g34;
	.dwpsn	"ADLATUS_CanHandler.c",1076,11
;----------------------------------------------------------------------
; 1080 | #if defined (cs_CCTP20)                                                
; 1087 | t_Result_UB = FUN_CCcan_RxDataTP20_UB ( (UBYTE) (t_SubSet_UB | t_Channe
;     | l_UB) );                                                               
; 1089 | if (d_CCcan_MsgObjInvalid == t_Result_UB)                              
; 1092 |   t_CCcan_CanFifoBuffer_AUB[t_WriteIndex_UB][d_CCglo_BufferState] &= \ 
; 1093 |     ~d_CCglo_BufferValid;                                              
; 1095 |   t_Result_UB = d_CCglo_Idle;                                          
; 1097 | #endif                                                                 
;----------------------------------------------------------------------
        LSR       A2, V1, #1            ; |1076| 
        BCC       L30                   ; |1076| 
        ; |1076| 
DWL$$FUN_CCcan_CheckCanReceiver_UB$39$E:
;* --------------------------------------------------------------------------*
L33:    
;**	-----------------------g38:
;* 1102	-----------------------    return t_Result_UB;
	.dwpsn	"ADLATUS_CanHandler.c",1102,3
;----------------------------------------------------------------------
; 1102 | return (t_Result_UB);                                                  
;----------------------------------------------------------------------
        MOV       A1, V6
	.dwpsn	"ADLATUS_CanHandler.c",1104,1
        ADD       SP, #8                ; |1102| 
	.dwcfa	0x0e, 32
        POP       {A2, A3, A4}
        MOV       V5, A2
        MOV       V6, A3
        MOV       V7, A4
        POP       {V1, V2, V3, V4, PC}

DW$132	.dwtag  DW_TAG_loop
	.dwattr DW$132, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L32:1:1323432538")
	.dwattr DW$132, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$132, DW_AT_begin_line(0x403)
	.dwattr DW$132, DW_AT_end_line(0x434)
DW$133	.dwtag  DW_TAG_loop_range
	.dwattr DW$133, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$39$B)
	.dwattr DW$133, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$39$E)
DW$134	.dwtag  DW_TAG_loop_range
	.dwattr DW$134, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$36$B)
	.dwattr DW$134, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$36$E)
DW$135	.dwtag  DW_TAG_loop_range
	.dwattr DW$135, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$38$B)
	.dwattr DW$135, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$38$E)
DW$136	.dwtag  DW_TAG_loop_range
	.dwattr DW$136, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$37$B)
	.dwattr DW$136, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$37$E)
	.dwendtag DW$132


DW$137	.dwtag  DW_TAG_loop
	.dwattr DW$137, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L28:1:1323432538")
	.dwattr DW$137, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$137, DW_AT_begin_line(0x3e3)
	.dwattr DW$137, DW_AT_end_line(0x3eb)
DW$138	.dwtag  DW_TAG_loop_range
	.dwattr DW$138, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$33$B)
	.dwattr DW$138, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$33$E)
	.dwendtag DW$137


DW$139	.dwtag  DW_TAG_loop
	.dwattr DW$139, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L27:1:1323432538")
	.dwattr DW$139, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$139, DW_AT_begin_line(0x36f)
	.dwattr DW$139, DW_AT_end_line(0x3b8)
DW$140	.dwtag  DW_TAG_loop_range
	.dwattr DW$140, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$29$B)
	.dwattr DW$140, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$29$E)
DW$141	.dwtag  DW_TAG_loop_range
	.dwattr DW$141, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$21$B)
	.dwattr DW$141, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$21$E)
DW$142	.dwtag  DW_TAG_loop_range
	.dwattr DW$142, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$22$B)
	.dwattr DW$142, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$22$E)
DW$143	.dwtag  DW_TAG_loop_range
	.dwattr DW$143, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$23$B)
	.dwattr DW$143, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$23$E)
DW$144	.dwtag  DW_TAG_loop_range
	.dwattr DW$144, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$24$B)
	.dwattr DW$144, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$24$E)
DW$145	.dwtag  DW_TAG_loop_range
	.dwattr DW$145, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$28$B)
	.dwattr DW$145, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$28$E)
DW$146	.dwtag  DW_TAG_loop_range
	.dwattr DW$146, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$27$B)
	.dwattr DW$146, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$27$E)
DW$147	.dwtag  DW_TAG_loop_range
	.dwattr DW$147, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$26$B)
	.dwattr DW$147, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$26$E)
DW$148	.dwtag  DW_TAG_loop_range
	.dwattr DW$148, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$25$B)
	.dwattr DW$148, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$25$E)
	.dwendtag DW$139


DW$149	.dwtag  DW_TAG_loop
	.dwattr DW$149, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L16:1:1323432538")
	.dwattr DW$149, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$149, DW_AT_begin_line(0x309)
	.dwattr DW$149, DW_AT_end_line(0x35c)
DW$150	.dwtag  DW_TAG_loop_range
	.dwattr DW$150, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$3$B)
	.dwattr DW$150, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$3$E)
DW$151	.dwtag  DW_TAG_loop_range
	.dwattr DW$151, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$14$B)
	.dwattr DW$151, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$14$E)
DW$152	.dwtag  DW_TAG_loop_range
	.dwattr DW$152, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$8$B)
	.dwattr DW$152, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$8$E)
DW$153	.dwtag  DW_TAG_loop_range
	.dwattr DW$153, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$9$B)
	.dwattr DW$153, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$9$E)
DW$154	.dwtag  DW_TAG_loop_range
	.dwattr DW$154, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$10$B)
	.dwattr DW$154, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$10$E)
DW$155	.dwtag  DW_TAG_loop_range
	.dwattr DW$155, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$11$B)
	.dwattr DW$155, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$11$E)
DW$156	.dwtag  DW_TAG_loop_range
	.dwattr DW$156, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$12$B)
	.dwattr DW$156, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$12$E)
DW$157	.dwtag  DW_TAG_loop_range
	.dwattr DW$157, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$13$B)
	.dwattr DW$157, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$13$E)
DW$158	.dwtag  DW_TAG_loop_range
	.dwattr DW$158, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$4$B)
	.dwattr DW$158, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$4$E)
DW$159	.dwtag  DW_TAG_loop_range
	.dwattr DW$159, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$5$B)
	.dwattr DW$159, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$5$E)
DW$160	.dwtag  DW_TAG_loop_range
	.dwattr DW$160, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$6$B)
	.dwattr DW$160, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$6$E)
DW$161	.dwtag  DW_TAG_loop_range
	.dwattr DW$161, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$7$B)
	.dwattr DW$161, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$7$E)
DW$162	.dwtag  DW_TAG_loop_range
	.dwattr DW$162, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$16$B)
	.dwattr DW$162, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$16$E)
DW$163	.dwtag  DW_TAG_loop_range
	.dwattr DW$163, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$17$B)
	.dwattr DW$163, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$17$E)
DW$164	.dwtag  DW_TAG_loop_range
	.dwattr DW$164, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$18$B)
	.dwattr DW$164, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$18$E)

DW$165	.dwtag  DW_TAG_loop
	.dwattr DW$165, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L19:2:1323432538")
	.dwattr DW$165, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$165, DW_AT_begin_line(0x341)
	.dwattr DW$165, DW_AT_end_line(0x34a)
DW$166	.dwtag  DW_TAG_loop_range
	.dwattr DW$166, DW_AT_low_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$15$B)
	.dwattr DW$166, DW_AT_high_pc(DWL$$FUN_CCcan_CheckCanReceiver_UB$15$E)
	.dwendtag DW$165

	.dwendtag DW$149

	.dwendentry
	.dwendtag DW$100



;******************************************************************************
;* CONSTANT TABLE                                                             *
;******************************************************************************
	.sect	".text"
	.align	4
CON3:	.field  	_e_CAN_MB,32
	.align	4
CON4:	.field  	_c_CCcan_TestPattern_AUB,32

	.sect	".text:v$12"
	.clink
	.global	_FUN_CCcan_RxData_UB

DW$167	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_RxData_UB"), DW_AT_symbol_name("_FUN_CCcan_RxData_UB")
	.dwattr DW$167, DW_AT_veneer(0x01)
	.dwattr DW$167, DW_AT_low_pc(_FUN_CCcan_RxData_UB)
	.dwattr DW$167, DW_AT_high_pc(0x00)
	.dwattr DW$167, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CCcan_RxData_UB                                     *
;*****************************************************************************
_FUN_CCcan_RxData_UB:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $FUN_CCcan_RxData_UB
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$167



	.sect	".text"
	.clink
	.global	$FUN_CCcan_RxData_UB

DW$168	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_RxData_UB"), DW_AT_symbol_name("$FUN_CCcan_RxData_UB")
	.dwattr DW$168, DW_AT_low_pc($FUN_CCcan_RxData_UB)
	.dwattr DW$168, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_CanHandler.c",1131,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 1130 | UBYTE FUN_CCcan_RxData_UB (PTR_BUFFER_UB t_InBuffer_PBUF, PTR_BUFFER_UB
;     |  t_OutBuffer_PBUF )                                                    
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CCcan_RxData_UB                                        *
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
$FUN_CCcan_RxData_UB:
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
;* A1    assigned to _t_InBuffer_PBUF
DW$169	.dwtag  DW_TAG_formal_parameter, DW_AT_name("t_InBuffer_PBUF"), DW_AT_symbol_name("_t_InBuffer_PBUF")
	.dwattr DW$169, DW_AT_type(*DWT$1023)
	.dwattr DW$169, DW_AT_location[DW_OP_reg0]
;* A2    assigned to _t_OutBuffer_PBUF
DW$170	.dwtag  DW_TAG_formal_parameter, DW_AT_name("t_OutBuffer_PBUF"), DW_AT_symbol_name("_t_OutBuffer_PBUF")
	.dwattr DW$170, DW_AT_type(*DWT$1023)
	.dwattr DW$170, DW_AT_location[DW_OP_reg1]
;* V1    assigned to C$1
DW$171	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$171, DW_AT_type(*DWT$6)
	.dwattr DW$171, DW_AT_location[DW_OP_reg4]
;* A3    assigned to C$2
DW$172	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$172, DW_AT_type(*DWT$11)
	.dwattr DW$172, DW_AT_location[DW_OP_reg2]
;* V1    assigned to C$3
DW$173	.dwtag  DW_TAG_variable, DW_AT_name("C$3"), DW_AT_symbol_name("C$3")
	.dwattr DW$173, DW_AT_type(*DWT$11)
	.dwattr DW$173, DW_AT_location[DW_OP_reg4]
;* A4    assigned to C$4
DW$174	.dwtag  DW_TAG_variable, DW_AT_name("C$4"), DW_AT_symbol_name("C$4")
	.dwattr DW$174, DW_AT_type(*DWT$1038)
	.dwattr DW$174, DW_AT_location[DW_OP_reg3]
;* V4    assigned to C$5
DW$175	.dwtag  DW_TAG_variable, DW_AT_name("C$5"), DW_AT_symbol_name("C$5")
	.dwattr DW$175, DW_AT_type(*DWT$6)
	.dwattr DW$175, DW_AT_location[DW_OP_reg7]
;* V3    assigned to _t_Index_UB
DW$176	.dwtag  DW_TAG_variable, DW_AT_name("t_Index_UB"), DW_AT_symbol_name("_t_Index_UB")
	.dwattr DW$176, DW_AT_type(*DWT$1018)
	.dwattr DW$176, DW_AT_location[DW_OP_reg6]
;* A3    assigned to _t_ReadIndex_UB
DW$177	.dwtag  DW_TAG_variable, DW_AT_name("t_ReadIndex_UB"), DW_AT_symbol_name("_t_ReadIndex_UB")
	.dwattr DW$177, DW_AT_type(*DWT$1018)
	.dwattr DW$177, DW_AT_location[DW_OP_reg2]
;* A1    assigned to _t_Result_UB
DW$178	.dwtag  DW_TAG_variable, DW_AT_name("t_Result_UB"), DW_AT_symbol_name("_t_Result_UB")
	.dwattr DW$178, DW_AT_type(*DWT$1018)
	.dwattr DW$178, DW_AT_location[DW_OP_reg0]
;* A2    assigned to _t_OutBuffer_PBUF
DW$179	.dwtag  DW_TAG_variable, DW_AT_name("t_OutBuffer_PBUF"), DW_AT_symbol_name("_t_OutBuffer_PBUF")
	.dwattr DW$179, DW_AT_type(*DWT$1024)
	.dwattr DW$179, DW_AT_location[DW_OP_reg1]
;* V2    assigned to K$10
DW$180	.dwtag  DW_TAG_variable, DW_AT_name("K$10"), DW_AT_symbol_name("K$10")
	.dwattr DW$180, DW_AT_type(*DWT$1184)
	.dwattr DW$180, DW_AT_location[DW_OP_reg5]
;* V9    assigned to U$24
DW$181	.dwtag  DW_TAG_variable, DW_AT_name("U$24"), DW_AT_symbol_name("U$24")
	.dwattr DW$181, DW_AT_type(*DWT$1041)
	.dwattr DW$181, DW_AT_location[DW_OP_reg12]
;* A3    assigned to U$23
DW$182	.dwtag  DW_TAG_variable, DW_AT_name("U$23"), DW_AT_symbol_name("U$23")
	.dwattr DW$182, DW_AT_type(*DWT$11)
	.dwattr DW$182, DW_AT_location[DW_OP_reg2]
;* A4    assigned to K$16
DW$183	.dwtag  DW_TAG_variable, DW_AT_name("K$16"), DW_AT_symbol_name("K$16")
	.dwattr DW$183, DW_AT_type(*DWT$1038)
	.dwattr DW$183, DW_AT_location[DW_OP_reg3]
;----------------------------------------------------------------------
; 1133 | UBYTE t_Result_UB;                                                     
; 1134 | UBYTE t_Channel_UB;                                                    
; 1135 | UBYTE t_ReadIndex_UB;                                                  
; 1136 | UBYTE t_Index_UB;                                                      
; 1139 | t_InBuffer_PBUF += 0x00u;                                              
;----------------------------------------------------------------------
;* 1144	-----------------------    t_Result_UB = 0u;
	.dwpsn	"ADLATUS_CanHandler.c",1144,3
;----------------------------------------------------------------------
; 1144 | t_Result_UB  = d_CCglo_Idle;                                           
;----------------------------------------------------------------------
        MOV       A1, #0                ; |1144| 
;* 1149	-----------------------    C$5 = *t_OutBuffer_PBUF;
	.dwpsn	"ADLATUS_CanHandler.c",1149,3
;----------------------------------------------------------------------
; 1149 | if ( (t_OutBuffer_PBUF[d_CCglo_BufferState] & d_CCglo_BufferValid) != d
;     | _CCglo_BufferValid)                                                    
; 1152 |   t_Channel_UB   = ( t_OutBuffer_PBUF[d_CCglo_ChannelNbr] & d_CCglo_Cha
;     | nnelMask);                                                             
;----------------------------------------------------------------------
        LDRB      V4, [A2, #0]          ; |1149| 
;* 1149	-----------------------    if ( C$5>>7 ) goto g7;
        LSR       A3, V4, #7            ; |1149| 
        BNE       L37                   ; |1149| 
        ; |1149| 
;* --------------------------------------------------------------------------*
;* 1153	-----------------------    K$10 = &CanCtrl_ST+33;
	.dwpsn	"ADLATUS_CanHandler.c",1153,5
;----------------------------------------------------------------------
; 1153 | t_ReadIndex_UB = CanCtrl_ST.ReadIndex_AUB;                             
;----------------------------------------------------------------------
        LDR       V2, CON5              ; |1153| 
        ADD       V2, #33               ; |1153| 
;* 1153	-----------------------    t_ReadIndex_UB = *(unsigned char *)K$10;
        LDRB      A3, [V2, #0]          ; |1153| 
;* 1158	-----------------------    C$4 = &t_CCcan_CanFifoBuffer_AUB;
	.dwpsn	"ADLATUS_CanHandler.c",1158,5
;----------------------------------------------------------------------
; 1158 | if ( d_CCglo_BufferValid ==                            \               
; 1159 |      (  t_CCcan_CanFifoBuffer_AUB[t_ReadIndex_UB     ] \               
; 1160 |                                  [d_CCglo_BufferState] & d_CCglo_Buffer
;     | Valid ))                                                               
;----------------------------------------------------------------------
        LDR       A4, CON8              ; |1158| 
;* 1158	-----------------------    if ( !(C$4[*(unsigned char *)K$10*(C$3 = 12)]>>7) ) goto g7;
        MOV       V1, #12               ; |1158| 
        LDRB      V3, [V2, #0]          ; |1158| 
        MUL       V3, V1                ; |1158| 
        LDRB      V3, [A4, V3]          ; |1158| 
        LSR       V3, V3, #7            ; |1158| 
        BEQ       L37                   ; |1158| 
        ; |1158| 
;* --------------------------------------------------------------------------*
;* 1166	-----------------------    *t_OutBuffer_PBUF = C$5|0xffffff80;
	.dwpsn	"ADLATUS_CanHandler.c",1166,7
;----------------------------------------------------------------------
; 1166 | t_OutBuffer_PBUF[d_CCglo_BufferState] |= d_CCglo_BufferValid;          
;----------------------------------------------------------------------
        MOV       V3, #127              ; |1166| 
        MVN       V3, V3                ; |1166| 
        ORR       V3, V4                ; |1166| 
        STRB      V3, [A2, #0]          ; |1166| 
;* 1158	-----------------------    K$16 = C$4;
	.dwpsn	"ADLATUS_CanHandler.c",1158,5
;* 1170	-----------------------    C$2 = t_ReadIndex_UB*C$3;
	.dwpsn	"ADLATUS_CanHandler.c",1170,7
;----------------------------------------------------------------------
; 1170 | t_OutBuffer_PBUF[d_CCglo_ChannelNbr] = \                               
; 1171 | t_CCcan_CanFifoBuffer_AUB[t_ReadIndex_UB][d_CCglo_ChannelNbr];         
;----------------------------------------------------------------------
        MUL       A3, V1
;* 1170	-----------------------    t_OutBuffer_PBUF[1] = K$16[C$2+1];
        ADD       V1, A3, A4            ; |1170| 
        LDRB      V1, [V1, #1]          ; |1170| 
        STRB      V1, [A2, #1]          ; |1170| 
;* 1175	-----------------------    U$23 = C$2;
	.dwpsn	"ADLATUS_CanHandler.c",1175,7
;----------------------------------------------------------------------
; 1175 | t_OutBuffer_PBUF[d_CCglo_DLC] = \                                      
; 1176 | t_CCcan_CanFifoBuffer_AUB[t_ReadIndex_UB][d_CCglo_DLC];                
;----------------------------------------------------------------------
;* 1175	-----------------------    U$24 = &K$16[U$23];
        ADD       V1, A3, A4            ; |1175| 
        MOV       V9, V1
;* 1175	-----------------------    t_OutBuffer_PBUF[3] = C$1 = K$16[U$23+3];
        ADD       V1, A3, A4            ; |1175| 
        LDRB      V1, [V1, #3]          ; |1175| 
        STRB      V1, [A2, #3]          ; |1175| 
;* 1180	-----------------------    if ( !C$1 ) goto g6;
	.dwpsn	"ADLATUS_CanHandler.c",1180,12
;----------------------------------------------------------------------
; 1180 | for (t_Index_UB   =  0x00u;                                            
; 1181 |      t_Index_UB <  t_OutBuffer_PBUF[d_CCglo_DLC];                      
; 1182 |      t_Index_UB   ++ )                                                 
;----------------------------------------------------------------------
        CMP       V1, #0                ; |1180| 
        BEQ       L36                   ; |1180| 
        ; |1180| 
;* --------------------------------------------------------------------------*
        BR        L34
;******************************************************************************
;* CONSTANT TABLE                                                             *
;******************************************************************************
	.sect	".text"
	.align	4
CON5:	.field  	_CanCtrl_ST,32
;* --------------------------------------------------------------------------*
L34:    
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;* 1180	-----------------------    t_Index_UB = 0u;
        MOV       V3, A1
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L35
;*
;*   Loop source line                : 1180
;*   Loop closing brace source line  : 1188
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L35:    
DWL$$FUN_CCcan_RxData_UB$6$B:
;**	-----------------------g5:
;* 1185	-----------------------    t_OutBuffer_PBUF[t_Index_UB+4] = K$16[t_Index_UB+U$23+4];
	.dwpsn	"ADLATUS_CanHandler.c",1185,9
;----------------------------------------------------------------------
; 1185 | t_OutBuffer_PBUF[d_CCglo_StartOfData + t_Index_UB] = \                 
; 1186 | t_CCcan_CanFifoBuffer_AUB[t_ReadIndex_UB][d_CCglo_StartOfData + t_Index
;     | _UB];                                                                  
;----------------------------------------------------------------------
        ADD       V1, A3, V3            ; |1185| 
        ADD       V1, A4, V1            ; |1185| 
        LDRB      V4, [V1, #4]          ; |1185| 
        ADD       V1, V3, A2            ; |1185| 
        STRB      V4, [V1, #4]          ; |1185| 
;* 1188	-----------------------    if ( t_OutBuffer_PBUF[3] > (++t_Index_UB) ) goto g5;
	.dwpsn	"ADLATUS_CanHandler.c",1188,7
        ADD       V1, V3, #1            ; |1188| 
        LSL       V3, V1, #24           ; |1209| 
        LSR       V3, V3, #24           ; |1209| 
        LDRB      V1, [A2, #3]          ; |1188| 
        CMP       V1, V3                ; |1188| 
        BGT       L35                   ; |1188| 
        ; |1188| 
DWL$$FUN_CCcan_RxData_UB$6$E:
;* --------------------------------------------------------------------------*
L36:    
;**	-----------------------g6:
;* 1193	-----------------------    *U$24 &= 0x7fu;
	.dwpsn	"ADLATUS_CanHandler.c",1193,7
;----------------------------------------------------------------------
; 1193 | t_CCcan_CanFifoBuffer_AUB[t_ReadIndex_UB][d_CCglo_BufferState] &= \    
; 1194 |                                            (UBYTE) ~d_CCglo_BufferValid
;     | ;                                                                      
;----------------------------------------------------------------------
        MOV       A2, V9
        LDRB      A3, [A2, #0]          ; |1193| 
        LSL       A3, A3, #25           ; |1209| 
        LSR       A3, A3, #25           ; |1209| 
        STRB      A3, [A2, #0]          ; |1193| 
;* 1198	-----------------------    *(unsigned char *)K$10 = *(unsigned char *)K$10+1&3;
	.dwpsn	"ADLATUS_CanHandler.c",1198,7
;----------------------------------------------------------------------
; 1198 | CanCtrl_ST.ReadIndex_AUB++;                                            
; 1199 | CanCtrl_ST.ReadIndex_AUB &= (UBYTE) 0x03u;                             
;----------------------------------------------------------------------
        LDRB      A2, [V2, #0]          ; |1198| 
        ADD       A2, #1                ; |1198| 
        LSL       A2, A2, #30           ; |1209| 
        LSR       A2, A2, #30           ; |1209| 
        STRB      A2, [V2, #0]          ; |1198| 
;* 1204	-----------------------    t_Result_UB |= 0x80u;
	.dwpsn	"ADLATUS_CanHandler.c",1204,7
;----------------------------------------------------------------------
; 1204 | t_Result_UB |= d_CCglo_Ready;                                          
;----------------------------------------------------------------------
        MOV       A2, #128              ; |1204| 
        ORR       A2, A1                ; |1204| 
        LSL       A1, A2, #24           ; |1209| 
        LSR       A1, A1, #24           ; |1209| 
;* --------------------------------------------------------------------------*
L37:    
;**	-----------------------g7:
;* 1209	-----------------------    return t_Result_UB;
	.dwpsn	"ADLATUS_CanHandler.c",1209,3
;----------------------------------------------------------------------
; 1209 | return (t_Result_UB);                                                  
;----------------------------------------------------------------------
	.dwpsn	"ADLATUS_CanHandler.c",1211,1
	.dwcfa	0x0e, 20
        POP       {V1, V2, V3, V4, PC}

DW$184	.dwtag  DW_TAG_loop
	.dwattr DW$184, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L35:1:1323432538")
	.dwattr DW$184, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$184, DW_AT_begin_line(0x49c)
	.dwattr DW$184, DW_AT_end_line(0x4a4)
DW$185	.dwtag  DW_TAG_loop_range
	.dwattr DW$185, DW_AT_low_pc(DWL$$FUN_CCcan_RxData_UB$6$B)
	.dwattr DW$185, DW_AT_high_pc(DWL$$FUN_CCcan_RxData_UB$6$E)
	.dwendtag DW$184

	.dwendentry
	.dwendtag DW$168



;******************************************************************************
;* CONSTANT TABLE                                                             *
;******************************************************************************
	.sect	".text"
	.align	4
CON2:	.field  	_e_SCC_ST,32
	.align	4
CON6:	.field  	_c_CCcan_BaudrateTable_AUL,32
	.align	4
CON8:	.field  	_t_CCcan_CanFifoBuffer_AUB,32

	.sect	".text:v$13"
	.clink
	.global	_FUN_CCcan_TxData_UB

DW$186	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_TxData_UB"), DW_AT_symbol_name("_FUN_CCcan_TxData_UB")
	.dwattr DW$186, DW_AT_veneer(0x01)
	.dwattr DW$186, DW_AT_low_pc(_FUN_CCcan_TxData_UB)
	.dwattr DW$186, DW_AT_high_pc(0x00)
	.dwattr DW$186, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CCcan_TxData_UB                                     *
;*****************************************************************************
_FUN_CCcan_TxData_UB:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $FUN_CCcan_TxData_UB
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$186



	.sect	".text"
	.clink
	.global	$FUN_CCcan_TxData_UB

DW$187	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_TxData_UB"), DW_AT_symbol_name("$FUN_CCcan_TxData_UB")
	.dwattr DW$187, DW_AT_low_pc($FUN_CCcan_TxData_UB)
	.dwattr DW$187, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_CanHandler.c",1241,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 1240 | UBYTE FUN_CCcan_TxData_UB (PTR_BUFFER_UB t_InBuffer_PBUF, PTR_BUFFER_UB
;     |  t_OutBuffer_PBUF )                                                    
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CCcan_TxData_UB                                        *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V1,V2,V3,V4,V5,V9,SP,LR,SR              *
;*   Regs Used         : A1,A2,A3,A4,V1,V2,V3,V4,V5,V9,SP,LR,SR              *
;*   Local Frame Size  : 0 Args + 0 Auto + 24 Save = 24 byte                 *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CCcan_TxData_UB:
;* --------------------------------------------------------------------------*
	.dwcfa	0x09, 26, 14
        PUSH      {V1, V2, V3, V4, LR}
        MOV       A3, V5
        PUSH      {A3}
	.dwcfa	0x0e, 4
	.dwcfa	0x80, 14, 1
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 8, 2
	.dwcfa	0x0e, 12
	.dwcfa	0x80, 7, 3
	.dwcfa	0x0e, 16
	.dwcfa	0x80, 6, 4
	.dwcfa	0x0e, 20
	.dwcfa	0x80, 5, 5
	.dwcfa	0x0e, 24
	.dwcfa	0x80, 4, 6
	.dwcfa	0x0e, 24
;* A1    assigned to _t_InBuffer_PBUF
DW$188	.dwtag  DW_TAG_formal_parameter, DW_AT_name("t_InBuffer_PBUF"), DW_AT_symbol_name("_t_InBuffer_PBUF")
	.dwattr DW$188, DW_AT_type(*DWT$1023)
	.dwattr DW$188, DW_AT_location[DW_OP_reg0]
;* A2    assigned to _t_OutBuffer_PBUF
DW$189	.dwtag  DW_TAG_formal_parameter, DW_AT_name("t_OutBuffer_PBUF"), DW_AT_symbol_name("_t_OutBuffer_PBUF")
	.dwattr DW$189, DW_AT_type(*DWT$1023)
	.dwattr DW$189, DW_AT_location[DW_OP_reg1]
;* V4    assigned to C$1
DW$190	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$190, DW_AT_type(*DWT$1040)
	.dwattr DW$190, DW_AT_location[DW_OP_reg7]
;* A2    assigned to C$2
DW$191	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$191, DW_AT_type(*DWT$1181)
	.dwattr DW$191, DW_AT_location[DW_OP_reg1]
;* A2    assigned to C$3
DW$192	.dwtag  DW_TAG_variable, DW_AT_name("C$3"), DW_AT_symbol_name("C$3")
	.dwattr DW$192, DW_AT_type(*DWT$1181)
	.dwattr DW$192, DW_AT_location[DW_OP_reg1]
;* A2    assigned to C$4
DW$193	.dwtag  DW_TAG_variable, DW_AT_name("C$4"), DW_AT_symbol_name("C$4")
	.dwattr DW$193, DW_AT_type(*DWT$6)
	.dwattr DW$193, DW_AT_location[DW_OP_reg1]
;* V2    assigned to C$5
DW$194	.dwtag  DW_TAG_variable, DW_AT_name("C$5"), DW_AT_symbol_name("C$5")
	.dwattr DW$194, DW_AT_type(*DWT$6)
	.dwattr DW$194, DW_AT_location[DW_OP_reg5]
;* A4    assigned to C$6
DW$195	.dwtag  DW_TAG_variable, DW_AT_name("C$6"), DW_AT_symbol_name("C$6")
	.dwattr DW$195, DW_AT_type(*DWT$1041)
	.dwattr DW$195, DW_AT_location[DW_OP_reg3]
;* V2    assigned to C$7
DW$196	.dwtag  DW_TAG_variable, DW_AT_name("C$7"), DW_AT_symbol_name("C$7")
	.dwattr DW$196, DW_AT_type(*DWT$1115)
	.dwattr DW$196, DW_AT_location[DW_OP_reg5]
;* LR    assigned to Q$1
DW$197	.dwtag  DW_TAG_variable, DW_AT_name("Q$1"), DW_AT_symbol_name("Q$1")
	.dwattr DW$197, DW_AT_type(*DWT$1041)
	.dwattr DW$197, DW_AT_location[DW_OP_reg14]
;* A1    assigned to _t_Index_UB
DW$198	.dwtag  DW_TAG_variable, DW_AT_name("t_Index_UB"), DW_AT_symbol_name("_t_Index_UB")
	.dwattr DW$198, DW_AT_type(*DWT$11)
	.dwattr DW$198, DW_AT_location[DW_OP_reg0]
;* V1    assigned to _t_InBuffer_PBUF
DW$199	.dwtag  DW_TAG_variable, DW_AT_name("t_InBuffer_PBUF"), DW_AT_symbol_name("_t_InBuffer_PBUF")
	.dwattr DW$199, DW_AT_type(*DWT$1024)
	.dwattr DW$199, DW_AT_location[DW_OP_reg4]
;* V5    assigned to _t_Result_UB
DW$200	.dwtag  DW_TAG_variable, DW_AT_name("t_Result_UB"), DW_AT_symbol_name("_t_Result_UB")
	.dwattr DW$200, DW_AT_type(*DWT$1018)
	.dwattr DW$200, DW_AT_location[DW_OP_reg8]
;* A2    assigned to _t_TableLine_UB
DW$201	.dwtag  DW_TAG_variable, DW_AT_name("t_TableLine_UB"), DW_AT_symbol_name("_t_TableLine_UB")
	.dwattr DW$201, DW_AT_type(*DWT$1018)
	.dwattr DW$201, DW_AT_location[DW_OP_reg1]
;* A1    assigned to _t_State_UB
DW$202	.dwtag  DW_TAG_variable, DW_AT_name("t_State_UB"), DW_AT_symbol_name("_t_State_UB")
	.dwattr DW$202, DW_AT_type(*DWT$1018)
	.dwattr DW$202, DW_AT_location[DW_OP_reg0]
;* V4    assigned to _t_EndlessLoopProtection_UL
DW$203	.dwtag  DW_TAG_variable, DW_AT_name("t_EndlessLoopProtection_UL"), DW_AT_symbol_name("_t_EndlessLoopProtection_UL")
	.dwattr DW$203, DW_AT_type(*DWT$1054)
	.dwattr DW$203, DW_AT_location[DW_OP_reg7]
;* V3    assigned to _t_Mailbox_UB
DW$204	.dwtag  DW_TAG_variable, DW_AT_name("t_Mailbox_UB"), DW_AT_symbol_name("_t_Mailbox_UB")
	.dwattr DW$204, DW_AT_type(*DWT$1018)
	.dwattr DW$204, DW_AT_location[DW_OP_reg6]
;* V9    assigned to K$79
DW$205	.dwtag  DW_TAG_variable, DW_AT_name("K$79"), DW_AT_symbol_name("K$79")
	.dwattr DW$205, DW_AT_type(*DWT$11)
	.dwattr DW$205, DW_AT_location[DW_OP_reg12]
;* A3    assigned to K$67
DW$206	.dwtag  DW_TAG_variable, DW_AT_name("K$67"), DW_AT_symbol_name("K$67")
	.dwattr DW$206, DW_AT_type(*DWT$1181)
	.dwattr DW$206, DW_AT_location[DW_OP_reg2]
;* V4    assigned to U$40
DW$207	.dwtag  DW_TAG_variable, DW_AT_name("U$40"), DW_AT_symbol_name("U$40")
	.dwattr DW$207, DW_AT_type(*DWT$1018)
	.dwattr DW$207, DW_AT_location[DW_OP_reg7]
;* V2    assigned to K$54
DW$208	.dwtag  DW_TAG_variable, DW_AT_name("K$54"), DW_AT_symbol_name("K$54")
	.dwattr DW$208, DW_AT_type(*DWT$1145)
	.dwattr DW$208, DW_AT_location[DW_OP_reg5]
;* A3    assigned to K$15
DW$209	.dwtag  DW_TAG_variable, DW_AT_name("K$15"), DW_AT_symbol_name("K$15")
	.dwattr DW$209, DW_AT_type(*DWT$1184)
	.dwattr DW$209, DW_AT_location[DW_OP_reg2]
;* A4    assigned to K$39
DW$210	.dwtag  DW_TAG_variable, DW_AT_name("K$39"), DW_AT_symbol_name("K$39")
	.dwattr DW$210, DW_AT_type(*DWT$1030)
	.dwattr DW$210, DW_AT_location[DW_OP_reg3]
;* V2    assigned to U$17
DW$211	.dwtag  DW_TAG_variable, DW_AT_name("U$17"), DW_AT_symbol_name("U$17")
	.dwattr DW$211, DW_AT_type(*DWT$1066)
	.dwattr DW$211, DW_AT_location[DW_OP_reg5]
;* A4    assigned to U$16
DW$212	.dwtag  DW_TAG_variable, DW_AT_name("U$16"), DW_AT_symbol_name("U$16")
	.dwattr DW$212, DW_AT_type(*DWT$1066)
	.dwattr DW$212, DW_AT_location[DW_OP_reg3]
;----------------------------------------------------------------------
; 1243 | UBYTE t_Result_UB;                                                     
; 1244 | UBYTE t_TableLine_UB;                                                  
; 1245 | UBYTE t_Index_UB;                                                      
; 1246 | static UBYTE t_MsgObjNbr_UB;                                           
; 1247 | UBYTE t_State_UB;                                                      
; 1248 | ULONG t_EndlessLoopProtection_UL;                                      
; 1250 | UBYTE t_Mailbox_UB;                                                    
; 1252 | #ifdef cs_CCTP20                                                       
; 1253 | UBYTE t_Channel_UB;                                                    
; 1254 | #endif                                                                 
; 1257 | t_OutBuffer_PBUF += 0x00;                                              
; 1259 | #ifdef cs_CCTP20                                                       
; 1266 | t_Channel_UB = t_InBuffer_PBUF[d_CCglo_ChannelNbr];                    
; 1268 |  FUN_CCcan_TxDataTP20_UB ((PTR_BUFFER_UB) &t_InBuffer_PBUF[0u] );      
; 1269 | #endif                                                                 
;----------------------------------------------------------------------
        MOV       V1, A1
;* 1274	-----------------------    t_Result_UB = 0u;
	.dwpsn	"ADLATUS_CanHandler.c",1274,3
;----------------------------------------------------------------------
; 1274 | t_Result_UB = d_CCglo_Idle;                                            
;----------------------------------------------------------------------
        MOV       A1, #0                ; |1274| 
        MOV       V5, A1
;* 1281	-----------------------    if ( !(*t_InBuffer_PBUF>>7) ) goto g31;
	.dwpsn	"ADLATUS_CanHandler.c",1281,3
;----------------------------------------------------------------------
; 1281 | if ( d_CCglo_BufferValid == (t_InBuffer_PBUF[d_CCglo_BufferState] & d_C
;     | Cglo_BufferValid))                                                     
;----------------------------------------------------------------------
        LDRB      A1, [V1, #0]          ; |1281| 
        LSR       A1, A1, #7            ; |1281| 
        BEQ       L52                   ; |1281| 
        ; |1281| 
;* --------------------------------------------------------------------------*
;**  	-----------------------    K$15 = &CanCtrl_ST;
        LDR       A3, CON11
;**  	-----------------------    U$16 = K$15->CanChannelTable_PST;
        LDR       A4, [A3, #4]
;* 1284	-----------------------    t_State_UB = 0u;
	.dwpsn	"ADLATUS_CanHandler.c",1284,5
;----------------------------------------------------------------------
; 1284 | t_State_UB     = 0x00u;                                                
;----------------------------------------------------------------------
        MOV       A2, V5
        MOV       A1, V5
;* 1285	-----------------------    t_TableLine_UB = 0u;
	.dwpsn	"ADLATUS_CanHandler.c",1285,5
;----------------------------------------------------------------------
; 1285 | t_TableLine_UB = 0x00u;                                                
; 1292 | while ( d_CCcan_StopScan != (t_State_UB & d_CCcan_StopScan) )          
;----------------------------------------------------------------------
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L38
;*
;*   Loop source line                : 1292
;*   Loop closing brace source line  : 1330
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L38:    
DWL$$FUN_CCcan_TxData_UB$3$B:
;**	-----------------------g3:
;* 1297	-----------------------    U$17 = &U$16[t_TableLine_UB];
	.dwpsn	"ADLATUS_CanHandler.c",1297,7
;----------------------------------------------------------------------
; 1297 | if ( d_CCglo_NoEntry == CanCtrl_ST.CanChannelTable_PST[t_TableLine_UB].
;     | MsgObjectNbr_UB )                                                      
; 1300 |   t_State_UB = d_CCcan_StopScan;                                       
; 1306 | else                                                                   
;----------------------------------------------------------------------
        LSL       V2, A2, #2            ; |1297| 
        ADD       V2, A4, V2            ; |1297| 
;* 1297	-----------------------    if ( U$17->MsgObjectNbr_UB == 255 ) goto g31;
        LDRB      V3, [V2, #0]          ; |1297| 
        CMP       V3, #255              ; |1297| 
        BEQ       L52                   ; |1297| 
        ; |1297| 
DWL$$FUN_CCcan_TxData_UB$3$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_TxData_UB$4$B:
;* 1312	-----------------------    if ( t_InBuffer_PBUF[1] == U$17->ChannelNbr_UB ) goto g7;
	.dwpsn	"ADLATUS_CanHandler.c",1312,9
;----------------------------------------------------------------------
; 1312 | if ( t_InBuffer_PBUF[d_CCglo_ChannelNbr] != \                          
; 1313 |      CanCtrl_ST.CanChannelTable_PST[t_TableLine_UB].ChannelNbr_UB )    
;----------------------------------------------------------------------
        LDRB      V2, [V2, #1]          ; |1312| 
        LDRB      V3, [V1, #1]          ; |1312| 
        CMP       V3, V2                ; |1312| 
        BEQ       L39                   ; |1312| 
        ; |1312| 
DWL$$FUN_CCcan_TxData_UB$4$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_TxData_UB$5$B:
;* 1316	-----------------------    ++t_TableLine_UB;
	.dwpsn	"ADLATUS_CanHandler.c",1316,11
;----------------------------------------------------------------------
; 1316 | t_TableLine_UB ++;                                                     
;----------------------------------------------------------------------
        ADD       A2, A2, #1            ; |1316| 
        LSL       A2, A2, #24
        LSR       A2, A2, #24
;* 1318	-----------------------    if ( !(t_State_UB&1) ) goto g3;
	.dwpsn	"ADLATUS_CanHandler.c",1318,9
;----------------------------------------------------------------------
; 1323 | else                                                                   
; 1326 |   t_State_UB = (d_CCcan_StopScan | d_CCcan_CorrectMsgEntryFound);      
;----------------------------------------------------------------------
        LSR       V2, A1, #1            ; |1318| 
        BCC       L38                   ; |1318| 
        ; |1318| 
DWL$$FUN_CCcan_TxData_UB$5$E:
;* --------------------------------------------------------------------------*
;* 1338	-----------------------    if ( t_State_UB&0x8 ) goto g8;
	.dwpsn	"ADLATUS_CanHandler.c",1338,5
;----------------------------------------------------------------------
; 1338 | if ( d_CCcan_CorrectMsgEntryFound ==  (t_State_UB & d_CCcan_CorrectMsgE
;     | ntryFound))                                                            
;----------------------------------------------------------------------
        LSR       V2, A1, #4            ; |1338| 
        BCS       L40                   ; |1338| 
        ; |1338| 
;* --------------------------------------------------------------------------*
;* 1338	-----------------------    goto g31;
        B         L52                   ; |1338| 
        ; |1338| 
;* --------------------------------------------------------------------------*
L39:    
;**	-----------------------g7:
;* 1326	-----------------------    t_State_UB = 9u;
	.dwpsn	"ADLATUS_CanHandler.c",1326,11
        MOV       A1, #9                ; |1326| 
;* --------------------------------------------------------------------------*
L40:    
;**	-----------------------g8:
;* 1343	-----------------------    C$7 = &U$16[t_TableLine_UB];
	.dwpsn	"ADLATUS_CanHandler.c",1343,7
;----------------------------------------------------------------------
; 1343 | t_MsgObjNbr_UB = CanCtrl_ST.CanChannelTable_PST[t_TableLine_UB].MsgObje
;     | ctNbr_UB;                                                              
;----------------------------------------------------------------------
        LSL       A2, A2, #2            ; |1343| 
        ADD       V2, A4, A2            ; |1343| 
;* 1343	-----------------------    C$6 = &t_MsgObjNbr_UB;
        LDR       A4, CON10             ; |1343| 
;* 1343	-----------------------    *C$6 = C$4 = C$7->MsgObjectNbr_UB;
        LDRB      A2, [V2, #0]          ; |1343| 
        STRB      A2, [A4, #0]          ; |1343| 
;* 1345	-----------------------    C$5 = C$7->AddIdByteInfo_UB;
	.dwpsn	"ADLATUS_CanHandler.c",1345,7
;----------------------------------------------------------------------
; 1345 | t_State_UB |= (CanCtrl_ST.CanChannelTable_PST[t_TableLine_UB].AddIdByte
;     | Info_UB & d_CCglo_FixedMsgLgnth);                                      
;----------------------------------------------------------------------
        LDRB      V2, [V2, #2]          ; |1345| 
;* 1345	-----------------------    t_State_UB |= C$5&0x10;
        MOV       V3, #16               ; |1345| 
        AND       V3, V2                ; |1345| 
        ORR       V3, A1                ; |1345| 
        LSL       A1, V3, #24
        LSR       A1, A1, #24
;* 1343	-----------------------    K$39 = C$6;
	.dwpsn	"ADLATUS_CanHandler.c",1343,7
;* 1348	-----------------------    if ( !(C$5&0x40) ) goto g10;
	.dwpsn	"ADLATUS_CanHandler.c",1348,7
;----------------------------------------------------------------------
; 1348 | if(d_CCglo_MbSendFromRam == (CanCtrl_ST.CanChannelTable_PST[t_TableLine
;     | _UB].AddIdByteInfo_UB & d_CCglo_MbSendFromRam))                        
;----------------------------------------------------------------------
        LSR       V2, V2, #7            ; |1348| 
        BCC       L41                   ; |1348| 
        ; |1348| 
;* --------------------------------------------------------------------------*
;* 1350	-----------------------    K$15->MbUsedinRAM_UB = C$4;
	.dwpsn	"ADLATUS_CanHandler.c",1350,9
;----------------------------------------------------------------------
; 1350 | CanCtrl_ST.MbUsedinRAM_UB = t_MsgObjNbr_UB;                            
;----------------------------------------------------------------------
        STRB      A2, [A3, #16]         ; |1350| 
;* --------------------------------------------------------------------------*
L41:    
;**	-----------------------g10:
;* 1354	-----------------------    U$40 = *K$39;
	.dwpsn	"ADLATUS_CanHandler.c",1354,7
;----------------------------------------------------------------------
; 1354 | t_Mailbox_UB = 0x00000001UL << t_MsgObjNbr_UB;                         
; 1359 | while ((e_SCC_ST.CANTRS_UL & (ULONG)t_Mailbox_UB) != 0ul)              
; 1361 |   ;                                                                    
;----------------------------------------------------------------------
        LDRB      V4, [A4, #0]          ; |1354| 
;* 1354	-----------------------    t_Mailbox_UB = 1u<<U$40;
        MOV       A2, #1                ; |1354| 
        LSL       A2, V4                ; |1354| 
        LSL       V3, A2, #24
        LSR       V3, V3, #24
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;**  	-----------------------    K$54 = &e_SCC_ST;
        LDR       V2, CON12
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L42
;*
;*   Loop source line                : 1359
;*   Loop closing brace source line  : 1362
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L42:    
DWL$$FUN_CCcan_TxData_UB$12$B:
;**	-----------------------g12:
;* 1362	-----------------------    if ( K$54->CANTRS_UL&t_Mailbox_UB ) goto g12;
	.dwpsn	"ADLATUS_CanHandler.c",1362,7
        LDR       A2, [V2, #8]          ; |1362| 
        TST       V3, A2                ; |1362| 
        BNE       L42                   ; |1362| 
        ; |1362| 
DWL$$FUN_CCcan_TxData_UB$12$E:
;* --------------------------------------------------------------------------*
;* 1367	-----------------------    if ( t_State_UB&0x10 ) goto g15;
	.dwpsn	"ADLATUS_CanHandler.c",1367,7
;----------------------------------------------------------------------
; 1367 | if (d_CCglo_FixedMsgLgnth != (t_State_UB & d_CCglo_FixedMsgLgnth))     
;----------------------------------------------------------------------
        LDR       A2, CON13             ; |1373| 
        LSR       A1, A1, #5            ; |1367| 
        BCS       L43                   ; |1367| 
        ; |1367| 
;* --------------------------------------------------------------------------*
;* 1369	-----------------------    C$3 = &e_CAN_MB[0];
	.dwpsn	"ADLATUS_CanHandler.c",1369,10
;----------------------------------------------------------------------
; 1369 | e_CAN_MB[t_MsgObjNbr_UB].MCF_ST.bw.CanMCF = ((t_InBuffer_PBUF[d_CCglo_D
;     | LC]) & 0x0F);                                                          
;----------------------------------------------------------------------
;* 1369	-----------------------    (((int)U$40<<4)+C$3)->MCF_ST.bw.CanMCF = t_InBuffer_PBUF[3]&0xf;
        LSL       A1, V4, #4            ; |1369| 
        ADD       A1, A2, A1            ; |1369| 
        LDRB      A3, [V1, #3]          ; |1369| 
        LSL       A3, A3, #28
        LSR       A3, A3, #28
        STRB      A3, [A1, #7]          ; |1369| 
;* 1369	-----------------------    K$67 = C$3;
        MOV       A3, A2
;* 1370	-----------------------    goto g16;
	.dwpsn	"ADLATUS_CanHandler.c",1370,7
;----------------------------------------------------------------------
; 1371 | else                                                                   
;----------------------------------------------------------------------
        B         L44                   ; |1370| 
        ; |1370| 
;* --------------------------------------------------------------------------*
L43:    
;**	-----------------------g15:
;* 1373	-----------------------    C$2 = &e_CAN_MB[0];
	.dwpsn	"ADLATUS_CanHandler.c",1373,10
;----------------------------------------------------------------------
; 1373 | e_CAN_MB[t_MsgObjNbr_UB].MCF_ST.bw.CanMCF = 0x08u;                     
; 1379 | #ifdef cs_CCFixed_Msg_LENGTH                                           
; 1380 | for (t_Index_UB = (UBYTE)  0x00u;                                      
; 1381 |   t_Index_UB < (UBYTE)  0x08u;                                         
; 1382 |   t_Index_UB ++ )                                                      
; 1383 | #else                                                                  
; 1384 | for (t_Index_UB = (UBYTE) 0x00u;                                       
; 1385 |   t_Index_UB <  t_InBuffer_PBUF[d_CCglo_DLC];                          
; 1386 |   t_Index_UB ++ )                                                      
; 1387 | #endif                                                                 
;----------------------------------------------------------------------
;* 1373	-----------------------    (((int)U$40<<4)+C$2)->MCF_ST.bw.CanMCF = 8;
        LSL       A1, V4, #4            ; |1373| 
        ADD       A1, A2, A1            ; |1373| 
        MOV       A3, #8                ; |1373| 
        STRB      A3, [A1, #7]          ; |1373| 
;* 1373	-----------------------    K$67 = C$2;
        MOV       A3, A2
;* --------------------------------------------------------------------------*
L44:    
;**	-----------------------g16:
;**  	-----------------------    #pragma MUST_ITERATE(8, 8, 8)
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;**  	-----------------------    K$79 = 0;
        MOV       A1, V5
;**  	-----------------------    Q$1 = &t_InBuffer_PBUF[4];
        ADD       A2, V1, #4
        MOV       LR, A2
;**  	-----------------------    t_Index_UB = 0;
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L45
;*
;*   Loop source line                : 1380
;*   Loop closing brace source line  : 1398
;*   Known Minimum Trip Count        : 8
;*   Known Maximum Trip Count        : 8
;*   Known Max Trip Count Factor     : 8
;* --------------------------------------------------------------------------*
L45:    
DWL$$FUN_CCcan_TxData_UB$17$B:
;**	-----------------------g18:
;* 1390	-----------------------    C$1 = ((int)*K$39<<4)+t_Index_UB+(volatile unsigned char *)K$67;
	.dwpsn	"ADLATUS_CanHandler.c",1390,9
;----------------------------------------------------------------------
; 1390 | e_CAN_MB[t_MsgObjNbr_UB].u.CanData_UB[t_Index_UB] =                    
; 1391 |                      t_InBuffer_PBUF[d_CCglo_StartOfData + t_Index_UB];
;----------------------------------------------------------------------
        LDRB      V4, [A4, #0]          ; |1390| 
        LSL       V4, V4, #4            ; |1390| 
        ADD       V4, A1, V4            ; |1390| 
        ADD       V4, A3, V4            ; |1390| 
;* 1390	-----------------------    C$1[8] = Q$1[t_Index_UB];
        MOV       A2, LR
        LDRB      A2, [A1, A2]          ; |1390| 
        STRB      A2, [V4, #8]          ; |1390| 
;* 1393	-----------------------    if ( t_Index_UB <= t_InBuffer_PBUF[3] ) goto g20;
	.dwpsn	"ADLATUS_CanHandler.c",1393,9
;----------------------------------------------------------------------
; 1393 | if (t_Index_UB > t_InBuffer_PBUF[d_CCglo_DLC])                         
;----------------------------------------------------------------------
        LDRB      A2, [V1, #3]          ; |1393| 
        CMP       A1, A2                ; |1393| 
        BLE       L46                   ; |1393| 
        ; |1393| 
DWL$$FUN_CCcan_TxData_UB$17$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_TxData_UB$18$B:
;* 1395	-----------------------    C$1[8] = K$79;
	.dwpsn	"ADLATUS_CanHandler.c",1395,13
;----------------------------------------------------------------------
; 1395 | e_CAN_MB[t_MsgObjNbr_UB].u.CanData_UB[t_Index_UB] = 0x00u;             
;----------------------------------------------------------------------
        MOV       A2, V5
        STRB      A2, [V4, #8]          ; |1395| 
DWL$$FUN_CCcan_TxData_UB$18$E:
;* --------------------------------------------------------------------------*
L46:    
DWL$$FUN_CCcan_TxData_UB$19$B:
;**	-----------------------g20:
;* 1398	-----------------------    if ( (++t_Index_UB) < 8 ) goto g18;
	.dwpsn	"ADLATUS_CanHandler.c",1398,7
;----------------------------------------------------------------------
; 1402 | while (e_SCC_ST.CANES_UN.CANES_ST.RM_B1)                               
; 1404 |    ;                                                                   
;----------------------------------------------------------------------
        ADD       A1, #1                ; |1398| 
        CMP       A1, #8                ; |1398| 
        BLT       L45                   ; |1398| 
        ; |1398| 
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
DWL$$FUN_CCcan_TxData_UB$19$E:
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L47
;*
;*   Loop source line                : 1402
;*   Loop closing brace source line  : 1405
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L47:    
DWL$$FUN_CCcan_TxData_UB$20$B:
;**	-----------------------g23:
;* 1405	-----------------------    if ( *((volatile struct $$fake2 *)&e_SCC_ST+51)&2u ) goto g23;
	.dwpsn	"ADLATUS_CanHandler.c",1405,7
        LDR       A1, CON14             ; |1405| 
        LDRB      A1, [A1, #0]          ; |1405| 
        LSR       A1, A1, #2            ; |1405| 
        BCS       L47                   ; |1405| 
        ; |1405| 
DWL$$FUN_CCcan_TxData_UB$20$E:
;* --------------------------------------------------------------------------*
;* 1408	-----------------------    K$54->CANTA_UL |= t_Mailbox_UB;
	.dwpsn	"ADLATUS_CanHandler.c",1408,7
;----------------------------------------------------------------------
; 1408 | e_SCC_ST.CANTA_UL  |= (ULONG)t_Mailbox_UB;                             
;----------------------------------------------------------------------
        LDR       A1, [V2, #16]         ; |1408| 
        ORR       A1, V3                ; |1408| 
        STR       A1, [V2, #16]         ; |1408| 
;* 1409	-----------------------    K$54->CANTRS_UL |= t_Mailbox_UB;
	.dwpsn	"ADLATUS_CanHandler.c",1409,7
;----------------------------------------------------------------------
; 1409 | e_SCC_ST.CANTRS_UL |= (ULONG)t_Mailbox_UB;                             
;----------------------------------------------------------------------
        LDR       A1, [V2, #8]          ; |1409| 
        ORR       A1, V3                ; |1409| 
        STR       A1, [V2, #8]          ; |1409| 
;* 1412	-----------------------    t_EndlessLoopProtection_UL = 0xffffffffu;
	.dwpsn	"ADLATUS_CanHandler.c",1412,7
;----------------------------------------------------------------------
; 1412 | t_EndlessLoopProtection_UL = 0xFFFFFFFFul;                             
;----------------------------------------------------------------------
        MOV       A1, #0                ; |1412| 
        MVN       V4, A1                ; |1412| 
;**  	-----------------------    #pragma LOOP_FLAGS(5376u)
;* 1416	-----------------------    goto g27;
	.dwpsn	"ADLATUS_CanHandler.c",1416,7
;----------------------------------------------------------------------
; 1416 | while (((e_SCC_ST.CANTA_UL & (ULONG)t_Mailbox_UB) == 0ul) && \         
; 1417 |                   (0ul != t_EndlessLoopProtection_UL))                 
; 1420 |     t_EndlessLoopProtection_UL--;                                      
; 1425 |     FUN_CCtim_SystemTimerCheck_V ();                                   
;----------------------------------------------------------------------
        B         L49                   ; |1416| 
        ; |1416| 
;* --------------------------------------------------------------------------*
L48:    
DWL$$FUN_CCcan_TxData_UB$22$B:
;**	-----------------------g25:
;* 1427	-----------------------    if ( !t_EndlessLoopProtection_UL ) goto g29;
	.dwpsn	"ADLATUS_CanHandler.c",1427,7
        CMP       V4, #0                ; |1427| 
        BEQ       L50                   ; |1427| 
        ; |1427| 
DWL$$FUN_CCcan_TxData_UB$22$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_TxData_UB$23$B:
;* 1420	-----------------------    --t_EndlessLoopProtection_UL;
	.dwpsn	"ADLATUS_CanHandler.c",1420,11
        SUB       V4, #1                ; |1420| 
;* 1425	-----------------------    FUN_CCtim_SystemTimerCheck_V();
	.dwpsn	"ADLATUS_CanHandler.c",1425,11
        BL        $FUN_CCtim_SystemTimerCheck_V ; |1425| 
        ; |1425| 
DWL$$FUN_CCcan_TxData_UB$23$E:
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L49
;* --------------------------------------------------------------------------*
L49:    
DWL$$FUN_CCcan_TxData_UB$24$B:
;**	-----------------------g27:
;* 1425	-----------------------    if ( !(K$54->CANTA_UL&t_Mailbox_UB) ) goto g25;
        LDR       A1, [V2, #16]         ; |1425| 
        TST       V3, A1                ; |1425| 
        BEQ       L48                   ; |1425| 
        ; |1425| 
DWL$$FUN_CCcan_TxData_UB$24$E:
;* --------------------------------------------------------------------------*
;* 1432	-----------------------    if ( t_EndlessLoopProtection_UL ) goto g30;
	.dwpsn	"ADLATUS_CanHandler.c",1432,7
;----------------------------------------------------------------------
; 1432 | if (0x0000ul == t_EndlessLoopProtection_UL)                            
; 1438 |   t_Result_UB |= d_CCglo_Busy;                                         
;----------------------------------------------------------------------
        CMP       V4, #0                ; |1432| 
        BNE       L51                   ; |1432| 
        ; |1432| 
;* --------------------------------------------------------------------------*
L50:    
;**	-----------------------g29:
;* 1440	-----------------------    return t_Result_UB |= 0x40u;
	.dwpsn	"ADLATUS_CanHandler.c",1440,7
;----------------------------------------------------------------------
; 1445 | else                                                                   
;----------------------------------------------------------------------
        MOV       A2, #64               ; |1440| 
        MOV       A1, V5
        ORR       A2, A1                ; |1440| 
        LSL       A1, A2, #24
        LSR       A1, A1, #24
        POP       {A3}
        MOV       V5, A3
        POP       {V1, V2, V3, V4, PC}
;* --------------------------------------------------------------------------*
L51:    
;**	-----------------------g30:
;* 1450	-----------------------    *t_InBuffer_PBUF &= 0x7fu;
	.dwpsn	"ADLATUS_CanHandler.c",1450,9
;----------------------------------------------------------------------
; 1450 | t_InBuffer_PBUF[d_CCglo_BufferState] &= (UBYTE) ~d_CCglo_BufferValid;  
;----------------------------------------------------------------------
        LDRB      A1, [V1, #0]          ; |1450| 
        LSL       A1, A1, #25
        LSR       A1, A1, #25
        STRB      A1, [V1, #0]          ; |1450| 
;* 1455	-----------------------    t_Result_UB |= 0x80u;
	.dwpsn	"ADLATUS_CanHandler.c",1455,9
;----------------------------------------------------------------------
; 1455 | t_Result_UB |= d_CCglo_Ready;                                          
;----------------------------------------------------------------------
        MOV       A2, #128              ; |1455| 
        MOV       A1, V5
        ORR       A2, A1                ; |1455| 
        LSL       A1, A2, #24
        LSR       A1, A1, #24
        MOV       V5, A1
;* --------------------------------------------------------------------------*
L52:    
;**	-----------------------g31:
;* 1461	-----------------------    return t_Result_UB;
	.dwpsn	"ADLATUS_CanHandler.c",1461,3
;----------------------------------------------------------------------
; 1461 | return (t_Result_UB);                                                  
;----------------------------------------------------------------------
        MOV       A1, V5
	.dwpsn	"ADLATUS_CanHandler.c",1463,1
	.dwcfa	0x0e, 24
        POP       {A3}
        MOV       V5, A3
        POP       {V1, V2, V3, V4, PC}

DW$213	.dwtag  DW_TAG_loop
	.dwattr DW$213, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L49:1:1323432538")
	.dwattr DW$213, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$213, DW_AT_begin_line(0x588)
	.dwattr DW$213, DW_AT_end_line(0x593)
DW$214	.dwtag  DW_TAG_loop_range
	.dwattr DW$214, DW_AT_low_pc(DWL$$FUN_CCcan_TxData_UB$24$B)
	.dwattr DW$214, DW_AT_high_pc(DWL$$FUN_CCcan_TxData_UB$24$E)
DW$215	.dwtag  DW_TAG_loop_range
	.dwattr DW$215, DW_AT_low_pc(DWL$$FUN_CCcan_TxData_UB$22$B)
	.dwattr DW$215, DW_AT_high_pc(DWL$$FUN_CCcan_TxData_UB$22$E)
DW$216	.dwtag  DW_TAG_loop_range
	.dwattr DW$216, DW_AT_low_pc(DWL$$FUN_CCcan_TxData_UB$23$B)
	.dwattr DW$216, DW_AT_high_pc(DWL$$FUN_CCcan_TxData_UB$23$E)
	.dwendtag DW$213


DW$217	.dwtag  DW_TAG_loop
	.dwattr DW$217, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L47:1:1323432538")
	.dwattr DW$217, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$217, DW_AT_begin_line(0x57a)
	.dwattr DW$217, DW_AT_end_line(0x57d)
DW$218	.dwtag  DW_TAG_loop_range
	.dwattr DW$218, DW_AT_low_pc(DWL$$FUN_CCcan_TxData_UB$20$B)
	.dwattr DW$218, DW_AT_high_pc(DWL$$FUN_CCcan_TxData_UB$20$E)
	.dwendtag DW$217


DW$219	.dwtag  DW_TAG_loop
	.dwattr DW$219, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L45:1:1323432538")
	.dwattr DW$219, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$219, DW_AT_begin_line(0x564)
	.dwattr DW$219, DW_AT_end_line(0x576)
DW$220	.dwtag  DW_TAG_loop_range
	.dwattr DW$220, DW_AT_low_pc(DWL$$FUN_CCcan_TxData_UB$17$B)
	.dwattr DW$220, DW_AT_high_pc(DWL$$FUN_CCcan_TxData_UB$17$E)
DW$221	.dwtag  DW_TAG_loop_range
	.dwattr DW$221, DW_AT_low_pc(DWL$$FUN_CCcan_TxData_UB$18$B)
	.dwattr DW$221, DW_AT_high_pc(DWL$$FUN_CCcan_TxData_UB$18$E)
DW$222	.dwtag  DW_TAG_loop_range
	.dwattr DW$222, DW_AT_low_pc(DWL$$FUN_CCcan_TxData_UB$19$B)
	.dwattr DW$222, DW_AT_high_pc(DWL$$FUN_CCcan_TxData_UB$19$E)
	.dwendtag DW$219


DW$223	.dwtag  DW_TAG_loop
	.dwattr DW$223, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L42:1:1323432538")
	.dwattr DW$223, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$223, DW_AT_begin_line(0x54f)
	.dwattr DW$223, DW_AT_end_line(0x552)
DW$224	.dwtag  DW_TAG_loop_range
	.dwattr DW$224, DW_AT_low_pc(DWL$$FUN_CCcan_TxData_UB$12$B)
	.dwattr DW$224, DW_AT_high_pc(DWL$$FUN_CCcan_TxData_UB$12$E)
	.dwendtag DW$223


DW$225	.dwtag  DW_TAG_loop
	.dwattr DW$225, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L38:1:1323432538")
	.dwattr DW$225, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$225, DW_AT_begin_line(0x50c)
	.dwattr DW$225, DW_AT_end_line(0x532)
DW$226	.dwtag  DW_TAG_loop_range
	.dwattr DW$226, DW_AT_low_pc(DWL$$FUN_CCcan_TxData_UB$3$B)
	.dwattr DW$226, DW_AT_high_pc(DWL$$FUN_CCcan_TxData_UB$3$E)
DW$227	.dwtag  DW_TAG_loop_range
	.dwattr DW$227, DW_AT_low_pc(DWL$$FUN_CCcan_TxData_UB$4$B)
	.dwattr DW$227, DW_AT_high_pc(DWL$$FUN_CCcan_TxData_UB$4$E)
DW$228	.dwtag  DW_TAG_loop_range
	.dwattr DW$228, DW_AT_low_pc(DWL$$FUN_CCcan_TxData_UB$5$B)
	.dwattr DW$228, DW_AT_high_pc(DWL$$FUN_CCcan_TxData_UB$5$E)
	.dwendtag DW$225

	.dwendentry
	.dwendtag DW$187




	.sect	".text:v$14"
	.clink
	.global	_FUN_CCcan_TxDiagResponse_V

DW$229	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_TxDiagResponse_V"), DW_AT_symbol_name("_FUN_CCcan_TxDiagResponse_V")
	.dwattr DW$229, DW_AT_veneer(0x01)
	.dwattr DW$229, DW_AT_low_pc(_FUN_CCcan_TxDiagResponse_V)
	.dwattr DW$229, DW_AT_high_pc(0x00)
	.dwattr DW$229, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CCcan_TxDiagResponse_V                              *
;*****************************************************************************
_FUN_CCcan_TxDiagResponse_V:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $FUN_CCcan_TxDiagResponse_V
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$229



	.sect	".text"
	.clink
	.global	$FUN_CCcan_TxDiagResponse_V

DW$230	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CCcan_TxDiagResponse_V"), DW_AT_symbol_name("$FUN_CCcan_TxDiagResponse_V")
	.dwattr DW$230, DW_AT_low_pc($FUN_CCcan_TxDiagResponse_V)
	.dwattr DW$230, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_CanHandler.c",1468,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 1467 | void FUN_CCcan_TxDiagResponse_V(UBYTE t_Handle_UB)                     
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CCcan_TxDiagResponse_V                                 *
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
$FUN_CCcan_TxDiagResponse_V:
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
;* A1    assigned to _t_Handle_UB
DW$231	.dwtag  DW_TAG_formal_parameter, DW_AT_name("t_Handle_UB"), DW_AT_symbol_name("_t_Handle_UB")
	.dwattr DW$231, DW_AT_type(*DWT$1018)
	.dwattr DW$231, DW_AT_location[DW_OP_reg0]
;* V1    assigned to C$1
DW$232	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$232, DW_AT_type(*DWT$1116)
	.dwattr DW$232, DW_AT_location[DW_OP_reg4]
;* A1    assigned to C$2
DW$233	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$233, DW_AT_type(*DWT$11)
	.dwattr DW$233, DW_AT_location[DW_OP_reg0]
;* A4    assigned to _t_ByteCounter_UB
DW$234	.dwtag  DW_TAG_variable, DW_AT_name("t_ByteCounter_UB"), DW_AT_symbol_name("_t_ByteCounter_UB")
	.dwattr DW$234, DW_AT_type(*DWT$11)
	.dwattr DW$234, DW_AT_location[DW_OP_reg3]
;* A1    assigned to _t_Handle_UB
DW$235	.dwtag  DW_TAG_variable, DW_AT_name("t_Handle_UB"), DW_AT_symbol_name("_t_Handle_UB")
	.dwattr DW$235, DW_AT_type(*DWT$1026)
	.dwattr DW$235, DW_AT_location[DW_OP_reg0]
;* V3    assigned to _t_EndlessLoopProtection_UL
DW$236	.dwtag  DW_TAG_variable, DW_AT_name("t_EndlessLoopProtection_UL"), DW_AT_symbol_name("_t_EndlessLoopProtection_UL")
	.dwattr DW$236, DW_AT_type(*DWT$1054)
	.dwattr DW$236, DW_AT_location[DW_OP_reg6]
;* V2    assigned to _t_Mailbox_UB
DW$237	.dwtag  DW_TAG_variable, DW_AT_name("t_Mailbox_UB"), DW_AT_symbol_name("_t_Mailbox_UB")
	.dwattr DW$237, DW_AT_type(*DWT$1018)
	.dwattr DW$237, DW_AT_location[DW_OP_reg5]
;* A4    assigned to _t_MailboxNbr_UB
DW$238	.dwtag  DW_TAG_variable, DW_AT_name("t_MailboxNbr_UB"), DW_AT_symbol_name("_t_MailboxNbr_UB")
	.dwattr DW$238, DW_AT_type(*DWT$1018)
	.dwattr DW$238, DW_AT_location[DW_OP_reg3]
;* V3    assigned to U$27
DW$239	.dwtag  DW_TAG_variable, DW_AT_name("U$27"), DW_AT_symbol_name("U$27")
	.dwattr DW$239, DW_AT_type(*DWT$1040)
	.dwattr DW$239, DW_AT_location[DW_OP_reg6]
;* A1    assigned to K$3
DW$240	.dwtag  DW_TAG_variable, DW_AT_name("K$3"), DW_AT_symbol_name("K$3")
	.dwattr DW$240, DW_AT_type(*DWT$11)
	.dwattr DW$240, DW_AT_location[DW_OP_reg0]
;* A1    assigned to K$6
DW$241	.dwtag  DW_TAG_variable, DW_AT_name("K$6"), DW_AT_symbol_name("K$6")
	.dwattr DW$241, DW_AT_type(*DWT$1184)
	.dwattr DW$241, DW_AT_location[DW_OP_reg0]
;* V1    assigned to K$15
DW$242	.dwtag  DW_TAG_variable, DW_AT_name("K$15"), DW_AT_symbol_name("K$15")
	.dwattr DW$242, DW_AT_type(*DWT$1145)
	.dwattr DW$242, DW_AT_location[DW_OP_reg4]
;----------------------------------------------------------------------
; 1470 | ULONG t_EndlessLoopProtection_UL = 0xFFFFFFFFul;                       
; 1472 | UBYTE t_ByteCounter_UB = 0u;                                           
; 1473 | UBYTE t_Mailbox_UB;                                                    
; 1474 | UBYTE t_MailboxNbr_UB;                                                 
;----------------------------------------------------------------------
;* 1478	-----------------------    C$1 = CanCtrl_ST.DiagResponseTG_PST;
	.dwpsn	"ADLATUS_CanHandler.c",1478,4
;----------------------------------------------------------------------
; 1478 | t_MailboxNbr_UB = CanCtrl_ST.DiagResponseTG_PST[t_Handle_UB].SendMailBo
;     | x_UB;                                                                  
;----------------------------------------------------------------------
        LDR       A3, CON11             ; |1478| 
        LDR       V1, [A3, #28]         ; |1478| 
;* 1478	-----------------------    C$2 = t_Handle_UB*10;
        MOV       A2, #10               ; |1478| 
        MUL       A1, A2
;* 1478	-----------------------    t_MailboxNbr_UB = (C$2+C$1)->SendMailBox_UB;
        LDRB      A4, [V1, A1]          ; |1478| 
;* 1479	-----------------------    K$3 = C$2;
	.dwpsn	"ADLATUS_CanHandler.c",1479,4
;----------------------------------------------------------------------
; 1479 | t_Mailbox_UB = 0x00000001ul << t_MailboxNbr_UB;                        
; 1482 | while ((e_SCC_ST.CANTRS_UL & (ULONG)t_Mailbox_UB) != 0ul)              
; 1484 |   ;                                                                    
;----------------------------------------------------------------------
;* 1479	-----------------------    t_Mailbox_UB = 1u<<(K$3+C$1)->SendMailBox_UB;
        LDRB      V1, [V1, A1]          ; |1479| 
        MOV       A2, #1                ; |1479| 
        LSL       A2, V1                ; |1479| 
        LSL       V2, A2, #24
        LSR       V2, V2, #24
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;**  	-----------------------    K$15 = &e_SCC_ST;
        LDR       A2, CON14             ; |1502| 
        MOV       V1, A2
        SUB       V1, #51
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L53
;*
;*   Loop source line                : 1482
;*   Loop closing brace source line  : 1485
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L53:    
DWL$$FUN_CCcan_TxDiagResponse_V$2$B:
;**	-----------------------g2:
;* 1485	-----------------------    if ( K$15->CANTRS_UL&t_Mailbox_UB ) goto g2;
	.dwpsn	"ADLATUS_CanHandler.c",1485,4
;----------------------------------------------------------------------
; 1487 | for (t_ByteCounter_UB = 0x00u; \                                       
; 1488 |      t_ByteCounter_UB < (UBYTE) 0x08u; \                               
; 1489 |      t_ByteCounter_UB ++ )                                             
;----------------------------------------------------------------------
        LDR       V3, [V1, #8]          ; |1485| 
        TST       V2, V3                ; |1485| 
        BNE       L53                   ; |1485| 
        ; |1485| 
DWL$$FUN_CCcan_TxDiagResponse_V$2$E:
;* --------------------------------------------------------------------------*
;**  	-----------------------    #pragma MUST_ITERATE(8, 8, 8)
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;**  	-----------------------    U$27 = &((volatile unsigned char *)e_CAN_MB)[((int)t_MailboxNbr_UB<<4)];
        LSL       A4, A4, #4
        LDR       V3, CON13
        ADD       V3, V3, A4
;**  	-----------------------    t_ByteCounter_UB = 0;
        MOV       A4, #0
;* 1478	-----------------------    K$6 = &CanCtrl_ST;
	.dwpsn	"ADLATUS_CanHandler.c",1478,4
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L54
;*
;*   Loop source line                : 1487
;*   Loop closing brace source line  : 1495
;*   Known Minimum Trip Count        : 8
;*   Known Maximum Trip Count        : 8
;*   Known Max Trip Count Factor     : 8
;* --------------------------------------------------------------------------*
L54:    
DWL$$FUN_CCcan_TxDiagResponse_V$4$B:
;**	-----------------------g5:
;* 1492	-----------------------    U$27[8] = *(K$6->DiagResponseTG_PST+(t_ByteCounter_UB+K$3)+2);
	.dwpsn	"ADLATUS_CanHandler.c",1492,9
;----------------------------------------------------------------------
; 1492 | e_CAN_MB[t_MailboxNbr_UB].u.CanData_UB[t_ByteCounter_UB] =             
; 1493 | CanCtrl_ST.DiagResponseTG_PST[t_Handle_UB].Data_AUB[t_ByteCounter_UB]; 
;----------------------------------------------------------------------
        ADD       A3, A1, A4            ; |1492| 
        LDR       V4, CON11             ; |1478| 
        LDR       V4, [V4, #28]         ; |1492| 
        ADD       A3, A3, V4            ; |1492| 
        LDRB      A3, [A3, #2]          ; |1492| 
        STRB      A3, [V3, #8]          ; |1492| 
;* 1495	-----------------------    ++U$27;
	.dwpsn	"ADLATUS_CanHandler.c",1495,4
;----------------------------------------------------------------------
; 1499 | while (e_SCC_ST.CANES_UN.CANES_ST.RM_B1)                               
; 1501 |   ;                                                                    
;----------------------------------------------------------------------
        ADD       V3, #1                ; |1495| 
;* 1495	-----------------------    if ( (++t_ByteCounter_UB) < 8 ) goto g5;
        ADD       A4, #1                ; |1495| 
        CMP       A4, #8                ; |1495| 
        BLT       L54                   ; |1495| 
        ; |1495| 
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
DWL$$FUN_CCcan_TxDiagResponse_V$4$E:
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L55
;*
;*   Loop source line                : 1499
;*   Loop closing brace source line  : 1502
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L55:    
DWL$$FUN_CCcan_TxDiagResponse_V$5$B:
;**	-----------------------g8:
;* 1502	-----------------------    if ( *((volatile struct $$fake2 *)&e_SCC_ST+51)&2u ) goto g8;
	.dwpsn	"ADLATUS_CanHandler.c",1502,4
        LDRB      A1, [A2, #0]          ; |1502| 
        LSR       A1, A1, #2            ; |1502| 
        BCS       L55                   ; |1502| 
        ; |1502| 
DWL$$FUN_CCcan_TxDiagResponse_V$5$E:
;* --------------------------------------------------------------------------*
;* 1505	-----------------------    K$15->CANTA_UL |= t_Mailbox_UB;
	.dwpsn	"ADLATUS_CanHandler.c",1505,4
;----------------------------------------------------------------------
; 1505 | e_SCC_ST.CANTA_UL  |= (ULONG)t_Mailbox_UB;                             
;----------------------------------------------------------------------
        LDR       A1, [V1, #16]         ; |1505| 
        ORR       A1, V2                ; |1505| 
        STR       A1, [V1, #16]         ; |1505| 
;* 1506	-----------------------    K$15->CANTRS_UL |= t_Mailbox_UB;
	.dwpsn	"ADLATUS_CanHandler.c",1506,4
;----------------------------------------------------------------------
; 1506 | e_SCC_ST.CANTRS_UL |= (ULONG)t_Mailbox_UB;                             
;----------------------------------------------------------------------
        LDR       A1, [V1, #8]          ; |1506| 
        ORR       A1, V2                ; |1506| 
        STR       A1, [V1, #8]          ; |1506| 
;* 1511	-----------------------    if ( K$15->CANTA_UL&t_Mailbox_UB ) goto g14;
	.dwpsn	"ADLATUS_CanHandler.c",1511,4
;----------------------------------------------------------------------
; 1511 | while (((e_SCC_ST.CANTA_UL & (ULONG)t_Mailbox_UB) == 0ul) &&           
; 1512 |             (0x0000ul != t_EndlessLoopProtection_UL))                  
; 1515 |        t_EndlessLoopProtection_UL--;                                   
; 1520 |        FUN_CCtim_SystemTimerCheck_V ();                                
;----------------------------------------------------------------------
        LDR       A1, [V1, #16]         ; |1511| 
        TST       V2, A1                ; |1511| 
        BNE       L57                   ; |1511| 
        ; |1511| 
;* --------------------------------------------------------------------------*
;**  	-----------------------    #pragma LOOP_FLAGS(5376u)
;* 1470	-----------------------    t_EndlessLoopProtection_UL = 0xffffffffu;
	.dwpsn	"ADLATUS_CanHandler.c",1470,10
        MOV       A1, #0                ; |1470| 
        MVN       V3, A1                ; |1470| 
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L56
;*
;*   Loop source line                : 1511
;*   Loop closing brace source line  : 1521
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L56:    
DWL$$FUN_CCcan_TxDiagResponse_V$8$B:
;**	-----------------------g12:
;* 1521	-----------------------    if ( !t_EndlessLoopProtection_UL ) goto g14;
	.dwpsn	"ADLATUS_CanHandler.c",1521,4
;----------------------------------------------------------------------
; 1523 | return;                                                                
;----------------------------------------------------------------------
        CMP       V3, #0                ; |1521| 
        BEQ       L57                   ; |1521| 
        ; |1521| 
DWL$$FUN_CCcan_TxDiagResponse_V$8$E:
;* --------------------------------------------------------------------------*
DWL$$FUN_CCcan_TxDiagResponse_V$9$B:
;* 1515	-----------------------    --t_EndlessLoopProtection_UL;
	.dwpsn	"ADLATUS_CanHandler.c",1515,11
        SUB       V3, #1                ; |1515| 
;* 1520	-----------------------    FUN_CCtim_SystemTimerCheck_V();
	.dwpsn	"ADLATUS_CanHandler.c",1520,11
        BL        $FUN_CCtim_SystemTimerCheck_V ; |1520| 
        ; |1520| 
;* 1520	-----------------------    if ( !(K$15->CANTA_UL&t_Mailbox_UB) ) goto g12;
        LDR       A1, [V1, #16]         ; |1520| 
        TST       V2, A1                ; |1520| 
        BEQ       L56                   ; |1520| 
        ; |1520| 
;**	-----------------------g14:
;**  	-----------------------    return;
DWL$$FUN_CCcan_TxDiagResponse_V$9$E:
;* --------------------------------------------------------------------------*
L57:    
	.dwpsn	"ADLATUS_CanHandler.c",1525,1
	.dwcfa	0x0e, 20
        POP       {V1, V2, V3, V4, PC}

DW$243	.dwtag  DW_TAG_loop
	.dwattr DW$243, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L56:1:1323432538")
	.dwattr DW$243, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$243, DW_AT_begin_line(0x5e7)
	.dwattr DW$243, DW_AT_end_line(0x5f1)
DW$244	.dwtag  DW_TAG_loop_range
	.dwattr DW$244, DW_AT_low_pc(DWL$$FUN_CCcan_TxDiagResponse_V$8$B)
	.dwattr DW$244, DW_AT_high_pc(DWL$$FUN_CCcan_TxDiagResponse_V$8$E)
DW$245	.dwtag  DW_TAG_loop_range
	.dwattr DW$245, DW_AT_low_pc(DWL$$FUN_CCcan_TxDiagResponse_V$9$B)
	.dwattr DW$245, DW_AT_high_pc(DWL$$FUN_CCcan_TxDiagResponse_V$9$E)
	.dwendtag DW$243


DW$246	.dwtag  DW_TAG_loop
	.dwattr DW$246, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L55:1:1323432538")
	.dwattr DW$246, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$246, DW_AT_begin_line(0x5db)
	.dwattr DW$246, DW_AT_end_line(0x5de)
DW$247	.dwtag  DW_TAG_loop_range
	.dwattr DW$247, DW_AT_low_pc(DWL$$FUN_CCcan_TxDiagResponse_V$5$B)
	.dwattr DW$247, DW_AT_high_pc(DWL$$FUN_CCcan_TxDiagResponse_V$5$E)
	.dwendtag DW$246


DW$248	.dwtag  DW_TAG_loop
	.dwattr DW$248, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L54:1:1323432538")
	.dwattr DW$248, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$248, DW_AT_begin_line(0x5cf)
	.dwattr DW$248, DW_AT_end_line(0x5d7)
DW$249	.dwtag  DW_TAG_loop_range
	.dwattr DW$249, DW_AT_low_pc(DWL$$FUN_CCcan_TxDiagResponse_V$4$B)
	.dwattr DW$249, DW_AT_high_pc(DWL$$FUN_CCcan_TxDiagResponse_V$4$E)
	.dwendtag DW$248


DW$250	.dwtag  DW_TAG_loop
	.dwattr DW$250, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_CanHandler.asm:L53:1:1323432538")
	.dwattr DW$250, DW_AT_begin_file("ADLATUS_CanHandler.c")
	.dwattr DW$250, DW_AT_begin_line(0x5ca)
	.dwattr DW$250, DW_AT_end_line(0x5cd)
DW$251	.dwtag  DW_TAG_loop_range
	.dwattr DW$251, DW_AT_low_pc(DWL$$FUN_CCcan_TxDiagResponse_V$2$B)
	.dwattr DW$251, DW_AT_high_pc(DWL$$FUN_CCcan_TxDiagResponse_V$2$E)
	.dwendtag DW$250

	.dwendentry
	.dwendtag DW$230



;******************************************************************************
;* CONSTANT TABLE                                                             *
;******************************************************************************
	.sect	".text"
	.align	4
CON10:	.field  	_t_MsgObjNbr_UB$1,32
	.align	4
CON11:	.field  	_CanCtrl_ST,32
	.align	4
CON12:	.field  	_e_SCC_ST,32
	.align	4
CON13:	.field  	_e_CAN_MB,32
	.align	4
CON14:	.field  	_e_SCC_ST+51,32
;******************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                              *
;******************************************************************************
	.global	$FUN_CCtim_SystemTimerCheck_V
	.global	_e_SCC_ST
	.global	_e_CAN_MB

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************
DWT$6	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned char")
	.dwattr DWT$6, DW_AT_encoding(DW_ATE_unsigned_char)
	.dwattr DWT$6, DW_AT_byte_size(0x01)
DWT$1018	.dwtag  DW_TAG_typedef, DW_AT_name("UBYTE"), DW_AT_type(*DWT$6)
	.dwattr DWT$1018, DW_AT_language(DW_LANG_C)

DWT$1019	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DWT$1018)
	.dwattr DWT$1019, DW_AT_language(DW_LANG_C)

DWT$1020	.dwtag  DW_TAG_array_type, DW_AT_type(*DWT$1018)
	.dwattr DWT$1020, DW_AT_language(DW_LANG_C)
	.dwattr DWT$1020, DW_AT_byte_size(0x08)
DW$252	.dwtag  DW_TAG_subrange_type
	.dwattr DW$252, DW_AT_upper_bound(0x07)
	.dwendtag DWT$1020

DWT$1023	.dwtag  DW_TAG_typedef, DW_AT_name("PTR_BUFFER_UB"), DW_AT_type(*DWT$1022)
	.dwattr DWT$1023, DW_AT_language(DW_LANG_C)
DWT$1024	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1023)

DWT$1025	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DWT$1018)
	.dwattr DWT$1025, DW_AT_language(DW_LANG_C)
DW$253	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1023)
DW$254	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1023)
	.dwendtag DWT$1025

DWT$1026	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1018)

DWT$1027	.dwtag  DW_TAG_array_type, DW_AT_type(*DWT$1026)
	.dwattr DWT$1027, DW_AT_language(DW_LANG_C)
	.dwattr DWT$1027, DW_AT_byte_size(0x03)
DW$255	.dwtag  DW_TAG_subrange_type
	.dwattr DW$255, DW_AT_upper_bound(0x02)
	.dwendtag DWT$1027


DWT$1029	.dwtag  DW_TAG_array_type, DW_AT_type(*DWT$1018)
	.dwattr DWT$1029, DW_AT_language(DW_LANG_C)
	.dwattr DWT$1029, DW_AT_byte_size(0x30)
DW$256	.dwtag  DW_TAG_subrange_type
	.dwattr DW$256, DW_AT_upper_bound(0x03)
DW$257	.dwtag  DW_TAG_subrange_type
	.dwattr DW$257, DW_AT_upper_bound(0x0b)
	.dwendtag DWT$1029

DWT$1030	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1018)
	.dwattr DWT$1030, DW_AT_address_class(0x20)
DWT$1035	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1033)
	.dwattr DWT$1035, DW_AT_address_class(0x20)
DWT$1038	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1036)
	.dwattr DWT$1038, DW_AT_address_class(0x20)
DWT$1040	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1039)
	.dwattr DWT$1040, DW_AT_address_class(0x20)
DWT$1041	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$6)
	.dwattr DWT$1041, DW_AT_address_class(0x20)
DWT$1044	.dwtag  DW_TAG_typedef, DW_AT_name("UWORD"), DW_AT_type(*DWT$8)
	.dwattr DWT$1044, DW_AT_language(DW_LANG_C)
DWT$11	.dwtag  DW_TAG_base_type, DW_AT_name("int")
	.dwattr DWT$11, DW_AT_encoding(DW_ATE_signed)
	.dwattr DWT$11, DW_AT_byte_size(0x04)
DWT$10	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned int")
	.dwattr DWT$10, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$10, DW_AT_byte_size(0x04)
DWT$1054	.dwtag  DW_TAG_typedef, DW_AT_name("ULONG"), DW_AT_type(*DWT$12)
	.dwattr DWT$1054, DW_AT_language(DW_LANG_C)

DWT$1056	.dwtag  DW_TAG_array_type, DW_AT_type(*DWT$1055)
	.dwattr DWT$1056, DW_AT_language(DW_LANG_C)
	.dwattr DWT$1056, DW_AT_byte_size(0x2c)
DW$258	.dwtag  DW_TAG_subrange_type
	.dwattr DW$258, DW_AT_upper_bound(0x0a)
	.dwendtag DWT$1056


DWT$1057	.dwtag  DW_TAG_subroutine_type
	.dwattr DWT$1057, DW_AT_language(DW_LANG_C)

DWT$1078	.dwtag  DW_TAG_subroutine_type
	.dwattr DWT$1078, DW_AT_language(DW_LANG_C)
DW$259	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1077)
	.dwendtag DWT$1078


DWT$1079	.dwtag  DW_TAG_subroutine_type
	.dwattr DWT$1079, DW_AT_language(DW_LANG_C)
DW$260	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1018)
	.dwendtag DWT$1079


DWT$1081	.dwtag  DW_TAG_subroutine_type
	.dwattr DWT$1081, DW_AT_language(DW_LANG_C)
DW$261	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1080)
DW$262	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1044)
	.dwendtag DWT$1081

DWT$1080	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1060)
	.dwattr DWT$1080, DW_AT_address_class(0x20)
DWT$1083	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1080)
DWT$1084	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1059)
	.dwattr DWT$1084, DW_AT_address_class(0x20)
DWT$1066	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1065)
	.dwattr DWT$1066, DW_AT_address_class(0x20)
DWT$1099	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1098)
	.dwattr DWT$1099, DW_AT_address_class(0x20)
DWT$1115	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1114)
	.dwattr DWT$1115, DW_AT_address_class(0x20)
DWT$1116	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1071)
	.dwattr DWT$1116, DW_AT_address_class(0x20)
DWT$1077	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1076)
	.dwattr DWT$1077, DW_AT_address_class(0x20)
DWT$1118	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1077)
DWT$1129	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1128)
	.dwattr DWT$1129, DW_AT_address_class(0x20)
DWT$1134	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1133)
	.dwattr DWT$1134, DW_AT_address_class(0x20)
DWT$1137	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1136)
	.dwattr DWT$1137, DW_AT_address_class(0x20)
DWT$1144	.dwtag  DW_TAG_typedef, DW_AT_name("SCC_ST"), DW_AT_type(*DWT$1143)
	.dwattr DWT$1144, DW_AT_language(DW_LANG_C)
DWT$1145	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1144)
	.dwattr DWT$1145, DW_AT_address_class(0x20)
DWT$1146	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1143)
	.dwattr DWT$1146, DW_AT_address_class(0x20)

DWT$1179	.dwtag  DW_TAG_array_type, DW_AT_type(*DWT$1178)
	.dwattr DWT$1179, DW_AT_language(DW_LANG_C)
	.dwattr DWT$1179, DW_AT_byte_size(0x100)
DW$263	.dwtag  DW_TAG_subrange_type
	.dwattr DW$263, DW_AT_upper_bound(0x0f)
	.dwendtag DWT$1179

DWT$1181	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1177)
	.dwattr DWT$1181, DW_AT_address_class(0x20)
DWT$1183	.dwtag  DW_TAG_typedef, DW_AT_name("CANCONTROL_ST"), DW_AT_type(*DWT$1182)
	.dwattr DWT$1183, DW_AT_language(DW_LANG_C)
DWT$1184	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1183)
	.dwattr DWT$1184, DW_AT_address_class(0x20)
DWT$1185	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1182)
	.dwattr DWT$1185, DW_AT_address_class(0x20)
DWT$1022	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1021)
	.dwattr DWT$1022, DW_AT_address_class(0x20)
DWT$1033	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$6)

DWT$1036	.dwtag  DW_TAG_array_type, DW_AT_type(*DWT$6)
	.dwattr DWT$1036, DW_AT_language(DW_LANG_C)
	.dwattr DWT$1036, DW_AT_byte_size(0x0c)
DW$264	.dwtag  DW_TAG_subrange_type
	.dwattr DW$264, DW_AT_upper_bound(0x0b)
	.dwendtag DWT$1036

DWT$1039	.dwtag  DW_TAG_volatile_type, DW_AT_type(*DWT$6)
DWT$8	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned short")
	.dwattr DWT$8, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$8, DW_AT_byte_size(0x02)
DWT$12	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned long")
	.dwattr DWT$12, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$12, DW_AT_byte_size(0x04)
DWT$1055	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1054)

DWT$1059	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1059, DW_AT_name("_CANMSGOBJCONFIG")
	.dwattr DWT$1059, DW_AT_byte_size(0x0c)
DW$265	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$265, DW_AT_name("MsgObjectNbr_UB"), DW_AT_symbol_name("_MsgObjectNbr_UB")
	.dwattr DW$265, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$265, DW_AT_accessibility(DW_ACCESS_public)
DW$266	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$266, DW_AT_name("MsgObjState_UB"), DW_AT_symbol_name("_MsgObjState_UB")
	.dwattr DW$266, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr DW$266, DW_AT_accessibility(DW_ACCESS_public)
DW$267	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$267, DW_AT_name("MsgObjDirection_UB"), DW_AT_symbol_name("_MsgObjDirection_UB")
	.dwattr DW$267, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$267, DW_AT_accessibility(DW_ACCESS_public)
DW$268	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$268, DW_AT_name("IDLength_UB"), DW_AT_symbol_name("_IDLength_UB")
	.dwattr DW$268, DW_AT_data_member_location[DW_OP_plus_uconst 0x3]
	.dwattr DW$268, DW_AT_accessibility(DW_ACCESS_public)
DW$269	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$269, DW_AT_name("CanIdentifier_UL"), DW_AT_symbol_name("_CanIdentifier_UL")
	.dwattr DW$269, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$269, DW_AT_accessibility(DW_ACCESS_public)
DW$270	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$270, DW_AT_name("AcceptanceMask_UL"), DW_AT_symbol_name("_AcceptanceMask_UL")
	.dwattr DW$270, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$270, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1059

DWT$1060	.dwtag  DW_TAG_typedef, DW_AT_name("CANMSGOBJCONFIG_ST"), DW_AT_type(*DWT$1059)
	.dwattr DWT$1060, DW_AT_language(DW_LANG_C)
DWT$1065	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1064)
DWT$1098	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1063)
DWT$1114	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1063)

DWT$1071	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1071, DW_AT_name("_DIAGRESPONSETG_ST")
	.dwattr DWT$1071, DW_AT_byte_size(0x0a)
DW$271	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$271, DW_AT_name("SendMailBox_UB"), DW_AT_symbol_name("_SendMailBox_UB")
	.dwattr DW$271, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$271, DW_AT_accessibility(DW_ACCESS_public)
DW$272	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$272, DW_AT_name("Reserve_UB"), DW_AT_symbol_name("_Reserve_UB")
	.dwattr DW$272, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr DW$272, DW_AT_accessibility(DW_ACCESS_public)
DW$273	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1020)
	.dwattr DW$273, DW_AT_name("Data_AUB"), DW_AT_symbol_name("_Data_AUB")
	.dwattr DW$273, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$273, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1071

DWT$1076	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1075)
DWT$1128	.dwtag  DW_TAG_volatile_type, DW_AT_type(*DWT$1127)
DWT$1133	.dwtag  DW_TAG_volatile_type, DW_AT_type(*DWT$1132)
DWT$1136	.dwtag  DW_TAG_volatile_type, DW_AT_type(*DWT$1135)
DWT$1143	.dwtag  DW_TAG_volatile_type, DW_AT_type(*DWT$1142)
DWT$1177	.dwtag  DW_TAG_volatile_type, DW_AT_type(*DWT$1176)
DWT$1178	.dwtag  DW_TAG_typedef, DW_AT_name("CANMBOX"), DW_AT_type(*DWT$1177)
	.dwattr DWT$1178, DW_AT_language(DW_LANG_C)

DWT$1182	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1182, DW_AT_name("_CANCONTROL")
	.dwattr DWT$1182, DW_AT_byte_size(0x24)
DW$274	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1080)
	.dwattr DW$274, DW_AT_name("CanMsgObjConfig_PST"), DW_AT_symbol_name("_CanMsgObjConfig_PST")
	.dwattr DW$274, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$274, DW_AT_accessibility(DW_ACCESS_public)
DW$275	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1066)
	.dwattr DW$275, DW_AT_name("CanChannelTable_PST"), DW_AT_symbol_name("_CanChannelTable_PST")
	.dwattr DW$275, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$275, DW_AT_accessibility(DW_ACCESS_public)
DW$276	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$276, DW_AT_name("QuarzClockFrequency_UL"), DW_AT_symbol_name("_QuarzClockFrequency_UL")
	.dwattr DW$276, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$276, DW_AT_accessibility(DW_ACCESS_public)
DW$277	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1044)
	.dwattr DW$277, DW_AT_name("CanNode_UW"), DW_AT_symbol_name("_CanNode_UW")
	.dwattr DW$277, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$277, DW_AT_accessibility(DW_ACCESS_public)
DW$278	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$278, DW_AT_name("DefaultBaudrate_UB"), DW_AT_symbol_name("_DefaultBaudrate_UB")
	.dwattr DW$278, DW_AT_data_member_location[DW_OP_plus_uconst 0xe]
	.dwattr DW$278, DW_AT_accessibility(DW_ACCESS_public)
DW$279	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$279, DW_AT_name("SelectedChannel_UB"), DW_AT_symbol_name("_SelectedChannel_UB")
	.dwattr DW$279, DW_AT_data_member_location[DW_OP_plus_uconst 0xf]
	.dwattr DW$279, DW_AT_accessibility(DW_ACCESS_public)
DW$280	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$280, DW_AT_name("MbUsedinRAM_UB"), DW_AT_symbol_name("_MbUsedinRAM_UB")
	.dwattr DW$280, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$280, DW_AT_accessibility(DW_ACCESS_public)
DW$281	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$281, DW_AT_name("RepeatCounter_UB"), DW_AT_symbol_name("_RepeatCounter_UB")
	.dwattr DW$281, DW_AT_data_member_location[DW_OP_plus_uconst 0x11]
	.dwattr DW$281, DW_AT_accessibility(DW_ACCESS_public)
DW$282	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1030)
	.dwattr DW$282, DW_AT_name("SendData_PUB"), DW_AT_symbol_name("_SendData_PUB")
	.dwattr DW$282, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr DW$282, DW_AT_accessibility(DW_ACCESS_public)
DW$283	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$283, DW_AT_name("MbUsedforStartup_UB"), DW_AT_symbol_name("_MbUsedforStartup_UB")
	.dwattr DW$283, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr DW$283, DW_AT_accessibility(DW_ACCESS_public)
DW$284	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1073)
	.dwattr DW$284, DW_AT_name("DiagResponseTG_PST"), DW_AT_symbol_name("_DiagResponseTG_PST")
	.dwattr DW$284, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr DW$284, DW_AT_accessibility(DW_ACCESS_public)
DW$285	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$285, DW_AT_name("WriteIndex_AUB"), DW_AT_symbol_name("_WriteIndex_AUB")
	.dwattr DW$285, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr DW$285, DW_AT_accessibility(DW_ACCESS_public)
DW$286	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$286, DW_AT_name("ReadIndex_AUB"), DW_AT_symbol_name("_ReadIndex_AUB")
	.dwattr DW$286, DW_AT_data_member_location[DW_OP_plus_uconst 0x21]
	.dwattr DW$286, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1182

DWT$1021	.dwtag  DW_TAG_typedef, DW_AT_name("BUFFER_UB"), DW_AT_type(*DWT$1018)
	.dwattr DWT$1021, DW_AT_language(DW_LANG_C)

DWT$1063	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1063, DW_AT_name("_CANMSGOBJINFO")
	.dwattr DWT$1063, DW_AT_byte_size(0x04)
DW$287	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$287, DW_AT_name("MsgObjectNbr_UB"), DW_AT_symbol_name("_MsgObjectNbr_UB")
	.dwattr DW$287, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$287, DW_AT_accessibility(DW_ACCESS_public)
DW$288	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$288, DW_AT_name("ChannelNbr_UB"), DW_AT_symbol_name("_ChannelNbr_UB")
	.dwattr DW$288, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr DW$288, DW_AT_accessibility(DW_ACCESS_public)
DW$289	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$289, DW_AT_name("AddIdByteInfo_UB"), DW_AT_symbol_name("_AddIdByteInfo_UB")
	.dwattr DW$289, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$289, DW_AT_accessibility(DW_ACCESS_public)
DW$290	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$290, DW_AT_name("AddIdentifier_UB"), DW_AT_symbol_name("_AddIdentifier_UB")
	.dwattr DW$290, DW_AT_data_member_location[DW_OP_plus_uconst 0x3]
	.dwattr DW$290, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1063

DWT$1064	.dwtag  DW_TAG_typedef, DW_AT_name("CANMSGOBJINFO_ST"), DW_AT_type(*DWT$1063)
	.dwattr DWT$1064, DW_AT_language(DW_LANG_C)
DWT$1073	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1072)
	.dwattr DWT$1073, DW_AT_address_class(0x20)
DWT$1075	.dwtag  DW_TAG_typedef, DW_AT_name("CANINTERFACE_ST"), DW_AT_type(*DWT$1074)
	.dwattr DWT$1075, DW_AT_language(DW_LANG_C)

DWT$1127	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1127, DW_AT_byte_size(0x02)
DW$291	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$291, DW_AT_name("LNTC_B1"), DW_AT_symbol_name("_LNTC_B1")
	.dwattr DW$291, DW_AT_bit_offset(0x00), DW_AT_bit_size(0x01)
	.dwattr DW$291, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$291, DW_AT_accessibility(DW_ACCESS_public)
DW$292	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$292, DW_AT_name("LNTM_B1"), DW_AT_symbol_name("_LNTM_B1")
	.dwattr DW$292, DW_AT_bit_offset(0x01), DW_AT_bit_size(0x01)
	.dwattr DW$292, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$292, DW_AT_accessibility(DW_ACCESS_public)
DW$293	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$293, DW_AT_name("SCM_B1"), DW_AT_symbol_name("_SCM_B1")
	.dwattr DW$293, DW_AT_bit_offset(0x02), DW_AT_bit_size(0x01)
	.dwattr DW$293, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$293, DW_AT_accessibility(DW_ACCESS_public)
DW$294	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$294, DW_AT_name("CCR_B1"), DW_AT_symbol_name("_CCR_B1")
	.dwattr DW$294, DW_AT_bit_offset(0x03), DW_AT_bit_size(0x01)
	.dwattr DW$294, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$294, DW_AT_accessibility(DW_ACCESS_public)
DW$295	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$295, DW_AT_name("PDR_B1"), DW_AT_symbol_name("_PDR_B1")
	.dwattr DW$295, DW_AT_bit_offset(0x04), DW_AT_bit_size(0x01)
	.dwattr DW$295, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$295, DW_AT_accessibility(DW_ACCESS_public)
DW$296	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$296, DW_AT_name("DBO_B1"), DW_AT_symbol_name("_DBO_B1")
	.dwattr DW$296, DW_AT_bit_offset(0x05), DW_AT_bit_size(0x01)
	.dwattr DW$296, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$296, DW_AT_accessibility(DW_ACCESS_public)
DW$297	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$297, DW_AT_name("WUBA_B1"), DW_AT_symbol_name("_WUBA_B1")
	.dwattr DW$297, DW_AT_bit_offset(0x06), DW_AT_bit_size(0x01)
	.dwattr DW$297, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$297, DW_AT_accessibility(DW_ACCESS_public)
DW$298	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$298, DW_AT_name("CDR_B1"), DW_AT_symbol_name("_CDR_B1")
	.dwattr DW$298, DW_AT_bit_offset(0x07), DW_AT_bit_size(0x01)
	.dwattr DW$298, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$298, DW_AT_accessibility(DW_ACCESS_public)
DW$299	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$299, DW_AT_name("ABO_B1"), DW_AT_symbol_name("_ABO_B1")
	.dwattr DW$299, DW_AT_bit_offset(0x08), DW_AT_bit_size(0x01)
	.dwattr DW$299, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$299, DW_AT_accessibility(DW_ACCESS_public)
DW$300	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$300, DW_AT_name("STM_B1"), DW_AT_symbol_name("_STM_B1")
	.dwattr DW$300, DW_AT_bit_offset(0x09), DW_AT_bit_size(0x01)
	.dwattr DW$300, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$300, DW_AT_accessibility(DW_ACCESS_public)
DW$301	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$301, DW_AT_name("SRES_B1"), DW_AT_symbol_name("_SRES_B1")
	.dwattr DW$301, DW_AT_bit_offset(0x0a), DW_AT_bit_size(0x01)
	.dwattr DW$301, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$301, DW_AT_accessibility(DW_ACCESS_public)
DW$302	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$302, DW_AT_name("WBNR_B5"), DW_AT_symbol_name("_WBNR_B5")
	.dwattr DW$302, DW_AT_bit_offset(0x0b), DW_AT_bit_size(0x05)
	.dwattr DW$302, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$302, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1127


DWT$1132	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1132, DW_AT_byte_size(0x04)
DW$303	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$303, DW_AT_name("Notused1"), DW_AT_symbol_name("_Notused1")
	.dwattr DW$303, DW_AT_bit_offset(0x00), DW_AT_bit_size(0x07)
	.dwattr DW$303, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$303, DW_AT_accessibility(DW_ACCESS_public)
DW$304	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$304, DW_AT_name("FE_B1"), DW_AT_symbol_name("_FE_B1")
	.dwattr DW$304, DW_AT_bit_offset(0x07), DW_AT_bit_size(0x01)
	.dwattr DW$304, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$304, DW_AT_accessibility(DW_ACCESS_public)
DW$305	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$305, DW_AT_name("BE_B1"), DW_AT_symbol_name("_BE_B1")
	.dwattr DW$305, DW_AT_bit_offset(0x08), DW_AT_bit_size(0x01)
	.dwattr DW$305, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$305, DW_AT_accessibility(DW_ACCESS_public)
DW$306	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$306, DW_AT_name("SA1_B1"), DW_AT_symbol_name("_SA1_B1")
	.dwattr DW$306, DW_AT_bit_offset(0x09), DW_AT_bit_size(0x01)
	.dwattr DW$306, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$306, DW_AT_accessibility(DW_ACCESS_public)
DW$307	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$307, DW_AT_name("CRCE_B1"), DW_AT_symbol_name("_CRCE_B1")
	.dwattr DW$307, DW_AT_bit_offset(0x0a), DW_AT_bit_size(0x01)
	.dwattr DW$307, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$307, DW_AT_accessibility(DW_ACCESS_public)
DW$308	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$308, DW_AT_name("SE_B1"), DW_AT_symbol_name("_SE_B1")
	.dwattr DW$308, DW_AT_bit_offset(0x0b), DW_AT_bit_size(0x01)
	.dwattr DW$308, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$308, DW_AT_accessibility(DW_ACCESS_public)
DW$309	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$309, DW_AT_name("ACKE_B1"), DW_AT_symbol_name("_ACKE_B1")
	.dwattr DW$309, DW_AT_bit_offset(0x0c), DW_AT_bit_size(0x01)
	.dwattr DW$309, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$309, DW_AT_accessibility(DW_ACCESS_public)
DW$310	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$310, DW_AT_name("BO_B1"), DW_AT_symbol_name("_BO_B1")
	.dwattr DW$310, DW_AT_bit_offset(0x0d), DW_AT_bit_size(0x01)
	.dwattr DW$310, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$310, DW_AT_accessibility(DW_ACCESS_public)
DW$311	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$311, DW_AT_name("EP_B1"), DW_AT_symbol_name("_EP_B1")
	.dwattr DW$311, DW_AT_bit_offset(0x0e), DW_AT_bit_size(0x01)
	.dwattr DW$311, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$311, DW_AT_accessibility(DW_ACCESS_public)
DW$312	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$312, DW_AT_name("EW_B1"), DW_AT_symbol_name("_EW_B1")
	.dwattr DW$312, DW_AT_bit_offset(0x0f), DW_AT_bit_size(0x01)
	.dwattr DW$312, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$312, DW_AT_accessibility(DW_ACCESS_public)
DW$313	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$313, DW_AT_name("Notused2"), DW_AT_symbol_name("_Notused2")
	.dwattr DW$313, DW_AT_bit_offset(0x10), DW_AT_bit_size(0x0a)
	.dwattr DW$313, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$313, DW_AT_accessibility(DW_ACCESS_public)
DW$314	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$314, DW_AT_name("SMA_B1"), DW_AT_symbol_name("_SMA_B1")
	.dwattr DW$314, DW_AT_bit_offset(0x1a), DW_AT_bit_size(0x01)
	.dwattr DW$314, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$314, DW_AT_accessibility(DW_ACCESS_public)
DW$315	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$315, DW_AT_name("CCE_B1"), DW_AT_symbol_name("_CCE_B1")
	.dwattr DW$315, DW_AT_bit_offset(0x1b), DW_AT_bit_size(0x01)
	.dwattr DW$315, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$315, DW_AT_accessibility(DW_ACCESS_public)
DW$316	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$316, DW_AT_name("PDA_B1"), DW_AT_symbol_name("_PDA_B1")
	.dwattr DW$316, DW_AT_bit_offset(0x1c), DW_AT_bit_size(0x01)
	.dwattr DW$316, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$316, DW_AT_accessibility(DW_ACCESS_public)
DW$317	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$317, DW_AT_name("Notused3"), DW_AT_symbol_name("_Notused3")
	.dwattr DW$317, DW_AT_bit_offset(0x1d), DW_AT_bit_size(0x01)
	.dwattr DW$317, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$317, DW_AT_accessibility(DW_ACCESS_public)
DW$318	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$318, DW_AT_name("RM_B1"), DW_AT_symbol_name("_RM_B1")
	.dwattr DW$318, DW_AT_bit_offset(0x1e), DW_AT_bit_size(0x01)
	.dwattr DW$318, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$318, DW_AT_accessibility(DW_ACCESS_public)
DW$319	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$319, DW_AT_name("TM_B1"), DW_AT_symbol_name("_TM_B1")
	.dwattr DW$319, DW_AT_bit_offset(0x1f), DW_AT_bit_size(0x01)
	.dwattr DW$319, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$319, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1132


DWT$1135	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1135, DW_AT_byte_size(0x04)
DW$320	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$320, DW_AT_name("Notused1"), DW_AT_symbol_name("_Notused1")
	.dwattr DW$320, DW_AT_bit_offset(0x00), DW_AT_bit_size(0x1c)
	.dwattr DW$320, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$320, DW_AT_accessibility(DW_ACCESS_public)
DW$321	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$321, DW_AT_name("TXFUNC_B1"), DW_AT_symbol_name("_TXFUNC_B1")
	.dwattr DW$321, DW_AT_bit_offset(0x1c), DW_AT_bit_size(0x01)
	.dwattr DW$321, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$321, DW_AT_accessibility(DW_ACCESS_public)
DW$322	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$322, DW_AT_name("TXDIR_B1"), DW_AT_symbol_name("_TXDIR_B1")
	.dwattr DW$322, DW_AT_bit_offset(0x1d), DW_AT_bit_size(0x01)
	.dwattr DW$322, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$322, DW_AT_accessibility(DW_ACCESS_public)
DW$323	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$323, DW_AT_name("TXOUT_B1"), DW_AT_symbol_name("_TXOUT_B1")
	.dwattr DW$323, DW_AT_bit_offset(0x1e), DW_AT_bit_size(0x01)
	.dwattr DW$323, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$323, DW_AT_accessibility(DW_ACCESS_public)
DW$324	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$324, DW_AT_name("TXIN_B1"), DW_AT_symbol_name("_TXIN_B1")
	.dwattr DW$324, DW_AT_bit_offset(0x1f), DW_AT_bit_size(0x01)
	.dwattr DW$324, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$324, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1135


DWT$1142	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1142, DW_AT_name("scc_st")
	.dwattr DWT$1142, DW_AT_byte_size(0x5c)
DW$325	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$325, DW_AT_name("CANME_UL"), DW_AT_symbol_name("_CANME_UL")
	.dwattr DW$325, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$325, DW_AT_accessibility(DW_ACCESS_public)
DW$326	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$326, DW_AT_name("CANMD_UL"), DW_AT_symbol_name("_CANMD_UL")
	.dwattr DW$326, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$326, DW_AT_accessibility(DW_ACCESS_public)
DW$327	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$327, DW_AT_name("CANTRS_UL"), DW_AT_symbol_name("_CANTRS_UL")
	.dwattr DW$327, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$327, DW_AT_accessibility(DW_ACCESS_public)
DW$328	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$328, DW_AT_name("CANTRR_UL"), DW_AT_symbol_name("_CANTRR_UL")
	.dwattr DW$328, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$328, DW_AT_accessibility(DW_ACCESS_public)
DW$329	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$329, DW_AT_name("CANTA_UL"), DW_AT_symbol_name("_CANTA_UL")
	.dwattr DW$329, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$329, DW_AT_accessibility(DW_ACCESS_public)
DW$330	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$330, DW_AT_name("CANAA_UL"), DW_AT_symbol_name("_CANAA_UL")
	.dwattr DW$330, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr DW$330, DW_AT_accessibility(DW_ACCESS_public)
DW$331	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$331, DW_AT_name("CANRMP_UL"), DW_AT_symbol_name("_CANRMP_UL")
	.dwattr DW$331, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr DW$331, DW_AT_accessibility(DW_ACCESS_public)
DW$332	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$332, DW_AT_name("CANRML_UL"), DW_AT_symbol_name("_CANRML_UL")
	.dwattr DW$332, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr DW$332, DW_AT_accessibility(DW_ACCESS_public)
DW$333	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$333, DW_AT_name("CANRFP_UL"), DW_AT_symbol_name("_CANRFP_UL")
	.dwattr DW$333, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr DW$333, DW_AT_accessibility(DW_ACCESS_public)
DW$334	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$334, DW_AT_name("CANGAM_UL"), DW_AT_symbol_name("_CANGAM_UL")
	.dwattr DW$334, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr DW$334, DW_AT_accessibility(DW_ACCESS_public)
DW$335	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1130)
	.dwattr DW$335, DW_AT_name("CANMC_UN"), DW_AT_symbol_name("_CANMC_UN")
	.dwattr DW$335, DW_AT_data_member_location[DW_OP_plus_uconst 0x2a]
	.dwattr DW$335, DW_AT_accessibility(DW_ACCESS_public)
DW$336	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$336, DW_AT_name("CANBTC_UL"), DW_AT_symbol_name("_CANBTC_UL")
	.dwattr DW$336, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr DW$336, DW_AT_accessibility(DW_ACCESS_public)
DW$337	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1138)
	.dwattr DW$337, DW_AT_name("CANES_UN"), DW_AT_symbol_name("_CANES_UN")
	.dwattr DW$337, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr DW$337, DW_AT_accessibility(DW_ACCESS_public)
DW$338	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$338, DW_AT_name("notused1"), DW_AT_symbol_name("_notused1")
	.dwattr DW$338, DW_AT_bit_offset(0x00), DW_AT_bit_size(0x18)
	.dwattr DW$338, DW_AT_data_member_location[DW_OP_plus_uconst 0x34]
	.dwattr DW$338, DW_AT_accessibility(DW_ACCESS_public)
DW$339	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$339, DW_AT_name("CANTEC_UL"), DW_AT_symbol_name("_CANTEC_UL")
	.dwattr DW$339, DW_AT_data_member_location[DW_OP_plus_uconst 0x37]
	.dwattr DW$339, DW_AT_accessibility(DW_ACCESS_public)
DW$340	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$340, DW_AT_name("notused2"), DW_AT_symbol_name("_notused2")
	.dwattr DW$340, DW_AT_bit_offset(0x00), DW_AT_bit_size(0x18)
	.dwattr DW$340, DW_AT_data_member_location[DW_OP_plus_uconst 0x38]
	.dwattr DW$340, DW_AT_accessibility(DW_ACCESS_public)
DW$341	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$341, DW_AT_name("CANREC_UL"), DW_AT_symbol_name("_CANREC_UL")
	.dwattr DW$341, DW_AT_data_member_location[DW_OP_plus_uconst 0x3b]
	.dwattr DW$341, DW_AT_accessibility(DW_ACCESS_public)
DW$342	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$342, DW_AT_name("CANGIFO_UL"), DW_AT_symbol_name("_CANGIFO_UL")
	.dwattr DW$342, DW_AT_data_member_location[DW_OP_plus_uconst 0x3c]
	.dwattr DW$342, DW_AT_accessibility(DW_ACCESS_public)
DW$343	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$343, DW_AT_name("CANGIM_UL"), DW_AT_symbol_name("_CANGIM_UL")
	.dwattr DW$343, DW_AT_data_member_location[DW_OP_plus_uconst 0x40]
	.dwattr DW$343, DW_AT_accessibility(DW_ACCESS_public)
DW$344	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$344, DW_AT_name("CANGIF1_UL"), DW_AT_symbol_name("_CANGIF1_UL")
	.dwattr DW$344, DW_AT_data_member_location[DW_OP_plus_uconst 0x44]
	.dwattr DW$344, DW_AT_accessibility(DW_ACCESS_public)
DW$345	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$345, DW_AT_name("CANMIM_UL"), DW_AT_symbol_name("_CANMIM_UL")
	.dwattr DW$345, DW_AT_data_member_location[DW_OP_plus_uconst 0x48]
	.dwattr DW$345, DW_AT_accessibility(DW_ACCESS_public)
DW$346	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$346, DW_AT_name("CANMIL_UL"), DW_AT_symbol_name("_CANMIL_UL")
	.dwattr DW$346, DW_AT_data_member_location[DW_OP_plus_uconst 0x4c]
	.dwattr DW$346, DW_AT_accessibility(DW_ACCESS_public)
DW$347	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$347, DW_AT_name("CANOPC_UL"), DW_AT_symbol_name("_CANOPC_UL")
	.dwattr DW$347, DW_AT_data_member_location[DW_OP_plus_uconst 0x50]
	.dwattr DW$347, DW_AT_accessibility(DW_ACCESS_public)
DW$348	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1139)
	.dwattr DW$348, DW_AT_name("CANTIOC_UN"), DW_AT_symbol_name("_CANTIOC_UN")
	.dwattr DW$348, DW_AT_data_member_location[DW_OP_plus_uconst 0x54]
	.dwattr DW$348, DW_AT_accessibility(DW_ACCESS_public)
DW$349	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1141)
	.dwattr DW$349, DW_AT_name("CANRIOC_UN"), DW_AT_symbol_name("_CANRIOC_UN")
	.dwattr DW$349, DW_AT_data_member_location[DW_OP_plus_uconst 0x58]
	.dwattr DW$349, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1142


DWT$1176	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1176, DW_AT_name("can_mbox_st")
	.dwattr DWT$1176, DW_AT_byte_size(0x10)
DW$350	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1153)
	.dwattr DW$350, DW_AT_name("MID_ST"), DW_AT_symbol_name("_MID_ST")
	.dwattr DW$350, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$350, DW_AT_accessibility(DW_ACCESS_public)
DW$351	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1165)
	.dwattr DW$351, DW_AT_name("MCF_ST"), DW_AT_symbol_name("_MCF_ST")
	.dwattr DW$351, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$351, DW_AT_accessibility(DW_ACCESS_public)
DW$352	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1175)
	.dwattr DW$352, DW_AT_name("u"), DW_AT_symbol_name("_u")
	.dwattr DW$352, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$352, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1176

DWT$1126	.dwtag  DW_TAG_typedef, DW_AT_name("BITFIELD"), DW_AT_type(*DWT$10)
	.dwattr DWT$1126, DW_AT_language(DW_LANG_C)
DWT$1072	.dwtag  DW_TAG_typedef, DW_AT_name("DIAGRESPONSETG_ST"), DW_AT_type(*DWT$1071)
	.dwattr DWT$1072, DW_AT_language(DW_LANG_C)

DWT$1074	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1074, DW_AT_name("_CANINTERFACE")
	.dwattr DWT$1074, DW_AT_byte_size(0x18)
DW$353	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1062)
	.dwattr DW$353, DW_AT_name("CanMsgObjConfig_PST"), DW_AT_symbol_name("_CanMsgObjConfig_PST")
	.dwattr DW$353, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$353, DW_AT_accessibility(DW_ACCESS_public)
DW$354	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1066)
	.dwattr DW$354, DW_AT_name("CanChannelTable_PST"), DW_AT_symbol_name("_CanChannelTable_PST")
	.dwattr DW$354, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$354, DW_AT_accessibility(DW_ACCESS_public)
DW$355	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1068)
	.dwattr DW$355, DW_AT_name("QuarzClockFrequency_PUL"), DW_AT_symbol_name("_QuarzClockFrequency_PUL")
	.dwattr DW$355, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$355, DW_AT_accessibility(DW_ACCESS_public)
DW$356	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1070)
	.dwattr DW$356, DW_AT_name("CanNode_PUW"), DW_AT_symbol_name("_CanNode_PUW")
	.dwattr DW$356, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$356, DW_AT_accessibility(DW_ACCESS_public)
DW$357	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1070)
	.dwattr DW$357, DW_AT_name("DefaultBaudrate_PUW"), DW_AT_symbol_name("_DefaultBaudrate_PUW")
	.dwattr DW$357, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$357, DW_AT_accessibility(DW_ACCESS_public)
DW$358	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1073)
	.dwattr DW$358, DW_AT_name("DiagResponseTG_PST"), DW_AT_symbol_name("_DiagResponseTG_PST")
	.dwattr DW$358, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr DW$358, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1074


DWT$1130	.dwtag  DW_TAG_union_type
	.dwattr DWT$1130, DW_AT_byte_size(0x02)
DW$359	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1044)
	.dwattr DW$359, DW_AT_name("CANMC_UW"), DW_AT_symbol_name("_CANMC_UW")
	.dwattr DW$359, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$359, DW_AT_accessibility(DW_ACCESS_public)
DW$360	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1127)
	.dwattr DW$360, DW_AT_name("CANMC_ST"), DW_AT_symbol_name("_CANMC_ST")
	.dwattr DW$360, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$360, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1130


DWT$1138	.dwtag  DW_TAG_union_type
	.dwattr DWT$1138, DW_AT_byte_size(0x04)
DW$361	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1044)
	.dwattr DW$361, DW_AT_name("CANES_UL"), DW_AT_symbol_name("_CANES_UL")
	.dwattr DW$361, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$361, DW_AT_accessibility(DW_ACCESS_public)
DW$362	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1132)
	.dwattr DW$362, DW_AT_name("CANES_ST"), DW_AT_symbol_name("_CANES_ST")
	.dwattr DW$362, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$362, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1138


DWT$1139	.dwtag  DW_TAG_union_type
	.dwattr DWT$1139, DW_AT_byte_size(0x04)
DW$363	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1044)
	.dwattr DW$363, DW_AT_name("CANTIOC_UL"), DW_AT_symbol_name("_CANTIOC_UL")
	.dwattr DW$363, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$363, DW_AT_accessibility(DW_ACCESS_public)
DW$364	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1135)
	.dwattr DW$364, DW_AT_name("CANTIOC_ST"), DW_AT_symbol_name("_CANTIOC_ST")
	.dwattr DW$364, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$364, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1139


DWT$1141	.dwtag  DW_TAG_union_type
	.dwattr DWT$1141, DW_AT_byte_size(0x04)
DW$365	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1044)
	.dwattr DW$365, DW_AT_name("CANRIOC_UL"), DW_AT_symbol_name("_CANRIOC_UL")
	.dwattr DW$365, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$365, DW_AT_accessibility(DW_ACCESS_public)
DW$366	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1140)
	.dwattr DW$366, DW_AT_name("CANRIOC_ST"), DW_AT_symbol_name("_CANRIOC_ST")
	.dwattr DW$366, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$366, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1141


DWT$1153	.dwtag  DW_TAG_union_type
	.dwattr DWT$1153, DW_AT_byte_size(0x04)
DW$367	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1152)
	.dwattr DW$367, DW_AT_name("w"), DW_AT_symbol_name("_w")
	.dwattr DW$367, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$367, DW_AT_accessibility(DW_ACCESS_public)
DW$368	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1147)
	.dwattr DW$368, DW_AT_name("l"), DW_AT_symbol_name("_l")
	.dwattr DW$368, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$368, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1153


DWT$1165	.dwtag  DW_TAG_union_type
	.dwattr DWT$1165, DW_AT_byte_size(0x04)
DW$369	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1158)
	.dwattr DW$369, DW_AT_name("bw"), DW_AT_symbol_name("_bw")
	.dwattr DW$369, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$369, DW_AT_accessibility(DW_ACCESS_public)
DW$370	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1162)
	.dwattr DW$370, DW_AT_name("l"), DW_AT_symbol_name("_l")
	.dwattr DW$370, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$370, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1165


DWT$1175	.dwtag  DW_TAG_union_type
	.dwattr DWT$1175, DW_AT_byte_size(0x08)
DW$371	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1171)
	.dwattr DW$371, DW_AT_name("l"), DW_AT_symbol_name("_l")
	.dwattr DW$371, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$371, DW_AT_accessibility(DW_ACCESS_public)
DW$372	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1172)
	.dwattr DW$372, DW_AT_name("w"), DW_AT_symbol_name("_w")
	.dwattr DW$372, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$372, DW_AT_accessibility(DW_ACCESS_public)
DW$373	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1173)
	.dwattr DW$373, DW_AT_name("c"), DW_AT_symbol_name("_c")
	.dwattr DW$373, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$373, DW_AT_accessibility(DW_ACCESS_public)
DW$374	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1174)
	.dwattr DW$374, DW_AT_name("CanData_UB"), DW_AT_symbol_name("_CanData_UB")
	.dwattr DW$374, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$374, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1175


DWT$1174	.dwtag  DW_TAG_array_type, DW_AT_type(*DWT$1018)
	.dwattr DWT$1174, DW_AT_language(DW_LANG_C)
	.dwattr DWT$1174, DW_AT_byte_size(0x07)
DW$375	.dwtag  DW_TAG_subrange_type
	.dwattr DW$375, DW_AT_upper_bound(0x06)
	.dwendtag DWT$1174

DWT$1070	.dwtag  DW_TAG_typedef, DW_AT_name("FAR_PTR_UWORD"), DW_AT_type(*DWT$1069)
	.dwattr DWT$1070, DW_AT_language(DW_LANG_C)
DWT$1068	.dwtag  DW_TAG_typedef, DW_AT_name("FAR_PTR_ULONG"), DW_AT_type(*DWT$1067)
	.dwattr DWT$1068, DW_AT_language(DW_LANG_C)
DWT$1062	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1061)
	.dwattr DWT$1062, DW_AT_address_class(0x20)

DWT$1140	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1140, DW_AT_byte_size(0x04)
DW$376	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$376, DW_AT_name("Notused1"), DW_AT_symbol_name("_Notused1")
	.dwattr DW$376, DW_AT_bit_offset(0x00), DW_AT_bit_size(0x1c)
	.dwattr DW$376, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$376, DW_AT_accessibility(DW_ACCESS_public)
DW$377	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$377, DW_AT_name("RXFUNC_B1"), DW_AT_symbol_name("_RXFUNC_B1")
	.dwattr DW$377, DW_AT_bit_offset(0x1c), DW_AT_bit_size(0x01)
	.dwattr DW$377, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$377, DW_AT_accessibility(DW_ACCESS_public)
DW$378	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$378, DW_AT_name("RXDIR_B1"), DW_AT_symbol_name("_RXDIR_B1")
	.dwattr DW$378, DW_AT_bit_offset(0x1d), DW_AT_bit_size(0x01)
	.dwattr DW$378, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$378, DW_AT_accessibility(DW_ACCESS_public)
DW$379	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$379, DW_AT_name("RXOUT_B1"), DW_AT_symbol_name("_RXOUT_B1")
	.dwattr DW$379, DW_AT_bit_offset(0x1e), DW_AT_bit_size(0x01)
	.dwattr DW$379, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$379, DW_AT_accessibility(DW_ACCESS_public)
DW$380	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1126)
	.dwattr DW$380, DW_AT_name("RXIN_B1"), DW_AT_symbol_name("_RXIN_B1")
	.dwattr DW$380, DW_AT_bit_offset(0x1f), DW_AT_bit_size(0x01)
	.dwattr DW$380, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$380, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1140


DWT$1147	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1147, DW_AT_byte_size(0x04)
DW$381	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$381, DW_AT_name("CanMID_UL"), DW_AT_symbol_name("_CanMID_UL")
	.dwattr DW$381, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$381, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1147


DWT$1152	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1152, DW_AT_byte_size(0x04)
DW$382	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1044)
	.dwattr DW$382, DW_AT_name("CanMID"), DW_AT_symbol_name("_CanMID")
	.dwattr DW$382, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$382, DW_AT_accessibility(DW_ACCESS_public)
DW$383	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1044)
	.dwattr DW$383, DW_AT_name("CanMID_low_unused"), DW_AT_symbol_name("_CanMID_low_unused")
	.dwattr DW$383, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$383, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1152


DWT$1158	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1158, DW_AT_byte_size(0x04)
DW$384	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1044)
	.dwattr DW$384, DW_AT_name("CanMCF_high_unused"), DW_AT_symbol_name("_CanMCF_high_unused")
	.dwattr DW$384, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$384, DW_AT_accessibility(DW_ACCESS_public)
DW$385	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$385, DW_AT_name("CanMCF_mid_unused"), DW_AT_symbol_name("_CanMCF_mid_unused")
	.dwattr DW$385, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$385, DW_AT_accessibility(DW_ACCESS_public)
DW$386	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$386, DW_AT_name("CanMCF"), DW_AT_symbol_name("_CanMCF")
	.dwattr DW$386, DW_AT_data_member_location[DW_OP_plus_uconst 0x3]
	.dwattr DW$386, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1158


DWT$1162	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1162, DW_AT_byte_size(0x04)
DW$387	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$387, DW_AT_name("CanMCF_UL"), DW_AT_symbol_name("_CanMCF_UL")
	.dwattr DW$387, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$387, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1162


DWT$1171	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1171, DW_AT_byte_size(0x08)
DW$388	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$388, DW_AT_name("L0"), DW_AT_symbol_name("_L0")
	.dwattr DW$388, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$388, DW_AT_accessibility(DW_ACCESS_public)
DW$389	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1054)
	.dwattr DW$389, DW_AT_name("L1"), DW_AT_symbol_name("_L1")
	.dwattr DW$389, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$389, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1171


DWT$1172	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1172, DW_AT_byte_size(0x08)
DW$390	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1044)
	.dwattr DW$390, DW_AT_name("W0"), DW_AT_symbol_name("_W0")
	.dwattr DW$390, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$390, DW_AT_accessibility(DW_ACCESS_public)
DW$391	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1044)
	.dwattr DW$391, DW_AT_name("W1"), DW_AT_symbol_name("_W1")
	.dwattr DW$391, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$391, DW_AT_accessibility(DW_ACCESS_public)
DW$392	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1044)
	.dwattr DW$392, DW_AT_name("W2"), DW_AT_symbol_name("_W2")
	.dwattr DW$392, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$392, DW_AT_accessibility(DW_ACCESS_public)
DW$393	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1044)
	.dwattr DW$393, DW_AT_name("W3"), DW_AT_symbol_name("_W3")
	.dwattr DW$393, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr DW$393, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1172


DWT$1173	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1173, DW_AT_byte_size(0x08)
DW$394	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$394, DW_AT_name("C0"), DW_AT_symbol_name("_C0")
	.dwattr DW$394, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$394, DW_AT_accessibility(DW_ACCESS_public)
DW$395	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$395, DW_AT_name("C1"), DW_AT_symbol_name("_C1")
	.dwattr DW$395, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr DW$395, DW_AT_accessibility(DW_ACCESS_public)
DW$396	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$396, DW_AT_name("C2"), DW_AT_symbol_name("_C2")
	.dwattr DW$396, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr DW$396, DW_AT_accessibility(DW_ACCESS_public)
DW$397	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$397, DW_AT_name("C3"), DW_AT_symbol_name("_C3")
	.dwattr DW$397, DW_AT_data_member_location[DW_OP_plus_uconst 0x3]
	.dwattr DW$397, DW_AT_accessibility(DW_ACCESS_public)
DW$398	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$398, DW_AT_name("C4"), DW_AT_symbol_name("_C4")
	.dwattr DW$398, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$398, DW_AT_accessibility(DW_ACCESS_public)
DW$399	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$399, DW_AT_name("C5"), DW_AT_symbol_name("_C5")
	.dwattr DW$399, DW_AT_data_member_location[DW_OP_plus_uconst 0x5]
	.dwattr DW$399, DW_AT_accessibility(DW_ACCESS_public)
DW$400	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$400, DW_AT_name("C6"), DW_AT_symbol_name("_C6")
	.dwattr DW$400, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr DW$400, DW_AT_accessibility(DW_ACCESS_public)
DW$401	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$401, DW_AT_name("C7"), DW_AT_symbol_name("_C7")
	.dwattr DW$401, DW_AT_data_member_location[DW_OP_plus_uconst 0x7]
	.dwattr DW$401, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1173

DWT$1069	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1044)
	.dwattr DWT$1069, DW_AT_address_class(0x20)
DWT$1067	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1054)
	.dwattr DWT$1067, DW_AT_address_class(0x20)
DWT$1061	.dwtag  DW_TAG_const_type, DW_AT_type(*DWT$1060)

	.dwattr DW$79, DW_AT_external(0x01)
	.dwattr DW$100, DW_AT_external(0x01)
	.dwattr DW$100, DW_AT_type(*DWT$1018)
	.dwattr DW$25, DW_AT_external(0x01)
	.dwattr DW$25, DW_AT_type(*DWT$1018)
	.dwattr DW$84, DW_AT_external(0x01)
	.dwattr DW$55, DW_AT_external(0x01)
	.dwattr DW$89, DW_AT_external(0x01)
	.dwattr DW$50, DW_AT_external(0x01)
	.dwattr DW$168, DW_AT_external(0x01)
	.dwattr DW$168, DW_AT_type(*DWT$1018)
	.dwattr DW$77, DW_AT_external(0x01)
	.dwattr DW$75, DW_AT_external(0x01)
	.dwattr DW$187, DW_AT_external(0x01)
	.dwattr DW$187, DW_AT_type(*DWT$1018)
	.dwattr DW$230, DW_AT_external(0x01)
	.dwattr DW$20, DW_AT_external(0x01)
	.dwattr DW$10, DW_AT_external(0x01)
	.dwattr DW$15, DW_AT_external(0x01)
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

DW$402	.dwtag  DW_TAG_assign_register, DW_AT_name("A1")
	.dwattr DW$402, DW_AT_location[DW_OP_reg0]
DW$403	.dwtag  DW_TAG_assign_register, DW_AT_name("A2")
	.dwattr DW$403, DW_AT_location[DW_OP_reg1]
DW$404	.dwtag  DW_TAG_assign_register, DW_AT_name("A3")
	.dwattr DW$404, DW_AT_location[DW_OP_reg2]
DW$405	.dwtag  DW_TAG_assign_register, DW_AT_name("A4")
	.dwattr DW$405, DW_AT_location[DW_OP_reg3]
DW$406	.dwtag  DW_TAG_assign_register, DW_AT_name("V1")
	.dwattr DW$406, DW_AT_location[DW_OP_reg4]
DW$407	.dwtag  DW_TAG_assign_register, DW_AT_name("V2")
	.dwattr DW$407, DW_AT_location[DW_OP_reg5]
DW$408	.dwtag  DW_TAG_assign_register, DW_AT_name("V3")
	.dwattr DW$408, DW_AT_location[DW_OP_reg6]
DW$409	.dwtag  DW_TAG_assign_register, DW_AT_name("V4")
	.dwattr DW$409, DW_AT_location[DW_OP_reg7]
DW$410	.dwtag  DW_TAG_assign_register, DW_AT_name("V5")
	.dwattr DW$410, DW_AT_location[DW_OP_reg8]
DW$411	.dwtag  DW_TAG_assign_register, DW_AT_name("V6")
	.dwattr DW$411, DW_AT_location[DW_OP_reg9]
DW$412	.dwtag  DW_TAG_assign_register, DW_AT_name("V7")
	.dwattr DW$412, DW_AT_location[DW_OP_reg10]
DW$413	.dwtag  DW_TAG_assign_register, DW_AT_name("V8")
	.dwattr DW$413, DW_AT_location[DW_OP_reg11]
DW$414	.dwtag  DW_TAG_assign_register, DW_AT_name("V9")
	.dwattr DW$414, DW_AT_location[DW_OP_reg12]
DW$415	.dwtag  DW_TAG_assign_register, DW_AT_name("SP")
	.dwattr DW$415, DW_AT_location[DW_OP_reg13]
DW$416	.dwtag  DW_TAG_assign_register, DW_AT_name("LR")
	.dwattr DW$416, DW_AT_location[DW_OP_reg14]
DW$417	.dwtag  DW_TAG_assign_register, DW_AT_name("PC")
	.dwattr DW$417, DW_AT_location[DW_OP_reg15]
DW$418	.dwtag  DW_TAG_assign_register, DW_AT_name("C0")
	.dwattr DW$418, DW_AT_location[DW_OP_reg16]
DW$419	.dwtag  DW_TAG_assign_register, DW_AT_name("C1")
	.dwattr DW$419, DW_AT_location[DW_OP_reg17]
DW$420	.dwtag  DW_TAG_assign_register, DW_AT_name("C2")
	.dwattr DW$420, DW_AT_location[DW_OP_reg18]
DW$421	.dwtag  DW_TAG_assign_register, DW_AT_name("C3")
	.dwattr DW$421, DW_AT_location[DW_OP_reg19]
DW$422	.dwtag  DW_TAG_assign_register, DW_AT_name("C4")
	.dwattr DW$422, DW_AT_location[DW_OP_reg20]
DW$423	.dwtag  DW_TAG_assign_register, DW_AT_name("C5")
	.dwattr DW$423, DW_AT_location[DW_OP_reg21]
DW$424	.dwtag  DW_TAG_assign_register, DW_AT_name("C6")
	.dwattr DW$424, DW_AT_location[DW_OP_reg22]
DW$425	.dwtag  DW_TAG_assign_register, DW_AT_name("C7")
	.dwattr DW$425, DW_AT_location[DW_OP_reg23]
DW$426	.dwtag  DW_TAG_assign_register, DW_AT_name("AP")
	.dwattr DW$426, DW_AT_location[DW_OP_reg24]
DW$427	.dwtag  DW_TAG_assign_register, DW_AT_name("SR")
	.dwattr DW$427, DW_AT_location[DW_OP_reg25]
DW$428	.dwtag  DW_TAG_assign_register, DW_AT_name("CIE_RETA")
	.dwattr DW$428, DW_AT_location[DW_OP_reg26]
	.dwendtag DWCU

