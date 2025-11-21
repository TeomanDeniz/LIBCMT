/******************************************************************************\
# H - PUSH                                       #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/02/27 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/11/22 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*\
|@                                                                            @|
|@                                  WARNING!                                  @|
|@                                                                            @|
|@                          THIS IS A WIP CONTENT!!!                          @|
|@                                                                            @|
|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
|@                                                                            @|
|@     THIS EXTENSION MIGHT NOT WORK ON ALL COMPILERS, OPERATING SYSTEMS,     @|
|@                            AND ARCHITECTURES!!!                            @|
|@                                                                            @|
|@                  UNDERGO MAJOR MAINTENANCE IN THE FUTURE!                  @|
|@                         USE IT WITH YOUR OWN RISK!                         @|
|@                                              ^^^^                          @|
|@                                                                            @|
\*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

/******************************************************************************\
|*                                  CONTENTS                                  *|
|******************************************************************************|
|*                            ....................                            *|
|*                            : BUILTIN KEYWORDS :                            *|
|*............................;,,,,,,,,,,,,,,,,,,;............................*|
|*    NAME   :    TYPE    :                   DESCRIPTION                     *|
|*...........:............:...................................................*|
|* SECTION   : #define () : CREATE A SECTION                                  *|
|*...........:............:...................................................*|
|* END       : #define    : END OF SECTION                                    *|
|*...........:............:...................................................*|
|* MEM       : #define () : USE MEMORY (ONE ARG)                              *|
|*...........:............:...................................................*|
|* MEM_INDEX : #define () : USE MEMORY (TWO ARGS)                             *|
|*...........:............:...................................................*|
|*                                                                            *|
|*                           .....................                            *|
|*                           : REGISTERS (INTEL) :                            *|
|*...........................;,,,,,,,,,,,,,,,,,,,;............................*|
|*              KEYWORDS              :              DESCRIPTION              *|
|*....................................:.......................................*|
|*                   RSI, ESI, SI, AH : SOURCE INDEX REGISTER                 *|
|*....................................:.......................................*|
|*                   RDI, EDI, DI, BH : DESTINATION INDEX REGISTER            *|
|*....................................:.......................................*|
|*                   RBP, EBP, BP, CH : BASE POINTER REGISTER                 *|
|*....................................:.......................................*|
|*                   RSP, ESP, SP, DH : STACK POINTER REGISTER                *|
|*....................................:.......................................*|
|*                   RAX, EAX, AX, AL : PRIMARY ACCUMULATOR REGISTER          *|
|*....................................:.......................................*|
|*                   RBX, EBX, BX, BL : BASE REGISTER                         *|
|*....................................:.......................................*|
|*                   RCX, ECX, CX, CL : COUNTER REGISTER                      *|
|*....................................:.......................................*|
|*                   RDX, EDX, DX, DL : DATA REGISTER                         *|
|*....................................:.......................................*|
|*             CS, DS, SS, ES, FS, GS : SEGMENT REGISTERS                     *|
|*....................................:.......................................*|
|*            R8, R9, o o o, R14, R15 : GENERAL-PURPOSE EXTENSION REGISTERS   *|
|*....................................:.......................................*|
|*            CR0, CR2, CR3, CR4, CR8 : CONTROL REGISTERS                     *|
|*....................................:.......................................*|
|*          DR0, DR1, o o o, DR7, DR8 : DEBUG REGISTERS                       *|
|*....................................:.......................................*|
|*               GDTR, IDTR, LDTR, TR : DESCRIPTOR TABLE REGISTERS            *|
|*....................................:.......................................*|
|*          MM0, MM1, o o o, MM6, MM7 : 128-BIT INTEGER REGISTERS             *|
|*....................................:.......................................*|
|*    YMM0, YMM1, o o o, YMM14, YMM15 : 256-BIT INTEGER REGISTERS             *|
|*....................................:.......................................*|
|*    ZMM0, ZMM1, o o o, ZMM30, ZMM31 : 512-BIT INTEGER REGISTERS             *|
|*....................................:.......................................*|
|*                                                                            *|
|*                            ....................                            *|
|*                            : COMMANDS (INTEL) :                            *|
|*............................;,,,,,,,,,,,,,,,,,,;............................*|
|* NAME  :                            DESCRIPTION                             *|
|*.......:....................................................................*|
|* RET   : IF SECTION CALLED VIA CALL, JUMPS BACK TO WHERE IT IS CALLED       *|
|*.......:....................................................................*|
|* MOV8  : MOVES 1 BYTE FROM THE SOURCE TO THE DESTINATION                    *|
|*.......:....................................................................*|
|* MOV16 : MOVES 2 BYTES FROM THE SOURCE TO THE DESTINATION                   *|
|*.......:....................................................................*|
|* MOV32 : MOVES 4 BYTES FROM THE SOURCE TO THE DESTINATION                   *|
|*.......:....................................................................*|
|* MOV64 : MOVES 8 BYTES FROM THE SOURCE TO THE DESTINATION                   *|
|*.......:....................................................................*|
|* ADD8  : ADDS 1 BYTE FROM THE SOURCE TO THE DESTINATION                     *|
|*.......:....................................................................*|
|* ADD16 : ADDS 2 BYTES FROM THE SOURCE TO THE DESTINATION                    *|
|*.......:....................................................................*|
|* ADD32 : ADDS 4 BYTES FROM THE SOURCE TO THE DESTINATION                    *|
|*.......:....................................................................*|
|* ADD64 : ADDS 8 BYTES FROM THE SOURCE TO THE DESTINATION                    *|
|*.......:....................................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::: OVERVIEW :::::::::::::::::::::::::::::::: *|
|* THIS HEADER PROVIDES A UNIFIED MACRO LAYER THAT LETS YOU WRITE INLINE      *|
|* ASSEMBLY WITH MINIMAL COMPILER-SPECIFIC BOILERPLATE.                       *|
|*                                                                            *|
|* THE SYSTEM:                                                                *|
|* - DETECTS COMPILER ASM SUPPORT                                             *|
|* - DETECTS ARCHITECTURE: 16-BIT / 32-BIT / 64-BIT                           *|
|* - DETECTS BACKEND SYNTAX: AT&T, INTEL, OR MSVC INLINE ASM                  *|
|* - DEFINES STABLE MACRO KEYWORDS SO YOUR ASM BLOCKS STAY PORTABLE           *|
|*                                                                            *|
|* IT ABSTRACTS:                                                              *|
|* - REGISTER NAMES                                                           *|
|* - MEMORY ADDRESSING                                                        *|
|* - BASIC ARITHMETIC AND MOVE OPERATIONS                                     *|
|* - SECTION CREATION (LABELS)                                                *|
|* - RETURN INSTRUCTIONS                                                      *|
|*                                                                            *|
|* NOTE: MOV64, ADD64, @64 ETC... DOWNSCALE AUTOMATICALLY ON 32/16-BIT MODES. *|
|*                                                                            *|
|* :::::::::::::::::::::::::::: WHAT IS IT DOES? :::::::::::::::::::::::::::: *|
|*                                                                            *|
|* * ENSURES YOUR INLINE ASM CAN COMPILE ACROSS:                              *|
|* :                                                                          *|
|* :.. GCC / CLANG (AT&T SYNTAX)                                              *|
|* :                                                                          *|
|* :.. ICC (AT&T OR INTEL DEPENDING ON BUILD)                                 *|
|* :                                                                          *|
|* :.. MSVC (__asm{} INTEL SYNTAX)                                            *|
|*                                                                            *|
|* * PROVIDES STABLE NAMES FOR REGISTERS THAT CHANGE SIZE ACROSS              *|
|*   ARCHITECTURES                                                            *|
|*                                                                            *|
|* * ALLOWS MACRO-STYLE 8/16/32/64-BIT OPS WITHOUT MANUAL SYNTAX BRANCHING    *|
|*                                                                            *|
|* * PROVIDES UNIFIED MEMORY ADDRESSING PATTERNS                              *|
|*                                                                            *|
|* * ENABLES PLATFORM-INDEPENDENT SECTION CREATION FOR ASM ENTRY POINTS       *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|*  O A RANDOM EXAMPLE                                                        *|
|*  :                                                                         *|
|* 1| #include "LIBCMT/ASM/PUSH.h"                                            *|
|* 2| SECTION(example_func) // example_func:                                  *|
|* 3|     MOV32(EAX, EBX)   // mov rax, ebx                                   *|
|* 4|     ADD32(EAX, 1)     // add eax, 1                                     *|
|* 5|     RET               // ret                                            *|
|* 6| END                                                                     *|
|* 7| #include "LIBCMT/ASM/POP.h"                                             *|
|* 8|                                                                         *|
|* 9| extern int example_func(void); // Connect it with C                     *|
|*  :                                                                         *|
|*                                                                            *|
|*  O EXAMPLE - BYTE COPY ROUTINE                                             *|
|*  :                                                                         *|
|* 1| #include "LIBCMT/ASM/PUSH.h"                                            *|
|* 2| SECTION(copy_byte)     // copy_byte:                                    *| 
|* 3|     MOV8(MEM(RDI), AL) // mov byte [rdi], al                            *|
|* 4|     RET                // ret                                           *|
|* 5| END                                                                     *|
|* 6| #include "LIBCMT/ASM/POP.h"                                             *|
|*  :                                                                         *|
|*                                                                            *|
|*  O EXAMPLE - ADD VALUE AT INDEX                                            *|
|*  :                                                                         *|
|* 1| #include "LIBCMT/ASM/PUSH.h"                                            *|
|* 2| SECTION(add_indexed)                // add_indexed                      *|
|* 3|     ADD32(MEM_INDEX(RAX, RCX), EDX) // add dword [rax + rcx], edx       *|
|* 4|     RET                             // ret                              *|
|* 5| END                                                                     *|
|* 6| #include "LIBCMT/ASM/POP.h"                                             *|
|*  :                                                                         *|
|*                                                                            *|
\******************************************************************************/

