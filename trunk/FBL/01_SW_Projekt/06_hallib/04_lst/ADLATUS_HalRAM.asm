;******************************************************************************
;* TMS470 C/C++ Codegen                                       PC Version 2.71 *
;* Date/Time created: Tue Jan 24 12:32:25 2012                                *
;******************************************************************************
	.state16

DWCU	.dwtag  DW_TAG_compile_unit
	.dwattr DWCU, DW_AT_name("ADLATUS_HalRAM.c")
	.dwattr DWCU, DW_AT_producer("TMS470 C/C++ Codegen PC Version 2.71 Copyright (c) 1996-2008 Texas Instruments Incorporated")
	.dwattr DWCU, DW_AT_stmt_list(0x00)
	.dwattr DWCU, DW_AT_TI_VERSION(0x01)
DW$1	.dwtag  DW_TAG_variable, DW_AT_name("t_CChal_HalCtrl_ST"), DW_AT_symbol_name("_t_CChal_HalCtrl_ST")
	.dwattr DW$1, DW_AT_type(*DWT$1026)
	.dwattr DW$1, DW_AT_declaration(0x01)
	.dwattr DW$1, DW_AT_external(0x01)
DW$2	.dwtag  DW_TAG_variable, DW_AT_name("e_SARRTI_ST"), DW_AT_symbol_name("_e_SARRTI_ST")
	.dwattr DW$2, DW_AT_type(*DWT$1041)
	.dwattr DW$2, DW_AT_declaration(0x01)
	.dwattr DW$2, DW_AT_external(0x01)
DW$3	.dwtag  DW_TAG_variable, DW_AT_name("e_GIO_ST"), DW_AT_symbol_name("_e_GIO_ST")
	.dwattr DW$3, DW_AT_type(*DWT$1052)
	.dwattr DW$3, DW_AT_declaration(0x01)
	.dwattr DW$3, DW_AT_external(0x01)
;	C:\CCStudio_v3.3\tms470\cgtools_271\bin\opt470.exe -v1 -q -s -O2 -e r:/06_hallib/04_lst/ADLATUS_HalRAM.if r:/06_hallib/04_lst/ADLATUS_HalRAM.opt -w r:/06_hallib/04_lst 

	.sect	".text:v$0"
	.clink
	.global	_FUN_CChal_HardwareTimerCheck_UW

DW$4	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_HardwareTimerCheck_UW"), DW_AT_symbol_name("_FUN_CChal_HardwareTimerCheck_UW")
	.dwattr DW$4, DW_AT_veneer(0x01)
	.dwattr DW$4, DW_AT_low_pc(_FUN_CChal_HardwareTimerCheck_UW)
	.dwattr DW$4, DW_AT_high_pc(0x00)
	.dwattr DW$4, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CChal_HardwareTimerCheck_UW                         *
;*****************************************************************************
_FUN_CChal_HardwareTimerCheck_UW:
	 STMFD     sp!, {lr}
	 ADD       lr, pc, #1
	 BX        lr
	.state16
	 BL        $FUN_CChal_HardwareTimerCheck_UW
	 BX        pc
	 NOP
	.state32
	 LDMFD     sp!, {pc}
	.state16
	.dwendtag DW$4



	.sect	".text"
	.clink
	.global	$FUN_CChal_HardwareTimerCheck_UW

DW$5	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_HardwareTimerCheck_UW"), DW_AT_symbol_name("$FUN_CChal_HardwareTimerCheck_UW")
	.dwattr DW$5, DW_AT_low_pc($FUN_CChal_HardwareTimerCheck_UW)
	.dwattr DW$5, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_HalRAM.c",144,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 143 | UWORD FUN_CChal_HardwareTimerCheck_UW (void)                           
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CChal_HardwareTimerCheck_UW                            *
;*                                                                           *
;*   Regs Modified     : A1,A2,A3,A4,V1,SP,SR                                *
;*   Regs Used         : A1,A2,A3,A4,V1,SP,LR,SR                             *
;*   Local Frame Size  : 0 Args + 0 Auto + 8 Save = 8 byte                   *
;*****************************************************************************

;******************************************************************************
;*                                                                            *
;* Using -g (debug) with optimization (-o2) may disable key optimizations!    *
;*                                                                            *
;******************************************************************************
$FUN_CChal_HardwareTimerCheck_UW:
;* --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 145 | UWORD t_CalculatedTimerTicks_UW;                                       
; 146 | ULONG t_NewTimerValue_UL;                                              
; 147 | ULONG t_TimeDelta_UL;                                                  
; 149 | t_CalculatedTimerTicks_UW        = 0x0000u;                            
;----------------------------------------------------------------------
	.dwcfa	0x09, 26, 14
        PUSH      {V1, LR}
	.dwcfa	0x0e, 4
	.dwcfa	0x80, 14, 1
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 4, 2
	.dwcfa	0x0e, 8
;* A2    assigned to C$1
DW$6	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$6, DW_AT_type(*DWT$10)
	.dwattr DW$6, DW_AT_location[DW_OP_reg1]
;* A3    assigned to C$2
DW$7	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$7, DW_AT_type(*DWT$1028)
	.dwattr DW$7, DW_AT_location[DW_OP_reg2]
;* A2    assigned to V$0
DW$8	.dwtag  DW_TAG_variable, DW_AT_name("V$0"), DW_AT_symbol_name("V$0")
	.dwattr DW$8, DW_AT_type(*DWT$10)
	.dwattr DW$8, DW_AT_location[DW_OP_reg1]
