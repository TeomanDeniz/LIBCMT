/******************************************************************************\
# H - VA_ARGS                                    #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/06/10 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - AGPL-3.0  :: Update - 2025/05/22 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*\
@@                                                                            @@
@@                _______   _________  ________  ____    ____                 @@
@@               |_   __ \ |  _   _  ||_   __  ||_   \  /   _|                @@
@@                 | |__) ||_/ | | \_|  | |_ \_|  |   \/   |                  @@
@@                 |  __ /     | |      |  _|     | |\  /| |                  @@
@@                _| |  \ \_  _| |_    _| |_     _| |_\/_| |_                 @@
@@               |____| |___||_____|  |_____|   |_____||_____|                @@
@@                                                                            @@
@@                          YES, YOU HEARD IT RIGHT!                          @@
@@                     READ THE FUCKING MANUAL BEFORE USE                     @@
@@                     ^    ^   ^       ^                                     @@
\*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*   NAME   :    TYPE    :                    DESCRIPTION                     *|
|*..........:............:....................................................*|
|* va_list  : typedef    : A TYPE FOR CREATING YOUR ARGUMENT LIST             *|
|* VA_LIST  :            :                                                    *|
|*..........:............:....................................................*|
|* va_add   : #define () : ADD A VARIABLE ON YOUR VA_LIST IN YOUR FUNCTION    *|
|* VA_ADD   :            :                                                    *|
|*..........:............:....................................................*|
|* va_arg   : #define () : GET A VARIABLE FROM YOUR VA_LIST IN YOUR FUNCTION  *|
|* VA_ARG   :            :                                                    *|
|*..........:............:....................................................*|
|* va_copy  : #define () : COPY YOUR VA_LIST ADDRESS                          *|
|* VA_COPY  :            :                                                    *|
|*..........:............:....................................................*|
|* va_push  : #define    : OPEN THE ARGUMENT LIST TO GIVE ARGUMENTS ON YOUR   *|
|* VA_PUSH  :            : FUNCTION YOU'RE CALLING                            *|
|*..........:............:....................................................*|
|* va_pop   : #define    : CLOSE THE ARGUMENT LIST ON YOUR FUNCTION YOU'RE    *|
|* VA_POP   :            : CALLING                                            *|
|*..........:............:....................................................*|
|* va_start : #define () : THE THE ADDRESS POINTER OF YOUR ARGUMENT LIST      *|
|* VA_START :            :                                                    *|
|*..........:............:....................................................*|
|* va_args  : #define    : TELL THE COMPILER THAT THE FUNCTION IS GONNA HAVE  *|
|* VA_ARGS  :            : __VA_ARGS__ (AKA: ...) ARGUMENTS                   *|
|*..........:............:....................................................*|
|* va_end   : #define () : END A VA_LIST POINTER                              *|
|* VA_END   :            :                                                    *|
|*..........:............:....................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* O - SETUP                                                                  *|
|* :                                                                          *|
|* : NOTE: SETUP PART IS OPTIONAL IF YOU'RE DEAILNG WITH main FUNCTION BY     *|
|* : YOURSELF WITH LIKE "#define main ..."                                    *|
|* :                                                                          *|
|* : BEFORE USING THIS LIBRARY, YOU MUST DEFINE THE MACRO "SETUP_VA_ARGS"     *|
|* : ONCE, IN ONE C FILE (TYPICALLY YOUR "main.c" OR ENTRY POINT).            *|
|* :                                                                          *|
|* : THIS ENSURES GLOBAL VARIABLES USED INTERNALLY ARE **PROPERLY DEFINED**.  *|
|* :                                                                          *|
|* : AFTER THAT, YOU CAN INCLUDE THIS HEADER ANYWHERE ELSE WITHOUT DEFINING   *|
|* : THE MACRO AGAIN. ALL OTHER FILES WILL JUST SEE "extern" DECLS.           *|
|* :                                                                          *|
|* : EXAMPLE USAGE:                                                           *|
|* ;.., [main.c]                                                              *|
|* :  :                                                                       *|
|* :  : #define SETUP_VA_ARGS // ENABLE GLOBAL DEFINITIONS                    *|
|* :  : #include "LIBCMT/PLATFORM_CROSSING/VA_ARGS.h"                         *|
|* :  :                                                                       *|
|* :  : int main(void) {                                                      *|
|* :  :     ...                                                               *|
|* :  : }                                                                     *|
|* :                                                                          *|
|* ;.., [static_link.c]                                                       *|
|*    :                                                                       *|
|*    : #include "LIBCMT/PLATFORM_CROSSING/VA_ARGS.h"                         *|
|*    : // DO NOT define SETUP_VA_ARGS here - only include the header         *|
|*    : . . .                                                                 *|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* ;.., void test(int, va_args); // PROTOTYPE                                 *|
|*    :                                                                       *|
|*    : int main(void)                                                        *|
|*    : {                                                                     *|
|*    :     test(42,                                                          *|
|*    :         va_push                                                       *|
|*    :             va_add(double, 42.0)                                      *|
|*    :             va_add(char *, "Hello world")                             *|
|*    :             va_add(int, 0X44800000) // Float type: 1024.0             *|
|*    :         va_pop                                                        *|
|*    :     );                                                                *|
|*    :     return (0);                                                       *|
|*    : }                                                                     *|
|*    :                                                                       *|
|*    : extern int printf(const char *, ...); // PROTOTYPE                    *|
|*    :                                                                       *|
|*    : void test(int start, va_args)                                         *|
|*    : {                                                                     *|
|*    :     va_list x;                                                        *|
|*    :     va_list y;                                                        *|
|*    :     va_start(x, start);                                               *|
|*    :     va_copy(y, x);                                                    *|
|*    :     printf("%d\nx:%f\n", start, va_arg(x, double));                   *|
|*    :     va_end(x);                                                        *|
|*    :     printf("y:%f\n", va_arg(y, double));                              *|
|*    :     printf("y:%s\n", va_arg(y, char *));                              *|
|*    :     printf("y:%f\n", va_arg(y, float)); // Yes, it is working         *|
|*    :     va_end(y);                                                        *|
|*    : }                                                                     *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* THIS LIBRARY'S PURPOSE IS USING VA_ARG FEATURE ON OLDER COMPILERS. FOR     *|
|* EXAMPLE, BEFORE C89 VERSIONS.                                              *|
|*                                                                            *|
|* IT'S (ALMOST) WORKS SAME LIKE ORIGINAL STD VA_ARG FUNCTION BUT YOU ALSO    *|
|* NEED TO ADD SOME ADDITIONAL STUFF TO MAKE IT WORK.                         *|
|*                                                                            *|
|* BEFORE SENDING MORE ARGUMENTS TO FUNCTION, YOU MUST NEED TO OPEN A VA_ARG  *|
|* LIST VIA USING [VA_PUSH] AND CLOSE THE ARGUMENT LIST USING [VA_POP].       *|
|*                                                                            *|
|* AND INSIDE OF THE [VA_PUSH] AND [VA_POP] YOU NEED TO PASS ARGUMENTS USING  *|
|* VA_ADD FUNCTION.                                                           *|
|*                                                                            *|
|* EXAMPLE:                                                                   *|
|*     printf("%d %d", va_push va_add(int, 42) va_add(char, 'a') va_pop);     *|
|*                                                                            *|
|* AND LASTLY, YOU MUST USE 'VA_ARGS' OR 'va_args' INSTEAD OF '...' FOR USE   *|
|* THIS FEATURE IN FUNCTIONS.                                                 *|
|*                                                                            *|
|* FOR EXAMPLE:                                                               *|
|*     printf(const char *, ...);                                             *|
|*     BECOMES                                                                *|
|*     printf(const char *, va_args);                                         *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                                SIDE NOTES                                #*|
|*############################################################################*|
|*                                                                            *|
|* IF YOU TRY TO GET 32, 16, OR 8 BIT VARIABLES ON 64 BIT ARCHITECTURES,      *|
|* YOU ARE GONNA GET "Illegal instruction" ERROR WHILE RUNNING YOUR SCRIPT!   *|
|* I DID NOT ADD THIS FEATURE BECAUSE THIS IS DUMB AS FUCK AND JUST ANNOYING. *|
|*                                                                            *|
|* I NEEDED TO USE GLOBAL VARIABLES TO PASS ARGUMENTS BECAUSE BEFORE C99,     *|
|* COMPOUND LITERALS (AKA: int *test = (int []){1, 2, 3, ...};) ARE NOT EXIST *|
|*                                     ^^^^^^^^                               *|
|*                                                                            *|
\******************************************************************************/

