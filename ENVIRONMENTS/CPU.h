/******************************************************************************\
# H - CPU                                        #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2025/08/02 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/11/30 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/******************************************************************************\
|*                                  CONTENTS                                  *|
|******************************************************************************|
|*............................................................................*|
|*        NAME      :   TYPE  :                  DESCRIPTION                  *|
|*..................:.........:...............................................*|
|* __CPU_INTEL__    : #define : DEFINED IF THE TARGET CPU IS INTEL CPU        *|
|*                  :         : (X86/X86-64)                                  *|
|*..................:.........:...............................................*|
|* __CPU_ARM__      : #define : DEFINED IF THE TARGET CPU IS ARM-BASED CPU    *|
|*                  :         : (AARCH32/AARCH64)                             *|
|*..................:.........:...............................................*|
|* __CPU_AMD_X86__  : #define : DEFINED IF THE TARGET CPU IS ARM-X86 CPU      *|
|*..................:.........:...............................................*|
|* __CPU_POWERPC__  : #define : DEFINED IF THE TARGET CPU IS IBM-POWERPC CPU  *|
|*..................:.........:...............................................*|
|* __CPU_RISCV__    : #define : DEFINED IF THE TARGET CPU IS RISC-V CPU       *|
|*..................:.........:...............................................*|
|* __CPU_HC12__     : #define : DEFINED IF THE TARGET CPU IS HC12 CPU         *|
|*..................:.........:...............................................*|
|* __CPU_HCS08__    : #define : DEFINED IF THE TARGET CPU IS HCS08 CPU        *|
|*..................:.........:...............................................*|
|* __CPU_COLDFIRE__ : #define : DEFINED IF THE TARGET CPU IS COLDFIRE CPU     *|
|*..................:.........:...............................................*|
|* __CPU_M68K__     : #define : DEFINED IF THE TARGET CPU IS M68K             *|
|*..................:.........:...............................................*|
|* __CPU_SH__       : #define : DEFINED IF THE TARGET CPU IS SUPERH           *|
|*..................:.........:...............................................*|
|* __CPU_MIPS__     : #define : DEFINED IF THE TARGET CPU IS MIPS             *|
|*..................:.........:...............................................*|
|* __CPU_SPARC__    : #define : DEFINED IF THE TARGET CPU IS SPARC            *|
|*..................:.........:...............................................*|
|* __CPU_6502__     : #define : DEFINED IF THE TARGET CPU IS 6502             *|
|*                  :         : MICROPROCESSOR                                *|
|*..................:.........:...............................................*|
|* __CPU_Z80__      : #define : DEFINED IF THE TARGET CPU IS Z80              *|
|*..................:.........:...............................................*|
|* __CPU_TI__       : #define : DEFINED IF THE TARGET CPU IS TI-MCU PROCESSOR *|
|*..................:.........:...............................................*|
|* __CPU_SHARC__    : #define : DEFINED IF THE TARGET CPU IS SHARC            *|
|*..................:.........:...............................................*|
|* __CPU_BLACKFIN__ : #define : DEFINED IF THE TARGET CPU IS BLACKFIN         *|
|*..................:.........:...............................................*|
|* __CPU_DSP56K__   : #define : DEFINED IF THE TARGET CPU IS                  *|
|*                  :         : MOTOROLA-DSP56000                             *|
|*..................:.........:...............................................*|
|* __CPU_VER__      : (*F)()  : RETURNS STATIC C-STRING DESCRIBING CPU VENDOR *|
|*                  :         : AND VERSION INFO AT RUNTIME. SAME SIGNATURE   *|
|*                  :         : ON BOTH INTEL AND ARM BUILDS                  *|
|*..................:.........:...............................................*|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF DOES THAT DO?                           #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* THIS HEADER PROVIDES CPU VENDOR/ARCHITECTURE DETECTION AND A RUNTIME       *|
|* VERSION QUERY FUNCTION WITH A UNIFIED SIGNATURE ACROSS SUPPORTED CPUS.     *|
|*                                                                            *|
|* - AT COMPILE TIME, PREPROCESSOR CHECKS DETECT THE TARGET CPU ARCHITECTURE  *|
|*   (INTEL X86/X86-64, AMD X86, ARM/AARCH32/AARCH64, POWERPC, RISC-V, ETC.)  *|
|*   AND DEFINE THE CORRESPONDING __CPU_XXX__ MACRO.                          *|
|*                                                                            *|
|* - AT RUNTIME, __CPU_VER__() RETURNS A STATIC C-STRING CONTAINING THE CPU   *|
|*   VENDOR ID AND A SHORT MODEL/VERSION/STEPPING DESCRIPTION.                *|
|*                                                                            *|
|* - FOR X86-FAMILY CPUS, CPUID IS USED TO OBTAIN VENDOR AND VERSION FIELDS.  *|
|* - FOR ARM-FAMILY CPUS, MIDR_EL1 OR MIDR IS READ AND PARSED.                *|
|* - FOR OTHER ARCHITECTURES, SIMILAR NATIVE REGISTERS OR INSTRUCTIONS CAN    *|
|*   BE IMPLEMENTED IN THE SAME INTERFACE.                                    *|
|*                                                                            *|
|* PURPOSE: ALLOWS ANY CODEBASE TO GET A CONSISTENT CPU IDENTIFICATION STRING *|
|* WITHOUT LINKING EXTRA LIBRARIES, CALLING OS APIS, OR USING SPRINTF/PRINTF. *|
|*                                                                            *|
\******************************************************************************/

#ifndef CPU_H
#	define CPU_H 202511 /* VERSION */

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

/* ************************ [v] __CPU_AMD_X86__ [v] ************************* */
#	ifdef __amd64__ /* GNU C & SUN STUDIO */
#		define __CPU_AMD_X86__
#		define __CPU_INTEL__
#		define LOCALMACRO__CPU_FOUND
#	else
#		ifdef __amd64 /* GNU C & SUN STUDIO */
#			define __CPU_AMD_X86__
#			define __CPU_INTEL__
#			define LOCALMACRO__CPU_FOUND
#		else
#			ifdef _M_AMD64 /* VISUAL STUDIO */
#				define __CPU_AMD_X86__
#				define __CPU_INTEL__
#				define LOCALMACRO__CPU_FOUND
#			else
#				ifdef __x86_64__ /* GNU C & SUN STUDIO */
#					define __CPU_AMD_X86__
#					define __CPU_INTEL__
#					define LOCALMACRO__CPU_FOUND
#				else
#					ifdef __x86_64 /* GNU C & SUN STUDIO */
#						define __CPU_AMD_X86__
#						define __CPU_INTEL__
#						define LOCALMACRO__CPU_FOUND
#					endif /* __x86_64 */
#				endif /* __x86_64__ */
#			endif /* _M_AMD64 */
#		endif /* __amd64 */
#	endif /* __amd64__ */
/* ************************ [^] __CPU_AMD_X86__ [^] ************************* */