;* A4    assigned to _t_TimeDelta_UL
DW$9	.dwtag  DW_TAG_variable, DW_AT_name("t_TimeDelta_UL"), DW_AT_symbol_name("_t_TimeDelta_UL")
	.dwattr DW$9, DW_AT_type(*DWT$1023)
	.dwattr DW$9, DW_AT_location[DW_OP_reg3]
;* V1    assigned to _t_NewTimerValue_UL
DW$10	.dwtag  DW_TAG_variable, DW_AT_name("t_NewTimerValue_UL"), DW_AT_symbol_name("_t_NewTimerValue_UL")
	.dwattr DW$10, DW_AT_type(*DWT$1023)
	.dwattr DW$10, DW_AT_location[DW_OP_reg4]
;* A1    assigned to _t_CalculatedTimerTicks_UW
DW$11	.dwtag  DW_TAG_variable, DW_AT_name("t_CalculatedTimerTicks_UW"), DW_AT_symbol_name("_t_CalculatedTimerTicks_UW")
	.dwattr DW$11, DW_AT_type(*DWT$1018)
	.dwattr DW$11, DW_AT_location[DW_OP_reg0]
;* A3    assigned to K$5
DW$12	.dwtag  DW_TAG_variable, DW_AT_name("K$5"), DW_AT_symbol_name("K$5")
	.dwattr DW$12, DW_AT_type(*DWT$1027)
	.dwattr DW$12, DW_AT_location[DW_OP_reg2]
;** 164	-----------------------    t_NewTimerValue_UL = *&e_SARRTI_ST>>11;
	.dwpsn	"ADLATUS_HalRAM.c",164,3
