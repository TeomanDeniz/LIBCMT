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
# : License - GPL-3.0   :: Update - 2025/11/30 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*  NAME  :  TYPE   :                      DESCRIPTION                        *|
|*........:.........:.........................................................*|
|* INLINE : #define : THE FUNCTION IS NOW INLINED, SIMILAR TO A #INCLUDE.     *|
|*........:.........:.........................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::::: INLINE ::::::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* JUST PUT THIS TAG AT THE BEGINNING OF THE FUNCTION.                        *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::::: SHOW TIME :::::::::::::::::::::::::::::::: *|
|*  O - EXAMPLE                                                               *|
|*  :                                                                         *|
|* 1| INLINE void function(void)                                              *|
|* 2| {                                                                       *|
|* 3|     . . .                                                               *|
|* 4| }                                                                       *|
|*  :                                                                         *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                            HOW NOT TO USE IT                             #*|
|*############################################################################*|
|*                                                                            *|
|* (1) DO NOT USE "STATIC" (STATIC INLINE) WHEN YOU DECIDE TO USE THIS        *|
|* KEYWORD WITH A FUNCTION. "STATIC" IS GOING TO CANCEL "INLINE"! OR IT       *|
|* MAY LIMIT VISIBILITY. IF THE FUNCTION IS ONLY CALLED ONCE OR TWICE, IT MAY *|
|* NEVER BE INLINED. IF IT'S UNUSED, IT MAY STILL OCCUPY A SYMBOL. STILL,     *|
|* IT'S NOT WORTH RISKING.                                                    *|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* ;.., THIS MAKES YOUR FUNCTION JUST A STATIC:                               *|
|*    :                                                                       *|
|*   1| static INLINE int test(void)                                          *|
|*   2| {                                                                     *|
|*   3|     return (15 + 42);                                                 *|
|*   4| }                                                                     *|
|*    :                                                                       *|
|*                                                                            *|
|* (2) DO NOT USE "GOTO" KEYWORD INSIDE INLINE LIBRARY! IT'S TECHNICALLY      *|
|* ALLOWED BUT MAY CAUSE SOME SERIOUS OPTIMISATION PROBLEMS!                  *|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* ;.., THIS IS WRONG... THIS FEELS SO WRONG:                                 *|
|*    :                                                                       *|
|*   1| INLINE int test(void)                                                 *|
|*   2| {                                                                     *|
|*   3|     LAYER:                                                            *|
|*   4|     . . .                                                             *|
|*   5|     GOTO LAYER;                                                       *|
|*   6| }                                                                     *|
|*    :                                                                       *|
|*                                                                            *|
|* (3) YOU CAN'T USE STATIC VARIABLES INSIDE INLINE FUNCTIONS!                *|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* ;.., WHAT DA DOG DOING?                                                    *|
|*    :                                                                       *|
|*   1| INLINE void test(void)                                                *|
|*   2| {                                                                     *|
|*   3|     static int dog;                                                   *|
|*   4|     . . .                                                             *|
|*   5| }                                                                     *|
|*    :                                                                       *|
|*                                                                            *|
|* (4) YOU CAN'T CALL THE FUNCTION ITSELF INSIDE AN INLINE FUNCTION           *|
|*     SO, NO RECURSION                                                       *|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* ;.., YOU CAN'T CALL SOMETHING THAT DOESN'T EXIST IN THE BINARY.            *|
|*    :                                                                       *|
|*   1| INLINE void inline_test(int a)                                        *|
|*   2| {                                                                     *|
|*   3|     inline_test(a + 1);                                               *|
|*   4|     . . .                                                             *|
|*   5| }                                                                     *|
|*    :                                                                       *|
|*                                                                            *|
|* (5) YOU CAN'T USE "va_list", "va_arg" (OR ...) IN INLINE FUNCTIONS!        *|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* ;.., NO, DON'T!                                                            *|
|*    :                                                                       *|
|*   1| INLINE void inline_test(int a, ...)                                   *|
|*   2| {                                                                     *|
|*   3|     va_list list;                                                     *|
|*   4|     . . .                                                             *|
|*   5| }                                                                     *|
|*    :                                                                       *|
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
|* ;.., LET'S IMAGINE WE HAVE AN INLINE FUNCTION:                             *|
|* :  :                                                                       *|
|* : 1| INLINE int test(void)                                                 *|
|* : 2| {                                                                     *|
|* : 3|     return (15 + 42);                                                 *|
|* : 4| }                                                                     *|
|* :  :                                                                       *|
|* :                                                                          *|
|* ;.., LET'S IMAGINE IT IS USED IN OUR MAIN FUNCTION:                        *|
|* :  :                                                                       *|
|* : 1| int main(void)                                                        *|
|* : 2| {                                                                     *|
|* : 3|     printf("%d", test());                                             *|
|* : 4|     return (0);                                                       *|
|* : 5| }                                                                     *|
|* :  :                                                                       *|
|* :                                                                          *|
|* ;.., AND THAT MAKES THE MAIN FUNCTION DURING COMPILING PROCESS:            *|
|*    :                                                                       *|
|*   1| int main(void)                                                        *|
|*   2| {                                                                     *|
|*   3|     printf("%d", (15 + 42));                                          *|
|*   4|     return (0);                                                       *|
|*   5| }                                                                     *|
|*    :                                                                       *|
|*                                                                            *|
|* IT WAS JUST AN EXAMPLE. FEEL FREE TO FILL YOUR FUNCTION AS MUCH AS YOU     *|
|* CAN. BUT PLEASE BE AWARE OF WHAT NOT TO DO INSIDE OF AN INLINE FUNCTION BY *|
|* READING THE "HOW NOT TO USE IT" LIST AT THE TOP!                           *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                                SIDE NOTES                                #*|
|*############################################################################*|
|*                                                                            *|
|* [[clang::always_inline]] NOT WORKING IN CLANG. BELIEVE ME.                 *|
|*                                                                            *|
|* USE THIS KEYWORD WITH YOUR "static" FUNCTIONS AND ON THE FUNCTIONS THAT    *|
|* DEFINED IN THE HEADER FILES!!!                                             *|
|*                                                                            *|
|* YOU DON'T NEED TO MAP INLINE FUNCTIONS WITH MVS LINKER PRAGMAS             *|
|* (SUCH AS `#pragma map`) WHEN TARGETING Z/OS SYSTEMS. INLINE FUNCTIONS DO   *|
|* NOT GENERATE EXTERNAL SYMBOLS UNLESS INLINING FAILS.                       *|
|*                                                                            *|
\******************************************************************************/

