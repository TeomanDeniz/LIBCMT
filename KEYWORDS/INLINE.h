/******************************************************************************\
# H - INLINE                                     #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2023/07/09 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - AGPL-3.0  :: Update - 2024/02/29 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*  NAME  :  TYPE   :                      DESCRIPTION                        *|
|*........:.........:.........................................................*|
|* INLINE : #define : THE FUNCTION IS NOW AN INLINE PASTE LIKE #INCLUDE.      *|
|*........:.........:.........................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::::: INLINE ::::::::::::::::::::::::::::::::: *|
|* JUST PUT THIS TAG ON THE BEGINNING OF THE FUNCTION. EZ LOL                 *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::: SHOW TIME :::::::::::::::::::::::::::::::: *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* ;.., INLINE void function(void)                                            *|
|*    : {                                                                     *|
|*    :     . . .                                                             *|
|*    : }                                                                     *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                            HOW NOT TO USE IT                             #*|
|*############################################################################*|
|*                                                                            *|
|* (1) DO NOT USE "STATIC" (STATIC INLINE) WHEN YOU DECIDE TO USE THIS        *|
|* KEYWORD ON A FUNCTION! "STATIC" IS GOING TO CANCEL "INLINE"!               *|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* ;.., // THIS MAKES YOUR FUNCTION JUST A STATIC FUNCTION:                   *|
|*    : static INLINE int test(void)                                          *|
|*    : {                                                                     *|
|*    :     return (15 + 42);                                                 *|
|*    : }                                                                     *|
|*                                                                            *|
|* (2) DO NOT USE "GOTO" KEYWORD INSIDE INLINE LIBRARY!                       *|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* ;.., // THIS IS WRONG:                                                     *|
|*    : static INLINE int test(void)                                          *|
|*    : {                                                                     *|
|*    :     LAYER:                                                            *|
|*    :     . . .                                                             *|
|*    :     GOTO LAYER;                                                       *|
|*    : }                                                                     *|
|*                                                                            *|
|* (3) YOU CAN'T USE STATIC VARIABLES INSIDE OF INLINE FUNCTION!              *|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* ;.., // WHAT DA DOG DOING?                                                 *|
|*    : static INLINE void test(void)                                         *|
|*    : {                                                                     *|
|*    :     static int dog;                                                   *|
|*    :     . . .                                                             *|
|*    : }                                                                     *|
|*                                                                            *|
|* (4) YOU CAN'T CALL ITSELF INSIDE OF INLINE. (YOU CAN'T DO RECURSIVE)       *|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* ;.., // YOU CAN'T CALL SOMETHING THAT DOESN'T EXIST IN THE BINNARY.        *|
|*    : static INLINE void inline_test(int a)                                 *|
|*    : {                                                                     *|
|*    :     inline_test(a + 1);                                               *|
|*    :     . . .                                                             *|
|*    : }                                                                     *|
|*                                                                            *|
|* (5) YOU CAN'T USE VA_LIST, VA_ARG (SIMPLY ...) KEYWORD ON INLINE FUNCTION! *|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* ;.., // NO SHIT                                                            *|
|*    : static INLINE void inline_test(int a, ...)                            *|
|*    : {                                                                     *|
|*    :     va_list list;                                                     *|
|*    :     . . .                                                             *|
|*    : }                                                                     *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|* IT PUTS THE COMMANDS YOU WRITE IN THE INLINE FUNCTION DIRECTLY TO THE      *|
|* PLACE WHERE YOU USED YOUR INLINE FUNCTION.                                 *|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* ;.., // LET'S IMAGINE WE HAVE AN INLINE FUNCTION:                          *|
|* :  : INLINE int test(void)                                                 *|
|* :  : {                                                                     *|
|* :  :     return (15 + 42);                                                 *|
|* :  : }                                                                     *|
|* :                                                                          *|
|* ;.., // LET'S IMAGINE IT IS USED IN OUR MAIN FUNCTION:                     *|
|* :  : int main(void)                                                        *|
|* :  : {                                                                     *|
|* :  :     printf("%d", test());                                             *|
|* :  :     return (0);                                                       *|
|* :  : }                                                                     *|
|* :                                                                          *|
|* ;.., // AND THAT MAKES THE MAIN FUNCTION DURING COMPILING PROCESS:         *|
|*    : int main(void)                                                        *|
|*    : {                                                                     *|
|*    :     printf("%d", (15 + 42));                                          *|
|*    :     return (0);                                                       *|
|*    : }                                                                     *|
|*                                                                            *|
|* IT WAS JUST AN EXAMPLE, YOU'RE FEEL FREE TO FILL YOUR FUNCTION AS MUCH AS  *|
|* YOU CAN. BUT PLEASE BE AWARE WHAT TO NOT DO INSIDE OF AN INLINE FUNCTION   *|
|* BY READIN THE "HOW NOT TO USE IT" LIST AT THE TOP!                         *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                                SIDE NOTES                                #*|
|*############################################################################*|
|*                                                                            *|
|* [[clang::always_inline]] NOT WORKING IN CLANG. TOO BAD!                    *|
|*                                                                            *|
\******************************************************************************/

