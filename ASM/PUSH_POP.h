/******************************************************************************\
# H - PUSH_POP                                   #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/02/27 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/08/27 : #    ::::!!!1!!1!!!1!!!::     #
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
|*............................................................................*|
|* NAME :    TYPE    :                      DESCRIPTION                       *|
|*......:............:........................................................*|
|* PUSH : #define () : MOVES A VALUE TO STACK MEMORY (NATURAL SIZE).         *|
|* push :            :                                                        *|
|*......:............:........................................................*|
|* PUSHW: #define () : MOVES A 16-BIT VALUE TO STACK MEMORY.                  *|
|* pushw:            :                                                        *|
|*......:............:........................................................*|
|* PUSHD: #define () : MOVES A 32-BIT VALUE TO STACK MEMORY.                  *|
|* pushd:            :                                                        *|
|*......:............:........................................................*|
|* PUSHQ: #define () : MOVES A 64-BIT VALUE TO STACK MEMORY.                  *|
|* pushq:            :                                                        *|
|*......:............:........................................................*|
|* POP  : #define () : GETS A VALUE FROM STACK MEMORY (NATURAL SIZE).        *|
|* pop  :            :                                                        *|
|*......:............:........................................................*|
|* POPW : #define () : GETS A 16-BIT VALUE FROM STACK MEMORY.                 *|
|* popw :            :                                                        *|
|*......:............:........................................................*|
|* POPD : #define () : GETS A 32-BIT VALUE FROM STACK MEMORY.                 *|
|* popd :            :                                                        *|
|*......:............:........................................................*|
|* POPQ : #define () : GETS A 64-BIT VALUE FROM STACK MEMORY.                 *|
|* popq :            :                                                        *|
|*......:............:........................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|* WITH THESE FUNCTIONS, YOU'RE ABLE TO MOVE AND GET VALUES FROM THE CPU      *|
|* STACK WITH DIFFERENT DATA SIZES AND ARCHITECTURES.                        *|
|*                                                                            *|
|* SUPPORTED ARCHITECTURES:                                                   *|
|* - INTEL X86/X86-64 (PUSH/POP INSTRUCTIONS)                                 *|
|* - ARM/AARCH64 (STR/LDR WITH STACK POINTER)                                 *|
|* - AMD X86-64 (PUSH/POP INSTRUCTIONS)                                       *|
|* - POWERPC (STW/LWZ WITH STACK REGISTER)                                    *|
|* - RISC-V (SW/LW WITH STACK POINTER)                                        *|
|*                                                                            *|
|* SUPPORTED COMPILERS:                                                       *|
|* - GCC/CLANG (GNU EXTENDED INLINE ASSEMBLY)                                 *|
|* - MICROSOFT VISUAL C++ (MSVC BLOCK ASSEMBLY)                               *|
|* - BORLAND/TURBO C (SIMPLE INLINE ASSEMBLY)                                 *|
|* - INTEL C COMPILER (INTEL MS-STYLE ASSEMBLY)                               *|
|* - WATCOM C (PRAGMA/BLOCK ASSEMBLY)                                         *|
|* - ARM COMPILER (ARM CONSTRAINTS ASSEMBLY)                                  *|
|* - KEIL EMBEDDED (PRAGMA BLOCKS ASSEMBLY)                                   *|
|* - AZTEC C (BLOCK ASSEMBLY)                                                 *|
|*                                                                            *|
|* DATA SIZES:                                                                *|
|* - PUSH/POP: NATURAL SIZE (32-BIT ON 32-BIT SYSTEMS, 64-BIT ON 64-BIT)     *|
|* - PUSHW/POPW: 16-BIT VALUES                                                 *|
|* - PUSHD/POPD: 32-BIT VALUES                                                 *|
|* - PUSHQ/POPQ: 64-BIT VALUES (ON 64-BIT SYSTEMS, FALLS BACK TO 32-BIT)     *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* LET'S WRITE SOME EXAMPLES FOR DIFFERENT DATA SIZES:                        *|
|*                                                                            *|
|* O - EXAMPLE 1: SIMPLE SWAP (NATURAL SIZE)                                  *|
|* :                                                                          *|
|* ;.., register int a = 42;                                                  *|
|*    : register int b = 11;                                                  *|
|*    :                                                                       *|
|*    : PUSH(a); // > ADDED 42 TO CPU STACK                                   *|
|*    : a = b;   // |                                                         *|
|*    : POP(b);  // < REMOVED 42 FROM CPU STACK                               *|
|*    ;..,                                                                    *|
|*       : b IS NOW 42                                                        *|
|*       : a IS NOW 11                                                        *|
|*                                                                            *|
|* O - EXAMPLE 2: 16-BIT VALUES                                               *|
|* :                                                                          *|
|* ;.., short value16 = 0x1234;                                               *|
|*    :                                                                       *|
|*    : PUSHW(value16); // > PUSH 16-BIT VALUE                                *|
|*    : value16 = 0;                                                          *|
|*    : POPW(value16);  // < POP 16-BIT VALUE                                 *|
|*    ;..,                                                                    *|
|*       : value16 IS NOW 0x1234                                              *|
|*                                                                            *|
|* O - EXAMPLE 3: 64-BIT VALUES (ON 64-BIT SYSTEMS)                           *|
|* :                                                                          *|
|* ;.., long long bigValue = 0x123456789ABCDEF0LL;                            *|
|*    :                                                                       *|
|*    : PUSHQ(bigValue); // > PUSH 64-BIT VALUE                               *|
|*    : bigValue = 0;                                                         *|
|*    : POPQ(bigValue);  // < POP 64-BIT VALUE                                *|
|*    ;..,                                                                    *|
|*       : bigValue IS NOW 0x123456789ABCDEF0LL                               *|
|*                                                                            *|
\******************************************************************************/

