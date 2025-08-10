/******************************************************************************\
# H - INLINE_ASM                                 #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2025/08/10 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - AGPL-3.0  :: Update - 2025/08/10 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*            NAME           :   TYPE    :             DESCRIPTION            *|
|*...........................:...........:....................................*|
|* IS__INLINE_ASM__SUPPORTED : #define   : DEFINED IF THE COMPILER SUPPORTS   *|
|*                           :           : INLINE ASSEMBLY SCRIPTING          *|
|*...........................:...........:....................................*|
|* INLINE_ASM_TYPE__GNU      : #define   : GNU-STYLE EXTENDED INLINE ASM      *|
|*...........................:...........:....................................*|
|* INLINE_ASM_TYPE__MSVC     : #define   : MICROSOFT VISUAL C++ BLOCK STYLE   *|
|*...........................:...........:....................................*|
|* INLINE_ASM_TYPE__BORLAND  : #define   : BORLAND/TURBO C SIMPLE STYLE       *|
|*...........................:...........:....................................*|
|* INLINE_ASM_TYPE__AZTEC    : #define   : AZTEC C BLOCK STYLE (X86)          *|
|*...........................:...........:....................................*|
|* INLINE_ASM_TYPE__LATTICE  : #define   : LATTICE C STRING STYLE (68K/AMIGA) *|
|*...........................:...........:....................................*|
|* INLINE_ASM_TYPE__INTEL_MS : #define   : INTEL C MS-STYLE (SINGLE LINE)     *|
|*...........................:...........:....................................*|
|* INLINE_ASM_TYPE__WATCOM   : #define   : WATCOM C PRAGMA/BLOCK STYLE        *|
|*...........................:...........:....................................*|
|* INLINE_ASM_TYPE__ARM      : #define   : ARM COMPILER STYLE                 *|
|*...........................:...........:....................................*|
|* INLINE_ASM_TYPE__KEIL     : #define   : KEIL EMBEDDED STYLE                *|
|*...........................:...........:....................................*|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* THE MACRO "IS__INLINE_ASM__SUPPORTED" IS DEFINED IF THE COMPILER SUPPORTS  *|
|* INLINE ASSEMBLY LANGUAGE WITHIN C/C++ CODE.                                *|
|*                                                                            *|
|* ADDITIONALLY, ONE OF THE FOLLOWING MACROS WILL BE DEFINED TO INDICATE      *|
|* THE SPECIFIC SYNTAX STYLE SUPPORTED BY THE COMPILER:                       *|
|*                                                                            *|
|* - INLINE_ASM_TYPE__GNU: GCC/CLANG EXTENDED INLINE ASSEMBLY                 *|
|* - INLINE_ASM_TYPE__MSVC: MICROSOFT VISUAL C++ BLOCK STYLE                  *|
|* - INLINE_ASM_TYPE__BORLAND: BORLAND/TURBO C SIMPLE STYLE                   *|
|* - INLINE_ASM_TYPE__AZTEC: AZTEC C BLOCK STYLE (X86)                        *|
|* - INLINE_ASM_TYPE__LATTICE: LATTICE C STRING STYLE (68K/AMIGA)             *|
|* - INLINE_ASM_TYPE__INTEL_MS: INTEL C MS-STYLE (SINGLE LINE)                *|
|* - INLINE_ASM_TYPE__WATCOM: WATCOM C PRAGMA/BLOCK STYLE                     *|
|* - INLINE_ASM_TYPE__ARM: ARM COMPILER STYLE                                 *|
|* - INLINE_ASM_TYPE__KEIL: KEIL EMBEDDED STYLE                               *|
|*                                                                            *|
|* FOR DETAILED SYNTAX EXAMPLES, SEE THE "ASM SYNTAX STYLES" SECTION BELOW.   *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                          WHAT IS THIS FEATURE?                           #*|
|*############################################################################*|
|*                                                                            *|
|* INLINE ASSEMBLY ALLOWS EMBEDDING ASSEMBLY LANGUAGE CODE DIRECTLY WITHIN    *|
|* C/C++ SOURCE CODE. DIFFERENT COMPILERS USE DIFFERENT SYNTAXES.             *|
|*                                                                            *|
|* THIS LIBRARY DETECTS WHICH INLINE ASSEMBLY SYNTAX YOUR COMPILER SUPPORTS   *|
|* AND DEFINES THE APPROPRIATE MACRO TO INDICATE THE SYNTAX TYPE.             *|
|*                                                                            *|
|* SUPPORTED SYNTAX TYPES:                                                    *|
|* - GNU STYLE: EXTENDED INLINE ASSEMBLY (GCC, CLANG)                         *|
|* - MSVC STYLE: BLOCK ASSEMBLY (MICROSOFT VISUAL C++)                        *|
|* - BORLAND STYLE: SIMPLE INLINE (BORLAND/TURBO C++)                         *|
|* - AZTEC STYLE: BLOCK WITH BRACES (AZTEC C X86)                             *|
|* - LATTICE STYLE: STRING BASED (LATTICE C 68K/AMIGA)                        *|
|* - INTEL MS STYLE: SINGLE LINE (INTEL C)                                    *|
|* - WATCOM STYLE: PRAGMA/BLOCK (WATCOM C)                                    *|
|* - ARM STYLE: CONSTRAINTS (ARM COMPILER)                                    *|
|* - KEIL STYLE: PRAGMA BLOCKS (KEIL EMBEDDED)                                *|
|*                                                                            *|
|* FOR DETAILED SYNTAX EXAMPLES, SEE THE "ASM SYNTAX STYLES" SECTION BELOW.   *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                            ASM SYNTAX STYLES                             #*|
|*############################################################################*|
|*                                                                            *|
|* O - GNU STYLE (GCC, CLANG) - EXTENDED INLINE ASSEMBLY                      *|
|* :                                                                          *|
|* : int result;                                                              *|
|* : asm("movl %1, %0" : "=r"(result) : "r"(input_var) : );                   *|
|*                                                                            *|
|* O - MICROSOFT VISUAL C++ STYLE - BLOCK ASSEMBLY                            *|
|* :                                                                          *|
|* : int input_var = 42;                                                      *|
|* : __asm {                                                                  *|
|* :     mov eax, input_var                                                   *|
|* :     mov result, eax                                                      *|
|* : }                                                                        *|
|*                                                                            *|
|* O - BORLAND STYLE - SIMPLE INLINE                                          *|
|* :                                                                          *|
|* : asm mov eax, input_var                                                   *|
|* : asm mov result, eax                                                      *|
|*                                                                            *|
|* O - AZTEC C STYLE (X86) - BLOCK WITH BRACES                                *|
|* :                                                                          *|
|* : asm {                                                                    *|
|* :     mov ax, input_var                                                    *|
|* :     mov result, ax                                                       *|
|* : }                                                                        *|
|*                                                                            *|
|* O - LATTICE C STYLE (68K/AMIGA) - STRING BASED                             *|
|* :                                                                          *|
|* : asm("move.l input_var,d0");                                              *|
|* : asm("move.l d0,result");                                                 *|
|*                                                                            *|
|* O - INTEL C MS-STYLE - SINGLE LINE                                         *|
|* :                                                                          *|
|* : __asm mov eax, input_var                                                 *|
|* : __asm mov result, eax                                                    *|
|*                                                                            *|
|* O - WATCOM C STYLE - PRAGMA/BLOCK                                          *|
|* :                                                                          *|
|* : _asm {                                                                   *|
|* :     mov eax, input_var                                                   *|
|* :     mov result, eax                                                      *|
|* : }                                                                        *|
|* : OR PRAGMA AUXILIARY FUNCTIONS                                            *|
|* : #pragma aux myhalt = "mov ax,4C00h" "int 21h";                           *|
|* : void myhalt(void);                                                       *|
|*                                                                            *|
|* O - ARM COMPILER STYLE - CONSTRAINTS                                       *|
|* :                                                                          *|
|* : __asm("mov %0,%1" : "=r"(result) : "r"(input_var));                      *|
|*                                                                            *|
|* O - KEIL EMBEDDED STYLE - PRAGMA BLOCKS                                    *|
|* :                                                                          *|
|* : #pragma asm                                                              *|
|* : MOV A, #input_var                                                        *|
|* : MOV result, A                                                            *|
|* : #pragma endasm                                                           *|
|*                                                                            *|
\******************************************************************************/

