/******************************************************************************\
# H - TOKEN_PASTING                              #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2025/07/09 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - AGPL-3.0  :: Update - 2025/07/20 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*

Check if token-pasting (##) is supported

IS__TOKEN_PASTING__SUPPORTED

*/


#ifndef CHECK_FEATURE__TOKEN_PASTING_H
#	define CHECK_FEATURE__TOKEN_PASTING_H
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __STDC_VERSION__
#			if (__STDC_VERSION__ >= 199901L)
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* __STDC_VERSION__ >= 199901L */
#		endif /* __STDC_VERSION__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __cplusplus
#			if (__cplusplus >= 199711L) /* C++98 OR LATER */
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* __cplusplus >= 199711L */
#		endif /* __cplusplus */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __GNUC__
#			define IS__TOKEN_PASTING__SUPPORTED
#			define IS__TOKEN_PASTING__SUPPORTED
#		endif /* __GNUC__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef _MSC_VER /* MICROSOFT C COMPILER */
#			define IS__TOKEN_PASTING__SUPPORTED
#			define IS__TOKEN_PASTING__SUPPORTED
#		endif /* _MSC_VER */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __clang__
#			define IS__TOKEN_PASTING__SUPPORTED
#			define IS__TOKEN_PASTING__SUPPORTED
#		endif /* __clang__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __ICC
#			define IS__TOKEN_PASTING__SUPPORTED
#			define IS__TOKEN_PASTING__SUPPORTED
#		endif /* __ICC */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __ECC
#			define IS__TOKEN_PASTING__SUPPORTED
#			define IS__TOKEN_PASTING__SUPPORTED
#		endif /* __ECC */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __ICL
#			define IS__TOKEN_PASTING__SUPPORTED
#			define IS__TOKEN_PASTING__SUPPORTED
#		endif /* __ICL */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __INTEL_COMPILER
#			define IS__TOKEN_PASTING__SUPPORTED
#			define IS__TOKEN_PASTING__SUPPORTED
#		endif /* __INTEL_COMPILER */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __TINYC__ /* TCC - TINY C COMPILTER */
#			define IS__TOKEN_PASTING__SUPPORTED
#			define IS__TOKEN_PASTING__SUPPORTED
#		endif /* __TINYC__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __WATCOMC__ /* OPEN WATCOM */
#			if (__WATCOMC__ >= 1100) /* C11+ */
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* __WATCOMC__ >= 1100 */
#		endif /* __WATCOMC__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __CODEGEARC__ /* BORLAND C++ */
#			define IS__TOKEN_PASTING__SUPPORTED
#			define IS__TOKEN_PASTING__SUPPORTED
#		endif /* __CODEGEARC__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __BORLANDC__ /* BORLAND C++ */
#			if (__BORLANDC__ >= 0X520) /* (5.02 --- 1.0)+ */
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* __BORLANDC__ >= 0X520 */
#		endif /* __BORLANDC__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __LCC__
#			define IS__TOKEN_PASTING__SUPPORTED
#			define IS__TOKEN_PASTING__SUPPORTED
#		endif /* __LCC__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef AZTEC_C /* AZTEC C COMPILER */
#			if (__VERSION >= 0X510)
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* __VERSION >= 0X510 */
#		endif /* AZTEC_C */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __DECC /* COMPAQ C/C++ */
#			if (__DECC_VER >= 500000000) /* VERSION 5.0+ */
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* __DECC_VER >= 500000000 */
#		endif /* __DECC */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __DECCXX /* COMPAQ C/C++ */
#			define IS__TOKEN_PASTING__SUPPORTED
#			define IS__TOKEN_PASTING__SUPPORTED
#		endif /* __DECCXX */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef _ACC_ /* PROBABLY? */
#			define IS__TOKEN_PASTING__SUPPORTED
#			define IS__TOKEN_PASTING__SUPPORTED
#		endif /* _ACC_ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __CMB__ /* ALTIUM MICROBLAZE C */
#			if (__VERSION__ >= 2)
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* __VERSION__ >= 2 */
#		endif /* __CMB__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __CHC__ /* ALTIUM MICROBLAZE C */
#			if (__VERSION__ >= 2)
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* __VERSION__ >= 2 */
#		endif /* __CHC__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __CC_ARM /* ARM C COMPILER */
#			if (__ARMCC_VERSION >= 200000)
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* __ARMCC_VERSION */
#		endif /* __CC_ARM */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __COMO__ /* COMEAU C++ */
#			if (__COMO_VERSION__ >= 430) /* VERSION 4.3+ */
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* __COMO_VERSION__ >= 430 */
#		endif /* __COMO__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef _CRAYC /* CRAY C COMPILER */
#			if (_RELEASE >= 8) /* VERSION 8+ */
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* _RELEASE >= 8 */
#		endif /* _CRAYC */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __DMC__ /* DIGITAL MARS */
#			if (__DMC__ >= 850)
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* __DMC__ >= 850 */
#		endif /* __DMC__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __DJGPP__
#			if (__DJGPP__ >= 2) /* VERSION 2+ */
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* __DJGPP__ >= 2 */
#		endif /* __DJGPP__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __EDG__
#			if (__EDG_VERSION__ >= 300) /* VERSION 3.0+ */
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* __EDG_VERSION__ >= 300 */
#		endif /* __EDG__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __PATHCC__ /* EKOPATH */
#			if (\
				__PATHCC__ > 4 || \
				(\
					__PATHCC__ == 4 && \
					__PATHCC_MINOR__ >= 0\
				)\
			) /* VERSION V4.0+ */
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* VERSION 4.0+ */
#		endif /* __PATHCC__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __FCC_VERSION /* FUJITSU C++ */
#			if (__FCC_VERSION >= 40000) /* VERSION 4.0+ */
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* __FCC_VERSION >= 40000 */
#		endif /* __FCC_VERSION */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __ghs__ /* GREEN HILLS C/C++ */
#			if (__ghs__ >= 1)
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* __ghs__ >= 1 */
#		endif /* __ghs__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __HP_aCC /* HP AC++ */
#			if (__HP_aCC >= 60000) /* A.06.00+ */
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* __HP_aCC >= 60000 */
#		endif /* __HP_aCC */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __IAR_SYSTEMS_ICC__ /* IAR C/C++ */
#			if (__VER__ >= 800) /* VERSION 8.00+ */
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* __VER__ >= 800 */
#		endif /* __IAR_SYSTEMS_ICC__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __ibmxl__ /* IBM XL C/C++ (CLANG-BASED VERSIONS) */
#			if (__ibmxl_vrm__ >= 0X01000000) /* VERSION 1.0+ */
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* __ibmxl_vrm__ >= 0X01000000 */
#		endif /* __ibmxl__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __xlC__ /* IBM XL C/C++ (LEGACY VERSIONS) */
#			if (__IBMC__ >= 0X0D0000) /* VERSION 13.00+ */
#				define IS__TOKEN_PASTING__SUPPORTED
#			endif /* __IBMC__ >= 0X0D0000 */
#		endif /* __xlC__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __IBMC__ /* IBM Z/OS XL C */
#			if (__IBMC__ >= 1300) /* VERSION 13+ */
#				define IS__TOKEN_PASTING__SUPPORTED
#			else
#				if (__COMPILER_VER__ >= 0X41300000) /* VERSION 13+: N=4/V=13 */
#					define IS__TOKEN_PASTING__SUPPORTED
#				endif /* __COMPILER_VER__ >= 0X41300000 */
#			endif /* __IBMC__ >= 1300 */
#		endif /* __IBMC__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */
#	ifndef IS__TOKEN_PASTING__SUPPORTED
#		ifdef __IBMCPP__ /* IBM Z/OS XL C++ */
#			if (__IBMCPP__ >= 1300) /* VERSION 13+ */
#				define IS__TOKEN_PASTING__SUPPORTED
#			else
#				if (__COMPILER_VER__ >= 0X41300000) /* VERSION 13+: N=4/V=13 */
#					define IS__TOKEN_PASTING__SUPPORTED
#				endif /* __COMPILER_VER__ >= 0X41300000 */
#			endif /* __IBMCPP__ >= 1300 */
#		endif /* __IBMCPP__ */
#	endif /* !IS__TOKEN_PASTING__SUPPORTED */

