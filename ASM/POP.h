/******************************************************************************\
# H - POP                                        #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2025/11/23 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/11/30 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifdef ASM_PUSH_H
#	undef ASM_PUSH_H
#	undef __START__
#	undef __END__
#	undef SECTION
#	undef END
#	undef VALUE
#	undef MEM8
#	undef MEM16
#	undef MEM32
#	undef MEM64
#	undef MEM8_INDEX
#	undef MEM16_INDEX
#	undef MEM32_INDEX
#	undef MEM64_INDEX

#	ifdef _
#		undef _
#	endif /* _ */

#	ifdef __CPU_INTEL__
#		undef IP
#		undef EIP
#		undef RIP
#		undef CS
#		undef DS
#		undef SS
#		undef ES
#		undef FS
#		undef GS
#		undef R8
#		undef R8D
#		undef R8W
#		undef R8B
#		undef R9
#		undef R9D
#		undef R9W
#		undef R9B
#		undef R10
#		undef R10D
#		undef R10W
#		undef R10B
#		undef R11
#		undef R11D
#		undef R11W
#		undef R11B
#		undef R12
#		undef R12D
#		undef R12W
#		undef R12B
#		undef R13
#		undef R13D
#		undef R13W
#		undef R13B
#		undef R14
#		undef R14D
#		undef R14W
#		undef R14B
#		undef R15
#		undef R15D
#		undef R15W
#		undef R15B
#		undef CR0
#		undef CR2
#		undef CR3
#		undef CR4
#		undef CR8
#		undef DR0
#		undef DR1
#		undef DR2
#		undef DR3
#		undef DR4
#		undef DR5
#		undef DR6
#		undef DR7
#		undef GDTR
#		undef IDTR
#		undef LDTR
#		undef TR
#		undef MM0
#		undef MM1
#		undef MM2
#		undef MM3
#		undef MM4
#		undef MM5
#		undef MM6
#		undef MM7
#		undef XMM0
#		undef XMM1
#		undef XMM2
#		undef XMM3
#		undef XMM4
#		undef XMM5
#		undef XMM6
#		undef XMM7
#		undef XMM8
#		undef XMM9
#		undef XMM10
#		undef XMM11
#		undef XMM12
#		undef XMM13
#		undef XMM14
#		undef XMM15
#		undef YMM0
#		undef YMM1
#		undef YMM2
#		undef YMM3
#		undef YMM4
#		undef YMM5
#		undef YMM6
#		undef YMM7
#		undef YMM8
#		undef YMM9
#		undef YMM10
#		undef YMM11
#		undef YMM12
#		undef YMM13
#		undef YMM14
#		undef YMM15
#		undef ZMM0
#		undef ZMM1
#		undef ZMM2
#		undef ZMM3
#		undef ZMM4
#		undef ZMM5
#		undef ZMM6
#		undef ZMM7
#		undef ZMM8
#		undef ZMM9
#		undef ZMM10
#		undef ZMM11
#		undef ZMM12
#		undef ZMM13
#		undef ZMM14
#		undef ZMM15
#		undef ZMM16
#		undef ZMM17
#		undef ZMM18
#		undef ZMM19
#		undef ZMM20
#		undef ZMM21
#		undef ZMM22
#		undef ZMM23
#		undef ZMM24
#		undef ZMM25
#		undef ZMM26
#		undef ZMM27
#		undef ZMM28
#		undef ZMM29
#		undef ZMM30
#		undef ZMM31
#		undef MOV8
#		undef MOV16
#		undef MOV32
#		undef MOV64
#		undef ADD8
#		undef ADD16
#		undef ADD32
#		undef ADD64
#		undef AH
#		undef SI
#		undef ESI
#		undef RSI
#		undef BH
#		undef DI
#		undef EDI
#		undef RDI
#		undef CH
#		undef BP
#		undef EBP
#		undef RBP
#		undef DH
#		undef SP
#		undef ESP
#		undef RSP
#		undef AL
#		undef AX
#		undef EAX
#		undef RAX
#		undef BL
#		undef BX
#		undef EBX
#		undef RBX
#		undef CL
#		undef CX
#		undef ECX
#		undef RCX
#		undef DL
#		undef DX
#		undef EDX
#		undef RDX
#		undef RET
#	endif /* __CPU_INTEL__ */

/* *************************** [v] C++ (POP) [v] **************************** */
#	ifdef __cplusplus /* C++ */
}
#	endif /* __cplusplus */
/* *************************** [^] C++ (POP) [^] **************************** */

/* ************************ [v] TI CGT CCS (POP) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */
#endif /* ASM_PUSH_H */

#ifdef __EOF__
#	undef __EOF__
#endif /* __EOF__ */
#define __EOF__ //  <- FOR DOS, CP/M, ETC
