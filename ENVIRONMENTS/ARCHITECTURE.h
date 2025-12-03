/******************************************************************************\
# H - ARCHITECTURE                               #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2023/07/12 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/12/03 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/******************************************************************************\
|*                                  CONTENTS                                  *|
|******************************************************************************|
|*    ....................................................................    *|
|*  .'                     CPU ARCHITECTURE WORD SIZE                     '.  *|
|*.:........................................................................:.*|
|*       NAME        :   TYPE  :                 DESCRIPTION                  *|
|*...................:.........:..............................................*|
|* __SYSTEM_64_BIT__ : #define : DEFINED IF THE SYSTEM IS 64-BIT              *|
|*...................:.........:..............................................*|
|* __SYSTEM_32_BIT__ : #define : DEFINED IF THE SYSTEM IS 32-BIT              *|
|*...................:.........:..............................................*|
|* __SYSTEM_31_BIT__ : #define : DEFINED IF THE SYSTEM ALSO 31-BIT            *|
|*...................:.........:..............................................*|
|* __SYSTEM_16_BIT__ : #define : DEFINED IF THE SYSTEM IS 16-BIT              *|
|*...................:.........:..............................................*|
|* __SYSTEM_8_BIT__  : #define : DEFINED IF THE SYSTEM IS 8-BIT               *|
|*...................:.........:..............................................*|
|* __SYSTEM_BIT__    : #define : MACRO INDICATING THE SYSTEM BIT-WIDTH        *|
|*...................:.........:..............................................*|
|*                                                                            *|
|*    ....................................................................    *|
|*  .'         FORCED / COMPILER-SUPPORTED EXTENDED INTEGER SIZES         '.  *|
|*.:........................................................................:.*|
|*        NAME        :   TYPE  :                 DESCRIPTION                 *|
|*....................:.........:.............................................*|
|* __HAS_128_BIT__    : #define : DEFINED IF THE SYSTEM ALSO SUPPORTS 128-BIT *|
|*....................:.........:.............................................*|
|* __HAS_64_BIT__     : #define : DEFINED IF THE SYSTEM ALSO SUPPORTS 64-BIT  *|
|*                    :         : (FOR 32/16-BIT SYSTEMS)                     *|
|*....................:.........:.............................................*|
|*                                                                            *|
|*    ....................................................................    *|
|*  .'                       VECTOR REGISTER SIZES                        '.  *|
|*.:........................................................................:.*|
|*          NAME          :  TYPE   :               DESCRIPTION               *|
|*........................:.........:.........................................*|
|* __HAS_512_BIT_VECTOR__ : #define : DEFINED IF THE SYSTEM SUPPORTS 512-BIT  *|
|*                        :         : VECTOR REGISTERS                        *|
|*........................:.........:.........................................*|
|* __HAS_256_BIT_VECTOR__ : #define : DEFINED IF THE SYSTEM SUPPORTS 256-BIT  *|
|*                        :         : VECTOR REGISTERS                        *|
|*........................:.........:.........................................*|
|* __HAS_128_BIT_VECTOR__ : #define : DEFINED IF THE SYSTEM SUPPORTS 128-BIT  *|
|*                        :         : VECTOR REGISTERS                        *|
|*........................:.........:.........................................*|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF DOES THAT DO?                           #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* THESE DEFINES INDICATE THE BIT-WIDTH SUPPORTED OR USED BY THE SYSTEM.      *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                                SIDE NOTES                                #*|
|*############################################################################*|
|*                                                                            *|
|* TO SUPPORT VERY OLD COMPILERS, THIS FILE STRICTLY AVOIDS USING #if & #elif *|
|*                                                                            *|
\******************************************************************************/

#ifndef ARCHITECTURE_H
#	define ARCHITECTURE_H 202512 /* VERSION */

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

/* *************************** [v] ARC CONFIG [v] *************************** */
#	ifdef CONFIG_ARC_CACHE_LINE_SHIFT
#		define LOCALMACRO__ARC_CONFIG_IS_EXIST_ALREADY
#		define LOCALMACRO__ARCHITECTURE_FOUND
#	else
#		ifdef CONFIG_L1_CACHE_SHIFT
#			define LOCALMACRO__ARC_CONFIG_IS_EXIST_ALREADY
#			define LOCALMACRO__ARCHITECTURE_FOUND
#		endif /* CONFIG_L1_CACHE_SHIFT */
#	endif /* CONFIG_ARC_CACHE_LINE_SHIFT */
/* *************************** [^] ARC CONFIG [^] *************************** */