/* ************************* [v] __CPU_INTEL__ [v] ************************** */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __i386__
#			define __CPU_INTEL__
#			define LOCALMACRO__CPU_FOUND
#		else
#			ifdef _M_X64
#				define __CPU_INTEL__
#				define LOCALMACRO__CPU_FOUND
#			else
#				ifdef _M_IX86
#					define __CPU_INTEL__
#					define LOCALMACRO__CPU_FOUND
#				else
#					ifdef i386
#						define __CPU_INTEL__
#						define LOCALMACRO__CPU_FOUND
#					else
#						ifdef __i386
#							define __CPU_INTEL__
#							define LOCALMACRO__CPU_FOUND
#						else
#							ifdef __INTEL__
#								define __CPU_INTEL__
#								define LOCALMACRO__CPU_FOUND
#							else
#								ifdef __386
#									define __CPU_INTEL__
#									define LOCALMACRO__CPU_FOUND
#								else
#									ifdef __I86__
#										define __CPU_INTEL__
#										define LOCALMACRO__CPU_FOUND
#									endif /* __I86__ */
#								endif /* __386 */
#							endif /* __INTEL__ */
#						endif /* __i386 */
#					endif /* i386 */
#				endif /* _M_IX86 */
#			endif /* _M_X64 */
#		endif /* __i386__ */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* ************************* [^] __CPU_INTEL__ [^] ************************** */

/* ************************** [v] __CPU_ARM__ [v] *************************** */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __aarch64__
#			define __CPU_ARM__
#			define LOCALMACRO__CPU_FOUND
#		else
#			ifdef __arm__ /* GNU C & REALVIEW */
#				define __CPU_ARM__
#				define LOCALMACRO__CPU_FOUND
#			else
#				ifdef _M_ARM /* VISUAL STUDIO */
#					define __CPU_ARM__
#					define LOCALMACRO__CPU_FOUND
#				else
#					ifdef _M_ARM64
#						define __CPU_ARM__
#						define LOCALMACRO__CPU_FOUND
#					else
#						ifdef __arm /* DIAB */
#							define __CPU_ARM__
#							define LOCALMACRO__CPU_FOUND
#						endif /* __arm */
#					endif /* _M_ARM64 */
#				endif /* _M_ARM */
#			endif /* __arm__ */
#		endif /* __aarch64__ */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* ************************** [^] __CPU_ARM__ [^] *************************** */

/* ************************ [v] __CPU_POWERPC__ [v] ************************* */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __powerpc__
#			define __CPU_POWERPC__
#			define LOCALMACRO__CPU_FOUND
#		else
#			ifdef __ppc__
#				define __CPU_POWERPC__
#				define LOCALMACRO__CPU_FOUND
#			else
#				ifdef _M_PPC
#					define __CPU_POWERPC__
#					define LOCALMACRO__CPU_FOUND
#				endif /* _M_PPC */
#			endif /* __ppc__ */
#		endif /* __powerpc__ */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* ************************ [^] __CPU_POWERPC__ [^] ************************* */

/* ************************* [v] __CPU_RISCV__ [v] ************************** */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __riscv /* RISC-V CPU */
#			define __CPU_RISCV__
#			define LOCALMACRO__CPU_FOUND
#		endif /* __riscv */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* ************************* [^] __CPU_RISCV__ [^] ************************** */

/* ************************** [v] __CPU_HC12__ [v] ************************** */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __HC12__ /* FREESCALE / NXP (HC(S)12) */
#			define __CPU_HC12__
#			define LOCALMACRO__CPU_FOUND
#		endif /* __HC12__ */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* ************************** [^] __CPU_HC12__ [^] ************************** */

/* ************************* [v] __CPU_HCS08__ [v] ************************** */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __HCS08__ /* FREESCALE / HCS08 */
#			define __CPU_HCS08__
#			define LOCALMACRO__CPU_FOUND
#		endif /* __HCS08__ */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* ************************* [^] __CPU_HCS08__ [^] ************************** */

/* ************************ [v] __CPU_COLDFIRE__ [v] ************************ */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __COLDFIRE__ /* FREESCALE / COLDFIRE */
#			define __CPU_COLDFIRE__
#			define LOCALMACRO__CPU_FOUND
#		endif /* __COLDFIRE__ */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* ************************ [^] __CPU_COLDFIRE__ [^] ************************ */

/* ************************** [v] __CPU_M68K__ [v] ************************** */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __m68k__ /* GNU C */
#			define __CPU_M68K__
#			define LOCALMACRO__CPU_FOUND
#		else
#			ifdef M68000 /* SAS/C */
#				define __CPU_M68K__
#				define LOCALMACRO__CPU_FOUND
#			else
#				ifdef __MC68K__ /* STRATUS VOS C */
#					define __CPU_M68K__
#					define LOCALMACRO__CPU_FOUND
#				endif /* __MC68K__ */
#			endif /* M68000 */
#		endif /* __m68k__ */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* ************************** [^] __CPU_M68K__ [^] ************************** */

/* *************************** [v] __CPU_SH__ [v] *************************** */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __sh__ /* SUPERH (SEGA SATURN, DREAMCAST) */
#			define __CPU_SH__ // TODO
#			define LOCALMACRO__CPU_FOUND
#		endif /* __sh__ */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* *************************** [^] __CPU_SH__ [^] *************************** */

/* ************************** [v] __CPU_MIPS__ [v] ************************** */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __mips__ /* MIPS (PS1, N64, PSP, ANDROID) */
#			define __CPU_MIPS__
#			define LOCALMACRO__CPU_FOUND
#		else
#			ifdef __mips
#				define __CPU_MIPS__
#				define LOCALMACRO__CPU_FOUND
#			endif /* __mips */
#		endif /* __mips__ */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* ************************** [^] __CPU_MIPS__ [^] ************************** */

/* ************************* [v] __CPU_SPARC__ [v] ************************** */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __sparc__ /* SUN EMBEDED/CONSOLE EXPERIMENTS */
#			define __CPU_SPARC__
#			define LOCALMACRO__CPU_FOUND
#		endif /* __sparc__ */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* ************************* [^] __CPU_SPARC__ [^] ************************** */

/* ************************** [v] __CPU_6502__ [v] ************************** */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __CC65__ /* 6502 / 65C816 (NES, SNES, C64, APPLE II, ATARI) */
#			define __CPU_6502__
#			define LOCALMACRO__CPU_FOUND
#		endif /* __CC65__ */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* ************************** [^] __CPU_6502__ [^] ************************** */

/* ************************** [v] __CPU_Z80__ [v] *************************** */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __SDCC_z80 /* SDCC
			Z80 (SEGA MASTER SYSTEM, GAME GEAR, GB/GBC, ZX SPACTRUM, MSX)
		*/
#			define __CPU_Z80__
#			define LOCALMACRO__CPU_FOUND
#		else
#			ifdef __Z80__ /* Z88DK */
#				define __CPU_Z80__
#				define LOCALMACRO__CPU_FOUND
#			endif /* __Z80__ */
#		endif /* __SDCC_z80 */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* ************************** [^] __CPU_Z80__ [^] *************************** */

/* *************************** [v] __CPU_TI__ [v] *************************** */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __TI_COMPILER_VERSION__ /* TEXAS INSTRUMENTS COMPILER (TI-CGT) */
#			define __CPU_TI__
#			define LOCALMACRO__CPU_FOUND
#		endif /* __TI_COMPILER_VERSION__ */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* *************************** [^] __CPU_TI__ [^] *************************** */