#ifndef VA_ARG_H
#	define VA_ARG_H 202505 /* VERSION */
#	ifndef __cplusplus /* C++ */

/* *********************** [v] TI CGT CCS (PUSH) [v] ************************ */
#		ifdef __TI_COMPILER_VERSION__
#			pragma diag_push /* TI CGT CCS COMPILER DIRECTIVES */
#			pragma CHECK_MISRA("-5.4") /*
#				TAG NAMES SHALL BE A UNIQUE IDENTIFIER
#			*/
#			pragma CHECK_MISRA("-19.3") /*
#				THE #INCLUDE DIRECTIVE SHALL BE FOLLOWED BY EITHER A <FILENAME>
#				OR "FILENAME" SEQUENCE
#			*/
#		endif /* __TI_COMPILER_VERSION__ */
/* *********************** [^] TI CGT CCS (PUSH) [^] ************************ */

/* **************************** [v] INCLUDES [v] **************************** */
#		include "../KEYWORDS/LOCAL.h" /*
#		 define LOCAL
#		        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ********************** [v] CAN CHANGABLE MACRO [v] *********************** */
#		ifndef VA_ARGS_MAX_BYTE_LIMIT
#			define VA_ARGS_MAX_BYTE_LIMIT 2048 // <- INCREASE IT IF YOU NEED
#		endif /* !VA_ARGS_MAX_BYTE_LIMIT */
/* ********************** [^] CAN CHANGABLE MACRO [^] *********************** */