;----------------------------------------------------------------------
; 164 | t_NewTimerValue_UL = e_SARRTI_ST.DRTICNTR_UN.DRTICNTR_ST.DRTICNTR_B21; 
;----------------------------------------------------------------------
        LDR       A1, CON1              ; |164| 
        LDR       A1, [A1, #0]          ; |164| 
        LSR       V1, A1, #11           ; |164| 
;** 170	-----------------------    C$2 = &t_CChal_HalCtrl_ST;
	.dwpsn	"ADLATUS_HalRAM.c",170,3
;----------------------------------------------------------------------
; 170 | t_TimeDelta_UL = (t_NewTimerValue_UL - t_CChal_HalCtrl_ST.OldTimerValue
;     | _UL) & 0x001FFFFFul;                                                   
;----------------------------------------------------------------------
        LDR       A3, CON2              ; |170| 
;** 170	-----------------------    t_TimeDelta_UL = t_NewTimerValue_UL-C$2->OldTimerValue_UL&0x1fffffu;
        LDR       A1, [A3, #12]         ; |170| 
        SUB       A1, V1, A1            ; |170| 
        LSL       A1, A1, #11           ; |170| 
        LSR       A4, A1, #11           ; |170| 
;** 149	-----------------------    t_CalculatedTimerTicks_UW = 0u;
	.dwpsn	"ADLATUS_HalRAM.c",149,3
        MOV       A1, #0                ; |149| 
;** 176	-----------------------    C$1 = C$2->TimerTicksForOneMilliSecond_UL;
	.dwpsn	"ADLATUS_HalRAM.c",176,3
;----------------------------------------------------------------------
; 176 | while ( t_TimeDelta_UL >= t_CChal_HalCtrl_ST.TimerTicksForOneMilliSecon
;     | d_UL)                                                                  
;----------------------------------------------------------------------
        LDR       A2, [A3, #16]         ; |176| 
;** 176	-----------------------    if ( t_TimeDelta_UL < C$1 ) goto g4;
        CMP       A4, A2                ; |176| 
        BCC       L2                    ; |176| 
        ; |176| 
;**  	-----------------------    V$0 = C$1;
;**  	-----------------------    #pragma LOOP_FLAGS(4096u)
;* --------------------------------------------------------------------------*
;*   BEGIN LOOP L1
;*
;*   Loop source line                : 176
;*   Loop closing brace source line  : 180
;*   Known Minimum Trip Count        : 1
;*   Known Maximum Trip Count        : 4294967295
;*   Known Max Trip Count Factor     : 1
;* --------------------------------------------------------------------------*
L1:    
DWL$$FUN_CChal_HardwareTimerCheck_UW$2$B:
;**	-----------------------g3:
;** 178	-----------------------    t_TimeDelta_UL -= V$0;
	.dwpsn	"ADLATUS_HalRAM.c",178,5
;----------------------------------------------------------------------
; 178 | t_TimeDelta_UL -= t_CChal_HalCtrl_ST.TimerTicksForOneMilliSecond_UL;   
;----------------------------------------------------------------------
        SUB       A4, A4, A2            ; |178| 
;** 179	-----------------------    ++t_CalculatedTimerTicks_UW;
	.dwpsn	"ADLATUS_HalRAM.c",179,5
;----------------------------------------------------------------------
; 179 | t_CalculatedTimerTicks_UW ++;                                          
;----------------------------------------------------------------------
        ADD       A1, A1, #1            ; |179| 
        LSL       A1, A1, #16           ; |201| 
        LSR       A1, A1, #16           ; |201| 
;** 179	-----------------------    if ( t_TimeDelta_UL >= V$0 ) goto g3;
        CMP       A4, A2                ; |179| 
        BCS       L1                    ; |179| 
        ; |179| 
DWL$$FUN_CChal_HardwareTimerCheck_UW$2$E:
;* --------------------------------------------------------------------------*
L2:    
;**	-----------------------g4:
;** 185	-----------------------    if ( !t_CalculatedTimerTicks_UW ) goto g6;
	.dwpsn	"ADLATUS_HalRAM.c",185,3
;----------------------------------------------------------------------
; 185 | if(0x0000u != t_CalculatedTimerTicks_UW)                               
;----------------------------------------------------------------------
        CMP       A1, #0                ; |185| 
        BEQ       L3                    ; |185| 
        ; |185| 
;* --------------------------------------------------------------------------*
;** 176	-----------------------    K$5 = &t_CChal_HalCtrl_ST;
	.dwpsn	"ADLATUS_HalRAM.c",176,3
;** 191	-----------------------    K$5->OldTimerValue_UL = t_NewTimerValue_UL-t_TimeDelta_UL&0x1fffffu;
	.dwpsn	"ADLATUS_HalRAM.c",191,6
;----------------------------------------------------------------------
; 191 | t_CChal_HalCtrl_ST.OldTimerValue_UL = (t_NewTimerValue_UL - t_TimeDelta
;     | _UL) & 0x001FFFFFul;                                                   
;----------------------------------------------------------------------
        SUB       A2, V1, A4            ; |191| 
        LSL       A2, A2, #11           ; |201| 
        LSR       A2, A2, #11           ; |201| 
        STR       A2, [A3, #12]         ; |191| 
;* --------------------------------------------------------------------------*
L3:    
;**	-----------------------g6:
;** 201	-----------------------    return t_CalculatedTimerTicks_UW;
	.dwpsn	"ADLATUS_HalRAM.c",201,3
;----------------------------------------------------------------------
; 201 | return (t_CalculatedTimerTicks_UW);                                    
;----------------------------------------------------------------------
	.dwpsn	"ADLATUS_HalRAM.c",203,1
	.dwcfa	0x0e, 8
        POP       {V1, PC}

DW$13	.dwtag  DW_TAG_loop
	.dwattr DW$13, DW_AT_name("r:/06_hallib/04_lst/ADLATUS_HalRAM.asm:L1:1:1327404745")
	.dwattr DW$13, DW_AT_begin_file("ADLATUS_HalRAM.c")
	.dwattr DW$13, DW_AT_begin_line(0xb0)
	.dwattr DW$13, DW_AT_end_line(0xb4)
DW$14	.dwtag  DW_TAG_loop_range
	.dwattr DW$14, DW_AT_low_pc(DWL$$FUN_CChal_HardwareTimerCheck_UW$2$B)
	.dwattr DW$14, DW_AT_high_pc(DWL$$FUN_CChal_HardwareTimerCheck_UW$2$E)
	.dwendtag DW$13

	.dwendentry
	.dwendtag DW$5




	.sect	".text:v$1"
	.clink
	.global	_FUN_CChal_TriggerIntWatchdog_V

DW$15	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_TriggerIntWatchdog_V"), DW_AT_symbol_name("_FUN_CChal_TriggerIntWatchdog_V")
	.dwattr DW$15, DW_AT_veneer(0x01)
	.dwattr DW$15, DW_AT_low_pc(_FUN_CChal_TriggerIntWatchdog_V)
	.dwattr DW$15, DW_AT_high_pc(0x00)
	.dwattr DW$15, DW_AT_external(0x01)
	.state32

;*****************************************************************************
;* FUNCTION VENEER: _FUN_CChal_TriggerIntWatchdog_V                          *
;*****************************************************************************
_FUN_CChal_TriggerIntWatchdog_V:
	 LDR       ip, [pc]
	 BX        ip
	.field     $FUN_CChal_TriggerIntWatchdog_V+1, 32
	.state16
	.dwendtag DW$15



	.sect	".text"
	.clink
	.global	$FUN_CChal_TriggerIntWatchdog_V

DW$16	.dwtag  DW_TAG_subprogram, DW_AT_name("FUN_CChal_TriggerIntWatchdog_V"), DW_AT_symbol_name("$FUN_CChal_TriggerIntWatchdog_V")
	.dwattr DW$16, DW_AT_low_pc($FUN_CChal_TriggerIntWatchdog_V)
	.dwattr DW$16, DW_AT_high_pc(0x00)
	.dwpsn	"ADLATUS_HalRAM.c",222,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 221 | void FUN_CChal_TriggerIntWatchdog_V (UWORD t_SysTimeTimerTicks_UW )    
;----------------------------------------------------------------------

;*****************************************************************************
;* FUNCTION NAME: FUN_CChal_TriggerIntWatchdog_V                             *
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
$FUN_CChal_TriggerIntWatchdog_V:
;* --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 226 | t_SysTimeTimerTicks_UW |= 0x0000u;                                     
; 228 | #ifdef TOGGLEPIN                                                       
;----------------------------------------------------------------------
	.dwcfa	0x09, 26, 14
;* A1    assigned to _t_SysTimeTimerTicks_UW
DW$17	.dwtag  DW_TAG_formal_parameter, DW_AT_name("t_SysTimeTimerTicks_UW"), DW_AT_symbol_name("_t_SysTimeTimerTicks_UW")
	.dwattr DW$17, DW_AT_type(*DWT$1018)
	.dwattr DW$17, DW_AT_location[DW_OP_reg0]
;** 230	-----------------------    C$2 = &e_GIO_ST+36;
;* A1    assigned to C$1
DW$18	.dwtag  DW_TAG_variable, DW_AT_name("C$1"), DW_AT_symbol_name("C$1")
	.dwattr DW$18, DW_AT_type(*DWT$1042)
	.dwattr DW$18, DW_AT_location[DW_OP_reg0]
;* A1    assigned to C$2
DW$19	.dwtag  DW_TAG_variable, DW_AT_name("C$2"), DW_AT_symbol_name("C$2")
	.dwattr DW$19, DW_AT_type(*DWT$1047)
	.dwattr DW$19, DW_AT_location[DW_OP_reg0]
;* A2    assigned to C$3
DW$20	.dwtag  DW_TAG_variable, DW_AT_name("C$3"), DW_AT_symbol_name("C$3")
	.dwattr DW$20, DW_AT_type(*DWT$10)
	.dwattr DW$20, DW_AT_location[DW_OP_reg1]
	.dwpsn	"ADLATUS_HalRAM.c",230,11
;----------------------------------------------------------------------
; 230 | e_GIO_ST.Port_ST[0].Dset_UL = 0x10ul;                                  
;----------------------------------------------------------------------
        LDR       A1, CON3              ; |230| 
;** 230	-----------------------    ((volatile struct $$fake10 *)C$2)->Dset_UL = C$3 = 16u;
        MOV       A2, #16               ; |230| 
        STR       A2, [A1, #12]         ; |230| 
;** 231	-----------------------    ((volatile struct $$fake10 *)C$2)->Dclr_UL = C$3;
	.dwpsn	"ADLATUS_HalRAM.c",231,11
;----------------------------------------------------------------------
; 231 | e_GIO_ST.Port_ST[0].Dclr_UL = 0x10ul;                                  
; 233 | #endif                                                                 
;----------------------------------------------------------------------
        STR       A2, [A1, #16]         ; |231| 
;** 236	-----------------------    C$1 = &e_SARRTI_ST;
	.dwpsn	"ADLATUS_HalRAM.c",236,3
;----------------------------------------------------------------------
; 236 | e_SARRTI_ST.WKEY_UL = (UBYTE) 0xE5u;                                   
;----------------------------------------------------------------------
        LDR       A1, CON1              ; |236| 
;** 236	-----------------------    C$1->WKEY_UL = 229u;
        MOV       A2, #229              ; |236| 
        STR       A2, [A1, #12]         ; |236| 
;** 237	-----------------------    C$1->WKEY_UL = 163u;
	.dwpsn	"ADLATUS_HalRAM.c",237,3
;----------------------------------------------------------------------
; 237 | e_SARRTI_ST.WKEY_UL = (UBYTE) 0xA3u;                                   
;----------------------------------------------------------------------
        MOV       A2, #163              ; |237| 
        STR       A2, [A1, #12]         ; |237| 
;** 239	-----------------------    return;
	.dwpsn	"ADLATUS_HalRAM.c",239,3
;----------------------------------------------------------------------
; 239 | return;                                                                
;----------------------------------------------------------------------
	.dwpsn	"ADLATUS_HalRAM.c",241,1
        BX        LR
	.dwendentry
	.dwendtag DW$16



;******************************************************************************
;* CONSTANT TABLE                                                             *
;******************************************************************************
	.sect	".text"
	.align	4
CON1:	.field  	_e_SARRTI_ST,32
	.align	4
CON2:	.field  	_t_CChal_HalCtrl_ST,32
	.align	4
CON3:	.field  	_e_GIO_ST+36,32
;******************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                              *
;******************************************************************************
	.global	_t_CChal_HalCtrl_ST
	.global	_e_SARRTI_ST
	.global	_e_GIO_ST

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************
DWT$1018	.dwtag  DW_TAG_typedef, DW_AT_name("UWORD"), DW_AT_type(*DWT$8)
	.dwattr DWT$1018, DW_AT_language(DW_LANG_C)

DWT$1019	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DWT$1018)
	.dwattr DWT$1019, DW_AT_language(DW_LANG_C)
DWT$10	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned int")
	.dwattr DWT$10, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$10, DW_AT_byte_size(0x04)
DWT$1023	.dwtag  DW_TAG_typedef, DW_AT_name("ULONG"), DW_AT_type(*DWT$12)
	.dwattr DWT$1023, DW_AT_language(DW_LANG_C)

DWT$1024	.dwtag  DW_TAG_subroutine_type
	.dwattr DWT$1024, DW_AT_language(DW_LANG_C)
DW$21	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DWT$1018)
	.dwendtag DWT$1024

DWT$1026	.dwtag  DW_TAG_typedef, DW_AT_name("HALCONTROL_ST"), DW_AT_type(*DWT$1025)
	.dwattr DWT$1026, DW_AT_language(DW_LANG_C)
DWT$1027	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1026)
	.dwattr DWT$1027, DW_AT_address_class(0x20)
DWT$1028	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1025)
	.dwattr DWT$1028, DW_AT_address_class(0x20)
DWT$1041	.dwtag  DW_TAG_typedef, DW_AT_name("SARRTI_ST"), DW_AT_type(*DWT$1040)
	.dwattr DWT$1041, DW_AT_language(DW_LANG_C)
DWT$1042	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1040)
	.dwattr DWT$1042, DW_AT_address_class(0x20)
DWT$1047	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DWT$1046)
	.dwattr DWT$1047, DW_AT_address_class(0x20)
DWT$1052	.dwtag  DW_TAG_typedef, DW_AT_name("GIO_ST"), DW_AT_type(*DWT$1051)
	.dwattr DWT$1052, DW_AT_language(DW_LANG_C)
DWT$8	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned short")
	.dwattr DWT$8, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$8, DW_AT_byte_size(0x02)
DWT$12	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned long")
	.dwattr DWT$12, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DWT$12, DW_AT_byte_size(0x04)

DWT$1025	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1025, DW_AT_name("_HALCONTROL")
	.dwattr DWT$1025, DW_AT_byte_size(0x14)
DW$22	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1023)
	.dwattr DW$22, DW_AT_name("IntClockFrequency_UL"), DW_AT_symbol_name("_IntClockFrequency_UL")
	.dwattr DW$22, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$22, DW_AT_accessibility(DW_ACCESS_public)
DW$23	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$23, DW_AT_name("IntWatchdogTriggerTime_UW"), DW_AT_symbol_name("_IntWatchdogTriggerTime_UW")
	.dwattr DW$23, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$23, DW_AT_accessibility(DW_ACCESS_public)
DW$24	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$24, DW_AT_name("IntWtdTimerReloadValue_UW"), DW_AT_symbol_name("_IntWtdTimerReloadValue_UW")
	.dwattr DW$24, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr DW$24, DW_AT_accessibility(DW_ACCESS_public)
DW$25	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1018)
	.dwattr DW$25, DW_AT_name("HWTimerValue_UW"), DW_AT_symbol_name("_HWTimerValue_UW")
	.dwattr DW$25, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$25, DW_AT_accessibility(DW_ACCESS_public)