/* ************************* [v] __CPU_SHARC__ [v] ************************** */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __ADSP21000__ /* DSP - ANALOG DEVICES: SHARC */
#			define __CPU_SHARC__
#			define LOCALMACRO__CPU_FOUND
#		endif /* __ADSP21000__ */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* ************************* [^] __CPU_SHARC__ [^] ************************** */

/* ************************ [v] __CPU_BLACKFIN__ [v] ************************ */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __bfin /* GNU C */
#			define __CPU_BLACKFIN__
#			define LOCALMACRO__CPU_FOUND
#		else
#			ifdef __BFIN__ /* GNU C */
#				define __CPU_BLACKFIN__
#				define LOCALMACRO__CPU_FOUND
#			else
#				ifdef __ADSPBLACKFIN__ /* DSP - ANALOG DEVICES: BLACKFIN */
#					define __CPU_BLACKFIN__
#					define LOCALMACRO__CPU_FOUND
#				endif /* __ADSPBLACKFIN__ */
#			endif /* __BFIN__ */
#		endif /* __bfin */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* ************************ [^] __CPU_BLACKFIN__ [^] ************************ */

/* ************************* [v] __CPU_DSP56K__ [v] ************************* */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __DSP56K__ /* DSP - MOTOROLA DSP56000 / DSP56300 */
#			define __CPU_DSP56K__
#			define LOCALMACRO__CPU_FOUND
#		endif /* __DSP56K__ */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* ************************* [^] __CPU_DSP56K__ [^] ************************* */

#	ifdef LOCALMACRO__CPU_FOUND
/* **************************** [v] INCLUDES [v] **************************** */
#		include "./KNR_STYLE.h" /*
#		 define KNR_STYLE
#		        */
#		include "../KEYWORDS/INLINE.h" /*
#		 define INLINE
#		        */
#		include "../CHECK_FEATURE/INLINE_ASM.h" /*
#		 define INLINE_ASM_TYPE__GNU
#		 define INLINE_ASM_TYPE__MSVC
#		 define INLINE_ASM_TYPE__BORLAND
#		 define INLINE_ASM_TYPE__AZTEC
#		 define INLINE_ASM_TYPE__LATTICE
#		 define INLINE_ASM_TYPE__INTEL_MS
#		 define INLINE_ASM_TYPE__WATCOM
#		 define INLINE_ASM_TYPE__ARM
#		 define INLINE_ASM_TYPE__KEIL
#		 define INLINE_ASM_TYPE__HCCF
#		 define INLINE_ASM_TYPE__ISO
#				*/
#		ifdef INLINE_ASM_TYPE__MSVC
#			include <intrin.h> /*
#			   void __cpuid(int [], int);
#			        */
#		endif /* INLINE_ASM_TYPE__MSVC */
/* **************************** [^] INCLUDES [^] **************************** */

/* ********************** [v] __CPU_VER__ | INTEL [v] *********************** */
#		ifdef __CPU_INTEL__
#			ifdef IS__INLINE_ASM__SUPPORTED
#				ifdef INLINE_ASM_TYPE__MSVC
#					define CPUID(LEAF, EAX, EBX, ECX, EDX) \
						{\
							int	REGS[4];\
							\
							__cpuid(REGS, (int)(LEAF));\
							(EAX) = REGS[0];\
							(EBX) = REGS[1];\
							(ECX) = REGS[2];\
							(EDX) = REGS[3];\
						}
#				endif /* INLINE_ASM_TYPE__MSVC */
#				ifdef INLINE_ASM_TYPE__GNU
#					ifdef __i386__ /* X86_32 */
#						ifdef __PIC__ /* POSITION-INDEPENDENT CODE */
#							define CPUID(LEAF, EAX, EBX, ECX, EDX) \
								asm("xchg{l} %%ebx, %1\n\t" \
									"cpuid\n\t" \
									"xchg{l} %%ebx, %1\n\t" \
									: \
										"=a"(EAX), \
										"=&r"(EBX), \
										"=c"(ECX), \
										"=d"(EDX) \
									: "a"(LEAF)\
								)
#						else
#							define CPUID(LEAF, EAX, EBX, ECX, EDX) \
								asm("cpuid" \
									: \
										"=a" (EAX), \
										"=b" (EBX), \
										"=c" (ECX), \
										"=d" (EDX) \
									: "a" (LEAF)\
								)
#						endif /* __PIC__ */
#					else /* X86_64 */
#						define CPUID(LEAF, EAX, EBX, ECX, EDX) \
							asm("cpuid" \
								: \
									"=a" (EAX), \
									"=b" (EBX), \
									"=c" (ECX), \
									"=d" (EDX) \
								: "a" (LEAF)\
							)
#					endif /* __i386__ */
#				endif /* INLINE_ASM_TYPE__GNU */
#				ifdef INLINE_ASM_TYPE__BORLAND
#					define CPUID(LEAF, EAX, EBX, ECX, EDX) \
						{\
							asm mov eax, LEAF;\
							asm cpuid;\
							asm mov EAX, eax;\
							asm mov EBX, ebx;\
							asm mov ECX, ecx;\
							asm mov EDX, edx;\
						}
#				endif /* INLINE_ASM_TYPE__BORLAND */
#				ifdef INLINE_ASM_TYPE__INTEL_MS
#					define CPUID(LEAF, EAX, EBX, ECX, EDX) \
						{\
							__asm mov eax, LEAF\
							__asm cpuid\
							__asm mov EAX, eax\
							__asm mov EBX, ebx\
							__asm mov ECX, ecx\
							__asm mov EDX, edx\
						}
#				endif /* INLINE_ASM_TYPE__INTEL_MS */
#				ifdef INLINE_ASM_TYPE__WATCOM
#					define CPUID(LEAF, EAX, EBX, ECX, EDX) \
						_asm {\
							mov eax, LEAF\
							cpuid\
							mov EAX, eax\
							mov EBX, ebx\
							mov ECX, ecx\
							mov EDX, edx\
						}
#				endif /* INLINE_ASM_TYPE__WATCOM */
#				ifdef INLINE_ASM_TYPE__AZTEC
#					define CPUID(LEAF, EAX, EBX, ECX, EDX) \
						asm {\
							mov eax, LEAF;\
							cpuid;\
							mov EAX, eax;\
							mov EBX, ebx;\
							mov ECX, ecx;\
							mov EDX, edx;\
						}
#				endif /* INLINE_ASM_TYPE__AZTEC */
#				ifdef INLINE_ASM_TYPE__ISO
#					ifdef __i386__
#						ifdef __PIC__ /* POSITION-INDEPENDENT CODE */
#							define CPUID(LEAF, EAX, EBX, ECX, EDX) \
								__asm__ __volatile__("xchg{l} %%ebx, %1\n\t" \
									"cpuid\n\t" \
									"xchg{l} %%ebx, %1\n\t" \
									: \
										"=a"(EAX), \
										"=&r"(EBX), \
										"=c"(ECX), \
										"=d"(EDX) \
									: "a"(LEAF)\
								)
#						else
#							define CPUID(LEAF, EAX, EBX, ECX, EDX) \
								__asm__ __volatile__("cpuid"\
									:\
										"=a" (EAX),\
										"=b" (EBX),\
										"=c" (ECX),\
										"=d" (EDX)\
									: "a" (LEAF)\
								)
