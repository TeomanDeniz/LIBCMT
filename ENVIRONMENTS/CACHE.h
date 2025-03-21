/******************************************************************************\
# H - CACHE                                      #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2023/07/12 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - AGPL-3.0  :: Update - 2025/03/16 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/******************************************************************************\
|*                                  CONTENTS                                  *|
|******************************************************************************|
|*............................................................................*|
|*       NAME      :   TYPE  :                   DESCRIPTION                  *|
|*.................:.........:................................................*|
|* __CACHE_BYTES__ : #define : INDICATES HOW MANY BYTES THE ARCHITECTURE      *|
|*                 :         : OF THE DEVICE OR COMPILER USES.                *|
|*.................:.........:................................................*|
|* L1_CACHE_BYTES  : #define : INDICATES HOW MANY BITS THE ARCHITECTURE OF    *|
|*                 :         : THE DEVICE OR COMPILER USES.                   *|
|*.................:.........:................................................*|
|* L1_CACHE_SHIFT  : #define : INDICATES THE NUMBER OF BIT SHIFTS IN THE      *|
|*                 :         : ARCHITECTURE OF THE DEVICE OR COMPILER.        *|
|*.................:.........:................................................*|
|* CACHE_LINE_MASK : #define : NEGATIVE VERSION OF (L1_CACHE_BYTES).          *|
|*.................:.........:................................................*|
|* SMP_CACHE_BYTES : #define : FOR SYMMETRIC MULTIPROCESSING SYSTEMS (SMP),   *|
|*                 :         : SAME AS (L1_CACHE_BYTES).                      *|
|*.................:.........:................................................*|
|* SMP_CACHE_SHIFT : #define : FOR SYMMETRIC MULTIPROCESSING SYSTEMS (SMP),   *|
|*                 :         : SAME AS (L1_CACHE_SHIFT).                      *|
|*.................:.........:................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF DOES THAT DO?                           #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|* THESE DEFINES SHOW YOU HOW MANY BITS THE ARCHITECTURE USES.                *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                                SIDE NOTES                                #*|
|*############################################################################*|
|*                                                                            *|
|* FOR THE LINUX CACHE.H LIBRARY, I PREFER USING THE OLD VERSION OF THE       *|
|* [__read_mostly] DEFINE. I AM USING v2.6.27-rc2 -> v4.7.10 TO MAKE IT WORK  *|
|* ON OLDER VERSIONS AS WELL.                                                 *|
|*                                                                            *|
|* ADDED THE [__ro_after_init] DEFINITION, WHICH WAS REMOVED IN NEWER         *|
|* VERSIONS.                                                                  *|
|*                                                                            *|
\******************************************************************************/

/* ************************* [v] VERSION CONTROL [v] ************************ */
#ifdef CACHE_H
#	if (CACHE_H < 202503)
#		undef CACHE_H /* OLD VERSION DETECTED */
#	endif /* CACHE_H < {LIBRARY_VERSION} */
#endif /* CACHE_H */
/* ************************* [^] VERSION CONTROL [^] ************************ */

#ifndef CACHE_H
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_push /* TI CGT CCS COMPILER DIRECTIVES */
#		pragma CHECK_MISRA("-5.4") /* TAG NAMES SHALL BE A UNIQUE IDENTIFIER */
#		pragma CHECK_MISRA("-19.3") /* THE #INCLUDE DIRECTIVE SHALL BE FOLLOWED
#		BY EITHER A <FILENAME> OR "FILENAME" SEQUENCE */
#	endif /* __TI_COMPILER_VERSION__ */