#ifndef INLINE_H
#	define INLINE_H 202508 /* VERSION */

/* *************************** [v] TI CGT CCS [v] *************************** */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_push /* TI CGT CCS COMPILER DIRECTIVES */
#		pragma CHECK_MISRA("5.4") /* TAG NAMES SHALL BE A UNIQUE IDENTIFIER */
#		pragma CHECK_MISRA("19.3") /*
#			THE #INCLUDE DIRECTIVE SHALL BE FOLLOWED BY EITHER A <FILENAME> OR
#			"FILENAME" SEQUENCE
#		*/
#	endif /* __TI_COMPILER_VERSION__ */

/* *************************** [^] TI CGT CCS [^] *************************** */

/* *************************** [v] C++ (PUSH) [v] *************************** */
#	ifdef __cplusplus /* C++ */
extern "C" {
#	endif /* __cplusplus */
/* *************************** [^] C++ (PUSH) [^] *************************** */

#	ifdef _MSC_VER /* MICROSOFT C++ */
#		define INLINE __forceinline
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
							(__GNUC__ > 4) || /* IF GTR 4.X.X */\
							(\
								(__GNUC__ == 4) && /* IF EQU 4.X.X */\
								(__GNUC_MINOR__ >= 2) /* IF GEQ X.2.X */\
							)\
						)\
					) /* IS GCC VERSION 4.2.X OR GREATER (MAXIMUM C99) */
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
							(__GNUC__ > 2) || /* IF GTR 2.X.X */\
							(\
								(__GNUC__ == 2) && /* IF EQU 2.X.X */\
								(__GNUC_MINOR__ >= 7) /* IF GEQ X.7.X */\
							)\
						) /* GCC VERSION 2.7.X OR GREATER (MAXIMUM C89) */
#							define INLINE __inline__
#						else /* GCC DOESN'T SUPPORT INLINE */
#							define INLINE /* NOT SUPPORTED */
#						endif /* __GNUC__ >= 2.7.X */
#					endif /* __GNUC__ >= 4.2.X */
#				endif /* __clang__ */
#			endif /* __TINYC__ */
#		endif /* __cplusplus */
#	endif /* _MSC_VER */

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

#endif /* !INLINE_H */

#ifdef __EOF__
#	undef __EOF__
#endif /* __EOF__ */
#define __EOF__ //  <- FOR DOS, CP/M, ETC