#						endif /* __PIC__ */
#					else /* X86_64 */
#						define CPUID(LEAF, EAX, EBX, ECX, EDX) \
							__asm__ __volatile__("cpuid" \
								: \
									"=a" (EAX), \
									"=b" (EBX), \
									"=c" (ECX), \
									"=d" (EDX) \
								: "a" (LEAF)\
							)
#					endif /* __i386__ */
#				endif /* INLINE_ASM_TYPE__ISO */
#			else
#				define CPUID_AMD(LEAF, EAX, EBX, ECX, EDX) \
					EAX = 0;\
					EAX = 0;\
					ECX = 0;\
					EDX = 0;
#			endif /* IS__INLINE_ASM__SUPPORTED */
#			ifndef KNR_STYLE /* STANDARD C */
static INLINE const char
	*__CPU_VER__(void)
#			else /* K&R */
static INLINE char
	*__CPU_VER__()
#			endif /* !KNR_STYLE */
{
	static char				RESULT[32];
	register unsigned int	EAX;
	register unsigned int	EBX;
	register unsigned int	ECX;
	register unsigned int	EDX;

	CPUID(0, EAX, EBX, ECX, EDX);
	((unsigned int *)RESULT)[0] = EBX;
	((unsigned int *)RESULT)[1] = EDX;
	((unsigned int *)RESULT)[2] = ECX;
	CPUID(1, EAX, EBX, ECX, EDX);
	RESULT[12] = ' ';
	RESULT[13] = 'F';
	RESULT[14] = 'A';
	RESULT[15] = 'M';
	RESULT[16] = (char)('0' + ((EAX >> 8) & 0XF));
	RESULT[17] = '-';
	RESULT[18] = 'M';
	RESULT[19] = 'O';
	RESULT[20] = 'D';
	RESULT[21] = (char)('0' + ((EAX >> 4) & 0XF));
	RESULT[22] = '-';
	RESULT[23] = 'S';
	RESULT[24] = 'T';
	RESULT[25] = 'P';
	RESULT[26] = (char)('0' + (EAX & 0XF));
	RESULT[27] = 0;
	return (RESULT);
}
#		endif /* __CPU_INTEL__ */
/* ********************** [^] __CPU_VER__ | INTEL [^] *********************** */

/* *********************** [v] __CPU_VER__ | AMD [v] ************************ */
#		ifdef __CPU_ARM__
#			ifdef IS__INLINE_ASM__SUPPORTED
#				ifdef INLINE_ASM_TYPE__GNU
#					ifdef __aarch64__
#						ifndef KNR_STYLE /* STANDARD C */
static INLINE unsigned long long
	READ_MIDR_EL1(void)
#						else /* K&R */
static INLINE unsigned long long
	READ_MIDR_EL1()
#						endif /* !KNR_STYLE */
{
	unsigned long long	MIDR;

	__asm__ __volatile__("mrs %0, midr_el1" : "=r"(MIDR));
	return (MIDR);
}
#					else
#						ifndef KNR_STYLE /* STANDARD C */
static INLINE unsigned int
	READ_MIDR(void)
#						else /* K&R */
static INLINE unsigned int
	READ_MIDR()
#						endif /* !KNR_STYLE */
{
	unsigned int	MIDR;

	__asm__ __volatile__("mrc p15, 0, %0, c0, c0, 0" : "=r"(MIDR));
	return (MIDR);
}
#					endif /* __aarch64__ */
#				endif /* INLINE_ASM_TYPE__GNU */
#				ifdef INLINE_ASM_TYPE__ARM
#					ifdef __aarch64__
#						ifndef KNR_STYLE /* STANDARD C */
static INLINE unsigned long long
	READ_MIDR_EL1(void)
#						else /* K&R */
static INLINE unsigned long long
	READ_MIDR_EL1()
#						endif /* !KNR_STYLE */
{
	unsigned long long	MIDR;

	__asm("mrs %0, midr_el1" : "=r"(MIDR));
	return (MIDR);
}
#					else
#						ifndef KNR_STYLE /* STANDARD C */
static INLINE unsigned int
	READ_MIDR(void)
#						else /* K&R */
static INLINE unsigned int
	READ_MIDR()
#						endif /* !KNR_STYLE */
{
	unsigned int	MIDR;

	__asm("mrc p15, 0, %0, c0, c0, 0" : "=r"(MIDR));
	return (MIDR);
}
#					endif /* __aarch64__ */
#				endif /* INLINE_ASM_TYPE__ARM */
#				ifdef INLINE_ASM_TYPE__KEIL
#					ifdef __aarch64__
#						ifndef KNR_STYLE /* STANDARD C */
static INLINE unsigned long long
	READ_MIDR_EL1(void)
#						else /* K&R */
static INLINE unsigned long long
	READ_MIDR_EL1()
#						endif /* !KNR_STYLE */
{
	unsigned long long	MIDR;

	__asm {MRS midr, MIDR_EL1}
	return (MIDR);
}
#					else
#						ifndef KNR_STYLE /* STANDARD C */
static INLINE unsigned int
	READ_MIDR(void)
#						else /* K&R */
static INLINE unsigned int
	READ_MIDR()
#						endif /* !KNR_STYLE */
{
	unsigned int	MIDR;

	__asm {MRC p15, 0, MIDR, c0, c0, 0}
	return (MIDR);
}
#					endif /* __aarch64__ */
#				endif /* INLINE_ASM_TYPE__KEIL */
#				ifdef INLINE_ASM_TYPE__ISO
#					ifdef __aarch64__
#						ifndef KNR_STYLE /* STANDARD C */
static INLINE unsigned long long
	READ_MIDR_EL1(void)
#						else /* K&R */
static INLINE unsigned long long
	READ_MIDR_EL1()
#						endif /* !KNR_STYLE */
{
	unsigned long long	MIDR;

	__asm__ __volatile__("mrs %0, midr_el1" : "=r"(MIDR));
	return (MIDR);
}
#					else
#						ifndef KNR_STYLE /* STANDARD C */
static INLINE unsigned int
	READ_MIDR(void)
#						else /* K&R */
static INLINE unsigned int
	READ_MIDR()
#						endif /* !KNR_STYLE */
{
	unsigned int	MIDR;

	__asm__ __volatile__("mrc p15, 0, %0, c0, c0, 0" : "=r"(MIDR));
	return (MIDR);
}
#					endif /* __aarch64__ */
#				endif /* INLINE_ASM_TYPE__ISO */
#			else
#				ifndef KNR_STYLE /* STANDARD C */
static INLINE unsigned int
	READ_MIDR(void)
#				else /* K&R */
static INLINE unsigned int
	READ_MIDR()
#				endif /* !KNR_STYLE */
{
	return ((unsigned int)0);
}
#				ifndef KNR_STYLE /* STANDARD C */
static INLINE unsigned long long
	READ_MIDR_EL1(void)
#				else /* K&R */
static INLINE unsigned long long
	READ_MIDR_EL1()
#				endif /* !KNR_STYLE */
{
	return ((unsigned long long)0);
}
#			endif /* IS__INLINE_ASM__SUPPORTED */
#			ifndef KNR_STYLE /* STANDARD C */
static INLINE const char
	*__CPU_VER__(void)
#			else /* K&R */
static INLINE char
	*__CPU_VER__()