#	ifdef __cplusplus /* C++ */
		extern "C" {
#	endif /* __cplusplus */

#	define CACHE_H 202503 /* VERSION */

/* ****************************** [v] RESET [v] ***************************** */
#	undef __CACHE_BYTES__
#	undef CACHE_LINE_MASK
#	undef L1_CACHE_BYTES
#	undef L1_CACHE_SHIFT
#	undef SMP_CACHE_BYTES
/* ****************************** [^] RESET [^] ***************************** */

#	if (defined(CONFIG_ARC_CACHE_LINE_SHIFT) || defined(CONFIG_L1_CACHE_SHIFT))
#		ifdef CONFIG_ARC_CACHE_LINE_SHIFT
#			define L1_CACHE_SHIFT CONFIG_ARC_CACHE_LINE_SHIFT /* ARC STANDARD */
#		else /* CONFIG_L1_CACHE_SHIFT */
#			define L1_CACHE_SHIFT CONFIG_L1_CACHE_SHIFT /* LINUX STANDARD */
#		endif /* CONFIG_ARC_CACHE_LINE_SHIFT */
#		define L1_CACHE_BYTES (1 << L1_CACHE_SHIFT) /* BITS (AUTOMATIC) */
#		define __CACHE_BYTES__ (L1_CACHE_BYTES / 8) /* BYTES (AUTOMATIC) */
#		define CACHE_LINE_MASK (~(L1_CACHE_BYTES - 1)) /* - MASK (AUTOMATIC) */
#		define SMP_CACHE_BYTES L1_CACHE_BYTES /* SAMPLE (AUTOMATIC) */
#		define SMP_CACHE_SHIFT L1_CACHE_SHIFT /* SAMPLE */
#	else /* 8 BIT */ // SORRY BUT WHY?
#		if (\
			defined(__SCCZ80) || /* SMALL DEVICE C COMPILER ZILOG Z80 */\
			defined(__STM8__) || /* EXPERIMENTAL SUPPORT IN SDCC */\
			defined(__Z80__) || /* ZILOG Z80 */\
			defined(__8051__) || /* 8051 MICROCONTROLLER */\
			defined(__MCS51__) || /* 8051 MICROCONTROLLER */\
			defined(__68HC08__) || /* MOTOROLA 68HC08 */\
			defined(__PIC24F__) || /* PIC FAMILY MICROCONTROLLERS */ \
			(\
				defined(__XC8__) || /* PIC XC COMPILER */\
				defined(__18CXX) || /* PIC18 SERIES */\
				defined(__XC8) /* PIC XC COMPILER */\
			)\
		)
#			define L1_CACHE_SHIFT 3 /* 2^3 8 BIT */
#			define L1_CACHE_BYTES 8 /* BITS */
#			define CACHE_LINE_MASK -8 /* - MASK */
#			define SMP_CACHE_BYTES 8 /* SAMPLE */
#			define SMP_CACHE_SHIFT 3 /* SAMPLE */
#			define __CACHE_BYTES__ 1 /* BYTE */ // (PROBABLY???)
#		else /* 16 BIT */
#			if (\
				defined(__RL78__) || /* RENESAS RL78 */\
				defined(__uClinux__) || /* uLinux */\
				defined(__MSP430__) || /* TI-MSP430 MICROCONTROLLERS */\
				defined(__TMS320C55X__) || /* TI-CGT C5000 SERIES */\
				defined(_TMS320C5X) || /* TI-CGT C5000 SERIES */\
				defined(_TMS320C5XX) || /* TI-CGT C54X SERIES */\
				defined(TMS320C55X) || /* TI-CGT C55X SERIES */\
				defined(_M_I86) || /* INTEL 16BIT CPU */\
				(\
					defined(__XC16__) || /* PIC XC COMPILER */\
					defined(__C30__) || /* dsPIC30/dsPIC33 SERIES */\
					defined(__XC16) /* PIC XC COMPILER */\
				) || (\
					defined(__DMC__) && /* DIGITAL MARS (DMC) */\
					(__INTSIZE == 2) /* 16 BIT */\
				)\
			)
