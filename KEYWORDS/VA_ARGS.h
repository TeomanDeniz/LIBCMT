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
# : License - GPL-3.0   :: Update - 2025/12/23 : #    ::::!!!1!!1!!!1!!!::     #
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
|* va_arg   : #define () : GET A VARIABLE FROM YOUR VA_LIST IN YOUR FUNCTION  *|
|* VA_ARG   :            :                                                    *|
|*..........:............:....................................................*|
|* va_copy  : #define () : COPY YOUR VA_LIST ADDRESS                          *|
|* VA_COPY  :            :                                                    *|
|*..........:............:....................................................*|
|* va_start : #define () : THE THE ADDRESS POINTER OF YOUR ARGUMENT LIST      *|
|* VA_START :            :                                                    *|
|*..........:............:....................................................*|
|* va_end   : #define () : END A VA_LIST POINTER                              *|
|* VA_END   :            :                                                    *|
|*..........:............:....................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|*   O - EXAMPLE                                                              *|
|*   :                                                                        *|
|*  1| test(); // PROTOTYPE                                                   *|
|*  2|                                                                        *|
|*  3| int main()                                                             *|
|*  4| {                                                                      *|
|*  5|     test(42, 42.0, "Hello world");                                     *|
|*  6|     return (0);                                                        *|
|*  7| }                                                                      *|
|*  8|                                                                        *|
|*  9| extern int printf();                                                   *|
|* 10|                                                                        *|
|* 11| test(start)                                                            *|
|* 12|     int start;                                                         *|
|* 13| {                                                                      *|
|* 14|     va_list x;                                                         *|
|* 15|     va_list y;                                                         *|
|* 16|     va_start(x, start);                                                *|
|* 17|     va_copy(y, x);                                                     *|
|* 18|     printf("%d\nx:%f\n", start, va_arg(x, double));                    *|
|* 19|     va_end(x);                                                         *|
|* 20|     printf("y:%f\n", va_arg(y, double));                               *|
|* 21|     printf("y:%s\n", va_arg(y, char *));                               *|
|* 22|     va_end(y);                                                         *|
|* 23| }                                                                      *|
|*   :                                                                        *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* THIS LIBRARY'S PURPOSE IS USING VA_ARG FEATURE ON OLDER COMPILERS. FOR     *|
|* EXAMPLE, BEFORE C89 VERSIONS.                                              *|
|*                                                                            *|
\******************************************************************************/

#ifndef VA_ARGS_H
#	define VA_ARGS_H 202512 /* VERSION */

/* *********************** [v] TI CGT CCS (PUSH) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_push /* TI CGT CCS COMPILER DIRECTIVES */
#		pragma CHECK_MISRA("5.4") /*
#			TAG NAMES SHALL BE A UNIQUE IDENTIFIER
#		*/
#		pragma CHECK_MISRA("19.3") /*
#			THE #INCLUDE DIRECTIVE SHALL BE FOLLOWED BY EITHER A <FILENAME>
#			OR "FILENAME" SEQUENCE
#		*/
#	endif /* __TI_COMPILER_VERSION__ */
/* *********************** [^] TI CGT CCS (PUSH) [^] ************************ */

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../ENVIRONMENTS/KNR_STYLE.H" /*
#	 define KNR_STYLE
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

#	ifdef KNR_STYLE /* COMPILER DOES NOT SUPPORTS VA_ARG */
/* **************************** [v] INCLUDES [v] **************************** */
#		include "../ENVIRONMENTS/ARCHITECTURE.H" /*
#		 define __SYSTEM_32_BIT__
#		 define __SYSTEM_16_BIT__
#		 define __SYSTEM_8_BIT__
#		        */
/* **************************** [^] INCLUDES [^] **************************** */

/* **************************** [v] TYPEDEFS [v] **************************** */
typedef char	*va_list;
/* **************************** [^] TYPEDEFS [^] **************************** */

#		ifdef __SYSTEM_32_BIT__
static char
	*__VA_ARGS_DUMMY_FUNCTION__(LIST, SIZE)
	register char	**LIST;
	register int	SIZE;
{
	register int	ADJUST;

	ADJUST = (SIZE + 3) & (~ 3);
	*LIST += ADJUST;
	return (*LIST - ADJUST);
}