#ifndef ASM_PUSH_H
#	define ASM_PUSH_H 202511 /* VERSION */

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../CHECK_FEATURE/INLINE_ASM.h" /*
#	 define IS__INLINE_ASM__SUPPORTED
#	 define INLINE_ASM_TYPE__GNU
#	         */
#	include "../ENVIRONMENTS/CPU.h" /*
#	 define __CPU_INTEL__
#	        */
#	include "../ENVIRONMENTS/ARCHITECTURE.h" /*
#	 define __SYSTEM_512_BIT__
#	 define __SYSTEM_256_BIT__
#	 define __SYSTEM_128_BIT__
#	 define __SYSTEM_64_BIT__
#	 define __SYSTEM_32_BIT__
#	 define __SYSTEM_16_BIT__
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *********************** [v] TI CGT CCS (PUSH) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_push /* TI CGT CCS COMPILER DIRECTIVES */
#		pragma CHECK_MISRA("5.4") /* TAG NAMES SHALL BE A UNIQUE IDENTIFIER */
#		pragma CHECK_MISRA("19.3") /*
#			THE #INCLUDE DIRECTIVE SHALL BE FOLLOWED BY EITHER A <FILENAME> OR
#			"FILENAME" SEQUENCE
#		*/
#	endif /* __TI_COMPILER_VERSION__ */
/* *********************** [^] TI CGT CCS (PUSH) [^] ************************ */

