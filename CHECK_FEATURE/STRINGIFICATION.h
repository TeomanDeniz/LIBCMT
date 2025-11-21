/******************************************************************************\
# H - STRINGIFICATION                            #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2025/11/21 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/11/21 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*              NAME              :   TYPE    :          DESCRIPTION          *|
|*................................:...........:...............................*|
|* IS__STRINGIFICATION__SUPPORTED : #define   : DEFINED IF STRINGIFICATION IS *|
|*                                :           : SUPPORTED BY YOUR COMPILER    *|
|*................................:...........:...............................*|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* THE MACRO "IS__STRINGIFICATION__SUPPORTED" IS DEFINED IF THE COMPILER      *|
|* SUPPORTS THE "STRINGIFICATION" FEATURE.                                    *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                          WHAT IS THIS FEATURE?                           #*|
|*############################################################################*|
|*                                                                            *|
|* STRINGIFICATION REFERS TO THE "#" OPERATOR IN MACROS, USED TO CONVERT ANY  *|
|* PURE INPUT AS STRING.                                                      *|
|*                                                                            *|
|* O - EXAMPLE:                                                               *|
|* :                                                                          *|
|*1| #define X(A) #A                                                          *|
|*2|                                                                          *|
|*3| printf( X( i am testing something ) );                                   *|
|* :                                                                          *|
|* : WILL RETURN: "i am testing something" WITHOUT A NEW LINE.                *|
|* :                                                                          *|
|*                                                                            *|
\******************************************************************************/

#ifndef CHECK_FEATURE__STRINGIFICATION_H
#	define CHECK_FEATURE__STRINGIFICATION_H 202511 /* VERSION */
#	ifdef __STDC__
#		ifdef __STDC_VERSION__
#			if (__STDC_VERSION__ >= 199012L) /* C89/ANSI C */
#				define IS__STRINGIFICATION__SUPPORTED
#			endif /* __STDC_VERSION__ >= 199012L */
#		else /* I KNOW, IT LOOKS WRONG. BUT TRUST ME */
#			define IS__STRINGIFICATION__SUPPORTED
#		endif /* __STDC_VERSION__ */
#	endif /* __STDC__ */
#	ifndef IS__STRINGIFICATION__SUPPORTED
#		ifdef __cplusplus /* C++ */
#			define IS__STRINGIFICATION__SUPPORTED
#		endif /* __cplusplus */
#	endif /* !IS__STRINGIFICATION__SUPPORTED */
#endif /* !CHECK_FEATURE__STRINGIFICATION_H */
