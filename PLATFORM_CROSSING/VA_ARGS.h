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
# : License - AGPL-3.0  :: Update - 2024/06/19 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

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
|* IT'S EXACTLY WORKS SAME AS ORIGINAL STD VA_ARG BUT YOU NEED ADDITIONAL     *|
|* STUFF TO MAKE IT WORK.                                                     *|
|*                                                                            *|
|* BEFORE SENDING MORE ARGUMENTS TO FUNCTION, YOU MUST NEED OPEN A VA_ARG     *|
|* LIST VIA USING [VA_PUSH] AND LOSE THE ARGUMENT LIST USING [VA_POP].        *|
|*                                                                            *|
|* AND INSIDE OF THE [VA_PUSH] AND [VA_POP] YOU NEED TO PASS ARGUMENTS USING  *|
|* VA_ADD FUNCTION.                                                           *|
|*                                                                            *|
|* EXAMPLE:                                                                   *|
|*     printf("%d %d", va_push va_add(int, 42) va_add(char, 'a') va_pop);     *|
|*                                                                            *|
|* AND LASTLY, YOU MUST USE 'VA_ARGS' OR 'va_args' INSTEAD OF '...' FOR       *|
|* THIS FEATURE TO USE IN FUNCTIONS.                                          *|
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
|* COMPOUND LITERALS (AKA: int *test = (int []){1, 2, 3, ...};) IS NOT EXIST! *|
|*                                     ^^^^^^^^                               *|
|*                                                                            *|
\******************************************************************************/

/* ************************* [v] VERSION CONTROL [v] ************************ */
#ifdef VA_ARG_H
#	if (VA_ARG_H < 202406)
#		undef VA_ARG_H /* OLD VERSION DETECTED */
#	endif /* PACK_H < LIBRARY_VERSION */
#endif /* PACK_H */
/* ************************* [^] VERSION CONTROL [^] ************************ */

/* *************** [v] CHECK IF STANDARD LIBRARY INCLUDED [v] *************** */
#if (\
		!defined(VA_ARG_H) && /* THIS LIBRARY */\
		(\
			defined(__dj_include_stdarg_h_) || /* DJGPP */ \
			defined(_STDARG_H) || /* TINY C COMPILER */ \
			defined(_VA_LIST_DEFINED) /* TINY C COMPILER */\
		)\
	)
#	define VA_ARG_H 202406
#endif
/* *************** [v] CHECK IF STANDARD LIBRARY INCLUDED [v] *************** */

#ifndef VA_ARG_H
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
#	define VA_ARG_H 202406 /* VERSION */
/* ****************************** [v] RESET [v] ***************************** */
#	undef va_add
#	undef va_arg
#	undef va_copy
#	undef va_push
#	undef va_pop
#	undef va_start
#	undef va_args
#	undef va_end
#	undef VA_ADD
#	undef VA_ARG
#	undef VA_COPY
#	undef VA_PUSH
#	undef VA_POP
#	undef VA_START
#	undef VA_ARGS
#	undef VA_END
#	undef __dj_include_stdarg_h_
#	undef _STDARG_H
#	undef _VA_LIST_DEFINED
/* ****************************** [^] RESET [^] ***************************** */
#	if ( \
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
			defined(__TenDRA__) \
		)
#		include <stdarg.h> /*
#		??????? va_list;
#		    <T> va_arg(va_list, <T>);
#		   void va_copy(va_list, va_list);
#		   void va_start(va_list, {parmN});
#		   void va_end(va_list);
#		         */
#		define va_args ...
#		define va_add(A, B) (A)B,
#		define va_push
#		define va_pop 0
#	else /* COMPILER DOES NOT SUPPORTS VA_ARG */
typedef char    **va_list;
//#		define va_add(A, B) ((char *)&(A){B}), // COMPOUND LITERALS
#		define va_add(A, B) \
			__VA_ARGS__GLOBAL_[++__VA_ARGS__GLOBAL_INDEX]=((char *)&(A){B}),
#		define va_arg(A, B) (*A && ++A, (B)*((B *)*(A - 1)))
#		define va_copy(A, B) A = B
//#		define va_push (char *[]){ // COMPOUND LITERALS
#		define va_push (
//#		define va_pop ((char *)0)} // COMPOUND LITERALS
#		define va_pop __VA_ARGS__GLOBAL_INDEX = -1, __VA_ARGS__GLOBAL_)
#		define va_start(A, B) A = __VA_ARGS___
#		define va_args char **__VA_ARGS___
#		define va_end(A) A = ((char **)0)
#		define __dj_include_stdarg_h_
#		define _STDARG_H
#		define _VA_LIST_DEFINED
#	endif /* IF COMPILER SUPPORTS VA_ARG */
/* **************************** [v] UPPERCASE [v] *************************** */
#	define VA_ADD va_add
#	define VA_ARG va_arg
#	define VA_COPY va_copy
#	define VA_PUSH va_push
#	define VA_POP va_pop
#	define VA_START va_start
#	define VA_ARGS va_args
#	define VA_END va_end
/* **************************** [^] UPPERCASE [^] *************************** */
#	ifndef VA_ARGS_GLOBALS_DEFINED
#		define VA_ARGS_GLOBALS_DEFINED
#		define VA_ARGS_MAX_BYTE_LIMIT 2048
char	*__VA_ARGS__GLOBAL_[VA_ARGS_MAX_BYTE_LIMIT];
int		__VA_ARGS__GLOBAL_INDEX = -1;
#	endif /* VA_ARG_GLOBALS_DEFINED */
#	ifdef __cplusplus /* C++ */
		}
#	endif /* __cplusplus */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
#endif /* VA_ARG_H */
