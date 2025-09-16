/******************************************************************************\
# H - RAX                                        #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2025/09/15 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/09/16 : #    ::::!!!1!!1!!!1!!!::     #
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
|*   NAME  :    TYPE    :                    DESCRIPTION                      *|
|*.........:............:.....................................................*|
|* GET_RAX : #define () : SET RAX INTO A VARIABLE                             *|
|* get_rax :            :                                                     *|
|*.........:............:.....................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|* WITH THESE FUNCTIONS, YOU'RE ABLE TO MOVE AND GET VALUES FROM THE CPU      *|
|* REGISTER (RAX, X0, ETC.) AND STACK WITH DIFFERENT DATA SIZES AND ARCHS.    *|
|*                                                                            *|
|* NOTE: ON 32-BIT SYSTEMS, EAX OR R0 REGISTERS ARE USED.                     *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* O - EXAMPLE 1: READ RAX INTO A VARIABLE                                    *|
|* :                                                                          *|
|* ;.., uint64_t myValue;                                                     *|
|*    :                                                                       *|
|*    : GET_RAX(myValue);  // > MOV RAX CONTENTS INTO myValue                 *|
|*    ;..,                                                                    *|
|*       : myValue NOW HOLDS THE VALUE FROM RAX                               *|
|*                                                                            *|
|* O - EXAMPLE 2: READ EAX ON 32-BIT SYSTEM                                   *|
|* :                                                                          *|
|* ;.., unsigned int myValue32;                                               *|
|*    :                                                                       *|
|*    : GET_RAX(myValue32); // > MOV EAX CONTENTS INTO myValue32              *|
|*    ;..,                                                                    *|
|*       : myValue32 NOW HOLDS THE VALUE FROM EAX                             *|
|*                                                                            *|
|* O - EXAMPLE 3: CROSS-ARCHITECTURE ARM SUPPORT                              *|
|* :                                                                          *|
|* ;.., uint64_t armValue;                                                    *|
|*    :                                                                       *|
|*    : GET_RAX(armValue); // > READS X0 ON ARM64 OR R0 ON ARM32              *|
|*    ;..,                                                                    *|
|*       : armValue NOW HOLDS THE FIRST ARGUMENT REGISTER VALUE               *|
|*                                                                            *|
\******************************************************************************/

