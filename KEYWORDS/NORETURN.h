/******************************************************************************\
# H - NORETURN                                   #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2023/07/07 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/11/30 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*   NAME   :  TYPE   :                     DESCRIPTION                       *|
|*..........:.........:.......................................................*|
|* NORETURN : #define : TELLS THE COMPILER THAT THE PROGRAM WILL END IN THIS  *|
|* noreturn :         : FUNCTION.                                             *|
|*..........:.........:.......................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::: NORETURN :::::::::::::::::::::::::::::::: *|
|* JUST PUT THIS TAG AT THE BEGINNING OF THE FUNCTION.                        *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::: SHOW TIME :::::::::::::::::::::::::::::::: *|
|* O - EXAMPLES                                                               *|
|* :                                                                          *|
|* ;.., UPPERCASE                                                             *|
|* :  :                                                                       *|
|* : 1| NORETURN void function(void)                                          *|
|* : 2| {                                                                     *|
|* : 3|     . . .                                                             *|
|* : 4|     if (. . .)                                                        *|
|* : 5|         exit(0);                                                      *|
|* : 6|     . . .                                                             *|
|* : 7| }                                                                     *|
|* :  :                                                                       *|
|* :                                                                          *|
|* ;.., LOWERCASE                                                             *|
|*    :                                                                       *|
|*   1| noreturn void function(void)                                          *|
|*   2| {                                                                     *|
|*   3|     . . .                                                             *|
|*   4|     if (. . .)                                                        *|
|*   5|         exit(0);                                                      *|
|*   6|     . . .                                                             *|
|*   7| }                                                                     *|
|*    :                                                                       *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                            WHAT DOES THAT DO?                            #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|* WARNS THE COMPILER THAT THE FUNCTION MAY TERMINATE THE PROGRAM WITHOUT     *|
|* RETURNING TO "main()". THE ONLY WAY TO DO THAT IS BY USING THE exit()      *|
|* FUNCTION.                                                                  *|
|*                                                                            *|
|* FOR OPTIMIZATION PURPOSES.                                                 *|
|*                                                                            *|
\******************************************************************************/

#ifndef NORETURN_H
#	define NORETURN_H 202508 /* VERSION */

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

#	ifndef __STDNORETURN_H
#		define __STDNORETURN_H /* <stdnoreturn.h> */

#		ifdef __noreturn_is_defined
#			define NORETURN noreturn
#		else
#			ifdef __cplusplus
#				define NORETURN [[noreturn]]
#				define __noreturn_is_defined 1
#			else
#				ifdef __GNUC__
#					ifdef __clang__
#						if (\
							(__clang_major__ >= 3) && /* IF GEQ 3.X */\
							(__clang_minor__ >= 3) /* IF GEQ X.3 */\
						) /* IS CLANG VERSION 3.3 OR GREATHER (C99) */
#							define NORETURN _Noreturn
#							define __noreturn_is_defined 1
						else
#							if (\
								(__GNUC__ >= 4) && /* IF GEQ 4.X.X */\
								(__GNUC_MINOR__ >= 2) /* IF GEQ X.2.X */\
							) /* IS GCC VERSION 4.2.X OR GREATHER (C99) */
#								define NORETURN __attribute__((noreturn))
#								define __noreturn_is_defined 1
#							else
#								define NORETURN /* EMPTY */
#							endif /* GNUC-4.2.X */
#						endif /* CLANG-3.3 */
#					else
#						if (\
							(__GNUC__ >= 4) && /* IF GEQ 4.X.X */\
							(__GNUC_MINOR__ >= 2) /* IF GEQ X.2.X */\
						) /* IS GCC VERSION 4.2.X OR GREATHER (C99) */
#							define NORETURN __attribute__((noreturn))
#							define __noreturn_is_defined 1
#						else
#							define NORETURN /* EMPTY */
#						endif /* GNUC-4.2.X */
#					endif /* __clang__ */
#				else
#					ifdef __clang__
#						if (\
							(__clang_major__ >= 3) && /* IF GEQ 3.X */\
							(__clang_minor__ >= 3) /* IF GEQ X.3 */\
						) /* IS CLANG VERSION 3.3 OR GREATHER (C99) */
#							define NORETURN _Noreturn
#							define __noreturn_is_defined 1
						else
#							define NORETURN /* EMPTY */
#						endif /* CLANG-3.3 */
#					else
#						define NORETURN /* EMPTY */
#					endif /* __clang__ */
#				endif /* __GNUC__ */
#			endif /* __cplusplus */
#		endif /* __noreturn_is_defined */
#	else
#		define NORETURN noreturn
#	endif /* !__STDNORETURN_H */

/* ************************ [v] TI CGT CCS (POP) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */

#endif /* !NORETURN_H */

#ifdef __EOF__
#	undef __EOF__
#endif /* __EOF__ */
#define __EOF__ //  <- FOR DOS, CP/M, ETC