/* **************************** [v] 64-BITS [v] ***************************** */
#	ifndef LOCALMACRO__ARCHITECTURE_FOUND
#		ifdef __DECC /* COMPAQ C/C++ COMPILER */
#			ifdef __alpha__ /* LAST VERSION */
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* __alpha__ */
#		endif /* __DECC */
#		ifdef __DECCXX /* COMPAQ C/C++ COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				ifdef __alpha__ /* LAST VERSION */
#					define __SYSTEM_64_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* __alpha__ */
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __DECCXX */
#		ifdef __POWERPC__ /* IBM 1991 (AIM) CPU */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __POWERPC__ */
#		ifdef __IBMC__ /* IBM XL C/C++ COPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __IBMC__ */
#		ifdef __xlC__ /* IBM XL C/C++ COPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __xlC__ */
#		ifdef __xlc__ /* IBM XL C/C++ COPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __xlc__ */
#		ifdef __ibmxl__ /* IBM XL C/C++ COPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __ibmxl__ */
#		ifdef __IBMCPP__ /* IBM Z/OS XL C/C++ COPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __IBMCPP__ */
#		ifdef __s390x__ /* IBM SYSTEM/390 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __s390x__ */
#		ifdef _MSC_VER /* MICROSOFT C++ */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _MSC_VER */
#		ifdef __INTEL_COMPILER /* ICC (INTEL C COMPILER) */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __INTEL_COMPILER */
#		ifdef __ICC /* ICC (INTEL C COMPILER) */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __ICC */
#		ifdef __INTEL_LLVM_COMPILER /* DPC++/C++ */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __INTEL_LLVM_COMPILER */
#		ifdef __ICL /* DPC++/C++ */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __ICL */
#		ifdef CONFIG_ALPHA_GENERIC /* DEC ALPHA CPU */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* CONFIG_ALPHA_GENERIC */
#		ifdef CONFIG_ALPHA_EV6 /* DEC ALPHA EV6 BUS */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* CONFIG_ALPHA_EV6 */
#		ifdef __WATCOMC__ /* OPEN WATCOM */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __WATCOMC__ */
#		ifdef __SUNPRO_C /* SUN STUDIO */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __SUNPRO_C */
#		ifdef __sun /* SUN STUDIO */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __sun */
#		ifdef __aarch64__ /* ARM V8 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __aarch64__ */
#		ifdef __ppc64__ /* POWER PC 64 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __ppc64__ */
#		ifdef __PPC64__ /* POWER PC 64 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __PPC64__ */
#		ifdef __powerpc64__ /* POWER PC 64 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __powerpc64__ */
#		ifdef __convexc__ /* CONVEX C COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __convexc__ */
#		ifdef __NDPC__ /* MICROWAY NDP C */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __NDPC__ */
#		ifdef __NDPX__ /* MICROWAY NDP */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __NDPX__ */
#		ifdef _CRAYC /* CRAY C COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _CRAYC */
#		ifdef __x86_64__ /* X64 / INTEL */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __x86_64__ */
#		ifdef __amd64__ /* AMD 64BIT */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __amd64__ */
#		ifdef _M_ARM64 /* AMD 64BIT */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _M_ARM64 */
#		ifdef _M_X64 /* MICROSOFT C&C++ */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _M_X64 */
#		ifdef _M_AMD64 /* VISUAL STUDIO */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_64_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _M_AMD64 */
#	endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
/* **************************** [^] 64-BITS [^] ***************************** */

