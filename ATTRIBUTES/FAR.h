/******************************************************************************\
# H - FAR                                        #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2025/03/07 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/08/27 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*  NAME  :  TYPE   :                   DESCRIPTION                           *|
|*........:.........:.........................................................*|
|* FAR    : #define : MARKS A MEMORY SEGMENT OR POINTER AS FAR, ALLOWING      *|
|*        :         : ACCESS BEYOND 64KB LIMITS.                              *|
|*........:.........:.........................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::::: FAR ::::::::::::::::::::::::::::::::::: *|
|* IT DEFINES THE MEMORY ACCESS TYPE BASED ON COMPILER AND PLATFORM.          *|
|* IN 16-BIT SYSTEMS, IT EXPANDS TO A FAR POINTER KEYWORD                     *|
|* ("far", "_far", etc.) IN MODERN SYSTEMS, IT MAY BE EMPTY OR NOT USED.      *|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::: EXAMPLES :::::::::::::::::::::::::::::::: *|
|* O - EXAMPLE 1 (VARIABLES)                                                  *|
|* :                                                                          *|
|* ;.., FAR int far_var;                                                      *|
|* :  : far_var = 42;                                                         *|
|* :                                                                          *|
|* ;... THIS CREATES AN INTEGER VARIABLE THAT USES A FAR MEMORY POINTER.      *|
|*                                                                            *|
|* O - EXAMPLE 2 (POINTERS)                                                   *|
|* :                                                                          *|
|* ;.., FAR char *far_ptr;                                                    *|
|* :  : far_ptr = "Hello, world!";                                            *|
|* :                                                                          *|
|* ;... A STRING POINTER STORED IN FAR MEMORY SPACE.                          *|
|*                                                                            *|
|* O - EXAMPLE 3 (STRUCTS)                                                    *|
|* :                                                                          *|
|* ;.., struct FAR far_struct                                                 *|
|* :  : {                                                                     *|
|* :  :     int id;                                                           *|
|* :  :     char name[20];                                                    *|
|* :  : };                                                                    *|
|* :                                                                          *|
|* ;... A STRUCT THAT IS STORED IN FAR MEMORY.                                *|
|*                                                                            *|
|* O - EXAMPLE 4 (FUNCTION POINTERS)                                          *|
|* :                                                                          *|
|* ;.., FAR void (*far_function)(void);                                       *|
|* :                                                                          *|
|* ;... A FUNCTION POINTER IN FAR MEMORY.                                     *|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::: PRO-TIP ::::::::::::::::::::::::::::::::  *|
|* - CHECK YOUR COMPILER DOCUMENTATION FOR MEMORY MODELS AND POINTER TYPES.   *|
|*                                                                            *|
|* FOR SUPPORT REALLY OLD COMPILERS: I STRICTLY AVOID USING #IF IN THIS FILE. *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|* [FAR] IS A MEMORY QUALIFIER USED TO ACCESS MEMORY LOCATIONS THAT ARE FAR   *|
|* FROM THE CODE SEGMENT IN 16-BIT ARCHITECTURES.                             *|
|*                                                                            *|
|* IN OLD 16-BIT COMPILERS (MS-DOS, TURBO C, WATCOM, ETC.), POINTERS CAN BE   *|
|* NEAR (WITHIN A SINGLE SEGMENT) OR FAR (CROSSING SEGMENTS).                 *|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::::: HOW? :::::::::::::::::::::::::::::::::: *|
|* MEMORY SEGMENTATION IN 16-BIT SYSTEMS WORKS WITH 64KB SEGMENTS.            *|
|* A NEAR POINTER IS 16-BITS (OFFSET ONLY), WHILE A FAR POINTER IS 32-BITS    *|
|* (SEGMENT:OFFSET).                                                          *|
|*                                                                            *|
|* O - EXAMPLES                                                               *|
|* :                                                                          *|
|* ;.., int near_ptr_var;                                                     *|
|* :  : int FAR far_ptr_var;                                                  *|
|* :                                                                          *|
|* ;... NEAR POINTERS CAN ACCESS ONLY WITHIN THEIR SEGMENT (64KB LIMIT).      *|
|* :                                                                          *|
|* ;... FAR POINTERS CAN ACCESS THE FULL 1MB ADDRESS SPACE.                   *|
|*                                                                            *|
|* O - FUNCTION POINTERS                                                      *|
|* :                                                                          *|
|* ;.., void (*near_func)(void);                                              *|
|* :  : FAR void (*far_func)(void);                                           *|
|* :                                                                          *|
|* ;... "near_func" CAN ONLY CALL FUNCTIONS WITHIN THE SAME SEGMENT.          *|
|* :                                                                          *|
|* ;... "far_func" CAN CALL FUNCTIONS IN DIFFERENT SEGMENTS.                  *|
|*                                                                            *|
|* ::::::::::::::::::::::::::: PRO-TIPS ::::::::::::::::::::::::::::::::::::  *|
|* - IN MODERN SYSTEMS (32/64-BIT), FAR POINTERS ARE NOT NEEDED.              *|
|* - ON MODERN COMPILERS, "FAR" IS USUALLY DEFINED AS EMPTY ("#define FAR").  *|
|* - FAR POINTERS ARE SLOWER BECAUSE THEY REQUIRE SEGMENT SWITCHING.          *|
|* - ONLY USE "FAR" IF YOU'RE COMPILING FOR 16-BIT REAL MODE ENVIRONMENTS.    *|
|*                                                                            *|
\******************************************************************************/

