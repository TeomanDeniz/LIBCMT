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
# : License - AGPL-3.0  :: Update - 2025/04/25 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/******************************************************************************\
|*                                  CONTENTS                                  *|
|******************************************************************************|
|*............................................................................*|
|*        NAME        :   TYPE  :                 DESCRIPTION                 *|
|*....................:.........:.............................................*|
|* __CACHE_BYTES__    : #define : INDICATES HOW MANY BYTES THE ARCHITECTURE   *|
|*                    :         : OF THE DEVICE OR COMPILER USES.             *|
|*....................:.........:.............................................*|
|* L1_CACHE_BYTES     : #define : INDICATES HOW MANY BITS THE ARCHITECTURE OF *|
|*                    :         : THE DEVICE OR COMPILER USES.                *|
|*....................:.........:.............................................*|
|* L1_CACHE_SHIFT     : #define : INDICATES THE NUMBER OF BIT SHIFTS IN THE   *|
|*                    :         : ARCHITECTURE OF THE DEVICE OR COMPILER.     *|
|*....................:.........:.............................................*|
|* CACHE_LINE_MASK    : #define : NEGATIVE VERSION OF (L1_CACHE_BYTES).       *|
|*....................:.........:.............................................*|
|* SMP_CACHE_BYTES    : #define : FOR SYMMETRIC MULTIPROCESSING SYSTEMS       *|
|*                    :         : (SMP), SAME AS (L1_CACHE_BYTES).            *|
|*....................:.........:.............................................*|
|* SMP_CACHE_SHIFT    : #define : FOR SYMMETRIC MULTIPROCESSING SYSTEMS       *|
|*                    :         : (SMP), SAME AS (L1_CACHE_SHIFT).            *|
|*....................:.........:.............................................*|
|* __SYSTEM_256_BIT__ : #define : DEFINED IF SYSTEM IS 256 BIT.               *|
|*....................:.........:.............................................*|
|* __SYSTEM_128_BIT__ : #define : DEFINED IF SYSTEM IS 128 BIT.               *|
|*....................:.........:.............................................*|
|* __SYSTEM_64_BIT__  : #define : DEFINED IF SYSTEM IS 64 BIT.                *|
|*....................:.........:.............................................*|
|* __SYSTEM_32_BIT__  : #define : DEFINED IF SYSTEM IS 32 BIT.                *|
|*....................:.........:.............................................*|
|* __SYSTEM_16_BIT__  : #define : DEFINED IF SYSTEM IS 16 BIT.                *|
|*....................:.........:.............................................*|
|* __SYSTEM_8_BIT__   : #define : DEFINED IF SYSTEM IS 8 BIT.                 *|
|*....................:.........:.............................................*|
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
|* FOR SUPPORT REALLY OLD COMPILERS, I STRICTLY AVOID USING #IF IN THIS FILE. *|
|*                                                                            *|
\******************************************************************************/

#ifndef CACHE_H
#	define CACHE_H 202504 /* VERSION */

/* *********************** [v] TI CGT CCS (PUSH) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_push /* TI CGT CCS COMPILER DIRECTIVES */
#		pragma CHECK_MISRA("-5.4") /* TAG NAMES SHALL BE A UNIQUE IDENTIFIER */
#		pragma CHECK_MISRA("-19.3") /*
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

/* *************************** [v] ARC CONFIG [v] *************************** */
#	ifdef CONFIG_ARC_CACHE_LINE_SHIFT
#		define LOCALMACRO__ARC_CONFIG_IS_EXIST_ALREADY
#		define LOCALMACRO__ARCHITECTURE_FOUND
#	else
#		ifdef CONFIG_L1_CACHE_SHIFT
#			define LOCALMACRO__ARC_CONFIG_IS_EXIST_ALREADY
#			define LOCALMACRO__ARCHITECTURE_FOUND
#		endif
#	endif
/* *************************** [^] ARC CONFIG [^] *************************** */