#				define L1_CACHE_SHIFT 4 /* 2^4 16 BIT */
#				define L1_CACHE_BYTES 16 /* BITS */
#				define CACHE_LINE_MASK -16 /* - MASK */
#				define SMP_CACHE_BYTES 16 /* SAMPLE */
#				define SMP_CACHE_SHIFT 4 /* SAMPLE */
#				define __CACHE_BYTES__ 2 /* BYTES */
#			else /* 32 BIT */
#				if (\
					defined(_M_IX86) || /* INTEL 32BIT CPU */\
					defined(__ESP8266__) || /* ESPRESSIF ESP8266 */\
					defined(__DJGPP__) || /* DJGPP DOS C COMPILER */\
					defined(__BORLANDC__) || /* BORLAND C COMPILER (BCC32) */\
					defined(__TINYC__) /* TINY C COMPILER */ ||  \
					defined(__TURBOC__) || /* TURBO C */\
					defined(__PCC__) || /* PORTABLE C COMPILER */\
					defined(__arm__) || /* ARM V7 */\
					defined(__TMS470__) || /* TMS470 G4 CPU */\
					defined(_TMS320C6600) || /* TM C6600 CPU */\
					defined(_TMS320C2XX) || /* TI-CGT C2000 SERIES */\
					defined(__TMS320C2000__) || /* TI-CGT C2000 SERIES */\
					defined(_TMS320C6X) || /* TI-CGT C6000 SERIES */\
					defined(__TMS320C6X__) || /* TI-CGT C6000 SERIES */\
					defined(_TMS320C28X) || /* TI-CGT C28XX SERIES */\
					defined(_TMS320C6200) || /* TI-CGT C6200 SERIES */\
					defined(_TMS320C6400) || /* TI-CGT C6400 SERIES */\
					defined(_TMS320C6400_PLUS) || /* TI-CGT C6400+ SERIES */\
					defined(_TMS320C64_PLUS) || /* TI-CGT C6400+ SERIES */\
					defined(_TMS320C6700) || /* TI-CGT C6700 SERIES */\
					defined(_TMS320C6700_PLUS) || /* TI-CGT C6700+ SERIES */\
					defined(_TMS320C67_PLUS) || /* TI-CGT C6700+ SERIES */\
					defined(_TMS320C6740) || /* TI-CGT C6740 SERIES */\
					(\
						defined(__XC32__) || /* PIC XC COMPILER */\
						defined(__XC32) || /* PIC XC COMPILER */\
						defined(__PIC32__) /* PIC 32-BIT MICROCONTROLLERS */\
					) || (\
						defined(__ARM_ARCH) && /* ARM CPU */\
						(\
							defined(__ARM_ARCH_6K__) || /* ARM CPU */\
							defined(__ARM_ARCH_7A__) /* ARM CPU */\
						)\
					) || (\
						defined(__ARM_ARCH) && /* ARM CPU */ \
						!defined(__ARM_ARCH_8A__) /* ARM CPU */\
					) || (\
						defined(__DMC__) && /* DIGITAL MARS (DMC) */\
						(__INTSIZE == 4) /* 32 BIT */\
					)\
				)
#					define L1_CACHE_SHIFT 5 /* 2^5 32 BIT */
#					define L1_CACHE_BYTES 32 /* BITS */
#					define CACHE_LINE_MASK -32 /* - MASK */
#					define SMP_CACHE_BYTES 32 /* SAMPLE */
#					define SMP_CACHE_SHIFT 5 /* SAMPLE */
#					define __CACHE_BYTES__ 4 /* BYTES */
#				else /* 64 BIT */
#					if (\
						defined(_MSC_VER) || /* MICROSOFT C++ */\
						defined(__INTEL_COMPILER) || /* ICC/C */\
						defined(__ICC) || /* ICC/C */\
						defined(__INTEL_LLVM_COMPILER) || /* DPC++/C++ */\
						defined(__ICL) || /* DPC++/C++ */\
						defined(CONFIG_ALPHA_GENERIC) || /* DEC ALPHA CPU */\
						defined(CONFIG_ALPHA_EV6) || /* DEC ALPHA EV6 BUS */\
						defined(__WATCOMC__) || /* OPEN WATCOM */\
						defined(__SUNPRO_C) || /* SUN STUDIO */\
						defined(__sun) || /* SUN STUDIO */\
						defined(__aarch64__) || /* ARM V8 */\
						defined(__ppc64__) || /* POWER PC 64 */\
						defined(__PPC64__) || /* POWER PC 64 */\
						defined(__powerpc64__) || /* POWER PC 64 */\
						defined(__x86_64__) || /* X86 / INTEL */\
						(\
							(\
								defined(__GNUC__) || /* GCC */\
								defined(__clang__) /* LLVM */\
							) && ( /* INTEL 64 BIT CPU DEFINES */\
								defined(i386) || /* GNU C */\
								defined(__i386) || /* SUN STUDIO */\
								defined(__IA32__) || /* VOS C */\
								defined(__X86__) || /* WATCOM C/C++ */\
								defined(_X86_) || /* MINGW32 */\
								defined(__THW_INTEL__) || /* XL C/C++ */\
								defined(__I86__) || /* DIGITAL MARS */\
								defined(__INTEL__) || /* CODE WARRIOR */\
								defined(__386) || /* DIAB */\
								defined(__i386__) || /* GNU C */\
								defined(__i486__) || /* GNU C */\
								defined(__i586__) || /* GNU C */\
								defined(__i686__) /* INTEL CPU */\
							)\
						) || (\
							defined(__ARM_ARCH) && /* ARM CPU */\
							defined(__ARM_ARCH_8A__) /* ARM CPU */ \
						)\
					)