#ifndef CHECK_FEATURE__INLINE_ASM_H
#	define CHECK_FEATURE__INLINE_ASM_H 202508 /* VERSION */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __STDC_VERSION__
#			if (__STDC_VERSION__ >= 199901L) /* C99 OR LATER */
#				define IS__INLINE_ASM__SUPPORTED
#			endif /* __STDC_VERSION__ >= 199901L */
#		endif /* __STDC_VERSION__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __cplusplus /* C++ */
#			define IS__INLINE_ASM__SUPPORTED
#		endif /* __cplusplus */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __GNUC__
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* __GNUC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef _MSC_VER /* MICROSOFT C COMPILER */
#			if (_MSC_VER >= 800) /* VISUAL C++ 1.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__MSVC
#			endif /* _MSC_VER >= 800 */
#		endif /* _MSC_VER */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __clang__ /* LLVM / CLANG */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* __clang__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __ICC /* INTEL C++ COMPILER - GNU/INTEL MS STYLE */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__INTEL_MS
#		endif /* __ICC */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __ECC /* INTEL C++ COMPILER - GNU/INTEL MS STYLE */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__INTEL_MS
#		endif /* __ECC */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __ICL /* INTEL C++ COMPILER - INTEL MS STYLE */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__INTEL_MS
#		endif /* __ICL */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __INTEL_COMPILER /* INTEL C++ COMPILER - INTEL MS STYLE */
#			define IS__INLINE_ASM__SUPPORTED
#			ifndef INLINE_ASM_TYPE__INTEL_MS
#				define INLINE_ASM_TYPE__INTEL_MS
#			endif
#		endif /* __INTEL_COMPILER */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __TINYC__ /* TCC - TINY C COMPILER */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* __TINYC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __WATCOMC__ /* OPEN WATCOM */
#			if (__WATCOMC__ >= 900) /* VERSION 9.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__WATCOM
#			endif /* __WATCOMC__ >= 900 */
#		endif /* __WATCOMC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __CODEGEARC__ /* BORLAND C++ (CODEGEAR) */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__BORLAND
#		endif /* __CODEGEARC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __BORLANDC__ /* BORLAND C++ */
#			if (__BORLANDC__ >= 0X200) /* VERSION 2.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__BORLAND
#			endif /* __BORLANDC__ >= 0X200 */
#		endif /* __BORLANDC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __LCC__ /* LCC */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* __LCC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef AZTEC_C /* AZTEC C COMPILER (X86) */
#			if (__VERSION >= 0X510) /* VERSION 5.10+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__AZTEC
#			endif /* __VERSION >= 0X510 */
#		endif /* AZTEC_C */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __AZTEC_C__ /* AZTEC C COMPILER (X86) */
#			if (__VERSION >= 0X510) /* VERSION 5.10+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__AZTEC
#			endif /* __VERSION >= 0X510 */
#		endif /* __AZTEC_C__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __DECC /* COMPAQ C/C++ */
#			if (__DECC_VER >= 50090001) /* VERSION 5.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __DECC_VER >= 50090001 */
#		endif /* __DECC */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __DECCXX /* COMPAQ C/C++ */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* __DECCXX */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef _ACC_ /* ACC */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* _ACC_ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __ACK__ /* AMSTERDAM COMPILER KIT */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* __ACK__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __COMPCERT__ /* COMPCERT */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* __COMPCERT__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __COVERITY__ /* COVERITY C/C++ STATIC ANALYZER */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* __COVERITY__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef _DICE /* DICE C */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__BORLAND
#		endif /* _DICE */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __SYSC__ /* DIGNUS SYSTEMS/C++ */
#			if (__SYSC_VER__ >= 15000) /* VERSION 1.50+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __SYSC_VER__ >= 15000 */
#		endif /* __SYSC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __convexc__ /* CONVEX C */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* __convexc__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __DCC__ /* DIAB C/C++ */
#			if (__VERSION_NUMBER__ >= 4000) /* VERSION 4.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __VERSION_NUMBER__ >= 4000 */
#		endif /* __DCC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __HP_cc /* HP ANSI C */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* __HP_cc */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __CMB__ /* ALTIUM MICROBLAZE C */
#			if (__VERSION__ >= 2)
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __VERSION__ >= 2 */
#		endif /* __CMB__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __CHC__ /* ALTIUM MICROBLAZE C */
#			if (__VERSION__ >= 2)
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __VERSION__ >= 2 */
#		endif /* __CHC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __CC_ARM /* ARM C COMPILER */
#			if (__ARMCC_VERSION >= 200000) /* VERSION 2.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__ARM
#			endif /* __ARMCC_VERSION >= 200000 */
#		endif /* __CC_ARM */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __COMO__ /* COMEAU C++ */
#			if (__COMO_VERSION__ >= 200) /* VERSION 2.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __COMO_VERSION__ >= 200 */
#		endif /* __COMO__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef _CRAYC /* CRAY C COMPILER */
#			if (_RELEASE >= 6) /* VERSION 6.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* _RELEASE >= 6 */
#		endif /* _CRAYC */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __DMC__ /* DIGITAL MARS */
#			if (__DMC__ >= 0X700) /* VERSION 7.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__BORLAND
#			endif /* __DMC__ >= 0X700 */
#		endif /* __DMC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __DJGPP__ /* MS-DOS GCC COMPILER */
#			if (__DJGPP__ >= 2) /* VERSION 2+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __DJGPP__ >= 2 */
#		endif /* __DJGPP__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __EDG__ /* EDG C++ FRONTEND */
#			if (__EDG_VERSION__ >= 200) /* VERSION 2.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __EDG_VERSION__ >= 200 */
#		endif /* __EDG__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __PATHCC__ /* EKOPATH */
#			if (__PATHCC__ >= 2) /* VERSION 2.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __PATHCC__ >= 2 */
#		endif /* __PATHCC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __FCC_VERSION /* FUJITSU C++ */
#			if (__FCC_VERSION >= 40000) /* VERSION 4.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __FCC_VERSION >= 40000 */
#		endif /* __FCC_VERSION */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __ghs__ /* GREEN HILLS C/C++ */
#			if (__ghs__ >= 1)
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __ghs__ >= 1 */
#		endif /* __ghs__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __HP_aCC /* HP AC++ */
#			if (__HP_aCC >= 60000) /* A.06.00+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __HP_aCC >= 60000 */
#		endif /* __HP_aCC */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __IAR_SYSTEMS_ICC__ /* IAR C/C++ */
#			if (__VER__ >= 800) /* VERSION 8.00+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __VER__ >= 800 */
#		endif /* __IAR_SYSTEMS_ICC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __ibmxl__ /* IBM XL C/C++ (CLANG-BASED VERSIONS) */
#			if (__ibmxl_vrm__ >= 0X01000000) /* VERSION 1.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __ibmxl_vrm__ >= 0X01000000 */
#		endif /* __ibmxl__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __xlC__ /* IBM XL C/C++ (LEGACY VERSIONS) */
#			if (__IBMC__ >= 0X0600) /* VERSION 6.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __IBMC__ >= 0X0600 */
#		endif /* __xlC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __IBMC__ /* IBM Z/OS XL C */
#			if (__IBMC__ >= 0X0600) /* VERSION 6.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __IBMC__ >= 0X0600 */
#		endif /* __IBMC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __IBMCPP__ /* IBM Z/OS XL C++ */
#			if (__IBMCPP__ >= 0X0600) /* VERSION 6.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __IBMCPP__ >= 0X0600 */
#		endif /* __IBMCPP__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __IMAGECRAFT__ /* IMAGECRAFT C */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__BORLAND
#		endif /* __IMAGECRAFT__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __KCC__ /* KAI C++ */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* __KCC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __CA__ /* KEIL CARM - PRAGMA STYLE */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__KEIL
#		endif /* __CA__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __KEIL__ /* KEIL CARM - PRAGMA STYLE */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__KEIL
#		endif /* __KEIL__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __C166__ /* KEIL C166 - PRAGMA STYLE */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__KEIL
#		endif /* __C166__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __C51__ /* KEIL C51 - PRAGMA STYLE */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__KEIL
#		endif /* __C51__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __CX51__ /* KEIL C51 - PRAGMA STYLE */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__KEIL
#		endif /* __CX51__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __llvm__ /* LLVM / CLANG */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* __llvm__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __HIGHC__ /* METAWARE HEIGH/C++ */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* __HIGHC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __MWERKS__ /* METROWERKS CODEWARRIOR */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__BORLAND
#		endif /* __MWERKS__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef _MRI /* MICROTEC MRI */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* _MRI */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __NDPC__ /* MICROWAY NDP */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__BORLAND
#		endif /* __NDPC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __NDPX__ /* MICROWAY NDP */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__BORLAND
#		endif /* __NDPX__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __MINGW32__ /* MINGW-32 */
#			ifdef __MINGW32_MAJOR_VERSION
#				if (__MINGW32_MAJOR_VERSION >= 1)
#					define IS__INLINE_ASM__SUPPORTED
#					define INLINE_ASM_TYPE__GNU
#				endif /* __MINGW32_MAJOR_VERSION >= 1 */
#			endif /* __MINGW32_MAJOR_VERSION */
#		endif /* __MINGW32__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __MINGW64__ /* MINGW-W64 */
#			ifdef __MINGW64_VERSION_MAJOR
#				if (__MINGW64_VERSION_MAJOR >= 1)
#					define IS__INLINE_ASM__SUPPORTED
#					define INLINE_ASM_TYPE__GNU
#				endif /* __MINGW64_VERSION_MAJOR >= 1 */
#			endif /* __MINGW64_VERSION_MAJOR */
#		endif /* __MINGW64__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __sgi /* MIPSPRO */
#			if (_COMPILER_VERSION >= 700) /* VERSION 7.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* _COMPILER_VERSION >= 700 */
#		endif /* __sgi */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef sgi /* MIPSPRO */
#			if (_COMPILER_VERSION >= 700) /* VERSION 7.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* _COMPILER_VERSION >= 700 */
#		endif /* sgi */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __MRC__ /* MPW C++ */
#			if (__MRC__ >= 0X500) /* VERSION 5.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__BORLAND
#			endif /* __MRC__ >= 0X500 */
#		endif /* __MRC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef MPW_C /* MPW C++ */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__BORLAND
#		endif /* MPW_C */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef MPW_CPLUS /* MPW C++ */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__BORLAND
#		endif /* MPW_CPLUS */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __CC_NORCROFT /* NORCROFT C */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* __CC_NORCROFT */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __NWCC__ /* NWCC */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* __NWCC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __OPEN64__ /* OPEN64 */
#			if (__OPENCC__ >= 4) /* VERSION 4.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __OPENCC__ >= 4 */
#		endif /* __OPEN64__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __OPENCC__ /* OPEN64 */
#			if (__OPENCC__ >= 4) /* VERSION 4.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __OPENCC__ >= 4 */
#		endif /* __OPENCC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef ORA_PROC /* ORACLE PRO*C PRECOMPILER */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* ORA_PROC */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __SUNPRO_C /* ORACLE SOLARIS STUDIO */
#			if (__SUNPRO_C >= 0X500) /* VERSION 5.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __SUNPRO_C >= 0X500 */
#		endif /* __SUNPRO_C */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef _PACC_VER /* PALM C/C++ */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* _PACC_VER */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __POCC__ /* PELLES C */
#			if (__POCC__ >= 300) /* VERSION 3.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__MSVC
#			endif /* __POCC__ >= 300 */
#		endif /* __POCC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __PGI /* PORTLAND GROUP C/C++ */
#			if (__PGIC__ >= 7) /* VERSION 7.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __PGIC__ >= 7 */
#		endif /* __PGI */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __PGIC__ /* PORTLAND GROUP C/C++ */
#			if (__PGIC__ >= 7) /* VERSION 7.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __PGIC__ >= 7 */
#		endif /* __PGIC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __RENESAS__ /* RENESAS C/C++ */
#			if (__RENESAS_VERSION__ >= 0X0800) /* VERSION 8.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__BORLAND
#			endif /* __RENESAS_VERSION__ >= 0X0800 */
#		endif /* __RENESAS__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __HITACHI__ /* RENESAS C/C++ (HITACHI) */
#			if (__HITACHI_VERSION__ >= 0X0800) /* VERSION 8.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__BORLAND
#			endif /* __HITACHI_VERSION__ >= 0X0800 */
#		endif /* __HITACHI__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef SASC /* SAS/C */
#			if (__SASC__ >= 650) /* VERSION 6.50+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__BORLAND
#			endif /* __SASC__ >= 650 */
#		endif /* SASC */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __SASC /* SAS/C */
#			if (__SASC__ >= 650) /* VERSION 6.50+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__BORLAND
#			endif /* __SASC__ >= 650 */
#		endif /* __SASC */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __SASC__ /* SAS/C */
#			if (__SASC__ >= 650) /* VERSION 6.50+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__BORLAND
#			endif /* __SASC__ >= 650 */
#		endif /* __SASC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef _SCO_DS /* SCO OPENSERVER */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* _SCO_DS */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef SDCC /* SMALL DEVICE C COMPILER */
#			if (SDCC >= 256) /* VERSION 2.5.6+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* SDCC >= 256 */
#		endif /* SDCC */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __SNC__ /* SN COMPILER */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* __SNC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __VOSC__ /* STRATUS VOS C */
#			if (__VOSC__ == 1) /* ONLY ANSI C MODE (1) */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __VOSC__ == 1 */
#		endif /* __VOSC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __SC__ /* SYMANTEC C++ */
#			if (__SC__ >= 0X700) /* VERSION 7.0+*/
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__BORLAND
#			endif /* __SC__ >= 0X700 */
#		endif /* __SC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __TenDRA__ /* TENDRA C/C++ */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* __TenDRA__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __TI_COMPILER_VERSION__ /* TEXAS INSTRUMENTS C/C++ COMPILER */
#			if (__TI_COMPILER_VERSION__ >= 4009001) /* VERSION 4.9.1+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __TI_COMPILER_VERSION__ >= 4009001 */
#		endif /* __TI_COMPILER_VERSION__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef _TMS320C6X /* TEXAS INSTRUMENTS C/C++ COMPILER */
#			if (__TI_COMPILER_VERSION__ >= 4009001) /* VERSION 4.9.1+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __TI_COMPILER_VERSION__ >= 4009001 */
#		endif /* _TMS320C6X */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef _UCC /* ULTIMATE C/C++ */
#			if (_MAJOR_REV >= 2) /* VERSION 2.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__BORLAND
#			endif /* _MAJOR_REV >= 2 */
#		endif /* _UCC */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __USLC__ /* USL C */
#			if (__SCO_VERSION__ >= 302199801) /* VERSION 3.2+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __SCO_VERSION__ >= 302199801 */
#		endif /* __USLC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __VBCC__ /* VBCC */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__GNU
#		endif /* __VBCC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __ZTC__ /* ZORTECH C++ */
#			if (__ZTC__ >= 0X300) /* VERSION 3.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__BORLAND
#			endif /* __ZTC__ >= 0X300 */
#		endif /* __ZTC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __TURBOC__ /* TURBO C/C++ */
#			if (__TURBOC__ >= 0X295) /* VERSION 1.0+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__BORLAND
#			endif /* __TURBOC__ >= 0X295 */
#		endif /* __TURBOC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __PACIFIC__ /* PACIFIC C */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__BORLAND
#		endif /* __PACIFIC__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef MIRACLE /* MIRACLE C */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__BORLAND
#		endif /* MIRACLE */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef THINKC3 /* THINK C VERSION 3.X */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__BORLAND
#		endif /* THINKC3 */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef THINKC4 /* THINK C VERSION 4.X */
#			define IS__INLINE_ASM__SUPPORTED
#			define INLINE_ASM_TYPE__BORLAND
#		endif /* THINKC4 */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#	ifndef IS__INLINE_ASM__SUPPORTED
#		ifdef __CC65__ /* CC65 C COMPILER FOR 6502 */
#			if (__CC65__ >= 0x2A1) /* VERSION 2.10.1+ */
#				define IS__INLINE_ASM__SUPPORTED
#				define INLINE_ASM_TYPE__GNU
#			endif /* __CC65__ >= 0x2A1 */
#		endif /* __CC65__ */
#	endif /* !IS__INLINE_ASM__SUPPORTED */
#endif /* !CHECK_FEATURE__INLINE_ASM_H */
