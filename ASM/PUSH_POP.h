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
# : License - GPL-3.0   :: Update - 2025/09/11 : #    ::::!!!1!!1!!!1!!!::     #
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
|* PUSH_16 : #define () : PUSH 2 BYTES INTO CPU STACK                         *|
|* push_16 :            :                                                     *|
|*.........:............:.....................................................*|
|* PUSH_32 : #define () : PUSH 4 BYTES INTO CPU STACK                         *|
|* push_32 :            :                                                     *|
|*.........:............:.....................................................*|
|* PUSH_64 : #define () : PUSH 8 BYTES INTO CPU STACK IF POSSIBLE             *|
|* push_64 :            :                                                     *|
|*.........:............:.....................................................*|
|* POP_16  : #define () : POP 2 BYTES FROM CPU STACK                          *|
|* pop_16  :            :                                                     *|
|*.........:............:.....................................................*|
|* POP_32  : #define () : POP 4 BYTES FROM CPU STACK                          *|
|* pop_32  :            :                                                     *|
|*.........:............:.....................................................*|
|* POP_64  : #define () : POP 8 BYTES FROM CPU STACK IF POSSIBLE              *|
|* pop_64  :            :                                                     *|
|*.........:............:.....................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|* WITH THESE FUNCTIONS, YOU'RE ABLE TO MOVE AND GET VALUES FROM THE CPU      *|
|* STACK WITH DIFFERENT DATA SIZES AND ARCHITECTURES.                         *|
|*                                                                            *|
|* NOTE: ON 32-BIT SYSTEMS, PUSH_64 AND POP_64 MACROS CAN MAXIMUM PUSH 32-BIT *|
|*       VARIABLES.                                                           *|
|*                                                                            *|
|*       THEY BEHAVE LIKE A "long" TYPE INSTEAD OF A TRUE 64-BIT VALUE.       *|
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
|*    : PUSH_32(a); // > ADDED 42 TO CPU STACK                                *|
|*    : a = b;      // |                                                      *|
|*    : POP_32(b);  // < REMOVED 42 FROM CPU STACK                            *|
|*    ;..,                                                                    *|
|*       : b IS NOW 42                                                        *|
|*       : a IS NOW 11                                                        *|
|*                                                                            *|
|* O - EXAMPLE 2: SENDING AND GETING DIRECT VALUES                            *|
|* :                                                                          *|
|* ;.., register int a;                                                       *|
|*    :                                                                       *|
|*    : PUSH_32(62); // > ADDED 62 TO CPU STACK                               *|
|*    : POP_32(a);   // < REMOVED 62 FROM CPU STACK                           *|
|*    ;..,                                                                    *|
|*       : a IS NOW 62                                                        *|
|*                                                                            *|
|* O - EXAMPLE 3: 16-BIT VALUES                                               *|
|* :                                                                          *|
|* ;.., short value16 = 0X1234;                                               *|
|*    :                                                                       *|
|*    : PUSH_16(value16); // > PUSH 16-BIT VALUE                              *|
|*    : value16 = 0;      // |                                                *|
|*    : POP_16(value16);  // < POP 16-BIT VALUE                               *|
|*    ;..,                                                                    *|
|*       : value16 IS NOW 0X1234                                              *|
|*                                                                            *|
|* O - EXAMPLE 4: 64-BIT VALUES (ON 64-BIT SYSTEMS)                           *|
|* :                                                                          *|
|* ;.., long bigValue = 0X123456789ABCDEF0LL;                                 *|
|*    :                                                                       *|
|*    : PUSH_64(bigValue); // > PUSH 64-BIT VALUE                             *|
|*    : bigValue = 0;      // |                                               *|
|*    : POP_64(bigValue);  // < POP 64-BIT VALUE                              *|
|*    ;..,                                                                    *|
|*       : bigValue IS NOW 0X123456789ABCDEF0LL                               *|
|*                                                                            *|
\******************************************************************************/

#ifndef PUSH_POP_H
#	define PUSH_POP_H 202509 /* VERSION */

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
#			define PUSH_16(VAR) \
				{\
					register unsigned short	__PUSH_16__;\
					\
					__PUSH_16__ = (unsigned short)(VAR);\
					__asm__ __volatile__ (\
						"pushw %0" \
						: "r" (__PUSH_16__)\
					);\
				}
