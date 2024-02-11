/******************************************************************************\
# H - PACK                                       #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2023/07/09 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - AGPL-3.0  :: Update - 2024/01/24 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/* LIST
#	Function or Variable is not used

	__UNUSED_FUNCTION__
	__UNUSED_VARIABLE__
*/

/* USAGE

void __UNUSED_FUNCTION__	function(int variable)
{
	__UNUSED_VARIABLE__ variable;
}

*/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|* IDK                                                                        *|
|*                                                                            *|
\******************************************************************************/

/* ************************* [v] VERSION CONTROL [v] ************************ */
#define LIBRARY_VERSION 202401 /* VERSION */
#ifdef UNUSED_H
#	if (UNUSED_H < LIBRARY_VERSION)
#		undef UNUSED_H /* OLD VERSION DETECTED */
#	endif /* UNUSED_H < LIBRARY_VERSION */
#endif /* UNUSED_H */
#undef LIBRARY_VERSION
/* ************************* [^] VERSION CONTROL [^] ************************ */

#ifndef UNUSED_H

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

#	define UNUSED_H 202401

/* ****************************** [v] RESET [v] ***************************** */
#	undef __UNUSED_FUNCTION__
#	undef __UNUSED_VARIABLE__
/* ****************************** [^] RESET [^] ***************************** */

#	ifdef _MSC_VER
#		define __UNUSED_FUNCTION__ __pragma(warning(suppress:4505))
#		define __UNUSED_VARIABLE__ __pragma(warning(suppress:4100))
#	else
#		ifdef __cplusplus
#		define __UNUSED_FUNCTION__ [[maybe_unused]]
#		define __UNUSED_VARIABLE__ [[maybe_unused]]
#		else
#			if (\
				(\
					defined(__GNUC__) || /* IF GCC */\
					defined(__clang__) /* IF CLANG */\
				) && (\
					(__GNUC__ > 4) || /* IF GEQ 4.X.X */\
					(\
						__GNUC__ == 4 && /* IF EQ 4.X.X */\
						__GNUC_MINOR__ >= 2 /* IF GEQ X.2.X */\
					)\
				)\
			) /* IS GCC VERSION 4.2.X OR GREATHER (MAXIMUM C99) */
#				define __UNUSED_FUNCTION__ __attribute__((unused))
#				define __UNUSED_VARIABLE__ (void)
#			else /* DJGPP || TCC || K&R */
#				define __UNUSED_FUNCTION__ /* EMPTY */
#				define __UNUSED_VARIABLE__ (void)
#			endif /* __GNUC__ */
#		endif /* __cplusplus */
#	endif /* MICROSOFT C++ */
#	ifdef __cplusplus /* C++ */
		}
#	endif /* __cplusplus */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
#endif /* UNUSED_H */