#		if (\
			(\
				defined(__GNUC__) && \
				defined(__GNUC_MINOR__) && \
				defined(__GNUC_PATCHLEVEL__)\
			) || \
			defined(__clang__) || \
			defined(__INTEL_COMPILER) || \
			defined(__SUNPRO_C) || \
			defined(__IBMC__) || \
			defined(__IBMCPP__) || \
			defined(__HP_cc) || \
			defined(__PGI) || \
			defined(__TI_COMPILER_VERSION__) || \
			defined(__TINYC__) || \
			defined(__COMPCERT__) || \
			defined(__PCC__) || \
			defined(__TenDRA__)\
		)
#			include <stdarg.h> /*
#			??????? va_list;
#			    <T> va_arg(va_list, <T>);
#			   void va_copy(va_list, va_list);
#			   void va_start(va_list, {parmN});
#			   void va_end(va_list);
#			        */
#			define va_args ...
#			define va_add(A, B) (A)B,
#			define va_push
#			define va_pop 0
#		else /* COMPILER DOES NOT SUPPORTS VA_ARG */
typedef char	**va_list;
//#			define va_add(A, B) ((char *)&(A){B}), // COMPOUND LITERALS
#			define va_add(A, B) \
				__VA_ARGS__GLOBAL_[++__VA_ARGS__GLOBAL_INDEX]=((char *)&(A){B}),
#			define va_arg(A, B) (*A && ++A, (B)*((B *)*(A - 1)))
#			define va_copy(A, B) A = B
//#			define va_push (char *[]){ /* COMPOUND LITERALS */
#			define va_push (
//#			define va_pop ((char *)0)} /* COMPOUND LITERALS */
#			define va_pop __VA_ARGS__GLOBAL_INDEX = -1, __VA_ARGS__GLOBAL_)
#			define va_start(A, B) A = __VA_ARGS___
#			define va_args char **__VA_ARGS___
#			define va_end(A) A = ((char **)0)
#			define __dj_include_stdarg_h_
#			define _STDARG_H
#			define _VA_LIST_DEFINED
#		endif /* IF COMPILER SUPPORTS VA_ARG */

/* **************************** [v] UPPERCASE [v] *************************** */
#		define VA_ADD va_add
#		define VA_ARG va_arg
#		define VA_COPY va_copy
#		define VA_PUSH va_push
#		define VA_POP va_pop
#		define VA_START va_start
#		define VA_ARGS va_args
#		define VA_END va_end
/* **************************** [^] UPPERCASE [^] *************************** */

/* ************************ [v] GLOBAL VARIABLES [v] ************************ */
#		ifdef SETUP_VA_ARGS
LOCAL char	*__VA_ARGS__GLOBAL_[VA_ARGS_MAX_BYTE_LIMIT];
LOCAL int		__VA_ARGS__GLOBAL_INDEX = -1;
#		else /* CREATE GLOBAL VARIABLES AUTOMATICALLY */
#			ifdef main
#				undef main
#			endif /* main */
#			ifdef WinMain
#				undef WinMain
#			endif /* main */
#			ifndef LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES
#				define LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES
#			endif /* !LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES */
#			define LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES \
				LOCAL char	*__VA_ARGS__GLOBAL_[VA_ARGS_MAX_BYTE_LIMIT];\
				LOCAL int		__VA_ARGS__GLOBAL_INDEX = -1;
#			define main \
				__IDLE__VA_ARGS;\
				LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES\
				LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES\
				int main
#			define WinMain \
				__IDLE__VA_ARGS;\
				LOCALMACRO__VA_ARGS_GLOBAL_VARIABLES\
				LOCALMACRO__TRY_CATCH_GLOBAL_VARIABLES\
				int WINAPI WinMain
#		endif /* SETUP_VA_ARGS */
LOCAL extern char	*__VA_ARGS__GLOBAL_[VA_ARGS_MAX_BYTE_LIMIT];
LOCAL extern int	__VA_ARGS__GLOBAL_INDEX;
/* ************************ [^] GLOBAL VARIABLES [^] ************************ */

/* ************************ [v] TI CGT CCS (POP) [v] ************************ */
#		ifdef __TI_COMPILER_VERSION__
#			pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#		endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */

#	endif /* !__cplusplus */
#endif /* !VA_ARG_H */