#			endif /* !KNR_STYLE */
{
	static char				RESULT[12];
	register unsigned int	IMPLEMENTER;
	register unsigned int	VARIANT;
	register unsigned int	ARCHITECTURE;
	register unsigned int	PARTNUM;
	register unsigned int	REVISION;

	{
#			ifdef __aarch64__
		const unsigned long long	MIDR = READ_MIDR_EL1();
#			else
		const unsigned int			MIDR = READ_MIDR();
#			endif

		IMPLEMENTER = (MIDR >> 24) & 0XFF;
		VARIANT = (MIDR >> 20) & 0XF;
		ARCHITECTURE = (MIDR >> 16) & 0XF;
		PARTNUM = (MIDR >> 4) & 0XFFF;
		REVISION = (MIDR >> 0) & 0XF;
	}

	RESULT[0] = (char)IMPLEMENTER; /* OR MAP TO ASCII IF NEEDED */
	RESULT[1] = '-';
	RESULT[2] = (char)('0' + VARIANT);
	RESULT[3] = '-';
	RESULT[4] = (char)('0' + ARCHITECTURE);
	RESULT[5] = '-';
	RESULT[6] = (char)('0' + ((PARTNUM >> 8) & 0XF));
	RESULT[7] = (char)('0' + ((PARTNUM >> 4) & 0XF));
	RESULT[8] = (char)('0' + (PARTNUM & 0XF));
	RESULT[9] = '-';
	RESULT[10] = (char)('0' + REVISION);
	RESULT[11] = 0;
	return (RESULT);
}
#		endif /* __CPU_ARM__ */
/* *********************** [^] __CPU_VER__ | AMD [^] ************************ */

/* ********************** [v] __CPU_VER__ | RISCV [v] *********************** */
#		ifdef __CPU_RISCV__
#			ifndef KNR_STYLE /* STANDARD C */
static INLINE const char
	*__CPU_VER__(void)
#			else /* K&R */
static INLINE char
	*__CPU_VER__()
#			endif /* !KNR_STYLE */
{
	static char	RESULT[9];

	RESULT[0] = 'R';
	RESULT[1] = 'I';
	RESULT[2] = 'S';
	RESULT[3] = 'C';
	RESULT[4] = '-';
	RESULT[5] = 'V';

#			ifdef __riscv_xlen
	if (__riscv_xlen == 32)
	{
		RESULT[6] = '3';
		RESULT[7] = '2';
		RESULT[8] = 0;
	}
	else if (__riscv_xlen == 64)
	{
		RESULT[6] = '6';
		RESULT[7] = '4';
		RESULT[8] = 0;
	}
	else
	{
		RESULT[6] = '?';
		RESULT[7] = '?';
		RESULT[8] = 0;
	}
#			else
	RESULT[6] = '?';
	RESULT[7] = '?';
	RESULT[8] = 0;
#			endif /* __riscv_xlen */

	return (RESULT);
}
#		endif /* __CPU_RISCV__ */
/* ********************** [^] __CPU_VER__ | RISCV [^] *********************** */

/* ********************* [v] __CPU_VER__ | POWERPC [v] ********************** */
#		ifdef __CPU_POWERPC__
#			ifdef IS__INLINE_ASM__SUPPORTED
#				ifdef INLINE_ASM_TYPE__GNU
#					ifndef KNR_STYLE /* STANDARD C */
static INLINE unsigned int
	READ_PVR(void)
#					else /* K&R */
static INLINE unsigned int
	READ_PVR()
#					endif /* !KNR_STYLE */
{
	unsigned int	PVR;

	__asm__ __volatile__("mfspr %0, 287" : "=r"(PVR)); /* 287 = PVR */
	return (PVR);
}
#				endif /* INLINE_ASM_TYPE__GNU */
#				ifdef INLINE_ASM_TYPE__ISO
#					ifndef KNR_STYLE /* STANDARD C */
static INLINE unsigned int
	READ_PVR(void)
#					else /* K&R */
static INLINE unsigned int
	READ_PVR()
#					endif /* !KNR_STYLE */
{
	unsigned int	PVR;

	__asm__ __volatile__("mfspr %0, 287" : "=r"(PVR)); /* 287 = PVR */
	return (PVR);
}
#				endif /* INLINE_ASM_TYPE__ISO */
#			else
#				error "POWERPC PVR - INLINE ASM NOT SUPPORTED"
#			endif /* IS__INLINE_ASM__SUPPORTED */
#			ifndef KNR_STYLE /* STANDARD C */
static INLINE const char
	*__CPU_VER__(void)
#			else /* K&R */
static INLINE char
	*__CPU_VER__()
#			endif /* !KNR_STYLE */
{
	static char				RESULT[14];
	register unsigned int	VERSION;
	register unsigned int	REVISION;

	{
		const unsigned int	PVR = READ_PVR();

		VERSION = (PVR >> 16) & 0XFFFF;
		REVISION = (PVR >> 0) & 0XFFFF;
	}

	RESULT[0] = 'P';
	RESULT[1] = 'P';
	RESULT[2] = 'C';
	RESULT[3] = '-';
	RESULT[4] = (char)('0' + ((VERSION >> 12) & 0XF));
	RESULT[5] = (char)('0' + ((VERSION >> 8) & 0XF));
	RESULT[6] = (char)('0' + ((VERSION >> 4) & 0XF));
	RESULT[7] = (char)('0' + (VERSION & 0XF));
	RESULT[8] = '-';
	RESULT[9] = (char)('0' + ((REVISION >> 12) & 0XF));
	RESULT[10] = (char)('0' + ((REVISION >> 8) & 0XF));
	RESULT[11] = (char)('0' + ((REVISION >> 4) & 0XF));
	RESULT[12] = (char)('0' + (REVISION & 0XF));
	RESULT[13] = 0;
	return (RESULT);
}
#		endif /* __CPU_POWERPC__ */
/* ********************* [^] __CPU_VER__ | POWERPC [^] ********************** */

/* *********************** [v] __CPU_VER__ | HCCF [v] *********************** */
#		ifdef INLINE_ASM_TYPE__HCCF
#			ifndef KNR_STYLE /* STANDARD C */
static INLINE const char
	*__CPU_VER__(void)
#			else /* K&R */
static INLINE char
	*__CPU_VER__()
#			endif /* !KNR_STYLE */
{
	static char	RESULT[9];

#			ifdef __CPU_HC12__
	RESULT[0] = 'H';
	RESULT[1] = 'C';
	RESULT[2] = '1';
	RESULT[3] = '2';
	RESULT[4] = 0;
#			else
#				ifdef __CPU_HCS08__
	RESULT[0] = 'H';
	RESULT[1] = 'C';
	RESULT[2] = 'S';
	RESULT[3] = '0';
	RESULT[4] = '8';
	RESULT[5] = 0;
#				else
#					ifdef __CPU_COLDFIRE__
	RESULT[0] = 'C';
	RESULT[1] = 'o';
	RESULT[2] = 'l';
	RESULT[3] = 'd';
	RESULT[4] = 'F';
	RESULT[5] = 'i';
	RESULT[6] = 'r';
	RESULT[7] = 'e';
	RESULT[8] = 0;
#					else
	RESULT[0] = 'H';
	RESULT[1] = 'C';
	RESULT[2] = '-';
	RESULT[3] = '?';
	RESULT[4] = '?';
	RESULT[5] = 0;
#					endif /* __CPU_COLDFIRE__ */
#				endif /* __CPU_HCS08__ */
#			endif /* __CPU_HC12__ */
	return (RESULT);
}
#		endif /* INLINE_ASM_TYPE__HCCF */
/* *********************** [^] __CPU_VER__ | HCCF [^] *********************** */