#			define va_start(LIST, ARGUMENT) \
				LIST = ((char *)&(ARGUMENT)) + ((sizeof(ARGUMENT) + 3) & (~ 3))
#			define va_arg(LIST, TYPE) \
				*(TYPE *)__VA_ARGS_DUMMY_FUNCTION__(&(LIST), sizeof(TYPE))
#			define va_copy(DESTINATION, SOURCE) (DESTINATION) = (SOURCE)
#			define va_end(LIST)
#		endif /* __SYSTEM_32_BIT__ */

#		ifdef __SYSTEM_16_BIT__
static char
	*__VA_ARGS_DUMMY_FUNCTION__(LIST, SIZE)
	register char	**LIST;
	register int	SIZE;
{
		register int	ADJUST;

		ADJUST = (SIZE + 1) & (~ 1);
		*LIST += ADJUST;
		return (*LIST - ADJUST);
}

#			define va_start(LIST, ARGUMENT) \
				LIST = ((char *)&(ARGUMENT)) + ((sizeof(ARGUMENT) + 1) & (~ 1))
#			define va_arg(LIST, TYPE) \
				*(TYPE *)__VA_ARGS_DUMMY_FUNCTION__(&(LIST), sizeof(TYPE))
#			define va_copy(DESTINATION, SOURCE) (DESTINATION) = (SOURCE)
#			define va_end(LIST)
#		endif /* __SYSTEM_16_BIT__ */

#		ifdef __SYSTEM_8_BIT__
static char
	*__VA_ARGS_DUMMY_FUNCTION__(LIST, SIZE)
	register char	**LIST;
	register int	SIZE;
{
		*LIST += SIZE;
		return (*LIST - SIZE);
}

#			define va_start(LIST, ARGUMENT) \
				LIST = ((char *)&(ARGUMENT)) + sizeof(ARGUMENT)
#			define va_arg(LIST, TYPE) \
				*(TYPE *)__VA_ARGS_DUMMY_FUNCTION__(&(LIST), sizeof(TYPE))
#			define va_copy(DESTINATION, SOURCE) (DESTINATION) = (SOURCE)
#			define va_end(LIST)
#		endif /* __SYSTEM_8_BIT__ */
#	else
#		ifdef __cplusplus /* C++ */
#			include <cstdarg> /*
#			typedef va_list;
#			    <T> va_arg(va_list, <T>);
#			   void va_copy(va_list, va_list);
#			   void va_start(va_list, {parmN});
#			   void va_end(va_list);
#			        */
#		else
#			include <stdarg.h> /*
#			typedef va_list;
#			    <T> va_arg(va_list, <T>);
#			   void va_copy(va_list, va_list);
#			   void va_start(va_list, {parmN});
#			   void va_end(va_list);
#			        */
#		endif /* __cplusplus */
#	endif /* KNR_STYLE */

/* **************************** [v] UPPERCASE [v] *************************** */
typedef va_list	VA_LIST;
#		define VA_ARG va_arg
#		define VA_COPY va_copy
#		define VA_START va_start
#		define VA_END va_end
/* **************************** [^] UPPERCASE [^] *************************** */

/* ************************ [v] TI CGT CCS (POP) [v] ************************ */
#		ifdef __TI_COMPILER_VERSION__
#			pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#		endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */

#	endif /* !__cplusplus */
#endif /* !VA_ARGS_H */

/* * * * * * * * * * * /!\ AUTOMATIC EOF TREATMENT! /!\ * * * * * * * * * * * *\
 * * AT THE ALL END OF FILES, I AM ADDING A SPECIAL BYTE <0X1A> TO END THE  * *
 * *                       FILE IN DOS, CP/M SYSTEMS                        * *
 * *   "//" FOR HANDLING THE BYTE IN MODERN COMPILERS AND #define IS FOR    * *
 * *       HANDLING "//" SYNTAX WHICH IS NOT SUPPORTED ON OLD SYSTEMS       * *
\* * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * */
#undef __CMT__END_OF_FILE__
#define __CMT__END_OF_FILE__ //
