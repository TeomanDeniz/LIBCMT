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
# : License - GPL-3.0   :: Update - 2025/11/30 : #    ::::!!!1!!1!!!1!!!::     #
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
|* SET_RAX : #define () : SET RAX                                             *|
|* set_rax :            :                                                     *|
|*.........:............:.....................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* WITH THESE FUNCTIONS, YOU'RE ABLE TO MOVE AND GET VALUES FROM THE CPU      *|
|* REGISTER (RAX) AND STACK WITH DIFFERENT DATA SIZES AND ARCHS.              *|
|*                                                                            *|
|* USING `GET_RAX` OR `SET_RAX` ON A NON-INTEL CPU WILL CAUSE AN ERROR.       *|
|*                                                                            *|
|* NOTE: ON 32-BIT SYSTEMS, EAX REGISTER IS USED.                             *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|*  O - EXAMPLE 1: READ RAX INTO A VARIABLE                                   *|
|*  :                                                                         *|
|* 1| uint64_t myValue;                                                       *|
|* 2|                                                                         *|
|* 3| GET_RAX(myValue); // > MOV RAX CONTENTS INTO myValue                    *|
|*  :                                                                         *|
|*  : myValue NOW HOLDS THE VALUE FROM RAX                                    *|
|*  :                                                                         *|
|*                                                                            *|
|*  O - EXAMPLE 2: READ EAX ON 32-BIT SYSTEM                                  *|
|*  :                                                                         *|
|* 1| unsigned int myValue32;                                                 *|
|* 2|                                                                         *|
|* 3| GET_RAX(myValue32); // > MOV EAX CONTENTS INTO myValue32                *|
|*  :                                                                         *|
|*  : myValue32 NOW HOLDS THE VALUE FROM EAX                                  *|
|*  :                                                                         *|
|*                                                                            *|
|*  O - EXAMPLE 3: SETTING RAX                                                *|
|*  :                                                                         *|
|* 1| uint64_t myValue64 = 42;                                                *|
|* 2|                                                                         *|
|* 3| SET_RAX(myValue32); // > RAX IS NOW 42                                  *|
|* 4|                                                                         *|
|* 5| // OR                                                                   *|
|* 6|                                                                         *|
|* 7| SET_RAX(42); // > RAX IS NOW 42                                         *|
|*  :                                                                         *|
|*                                                                            *|
\******************************************************************************/