#			define POP_16(VAR) \
				{\
					register unsigned short	__POP_16__;\
					\
					__asm__ __volatile__ (\
						"popw %0" \
						: "r" (__POP_16__)\
					);\
					(VAR) = __POP_16__;\
				}
#			define PUSH_32(VAR) \
				{\
					register unsigned int	__PUSH_32__;\
					\
					__PUSH_32__ = (unsigned int)(VAR);\
					__asm__ __volatile__ (\
						"pushl %0" \
						: "r" (__PUSH_32__)\
					);\
				}
#			define POP_32(VAR) \
				{\
					register unsigned int	__POP_32__;\
					\
					__asm__ __volatile__ (\
						"popl %0" \
						: "r" (__POP_32__)\
					);\
					(VAR) = __POP_32__;\
				}
#			ifdef __SYSTEM_64_BIT__
#				define PUSH_64(VAR) \
					{\
						register uint64_t	__PUSH_64__;\
						\
						__PUSH_64__ = (uint64_t)(VAR);\
						__asm__ __volatile__ (\
							"pushq %0" \
							: "r" (__PUSH_64__)\
						);\
					}
#				define POP_64(VAR) \
					{\
						register uint64_t	__POP_64__;\
						\
						__asm__ __volatile__ (\
							"popq %0" \
							: "r" (__POP_64__)\
						);\
						(VAR) = __POP_64__;\
					}
#			else
#				define PUSH_64(VAR) \
					{\
						register unsigned long	__PUSH_64__;\
						\
						__PUSH_64__ = (unsigned long)(VAR);\
						__asm__ __volatile__ (\
							"pushl %0" \
							: "r" (__PUSH_64__)\
						);\
					}
#				define POP_64(VAR) \
					{\
						register unsigned long	__POP_64__;\
						\
						__asm__ __volatile__ (\
							"popl %0" \
							: "r" (__POP_64__)\
						);\
						(VAR) = __POP_64__;\
					}
#			endif /* __SYSTEM_64_BIT__ */
#		else
#			ifdef __GNUC__
#				define PUSH_16(VAR) \
					{\
						register unsigned short	__PUSH_16__;\
						\
						__PUSH_16__ = (unsigned short)(VAR);\
						asm volatile (\
							"subl $2, %%esp\n\t" \
							"movw %0, (%%esp)" \
							: \
							: "r"(__PUSH_16__) \
							: "esp", "memory"\
						);\
					}
#				define POP_16(VAR) \
					{\
						register unsigned short	__POP_16__;\
						\
						asm volatile (\
							"movw (%%esp), %0\n\t" \
							"addl $2, %%esp" \
							: "=r"(__POP_16__) \
							: \
							: "esp", "memory"\
						);\
						(VAR) = __POP_16__;\
					}
#				define PUSH_32(VAR) \
					{\
						register unsigned int	__PUSH_32__;\
						\
						__PUSH_32__ = (unsigned int)(VAR);\
						asm volatile (\
							"subl $4, %%esp\n\t" \
							"movl %0, (%%esp)" \
							: \
							: "r"(__PUSH_32__) \
							: "esp", "memory"\
						);\
					}
#				define POP_32(VAR) \
					{\
						register unsigned int	__POP_32__;\
						\
						asm volatile (\
							"movl (%%esp), %0\n\t" \
							"addl $4, %%esp" \
							: "=r"(__POP_32__) \
							: \
							: "esp", "memory"\
						);\
						(VAR) = __POP_32__;\
					}
#				ifdef __SYSTEM_64_BIT__
#					define PUSH_64(VAR) \
						{\
							register uint64_t	__PUSH_64__;\
							\
							__PUSH_64__ = (uint64_t)(VAR);\
							asm volatile (\
								"subq $8, %%rsp\n\t" \
								"movq %0, (%%rsp)" \
								: \
								: "r"(__PUSH_64__) \
								: "rsp", "memory"\
							);\
						}
#					define POP_64(VAR) \
						{\
							register uint64_t	__POP_64__;\
							\
							asm volatile (\
								"movq (%%rsp), %0\n\t" \
								"addq $8, %%rsp" \
								: "=r"(__POP_64__) \
								: \
								: "rsp", "memory"\
							);\
							(VAR) = __POP_64__;\
						}