/* *********************** [v] __CPU_VER__ | M68K [v] *********************** */
#		ifdef __CPU_M68K__
#			ifndef KNR_STYLE /* STANDARD C */
static INLINE const char
	*__CPU_VER__(void)
#			else /* K&R */
static INLINE char
	*__CPU_VER__()
#			endif /* !KNR_STYLE */
{
	static char	RESULT[7];

	RESULT[0] = 'M';
	RESULT[1] = '6';
	RESULT[2] = '8';
	RESULT[3] = 'K';

#	ifdef __mc68000__
#		define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[4] = '0';
#	endif /* __mc68000__ */
#	ifndef LOCALMACRO__CPU_VERSION_FOUND
#		ifdef __MC68000__
#			define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[4] = '0';
#		endif /* __MC68000__ */
#	endif /* !LOCALMACRO__CPU_VERSION_FOUND */
#	ifndef LOCALMACRO__CPU_VERSION_FOUND
#		ifdef __mc68010__
#			define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[4] = '1';
#		endif /* __mc68010__ */
#	endif /* !LOCALMACRO__CPU_VERSION_FOUND */
#	ifndef LOCALMACRO__CPU_VERSION_FOUND
#		ifdef __mc68020__
#			define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[4] = '2';
#		endif /* __mc68020__ */
#	endif /* !LOCALMACRO__CPU_VERSION_FOUND */
#	ifndef LOCALMACRO__CPU_VERSION_FOUND
#		ifdef __MC68020__
#			define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[4] = '2';
#		endif /* __MC68020__ */
#	endif /* !LOCALMACRO__CPU_VERSION_FOUND */
#	ifndef LOCALMACRO__CPU_VERSION_FOUND
#		ifdef __mc68030__
#			define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[4] = '3';
#		endif /* __mc68030__ */
#	endif /* !LOCALMACRO__CPU_VERSION_FOUND */
#	ifndef LOCALMACRO__CPU_VERSION_FOUND
#		ifdef __MC68030__
#			define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[4] = '3';
#		endif /* __MC68030__ */
#	endif /* !LOCALMACRO__CPU_VERSION_FOUND */
#	ifndef LOCALMACRO__CPU_VERSION_FOUND
#		ifdef __mc68040__
#			define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[4] = '4';
#		endif /* __mc68040__ */
#	endif /* !LOCALMACRO__CPU_VERSION_FOUND */
#	ifndef LOCALMACRO__CPU_VERSION_FOUND
#		ifdef __mc68060__
#			define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[4] = '6';
#		endif /* __mc68060__ */
#	endif /* !LOCALMACRO__CPU_VERSION_FOUND */

#	ifdef LOCALMACRO__CPU_VERSION_FOUND
	RESULT[5] = '0';
#		undef LOCALMACRO__CPU_VERSION_FOUND
#	else
	RESULT[4] = '?';
	RESULT[5] = '?';
#	endif /* LOCALMACRO__CPU_VERSION_FOUND */

	RESULT[6] = 0;
	return (RESULT);
}
#		endif /* __CPU_M68K__ */
/* *********************** [^] __CPU_VER__ | M68K [^] *********************** */

/* ************************ [v] __CPU_VER__ | SH [v]************************* */
#		ifdef __CPU_SH__
#			ifndef KNR_STYLE /* STANDARD C */
static INLINE const char
	*__CPU_VER__(void)
#			else /* K&R */
static INLINE char
	*__CPU_VER__()
#			endif /* !KNR_STYLE */
{
	static char	RESULT[5];

	RESULT[0] = 'S';
	RESULT[1] = 'H';
	RESULT[2] = '-';
#			ifdef __sh1__
	RESULT[3] = '1';
#			else
#				ifdef __sh2__
	RESULT[3] = '2';
#				else
#					ifdef __sh3__
	RESULT[3] = '3';
#					else
#						ifdef __sh4__
	RESULT[3] = '4';
#						else
	RESULT[3] = 'X';
#						endif /* __sh4__ */
#					endif /* __sh3__ */
#				endif /* __sh2__ */
#			endif /* __sh1__ */
	RESULT[4] = 0;
	return (RESULT);
}
#		endif /* __CPU_SH__ */
/* ************************[^] __CPU_VER__ | SH [^] ************************* */

/* *********************** [v] __CPU_VER__ | MIPS [v] *********************** */
#		ifdef __CPU_MIPS__
#			ifndef KNR_STYLE /* STANDARD C */
static INLINE const char
	*__CPU_VER__(void)
#			else /* K&R */
static INLINE char
	*__CPU_VER__()
#			endif /* !KNR_STYLE */
{
	static char	RESULT[10];

	RESULT[0] = 'M';
	RESULT[1] = 'I';
	RESULT[2] = 'P';
	RESULT[3] = 'S';
#			ifdef _MIPS_ISA_MIPS1
	RESULT[4] = '-';
	RESULT[5] = 'I';
	RESULT[6] = 'S';
	RESULT[7] = 'A';
	RESULT[8] = '1';
	RESULT[9] = 0;
#			else
#				ifdef _MIPS_ISA_MIPS2
	RESULT[4] = '-';
	RESULT[5] = 'I';
	RESULT[6] = 'S';
	RESULT[7] = 'A';
	RESULT[8] = '2';
	RESULT[9] = 0;
#				else
#					ifdef _MIPS_ISA_MIPS3
	RESULT[4] = '-';
	RESULT[5] = 'I';
	RESULT[6] = 'S';
	RESULT[7] = 'A';
	RESULT[8] = '3';
	RESULT[9] = 0;
#					else
#						ifdef _MIPS_ISA_MIPS4
	RESULT[4] = '-';
	RESULT[5] = 'I';
	RESULT[6] = 'S';
	RESULT[7] = 'A';
	RESULT[8] = '4';
	RESULT[9] = 0;
#						else
#							ifdef _MIPS_ISA_MIPS32
	RESULT[4] = '3';
	RESULT[5] = '2';
	RESULT[6] = 0;
#							else
#								ifdef _MIPS_ISA_MIPS64
	RESULT[4] = '6';
	RESULT[5] = '4';
	RESULT[6] = 0;
#								else
	RESULT[4] = '-';
	RESULT[5] = 'X';
	RESULT[6] = 0;
#								endif /* _MIPS_ISA_MIPS64 */
#							endif /* _MIPS_ISA_MIPS32 */
#						endif /* _MIPS_ISA_MIPS4 */
#					endif /* _MIPS_ISA_MIPS3 */
#				endif /* _MIPS_ISA_MIPS2 */
#			endif /* _MIPS_ISA_MIPS1 */
	return (RESULT);
}
#		endif /* __CPU_MIPS__ */
/* *********************** [^] __CPU_VER__ | MIPS [^] *********************** */