/* **************************** [v] 32-BITS [v] ***************************** */
#	ifndef LOCALMACRO__ARCHITECTURE_FOUND
#		ifdef __PIC32__ /* PIC 32-BIT MICROCONTROLLERS */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __PIC32__ */
#		ifdef __WIN32__ /* BORLAND C++ */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __WIN32__ */
#		ifdef _WIN32_WCE /* EMBEDDED VISUAL STUDIO C++ */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _WIN32_WCE */
#		ifdef __SYMBIAN32__ /* SYMBIAN OS */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __SYMBIAN32__ */
#		ifdef __CC_ARM /* ARM COMPILER (KEIL ARMCC) */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __CC_ARM */
#		ifdef __PATHCC__ /* EKOPATH COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __PATHCC__ */
#		ifdef __USLC__ /* USL C COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __USLC__ */
#		ifdef _PACC_VER /* PALM C/C++ COMPILER (ARM) */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _PACC_VER */
#		ifdef __NWCC__ /* NATHAN W. COHEN'S C COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __NWCC__ */
#		ifdef __COMPCERT__ /* COMPCERT VERIFIED C COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __COMPCERT__ */
#		ifdef _MRI /* MICROTEC C/C++ */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _MRI */
#		ifdef __CA__ /* KEIL CARM (ARM) */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __CA__ */
#		ifdef __KEIL__ /* KEIL CARM (ARM) */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __KEIL__ */
#		ifdef _M_IX86 /* INTEL 32BIT CPU */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _M_IX86 */
#		ifdef __ESP8266__ /* ESPRESSIF ESP8266 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __ESP8266__ */
#		ifdef __DJGPP__ /* DJGPP DOS C COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __DJGPP__ */
#		ifdef __BORLANDC__ /* BORLAND C COMPILER (BCC32) */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __BORLANDC__ */
#		ifdef __TINYC__ /* TINY C COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __TINYC__ */
#		ifdef __TURBOC__ /* TURBO C */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __TURBOC__ */
#		ifdef __PCC__ /* PORTABLE C COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __PCC__ */
#		ifdef __arm__ /* ARM V7 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __arm__ */
#		ifdef __TMS470__ /* TMS470 G4 CPU */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __TMS470__ */
#		ifdef _TMS320C6600 /* TM C6600 CPU */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C6600 */
#		ifdef __TMS320C28XX__ /* TI-CGT C2000 SERIES: C28X CORE */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __TMS320C28XX__ */
#		ifdef _TMS320C2XX /* TI-CGT C2000 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C2XX */
#		ifdef __TMS320C2000__ /* TI-CGT C2000 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __TMS320C2000__ */
#		ifdef _TMS320C6X /* TI-CGT C6000 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C6X */
#		ifdef __TMS320C6X__ /* TI-CGT C6000 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __TMS320C6X__ */
#		ifdef _TMS320C28X /* TI-CGT C28XX SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C28X */
#		ifdef _TMS320C6200 /* TI-CGT C6200 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C6200 */
#		ifdef _TMS320C6400 /* TI-CGT C6400 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C6400 */
#		ifdef _TMS320C6400_PLUS /* TI-CGT C6400+ SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C6400_PLUS */
#		ifdef _TMS320C64_PLUS /* TI-CGT C6400+ SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C64_PLUS */
#		ifdef _TMS320C6700 /* TI-CGT C6700 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C6700 */
#		ifdef _TMS320C6700_PLUS /* TI-CGT C6700+ SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C6700_PLUS */
#		ifdef _TMS320C67_PLUS /* TI-CGT C6700+ SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C67_PLUS */
#		ifdef _TMS320C6740 /* TI-CGT C6740 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C6740 */
#		ifdef __LCC__ /* LCC (LOCAL C COMPILER) */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __LCC__ */
#		ifdef __KCC /* KAI C++ */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __KCC */
#		ifdef __XC32__ /* PIC XC COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __XC32__ */
#		ifdef __XC32 /* PIC XC COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __XC32 */
#		ifdef __PIC32__ /* PIC 32-BIT MICROCONTROLLERS */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __PIC32__ */
#		ifdef __VAXC /* COMPAQ C/C++ COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __VAXC */
#		ifdef VAXC /* COMPAQ C/C++ COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* VAXC */
#		ifdef __DECC /* COMPAQ C/C++ COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __DECC */
#		ifdef __DECCXX /* COMPAQ C/C++ COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __DECCXX */
#		ifdef __ARM_ARCH /* PIC 32-BIT MICROCONTROLLERS */
#			ifdef __ARM_ARCH_6K__ /* ARM CPU */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_32_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __ARM_ARCH_6K__ */
#			ifdef __ARM_ARCH_7A__ /* ARM CPU */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_32_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __ARM_ARCH_7A__ */
#			ifndef __ARM_ARCH_8A__ /* ARM CPU */
#				ifndef LOCALMACRO__ARCHITECTURE_FOUND
#					define __SYSTEM_32_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#			endif /* __ARM_ARCH_7A__ */
#		endif /* __ARM_ARCH */
#		ifdef __DMC__ /* DIGITAL MARS (DMC) */
#			ifdef __INTSIZE
#				if (__INTSIZE == 4)
#					ifndef LOCALMACRO__ARCHITECTURE_FOUND
#						define __SYSTEM_32_BIT__
#						define LOCALMACRO__ARCHITECTURE_FOUND
#					endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#				endif /* __INTSIZE == 4 */
#			endif /* __INTSIZE */
#			ifdef __SIZEOF_INT__
#				if (__SIZEOF_INT__ == 4)
#					ifndef LOCALMACRO__ARCHITECTURE_FOUND
#						define __SYSTEM_32_BIT__
#						define LOCALMACRO__ARCHITECTURE_FOUND
#					endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#				endif /* __SIZEOF_INT__ == 4 */
#			endif /* __SIZEOF_INT__ */
#		endif /* __DMC__ */
#		ifdef __s390__ /* IBM SYSTEM/390 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_31_BIT__ /* YES. 31 BIT */
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __s390__ */
#		ifdef i386 /* INTEL 86 V3 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* i386 */
#		ifdef __i386 /* SUN STUDIO */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __i386 */
#		ifdef __IA32__ /* VOS C */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __IA32__ */
#		ifdef __X86__ /* WATCOM C/C++ */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __X86__ */
#		ifdef _X86_ /* MINGW32 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _X86_ */
#		ifdef __THW_INTEL__ /* XL C/C++ */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __THW_INTEL__ */
#		ifdef __I86__ /* DIGITAL MARS */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __I86__ */
#		ifdef __INTEL__ /* CODE WARRIOR */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __INTEL__ */
#		ifdef __386 /* DIAB */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __386 */
#		ifdef __i386__ /* INTEL 86 V3 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __i386__ */
#		ifdef __i486__ /* INTEL 86 V4 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __i486__ */
#		ifdef __i586__ /* INTEL 86 V5 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __i586__ */
#		ifdef __i686__ /* INTEL 86 V6 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_32_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __i686__ */
#	endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
/* **************************** [^] 32-BITS [^] ***************************** */