DW$26	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1023)
	.dwattr DW$26, DW_AT_name("OldTimerValue_UL"), DW_AT_symbol_name("_OldTimerValue_UL")
	.dwattr DW$26, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$26, DW_AT_accessibility(DW_ACCESS_public)
DW$27	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1023)
	.dwattr DW$27, DW_AT_name("TimerTicksForOneMilliSecond_UL"), DW_AT_symbol_name("_TimerTicksForOneMilliSecond_UL")
	.dwattr DW$27, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$27, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1025

DWT$1040	.dwtag  DW_TAG_volatile_type, DW_AT_type(*DWT$1039)

DWT$1046	.dwtag  DW_TAG_array_type, DW_AT_type(*DWT$1044)
	.dwattr DWT$1046, DW_AT_language(DW_LANG_C)
	.dwattr DWT$1046, DW_AT_byte_size(0xa0)
DW$28	.dwtag  DW_TAG_subrange_type
	.dwattr DW$28, DW_AT_upper_bound(0x07)
	.dwendtag DWT$1046

DWT$1051	.dwtag  DW_TAG_volatile_type, DW_AT_type(*DWT$1050)

DWT$1039	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1039, DW_AT_name("rti")
	.dwattr DWT$1039, DW_AT_byte_size(0x20)
DW$29	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1030)
	.dwattr DW$29, DW_AT_name("DRTICNTR_UN"), DW_AT_symbol_name("_DRTICNTR_UN")
	.dwattr DW$29, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$29, DW_AT_accessibility(DW_ACCESS_public)