#ifndef PUSH_POP_H
#	define PUSH_POP_H 202508 /* VERSION */

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

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../ENVIRONMENTS/CPU.h" /*
#			CPU ARCHITECTURE DETECTION
#		*/
#	include "../CHECK_FEATURE/INLINE_ASM.h" /*
#			INLINE ASSEMBLY FEATURE DETECTION
#		*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] C++ (PUSH) [v] *************************** */
#	ifdef __cplusplus /* C++ */
extern "C" {
#	endif /* __cplusplus */
/* *************************** [^] C++ (PUSH) [^] *************************** */

/* ********************* [v] PUSH/POP IMPLEMENTATION [v] ******************** */
#	ifdef IS__INLINE_ASM__SUPPORTED

/* ************************ [v] INTEL X86/X64 CPU [v] *********************** */
#		ifdef __CPU_INTEL__

/* ************************** [v] GNU ASM STYLE [v] ************************* */
#			ifdef INLINE_ASM_TYPE__GNU
#				define PUSH(PUSH_VAR) \
					__asm__ __volatile__("push %0" : : "rm"((long)(PUSH_VAR)))

#				define PUSHW(PUSH_VAR) \
					__asm__ __volatile__("pushw %0" : : "rm"((short)(PUSH_VAR)))

#				define PUSHD(PUSH_VAR) \
					__asm__ __volatile__("pushl %0" : : "rm"((int)(PUSH_VAR)))

#				ifdef __x86_64__
#					define PUSHQ(PUSH_VAR) \
						__asm__ __volatile__("pushq %0" : : "rm"((long long)(PUSH_VAR)))
#				else
#					define PUSHQ(PUSH_VAR) PUSHD(PUSH_VAR)
#				endif /* __x86_64__ */

#				define POP(POP_VAR) \
					__asm__ __volatile__("pop %0" : "=rm"(POP_VAR))

#				define POPW(POP_VAR) \
					__asm__ __volatile__("popw %0" : "=rm"(POP_VAR))

#				define POPD(POP_VAR) \
					__asm__ __volatile__("popl %0" : "=rm"(POP_VAR))

#				ifdef __x86_64__
#					define POPQ(POP_VAR) \
						__asm__ __volatile__("popq %0" : "=rm"(POP_VAR))
#				else
#					define POPQ(POP_VAR) POPD(POP_VAR)
#				endif /* __x86_64__ */
#			endif /* INLINE_ASM_TYPE__GNU */
/* ************************** [^] GNU ASM STYLE [^] ************************* */

/* ************************* [v] MSVC ASM STYLE [v] ************************* */
#			ifdef INLINE_ASM_TYPE__MSVC
#				define PUSH(PUSH_VAR) \
					__asm { push PUSH_VAR }

#				define PUSHW(PUSH_VAR) \
					__asm { push PUSH_VAR }

#				define PUSHD(PUSH_VAR) \
					__asm { push PUSH_VAR }

#				define PUSHQ(PUSH_VAR) \
					__asm { push PUSH_VAR }

#				define POP(POP_VAR) \
					__asm { pop POP_VAR }

#				define POPW(POP_VAR) \
					__asm { pop POP_VAR }

#				define POPD(POP_VAR) \
					__asm { pop POP_VAR }

#				define POPQ(POP_VAR) \
					__asm { pop POP_VAR }
#			endif /* INLINE_ASM_TYPE__MSVC */
/* ************************* [^] MSVC ASM STYLE [^] ************************* */

/* ************************ [v] BORLAND ASM STYLE [v] ********************** */
#			ifdef INLINE_ASM_TYPE__BORLAND
#				define PUSH(PUSH_VAR) \
					asm push PUSH_VAR

#				define PUSHW(PUSH_VAR) \
					asm push PUSH_VAR

#				define PUSHD(PUSH_VAR) \
					asm push PUSH_VAR

#				define PUSHQ(PUSH_VAR) \
					asm push PUSH_VAR

#				define POP(POP_VAR) \
					asm pop POP_VAR

#				define POPW(POP_VAR) \
					asm pop POP_VAR

#				define POPD(POP_VAR) \
					asm pop POP_VAR

#				define POPQ(POP_VAR) \
					asm pop POP_VAR
#			endif /* INLINE_ASM_TYPE__BORLAND */
/* ************************ [^] BORLAND ASM STYLE [^] ********************** */

/* ********************** [v] INTEL MS ASM STYLE [v] ********************* */
#			ifdef INLINE_ASM_TYPE__INTEL_MS
#				define PUSH(PUSH_VAR) \
					__asm push PUSH_VAR

#				define PUSHW(PUSH_VAR) \
					__asm push PUSH_VAR

#				define PUSHD(PUSH_VAR) \
					__asm push PUSH_VAR

#				define PUSHQ(PUSH_VAR) \
					__asm push PUSH_VAR

#				define POP(POP_VAR) \
					__asm pop POP_VAR

#				define POPW(POP_VAR) \
					__asm pop POP_VAR

#				define POPD(POP_VAR) \
					__asm pop POP_VAR

#				define POPQ(POP_VAR) \
					__asm pop POP_VAR
#			endif /* INLINE_ASM_TYPE__INTEL_MS */
/* ********************** [^] INTEL MS ASM STYLE [^] ********************* */

/* ************************ [v] WATCOM ASM STYLE [v] *********************** */
#			ifdef INLINE_ASM_TYPE__WATCOM
#				define PUSH(PUSH_VAR) \
					_asm { push PUSH_VAR }

#				define PUSHW(PUSH_VAR) \
					_asm { push PUSH_VAR }

#				define PUSHD(PUSH_VAR) \
					_asm { push PUSH_VAR }

#				define PUSHQ(PUSH_VAR) \
					_asm { push PUSH_VAR }

#				define POP(POP_VAR) \
					_asm { pop POP_VAR }

#				define POPW(POP_VAR) \
					_asm { pop POP_VAR }

#				define POPD(POP_VAR) \
					_asm { pop POP_VAR }

#				define POPQ(POP_VAR) \
					_asm { pop POP_VAR }
#			endif /* INLINE_ASM_TYPE__WATCOM */
/* ************************ [^] WATCOM ASM STYLE [^] *********************** */

/* ************************ [v] AZTEC ASM STYLE [v] ************************ */
#			ifdef INLINE_ASM_TYPE__AZTEC
#				define PUSH(PUSH_VAR) \
					asm { push PUSH_VAR }

#				define PUSHW(PUSH_VAR) \
					asm { push PUSH_VAR }

#				define PUSHD(PUSH_VAR) \
					asm { push PUSH_VAR }

#				define PUSHQ(PUSH_VAR) \
					asm { push PUSH_VAR }

#				define POP(POP_VAR) \
					asm { pop POP_VAR }

#				define POPW(POP_VAR) \
					asm { pop POP_VAR }

#				define POPD(POP_VAR) \
					asm { pop POP_VAR }

#				define POPQ(POP_VAR) \
					asm { pop POP_VAR }
#			endif /* INLINE_ASM_TYPE__AZTEC */
/* ************************ [^] AZTEC ASM STYLE [^] ************************ */

/* ************************* [v] ISO C ASM STYLE [v] ************************ */
#			ifdef INLINE_ASM_TYPE__ISO
#				define PUSH(PUSH_VAR) \
					__asm__ __volatile__("push %0" : : "rm"((long)(PUSH_VAR)))

#				define PUSHW(PUSH_VAR) \
					__asm__ __volatile__("pushw %0" : : "rm"((short)(PUSH_VAR)))

#				define PUSHD(PUSH_VAR) \
					__asm__ __volatile__("pushl %0" : : "rm"((int)(PUSH_VAR)))

#				ifdef __x86_64__
#					define PUSHQ(PUSH_VAR) \
						__asm__ __volatile__("pushq %0" : : "rm"((long long)(PUSH_VAR)))
#				else
#					define PUSHQ(PUSH_VAR) PUSHD(PUSH_VAR)
#				endif /* __x86_64__ */

#				define POP(POP_VAR) \
					__asm__ __volatile__("pop %0" : "=rm"(POP_VAR))

#				define POPW(POP_VAR) \
					__asm__ __volatile__("popw %0" : "=rm"(POP_VAR))

#				define POPD(POP_VAR) \
					__asm__ __volatile__("popl %0" : "=rm"(POP_VAR))

#				ifdef __x86_64__
#					define POPQ(POP_VAR) \
						__asm__ __volatile__("popq %0" : "=rm"(POP_VAR))
#				else
#					define POPQ(POP_VAR) POPD(POP_VAR)
#				endif /* __x86_64__ */
#			endif /* INLINE_ASM_TYPE__ISO */
/* ************************* [^] ISO C ASM STYLE [^] ************************ */

#		endif /* __CPU_INTEL__ */
/* ************************ [^] INTEL X86/X64 CPU [^] *********************** */

/* *************************** [v] ARM CPU [v] ****************************** */
#		ifdef __CPU_AMD__

/* ************************** [v] GNU ASM STYLE [v] ************************* */
#			ifdef INLINE_ASM_TYPE__GNU
#				define PUSH(PUSH_VAR) \
					__asm__ __volatile__("str %0, [sp, #-4]!" : : "r"((int)(PUSH_VAR)) : "sp")

#				define PUSHW(PUSH_VAR) \
					__asm__ __volatile__("strh %0, [sp, #-2]!" : : "r"((short)(PUSH_VAR)) : "sp")

#				define PUSHD(PUSH_VAR) \
					__asm__ __volatile__("str %0, [sp, #-4]!" : : "r"((int)(PUSH_VAR)) : "sp")

#				ifdef __aarch64__
#					define PUSHQ(PUSH_VAR) \
						__asm__ __volatile__("str %0, [sp, #-8]!" : : "r"((long long)(PUSH_VAR)) : "sp")
#				else
#					define PUSHQ(PUSH_VAR) PUSHD(PUSH_VAR)
#				endif /* __aarch64__ */

#				define POP(POP_VAR) \
					__asm__ __volatile__("ldr %0, [sp], #4" : "=r"(POP_VAR) : : "sp")

#				define POPW(POP_VAR) \
					__asm__ __volatile__("ldrh %0, [sp], #2" : "=r"(POP_VAR) : : "sp")

#				define POPD(POP_VAR) \
					__asm__ __volatile__("ldr %0, [sp], #4" : "=r"(POP_VAR) : : "sp")

#				ifdef __aarch64__
#					define POPQ(POP_VAR) \
						__asm__ __volatile__("ldr %0, [sp], #8" : "=r"(POP_VAR) : : "sp")
#				else
#					define POPQ(POP_VAR) POPD(POP_VAR)
#				endif /* __aarch64__ */
#			endif /* INLINE_ASM_TYPE__GNU */
/* ************************** [^] GNU ASM STYLE [^] ************************* */

/* ************************** [v] ARM ASM STYLE [v] ************************* */
#			ifdef INLINE_ASM_TYPE__ARM
#				define PUSH(PUSH_VAR) \
					__asm("str %0, [sp, #-4]!" : : "r"((int)(PUSH_VAR)))

#				define PUSHW(PUSH_VAR) \
					__asm("strh %0, [sp, #-2]!" : : "r"((short)(PUSH_VAR)))

#				define PUSHD(PUSH_VAR) \
					__asm("str %0, [sp, #-4]!" : : "r"((int)(PUSH_VAR)))

#				ifdef __aarch64__
#					define PUSHQ(PUSH_VAR) \
						__asm("str %0, [sp, #-8]!" : : "r"((long long)(PUSH_VAR)))
#				else
#					define PUSHQ(PUSH_VAR) PUSHD(PUSH_VAR)
#				endif /* __aarch64__ */

#				define POP(POP_VAR) \
					__asm("ldr %0, [sp], #4" : "=r"(POP_VAR))

#				define POPW(POP_VAR) \
					__asm("ldrh %0, [sp], #2" : "=r"(POP_VAR))

#				define POPD(POP_VAR) \
					__asm("ldr %0, [sp], #4" : "=r"(POP_VAR))

#				ifdef __aarch64__
#					define POPQ(POP_VAR) \
						__asm("ldr %0, [sp], #8" : "=r"(POP_VAR))
#				else
#					define POPQ(POP_VAR) POPD(POP_VAR)
#				endif /* __aarch64__ */
#			endif /* INLINE_ASM_TYPE__ARM */
/* ************************** [^] ARM ASM STYLE [^] ************************* */

/* ************************** [v] KEIL ASM STYLE [v] ************************ */
#			ifdef INLINE_ASM_TYPE__KEIL
#				define PUSH(PUSH_VAR) \
					{ \
						__asm { STR PUSH_VAR, [SP, #-4]! } \
					}

#				define PUSHW(PUSH_VAR) \
					{ \
						__asm { STRH PUSH_VAR, [SP, #-2]! } \
					}

#				define PUSHD(PUSH_VAR) \
					{ \
						__asm { STR PUSH_VAR, [SP, #-4]! } \
					}

#				define PUSHQ(PUSH_VAR) PUSHD(PUSH_VAR)

#				define POP(POP_VAR) \
					{ \
						__asm { LDR POP_VAR, [SP], #4 } \
					}

#				define POPW(POP_VAR) \
					{ \
						__asm { LDRH POP_VAR, [SP], #2 } \
					}

#				define POPD(POP_VAR) \
					{ \
						__asm { LDR POP_VAR, [SP], #4 } \
					}

#				define POPQ(POP_VAR) POPD(POP_VAR)
#			endif /* INLINE_ASM_TYPE__KEIL */
/* ************************** [^] KEIL ASM STYLE [^] ************************ */

/* ************************* [v] ISO C ASM STYLE [v] ************************ */
#			ifdef INLINE_ASM_TYPE__ISO
#				define PUSH(PUSH_VAR) \
					__asm__ __volatile__("str %0, [sp, #-4]!" : : "r"((int)(PUSH_VAR)) : "sp")

#				define PUSHW(PUSH_VAR) \
					__asm__ __volatile__("strh %0, [sp, #-2]!" : : "r"((short)(PUSH_VAR)) : "sp")

#				define PUSHD(PUSH_VAR) \
					__asm__ __volatile__("str %0, [sp, #-4]!" : : "r"((int)(PUSH_VAR)) : "sp")

#				ifdef __aarch64__
#					define PUSHQ(PUSH_VAR) \
						__asm__ __volatile__("str %0, [sp, #-8]!" : : "r"((long long)(PUSH_VAR)) : "sp")
#				else
#					define PUSHQ(PUSH_VAR) PUSHD(PUSH_VAR)
#				endif /* __aarch64__ */

#				define POP(POP_VAR) \
					__asm__ __volatile__("ldr %0, [sp], #4" : "=r"(POP_VAR) : : "sp")

#				define POPW(POP_VAR) \
					__asm__ __volatile__("ldrh %0, [sp], #2" : "=r"(POP_VAR) : : "sp")

#				define POPD(POP_VAR) \
					__asm__ __volatile__("ldr %0, [sp], #4" : "=r"(POP_VAR) : : "sp")

#				ifdef __aarch64__
#					define POPQ(POP_VAR) \
						__asm__ __volatile__("ldr %0, [sp], #8" : "=r"(POP_VAR) : : "sp")
#				else
#					define POPQ(POP_VAR) POPD(POP_VAR)
#				endif /* __aarch64__ */
#			endif /* INLINE_ASM_TYPE__ISO */
/* ************************* [^] ISO C ASM STYLE [^] ************************ */

#		endif /* __CPU_AMD__ */
/* *************************** [^] ARM CPU [^] ****************************** */

/* ************************* [v] AMD X86 CPU [v] **************************** */
#		ifdef __CPU_AMD_X86__

/* ************************** [v] GNU ASM STYLE [v] ************************* */
#			ifdef INLINE_ASM_TYPE__GNU
#				define PUSH(PUSH_VAR) \
					__asm__ __volatile__("push %0" : : "rm"((long)(PUSH_VAR)))

#				define PUSHW(PUSH_VAR) \
					__asm__ __volatile__("pushw %0" : : "rm"((short)(PUSH_VAR)))

#				define PUSHD(PUSH_VAR) \
					__asm__ __volatile__("pushl %0" : : "rm"((int)(PUSH_VAR)))

#				define PUSHQ(PUSH_VAR) \
					__asm__ __volatile__("pushq %0" : : "rm"((long long)(PUSH_VAR)))

#				define POP(POP_VAR) \
					__asm__ __volatile__("pop %0" : "=rm"(POP_VAR))

#				define POPW(POP_VAR) \
					__asm__ __volatile__("popw %0" : "=rm"(POP_VAR))

#				define POPD(POP_VAR) \
					__asm__ __volatile__("popl %0" : "=rm"(POP_VAR))

#				define POPQ(POP_VAR) \
					__asm__ __volatile__("popq %0" : "=rm"(POP_VAR))
#			endif /* INLINE_ASM_TYPE__GNU */
/* ************************** [^] GNU ASM STYLE [^] ************************* */

/* ************************* [v] ISO C ASM STYLE [v] ************************ */
#			ifdef INLINE_ASM_TYPE__ISO
#				define PUSH(PUSH_VAR) \
					__asm__ __volatile__("push %0" : : "rm"((long)(PUSH_VAR)))

#				define PUSHW(PUSH_VAR) \
					__asm__ __volatile__("pushw %0" : : "rm"((short)(PUSH_VAR)))

#				define PUSHD(PUSH_VAR) \
					__asm__ __volatile__("pushl %0" : : "rm"((int)(PUSH_VAR)))

#				define PUSHQ(PUSH_VAR) \
					__asm__ __volatile__("pushq %0" : : "rm"((long long)(PUSH_VAR)))

#				define POP(POP_VAR) \
					__asm__ __volatile__("pop %0" : "=rm"(POP_VAR))

#				define POPW(POP_VAR) \
					__asm__ __volatile__("popw %0" : "=rm"(POP_VAR))

#				define POPD(POP_VAR) \
					__asm__ __volatile__("popl %0" : "=rm"(POP_VAR))

#				define POPQ(POP_VAR) \
					__asm__ __volatile__("popq %0" : "=rm"(POP_VAR))
#			endif /* INLINE_ASM_TYPE__ISO */
/* ************************* [^] ISO C ASM STYLE [^] ************************ */

#		endif /* __CPU_AMD_X86__ */
/* ************************* [^] AMD X86 CPU [^] **************************** */

/* ************************ [v] POWERPC CPU [v] ****************************** */
#		ifdef __CPU_POWERPC__

/* ************************** [v] GNU ASM STYLE [v] ************************* */
#			ifdef INLINE_ASM_TYPE__GNU
#				define PUSH(PUSH_VAR) \
					__asm__ __volatile__("stwu %0, -4(%%r1)" : : "r"((int)(PUSH_VAR)) : "r1")

#				define PUSHW(PUSH_VAR) \
					__asm__ __volatile__("sthux %0, %%r1, %1" : : "r"((short)(PUSH_VAR)), "r"(-2) : "r1")

#				define PUSHD(PUSH_VAR) \
					__asm__ __volatile__("stwu %0, -4(%%r1)" : : "r"((int)(PUSH_VAR)) : "r1")

#				define PUSHQ(PUSH_VAR) \
					__asm__ __volatile__("stdu %0, -8(%%r1)" : : "r"((long long)(PUSH_VAR)) : "r1")

#				define POP(POP_VAR) \
					__asm__ __volatile__("lwz %0, 0(%%r1); addi %%r1, %%r1, 4" : "=r"(POP_VAR) : : "r1")

#				define POPW(POP_VAR) \
					__asm__ __volatile__("lhz %0, 0(%%r1); addi %%r1, %%r1, 2" : "=r"(POP_VAR) : : "r1")

#				define POPD(POP_VAR) \
					__asm__ __volatile__("lwz %0, 0(%%r1); addi %%r1, %%r1, 4" : "=r"(POP_VAR) : : "r1")

#				define POPQ(POP_VAR) \
					__asm__ __volatile__("ld %0, 0(%%r1); addi %%r1, %%r1, 8" : "=r"(POP_VAR) : : "r1")
#			endif /* INLINE_ASM_TYPE__GNU */
/* ************************** [^] GNU ASM STYLE [^] ************************* */

/* ************************* [v] ISO C ASM STYLE [v] ************************ */
#			ifdef INLINE_ASM_TYPE__ISO
#				define PUSH(PUSH_VAR) \
					__asm__ __volatile__("stwu %0, -4(%%r1)" : : "r"((int)(PUSH_VAR)) : "r1")

#				define PUSHW(PUSH_VAR) \
					__asm__ __volatile__("sthux %0, %%r1, %1" : : "r"((short)(PUSH_VAR)), "r"(-2) : "r1")

#				define PUSHD(PUSH_VAR) \
					__asm__ __volatile__("stwu %0, -4(%%r1)" : : "r"((int)(PUSH_VAR)) : "r1")

#				define PUSHQ(PUSH_VAR) \
					__asm__ __volatile__("stdu %0, -8(%%r1)" : : "r"((long long)(PUSH_VAR)) : "r1")

#				define POP(POP_VAR) \
					__asm__ __volatile__("lwz %0, 0(%%r1); addi %%r1, %%r1, 4" : "=r"(POP_VAR) : : "r1")

#				define POPW(POP_VAR) \
					__asm__ __volatile__("lhz %0, 0(%%r1); addi %%r1, %%r1, 2" : "=r"(POP_VAR) : : "r1")

#				define POPD(POP_VAR) \
					__asm__ __volatile__("lwz %0, 0(%%r1); addi %%r1, %%r1, 4" : "=r"(POP_VAR) : : "r1")

#				define POPQ(POP_VAR) \
					__asm__ __volatile__("ld %0, 0(%%r1); addi %%r1, %%r1, 8" : "=r"(POP_VAR) : : "r1")
#			endif /* INLINE_ASM_TYPE__ISO */
/* ************************* [^] ISO C ASM STYLE [^] ************************ */

#		endif /* __CPU_POWERPC__ */
/* ************************ [^] POWERPC CPU [^] ****************************** */

/* ************************* [v] RISC-V CPU [v] ****************************** */
#		ifdef __CPU_RISCV__

/* ************************** [v] GNU ASM STYLE [v] ************************* */
#			ifdef INLINE_ASM_TYPE__GNU
#				define PUSH(PUSH_VAR) \
					__asm__ __volatile__("addi sp, sp, -4; sw %0, 0(sp)" : : "r"((int)(PUSH_VAR)) : "sp")

#				define PUSHW(PUSH_VAR) \
					__asm__ __volatile__("addi sp, sp, -2; sh %0, 0(sp)" : : "r"((short)(PUSH_VAR)) : "sp")

#				define PUSHD(PUSH_VAR) \
					__asm__ __volatile__("addi sp, sp, -4; sw %0, 0(sp)" : : "r"((int)(PUSH_VAR)) : "sp")

#				ifdef __riscv_xlen
#					if __riscv_xlen == 64
#						define PUSHQ(PUSH_VAR) \
							__asm__ __volatile__("addi sp, sp, -8; sd %0, 0(sp)" : : "r"((long long)(PUSH_VAR)) : "sp")
#					else
#						define PUSHQ(PUSH_VAR) PUSHD(PUSH_VAR)
#					endif /* __riscv_xlen == 64 */
#				else
#					define PUSHQ(PUSH_VAR) PUSHD(PUSH_VAR)
#				endif /* __riscv_xlen */

#				define POP(POP_VAR) \
					__asm__ __volatile__("lw %0, 0(sp); addi sp, sp, 4" : "=r"(POP_VAR) : : "sp")

#				define POPW(POP_VAR) \
					__asm__ __volatile__("lh %0, 0(sp); addi sp, sp, 2" : "=r"(POP_VAR) : : "sp")

#				define POPD(POP_VAR) \
					__asm__ __volatile__("lw %0, 0(sp); addi sp, sp, 4" : "=r"(POP_VAR) : : "sp")

#				ifdef __riscv_xlen
#					if __riscv_xlen == 64
#						define POPQ(POP_VAR) \
							__asm__ __volatile__("ld %0, 0(sp); addi sp, sp, 8" : "=r"(POP_VAR) : : "sp")
#					else
#						define POPQ(POP_VAR) POPD(POP_VAR)
#					endif /* __riscv_xlen == 64 */
#				else
#					define POPQ(POP_VAR) POPD(POP_VAR)
#				endif /* __riscv_xlen */
#			endif /* INLINE_ASM_TYPE__GNU */
/* ************************** [^] GNU ASM STYLE [^] ************************* */

/* ************************* [v] ISO C ASM STYLE [v] ************************ */
#			ifdef INLINE_ASM_TYPE__ISO
#				define PUSH(PUSH_VAR) \
					__asm__ __volatile__("addi sp, sp, -4; sw %0, 0(sp)" : : "r"((int)(PUSH_VAR)) : "sp")

#				define PUSHW(PUSH_VAR) \
					__asm__ __volatile__("addi sp, sp, -2; sh %0, 0(sp)" : : "r"((short)(PUSH_VAR)) : "sp")

#				define PUSHD(PUSH_VAR) \
					__asm__ __volatile__("addi sp, sp, -4; sw %0, 0(sp)" : : "r"((int)(PUSH_VAR)) : "sp")

#				ifdef __riscv_xlen
#					if __riscv_xlen == 64
#						define PUSHQ(PUSH_VAR) \
							__asm__ __volatile__("addi sp, sp, -8; sd %0, 0(sp)" : : "r"((long long)(PUSH_VAR)) : "sp")
#					else
#						define PUSHQ(PUSH_VAR) PUSHD(PUSH_VAR)
#					endif /* __riscv_xlen == 64 */
#				else
#					define PUSHQ(PUSH_VAR) PUSHD(PUSH_VAR)
#				endif /* __riscv_xlen */

#				define POP(POP_VAR) \
					__asm__ __volatile__("lw %0, 0(sp); addi sp, sp, 4" : "=r"(POP_VAR) : : "sp")

#				define POPW(POP_VAR) \
					__asm__ __volatile__("lh %0, 0(sp); addi sp, sp, 2" : "=r"(POP_VAR) : : "sp")

#				define POPD(POP_VAR) \
					__asm__ __volatile__("lw %0, 0(sp); addi sp, sp, 4" : "=r"(POP_VAR) : : "sp")

#				ifdef __riscv_xlen
#					if __riscv_xlen == 64
#						define POPQ(POP_VAR) \
							__asm__ __volatile__("ld %0, 0(sp); addi sp, sp, 8" : "=r"(POP_VAR) : : "sp")
#					else
#						define POPQ(POP_VAR) POPD(POP_VAR)
#					endif /* __riscv_xlen == 64 */
#				else
#					define POPQ(POP_VAR) POPD(POP_VAR)
#				endif /* __riscv_xlen */
#			endif /* INLINE_ASM_TYPE__ISO */
/* ************************* [^] ISO C ASM STYLE [^] ************************ */

#		endif /* __CPU_RISCV__ */
/* ************************* [^] RISC-V CPU [^] ****************************** */

#	else
/* ***************** [v] INLINE ASM NOT SUPPORTED [v] ********************* */
#		error "PUSH/POP - INLINE ASSEMBLY NOT SUPPORTED ON THIS COMPILER"
/* ***************** [^] INLINE ASM NOT SUPPORTED [^] ********************* */
#	endif /* IS__INLINE_ASM__SUPPORTED */
/* ********************* [^] PUSH/POP IMPLEMENTATION [^] ******************** */

/* **************************** [v] LOWERCASE [v] *************************** */
#	define push PUSH
#	define pushw PUSHW
#	define pushd PUSHD
#	define pushq PUSHQ
#	define pop POP
#	define popw POPW
#	define popd POPD
#	define popq POPQ
/* **************************** [^] LOWERCASE [^] *************************** */

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

#endif /* !PUSH_POP_H */