#				else
#					define PUSH_64(VAR) \
						{\
							register unsigned long	__PUSH_64__;\
							\
							__PUSH_64__ = (unsigned long)(VAR);\
							asm volatile (\
								"subl $4, %%esp\n\t" \
								"movl %0, (%%esp)" \
								: \
								: "r"(__PUSH_64__) \
								: "esp", "memory"\
							);\
						}
#					define POP_64(VAR) \
						{\
							register unsigned long	__POP_64__;\
							\
							asm volatile (\
								"movl (%%esp), %0\n\t" \
								"addl $4, %%esp" \
								: "=r"(__POP_64__) \
								: \
								: "esp", "memory"\
							);\
							(VAR) = __POP_64__;\
						}
#				endif /* __SYSTEM_64_BIT__ */
#			endif /* __GNUC__ */
#			ifdef _MSC_VER
#				define PUSH_16(VAR) \
					{\
						unsigned short	__PUSH_16__;\
						\
						__PUSH_16__ = (unsigned short)(VAR);\
						__asm\
						{\
							mov ax, __PUSH_16__\
							push ax\
						};\
					}
#				define POP_16(VAR) \
					{\
						unsigned short	__POP_16__;\
						\
						__asm\
						{\
							pop ax\
							mov __PUSH_16__, ax\
						};\
						(VAR) = __PUSH_16__;\
					}
#				define PUSH_32(VAR) \
					{\
						unsigned int	__PUSH_32__;\
						\
						__PUSH_32__ = (unsigned int)(VAR);\
						__asm\
						{\
							mov eax, __PUSH_32__\
							push eax\
						};\
					}
#				define POP_32(VAR) \
					{\
						unsigned int	__POP_32__;\
						\
						__asm\
						{\
							pop eax\
							mov __POP_32__, eax\
						};\
						(VAR) = __POP_32__;\
					}
#				ifdef __SYSTEM_64_BIT__
#					define PUSH_64(VAR) \
						{\
							uint64_t	__PUSH_64__;\
							\
							__PUSH_64__ = (uint64_t)(VAR);\
							__asm\
							{\
								mov rax, __PUSH_64__\
								push rax\
							};\
						}
#					define POP_64(VAR) \
						{\
							uint64_t	__POP_64__;\
							\
							__asm\
							{\
								pop rax\
								mov __POP_64__, rax\
							};\
							(VAR) = __POP_64__;\
						}
#				else
#					define PUSH_64(VAR) \
						{\
							unsigned long	__PUSH_64__;\
							\
							__PUSH_64__ = (unsigned long)(VAR);\
							__asm\
							{\
								mov eax, __PUSH_64__\
								push eax\
							};\
						}
#					define POP_64(VAR) \
						{\
							unsigned long	__POP_64__;\
							\
							__asm\
							{\
								pop eax\
								mov __POP_64__, eax\
							};\
							(VAR) = __POP_64__;\
						}
#				endif /* __SYSTEM_64_BIT__ */
#			endif /* _MSC_VER */
#			ifdef __clang__
#				define PUSH_16(VAR) \
					{\
						register unsigned short	__PUSH_16__;\
						\
						__PUSH_16__ = (unsigned short)(VAR);\
						asm volatile (\
							"subl $2, %%esp\n\t" \
							"movw %0, (%%esp)" \
							: \
							: "r"(__PUSH_16__) \
							: "esp", "memory"\
						);\
					}
#				define POP_16(VAR) \
					{\
						register unsigned short	__POP_16__;\
						\
						asm volatile (\
							"movw (%%esp), %0\n\t" \
							"addl $2, %%esp" \
							: "=r"(__POP_16__) \
							: \
							: "esp", "memory"\
						);\
						(VAR) = __POP_16__;\
					}
#				define PUSH_32(VAR) \
					{\
						register unsigned int	__PUSH_32__;\
						\
						__PUSH_32__ = (unsigned int)(VAR);\
						asm volatile (\
							"subl $4, %%esp\n\t" \
							"movl %0, (%%esp)" \
							: \
							: "r"(__PUSH_32__) \
							: "esp", "memory"\
						);\
					}