#ifndef RAX_H
#	define RAX_H 202511 /* VERSION */

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../ENVIRONMENTS/CPU.h" /*
#	 define __CPU_INTEL__
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
#	include "../../ENVIRONMENTS/ARCHITECTURE.h" /*
#	 define __SYSTEM_64_BIT__
#	        */
#	include "../../CHECK_FEATURE/INLINE_ASM.h" /*
#	 define IS__INLINE_ASM__SUPPORTED
#	 define INLINE_ASM_TYPE__GNU
#	 define INLINE_ASM_TYPE__ISO
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] C++ (PUSH) [v] *************************** */
#	ifdef __cplusplus /* C++ */
extern "C" {
#	endif /* __cplusplus */
/* *************************** [^] C++ (PUSH) [^] *************************** */

#	ifndef IS__INLINE_ASM__SUPPORTED /* UH-OH ._. */
#		define GET_RAX(_) \
			"ERROR - INLINE ASM DOES NOT SUPPORTED IN YOUR COMPILER :-("
#		define SET_RAX(_) GET_RAX(_)
#	endif /* !IS__INLINE_ASM__SUPPORTED */

#	ifndef GET_RAX
#		ifndef __CPU_INTEL__ /* UH-OH 2 ._. */
#			define GET_RAX(_) \
				"ERROR - YOU'RE NOT USING AN INTEL CPU TO USE THIS COMMAND >:("
#			define SET_RAX(_) GET_RAX(_)
#		endif /* !__CPU_INTEL__ */
#	endif /* !GET_RAX */

/* ************************* [v] __CPU_INTEL__ [v] ************************** */
#	ifdef __CPU_INTEL__
#		ifdef INLINE_ASM_TYPE__ISO
#			ifdef __SYSTEM_64_BIT__
#				define LOCALMACRO__RAX_GET(__REGISTER__) \
					__asm__ __volatile__ (\
						"movq %%rax, %0" \
						: "=r" (__REGISTER__)\
					)
#				define LOCALMACRO__RAX_SET(__REGISTER__) \
					__asm__ __volatile__ (\
						"movq %0, %%rax" \
						: \
						: "r" (__REGISTER__)\
					)
#			endif /* __SYSTEM_64_BIT__ */
#			ifdef __SYSTEM_32_BIT__
#				define LOCALMACRO__RAX_GET(__REGISTER__) \
					__asm__ __volatile__ (\
						"movl %%eax, %0" \
						: "=r" (__REGISTER__)\
					)
#				define LOCALMACRO__RAX_SET(__REGISTER__) \
					__asm__ __volatile__ (\
						"movl %0, %%eax" \
						: \
						: "r" (__REGISTER__)\
					)
#			endif /* __SYSTEM_32_BIT__ */
#			ifdef __SYSTEM_16_BIT__
#				define LOCALMACRO__RAX_GET(__REGISTER__) \
					__asm__ __volatile__ ("mov %%ax, %0" : "=r" (__REGISTER__))
#				define LOCALMACRO__RAX_SET(__REGISTER__) \
					__asm__ __volatile__ ("mov %0, %%ax" : : "r" (__REGISTER__))
#			endif /* __SYSTEM_16_BIT__ */
#		else
#			ifdef INLINE_ASM_TYPE__GNU
#				ifdef __SYSTEM_64_BIT__
#					define LOCALMACRO__RAX_GET(__REGISTER__) \
						asm volatile ("movq %%rax, %0" : "=r"(__REGISTER__))
#					define LOCALMACRO__RAX_SET(__REGISTER__) \
						asm volatile ("movq %0, %%rax" : : "r"(__REGISTER__))
#				endif /* __SYSTEM_64_BIT__ */
#				ifdef __SYSTEM_32_BIT__
#					define LOCALMACRO__RAX_GET(__REGISTER__) \
						asm volatile ("movl %%eax, %0" : "=r"(__REGISTER__))
#					define LOCALMACRO__RAX_SET(__REGISTER__) \
						asm volatile ("movl %0, %%eax" : : "r"(__REGISTER__))
#				endif /* __SYSTEM_32_BIT__ */
#				ifdef __SYSTEM_16_BIT__
#					define LOCALMACRO__RAX_GET(__REGISTER__) \
						asm volatile ("mov %%ax, %0" : "=r"(__REGISTER__))
#					define LOCALMACRO__RAX_SET(__REGISTER__) \
						asm volatile ("mov %0, %%ax" : : "r"(__REGISTER__))
#				endif /* __SYSTEM_16_BIT__ */
#			endif /* INLINE_ASM_TYPE__GNU */
#			ifndef LOCALMACRO__RAX_GET
#				ifdef _MSC_VER
#					ifdef __SYSTEM_64_BIT__
#						define LOCALMACRO__RAX_GET(__REGISTER__) \
							__asm\
							{\
								mov rax, __REGISTER__\
							}
#						define LOCALMACRO__RAX_SET(__REGISTER__) \
							__asm\
							{\
								mov __REGISTER__, rax\
							}
#					endif /* __SYSTEM_64_BIT__ */
#					ifdef __SYSTEM_32_BIT__
#						define LOCALMACRO__RAX_GET(__REGISTER__) \
							__asm\
							{\
								mov eax, __REGISTER__\
							}
#						define LOCALMACRO__RAX_SET(__REGISTER__) \
							__asm\
							{\
								mov __REGISTER__, eax\
							}
#					endif /* __SYSTEM_32_BIT__ */
#					ifdef __SYSTEM_16_BIT__
#						define LOCALMACRO__RAX_GET(__REGISTER__) \
							__asm\
							{\
								mov ax, __REGISTER__\
							}
#						define LOCALMACRO__RAX_SET(__REGISTER__) \
							__asm\
							{\
								mov __REGISTER__, ax\
							}
#					endif /* __SYSTEM_16_BIT__ */
#				endif /* _MSC_VER */
#			endif /* !LOCALMACRO__RAX_GET */
#			ifndef LOCALMACRO__RAX_GET
#				ifdef __clang__
#					ifdef __SYSTEM_64_BIT__
#						define LOCALMACRO__RAX_GET(__REGISTER__) \
							asm volatile (\
								"movq %%rax, %0" \
								: "=r"(__REGISTER__) \
							)
#						define LOCALMACRO__RAX_SET(__REGISTER__) \
							asm volatile (\
								"movq %0, %%rax" \
								: \
								: "r"(__REGISTER__) \
							)
#					endif /* __SYSTEM_64_BIT__ */
#					ifdef __SYSTEM_32_BIT__
#						define LOCALMACRO__RAX_GET(__REGISTER__) \
							asm volatile (\
								"movl %%eax, %0" \
								: "=r"(__REGISTER__) \
							)
#						define LOCALMACRO__RAX_SET(__REGISTER__) \
							asm volatile (\
								"movl %0, %%eax" \
								: \
								: "r"(__REGISTER__) \
							)
#					endif /* __SYSTEM_32_BIT__ */
#					ifdef __SYSTEM_16_BIT__
#						define LOCALMACRO__RAX_GET(__REGISTER__) \
							asm volatile (\
								"mov %%ax, %0" \
								: "=r"(__REGISTER__) \
							)
#						define LOCALMACRO__RAX_SET(__REGISTER__) \
							asm volatile (\
								"mov %0, %%ax" \
								: \
								: "r"(__REGISTER__) \
							)
#					endif /* __SYSTEM_16_BIT__ */
#				endif /* __clang__ */
#			endif /* !LOCALMACRO__RAX_GET */
/* TODO: ... */
#		endif /* INLINE_ASM_TYPE__ISO */
#	endif /* __CPU_INTEL__ */
/* ************************* [^] __CPU_INTEL__ [^] ************************** */

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

#	ifndef GET_RAX
#		define GET_RAX(VARIABLE) \
			do\
			{\
				register void	*__REGISTER__;\
				\
				LOCALMACRO__RAX_GET(__REGISTER__);\
				(VARIABLE) = __REGISTER__;\
			}\
			while (0)
#	endif /* !GET_RAX */

#	ifndef SET_RAX
#		define SET_RAX(VALUE) \
			do\
			{\
				register void	*__REGISTER__ = (void *)(VALUE);\
				\
				LOCALMACRO__RAX_SET(__REGISTER__);\
			}\
			while (0)
#	endif /* !SET_RAX */

/* *************************** [v] C++ (POP) [v] **************************** */
#	ifdef __cplusplus /* C++ */
}
#	endif /* __cplusplus */
/* *************************** [^] C++ (POP) [^] **************************** */

/* *************************** [v] LOWERCASE [v] **************************** */
#	define get_rax GET_RAX
#	define set_rax SET_RAX
/* *************************** [^] LOWERCASE [^] **************************** */

#endif /* !RAX_H */

#ifdef __EOF__
#	undef __EOF__
#endif /* __EOF__ */
#define __EOF__ //  <- FOR DOS, CP/M, ETC