/* ************************* [v] VERSION CONTROL [v] ************************ */
#define LIBRARY_VERSION 202402 /* VERSION */
#ifdef INLINE_H
#	if (INLINE_H < LIBRARY_VERSION)
#		undef INLINE_H /* OLD VERSION DETECTED */
#	endif /* INLINE_H < LIBRARY_VERSION */
#endif /* INLINE_H */
#undef LIBRARY_VERSION
/* ************************* [^] VERSION CONTROL [^] ************************ */

#ifndef INLINE_H
/* *************************** [v] TI CGT CCS [v] *************************** */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_push /* TI CGT CCS COMPILER DIRECTIVES */
#		pragma CHECK_MISRA("-5.4") /* TAG NAMES SHALL BE A UNIQUE IDENTIFIER */
#		pragma CHECK_MISRA("-19.3") /* THE #INCLUDE DIRECTIVE SHALL BE FOLLOWED
#		BY EITHER A <FILENAME> OR "FILENAME" SEQUENCE */
#	endif /* __TI_COMPILER_VERSION__ */
/* *************************** [^] TI CGT CCS [^] *************************** */
#	ifdef __cplusplus /* C++ */
		extern "C" {
#	endif /* __cplusplus */
#	define INLINE_H 202402 /* VERSION */
/* ****************************** [v] RESET [v] ***************************** */
#	undef INLINE
/* ****************************** [^] RESET [^] ***************************** */
#	ifdef _MSC_VER /* MICROSOFT C++ */
#		define INLINE __inline__ __forceinline
#	else
#		ifdef __cplusplus /* C++ */
#			define INLINE inline
#		else
#			ifdef __TINYC__ /* TCC (TINY C COMPILER) */
#				define INLINE __inline__
#			else
#				ifdef __clang__ /* CLANG / LLVM */
#					define INLINE __inline__
#				else
#					if (\
						defined(__GNUC__) && /* IF GCC */\
						(\
							(__GNUC__ >= 4) && /* IF GEQ 4.X.X */\
							(__GNUC_MINOR__ >= 2) /* IF GEQ X.2.X */\
						)\
					) /* IS GCC VERSION 4.2.X OR GREATHER (MAXIMUM C99) */
#						ifdef __DJGPP__
#							define INLINE __inline__ \
							__attribute__((__gnu_inline__))
#						else
#							define INLINE __inline__ \
								__attribute__((\
									__gnu_inline__, \
									always_inline\
								))
#						endif /* DJGPP */
#					else /* __attribute__ DOESN'T SUPPORTED */
#						if (\
							(__GNUC__ >= 2) && /* IF GRE 2.X.X */\
							(__GNUC_MINOR__ >= 7) && /* IF GEQ X.7.X */\
						) /* GCC VERSION 2.7.X OR GREATHER (MAXIMUM C89) */
#							define INLINE __inline__
#						else /* GCC DOESN'T SUPPORT INLINE */
#							define INLINE /* NULL */
#						endif /* GNUC VERSION 2.7.1 */
#					endif /* GNUC VERSION 4.2.X */
#				endif /* __clang__ */
#			endif /* __TINYC__ */
#		endif /* __cplusplus */
#	endif /* _MSC_VER */
#	ifdef __cplusplus /* C++ */
		}
#	endif /* __cplusplus */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
#endif /* INLINE_H */