/* **************************** [v] 16-BITS [v] ***************************** */
#	ifndef LOCALMACRO__ARCHITECTURE_FOUND
#		ifdef _WIN16 /* WINDOWS 16-BIT */
#			define __SYSTEM_16_BIT__
#			define LOCALMACRO__ARCHITECTURE_FOUND
#		endif /* _WIN16 */
#		ifdef __C166__ /* KEIL C166 (ARM) */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __C166__ */
#		ifdef __RL78__ /* RENESAS RL78 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __RL78__ */
#		ifdef __uClinux__ /* uLinux */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __uClinux__ */
#		ifdef __MSP430__ /* TI-MSP430 MICROCONTROLLERS */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __MSP430__ */
#		ifdef __TMS320C55X__ /* TI-CGT C5000 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __TMS320C55X__ */
#		ifdef _TMS320C5X /* TI-CGT C5000 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C5X */
#		ifdef _TMS320C5XX /* TI-CGT C54X SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _TMS320C5XX */
#		ifdef TMS320C55X /* TI-CGT C55X SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* TMS320C55X */
#		ifdef MIRACLE /* MIRACLE C */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* MIRACLE */
#		ifdef __XC16__ /* PIC XC COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __XC16__ */
#		ifdef __C30__ /* dsPIC30/dsPIC33 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __C30__ */
#		ifdef __XC16 /* PIC XC COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __XC16 */
#		ifdef __PIC24F__ /* PIC FAMILY MICROCONTROLLERS */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __PIC24F__ */
#		ifdef AZTEC_C /* AZTEC C COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				ifdef __I8086__ /* INTEL 8086 */
#					define __SYSTEM_16_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* __I8086__ */
#				ifdef __MSDOS__ /* MICROSOFT DISK OPERATING SYSTEM */
#					define __SYSTEM_16_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* __MSDOS__ */
#				ifdef _M_I86 /* INTEL 8086 */
#					define __SYSTEM_16_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* _M_I86 */
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* AZTEC_C */
#		ifdef __AZTEC_C__ /* AZTEC C COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				ifdef __I8086__ /* INTEL 8086 */
#					define __SYSTEM_16_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* __I8086__ */
#				ifdef __MSDOS__ /* MICROSOFT DISK OPERATING SYSTEM */
#					define __SYSTEM_16_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* __MSDOS__ */
#				ifdef _M_I86 /* INTEL 8086 */
#					define __SYSTEM_16_BIT__
#					define LOCALMACRO__ARCHITECTURE_FOUND
#				endif /* _M_I86 */
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __AZTEC_C__ */
#		ifdef _M_I86 /* INTEL 8086 (FALLBACK) */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_16_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* _M_I86 */
#		ifdef __I8086__ /* INTEL 8086 (FALLBACK) */
#			define __SYSTEM_16_BIT__
#			define LOCALMACRO__ARCHITECTURE_FOUND
#		endif /* __I8086__ */
#		ifdef __DMC__ /* DIGITAL MARS (DMC) */
#			ifdef __INTSIZE
#				if (__INTSIZE == 2)
#					ifndef LOCALMACRO__ARCHITECTURE_FOUND
#						define __SYSTEM_16_BIT__
#						define LOCALMACRO__ARCHITECTURE_FOUND
#					endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#				endif /* __INTSIZE == 2 */
#			endif /* __INTSIZE */
#			ifdef __SIZEOF_INT__
#				if (__SIZEOF_INT__ == 2)
#					ifndef LOCALMACRO__ARCHITECTURE_FOUND
#						define __SYSTEM_16_BIT__
#						define LOCALMACRO__ARCHITECTURE_FOUND
#					endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#				endif /* __SIZEOF_INT__ == 2 */
#			endif /* __SIZEOF_INT__ */
#		endif /* __DMC__ */
#	endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
/* **************************** [^] 16-BITS [^] ***************************** */