#ifndef RAX_H
#	define RAX_H 202509 /* VERSION */

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
#	include <stdint.h> /*
#	typedef uint64_t;
#	        */
#	include "../ENVIRONMENTS/CPU.h" /*
#	 define __CPU_INTEL__
#	 define __CPU_ARM__
#	 define __CPU_AMD_X86__
#	 define __CPU_POWERPC__
#	 define __CPU_RISCV__
#	 define __CPU_HC12__
#	 define __CPU_HCS08__
#	 define __CPU_COLDFIRE__
#	 define __CPU_M68K__
#	 define __CPU_SH__
#	 define __CPU_MIPS__
#	 define __CPU_SPARC__
#	 define __CPU_6502__
#	 define __CPU_Z80__
#	 define __CPU_TI__
#	 define __CPU_SHARC__
#	 define __CPU_BLACKFIN__
#	 define __CPU_DSP56K__
#	        */
#	include "../ENVIRONMENTS/ARCHITECTURE.h" /*
#	 define __SYSTEM_64_BIT__
#	        */
#	include "../CHECK_FEATURE/INLINE_ASM.h" /*
#	 define IS__INLINE_ASM__SUPPORTED
#	 define INLINE_ASM_TYPE__ISO
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] C++ (PUSH) [v] *************************** */
#	ifdef __cplusplus /* C++ */
extern "C" {
#	endif /* __cplusplus */
/* *************************** [^] C++ (PUSH) [^] *************************** */

#	ifndef IS__INLINE_ASM__SUPPORTED /* UH-OH ._. */
#		error "INLINE ASM DOES NOT SUPPORTED IN YOUR COMPILER :-("
#	endif /* !IS__INLINE_ASM__SUPPORTED */

/* ************************* [v] __CPU_INTEL__ [v] ************************** */
#	ifdef __CPU_INTEL__
#		ifdef INLINE_ASM_TYPE__ISO
#			ifdef __SYSTEM_64_BIT__
#				define GET_RAX(VAR) \
					{\
						register uint64_t	__RAX__;\
						\
						__asm__ __volatile__ (\
							"movq %%rax, %0" \
							: "=r" (__RAX__)\
						);\
						(VAR) = (uint64_t)__RAX__;\
					}
#			else
#				define GET_RAX(VAR) \
					{\
						register unsigned long	__EAX__;\
						\
						__asm__ __volatile__ (\
							"movl %%eax, %0" \
							: "=r" (__RAX__)\
						);\
						(VAR) = (unsigned long)__EAX__;\
					}
#			endif /* __SYSTEM_64_BIT__ */
#		else
#			ifdef __GNUC__
#				ifdef __SYSTEM_64_BIT__
#					define GET_RAX(VAR) \
						{\
							register uint64_t	__RAX__;\
							\
							asm volatile (\
								"movq %%rax, %0" \
								: "=r"(__RAX__) \
								: \
								: \
							);\
							(VAR) = (uint64_t)__RAX__;\
						}
#				else
#					define GET_RAX(VAR) \
						{\
							register unsigned long	__EAX__;\
							\
							asm volatile (\
								"movl %%eax, %0" \
								: "=r"(__EAX__) \
								: \
								: \
							);\
							(VAR) = (unsigned long)__EAX__;\
						}
#				endif /* __SYSTEM_64_BIT__ */
#			endif /* __GNUC__ */
#			ifdef _MSC_VER
#				ifdef __SYSTEM_64_BIT__
#					define GET_RAX(VAR) \
						{\
							uint64_t	__RAX__;\
							\
							__asm\
							{\
								mov rax, __RAX__\
							};\
							(VAR) = __RAX__;\
						}
#				else
#					define GET_RAX(VAR) \
						{\
							unsigned long	__EAX__;\
							\
							__asm\
							{\
								mov eax, __EAX__\
							};\
							(VAR) = __EAX__;\
						}
#				endif /* __SYSTEM_64_BIT__ */
#			endif /* _MSC_VER */
#			ifdef __clang__
#				ifdef __SYSTEM_64_BIT__
#					define GET_RAX(VAR) \
						{\
							register uint64_t	__RAX__;\
							\
							asm volatile (\
								"movq %%rax, %0" \
								: "=r"(__RAX__) \
								: \
								: \
							);\
							(VAR) = __RAX__;\
						}
#				else
#					define GET_RAX(VAR) \
						{\
							register unsigned long	__EAX__;\
							\
							asm volatile (\
								"movl %%rax, %0" \
								: "=r"(__EAX__) \
								: \
								: \
							);\
							(VAR) = __EAX__;\
						}
#				endif /* __SYSTEM_64_BIT__ */
#			endif /* __clang__ */
/* TODO: ... */
#		endif /* INLINE_ASM_TYPE__ISO */
#	endif /* __CPU_INTEL__ */
/* ************************* [^] __CPU_INTEL__ [^] ************************** */

/* ************************** [v] __CPU_ARM__ [v] *************************** */
#	ifdef __CPU_ARM__
#		ifdef INLINE_ASM_TYPE__ISO
#			ifdef __SYSTEM_64_BIT__
#				define GET_RAX(VAR) \
					{\
						register uint64_t	__RAX__;\
						\
						__asm__ __volatile__ (\
							"mov %0, x0"\
							: "=r"(__RAX__)\
							: \
							: \
						);\
						(VAR) = __RAX__;\
					}
#			else
#				define GET_RAX(VAR) \
					{\
						register unsigned long	__EAX__;\
						\
						__asm__ __volatile__ (\
							"mov %0, r0"\
							: "=r"(__EAX__)\
							: \
							: \
						);\
						(VAR) = __EAX__;\
					}
#			endif /* __SYSTEM_64_BIT__ */
#		else
#			ifdef __CC_ARM
#				if (__ARMCC_VERSION <= 600000) /* ARMCC V5 */
#					ifdef __SYSTEM_64_BIT__
#						define GET_RAX(VAR) \
							{\
								register uint64_t	__RAX__;\
								\
								__asm {\
									MOV __RAX__, X0\
								};\
								(VAR) = __RAX__;\
							}
#					else
#						define GET_RAX(VAR) \
							{\
								register unsigned long	__EAX__;\
								\
								__asm {\
									MOV __EAX__, R0\
								};\
								(VAR) = __EAX__;\
							}
#					endif /* __SYSTEM_64_BIT__ */
#				else /* __ARMCC_VERSION > 600000 */
#					ifdef __SYSTEM_64_BIT__
#						define GET_RAX(VAR) \
							{\
								register uint64_t	__RAX__;\
								\
								asm volatile (\
									"mov %0, x0"\
									: "=r"(__RAX__)\
									: \
									: \
								);\
								(VAR) = __RAX__;\
							}
#					else
#						define GET_RAX(VAR) \
							{\
								register unsigned long	__EAX__;\
								\
								asm volatile (\
									"mov %0, r0"\
									: "=r"(__EAX__)\
									: \
									: \
								);\
								(VAR) = __EAX__;\
							}
#					endif /* __SYSTEM_64_BIT__ */
#				endif /* __ARMCC_VERSION <= 600000 */
#			endif /* __CC_ARM */
#			ifdef __GNUC__
#				ifdef __SYSTEM_64_BIT__
#					define GET_RAX(VAR) \
						{\
							register uint64_t	__RAX__;\
							\
							asm volatile (\
								"mov %0, x0"\
								: "=r"(__RAX__)\
								: \
								: \
							);\
							(VAR) = __RAX__;\
						}
#				else
#					define GET_RAX(VAR) \
						{\
							register unsigned long	__EAX__;\
							\
							asm volatile (\
								"mov %0, r0"\
								: "=r"(__EAX__)\
								: \
								: \
							);\
							(VAR) = __EAX__;\
						}
#				endif /* __SYSTEM_64_BIT__ */
#			endif /* __GNUC__ */
#			ifdef __clang__
#				ifdef __SYSTEM_64_BIT__
#					define GET_RAX(VAR) \
						{\
							register uint64_t	__RAX__;\
							\
							asm volatile (\
								"mov %0, x0"\
								: "=r"(__RAX__)\
								: \
								: \
							);\
							(VAR) = __RAX__;\
						}
#				else
#					define GET_RAX(VAR) \
						{\
							register unsigned long	__EAX__;\
							\
							asm volatile (\
								"mov %0, r0"\
								: "=r"(__EAX__)\
								: \
								: \
							);\
							(VAR) = __EAX__;\
						}
#				endif /* __SYSTEM_64_BIT__ */
#			endif /* __clang__ */
#		endif /* INLINE_ASM_TYPE__ISO */
#	endif /* __CPU_ARM__ */
/* ************************** [^] __CPU_ARM__ [^] *************************** */

/* ************************ [v] __CPU_AMD_X86__ [v] ************************* */
#	ifdef __CPU_AMD_X86__
/* TODO: ... */
#	endif /* __CPU_AMD_X86__ */
/* ************************ [^] __CPU_AMD_X86__ [^] ************************* */

/* ************************ [v] __CPU_POWERPC__ [v] ************************* */
#	ifdef __CPU_POWERPC__
/* TODO: ... */
#	endif /* __CPU_POWERPC__ */
/* ************************ [^] __CPU_POWERPC__ [^] ************************* */

/* ************************* [v] __CPU_RISCV__ [v] ************************** */
#	ifdef __CPU_RISCV__
/* TODO: ... */
#	endif /* __CPU_RISCV__ */
/* ************************* [^] __CPU_RISCV__ [^] ************************** */

/* ************************** [v] __CPU_HC12__ [v] ************************** */
#	ifdef __CPU_HC12__
/* TODO: ... */
#	endif /* __CPU_HC12__ */
/* ************************** [^] __CPU_HC12__ [^] ************************** */

/* ************************* [v] __CPU_HCS08__ [v] ************************** */
#	ifdef __CPU_HCS08__
/* TODO: ... */
#	endif /* __CPU_HCS08__ */
/* ************************* [^] __CPU_HCS08__ [^] ************************** */

/* ************************ [v] __CPU_COLDFIRE__ [v] ************************ */
#	ifdef __CPU_COLDFIRE__
/* TODO: ... */
#	endif /* __CPU_COLDFIRE__ */
/* ************************ [^] __CPU_COLDFIRE__ [^] ************************ */

/* ************************** [v] __CPU_M68K__ [v] ************************** */
#	ifdef __CPU_M68K__
/* TODO: ... */
#	endif /* __CPU_M68K__ */
/* ************************** [^] __CPU_M68K__ [^] ************************** */

/* *************************** [v] __CPU_SH__ [v] *************************** */
#	ifdef __CPU_SH__
/* TODO: ... */
#	endif /* __CPU_SH__ */
/* *************************** [^] __CPU_SH__ [^] *************************** */

/* ************************** [v] __CPU_MIPS__ [v] ************************** */
#	ifdef __CPU_MIPS__
/* TODO: ... */
#	endif /* __CPU_MIPS__ */
/* ************************** [^] __CPU_MIPS__ [^] ************************** */

/* ************************* [v] __CPU_SPARC__ [v] ************************** */
#	ifdef __CPU_SPARC__
/* TODO: ... */
#	endif /* __CPU_SPARC__ */
/* ************************* [^] __CPU_SPARC__ [^] ************************** */

/* ************************** [v] __CPU_6502__ [v] ************************** */
#	ifdef __CPU_6502__
/* TODO: ... */
#	endif /* __CPU_6502__ */
/* ************************** [^] __CPU_6502__ [^] ************************** */

/* ************************** [v] __CPU_Z80__ [v] *************************** */
#	ifdef __CPU_Z80__
/* TODO: ... */
#	endif /* __CPU_Z80__ */
/* ************************** [^] __CPU_Z80__ [^] *************************** */

/* *************************** [v] __CPU_TI__ [v] *************************** */
#	ifdef __CPU_TI__
/* TODO: ... */
#	endif /* __CPU_TI__ */
/* *************************** [^] __CPU_TI__ [^] *************************** */

/* ************************* [v] __CPU_SHARC__ [v] ************************** */
#	ifdef __CPU_SHARC__
/* TODO: ... */
#	endif /* __CPU_SHARC__ */
/* ************************* [^] __CPU_SHARC__ [^] ************************** */

/* ************************ [v] __CPU_BLACKFIN__ [v] ************************ */
#	ifdef __CPU_BLACKFIN__
/* TODO: ... */
#	endif /* __CPU_BLACKFIN__ */
/* ************************ [^] __CPU_BLACKFIN__ [^] ************************ */

/* ************************* [v] __CPU_DSP56K__ [v] ************************* */
#	ifdef __CPU_DSP56K__
#		ifdef __MWERKS__
/* TODO: ... */
#		endif /* __MWERKS__ */
#	endif /* __CPU_DSP56K__ */
/* ************************* [^] __CPU_DSP56K__ [^] ************************* */

/* *************************** [v] C++ (POP) [v] **************************** */
#	ifdef __cplusplus /* C++ */
}
#	endif /* __cplusplus */
/* *************************** [^] C++ (POP) [^] **************************** */

/* *************************** [v] LOWERCASE [v] **************************** */
#	define get_rax GET_RAX
/* *************************** [^] LOWERCASE [^] **************************** */

/* ************************ [v] TI CGT CCS (POP) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */

#endif /* !RAX_H */