DW$30	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1032)
	.dwattr DW$30, DW_AT_name("DRTIPCTL_UN"), DW_AT_symbol_name("_DRTIPCTL_UN")
	.dwattr DW$30, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$30, DW_AT_accessibility(DW_ACCESS_public)
DW$31	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1034)
	.dwattr DW$31, DW_AT_name("DRTICNTL_UN"), DW_AT_symbol_name("_DRTICNTL_UN")
	.dwattr DW$31, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$31, DW_AT_accessibility(DW_ACCESS_public)
DW$32	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$32, DW_AT_name("WKEY_UL"), DW_AT_symbol_name("_WKEY_UL")
	.dwattr DW$32, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$32, DW_AT_accessibility(DW_ACCESS_public)
DW$33	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$33, DW_AT_name("RTICR1_UL"), DW_AT_symbol_name("_RTICR1_UL")
	.dwattr DW$33, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$33, DW_AT_accessibility(DW_ACCESS_public)
DW$34	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$34, DW_AT_name("RTICR2_UL"), DW_AT_symbol_name("_RTICR2_UL")
	.dwattr DW$34, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr DW$34, DW_AT_accessibility(DW_ACCESS_public)
DW$35	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1036)
	.dwattr DW$35, DW_AT_name("DRTICINT_UN"), DW_AT_symbol_name("_DRTICINT_UN")
	.dwattr DW$35, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr DW$35, DW_AT_accessibility(DW_ACCESS_public)
DW$36	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1038)
	.dwattr DW$36, DW_AT_name("DRTICNTEN_UN"), DW_AT_symbol_name("_DRTICNTEN_UN")
	.dwattr DW$36, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr DW$36, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1039

DWT$1044	.dwtag  DW_TAG_volatile_type, DW_AT_type(*DWT$1043)

DWT$1050	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1050, DW_AT_name("gio_st")
	.dwattr DWT$1050, DW_AT_byte_size(0xc4)
DW$37	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1048)
	.dwattr DW$37, DW_AT_name("Pwdn_ST"), DW_AT_symbol_name("_Pwdn_ST")
	.dwattr DW$37, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$37, DW_AT_accessibility(DW_ACCESS_public)
DW$38	.dwtag  DW_TAG_member, DW_AT_type(*DWT$6)
	.dwattr DW$38, DW_AT_name("Ena_UB"), DW_AT_symbol_name("_Ena_UB")
	.dwattr DW$38, DW_AT_data_member_location[DW_OP_plus_uconst 0x7]
	.dwattr DW$38, DW_AT_accessibility(DW_ACCESS_public)