/* ********************** [v] __CPU_VER__ | SPARC [v] *********************** */
#		ifdef __CPU_SPARC__
#			ifndef KNR_STYLE /* STANDARD C */
static INLINE const char
	*__CPU_VER__(void)
#			else /* K&R */
static INLINE char
	*__CPU_VER__()
#			endif /* !KNR_STYLE */
{
	static char	RESULT[8];

	RESULT[0] = 'S';
	RESULT[1] = 'P';
	RESULT[2] = 'A';
	RESULT[3] = 'R';
	RESULT[4] = 'C';
#			ifdef __sparcv8
	RESULT[5] = 'v';
	RESULT[6] = '8';
#			else
#				ifdef __sparcv9
	RESULT[5] = 'v';
	RESULT[6] = '9';
#				else
#					ifdef __sparc_v9__
	RESULT[5] = 'v';
	RESULT[6] = '9';
#					else
	RESULT[5] = '-';
	RESULT[6] = 'X';
#					endif /* __sparc_v9__ */
#				endif /* __sparcv9 */
#			endif /* __sparcv8 */
	RESULT[7] = 0;
	return (RESULT);
}
#		endif /* __CPU_SPARC__ */
/* ********************** [^] __CPU_VER__ | SPARC [^] *********************** */

/* *********************** [v] __CPU_VER__ | 6502 [v] *********************** */
#		ifdef __CPU_6502__
#			ifndef KNR_STYLE /* STANDARD C */
static INLINE const char
	*__CPU_VER__(void)
#			else /* K&R */
static INLINE char
	*__CPU_VER__()
#			endif /* !KNR_STYLE */
{
	static char	RESULT[7];

	RESULT[0] = '6';
	RESULT[1] = '5';
#			ifdef __65C02__
	RESULT[2] = 'C';
	RESULT[3] = '0';
	RESULT[4] = '2';
	RESULT[5] = 0;
#			else
#				ifdef __65SC02__
	RESULT[2] = 'S';
	RESULT[3] = 'C';
	RESULT[4] = '0';
	RESULT[5] = '2';
	RESULT[6] = 0;
#				else
#					ifdef __65816__
	RESULT[2] = '8';
	RESULT[3] = '1';
	RESULT[4] = '6';
	RESULT[5] = 0;
#					else /* PROBABLY */
	RESULT[2] = '0';
	RESULT[3] = '2';
	RESULT[4] = 0;
#					endif /* __65816__ */
#				endif /* __65SC02__ */
#			endif /* __65C02__ */
	return (RESULT);
}
#		endif /* __CPU_6502__ */
/* *********************** [^] __CPU_VER__ | 6502 [^] *********************** */

/* *********************** [v] __CPU_VER__ | Z80 [v] ************************ */
#		ifdef __CPU_Z80__
#			ifndef KNR_STYLE /* STANDARD C */
static INLINE const char
	*__CPU_VER__(void)
#			else /* K&R */
static INLINE char
	*__CPU_VER__()
#			endif /* !KNR_STYLE */
{
	static char	RESULT[8];

	RESULT[0] = 'Z';
	RESULT[1] = '8';
	RESULT[2] = '0';
#			ifdef __RABBIT
	RESULT[3] = 'R';
	RESULT[4] = 0;
#			else
#				ifdef __GBZ80__
	RESULT[3] = 'G';
	RESULT[4] = 'B';
	RESULT[5] = 0;
#				else
	RESULT[3] = 0;
#				endif /* __GBZ80__ */
#			endif /* __RABBIT */
	return (RESULT);
}
#		endif /* __CPU_Z80__ */
/* *********************** [^] __CPU_VER__ | Z80 [^] ************************ */

/* ************************ [v] __CPU_VER__ | TI [v] ************************ */
#		ifdef __CPU_TI__
#			ifndef KNR_STYLE /* STANDARD C */
static INLINE const char
	*__CPU_VER__(void)
#			else /* K&R */
static INLINE char
	*__CPU_VER__()
#			endif /* !KNR_STYLE */
{
	static char	RESULT[10];

	RESULT[0] = 'T';
	RESULT[1] = 'I';
	RESULT[2] = '-';
#			ifdef __MSP430__ /* TI-MSP430 MICROCONTROLLERS */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'M';
	RESULT[4] = 'S';
	RESULT[5] = 'P';
	RESULT[6] = '4';
	RESULT[7] = '3';
	RESULT[8] = '0';
	RESULT[9] = 0;
#			endif /* __MSP430__ */
#			ifdef __TMS320C55X__ /* TI-CGT C5000 SERIES */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'C';
	RESULT[4] = '5';
	RESULT[5] = '5';
	RESULT[6] = 'X';
	RESULT[7] = 0;
#			endif /* __TMS320C55X__ */
#			ifdef TMS320C55X /* TI-CGT C55X SERIES */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'C';
	RESULT[4] = '5';
	RESULT[5] = '5';
	RESULT[6] = 'X';
	RESULT[7] = 0;
#			endif /* TMS320C55X */
#			ifdef __TMS320C28XX__ /* TI-CGT C2000 SERIES: C28X CORE */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'C';
	RESULT[4] = '2';
	RESULT[5] = '8';
	RESULT[6] = 'X';
	RESULT[7] = 'X';
	RESULT[8] = 0;
#			endif /* __TMS320C28XX__ */
#			ifdef _TMS320C28X /* TI-CGT C28XX SERIES */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'C';
	RESULT[4] = '2';
	RESULT[5] = '8';
	RESULT[6] = 'X';
	RESULT[7] = 'X';
	RESULT[8] = 0;
#			endif /* _TMS320C28X */
#			ifdef __TMS320C2000__ /* TI-CGT C2000 SERIES */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'C';
	RESULT[4] = '2';
	RESULT[5] = '0';
	RESULT[6] = '0';
	RESULT[7] = '0';
	RESULT[8] = 0;
#			endif /* __TMS320C2000__ */
#			ifdef _TMS320C2XX /* TI-CGT C2000 SERIES */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'C';
	RESULT[4] = '2';
	RESULT[5] = '0';
	RESULT[6] = '0';
	RESULT[7] = '0';
	RESULT[8] = 0;
#			endif /* _TMS320C2XX */
#			ifdef __TMS320C6X__ /* TI-CGT C6000 SERIES */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'C';
	RESULT[4] = '6';
	RESULT[5] = 'X';
	RESULT[6] = 0;
#			endif /* __TMS320C6X__ */
#			ifdef _TMS320C6X /* TI-CGT C6000 SERIES */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'C';
	RESULT[4] = '6';
	RESULT[5] = 'X';
	RESULT[6] = 0;
#			endif /* _TMS320C6X */
#			ifdef _TMS320C6740 /* TI-CGT C6740 SERIES */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'C';
	RESULT[4] = '6';
	RESULT[5] = '7';
	RESULT[6] = '4';
	RESULT[7] = '0';
	RESULT[8] = 0;
#			endif /* _TMS320C6740 */
#			ifdef _TMS320C6700_PLUS /* TI-CGT C6700+ SERIES */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'C';
	RESULT[4] = '6';
	RESULT[5] = '7';
	RESULT[6] = '+';
	RESULT[7] = 0;
#			endif /* _TMS320C6700_PLUS */
#			ifdef _TMS320C67_PLUS /* TI-CGT C6700+ SERIES */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'C';
	RESULT[4] = '6';
	RESULT[5] = '7';
	RESULT[6] = '+';
	RESULT[7] = 0;
#			endif /* _TMS320C67_PLUS */
#			ifdef _TMS320C6700 /* TI-CGT C6700 SERIES */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'C';
	RESULT[4] = '6';
	RESULT[5] = '7';
	RESULT[6] = '0';
	RESULT[7] = '0';
	RESULT[8] = 0;
#			endif /* _TMS320C6700 */
#			ifdef _TMS320C6600 /* TM C6600 CPU */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'C';
	RESULT[4] = '6';
	RESULT[5] = '6';
	RESULT[6] = '0';
	RESULT[7] = '0';
	RESULT[8] = 0;
#			endif /* _TMS320C6600 */
#			ifdef _TMS320C6400_PLUS /* TI-CGT C6400+ SERIES */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'C';
	RESULT[4] = '6';
	RESULT[5] = '4';
	RESULT[6] = '+';
	RESULT[7] = 0;
#			endif /* _TMS320C6400_PLUS */
#			ifdef _TMS320C64_PLUS /* TI-CGT C6400+ SERIES */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'C';
	RESULT[4] = '6';
	RESULT[5] = '4';
	RESULT[6] = '+';
	RESULT[7] = 0;
#			endif /* _TMS320C64_PLUS */
#			ifdef _TMS320C6400 /* TI-CGT C6400 SERIES */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'C';
	RESULT[4] = '6';
	RESULT[5] = '4';
	RESULT[6] = '0';
	RESULT[7] = '0';
	RESULT[8] = 0;
#			endif /* _TMS320C6400 */
#			ifdef _TMS320C6200 /* TI-CGT C6200 SERIES */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'C';
	RESULT[4] = '6';
	RESULT[5] = '2';
	RESULT[6] = '0';
	RESULT[7] = '0';
	RESULT[8] = 0;
#			endif /* _TMS320C6200 */
#			ifdef _TMS320C5XX /* TI-CGT C54X SERIES */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'C';
	RESULT[4] = '5';
	RESULT[5] = 'X';
	RESULT[6] = 'X';
	RESULT[7] = 0;
#			endif /* _TMS320C6200 */
#			ifdef _TMS320C5X /* TI-CGT C5000 SERIES */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'C';
	RESULT[4] = '5';
	RESULT[5] = 'X';
	RESULT[6] = 0;
#			endif /* _TMS320C5X */
#			ifdef __TMS470__ /* TMS470 G4 CPU */
#				define LOCALMACRO__CPU_VERSION_FOUND
	RESULT[3] = 'T';
	RESULT[4] = 'M';
	RESULT[5] = 'S';
	RESULT[6] = '4';
	RESULT[7] = '7';
	RESULT[8] = '0';
	RESULT[9] = 0;
#			endif /* __TMS470__ */
#			ifdef LOCALMACRO__CPU_VERSION_FOUND
#				undef LOCALMACRO__CPU_VERSION_FOUND
#			else
	RESULT[3] = 'U';
	RESULT[4] = 'N';
	RESULT[5] = 'K';
	RESULT[6] = 0;
#			endif /* LOCALMACRO__CPU_VERSION_FOUND */
	return (RESULT);
}
#		endif /* __CPU_TI__ */
/* ************************ [^] __CPU_VER__ | TI [^] ************************ */