// #	ifndef IS__TOKEN_PASTING__SUPPORTED
// #		ifdef  /*  */
// #			if ()
// #				define IS__TOKEN_PASTING__SUPPORTED
// #			endif /*  */
// #		endif /*  */
// #	endif /* !IS__TOKEN_PASTING__SUPPORTED */

/*

TODO: (READ THEIR DOCUMENTATIONS)

ImageCraft C (__IMAGECRAFT__)
KAI C++ (__KCC, __KCC_VERSION)
KEIL CARM (__CA__ or __KEIL__)
KEIL C166 (__C166__)
KEIL C51 (__C51__ or __CX51__)
LLVM (__llvm__)
MetaWare High C/C++ (__HIGHC__)
Metrowerks CodeWarrior (__MWERKS__ or __CWCC__)
Microtec C/C++ (_MRI)
Microway NDP C (__NDPC__ or __NDPX__)
MinGW and MinGW-w64 (__MINGW32__, __MINGW32_MAJOR_VERSION, __MINGW32_MINOR_VERSION, __MINGW64__, __MINGW64_MAJOR_VERSION, __MINGW64_MINOR_VERSION)
MIPSpro (__sgi or sgi)
Miracle C (MIRACLE)
MPW C++ (__MRC__ or MPW_C or MPW_CPLUS)
Norcroft C (__CC_NORCROFT, __ARMCC_VERSION)
NWCC (__NWCC__)
Open64 (__OPEN64__ or __OPENCC__)
Oracle Pro*C Precompiler (ORA_PROC)
Oracle Solaris Studio (__SUNPRO_C)
Pacific C (__PACIFIC__)
Palm C/C++ (_PACC_VER)
Pelles C (__POCC__)
Portland Group C/C++ (__PGI, __PGIC__)
Renesas C/C++ (__RENESAS__ or __HITACHI__, __RENESAS_VERSION__)
SAS/C (SASC or __SASC or __SASC__, __VERSION__, __REVISION__)
SCO OpenServer (_SCO_DS)
Small Device C Compiler (SDCC)
SN Compiler (__SNC__)
Stratus VOS C (__VOSC__)
Symantec C++ (__SC__)
TenDRA C/C++ (__TenDRA__)
Texas Instruments C/C++ Compiler (__TI_COMPILER_VERSION__ or _TMS320C6X, __TI_COMPILER_VERSION__)
THINK C (THINKC3, THINKC4)
Turbo C/C++ (__TURBOC__)
Ultimate C/C++ (_UCC, _MAJOR_REV, _MINOR_REV)
USL C (__USLC__, __SCO_VERSION__)
VBCC (__VBCC__)
Zortech C++ (__ZTC__)
*/

#endif /* !CHECK_FEATURE__TOKEN_PASTING_H */