DW$39	.dwtag  DW_TAG_member, DW_AT_type(*DWT$6)
	.dwattr DW$39, DW_AT_name("Pol_UB"), DW_AT_symbol_name("_Pol_UB")
	.dwattr DW$39, DW_AT_data_member_location[DW_OP_plus_uconst 0xb]
	.dwattr DW$39, DW_AT_accessibility(DW_ACCESS_public)
DW$40	.dwtag  DW_TAG_member, DW_AT_type(*DWT$6)
	.dwattr DW$40, DW_AT_name("Flg_UB"), DW_AT_symbol_name("_Flg_UB")
	.dwattr DW$40, DW_AT_data_member_location[DW_OP_plus_uconst 0xf]
	.dwattr DW$40, DW_AT_accessibility(DW_ACCESS_public)
DW$41	.dwtag  DW_TAG_member, DW_AT_type(*DWT$6)
	.dwattr DW$41, DW_AT_name("Pry_UB"), DW_AT_symbol_name("_Pry_UB")
	.dwattr DW$41, DW_AT_data_member_location[DW_OP_plus_uconst 0x13]
	.dwattr DW$41, DW_AT_accessibility(DW_ACCESS_public)
DW$42	.dwtag  DW_TAG_member, DW_AT_type(*DWT$6)
	.dwattr DW$42, DW_AT_name("OffA_UB"), DW_AT_symbol_name("_OffA_UB")
	.dwattr DW$42, DW_AT_data_member_location[DW_OP_plus_uconst 0x17]
	.dwattr DW$42, DW_AT_accessibility(DW_ACCESS_public)
DW$43	.dwtag  DW_TAG_member, DW_AT_type(*DWT$6)
	.dwattr DW$43, DW_AT_name("EmuA_UB"), DW_AT_symbol_name("_EmuA_UB")
	.dwattr DW$43, DW_AT_data_member_location[DW_OP_plus_uconst 0x1b]
	.dwattr DW$43, DW_AT_accessibility(DW_ACCESS_public)
DW$44	.dwtag  DW_TAG_member, DW_AT_type(*DWT$6)
	.dwattr DW$44, DW_AT_name("OffB_UB"), DW_AT_symbol_name("_OffB_UB")
	.dwattr DW$44, DW_AT_data_member_location[DW_OP_plus_uconst 0x1f]
	.dwattr DW$44, DW_AT_accessibility(DW_ACCESS_public)
DW$45	.dwtag  DW_TAG_member, DW_AT_type(*DWT$6)
	.dwattr DW$45, DW_AT_name("EmuB_UB"), DW_AT_symbol_name("_EmuB_UB")
	.dwattr DW$45, DW_AT_data_member_location[DW_OP_plus_uconst 0x23]
	.dwattr DW$45, DW_AT_accessibility(DW_ACCESS_public)
DW$46	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1049)
	.dwattr DW$46, DW_AT_name("Port_ST"), DW_AT_symbol_name("_Port_ST")
	.dwattr DW$46, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr DW$46, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1050

DWT$6	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned char")
	.dwattr DWT$6, DW_AT_encoding(DW_ATE_unsigned_char)
	.dwattr DWT$6, DW_AT_byte_size(0x01)

DWT$1030	.dwtag  DW_TAG_union_type
	.dwattr DWT$1030, DW_AT_byte_size(0x04)
DW$47	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$47, DW_AT_name("DRTICNTR_UL"), DW_AT_symbol_name("_DRTICNTR_UL")
	.dwattr DW$47, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$47, DW_AT_accessibility(DW_ACCESS_public)
DW$48	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1029)
	.dwattr DW$48, DW_AT_name("DRTICNTR_ST"), DW_AT_symbol_name("_DRTICNTR_ST")
	.dwattr DW$48, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$48, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1030


DWT$1032	.dwtag  DW_TAG_union_type
	.dwattr DWT$1032, DW_AT_byte_size(0x04)
DW$49	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$49, DW_AT_name("DRTIPCTL_UL"), DW_AT_symbol_name("_DRTIPCTL_UL")
	.dwattr DW$49, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$49, DW_AT_accessibility(DW_ACCESS_public)
DW$50	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1031)
	.dwattr DW$50, DW_AT_name("DRTIPCTL_ST"), DW_AT_symbol_name("_DRTIPCTL_ST")
	.dwattr DW$50, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$50, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1032


DWT$1034	.dwtag  DW_TAG_union_type
	.dwattr DWT$1034, DW_AT_byte_size(0x04)
DW$51	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$51, DW_AT_name("DRTICNTL_UL"), DW_AT_symbol_name("_DRTICNTL_UL")
	.dwattr DW$51, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$51, DW_AT_accessibility(DW_ACCESS_public)
DW$52	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1033)
	.dwattr DW$52, DW_AT_name("DRTICNTL_ST"), DW_AT_symbol_name("_DRTICNTL_ST")
	.dwattr DW$52, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$52, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1034


DWT$1036	.dwtag  DW_TAG_union_type
	.dwattr DWT$1036, DW_AT_byte_size(0x04)
DW$53	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$53, DW_AT_name("DRTICINT_UL"), DW_AT_symbol_name("_DRTICINT_UL")
	.dwattr DW$53, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$53, DW_AT_accessibility(DW_ACCESS_public)
DW$54	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1035)
	.dwattr DW$54, DW_AT_name("DRTICINT_ST"), DW_AT_symbol_name("_DRTICINT_ST")
	.dwattr DW$54, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$54, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1036