#ifndef FAR_H
#	define FAR_H 202508 /* VERSION */

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

#	ifndef __cplusplus /* C++ */
/* **************************** [v] INCLUDES [v] **************************** */
#		include	"../ENVIRONMENTS/ARCHITECTURE.h" /*
#		 define __SYSTEM_8_BIT__
#		 define __SYSTEM_16_BIT__
#		        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ************************* [v] SEALING SYSTEM [v] ************************* *\
|* *   SEALING SYSTEM IS FOR AVOID USING "#IF" PRE-PROCESSING COMMANDS TO   * *|
|* * MAKE THE LIBRARY CAN ABLE TO WORK AND COMPILE WITHOUT ANY WARNINGS AND * *|
|* *         ERRORS IN EVERY C COMPILER AND C COMPILER VERSIONS!!!          * *|
\* ************************************************************************** */
#		ifdef M_I86SM
#			define LOCALMACRO__FAR_MODE_IS_TRUE
#		else
#			ifdef M_I86MM
#				define LOCALMACRO__FAR_MODE_IS_TRUE
#			else
#				ifdef __SMALL__
#					define LOCALMACRO__FAR_MODE_IS_TRUE
#				else
#					ifdef __MEDIUM__
#						define LOCALMACRO__FAR_MODE_IS_TRUE
#					else
#						ifdef __MSDOS__
#							define LOCALMACRO__FAR_MODE_IS_TRUE
#						else
#							ifdef _DOS
#								define LOCALMACRO__FAR_MODE_IS_TRUE
#							else
#								ifdef __SYSTEM_16_BIT__
#									define LOCALMACRO__FAR_MODE_IS_TRUE
#								else
#									ifdef __SYSTEM_8_BIT__
#										define LOCALMACRO__FAR_MODE_IS_TRUE
#									endif /* __SYSTEM_8_BIT__ */
#								endif /* __SYSTEM_16_BIT__ */
#							endif /* _DOS */
#						endif /* __MSDOS__ */
#					endif /* __MEDIUM__ */
#				endif /* __SMALL__ */
#			endif /* M_I86MM */
#		endif /* M_I86SM */
/* ************************* [^] SEALING SYSTEM [^] ************************* */

/* *************************** [v] DEFINE FAR [v] *************************** */
#		ifdef LOCALMACRO__FAR_MODE_IS_TRUE
#			ifndef FAR
#				ifdef _MSC_VER
#					define FAR _far
#				endif /* _MSC_VER */
#			endif /* FAR */
#			ifndef FAR
#				ifdef __TURBOC__
#					define FAR _far
#				endif /* __TURBOC__ */
#			endif /* FAR */
#			ifndef FAR
#				ifdef __BORLANDC__
#					define FAR _far
#				endif /* __BORLANDC__ */
#			endif /* FAR */
#			ifndef FAR
#				ifdef __WATCOMC__
#					define FAR __far
#				endif /* __WATCOMC__ */
#			endif /* FAR */
#			ifndef FAR
#				ifdef __GNUC__
#					define FAR __attribute__((far))
#				endif /* __GNUC__ */
#			endif /* FAR */
#			ifndef FAR
#				define FAR far
#			endif /* FAR */
#		else
#			define FAR
#		endif /* LOCALMACRO__FAR_MODE_IS_TRUE */
/* *************************** [^] DEFINE FAR [^] *************************** */
#	endif /* !__cplusplus */

/* ************************ [v] TI CGT CCS (POP) [v] *******************#***** */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */

#endif /* !FAR_H */