/* ***************************** [v] 8-BITS [v] ***************************** */
#	ifndef LOCALMACRO__ARCHITECTURE_FOUND
#		ifdef __CC65__ /* CC65 (65C02 C COMPILER) | FOR 6502 FAMILY */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __CC65__ */
#		ifdef __C51__ /* KEIL C51 - 8051 MICROCONTROLLER (ARM) */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __C51__ */
#		ifdef __CX51__ /* KEIL C51 - 8051 MICROCONTROLLER (ARM) */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __CX51__ */
#		ifdef __SCCZ80 /* SMALL DEVICE C COMPILER ZILOG Z80 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __SCCZ80 */
#		ifdef __STM8__ /* EXPERIMENTAL SUPPORT IN SDCC */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __STM8__ */
#		ifdef __Z80__ /* ZILOG Z80 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __Z80__ */
#		ifdef __8051__ /* 8051 MICROCONTROLLER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __8051__ */
#		ifdef __MCS51__ /* 8051 MICROCONTROLLER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __MCS51__ */
#		ifdef __68HC08__ /* MOTOROLA 68HC08 */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __68HC08__ */
#		ifdef __XC8__ /* PIC XC COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __XC8__ */
#		ifdef __18CXX /* PIC18 SERIES */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __18CXX */
#		ifdef __XC8 /* PIC XC COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __XC8 */
#		ifdef AZTEC_C /* AZTEC C COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__ /* MOS 6502 OR ZILOG Z80 */
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* AZTEC_C */
#		ifdef __AZTEC_C__ /* AZTEC C COMPILER */
#			ifndef LOCALMACRO__ARCHITECTURE_FOUND
#				define __SYSTEM_8_BIT__ /* MOS 6502 OR ZILOG Z80 */
#				define LOCALMACRO__ARCHITECTURE_FOUND
#			endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
#		endif /* __AZTEC_C__ */
#	endif /* !LOCALMACRO__ARCHITECTURE_FOUND */
/* ***************************** [^] 8-BITS [^] ***************************** */

