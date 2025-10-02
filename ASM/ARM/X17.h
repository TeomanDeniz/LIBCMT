/******************************************************************************\
# H - X17                                        #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2025/09/15 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/09/29 : #    ::::!!!1!!1!!!1!!!::     #
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
|* GET_X17 : #define () : SET X17 INTO A VARIABLE                             *|
|* get_x17 :            :                                                     *|
|*.........:............:.....................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|* WITH THESE FUNCTIONS, YOU'RE ABLE TO MOVE AND GET VALUES FROM ARM AND      *|
|* AARCH CPUS' REGISTER (X17) AND STACK WITH DIFFERENT DATA SIZES AND ARCHS.  *|
|*                                                                            *|
|* NOTE: ON 32-BIT SYSTEMS, R17 REGISTER IS USED.                             *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* O - EXAMPLE 1: READ X17 INTO A VARIABLE                                    *|
|* :                                                                          *|
|* ;.., uint64_t myValue;                                                     *|
|*    :                                                                       *|
|*    : GET_X17(myValue);  // > MOV X17 CONTENTS INTO myValue                 *|
|*    ;..,                                                                    *|
|*       : myValue NOW HOLDS THE VALUE FROM X17                               *|
|*                                                                            *|
\******************************************************************************/

#ifndef X17_H
#	define X17_H 202509 /* VERSION */

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../../ENVIRONMENTS/CPU.h" /*
#	 define __CPU_ARM__
#	        */
#	include "../../ENVIRONMENTS/ARCHITECTURE.h" /*
#	 define __SYSTEM_64_BIT__
#	        */
#	include "../../CHECK_FEATURE/INLINE_ASM.h" /*
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
#		define GET_X17(_) \
			"ERROR - INLINE ASM DOES NOT SUPPORTED IN YOUR COMPILER :-("
#	endif /* !IS__INLINE_ASM__SUPPORTED */

#	ifndef GET_X17
#		ifndef __CPU_ARM__ /* UH-OH2 .3. */
#			define GET_X17(_) \
				"ERROR - YOU'RE NOT USING AN ARM CPU TO USE THIS COMMAND >:("
#		endif /* !__CPU_ARM__ */
#	endif /* !GET_X17 */

#	ifndef GET_X17
#		ifndef __SYSTEM_64_BIT__ /* UH-OH3 .A. */
#			define GET_X17(_) \
				"ERROR - YOUR ARCHITECTURE DOESN'T SUPPORT THIS COMMAND D:<"
#		endif /* !__SYSTEM_64_BIT__ */
#	endif /* !GET_X17 */

/* ************************** [v] __CPU_ARM__ [v] *************************** */
#	ifdef __CPU_ARM__
#		ifdef INLINE_ASM_TYPE__ISO
#			define LOCALMACRO__X17_GET(__REGISTER__) \
				__asm__ __volatile__ (\
					"mov %0, x17"\
					: "=r"(__REGISTER__)\
					: \
					: \
				)
#		else
#			ifdef __CC_ARM
#				if (__ARMCC_VERSION <= 600000) /* ARMCC V5 */
#					define LOCALMACRO__X17_GET(__REGISTER__) \
						__asm\
						{\
							MOV __REGISTER__, X17\
						}
#				else /* __ARMCC_VERSION > 600000 */
#					define LOCALMACRO__X17_GET(__REGISTER__) \
						asm volatile (\
							"mov %0, x17"\
							: "=r"(__REGISTER__)\
							: \
							: \
						)
#				endif /* __ARMCC_VERSION <= 600000 */
#			endif /* __CC_ARM */
#			ifndef LOCALMACRO__X17_GET
#				ifdef __GNUC__
#					define LOCALMACRO__X17_GET(__REGISTER__) \
						asm volatile (\
							"mov %0, x17"\
							: "=r"(__REGISTER__)\
							: \
							: \
						)
#				endif /* __GNUC__ */
#			endif /* !LOCALMACRO__X17_GET */
#			ifndef LOCALMACRO__X17_GET
#				ifdef __clang__
#					define LOCALMACRO__X17_GET(__REGISTER__) \
						asm volatile (\
							"mov %0, x17"\
							: "=r"(__REGISTER__)\
							: \
							: \
						)
#				endif /* __clang__ */
#			endif /* !LOCALMACRO__X17_GET */
#		endif /* INLINE_ASM_TYPE__ISO */
#	endif /* __CPU_ARM__ */
/* ************************** [^] __CPU_ARM__ [^] *************************** */

#	ifndef GET_X17
#		define GET_X17(VAR) \
			{\
				register void	*__REGISTER__;\
				\
				LOCALMACRO__X17_GET(__REGISTER__);\
				(VAR) = __REGISTER__;\
			}
#	endif /* !GET_X17 */

/* *************************** [v] C++ (POP) [v] **************************** */
#	ifdef __cplusplus /* C++ */
}
#	endif /* __cplusplus */
/* *************************** [^] C++ (POP) [^] **************************** */

/* *************************** [v] LOWERCASE [v] **************************** */
#	define get_x17 GET_X17
/* *************************** [^] LOWERCASE [^] **************************** */

#endif /* !X17_H */