/* **************************** [v] 128-BITS [v] **************************** */
#	ifndef LOCALMACRO__ARCHITECTURE_FOUND
#		ifdef __s390__ /* IBM SYSTEM/390 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_256_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __s390__ */
#	endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
/* **************************** [^] 128-BITS [^] **************************** */

/* **************************** [v] 128-BITS [v] **************************** */
#	ifndef LOCALMACRO__ARCHITECTURE_FOUND
#		ifdef __POWERPC__ /* IBM 1991 (AIM) CPU */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_128_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __PIC32__ */
#		ifdef __IBMC__ /* IBM XL C/C++ COPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_128_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __PIC32__ */
#		ifdef __IBMCPP__ /* IBM XL C/C++ COPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_128_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __PIC32__ */
#		ifdef __xlC__ /* IBM XL C/C++ COPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_128_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __PIC32__ */
#		ifdef __xlc__ /* IBM XL C/C++ COPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_128_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __PIC32__ */
#		ifdef __ibmxl__ /* IBM XL C/C++ COPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_128_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __PIC32__ */
#	endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
/* **************************** [^] 128-BITS [^] **************************** */

/* **************************** [v] 64-BITS [v] ***************************** */
#	ifndef LOCALMACRO__ARCHITECTURE_FOUND
#		ifdef __PIC32__ /* PIC 32-BIT MICROCONTROLLERS */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __PIC32__ */
#		ifdef _MSC_VER /* MICROSOFT C++ */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _MSC_VER */
#		ifdef __INTEL_COMPILER /* ICC/C */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __INTEL_COMPILER */
#		ifdef __ICC /* ICC/C */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __ICC */
#		ifdef __INTEL_LLVM_COMPILER /* DPC++/C++ */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __INTEL_LLVM_COMPILER */
#		ifdef __ICL /* DPC++/C++ */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __ICL */
#		ifdef CONFIG_ALPHA_GENERIC /* DEC ALPHA CPU */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* CONFIG_ALPHA_GENERIC */
#		ifdef CONFIG_ALPHA_EV6 /* DEC ALPHA EV6 BUS */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* CONFIG_ALPHA_EV6 */
#		ifdef __WATCOMC__ /* OPEN WATCOM */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __WATCOMC__ */
#		ifdef __SUNPRO_C /* SUN STUDIO */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __SUNPRO_C */
#		ifdef __sun /* SUN STUDIO */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __sun */
#		ifdef __aarch64__ /* ARM V8 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __aarch64__ */
#		ifdef __ppc64__ /* POWER PC 64 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __ppc64__ */
#		ifdef __PPC64__ /* POWER PC 64 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __PPC64__ */
#		ifdef __powerpc64__ /* POWER PC 64 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __powerpc64__ */
#		ifdef __x86_64__ /* X86 / INTEL */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __x86_64__ */
#		ifdef __GNUC__ /* GCC */
#			ifdef i386 /* INTEL 86 V3 */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* i386 */
#			ifdef __i386 /* SUN STUDIO */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __i386 */
#			ifdef __IA32__ /* VOS C */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __IA32__ */
#			ifdef __X86__ /* WATCOM C/C++ */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __X86__ */
#			ifdef _X86_ /* MINGW32 */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* _X86_ */
#			ifdef __THW_INTEL__ /* XL C/C++ */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __THW_INTEL__ */
#			ifdef __I86__ /* DIGITAL MARS */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __I86__ */
#			ifdef __INTEL__ /* CODE WARRIOR */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __INTEL__ */
#			ifdef __386 /* DIAB */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __386 */
#			ifdef __i386__ /* INTEL 86 V3 */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __i386__ */
#			ifdef __i486__ /* INTEL 86 V4 */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __i486__ */
#			ifdef __i586__ /* INTEL 86 V5 */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __i586__ */
#			ifdef __i686__ /* INTEL 86 V6 */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __i686__ */
#		endif /* __GNUC__ */
#		ifdef __clang__ /* LLVM */
#			ifdef i386 /* INTEL 86 V3 */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* i386 */
#			ifdef __i386 /* SUN STUDIO */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __i386 */
#			ifdef __IA32__ /* VOS C */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __IA32__ */
#			ifdef __X86__ /* WATCOM C/C++ */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __X86__ */
#			ifdef _X86_ /* MINGW32 */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* _X86_ */
#			ifdef __THW_INTEL__ /* XL C/C++ */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __THW_INTEL__ */
#			ifdef __I86__ /* DIGITAL MARS */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __I86__ */
#			ifdef __INTEL__ /* CODE WARRIOR */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __INTEL__ */
#			ifdef __386 /* DIAB */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __386 */
#			ifdef __i386__ /* INTEL 86 V3 */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __i386__ */
#			ifdef __i486__ /* INTEL 86 V4 */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __i486__ */
#			ifdef __i586__ /* INTEL 86 V5 */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __i586__ */
#			ifdef __i686__ /* INTEL 86 V6 */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __i686__ */
#		endif /* __clang__ */
#		ifdef __ARM_ARCH /* ARM CPU */
#			ifdef __ARM_ARCH_8A__ /* ARM CPU */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __i686__ */
#		endif /* __i686__ */
#	endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
/* **************************** [^] 64-BITS [^] ***************************** */