/* *************************** [v] ARC CONFIG [v] *************************** */
#	ifdef LOCALMACRO__ARC_CONFIG_IS_EXIST_ALREADY
#		undef LOCALMACRO__ARC_CONFIG_IS_EXIST_ALREADY
#		ifdef CONFIG_ARC_CACHE_LINE_SHIFT /* ARC STANDARD */
#			define LOCALMACRO__L1_CACHE_BYTES (1 << CONFIG_ARC_CACHE_LINE_SHIFT)
#		else /* LINUX STANDARD */
#			define LOCALMACRO__L1_CACHE_BYTES (1 << CONFIG_L1_CACHE_SHIFT)
#		endif /* CONFIG_ARC_CACHE_LINE_SHIFT */
#		if (LOCALMACRO__L1_CACHE_BYTES == 8)
#			define __SYSTEM_8_BIT__
#		endif /* LOCALMACRO__L1_CACHE_BYTES == 8 */
#		if (LOCALMACRO__L1_CACHE_BYTES == 16)
#			define __SYSTEM_16_BIT__
#		endif /* LOCALMACRO__L1_CACHE_BYTES == 16 */
#		if (LOCALMACRO__L1_CACHE_BYTES == 32)
#			define __SYSTEM_32_BIT__
#		endif /* LOCALMACRO__L1_CACHE_BYTES == 32 */
#		if (LOCALMACRO__L1_CACHE_BYTES >= 64)
#			define __SYSTEM_64_BIT__
#		endif /* LOCALMACRO__L1_CACHE_BYTES >= 64 */
#	endif /* LOCALMACRO__ARC_CONFIG_IS_EXIST_ALREADY */
/* *************************** [^] ARC CONFIG [^] *************************** */

/* ************************* [v] __SYSTEM_BIT__ [v] ************************* */
#	ifdef __SYSTEM_64_BIT__
#		define __SYSTEM_BIT__ 64
#	else
#		ifdef __SYSTEM_32_BIT__
#			define __SYSTEM_BIT__ 32
#		else
#			ifdef __SYSTEM_16_BIT__
#				define __SYSTEM_BIT__ 16
#			else
#				ifdef __SYSTEM_8_BIT__
#					define __SYSTEM_BIT__ 8
#				else
#					define __SYSTEM_32_BIT__ /* PROBABLY */
#					define __SYSTEM_BIT__ 32 /* PROBABLY */
#				endif /* __SYSTEM_8_BIT__ */
#			endif /* __SYSTEM_16_BIT__ */
#		endif /* __SYSTEM_32_BIT__ */
#	endif /* __SYSTEM_64_BIT__ */
/* ************************* [^] __SYSTEM_BIT__ [^] ************************* */

/* ********************* [v] __HAS_512_BIT_VECTOR__ [v] ********************* */
#	ifdef __AVX512F__ /* (512-BIT ADVANCED VECTOR EXTENSIONS) */
#		define __HAS_512_BIT_VECTOR__
#	else
#		ifdef __ARM_FEATURE_SVE /* SCALABLE VECTOR EXTENSION */
#			ifdef __ARM_FEATURE_SVE_BITS
#				if (__ARM_FEATURE_SVE_BITS >= 512)
#					define __HAS_512_BIT_VECTOR__
#				endif /* __ARM_FEATURE_SVE_BITS >= 512 */
#			endif /* __ARM_FEATURE_SVE_BITS */
#		endif /* __ARM_FEATURE_SVE */
#	endif /* __AVX512F__ */
/* ********************* [^] __HAS_512_BIT_VECTOR__ [^] ********************* */