#						define L1_CACHE_SHIFT 6 /* 2^6 64 BIT */
#						define L1_CACHE_BYTES 64 /* BITS */
#						define CACHE_LINE_MASK -64 /* - MASK */
#						define SMP_CACHE_BYTES 64 /* SAMPLE */
#						define SMP_CACHE_SHIFT 6 /* SAMPLE */
#						define __CACHE_BYTES__ 8 /* BYTES */
#					else /* 128 BIT */
#						if (\
							defined(__POWERPC__) || /* IBM 1991 (AIM) CPU */\
							defined(__IBMC__) || /* IBM XL C/C++ COPILER */\
							defined(__IBMCPP__) || /* IBM XL C/C++ COPILER */\
							defined(__xlC__) || /* IBM XL C/C++ COPILER */\
							defined(__xlc__) || /* IBM XL C/C++ COPILER */\
							defined(__ibmxl__) /* IBM XL C/C++ COPILER */\
						)
#							define L1_CACHE_SHIFT 7 /* 2^7 128 BIT */
#							define L1_CACHE_BYTES 128 /* BITS */
#							define CACHE_LINE_MASK -128 /* - MASK */
#							define SMP_CACHE_BYTES 128 /* SAMPLE */
#							define SMP_CACHE_SHIFT 7 /* SAMPLE */
#							define __CACHE_BYTES__ 16 /* BYTES */
#						else /* 256 BIT */
#							ifdef __s390__ /* IBM SYSTEM/390 */
#								ifndef __ARCH_S390_CACHE_H
#									define L1_CACHE_SHIFT 8 /* 2^8 256 BIT */
#									define L1_CACHE_BYTES 256 /* BITS */
#									define NET_SKB_PAD 32 /* NET CODE LINUX */
#									define __ARCH_S390_CACHE_H
#									define __read_mostly \
										__attribute__(( \
											__section__(".data.read_mostly")\
										)) /* IMPROV READ ACCESS */
#									define __ro_after_init __read_mostly
#								endif /* __ARCH_S390_CACHE_H */
#								define CACHE_LINE_MASK -256 /* - MASK */
#								define SMP_CACHE_BYTES 256 /* SAMPLE */
#								define SMP_CACHE_SHIFT 8 /* SAMPLE */
#								define __CACHE_BYTES__ 32 /* BYTES */
#							else /* DEFAULT (32 BIT) */
#								define L1_CACHE_SHIFT 5 /* 2^5 32 BIT */
#								define L1_CACHE_BYTES 32 /* BITS */
#								define CACHE_LINE_MASK -32 /* - MASK */
#								define SMP_CACHE_BYTES 32 /* SAMPLE */
#								define SMP_CACHE_SHIFT 5 /* SAMPLE */
#								define __CACHE_BYTES__ 4 /* BYTES */
#							endif /* 256 BIT */
#						endif /* 128 BIT */
#					endif /* 64 BIT */
#				endif /* 32 BIT */
#			endif /* 16 BIT */
#		endif /* 8 BIT */
#	endif /* ARC CACHE AUTOMATIC */

#	ifdef __cplusplus /* C++ */
		}
#	endif /* __cplusplus */

#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
#endif /* CACHE_H */