/* **************************** [v] 32-BITS [v] ***************************** */
#	ifndef LOCALMACRO__ARCHITECTURE_FOUND
#		ifdef _M_IX86 /* INTEL 32BIT CPU */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _M_IX86 */
#		ifdef __ESP8266__ /* ESPRESSIF ESP8266 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __ESP8266__ */
#		ifdef __DJGPP__ /* DJGPP DOS C COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __DJGPP__ */
#		ifdef __BORLANDC__ /* BORLAND C COMPILER (BCC32) */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __BORLANDC__ */
#		ifdef __TINYC__ /* TINY C COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __TINYC__ */
#		ifdef __TURBOC__ /* TURBO C */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __TURBOC__ */
#		ifdef __PCC__ /* PORTABLE C COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __PCC__ */
#		ifdef __arm__ /* ARM V7 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __arm__ */
#		ifdef __TMS470__ /* TMS470 G4 CPU */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __TMS470__ */
#		ifdef _TMS320C6600 /* TM C6600 CPU */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C6600 */
#		ifdef _TMS320C2XX /* TI-CGT C2000 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C2XX */
#		ifdef __TMS320C2000__ /* TI-CGT C2000 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __TMS320C2000__ */
#		ifdef _TMS320C6X /* TI-CGT C6000 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C6X */
#		ifdef __TMS320C6X__ /* TI-CGT C6000 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __TMS320C6X__ */
#		ifdef _TMS320C28X /* TI-CGT C28XX SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C28X */
#		ifdef _TMS320C6200 /* TI-CGT C6200 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C6200 */
#		ifdef _TMS320C6400 /* TI-CGT C6400 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C6400 */
#		ifdef _TMS320C6400_PLUS /* TI-CGT C6400+ SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C6400_PLUS */
#		ifdef _TMS320C64_PLUS /* TI-CGT C6400+ SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C64_PLUS */
#		ifdef _TMS320C6700 /* TI-CGT C6700 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C6700 */
#		ifdef _TMS320C6700_PLUS /* TI-CGT C6700+ SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C6700_PLUS */
#		ifdef _TMS320C67_PLUS /* TI-CGT C6700+ SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C67_PLUS */
#		ifdef _TMS320C6740 /* TI-CGT C6740 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C6740 */
#		ifdef __XC32__ /* PIC XC COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __XC32__ */
#		ifdef __XC32 /* PIC XC COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __XC32 */
#		ifdef __PIC32__ /* PIC 32-BIT MICROCONTROLLERS */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __PIC32__ */
#		ifdef __ARM_ARCH /* PIC 32-BIT MICROCONTROLLERS */
#			ifdef __ARM_ARCH_6K__ /* ARM CPU */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_32_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __ARM_ARCH_6K__ */
#			ifdef __ARM_ARCH_7A__ /* ARM CPU */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_32_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __ARM_ARCH_7A__ */
#			ifndef __ARM_ARCH_8A__ /* ARM CPU */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_32_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __ARM_ARCH_7A__ */
#		endif /* __ARM_ARCH */
#		ifdef __DMC__ /* DIGITAL MARS (DMC) */
#			ifdef __INTSIZE
#				if (__INTSIZE == 4)
#					ifndef LOCALMACRO__ARCHITECTURE_FOUND
#						define __SYSTEM_32_BIT__
#						define LOCALMACRO__ARCHITECTURE_FOUND
#					endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#				endif
#			endif /* __INTSIZE */
#			ifdef __SIZEOF_INT__
#				if (__SIZEOF_INT__ == 4)
#					ifndef LOCALMACRO__ARCHITECTURE_FOUND
#						define __SYSTEM_32_BIT__
#						define LOCALMACRO__ARCHITECTURE_FOUND
#					endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#				endif
#			endif /* __SIZEOF_INT__ */
#		endif /* __DMC__ */
#	endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
/* **************************** [^] 32-BITS [^] ***************************** */