/* *************************** [v] C++ (PUSH) [v] *************************** */
#	ifdef __cplusplus /* C++ */
extern "C" {
#	endif /* __cplusplus */
/* *************************** [^] C++ (PUSH) [^] *************************** */

#	ifdef IS__INLINE_ASM__SUPPORTED
#		ifdef INLINE_ASM_TYPE__GNU
#			define LOCALMACRO_ATNT_SYNTAX_STRING
#			define __START__
#			define __END__ "\n"
#			define SECTION(NAME) __asm__ (".global "#NAME"\n"#NAME":\n"
#			define END );
#		endif /* INLINE_ASM_TYPE__GNU */
#		ifdef INLINE_ASM_TYPE__ISO
#			define LOCALMACRO_ATNT_SYNTAX_STRING
#			define __START__
#			define __END__ "\n"
#			define SECTION(NAME) \
			__asm__ (".section "#NAME",\"a\"\n.global "#NAME"\n"#NAME":\n"
#			define END ".text");	
#		endif /* INLINE_ASM_TYPE__ISO */
#		ifdef INLINE_ASM_TYPE__MSVC
#			define LOCALMACRO_INTEL_SYNTAX_PURE
#			define __START__
#			define __END__
#			define SECTION(NAME) __declspec(naked) int NAME(void){__asm {
#			define END }}
#		endif /* INLINE_ASM_TYPE__MSVC */
#		ifdef LOCALMACRO_ATNT_SYNTAX_STRING
#			undef LOCALMACRO_ATNT_SYNTAX_STRING
#			define MEM(ARG) "("#ARG")"
#			define MEM_INDEX(ARG, INDEX) "("#ARG","#INDEX")"
#			ifdef __CPU_INTEL__
#				define CS %cs
#				define DS %ds
#				define SS %ss
#				define ES %es
#				define FS %fs
#				define GS %gs
#				ifdef __MMX__
#					define MM0 %mm0
#					define MM1 %mm1
#					define MM2 %mm2
#					define MM3 %mm3
#					define MM4 %mm4
#					define MM5 %mm5
#					define MM6 %mm6
#					define MM7 %mm7
#				else
#					define MM0 ERROR__MMX_DOES_NOT_SUPPORTED
#					define MM1 MM0
#					define MM2 MM0
#					define MM3 MM0
#					define MM4 MM0
#					define MM5 MM0
#					define MM6 MM0
#					define MM7 MM0
#				endif /* __MMX__ */
#				ifdef __SYSTEM_128_BIT__
#					define XMM0 %xmm0
#					define XMM1 %xmm1
#					define XMM2 %xmm2
#					define XMM3 %xmm3
#					define XMM4 %xmm4
#					define XMM5 %xmm5
#					define XMM6 %xmm6
#					define XMM7 %xmm7
#					define XMM8 %xmm8
#					define XMM9 %xmm9
#					define XMM10 %xmm10
#					define XMM11 %xmm11
#					define XMM12 %xmm12
#					define XMM13 %xmm13
#					define XMM14 %xmm14
#					define XMM15 %xmm15
#				else
#					define XMM0 ERROR__SSE128_REGISTERS_DOES_NOT_SUPPORTED
#					define XMM1 XMM0
#					define XMM2 XMM0
#					define XMM3 XMM0
#					define XMM4 XMM0
#					define XMM5 XMM0
#					define XMM6 XMM0
#					define XMM7 XMM0
#					define XMM8 XMM0
#					define XMM9 XMM0
#					define XMM10 XMM0
#					define XMM11 XMM0
#					define XMM12 XMM0
#					define XMM13 XMM0
#					define XMM14 XMM0
#					define XMM15 XMM0
#				endif /* __SYSTEM_128_BIT__ */
#				ifdef __SYSTEM_256_BIT__
#					define YMM0 %ymm0
#					define YMM1 %ymm1
#					define YMM2 %ymm2
#					define YMM3 %ymm3
#					define YMM4 %ymm4
#					define YMM5 %ymm5
#					define YMM6 %ymm6
#					define YMM7 %ymm7
#					define YMM8 %ymm8
#					define YMM9 %ymm9
#					define YMM10 %ymm10
#					define YMM11 %ymm11
#					define YMM12 %ymm12
#					define YMM13 %ymm13
#					define YMM14 %ymm14
#					define YMM15 %ymm15
#				else
#					define YMM0 ERROR__AVX256_REGISTERS_DOES_NOT_SUPPORTED
#					define YMM1 YMM0
#					define YMM2 YMM0
#					define YMM3 YMM0
#					define YMM4 YMM0
#					define YMM5 YMM0
#					define YMM6 YMM0
#					define YMM7 YMM0
#					define YMM8 YMM0
#					define YMM9 YMM0
#					define YMM10 YMM0
#					define YMM11 YMM0
#					define YMM12 YMM0
#					define YMM13 YMM0
#					define YMM14 YMM0
#					define YMM15 YMM0
#				endif /* __SYSTEM_256_BIT__ */
#				ifdef __SYSTEM_512_BIT__
#					define ZMM0 %zmm0
#					define ZMM1 %zmm1
#					define ZMM2 %zmm2
#					define ZMM3 %zmm3
#					define ZMM4 %zmm4
#					define ZMM5 %zmm5
#					define ZMM6 %zmm6
#					define ZMM7 %zmm7
#					define ZMM8 %zmm8
#					define ZMM9 %zmm9
#					define ZMM10 %zmm10
#					define ZMM11 %zmm11
#					define ZMM12 %zmm12
#					define ZMM13 %zmm13
#					define ZMM14 %zmm14
#					define ZMM15 %zmm15
#					define ZMM16 %zmm16
#					define ZMM17 %zmm17
#					define ZMM18 %zmm18
#					define ZMM19 %zmm19
#					define ZMM20 %zmm20
#					define ZMM21 %zmm21
#					define ZMM22 %zmm22
#					define ZMM23 %zmm23
#					define ZMM24 %zmm24
#					define ZMM25 %zmm25
#					define ZMM26 %zmm26
#					define ZMM27 %zmm27
#					define ZMM28 %zmm28
#					define ZMM29 %zmm29
#					define ZMM30 %zmm30
#					define ZMM31 %zmm31
#				else
#					define ZMM0 ERROR__AVX512_REGISTERS_DOES_NOT_SUPPORTED
#					define ZMM1 ZMM0
#					define ZMM2 ZMM0
#					define ZMM3 ZMM0
#					define ZMM4 ZMM0
#					define ZMM5 ZMM0
#					define ZMM6 ZMM0
#					define ZMM7 ZMM0
#					define ZMM8 ZMM0
#					define ZMM9 ZMM0
#					define ZMM10 ZMM0
#					define ZMM11 ZMM0
#					define ZMM12 ZMM0
#					define ZMM13 ZMM0
#					define ZMM14 ZMM0
#					define ZMM15 ZMM0
#					define ZMM16 ZMM0
#					define ZMM17 ZMM0
#					define ZMM18 ZMM0
#					define ZMM19 ZMM0
#					define ZMM20 ZMM0
#					define ZMM21 ZMM0
#					define ZMM22 ZMM0
#					define ZMM23 ZMM0
#					define ZMM24 ZMM0
#					define ZMM25 ZMM0
#					define ZMM26 ZMM0
#					define ZMM27 ZMM0
#					define ZMM28 ZMM0
#					define ZMM29 ZMM0
#					define ZMM30 ZMM0
#					define ZMM31 ZMM0
#				endif /* __SYSTEM_512_BIT__ */
#				ifdef __SYSTEM_64_BIT__
#					define MOV8(A, B) __START__ "movb " #B ", " #A __END__
#					define MOV16(A, B) __START__ "movw " #B ", " #A __END__
#					define MOV32(A, B) __START__ "movl " #B ", " #A __END__
#					define MOV64(A, B) __START__ "movq " #B ", " #A __END__
#					define ADD8(A, B) __START__ "addb " #B ", " #A __END__
#					define ADD16(A, B) __START__ "addw " #B ", " #A __END__
#					define ADD32(A, B) __START__ "addl " #B ", " #A __END__
#					define ADD64(A, B) __START__ "addq " #B ", " #A __END__
#					define IP %ip
#					define EIP %eip
#					define RIP %rip
#					define R8 %r8
#					define R8D %r8d
#					define R8W %r8w
#					define R8B %r8b
#					define R9 %r9
#					define R9D %r9d
#					define R9W %r9w
#					define R9B %r9b
#					define R10 %r10
#					define R10D %r10d
#					define R10W %r10w
#					define R10B %r10b
#					define R11 %r11
#					define R11D %r11d
#					define R11W %r11w
#					define R11B %r11b
#					define R12 %r12
#					define R12D %r12d
#					define R12W %r12w
#					define R12B %r12b
#					define R13 %r13
#					define R13D %r13d
#					define R13W %r13w
#					define R13B %r13b
#					define R14 %r14
#					define R14D %r14d
#					define R14W %r14w
#					define R14B %r14b
#					define R15 %r15
#					define R15D %r15d
#					define R15W %r15w
#					define R15B %r15b
#					define CR0 %cr0
#					define CR2 %cr2
#					define CR3 %cr3
#					define CR4 %cr4
#					define CR8 %cr8
#					define DR0 %dr0
#					define DR1 %dr1
#					define DR2 %dr2
#					define DR3 %dr3
#					define DR4 ERROR__DR4_DEPRECATED_AFTER_486
#					define DR5 ERROR__DR5_DEPRECATED_AFTER_486
#					define DR6 %dr6
#					define DR7 %dr7
#					define GDTR %gdtr
#					define IDTR %idtr
#					define LDTR %ldtr
#					define TR %tr
#					define AH %ah
#					define SI %si
#					define ESI %esi
#					define RSI %rsi
#					define BH %bh
#					define DI %di
#					define EDI %edi
#					define RDI %rdi
#					define CH %ch
#					define BP %bp
#					define EBP %ebp
#					define RBP %rbp
#					define DH %dh
#					define SP %sp
#					define ESP %esp
#					define RSP %rsp
#					define AL %al
#					define AX %ax
#					define EAX %eax
#					define RAX %rax
#					define BL %bl
#					define BX %bx
#					define EBX %ebx
#					define RBX %rbx
#					define CL %cl
#					define CX %cx
#					define ECX %ecx
#					define RCX %rcx
#					define DL %dl
#					define DX %dx
#					define EDX %edx
#					define RDX %rdx
#				endif /* __SYSTEM_64_BIT__ */
#				ifdef __SYSTEM_32_BIT__
#					define MOV8(A, B) __START__ "movb " #B ", " #A __END__
#					define MOV16(A, B) __START__ "movw " #B ", " #A __END__
#					define MOV32(A, B) __START__ "movl " #B ", " #A __END__
#					define MOV64(A, B) MOV32(A, B)
#					define ADD8(A, B) __START__ "addb " #B ", " #A __END__
#					define ADD16(A, B) __START__ "addw " #B ", " #A __END__
#					define ADD32(A, B) __START__ "addl " #B ", " #A __END__
#					define ADD64(A, B) ADD32(A, B)
#					define IP %ip
#					define EIP %eip
#					define RIP EIP
#					define R8 ERROR__64_BIT_REGISTERS_DOES_NOT_SUPPORTED
#					define R8D R8
#					define R8W R8
#					define R8B R8
#					define R9 R8
#					define R9D R8
#					define R9W R8
#					define R9B R8
#					define R10 R8
#					define R10D R8
#					define R10W R8
#					define R10B R8
#					define R11 R8
#					define R11D R8
#					define R11W R8
#					define R11B R8
#					define R12 R8
#					define R12D R8
#					define R12W R8
#					define R12B R8
#					define R13 R8
#					define R13D R8
#					define R13W R8
#					define R13B R8
#					define R14 R8
#					define R14D R8
#					define R14W R8
#					define R14B R8
#					define R15 R8
#					define R15D R8
#					define R15W R8
#					define R15B R8
#					define CR0 %cr0
#					define CR2 %cr2
#					define CR3 %cr3
#					define CR4 %cr4
#					define CR8 ERROR__CR8_ONLY_EXIST_AT_64_BIT
#					define DR0 %dr0
#					define DR1 %dr1

#					ifdef i386
#						define LOCALMACRO_DR4_DR5_SUPPORTED
#					endif /* i386 */
#					ifndef LOCALMACRO_DR4_DR5_SUPPORTED
#						ifdef __i386
#							define LOCALMACRO_DR4_DR5_SUPPORTED
#						endif /* __i386 */
#					endif /* !LOCALMACRO_DR4_DR5_SUPPORTED */
#					ifndef LOCALMACRO_DR4_DR5_SUPPORTED
#						ifdef __i386__
#							define LOCALMACRO_DR4_DR5_SUPPORTED
#						endif /* __i386__ */
#					endif /* !LOCALMACRO_DR4_DR5_SUPPORTED */
#					ifndef LOCALMACRO_DR4_DR5_SUPPORTED
#						ifdef __i486__
#							define LOCALMACRO_DR4_DR5_SUPPORTED
#						endif /* __i486__ */
#					endif /* !LOCALMACRO_DR4_DR5_SUPPORTED */
#					ifndef LOCALMACRO_DR4_DR5_SUPPORTED
#						ifdef __386
#							define LOCALMACRO_DR4_DR5_SUPPORTED
#						endif /* __386 */
#					endif /* !LOCALMACRO_DR4_DR5_SUPPORTED */
#					ifndef LOCALMACRO_DR4_DR5_SUPPORTED
#						ifdef __386__
#							define LOCALMACRO_DR4_DR5_SUPPORTED
#						endif /* __386__ */
#					endif /* !LOCALMACRO_DR4_DR5_SUPPORTED */
#					ifndef LOCALMACRO_DR4_DR5_SUPPORTED
#						ifdef _M_I386
#							define LOCALMACRO_DR4_DR5_SUPPORTED
#						endif /* _M_I386 */
#					endif /* !LOCALMACRO_DR4_DR5_SUPPORTED */

#					define DR2 %dr2
#					define DR3 %dr3

#					ifdef LOCALMACRO_DR4_DR5_SUPPORTED
#						undef LOCALMACRO_DR4_DR5_SUPPORTED
#						define DR4 %dr4
#						define DR5 %dr5
#					else
#						define DR4 ERROR__DR4_DEPRECATED_AFTER_486
#						define DR5 ERROR__DR5_DEPRECATED_AFTER_486
#					endif /* LOCALMACRO_DR4_DR5_SUPPORTED */

#					define DR6 %dr6
#					define DR7 %dr7
#					define GDTR %gdtr
#					define IDTR %idtr
#					define LDTR %ldtr
#					define TR %tr
#					define AH %ah
#					define SI %si
#					define ESI %esi
#					define RSI ESI
#					define BH %bh
#					define DI %di
#					define EDI %edi
#					define RDI EDI
#					define CH %ch
#					define BP %bp
#					define EBP %ebp
#					define RBP EBP
#					define DH %dh
#					define SP %sp
#					define ESP %esp
#					define RSP ESP
#					define AL %al
#					define AX %ax
#					define EAX %eax
#					define RAX EAX
#					define BL %bl
#					define BX %bx
#					define EBX %ebx
#					define RBX EBX
#					define CL %cl
#					define CX %cx
#					define ECX %ecx
#					define RCX ECX
#					define DL %dl
#					define DX %dx
#					define EDX %edx
#					define RDX EDX
#				endif /* __SYSTEM_32_BIT__ */
#				ifdef __SYSTEM_16_BIT__
#					define MOV8(A, B) __START__ "movb " #B ", " #A __END__
#					define MOV16(A, B) __START__ "movw " #B ", " #A __END__
#					define MOV32(A, B) MOV16(A, B)
#					define MOV64(A, B) MOV16(A, B)
#					define ADD8(A, B) __START__ "addb " #B ", " #A __END__
#					define ADD16(A, B) __START__ "addw " #B ", " #A __END__
#					define ADD32(A, B) ADD16(A, B)
#					define ADD64(A, B) ADD16(A, B)
#					define IP %ip
#					define EIP IP
#					define RIP IP
#					define CR0 ERROR__CR_REGISTERS_ONLY_EXIST_AT_32_BIT
#					define CR2 CR0
#					define CR3 CR0
#					define CR4 CR0
#					define CR8 ERROR__CR8_ONLY_EXIST_AT_64_BIT
#					define DR0 ERROR__DR_REGISTERS_ONLY_EXIST_AT_32_BIT
#					define DR1 DR0
#					define DR2 DR0
#					define DR3 DR0
#					define DR4 ERROR__DR4_DEPRECATED_AFTER_486
#					define DR5 ERROR__DR5_DEPRECATED_AFTER_486
#					define DR6 DR0
#					define DR7 DR0
#					define GDTR %gdtr
#					define IDTR %idtr
#					define LDTR %ldtr
#					define TR %tr
#					define AH %ah
#					define SI %si
#					define ESI SI
#					define RSI SI
#					define BH %bh
#					define DI %di
#					define EDI DI
#					define RDI DI
#					define CH %ch
#					define BP %bp
#					define EBP BP
#					define RBP BP
#					define DH %dh
#					define SP %sp
#					define ESP SP
#					define RSP SP
#					define AL %al
#					define AX %ax
#					define EAX AX
#					define RAX AX
#					define BL %bl
#					define BX %bx
#					define EBX BX
#					define RBX BX
#					define CL %cl
#					define CX %cx
#					define ECX CX
#					define RCX CX
#					define DL %dl
#					define DX %dx
#					define EDX DX
#					define RDX DX
#				endif /* __SYSTEM_16_BIT__ */
#				define RET ret\n
#			endif /* __CPU_INTEL__ */
#		endif /* LOCALMACRO_ATNT_SYNTAX_STRING */
#		ifdef LOCALMACRO_INTEL_SYNTAX_PURE
#			undef LOCALMACRO_INTEL_SYNTAX_PURE
#			define MEM(ARG) ptr [ARG]
#			define MEM_INDEX(ARG, INDEX) ptr [ARG + INDEX]
#			ifdef __CPU_INTEL__
#				define CS cs
#				define DS ds
#				define SS ss
#				define ES es
#				define FS fs
#				define GS gs
#				ifdef __MMX__
#					define MM0 %mm0
#					define MM1 %mm1
#					define MM2 %mm2
#					define MM3 %mm3
#					define MM4 %mm4
#					define MM5 %mm5
#					define MM6 %mm6
#					define MM7 %mm7
#				else
#					define MM0 ERROR__MMX_DOES_NOT_SUPPORTED
#					define MM1 MM0
#					define MM2 MM0
#					define MM3 MM0
#					define MM4 MM0
#					define MM5 MM0
#					define MM6 MM0
#					define MM7 MM0
#				endif /* __MMX__ */
#				ifdef __SYSTEM_128_BIT__
#					define XMM0 xmm0
#					define XMM1 xmm1
#					define XMM2 xmm2
#					define XMM3 xmm3
#					define XMM4 xmm4
#					define XMM5 xmm5
#					define XMM6 xmm6
#					define XMM7 xmm7
#					define XMM8 xmm8
#					define XMM9 xmm9
#					define XMM10 xmm10
#					define XMM11 xmm11
#					define XMM12 xmm12
#					define XMM13 xmm13
#					define XMM14 xmm14
#					define XMM15 xmm15
#				else
#					define XMM0 ERROR__SSE128_REGISTERS_DOES_NOT_SUPPORTED
#					define XMM1 XMM0
#					define XMM2 XMM0
#					define XMM3 XMM0
#					define XMM4 XMM0
#					define XMM5 XMM0
#					define XMM6 XMM0
#					define XMM7 XMM0
#					define XMM8 XMM0
#					define XMM9 XMM0
#					define XMM10 XMM0
#					define XMM11 XMM0
#					define XMM12 XMM0
#					define XMM13 XMM0
#					define XMM14 XMM0
#					define XMM15 XMM0
#				endif /* __SYSTEM_128_BIT__ */
#				ifdef __SYSTEM_256_BIT__
#					define YMM0 ymm0
#					define YMM1 ymm1
#					define YMM2 ymm2
#					define YMM3 ymm3
#					define YMM4 ymm4
#					define YMM5 ymm5
#					define YMM6 ymm6
#					define YMM7 ymm7
#					define YMM8 ymm8
#					define YMM9 ymm9
#					define YMM10 ymm10
#					define YMM11 ymm11
#					define YMM12 ymm12
#					define YMM13 ymm13
#					define YMM14 ymm14
#					define YMM15 ymm15
#				else
#					define YMM0 ERROR__AVX256_REGISTERS_DOES_NOT_SUPPORTED
#					define YMM1 YMM0
#					define YMM2 YMM0
#					define YMM3 YMM0
#					define YMM4 YMM0
#					define YMM5 YMM0
#					define YMM6 YMM0
#					define YMM7 YMM0
#					define YMM8 YMM0
#					define YMM9 YMM0
#					define YMM10 YMM0
#					define YMM11 YMM0
#					define YMM12 YMM0
#					define YMM13 YMM0
#					define YMM14 YMM0
#					define YMM15 YMM0
#				endif /* __SYSTEM_256_BIT__ */
#				ifdef __SYSTEM_512_BIT__
#					define ZMM0 zmm0
#					define ZMM1 zmm1
#					define ZMM2 zmm2
#					define ZMM3 zmm3
#					define ZMM4 zmm4
#					define ZMM5 zmm5
#					define ZMM6 zmm6
#					define ZMM7 zmm7
#					define ZMM8 zmm8
#					define ZMM9 zmm9
#					define ZMM10 zmm10
#					define ZMM11 zmm11
#					define ZMM12 zmm12
#					define ZMM13 zmm13
#					define ZMM14 zmm14
#					define ZMM15 zmm15
#					define ZMM16 zmm16
#					define ZMM17 zmm17
#					define ZMM18 zmm18
#					define ZMM19 zmm19
#					define ZMM20 zmm20
#					define ZMM21 zmm21
#					define ZMM22 zmm22
#					define ZMM23 zmm23
#					define ZMM24 zmm24
#					define ZMM25 zmm25
#					define ZMM26 zmm26
#					define ZMM27 zmm27
#					define ZMM28 zmm28
#					define ZMM29 zmm29
#					define ZMM30 zmm30
#					define ZMM31 zmm31
#				else
#					define ZMM0 ERROR__AVX512_REGISTERS_DOES_NOT_SUPPORTED
#					define ZMM1 ZMM0
#					define ZMM2 ZMM0
#					define ZMM3 ZMM0
#					define ZMM4 ZMM0
#					define ZMM5 ZMM0
#					define ZMM6 ZMM0
#					define ZMM7 ZMM0
#					define ZMM8 ZMM0
#					define ZMM9 ZMM0
#					define ZMM10 ZMM0
#					define ZMM11 ZMM0
#					define ZMM12 ZMM0
#					define ZMM13 ZMM0
#					define ZMM14 ZMM0
#					define ZMM15 ZMM0
#					define ZMM16 ZMM0
#					define ZMM17 ZMM0
#					define ZMM18 ZMM0
#					define ZMM19 ZMM0
#					define ZMM20 ZMM0
#					define ZMM21 ZMM0
#					define ZMM22 ZMM0
#					define ZMM23 ZMM0
#					define ZMM24 ZMM0
#					define ZMM25 ZMM0
#					define ZMM26 ZMM0
#					define ZMM27 ZMM0
#					define ZMM28 ZMM0
#					define ZMM29 ZMM0
#					define ZMM30 ZMM0
#					define ZMM31 ZMM0
#				endif /* __SYSTEM_512_BIT__ */
#				ifdef __SYSTEM_64_BIT__
#					define MOV8(A, B) __START__ mov byte A, B __END__
#					define MOV16(A, B) __START__ mov word A, B __END__
#					define MOV32(A, B) __START__ mov dword A, B __END__
#					define MOV64(A, B) __START__ mov qword A, B __END__
#					define ADD8(A, B) __START__ add byte A, B __END__
#					define ADD16(A, B) __START__ add word A, B __END__
#					define ADD32(A, B) __START__ add dword A, B __END__
#					define ADD64(A, B) __START__ add qword A, B __END__
#					define IP ip
#					define EIP eip
#					define RIP rip
#					define R8 r8
#					define R8D r8d
#					define R8W r8w
#					define R8B r8b
#					define R9 r9
#					define R9D r9d
#					define R9W r9w
#					define R9B r9b
#					define R10 r10
#					define R10D r10d
#					define R10W r10w
#					define R10B r10b
#					define R11 r11
#					define R11D r11d
#					define R11W r11w
#					define R11B r11b
#					define R12 r12
#					define R12D r12d
#					define R12W r12w
#					define R12B r12b
#					define R13 r13
#					define R13D r13d
#					define R13W r13w
#					define R13B r13b
#					define R14 r14
#					define R14D r14d
#					define R14W r14w
#					define R14B r14b
#					define R15 r15
#					define R15D r15d
#					define R15W r15w
#					define R15B r15b
#					define CR0 cr0
#					define CR2 cr2
#					define CR3 cr3
#					define CR4 cr4
#					define CR8 cr8
#					define DR0 dr0
#					define DR1 dr1
#					define DR2 dr2
#					define DR3 dr3
#					define DR4 ERROR__DR4_DEPRECATED_AFTER_486
#					define DR5 ERROR__DR5_DEPRECATED_AFTER_486
#					define DR6 dr6
#					define DR7 dr7
#					define GDTR gdtr
#					define IDTR idtr
#					define LDTR ldtr
#					define TR tr
#					define AH ah
#					define SI si
#					define ESI esi
#					define RSI rsi
#					define BH bh
#					define DI di
#					define EDI edi
#					define RDI rdi
#					define CH ch
#					define BP bp
#					define EBP ebp
#					define RBP rbp
#					define DH dh
#					define SP sp
#					define ESP esp
#					define RSP rsp
#					define AL al
#					define AX ax
#					define EAX eax
#					define RAX rax
#					define BL bl
#					define BX bx
#					define EBX ebx
#					define RBX rbx
#					define CL cl
#					define CX cx
#					define ECX ecx
#					define RCX rcx
#					define DL dl
#					define DX dx
#					define EDX edx
#					define RDX rdx
#				endif /* __SYSTEM_64_BIT__ */
#				ifdef __SYSTEM_32_BIT__
#					define MOV8(A, B) __START__ mov byte A, B __END__
#					define MOV16(A, B) __START__ mov word A, B __END__
#					define MOV32(A, B) __START__ mov dword A, B __END__
#					define MOV64(A, B) MOV32(A, B)
#					define ADD8(A, B) __START__ add byte A, B __END__
#					define ADD16(A, B) __START__ add word A, B __END__
#					define ADD32(A, B) __START__ add dword A, B __END__
#					define ADD64(A, B) ADD32(A, B)
#					define IP ip
#					define EIP eip
#					define RIP EIP
#					define R8 ERROR__64_BIT_REGISTERS_DOES_NOT_SUPPORTED
#					define R8D R8
#					define R8W R8
#					define R8B R8
#					define R9 R8
#					define R9D R8
#					define R9W R8
#					define R9B R8
#					define R10 R8
#					define R10D R8
#					define R10W R8
#					define R10B R8
#					define R11 R8
#					define R11D R8
#					define R11W R8
#					define R11B R8
#					define R12 R8
#					define R12D R8
#					define R12W R8
#					define R12B R8
#					define R13 R8
#					define R13D R8
#					define R13W R8
#					define R13B R8
#					define R14 R8
#					define R14D R8
#					define R14W R8
#					define R14B R8
#					define R15 R8
#					define R15D R8
#					define R15W R8
#					define R15B R8
#					define CR0 cr0
#					define CR2 cr2
#					define CR3 cr3
#					define CR4 cr4
#					define CR8 ERROR__CR8_ONLY_EXIST_AT_64_BIT
#					define DR0 dr0
#					define DR1 dr1

#					ifdef i386
#						define LOCALMACRO_DR4_DR5_SUPPORTED
#					endif /* i386 */
#					ifndef LOCALMACRO_DR4_DR5_SUPPORTED
#						ifdef __i386
#							define LOCALMACRO_DR4_DR5_SUPPORTED
#						endif /* __i386 */
#					endif /* !LOCALMACRO_DR4_DR5_SUPPORTED */
#					ifndef LOCALMACRO_DR4_DR5_SUPPORTED
#						ifdef __i386__
#							define LOCALMACRO_DR4_DR5_SUPPORTED
#						endif /* __i386__ */
#					endif /* !LOCALMACRO_DR4_DR5_SUPPORTED */
#					ifndef LOCALMACRO_DR4_DR5_SUPPORTED
#						ifdef __i486__
#							define LOCALMACRO_DR4_DR5_SUPPORTED
#						endif /* __i486__ */
#					endif /* !LOCALMACRO_DR4_DR5_SUPPORTED */
#					ifndef LOCALMACRO_DR4_DR5_SUPPORTED
#						ifdef __386
#							define LOCALMACRO_DR4_DR5_SUPPORTED
#						endif /* __386 */
#					endif /* !LOCALMACRO_DR4_DR5_SUPPORTED */
#					ifndef LOCALMACRO_DR4_DR5_SUPPORTED
#						ifdef __386__
#							define LOCALMACRO_DR4_DR5_SUPPORTED
#						endif /* __386__ */
#					endif /* !LOCALMACRO_DR4_DR5_SUPPORTED */
#					ifndef LOCALMACRO_DR4_DR5_SUPPORTED
#						ifdef _M_I386
#							define LOCALMACRO_DR4_DR5_SUPPORTED
#						endif /* _M_I386 */
#					endif /* !LOCALMACRO_DR4_DR5_SUPPORTED */

#					define DR2 dr2
#					define DR3 dr3

#					ifdef LOCALMACRO_DR4_DR5_SUPPORTED
#						undef LOCALMACRO_DR4_DR5_SUPPORTED
#						define DR4 dr4
#						define DR5 dr5
#					else
#						define DR4 ERROR__DR4_DEPRECATED_AFTER_486
#						define DR5 ERROR__DR5_DEPRECATED_AFTER_486
#					endif /* LOCALMACRO_DR4_DR5_SUPPORTED */

#					define DR6 dr6
#					define DR7 dr7
#					define GDTR gdtr
#					define IDTR idtr
#					define LDTR ldtr
#					define TR tr
#					define AH ah
#					define SI si
#					define ESI esi
#					define RSI ESI
#					define BH bh
#					define DI di
#					define EDI edi
#					define RDI EDI
#					define CH ch
#					define BP bp
#					define EBP ebp
#					define RBP EBP
#					define DH dh
#					define SP sp
#					define ESP esp
#					define RSP ESP
#					define AL al
#					define AX ax
#					define EAX eax
#					define RAX EAX
#					define BL bl
#					define BX bx
#					define EBX ebx
#					define RBX EBX
#					define CL cl
#					define CX cx
#					define ECX ecx
#					define RCX ECX
#					define DL dl
#					define DX dx
#					define EDX edx
#					define RDX EDX
#				endif /* __SYSTEM_32_BIT__ */
#				ifdef __SYSTEM_16_BIT__
#					define MOV8(A, B) __START__ mov byte A, B __END__
#					define MOV16(A, B) __START__ mov word A, B __END__
#					define MOV32(A, B) MOV16(A, B)
#					define MOV64(A, B) MOV16(A, B)
#					define ADD8(A, B) __START__ add byte A, B __END__
#					define ADD16(A, B) __START__ add word A, B __END__
#					define ADD32(A, B) ADD16(A, B)
#					define ADD64(A, B) ADD16(A, B)
#					define IP ip
#					define EIP IP
#					define RIP IP
#					define CR0 ERROR__CR_REGISTERS_ONLY_EXIST_AT_32_BIT
#					define CR2 CR0
#					define CR3 CR0
#					define CR4 CR0
#					define CR8 ERROR__CR8_ONLY_EXIST_AT_64_BIT
#					define DR0 ERROR__DR_REGISTERS_ONLY_EXIST_AT_32_BIT
#					define DR1 DR0
#					define DR2 DR0
#					define DR3 DR0
#					define DR4 ERROR__DR4_DEPRECATED_AFTER_486
#					define DR5 ERROR__DR5_DEPRECATED_AFTER_486
#					define DR6 DR0
#					define DR7 DR0
#					define GDTR gdtr
#					define IDTR idtr
#					define LDTR ldtr
#					define TR tr
#					define AH ah
#					define SI si
#					define ESI SI
#					define RSI SI
#					define BH bh
#					define DI di
#					define EDI DI
#					define RDI DI
#					define CH ch
#					define BP bp
#					define EBP BP
#					define RBP BP
#					define DH dh
#					define SP sp
#					define ESP SP
#					define RSP SP
#					define AL al
#					define AX ax
#					define EAX AX
#					define RAX AX
#					define BL bl
#					define BX bx
#					define EBX BX
#					define RBX BX
#					define CL cl
#					define CX cx
#					define ECX CX
#					define RCX CX
#					define DL dl
#					define DX dx
#					define EDX DX
#					define RDX DX
#				endif /* __SYSTEM_16_BIT__ */
#				define RET ret
#			endif /* __CPU_INTEL__ */
#		endif /* LOCALMACRO_INTEL_SYNTAX_PURE */
#	else
#		error "INLINE ASM DOES NOT SUPPORTED IN THIS COMPILER"
#	endif /* IS__INLINE_ASM__SUPPORTED */
#endif /* !ASM_PUSH_H */