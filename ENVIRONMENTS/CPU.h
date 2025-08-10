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
# : License - AGPL-3.0  :: Update - 2025/08/10 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/******************************************************************************\
|*                                  CONTENTS                                  *|
|******************************************************************************|
|*............................................................................*|
|*      NAME       :   TYPE  :                  DESCRIPTION                   *|
|*.................:.........:................................................*|
|* __CPU_INTEL__   : #define : DEFINED IF THE TARGET CPU IS INTEL CPU         *|
|*                 :         : (X86/X86-64)                                   *|
|*.................:.........:................................................*|
|* __CPU_AMD__     : #define : DEFINED IF THE TARGET CPU IS ARM-BASED CPU     *|
|*                 :         : (AARCH32/AARCH64)                              *|
|*.................:.........:................................................*|
|* __CPU_AMD_X86__ : #define : DEFINED IF THE TARGET CPU IS ARM-X86 CPU       *|
|*                 :         :                                                *|
|*.................:.........:................................................*|
|* __CPU_POWERPC__ : #define : DEFINED IF THE TARGET CPU IS IBM-POWERPC CPU   *|
|*                 :         :                                                *|
|*.................:.........:................................................*|
|* __CPU_RISCV__   : #define : DEFINED IF THE TARGET CPU IS RISC-V CPU        *|
|*                 :         :                                                *|
|*.................:.........:................................................*|
|* __CPU_VER__     : (*F)()  : RETURNS STATIC C-STRING DESCRIBING CPU VENDOR  *|
|*                 :         : AND VERSION INFO AT RUNTIME. SAME SIGNATURE ON *|
|*                 :         : BOTH INTEL AND ARM BUILDS                      *|
|*.................:.........:................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF DOES THAT DO?                           #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
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
#	define CPU_H 202508 /* VERSION */

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

/* ************************* [v] __CPU_INTEL__ [v] ************************** */
#	ifdef __x86_64__
#		define __CPU_INTEL__
#		define LOCALMACRO__CPU_FOUND
#	else
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
#				endif /* _M_IX86 */
#			endif /* _M_X64 */
#		endif /* __i386__ */
#	endif /* __x86_64__ */
/* ************************* [^] __CPU_INTEL__ [^] ************************** */

/* ************************** [v] __CPU_AMD__ [v] *************************** */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __aarch64__
#			define __CPU_AMD__
#			define LOCALMACRO__CPU_FOUND
#		else
#			ifdef __arm__
#				define __CPU_AMD__
#				define LOCALMACRO__CPU_FOUND
#			else
#				ifdef _M_ARM
#					define __CPU_AMD__
#					define LOCALMACRO__CPU_FOUND
#				else
#					ifdef _M_ARM64
#						define __CPU_AMD__
#						define LOCALMACRO__CPU_FOUND
#					endif /* _M_ARM64 */
#				endif /* _M_ARM */
#			endif /* __arm__ */
#		endif /* __aarch64__ */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* ************************** [^] __CPU_AMD__ [^] *************************** */

/* ************************ [v] __CPU_AMD_X86__ [v] ************************* */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __amd64__
#			define __CPU_AMD_X86__
#			define LOCALMACRO__CPU_FOUND
#		else
#			ifdef __x86_64__
#				define __CPU_AMD_X86__
#				define LOCALMACRO__CPU_FOUND  //////////  TODO
#			else
#				ifdef _M_AMD64
#					define __CPU_AMD_X86__
#					define LOCALMACRO__CPU_FOUND
#				endif /* _M_AMD64 */
#			endif /* __x86_64__ */
#		endif /* __amd64__ */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* ************************ [^] __CPU_AMD_X86__ [^] ************************* */

/* ************************ [v] __CPU_POWERPC__ [v] ************************* */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __powerpc__
#			define __CPU_POWERPC__
#			define LOCALMACRO__CPU_FOUND
#		else
#			ifdef __ppc__
#				define __CPU_POWERPC__
#				define LOCALMACRO__CPU_FOUND  //////////  TODO
#			else
#				ifdef _M_PPC
#					define __CPU_POWERPC__
#					define LOCALMACRO__CPU_FOUND
#				endif /* _M_PPC */
#			endif /* __ppc__ */
#		endif /*  */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* ************************ [^] __CPU_POWERPC__ [^] ************************* */

/* ************************* [v] __CPU_RISCV__ [v] ************************** */
#	ifndef LOCALMACRO__CPU_FOUND
#		ifdef __riscv /* RISC-V CPU */
#			define __CPU_RISCV__
#			define LOCALMACRO__CPU_FOUND  //////////  TODO
#		endif /* __riscv */
#	endif /* !LOCALMACRO__CPU_FOUND */
/* ************************* [^] __CPU_RISCV__ [^] ************************** */

/* ********************** [v] __CPU_VER__ | INTEL [v] *********************** */
#	ifdef __CPU_INTEL__

/* **************************** [v] INCLUDES [v] **************************** */
#		include "../CHECK_FEATURE/INLINE_ASM.h" /*
#				*/
/* **************************** [^] INCLUDES [^] **************************** */

