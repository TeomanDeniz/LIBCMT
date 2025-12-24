/******************************************************************************\
# H - ROM                                        #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2025/12/20 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/12/25 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|* NAME :  TYPE   :                        DESCRIPTION                        *|
|*......:.........:...........................................................*|
|* ROM  : #define : PLACES VARIABLES INTO READ-ONLY MEMORY (ROM / FLASH)      *|
|*      :         : USING THE BEST MECHANISM FOR THE TARGET COMPILER AND      *|
|*      :         : ARCHITECTURE                                              *|
|*      :         :                                                           *|
|*......:.........:...........................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|*  O - FOR CONSTANTS AND LOOKUP TABLES                                       *|
|*  :                                                                         *|
|* 1|                                                                         *|
|* 2| ROM int table[] = { 1, 2, 3, 4 };                                       *|
|* 3|                                                                         *|
|*  :                                                                         *|
|*                                                                            *|
|*  O - FOR STRINGS                                                           *|
|*  :                                                                         *|
|* 1|                                                                         *|
|* 2| ROM char message[] = "Hello";                                           *|
|* 3|                                                                         *|
|*  :                                                                         *|
|*                                                                            *|
\******************************************************************************/ 

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* "ROM" ABSTRACTS READ-ONLY MEMORY PLACEMENT ACROSS COMPILERS AND            *|
|* ARCHITECTURES.                                                             *|
|*                                                                            *|
|* DEPENDING ON THE TARGET, IT EXPANDS TO:                                    *|
|*                                                                            *|
|* O - "constexpr" OR "const" (C / C++)                                       *|
|*                                                                            *|
|* O - "PROGMEM" ON AVR                                                       *|
|*                                                                            *|
|* O - COMPILER-SPECIFIC SECTION ATTRIBUTES                                   *|
|*                                                                            *|
|* O - FLASH-SPECIFIC QUALIFIERS ON EMBEDDED TOOLCHAINS                       *|
|*                                                                            *|
|* THE GOAL IS TO ENSURE DATA IS STORED IN NON-WRITABLE MEMORY, CONSERVING    *|
|* RAM AND ENFORCING IMMUTABILITY.                                            *|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::::: NOTE :::::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* O - "ROM" IS INTENDED FOR DATA OBJECTS, NOT FUNCTIONS                      *|
|*                                                                            *|
|* O - DO NOT ASSUME RUNTIME ACCESS SEMANTICS ARE IDENTICAL ON ALL PLATFORMS  *|
|*                                                                            *|
|* O - ON AVR, SPECIAL ACCESS MACROS MAY BE REQUIRED FOR "PROGMEM" DATA       *|
|*                                                                            *|
\******************************************************************************/

#ifndef ROM_H
#	define ROM_H 202512 /* VERSION */
#	ifdef __cplusplus
#		if (__cplusplus >= 201103L)
#			define LOCALMACRO__CONST_FOR_ROM constexpr
#		endif /* __cplusplus >= 201103L */
#	endif /* __cplusplus */
#	ifndef LOCALMACRO__CONST_FOR_ROM
#		include "../ENVIRONMENTS/KNR_STYLE.H" /*
#		 define KNR_STYLE
#		        */
#		ifdef KNR_STYLE
#			define LOCALMACRO__CONST_FOR_ROM /* EMPRY */
#		else
#			define LOCALMACRO__CONST_FOR_ROM const
#		endif /* KNR_STYLE */
#	endif /* !LOCALMACRO__CONST_FOR_ROM */
#	ifdef __AVR__
#		define LOCALMACRO__AVR
#	else
#		ifdef ARDUINO_ARCH_AVR
#			define LOCALMACRO__AVR
#		endif /* ARDUINO_ARCH_AVR */
#	endif /* __AVR__ */
#	ifdef LOCALMACRO__AVR
#		undef LOCALMACRO__AVR
#		include <avr/pgmspace.h> /*
#		 define PROGMEM
#		        */
#		define ROM PROGMEM
#	endif /* LOCALMACRO__AVR */
#	ifndef ROM
#		ifdef __GNUC__
#			define ROM \
				LOCALMACRO__CONST_FOR_ROM __attribute__((section(".rodata")))
#		endif /* __GNUC__ */
#	endif /* !ROM */
#	ifndef ROM
#		ifdef __clang__
#			define ROM \
				LOCALMACRO__CONST_FOR_ROM __attribute__((section(".rodata")))
#		endif /* __clang__ */
#	endif /* !ROM */
#	ifndef ROM
#		ifdef __ICCARM__
#			define ROM LOCALMACRO__CONST_FOR_ROM __flash
#		endif /* __ICCARM__ */
#	endif /* !ROM */
#	ifndef ROM
#		ifdef __CC_ARM
#			define ROM \
				LOCALMACRO__CONST_FOR_ROM __attribute__((section("ER_RO")))
#		endif /* __CC_ARM */
#	endif /* !ROM */
#	ifndef ROM
#		ifdef __ARMCC_VERSION
#			define ROM \
				LOCALMACRO__CONST_FOR_ROM __attribute__((section("ER_RO")))
#		endif /* __ARMCC_VERSION */
#	endif /* !ROM */
#	ifndef ROM
#		define ROM LOCALMACRO__CONST_FOR_ROM
#	endif /* !ROM */
#endif /* !ROM_H */

/* * * * * * * * * * * /!\ AUTOMATIC EOF TREATMENT! /!\ * * * * * * * * * * * *\
 * * AT THE ALL END OF FILES, I AM ADDING A SPECIAL BYTE <0X1A> TO END THE  * *
 * *                       FILE IN DOS, CP/M SYSTEMS                        * *
 * *   "//" FOR HANDLING THE BYTE IN MODERN COMPILERS AND #define IS FOR    * *
 * *       HANDLING "//" SYNTAX WHICH IS NOT SUPPORTED ON OLD SYSTEMS       * *
\* * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * */
#undef __CMT__END_OF_FILE__
#define __CMT__END_OF_FILE__ //