/* **************************** [v] 16-BITS [v] ***************************** */
#	ifndef LOCALMACRO__ARCHITECTURE_FOUND
#		ifdef __RL78__ /* RENESAS RL78 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __RL78__ */
#		ifdef __uClinux__ /* uLinux */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __uClinux__ */
#		ifdef __MSP430__ /* TI-MSP430 MICROCONTROLLERS */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __MSP430__ */
#		ifdef __TMS320C55X__ /* TI-CGT C5000 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __TMS320C55X__ */
#		ifdef _TMS320C5X /* TI-CGT C5000 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C5X */
#		ifdef _TMS320C5XX /* TI-CGT C54X SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C5XX */
#		ifdef TMS320C55X /* TI-CGT C55X SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* TMS320C55X */
#		ifdef _M_I86 /* INTEL 16BIT CPU */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _M_I86 */
#		ifdef __XC16__  /* PIC XC COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __XC16__ */
#		ifdef __C30__ /* dsPIC30/dsPIC33 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __C30__ */
#		ifdef __XC16 /* PIC XC COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __XC16 */
#		ifdef __DMC__ /* DIGITAL MARS (DMC) */
#			ifdef __INTSIZE
#				if (__INTSIZE == 2)
#					ifndef LOCALMACRO__ARCHITECTURE_FOUND
#						define __SYSTEM_16_BIT__
#						define LOCALMACRO__ARCHITECTURE_FOUND
#					endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#				endif
#			endif /* __INTSIZE */
#			ifdef __SIZEOF_INT__
#				if (__SIZEOF_INT__ == 2)
#					ifndef LOCALMACRO__ARCHITECTURE_FOUND
#						define __SYSTEM_16_BIT__
#						define LOCALMACRO__ARCHITECTURE_FOUND
#					endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#				endif
#			endif /* __SIZEOF_INT__ */
#		endif /* __DMC__ */
#	endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
/* **************************** [^] 16-BITS [^] ***************************** */

/* ***************************** [v] 8-BITS [v] ***************************** */
#	ifndef LOCALMACRO__ARCHITECTURE_FOUND
#		ifdef __SCCZ80 /* SMALL DEVICE C COMPILER ZILOG Z80 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __SCCZ80 */
#		ifdef __STM8__ /* EXPERIMENTAL SUPPORT IN SDCC */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __STM8__ */
#		ifdef __Z80__ /* ZILOG Z80 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __Z80__ */
#		ifdef __8051__ /* 8051 MICROCONTROLLER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __8051__ */
#		ifdef __MCS51__ /* 8051 MICROCONTROLLER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __MCS51__ */
#		ifdef __68HC08__ /* MOTOROLA 68HC08 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __68HC08__ */
#		ifdef __PIC24F__ /* PIC FAMILY MICROCONTROLLERS */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __PIC24F__ */
#		ifdef __XC8__ /* PIC XC COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __XC8__ */
#		ifdef __18CXX /* PIC18 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __18CXX */
#		ifdef __XC8 /* PIC XC COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __XC8 */
#	endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
/* ***************************** [^] 8-BITS [^] ***************************** */