DWT$1038	.dwtag  DW_TAG_union_type
	.dwattr DWT$1038, DW_AT_byte_size(0x04)
DW$55	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$55, DW_AT_name("DRTICNTEN_UL"), DW_AT_symbol_name("_DRTICNTEN_UL")
	.dwattr DW$55, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$55, DW_AT_accessibility(DW_ACCESS_public)
DW$56	.dwtag  DW_TAG_member, DW_AT_type(*DWT$1037)
	.dwattr DW$56, DW_AT_name("DRTICNTEN_ST"), DW_AT_symbol_name("_DRTICNTEN_ST")
	.dwattr DW$56, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$56, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1038


DWT$1043	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1043, DW_AT_byte_size(0x14)
DW$57	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$57, DW_AT_name("Dir_UL"), DW_AT_symbol_name("_Dir_UL")
	.dwattr DW$57, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$57, DW_AT_accessibility(DW_ACCESS_public)
DW$58	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$58, DW_AT_name("Din_UL"), DW_AT_symbol_name("_Din_UL")
	.dwattr DW$58, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$58, DW_AT_accessibility(DW_ACCESS_public)
DW$59	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$59, DW_AT_name("Dout_UL"), DW_AT_symbol_name("_Dout_UL")
	.dwattr DW$59, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$59, DW_AT_accessibility(DW_ACCESS_public)
DW$60	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$60, DW_AT_name("Dset_UL"), DW_AT_symbol_name("_Dset_UL")
	.dwattr DW$60, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$60, DW_AT_accessibility(DW_ACCESS_public)
DW$61	.dwtag  DW_TAG_member, DW_AT_type(*DWT$12)
	.dwattr DW$61, DW_AT_name("Dclr_UL"), DW_AT_symbol_name("_Dclr_UL")
	.dwattr DW$61, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$61, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1043


DWT$1049	.dwtag  DW_TAG_array_type, DW_AT_type(*DWT$1043)
	.dwattr DWT$1049, DW_AT_language(DW_LANG_C)
	.dwattr DWT$1049, DW_AT_byte_size(0xa0)
DW$62	.dwtag  DW_TAG_subrange_type
	.dwattr DW$62, DW_AT_upper_bound(0x07)
	.dwendtag DWT$1049


DWT$1048	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1048, DW_AT_byte_size(0x04)
DW$63	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$63, DW_AT_name("Pwdn_B1"), DW_AT_symbol_name("_Pwdn_B1")
	.dwattr DW$63, DW_AT_bit_offset(0x1f), DW_AT_bit_size(0x01)
	.dwattr DW$63, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$63, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1048


DWT$1029	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1029, DW_AT_byte_size(0x04)
DW$64	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$64, DW_AT_name("DRTICNTR_B21"), DW_AT_symbol_name("_DRTICNTR_B21")
	.dwattr DW$64, DW_AT_bit_offset(0x00), DW_AT_bit_size(0x15)
	.dwattr DW$64, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$64, DW_AT_accessibility(DW_ACCESS_public)
DW$65	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$65, DW_AT_name("DRTIMOD_B11"), DW_AT_symbol_name("_DRTIMOD_B11")
	.dwattr DW$65, DW_AT_bit_offset(0x15), DW_AT_bit_size(0x0b)
	.dwattr DW$65, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$65, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1029


DWT$1031	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1031, DW_AT_byte_size(0x04)
DW$66	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$66, DW_AT_name("RTIM_B3"), DW_AT_symbol_name("_RTIM_B3")
	.dwattr DW$66, DW_AT_bit_offset(0x12), DW_AT_bit_size(0x03)
	.dwattr DW$66, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$66, DW_AT_accessibility(DW_ACCESS_public)
DW$67	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$67, DW_AT_name("PREDL_B11"), DW_AT_symbol_name("_PREDL_B11")
	.dwattr DW$67, DW_AT_bit_offset(0x15), DW_AT_bit_size(0x0b)
	.dwattr DW$67, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$67, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1031


DWT$1033	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1033, DW_AT_byte_size(0x04)
DW$68	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$68, DW_AT_name("RTIF_B1"), DW_AT_symbol_name("_RTIF_B1")
	.dwattr DW$68, DW_AT_bit_offset(0x18), DW_AT_bit_size(0x01)
	.dwattr DW$68, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$68, DW_AT_accessibility(DW_ACCESS_public)
DW$69	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$69, DW_AT_name("RTIE_B1"), DW_AT_symbol_name("_RTIE_B1")
	.dwattr DW$69, DW_AT_bit_offset(0x19), DW_AT_bit_size(0x01)
	.dwattr DW$69, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$69, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1033


DWT$1035	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1035, DW_AT_byte_size(0x04)
DW$70	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$70, DW_AT_name("CF1_B1"), DW_AT_symbol_name("_CF1_B1")
	.dwattr DW$70, DW_AT_bit_offset(0x18), DW_AT_bit_size(0x01)
	.dwattr DW$70, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$70, DW_AT_accessibility(DW_ACCESS_public)
DW$71	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$71, DW_AT_name("CF2_B1"), DW_AT_symbol_name("_CF2_B1")
	.dwattr DW$71, DW_AT_bit_offset(0x19), DW_AT_bit_size(0x01)
	.dwattr DW$71, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$71, DW_AT_accessibility(DW_ACCESS_public)
DW$72	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$72, DW_AT_name("CE1_B1"), DW_AT_symbol_name("_CE1_B1")
	.dwattr DW$72, DW_AT_bit_offset(0x1a), DW_AT_bit_size(0x01)
	.dwattr DW$72, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$72, DW_AT_accessibility(DW_ACCESS_public)