/* ********************** [v] __CPU_VER__ | SHARC [v] *********************** */
#		ifdef __CPU_SHARC__
#			ifndef KNR_STYLE /* STANDARD C */
static INLINE const char
	*__CPU_VER__(void)
#			else /* K&R */
static INLINE char
	*__CPU_VER__()
#			endif /* !KNR_STYLE */
{
	static char	RESULT[11];

	RESULT[0] = 'A';
	RESULT[1] = 'D';
	RESULT[2] = 'S';
	RESULT[3] = 'P';
	RESULT[4] = '-';
	RESULT[5] = 'S';
	RESULT[6] = 'H';
	RESULT[7] = 'A';
	RESULT[8] = 'R';
	RESULT[9] = 'C';
	RESULT[10] = 0;
	return (RESULT);
}
#		endif /* __CPU_SHARC__ */
/* ********************** [^] __CPU_VER__ | SHARC [^] *********************** */

/* ********************* [v] __CPU_VER__ | BLACKFIN [v] ********************* */
#		ifdef __CPU_BLACKFIN__
#			ifndef KNR_STYLE /* STANDARD C */
static INLINE const char
	*__CPU_VER__(void)
#			else /* K&R */
static INLINE char
	*__CPU_VER__()
#			endif /* !KNR_STYLE */
{
	static char	RESULT[14];

	RESULT[0] = 'A';
	RESULT[1] = 'D';
	RESULT[2] = 'S';
	RESULT[3] = 'P';
	RESULT[4] = '-';
	RESULT[5] = 'B';
	RESULT[6] = 'L';
	RESULT[7] = 'A';
	RESULT[8] = 'C';
	RESULT[9] = 'K';
	RESULT[10] = 'F';
	RESULT[11] = 'I';
	RESULT[12] = 'N';
	RESULT[13] = 0;
	return (RESULT);
}
#		endif /* __CPU_BLACKFIN__ */
/* ********************* [^] __CPU_VER__ | BLACKFIN [^] ********************* */

/* ********************** [v] __CPU_VER__ | DSP56K [v] ********************** */
#		ifdef __CPU_DSP56K__
#			ifndef KNR_STYLE /* STANDARD C */
static INLINE const char
	*__CPU_VER__(void)
#			else /* K&R */
static INLINE char
	*__CPU_VER__()
#			endif /* !KNR_STYLE */
{
	static char	RESULT[12];

	RESULT[0] = 'M';
	RESULT[1] = 'O';
	RESULT[2] = 'T';
	RESULT[3] = '-';
	RESULT[4] = 'D';
	RESULT[5] = 'S';
	RESULT[6] = 'P';
	RESULT[7] = '5';
	RESULT[8] = '6';
	RESULT[9] = 'K';
	RESULT[10] = 0;
	return (RESULT);
}
#		endif /* __CPU_DSP56K__ */
/* ********************** [^] __CPU_VER__ | DSP56K [^] ********************** */
#		undef LOCALMACRO__CPU_FOUND
#	else
#		ifndef KNR_STYLE /* STANDARD C */
static INLINE const char
	*__CPU_VER__(void)
#		else /* K&R */
static INLINE char
	*__CPU_VER__()
#		endif /* !KNR_STYLE */
{
	static char	RESULT[12];

	RESULT[0] = 'U';
	RESULT[1] = 'N';
	RESULT[2] = 'K';
	RESULT[3] = 'N';
	RESULT[4] = 'O';
	RESULT[5] = 'W';
	RESULT[6] = 'N';
	RESULT[7] = ' ';
	RESULT[8] = 'C';
	RESULT[9] = 'P';
	RESULT[10] = 'U';
	RESULT[11] = 0;
	return (RESULT);
}
#	endif /* LOCALMACRO__CPU_FOUND */

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

#endif /* !CPU_H */

#ifdef __EOF__
#	undef __EOF__
#endif /* __EOF__ */
#define __EOF__ //  <- FOR DOS, CP/M, ETC