#		ifdef IS__INLINE_ASM__SUPPORTED
#			ifdef INLINE_ASM_TYPE__MSVC
/* **************************** [v] INCLUDES [v] **************************** */
#				include <intrin.h> /*
#				   void __cpuid(int [], int);
#				        */
/* **************************** [^] INCLUDES [^] **************************** */
#				define CPUID(LEAF, EAX, EBX, ECX, EDX) \
					{\
						int	REGS[4]; \
						\
						__cpuid(REGS, (int)(LEAF)); \
						(EAX) = REGS[0]; \
						(EBX) = REGS[1]; \
						(ECX) = REGS[2]; \
						(EDX) = REGS[3]; \
					}
#			endif /* INLINE_ASM_TYPE__MSVC */
#			ifdef INLINE_ASM_TYPE__GNU
#				ifdef __i386__
#					ifdef __PIC__ /* POSITION-INDEPENDENT CODE */
#						define CPUID(LEAF, EAX, EBX, ECX, EDX) \
							asm("xchg{l} %%ebx, %1\n\t" \
								"cpuid\n\t" \
								"xchg{l} %%ebx, %1\n\t" \
								: "=a"(EAX), "=&r"(EBX), "=c"(ECX), "=d"(EDX) \
								: "a"(LEAF)\
							)
#					else
#						define CPUID(LEAF, EAX, EBX, ECX, EDX) \
							asm("cpuid" \
								: \
									"=a" (EAX), \
									"=b" (EBX), \
									"=c" (ECX), \
									"=d" (EDX) \
								: "a" (LEAF)\
							)
#					endif /* __PIC__ */
#				else /* X86_64 */
#					define CPUID(LEAF, EAX, EBX, ECX, EDX) \
						asm("cpuid" \
							: "=a" (EAX), "=b" (EBX), "=c" (ECX), "=d" (EDX) \
							: "a" (LEAF)\
						)
#				endif /* __i386__ */
#			endif /* INLINE_ASM_TYPE__GNU */
#			ifdef INLINE_ASM_TYPE__BORLAND
#				define CPUID(LEAF, EAX, EBX, ECX, EDX) \
					{\
						asm mov eax, LEAF; \
						asm cpuid; \
						asm mov EAX, eax; \
						asm mov EBX, ebx; \
						asm mov ECX, ecx; \
						asm mov EDX, edx; \
					}
#			endif /* INLINE_ASM_TYPE__BORLAND */
#			ifdef INLINE_ASM_TYPE__INTEL_MS
#				define CPUID(LEAF, EAX, EBX, ECX, EDX) \
					{\
						__asm mov eax, LEAF \
						__asm cpuid \
						__asm mov EAX, eax \
						__asm mov EBX, ebx \
						__asm mov ECX, ecx \
						__asm mov EDX, edx \
					}
#			endif /* INLINE_ASM_TYPE__INTEL_MS */
#			ifdef INLINE_ASM_TYPE__WATCOM
#				define CPUID(LEAF, EAX, EBX, ECX, EDX) \
					_asm {\
						mov eax, LEAF \
						cpuid \
						mov EAX, eax \
						mov EBX, ebx \
						mov ECX, ecx \
						mov EDX, edx \
					}
#			endif /* INLINE_ASM_TYPE__WATCOM */
#			ifdef INLINE_ASM_TYPE__AZTEC
#				define CPUID(LEAF, EAX, EBX, ECX, EDX) \
					asm {\
						mov eax, LEAF; \
						cpuid; \
						mov EAX, eax; \
						mov EBX, ebx; \
						mov ECX, ecx; \
						mov EDX, edx; \
					}
#			endif /* INLINE_ASM_TYPE__AZTEC */
#		else
#			error "CPUID - INLINE ASM NOT SUPPORTED"
#		endif /* IS__INLINE_ASM__SUPPORTED */

static inline const char
	*__CPU_VER__(void)
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
#	endif /* __CPU_INTEL__ */
/* ********************** [^] __CPU_VER__ | INTEL [^] *********************** */

/* *********************** [v] __CPU_VER__ | AMD [v] ************************ */
#	ifdef __CPU_AMD__
static inline const char
	*__CPU_VER__(void)
{
	static char				RESULT[32];
	register unsigned int	IMPLEMENTER;
	register unsigned int	VARIANT;
	register unsigned int	ARCHITECTURE;
	register unsigned int	PARTNUM;
	register unsigned int	REVISION;

	{
#		ifdef __aarch64__
		const unsigned long long	MIDR = read_midr_el1();
#		else
		const unsigned int			MIDR = read_midr();
#		endif
		IMPLEMENTER  = (MIDR >> 24) & 0XFF;
		VARIANT      = (MIDR >> 20) & 0XF;
		ARCHITECTURE = (MIDR >> 16) & 0XF;
		PARTNUM      = (MIDR >> 4) & 0XFFF;
		REVISION     = (MIDR >> 0) & 0XF;
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
#	endif /* __CPU_AMD__ */
/* *********************** [^] __CPU_VER__ | AMD [^] ************************ */

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