#	ifdef LOCALMACRO__ARC_CONFIG_IS_EXIST_ALREADY
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
#		if (L1_CACHE_BYTES == 8)
#			define __SYSTEM_8_BIT__
#		endif
#		if (L1_CACHE_BYTES == 16)
#			define __SYSTEM_16_BIT__
#		endif
#		if (L1_CACHE_BYTES == 32)
#			define __SYSTEM_32_BIT__
#		endif
#		if (L1_CACHE_BYTES == 64)
#			define __SYSTEM_64_BIT__
#		endif
#		if (L1_CACHE_BYTES == 128)
#			define __SYSTEM_128_BIT__
#		endif
#		if (L1_CACHE_BYTES == 256)
#			define __SYSTEM_256_BIT__
#		endif
#	else /* 8 BIT */ // SORRY BUT WHY?
#		ifdef __SYSTEM_8_BIT__
#			define L1_CACHE_SHIFT 3 /* 2^3 8 BIT */
#			define L1_CACHE_BYTES 8 /* BITS */
#			define CACHE_LINE_MASK -8 /* - MASK */
#			define SMP_CACHE_BYTES 8 /* SAMPLE */
#			define SMP_CACHE_SHIFT 3 /* SAMPLE */
#			define __CACHE_BYTES__ 1 /* BYTE */ // (PROBABLY???)
#		else /* 16 BIT */
#			ifdef __SYSTEM_16_BIT__
#				define L1_CACHE_SHIFT 4 /* 2^4 16 BIT */
#				define L1_CACHE_BYTES 16 /* BITS */
#				define CACHE_LINE_MASK -16 /* - MASK */
#				define SMP_CACHE_BYTES 16 /* SAMPLE */
#				define SMP_CACHE_SHIFT 4 /* SAMPLE */
#				define __CACHE_BYTES__ 2 /* BYTES */
#				define __SYSTEM_16_BIT__
#			else /* 32 BIT */
#				ifdef __SYSTEM_32_BIT__
#					define L1_CACHE_SHIFT 5 /* 2^5 32 BIT */
#					define L1_CACHE_BYTES 32 /* BITS */
#					define CACHE_LINE_MASK -32 /* - MASK */
#					define SMP_CACHE_BYTES 32 /* SAMPLE */
#					define SMP_CACHE_SHIFT 5 /* SAMPLE */
#					define __CACHE_BYTES__ 4 /* BYTES */
#				else /* 64 BIT */
#					ifdef __SYSTEM_64_BIT__
#						define L1_CACHE_SHIFT 6 /* 2^6 64 BIT */
#						define L1_CACHE_BYTES 64 /* BITS */
#						define CACHE_LINE_MASK -64 /* - MASK */
#						define SMP_CACHE_BYTES 64 /* SAMPLE */
#						define SMP_CACHE_SHIFT 6 /* SAMPLE */
#						define __CACHE_BYTES__ 8 /* BYTES */
#					else /* 128 BIT */
#						ifdef __SYSTEM_128_BIT__
#							define L1_CACHE_SHIFT 7 /* 2^7 128 BIT */
#							define L1_CACHE_BYTES 128 /* BITS */
#							define CACHE_LINE_MASK -128 /* - MASK */
#							define SMP_CACHE_BYTES 128 /* SAMPLE */
#							define SMP_CACHE_SHIFT 7 /* SAMPLE */
#							define __CACHE_BYTES__ 16 /* BYTES */
#						else /* 256 BIT */
#							ifdef __SYSTEM_256_BIT__
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
#								define __SYSTEM_32_BIT__
#							endif /* __SYSTEM_256_BIT__ */
#						endif /* __SYSTEM_128_BIT__ */
#					endif /* __SYSTEM_64_BIT__ */
#				endif /* __SYSTEM_32_BIT__ */
#			endif /* __SYSTEM_16_BIT__ */
#		endif /* __SYSTEM_8_BIT__ */
#	endif /* ARC CACHE AUTOMATIC */

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

#endif /* CACHE_H */