/* ********************* [v] __HAS_256_BIT_VECTOR__ [v] ********************* */
#	ifdef __AVX2__ /* (256-BIT ADVANCED VECTOR EXTENSIONS) V2 */
#		define __HAS_256_BIT_VECTOR__
#	else
#		ifdef __AVX__ /* (256-BIT ADVANCED VECTOR EXTENSIONS) */
#			define __HAS_256_BIT_VECTOR__
#		else
#			ifdef __ARM_FEATURE_SVE /* SCALABLE VECTOR EXTENSION */
#				ifdef __ARM_FEATURE_SVE_BITS
#					if (__ARM_FEATURE_SVE_BITS >= 256)
#						define __HAS_256_BIT_VECTOR__
#					endif /* __ARM_FEATURE_SVE_BITS >= 256 */
#				endif /* __ARM_FEATURE_SVE_BITS */
#			endif /* __ARM_FEATURE_SVE */
#		endif /* __AVX__ */
#	endif /* __AVX2__ */
/* ********************* [^] __HAS_256_BIT_VECTOR__ [^] ********************* */

/* ********************* [v] __HAS_128_BIT_VECTOR__ [v] ********************* */
#	ifdef __SSE3__ /* INTEL SIMD */
#		define __HAS_128_BIT_VECTOR__
#	else
#		ifdef __SSE2__ /* INTEL SIMD */
#			define __HAS_128_BIT_VECTOR__
#		else
#			ifdef __SSE__ /* INTEL SIMD */
#				define __HAS_128_BIT_VECTOR__
#			else
#				ifdef __ARM_NEON__ /* ARM NEON SIMD */
#					define __HAS_128_BIT_VECTOR__
#				else
#					ifdef __ARM_NEON /* ARM NEON SIMD */
#						define __HAS_128_BIT_VECTOR__
#					endif /* __ARM_NEON */
#				endif /* __ARM_NEON__ */
#			endif /* __SSE__ */
#		endif /* __SSE2__ */
#	endif /* __SSE3__ */
/* ********************* [^] __HAS_128_BIT_VECTOR__ [^] ********************* */

/* ************************ [v] __HAS_128_BIT__ [v] ************************* */
#	ifdef __SIZEOF_INT128__
#		if (__SIZEOF_INT128__ == 16)
#			define __HAS_128_BIT__
#		endif /* __SIZEOF_INT128__ == 16 */
#	endif /* __SIZEOF_INT128__ */
/* ************************ [^] __HAS_128_BIT__ [^] ************************* */

/* ************************* [v] __HAS_64_BIT__ [v] ************************* */
#	ifdef __SYSTEM_32_BIT__
#		ifdef __STDC_VERSION__
#			if (__STDC_VERSION__ >= 199901L)
#				define __HAS_64_BIT__
#			endif /* __STDC_VERSION__ >= 199901L */
#		endif /* __STDC_VERSION__ */
#	else
#		ifdef __SYSTEM_16_BIT__
#			ifdef __STDC_VERSION__
#				if (__STDC_VERSION__ >= 199901L)
#					define __HAS_64_BIT__
#				endif /* __STDC_VERSION__ >= 199901L */
#			endif /* __STDC_VERSION__ */
#		endif /* __SYSTEM_16_BIT__ */
#	endif /* __SYSTEM_32_BIT__ */
/* ************************* [^] __HAS_64_BIT__ [^] ************************* */

/* ************************ [v] TI CGT CCS (POP) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */

#	ifdef LOCALMACRO__ARCHITECTURE_FOUND
#		undef LOCALMACRO__ARCHITECTURE_FOUND
#	else
#		warning "CPU ARCHITECTURE COULDN'T FOUND"
#	endif /* LOCALMACRO__ARCHITECTURE_FOUND */

#endif /* !ARCHITECTURE_H */

/* * * * * * * * * * * /!\ AUTOMATIC EOF TREATMENT! /!\ * * * * * * * * * * * *\
 * * AT THE ALL END OF FILES, I AM ADDING A SPECIAL BYTE <0X1A> TO END THE  * *
 * *                       FILE IN DOS, CP/M SYSTEMS                        * *
 * *   "//" FOR HANDLING THE BYTE IN MODERN COMPILERS AND #define IS FOR    * *
 * *       HANDLING "//" SYNTAX WHICH IS NOT SUPPORTED ON OLD SYSTEMS       * *
\* * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * */
#undef __LIBCMT__END_OF_FILE__
#define __LIBCMT__END_OF_FILE__ //