DW$73	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$73, DW_AT_name("CR2_B1"), DW_AT_symbol_name("_CR2_B1")
	.dwattr DW$73, DW_AT_bit_offset(0x1b), DW_AT_bit_size(0x01)
	.dwattr DW$73, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$73, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1035


DWT$1037	.dwtag  DW_TAG_structure_type
	.dwattr DWT$1037, DW_AT_byte_size(0x04)
DW$74	.dwtag  DW_TAG_member, DW_AT_type(*DWT$10)
	.dwattr DW$74, DW_AT_name("CNTEN_B2"), DW_AT_symbol_name("_CNTEN_B2")
	.dwattr DW$74, DW_AT_bit_offset(0x1e), DW_AT_bit_size(0x02)
	.dwattr DW$74, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$74, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DWT$1037


	.dwattr DW$5, DW_AT_external(0x01)
	.dwattr DW$5, DW_AT_type(*DWT$1018)
	.dwattr DW$16, DW_AT_external(0x01)
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

DW$75	.dwtag  DW_TAG_assign_register, DW_AT_name("A1")
	.dwattr DW$75, DW_AT_location[DW_OP_reg0]
DW$76	.dwtag  DW_TAG_assign_register, DW_AT_name("A2")
	.dwattr DW$76, DW_AT_location[DW_OP_reg1]
DW$77	.dwtag  DW_TAG_assign_register, DW_AT_name("A3")
	.dwattr DW$77, DW_AT_location[DW_OP_reg2]
DW$78	.dwtag  DW_TAG_assign_register, DW_AT_name("A4")
	.dwattr DW$78, DW_AT_location[DW_OP_reg3]
DW$79	.dwtag  DW_TAG_assign_register, DW_AT_name("V1")
	.dwattr DW$79, DW_AT_location[DW_OP_reg4]
DW$80	.dwtag  DW_TAG_assign_register, DW_AT_name("V2")
	.dwattr DW$80, DW_AT_location[DW_OP_reg5]
DW$81	.dwtag  DW_TAG_assign_register, DW_AT_name("V3")
	.dwattr DW$81, DW_AT_location[DW_OP_reg6]
DW$82	.dwtag  DW_TAG_assign_register, DW_AT_name("V4")
	.dwattr DW$82, DW_AT_location[DW_OP_reg7]
DW$83	.dwtag  DW_TAG_assign_register, DW_AT_name("V5")
	.dwattr DW$83, DW_AT_location[DW_OP_reg8]
DW$84	.dwtag  DW_TAG_assign_register, DW_AT_name("V6")
	.dwattr DW$84, DW_AT_location[DW_OP_reg9]
DW$85	.dwtag  DW_TAG_assign_register, DW_AT_name("V7")
	.dwattr DW$85, DW_AT_location[DW_OP_reg10]
DW$86	.dwtag  DW_TAG_assign_register, DW_AT_name("V8")
	.dwattr DW$86, DW_AT_location[DW_OP_reg11]
DW$87	.dwtag  DW_TAG_assign_register, DW_AT_name("V9")
	.dwattr DW$87, DW_AT_location[DW_OP_reg12]
DW$88	.dwtag  DW_TAG_assign_register, DW_AT_name("SP")
	.dwattr DW$88, DW_AT_location[DW_OP_reg13]
DW$89	.dwtag  DW_TAG_assign_register, DW_AT_name("LR")
	.dwattr DW$89, DW_AT_location[DW_OP_reg14]
DW$90	.dwtag  DW_TAG_assign_register, DW_AT_name("PC")
	.dwattr DW$90, DW_AT_location[DW_OP_reg15]
DW$91	.dwtag  DW_TAG_assign_register, DW_AT_name("C0")
	.dwattr DW$91, DW_AT_location[DW_OP_reg16]
DW$92	.dwtag  DW_TAG_assign_register, DW_AT_name("C1")
	.dwattr DW$92, DW_AT_location[DW_OP_reg17]
DW$93	.dwtag  DW_TAG_assign_register, DW_AT_name("C2")
	.dwattr DW$93, DW_AT_location[DW_OP_reg18]
DW$94	.dwtag  DW_TAG_assign_register, DW_AT_name("C3")
	.dwattr DW$94, DW_AT_location[DW_OP_reg19]
DW$95	.dwtag  DW_TAG_assign_register, DW_AT_name("C4")
	.dwattr DW$95, DW_AT_location[DW_OP_reg20]
DW$96	.dwtag  DW_TAG_assign_register, DW_AT_name("C5")
	.dwattr DW$96, DW_AT_location[DW_OP_reg21]
DW$97	.dwtag  DW_TAG_assign_register, DW_AT_name("C6")
	.dwattr DW$97, DW_AT_location[DW_OP_reg22]
DW$98	.dwtag  DW_TAG_assign_register, DW_AT_name("C7")
	.dwattr DW$98, DW_AT_location[DW_OP_reg23]
DW$99	.dwtag  DW_TAG_assign_register, DW_AT_name("AP")
	.dwattr DW$99, DW_AT_location[DW_OP_reg24]
DW$100	.dwtag  DW_TAG_assign_register, DW_AT_name("SR")
	.dwattr DW$100, DW_AT_location[DW_OP_reg25]
DW$101	.dwtag  DW_TAG_assign_register, DW_AT_name("CIE_RETA")
	.dwattr DW$101, DW_AT_location[DW_OP_reg26]
	.dwendtag DWCU

