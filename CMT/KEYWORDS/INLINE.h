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
# : License - GNU       :: Update - 2024/01/17 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/* LIST
#	Standard function inlinening processor

	__STD_INLINE__
	__STATIC_INLINE__
*/

/* USAGE

__STD_INLINE__ void	function(void);

__STATIC_INLINE__ void	function(void);

*/

/******************************************************************************\
|*                               WTF THAT DOES?                               *|
|******************************************************************************|
|*                                                                            *|
\******************************************************************************/

/* ************************* [v] VERSION CONTROL [v] ************************ */
#define LIBRARY_VERSION 202401
#ifdef INLINE_H
#	if (INLINE_H < LIBRARY_VERSION)
#		undef INLINE_H
#	else
#		undef LIBRARY_VERSION
#	endif
#endif
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

#	define INLINE_H 202401

/* ****************************** [v] RESET [v] ***************************** */
#	undef LIBRARY_VERSION /* VERSION */
#	undef __STD_INLINE__
#	undef __STATIC_INLINE__
/* ****************************** [^] RESET [^] ***************************** */

#	ifdef _MSC_VER /* MICROSOFT C++ */
#		define __STD_INLINE__ __inline__ __forceinline
#		define __STATIC_INLINE__ static __STD_INLINE__
#	else
#		ifdef __cplusplus
#			define __STD_INLINE__ inline
#			define __STATIC_INLINE__ static __STD_INLINE__
#		else
#			ifdef __TINYC__ /* TCC (TINY C COMPILER) */
#				define __STD_INLINE__ __inline__
#				define __STATIC_INLINE__ static __STD_INLINE__
#			else
#				ifdef __clang__ /* CLANG */
#					define __STD_INLINE__ __inline__ // [[clang::always_inline]] ASSHOLE NOT WORKING
#					define __STATIC_INLINE__ static __STD_INLINE__
#				else
#					ifdef __GNUC__
#						if ((__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2))
#							ifdef __DJGPP__
#								define __STD_INLINE__ __inline__ __attribute__((__gnu_inline__))
#								define __STATIC_INLINE__ static __inline__
#							else
#								define __STD_INLINE__ __inline__ __attribute__((__gnu_inline__, always_inline))
#								define __STATIC_INLINE__ static __inline__
#							endif /* DJGPP */
#						else /* __attribute__ DOESN'T SUPPORTED */
#							define __STD_INLINE__ __inline__
#							define __STATIC_INLINE__ static
#						endif /* GNUC VERSION */
#					else /* K&R, ETC... */
#						define __STD_INLINE__ /* NULL */
#						define __STATIC_INLINE__ static
#					endif /* GNU GCC C */
#				endif /* CLANG */
#			endif /* TCC (TINY C COMPILER) */
#		endif /* __cplusplus */
#	endif /* MICROSOFT C++ */
#	ifdef __cplusplus /* C++ */
		}
#	endif /* __cplusplus */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
#endif /* INLINE_H */