#				define POP_32(VAR) \
					{\
						register unsigned int	__POP_32__;\
						\
						asm volatile (\
							"movl (%%esp), %0\n\t" \
							"addl $4, %%esp" \
							: "=r"(__POP_32__) \
							: \
							: "esp", "memory"\
						);\
						(VAR) = __POP_32__;\
					}
#				ifdef __SYSTEM_64_BIT__
#					define PUSH_64(VAR) \
						{\
							register uint64_t	__PUSH_64__;\
							\
							__PUSH_64__ = (uint64_t)(VAR);\
							asm volatile (\
								"subq $8, %%rsp\n\t" \
								"movq %0, (%%rsp)" \
								: \
								: "r"(__PUSH_64__) \
								: "rsp", "memory"\
							);\
						}
#					define POP_64(VAR) \
						{\
							register uint64_t	__POP_64__;\
							\
							asm volatile (\
								"movq (%%rsp), %0\n\t" \
								"addq $8, %%rsp" \
								: "=r"(__POP_64__) \
								: \
								: "rsp", "memory"\
							);\
							(VAR) = __POP_64__;\
						}
#				else
#					define PUSH_64(VAR) \
						{\
							register unsigned long	__PUSH_64__;\
							\
							__PUSH_64__ = (unsigned long)(VAR);\
							asm volatile (\
								"subl $4, %%esp\n\t" \
								"movl %0, (%%esp)" \
								: \
								: "r"(__PUSH_64__) \
								: "esp", "memory"\
							);\
						}
#					define POP_64(VAR) \
						{\
							register unsigned long	__POP_64__;\
							\
							asm volatile (\
								"movl (%%esp), %0\n\t" \
								"addl $4, %%esp" \
								: "=r"(__POP_64__) \
								: \
								: "esp", "memory"\
							);\
							(VAR) = __POP_64__;\
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
#			define PUSH_16(VAR) \
				{\
					register unsigned short	__PUSH_16__;\
					\
					__PUSH_16__ = (unsigned short)(VAR);\
					__asm__ __volatile__ (\
						"sub sp, sp, #2\n\t"\
						"strh %0, [sp]\n\t"\
						: \
						: "r"(__PUSH_16__)\
						: "sp", "memory"\
					);\
				}
#			define POP_16(VAR) \
				{\
					register unsigned short	__POP_16__;\
					\
					__asm__ __volatile__ (\
						"ldrh %0, [sp]\n\t"\
						"add sp, sp, #2\n\t"\
						: "=r"(__POP_16__)\
						: \
						: "sp", "memory"\
					);\
					(VAR) = __POP_16__;\
				}
#			define PUSH_32(VAR) \
				{\
					register unsigned int	__PUSH_32__;\
					\
					__PUSH_32__ = (unsigned int)(VAR);\
					__asm__ __volatile__ (\
						"sub sp, sp, #4\n\t"\
						"str %0, [sp]\n\t"\
						: \
						: "r"(__PUSH_32__)\
						: "sp", "memory"\
					);\
				}
#			define POP_32(VAR) \
				{\
					register unsigned int	__POP_32__;\
					\
					__asm__ __volatile__ (\
						"ldr %0, [sp]\n\t"\
						"add sp, sp, #4\n\t"\
						: "=r"(__POP_32__)\
						: \
						: "sp", "memory"\
					);\
					(VAR) = __POP_32__;\
				}
#			ifdef __SYSTEM_64_BIT__
#				define PUSH_64(VAR) \
					{\
						register uint64_t	__PUSH_64__;\
						\
						__PUSH_64__ = (uint64_t)(VAR);\
						__asm__ __volatile__ (\
							"sub sp, sp, #8\n\t"\
							"str %0, [sp]\n\t"\
							: \
							: "r"(__PUSH_64__)\
							: "sp", "memory"\
						);\
					}
#				define POP_64(VAR) \
					{\
						register uint64_t	__POP_64__;\
						\
						__asm__ __volatile__ (\
							"ldr %0, [sp]\n\t"\
							"add sp, sp, #8\n\t"\
							: "=r"(__POP_64__)\
							: \
							: "sp", "memory"\
						);\
						(VAR) = __POP_64__;\
					}
#			else
#				define PUSH_64(VAR) \
					{\
						register unsigned long	__PUSH_64__;\
						\
						__PUSH_64__ = (unsigned long)(VAR);\
						__asm__ __volatile__ (\
							"sub sp, sp, #4\n\t"\
							"str %0, [sp]\n\t"\
							: \
							: "r"(__PUSH_64__)\
							: "sp", "memory"\
						);\
					}
#				define POP_64(VAR) \
					{\
						register unsigned long	__POP_64__;\
						\
						__asm__ __volatile__ (\
							"ldr %0, [sp]\n\t"\
							"add sp, sp, #4\n\t"\
							: "=r"(__POP_64__)\
							: \
							: "sp", "memory"\
						);\
						(VAR) = __POP_64__;\
					}
#			endif /* __SYSTEM_64_BIT__ */
#		else
#			ifdef __CC_ARM
#				if (__ARMCC_VERSION <= 600000) /* ARMCC V5 */
#					define PUSH_16(VAR) \
						{\
							register unsigned short	__PUSH_16__;\
							\
							__PUSH_16__ = (unsigned short)(VAR);\
							__asm {\
								sub sp, sp, #2 \
								strh __PUSH_16__, [sp]\
							}\
						}
#					define POP_16(VAR) \
						{\
							register unsigned short	__POP_16__;\
							\
							__asm {\
								LDRH __POP_16__, [sp] \
								ADD sp, sp, #2\
							}\
							(VAR) = __POP_16__;\
						}
#					define PUSH_32(VAR) \
						{\
							register unsigned int	__PUSH_32__;\
							\
							__PUSH_32__ = (unsigned int)(VAR);\
							__asm {\
								SUB sp, sp, #4 \
								STR __PUSH_32__, [sp]\
							}\
						}
#					define POP_32(VAR) \
						{\
							register unsigned int	__POP_32__;\
							\
							__asm {\
								LDR __POP_32__, [sp] \
								ADD sp, sp, #4\
							}\
							(VAR) = __POP_32__;\
						}
#					ifdef __SYSTEM_64_BIT__
#						define PUSH_64(VAR) \
							{\
								register uint64_t	__PUSH_64__;\
								\
								__PUSH_64__ = (uint64_t)(VAR);\
								__asm {\
									SUB sp, sp, #8 \
									STR __PUSH_64__, [sp]\
								};\
							}
#						define POP_64(VAR) \
							{\
								register uint64_t	__POP_64__;\
								\
								__asm {\
									LDR __POP_64__, [sp] \
									ADD sp, sp, #8\
								};\
								(VAR) = __POP_64__;\
							}
#					else
#						define PUSH_64(VAR) \
							{\
								register unsigned long	__PUSH_64__;\
								\
								__PUSH_64__ = (unsigned long)(VAR);\
								__asm {\
									SUB sp, sp, #4 \
									STR __PUSH_64__, [sp]\
								};\
							}
#						define POP_64(VAR) \
							{\
								register unsigned long	__POP_64__;\
								\
								__asm {\
									LDR __POP_64__, [sp] \
									ADD sp, sp, #4\
								};\
								(VAR) = __POP_64__;\
							}
#					endif /* __SYSTEM_64_BIT__ */
#				else /* __ARMCC_VERSION > 600000 */
#					define PUSH_16(VAR) \
						{\
							register unsigned short	__PUSH_16__;\
							\
							__PUSH_16__ = (unsigned short)(VAR);\
							asm volatile (\
								"sub sp, sp, #2\n\t"\
								"strh %0, [sp]\n\t"\
								: \
								: "r"(__PUSH_16__)\
								: "sp", "memory"\
							);\
						}
#					define POP_16(VAR) \
						{\
							register unsigned short	__POP_16__;\
							\
							asm volatile (\
								"ldrh %0, [sp]\n\t"\
								"add sp, sp, #2\n\t"\
								: "=r"(__POP_16__)\
								: \
								: "sp", "memory"\
							);\
							(VAR) = __POP_16__;\
						}
#					define PUSH_32(VAR) \
						{\
							register unsigned int	__PUSH_32__;\
							\
							__PUSH_32__ = (unsigned int)(VAR);\
							asm volatile (\
								"sub sp, sp, #4\n\t"\
								"str %0, [sp]\n\t"\
								: \
								: "r"(__PUSH_32__)\
								: "sp", "memory"\
							);\
						}
#					define POP_32(VAR) \
						{\
							register unsigned int	__POP_32__;\
							\
							asm volatile (\
								"ldr %0, [sp]\n\t"\
								"add sp, sp, #4\n\t"\
								: "=r"(__POP_32__)\
								: \
								: "sp", "memory"\
							);\
							(VAR) = __POP_32__;\
						}
#					ifdef __SYSTEM_64_BIT__
#						define PUSH_64(VAR) \
							{\
								register uint64_t	__PUSH_64__;\
								\
								__PUSH_64__ = (uint64_t)(VAR);\
								asm volatile (\
									"sub sp, sp, #8\n\t"\
									"str %0, [sp]\n\t"\
									: \
									: "r"(__PUSH_64__)\
									: "sp", "memory"\
								);\
							}
#						define POP_64(VAR) \
							{\
								register uint64_t	__POP_64__;\
								\
								asm volatile (\
									"ldr %0, [sp]\n\t"\
									"add sp, sp, #8\n\t"\
									: "=r"(__POP_64__)\
									: \
									: "sp", "memory"\
								);\
								(VAR) = __POP_64__;\
							}
#					else
#						define PUSH_64(VAR) \
							{\
								register unsigned long	__PUSH_64__;\
								\
								__PUSH_64__ = (unsigned long)(VAR);\
								asm volatile (\
									"sub sp, sp, #4\n\t"\
									"str %0, [sp]\n\t"\
									: \
									: "r"(__PUSH_64__)\
									: "sp", "memory"\
								);\
							}
#						define POP_64(VAR) \
							{\
								register unsigned long	__POP_64__;\
								\
								asm volatile (\
									"ldr %0, [sp]\n\t"\
									"add sp, sp, #4\n\t"\
									: "=r"(__POP_64__)\
									: \
									: "sp", "memory"\
								);\
								(VAR) = __POP_64__;\
							}
#					endif /* __SYSTEM_64_BIT__ */
#				endif /* __ARMCC_VERSION <= 600000 */
#			endif /* __CC_ARM */
#			ifdef __GNUC__
#				define PUSH_16(VAR) \
					{\
						register unsigned short	__PUSH_16__;\
						\
						__PUSH_16__ = (unsigned short)(VAR);\
						asm volatile (\
							"sub sp, sp, #2\n\t"\
							"strh %0, [sp]\n\t"\
							: \
							: "r"(__PUSH_16__)\
							: "sp", "memory"\
						);\
					}
#				define POP_16(VAR) \
					{\
						register unsigned short	__POP_16__;\
						\
						asm volatile (\
							"ldrh %0, [sp]\n\t"\
							"add sp, sp, #2\n\t"\
							: "=r"(__POP_16__)\
							: \
							: "sp", "memory"\
						);\
						(VAR) = __POP_16__;\
					}
#				define PUSH_32(VAR) \
					{\
						register unsigned int	__PUSH_32__;\
						\
						__PUSH_32__ = (unsigned int)(VAR);\
						asm volatile (\
							"sub sp, sp, #4\n\t"\
							"str %0, [sp]\n\t"\
							: \
							: "r"(__PUSH_32__)\
							: "sp", "memory"\
						);\
					}
#				define POP_32(VAR) \
					{\
						register unsigned int	__POP_32__;\
						\
						asm volatile (\
							"ldr %0, [sp]\n\t"\
							"add sp, sp, #4\n\t"\
							: "=r"(__POP_32__)\
							: \
							: "sp", "memory"\
						);\
						(VAR) = __POP_32__;\
					}
#				ifdef __SYSTEM_64_BIT__
#					define PUSH_64(VAR) \
						{\
							register uint64_t	__PUSH_64__;\
							\
							__PUSH_64__ = (uint64_t)(VAR);\
							asm volatile (\
								"sub sp, sp, #8\n\t"\
								"str %0, [sp]\n\t"\
								: \
								: "r"(__PUSH_64__)\
								: "sp", "memory"\
							);\
						}
#					define POP_64(VAR) \
						{\
							register uint64_t	__POP_64__;\
							\
							asm volatile (\
								"ldr %0, [sp]\n\t"\
								"add sp, sp, #8\n\t"\
								: "=r"(__POP_64__)\
								: \
								: "sp", "memory"\
							);\
							(VAR) = __POP_64__;\
						}
#				else
#					define PUSH_64(VAR) \
						{\
							register unsigned long	__PUSH_64__;\
							\
							__PUSH_64__ = (unsigned long)(VAR);\
							asm volatile (\
								"sub sp, sp, #4\n\t"\
								"str %0, [sp]\n\t"\
								: \
								: "r"(__PUSH_64__)\
								: "sp", "memory"\
							);\
						}
#					define POP_64(VAR) \
						{\
							register unsigned long	__POP_64__;\
							\
							asm volatile (\
								"ldr %0, [sp]\n\t"\
								"add sp, sp, #4\n\t"\
								: "=r"(__POP_64__)\
								: \
								: "sp", "memory"\
							);\
							(VAR) = __POP_64__;\
						}
#				endif /* __SYSTEM_64_BIT__ */
#			endif /* __GNUC__ */

#			ifdef __clang__
#				define PUSH_16(VAR) \
					{\
						register unsigned short	__PUSH_16__;\
						\
						__PUSH_16__ = (unsigned short)(VAR);\
						asm volatile (\
							"sub sp, sp, #2\n\t"\
							"strh %0, [sp]\n\t"\
							: \
							: "r"(__PUSH_16__)\
							: "sp", "memory"\
						);\
					}
#				define POP_16(VAR) \
					{\
						register unsigned short	__POP_16__;\
						\
						asm volatile (\
							"ldrh %0, [sp]\n\t"\
							"add sp, sp, #2\n\t"\
							: "=r"(__POP_16__)\
							: \
							: "sp", "memory"\
						);\
						(VAR) = __POP_16__;\
					}
#				define PUSH_32(VAR) \
					{\
						register unsigned int	__PUSH_32__;\
						\
						__PUSH_32__ = (unsigned int)(VAR);\
						asm volatile (\
							"sub sp, sp, #4\n\t"\
							"str %0, [sp]\n\t"\
							: \
							: "r"(__PUSH_32__)\
							: "sp", "memory"\
						);\
					}
#				define POP_32(VAR) \
					{\
						register unsigned int	__POP_32__;\
						\
						asm volatile (\
							"ldr %0, [sp]\n\t"\
							"add sp, sp, #4\n\t"\
							: "=r"(__POP_32__)\
							: \
							: "sp", "memory"\
						);\
						(VAR) = __POP_32__;\
					}
#				ifdef __SYSTEM_64_BIT__
#					define PUSH_64(VAR) \
						{\
							register uint64_t	__PUSH_64__;\
							\
							__PUSH_64__ = (uint64_t)(VAR);\
							asm volatile (\
								"sub sp, sp, #8\n\t"\
								"str %0, [sp]\n\t"\
								: \
								: "r"(__PUSH_64__)\
								: "sp", "memory"\
							);\
						}
#					define POP_64(VAR) \
						{\
							register uint64_t	__POP_64__;\
							\
							asm volatile (\
								"ldr %0, [sp]\n\t"\
								"add sp, sp, #8\n\t"\
								: "=r"(__POP_64__)\
								: \
								: "sp", "memory"\
							);\
							(VAR) = __POP_64__;\
						}
#				else
#					define PUSH_64(VAR) \
						{\
							register unsigned long	__PUSH_64__;\
							\
							__PUSH_64__ = (unsigned long)(VAR);\
							asm volatile (\
								"sub sp, sp, #4\n\t"\
								"str %0, [sp]\n\t"\
								: \
								: "r"(__PUSH_64__)\
								: "sp", "memory"\
							);\
						}
#					define POP_64(VAR) \
						{\
							register unsigned long	__POP_64__;\
							\
							asm volatile (\
								"ldr %0, [sp]\n\t"\
								"add sp, sp, #4\n\t"\
								: "=r"(__POP_64__)\
								: \
								: "sp", "memory"\
							);\
							(VAR) = __POP_64__;\
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
#	define push_16 PUSH_16
#	define push_32 PUSH_32
#	define push_64 PUSH_64
#	define pop_16 POP_16
#	define pop_32 POP_32
#	define pop_64 POP_64
/* *************************** [^] LOWERCASE [^] **************************** */

/* ************************ [v] TI CGT CCS (POP) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */

#endif /* !PUSH_POP_H */
