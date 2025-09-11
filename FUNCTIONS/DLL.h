/******************************************************************************\
# H - DLL                                        #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/03/15 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - GPL-3.0   :: Update - 2025/09/11 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*   NAME    :    TYPE    :                   DESCRIPTION                     *|
|*...........:............:...................................................*|
|* DLL       : typedef    : A VARIABLE TYPE FOR HANDLE THE OPENED DLL         *|
|* dll       :            :                                                   *|
|*...........:............:...................................................*|
|* OPEN_DLL  : #define () : OPEN A DLL FILE                                   *|
|* open_dll  :            :                                                   *|
|*...........:............:...................................................*|
|* READ_DLL  : #define () : CALL A FUNCTION POINTER FROM THE DLL FILE         *|
|* read_dll  :            :                                                   *|
|*...........:............:...................................................*|
|* CLOSE_DLL : #define () : CLOSE DLL FILE                                    *|
|* close_dll :            :                                                   *|
|*...........:............:...................................................*|
|* DYNAMIC   : #define    : SET FUNCTION/VARIABLE AS DYNAMICALLY LINKABLE     *|
|* dynamic   :            :                                                   *|
|*...........:............:...................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::: CREATING A DLL FILE ::::::::::::::::::::::::::: *|
|* FOR CREATING DYNAMIC LINK LIBRARIES, YOU MUST COMPILE YOUR .c FILE WITH    *|
|* [-c] FLAG FIRST TO COMPILE IT AS A STATIC LINK LIBRARY. THEN COMPILE YOUR  *|
|* .o FILE WITH [-shared] FLAG.                                               *|
|*                                                                            *|
|* O - my_dll.c                                                               *|
|* :                                                                          *|
|* ;.., void dynamic my_write(void)                                           *|
|*    : {                                                                     *|
|*    :     printf("TEST\n");                                                 *|
|*    : }                                                                     *|
|*                                                                            *|
|* .........................................................................  *|
|* : CMD                                                            _ [] X :  *|
|* :.......................................................................:  *|
|* :                                                                       :  *|
|* : $> gcc -c my_dll.c -o my_sll.o                                        :  *|
|* : ...                                                                   :  *|
|* :                                                                       :  *|
|* : $> gcc -shared  my_sll.o -o my_dll.dll                                :  *|
|* :                                                                       :  *|
|* :.......................................................................:  *|
|*                                                                            *|
|* THEN CONGRATS! YOU NOW CREATED A DYNAMIC LINK LIBRARY!                     *|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: CONNECT DLL ::::::::::::::::::::::::::::::: *|
|* O - use_dll.c                                                              *|
|* :                                                                          *|
|* ;.., dll dll_file;                                                         *|
|*    :                                                                       *|
|*    : dll_file = open_dll("my_dll.dll");                                    *|
|*    :                                                                       *|
|*    : if (!dll_file) // DO SOMETHING IF DLL FILE COULD'T OPEN               *|
|*    :     exit(1);                                                          *|
|*    :                                                                       *|
|*    : void (*my_write)(); // FUNCTION POINTER                               *|
|*    : my_write = ((*)()) read_dll(dll_file, "my_write");                    *|
|*    :                                                                       *|
|*    : if (!my_write) // DO SOMETHING IF FUNCTION DOESN'T EXIST FROM DLL     *|
|*    :     exit(1);                                                          *|
|*    :                                                                       *|
|*    : my_write();                                                           *|
|*    : close_dll(dll_file);                                                  *|
|*    :                                                                       *|
|*    ;.., DO NOT CLOSE THE DLL FILE BEFORE USING A FUNCTION FROM IT!!!       *|
|*       : IT WILL CAUSE A SEGMENTATION ERROR!                                *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF DOES THAT DO?                           #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::::: DLL ::::::::::::::::::::::::::::::::::: *|
|* DYNAMIC LINK LIBRARIES ARE SEPARATE FILES FROM EXECUTABLES THAT NEED       *|
|* FUNCTIONS/VARIABLES FROM THEM.                                             *|
|*                                                                            *|
|* WHY COMPILE THE WHOLE PRINTF FUNCTION INTO EVERY EXE FILE? JUST MAKE       *|
|* PRINTF A DLL AND CONNECT ALL EXES TO IT.                                   *|
|*                                                                            *|
|* YOUR ~40KB EXE FILES WILL BECOME ~100 BYTES. CRAZY, RIGHT?                 *|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: THIS LIBRARY :::::::::::::::::::::::::::::: *|
|* YOU CAN GET A FUNCTION POINTER FROM A DLL FILE AND USE IT DIRECTLY.        *|
|*                                                                            *|
|* BUT THIS LIBRARY JUST HANDLES CROSS-PLATFORM KEYWORDS FOR THAT.            *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*                                 SIDE NOTES                                 *|
|*############################################################################*|
|*                                                                            *|
|* FOR OS/2 16-BIT OR AMIGAOS-3; USE YOUR FUNCTION'S ORDINAL NUMBER TO        *|
|* RETRIEVE THE FUNCTION POINTER FROM THE DLL.                                *|
|*                                                                            *|
|* REFER TO YOUR COMPILER'S DOCUMENTATION FOR DETAILS ON COMPILING DLLS.      *|
|*                                                                            *|
\*############################################################################*/

#ifndef DLL_H
#	define DLL_H 202509 /* VERSION */

/* *********************** [v] TI CGT CCS (PUSH) [v] ************************ *\
|* *   IT'S WORTH NOTING THAT TI COMPILERS MAY HAVE UNIQUE BEHAVIORS WHEN   * *|
|* *                      DEALING WITH DYNAMIC LINKING                      * *|
\* ************************************************************************** */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_push /* TI CGT CCS COMPILER DIRECTIVES */
#		pragma CHECK_MISRA("5.4") /* TAG NAMES SHALL BE A UNIQUE IDENTIFIER */
#		pragma CHECK_MISRA("19.3") /*
#			THE #INCLUDE DIRECTIVE SHALL BE FOLLOWED BY EITHER A <FILENAME> OR
#			"FILENAME" SEQUENCE
#		*/
#	endif /* __TI_COMPILER_VERSION__ */
/* *********************** [^] TI CGT CCS (PUSH) [^] ************************ */

/* **************************** [v] INCLUDES [v] **************************** */
#	include "../KEYWORDS/INLINE.h" /*
#	 define INLINE
#	        */
#	include "../ENVIRONMENTS/KNR_STYLE.h" /*
#	 define KNR_STYLE
#	        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] C++ (PUSH) [v] *************************** */
#	ifdef __cplusplus /* C++ */
extern "C" {
#	endif /* __cplusplus */
/* *************************** [^] C++ (PUSH) [^] *************************** */

/* ********************* [v] LOCALMACRO_DLL_FOR_OS2 [v] ********************* */
#	ifdef __OS2__
#		define LOCALMACRO_DLL_FOR_OS2
#		define LOCALMACRO_DLL_FOUND
#		ifdef __32BIT__
#			define LOCALMACRO_DLL_FOR_OS2_32BIT
#		else
#			ifdef _M_386
#				define LOCALMACRO_DLL_FOR_OS2_32BIT
#			endif /* _M_386 */
#		endif /* __32BIT__ */
#	else
#		ifdef __EMX__
#			define LOCALMACRO_DLL_FOR_OS2
#			ifdef __32BIT__
#				define LOCALMACRO_DLL_FOR_OS2_32BIT
#			else
#				ifdef _M_386
#					define LOCALMACRO_DLL_FOR_OS2_32BIT
#				endif /* _M_386 */
#			endif /* __32BIT__ */
#		endif /* __EMX__ */
#	endif /* __OS2__ */
/* ********************* [^] LOCALMACRO_DLL_FOR_OS2 [^] ********************* */

/* ******************** [v] LOCALMACRO_DLL_FOR_UNIX [v] ********************* */
#	ifndef LOCALMACRO_DLL_FOUND
#		ifdef __APPLE__
#			define LOCALMACRO_DLL_FOUND
#			define LOCALMACRO_DLL_FOR_UNIX
#		else
#			ifdef __linux__
#				define LOCALMACRO_DLL_FOUND
#				define LOCALMACRO_DLL_FOR_UNIX
#			else
#				ifdef __gnu_linux__
#					define LOCALMACRO_DLL_FOUND
#					define LOCALMACRO_DLL_FOR_UNIX
#				else
#					ifdef __FreeBSD__
#						define LOCALMACRO_DLL_FOUND
#						define LOCALMACRO_DLL_FOR_UNIX
#					else
#						ifdef __NetBSD__
#							define LOCALMACRO_DLL_FOUND
#							define LOCALMACRO_DLL_FOR_UNIX
#						else
#							ifdef __OpenBSD__
#								define LOCALMACRO_DLL_FOUND
#								define LOCALMACRO_DLL_FOR_UNIX
#							else
#								ifdef __DragonFly__
#									define LOCALMACRO_DLL_FOUND
#									define LOCALMACRO_DLL_FOR_UNIX
#								else
#									ifdef __sun
#										define LOCALMACRO_DLL_FOUND
#										define LOCALMACRO_DLL_FOR_UNIX
#									else
#										ifdef __amigaos4__ /* ELF EXIST */
#											define LOCALMACRO_DLL_FOUND
#											define LOCALMACRO_DLL_FOR_UNIX
#										endif /* __amigaos4__ */
#									endif /* __sun */
#								endif /* __DragonFly__ */
#							endif /* __OpenBSD__ */
#						endif /* __NetBSD__ */
#					endif /* __FreeBSD__ */
#				endif /* __gnu_linux__ */
#			endif /* __linux__ */
#		endif /* __APPLE__ */
#	endif /* !LOCALMACRO_DLL_FOUND */
/* ******************** [^] LOCALMACRO_DLL_FOR_UNIX [^] ********************* */

/* ******************* [v] LOCALMACRO_DLL_FOR_WINDOWS [v] ******************* */
#	ifndef LOCALMACRO_DLL_FOUND
#		ifdef _WIN32
#			define LOCALMACRO_DLL_FOUND
#			define LOCALMACRO_DLL_FOR_WINDOWS
#		endif /* _WIN32 */
#	endif /* !LOCALMACRO_DLL_FOUND */
/* ******************* [^] LOCALMACRO_DLL_FOR_WINDOWS [^] ******************* */

/* ****************** [v] LOCALMACRO_DLL_FOR_AMIGAOS3 [v] ******************* */
#	ifndef LOCALMACRO_DLL_FOUND
#		ifdef __MORPHOS__ /* MORPHOS */
#			define LOCALMACRO_DLL_FOUND
#			define LOCALMACRO_DLL_FOR_AMIGAOS3
#		else
#			ifdef __AROS__ /* AROS */
#				define LOCALMACRO_DLL_FOUND
#				define LOCALMACRO_DLL_FOR_AMIGAOS3
#			else
#				ifdef __amigaos__ /* AMIGAOS3 */
#					define LOCALMACRO_DLL_FOUND
#					define LOCALMACRO_DLL_FOR_AMIGAOS3
#				endif /* __amigaos__ */
#			endif /* __AROS__ */
#		endif /* __MORPHOS__ */
#	endif /* !LOCALMACRO_DLL_FOUND */
/* ****************** [^] LOCALMACRO_DLL_FOR_AMIGAOS3 [^] ******************* */

#	ifdef LOCALMACRO_DLL_FOUND
#		ifdef LOCALMACRO_DLL_FOR_OS2
#			ifdef LOCALMACRO_DLL_FOR_OS2_32BIT
/* **************************** [v] INCLUDES [v] **************************** */
#		define INCL_DOSMODULEMGR
#		include <os2.h> /*
#		typedef HMODULE;
#		typedef USHORT;
#		typedef PFN;
#		 USHORT DosLoadModule(PSZ, USHORT, PSZ, PHMODULE);
#		 APIRET DosQueryProcAddr(HMODULE, ULONG, PCSZ, PFN *);
#		 USHORT DosFreeModule(HMODULE);
#		        */
/* **************************** [^] INCLUDES [^] **************************** */

/* **************************** [v] TYPEDEFS [v] **************************** */
typedef HMODULE	DLL;
/* **************************** [^] TYPEDEFS [^] **************************** */

#				ifndef KNR_STYLE /* STANDARD C */
static DLL
	OPEN_DLL(char *__DLL_FILE__)
#				else /* K&R */
static DLL
	OPEN_DLL(__DLL_FILE__)
	char	*__DLL_FILE__;
#				endif /* !KNR_STYLE */
{
	DLL				__TEMP_DLL__;
	register USHORT	RETURN_CODE;

	RETURN_CODE = DosLoadModule((char *)0, 0, __DLL_FILE__, &__TEMP_DLL__);

	if (RETURN_CODE)
		return ((DLL)0);

	return (__TEMP_DLL__);
}

#				ifndef KNR_STYLE /* STANDARD C */
static PFN
	READ_DLL(DLL __THE_DLL__, char *__FUNCTION_NAME__)
#				else /* K&R */
static PFN
	READ_DLL(__THE_DLL__, __FUNCTION_NAME__)
	DLL		__THE_DLL__;
	char	*__FUNCTION_NAME__;
#				endif /* !KNR_STYLE */
{
	PFN	ADDRESS;

	ADDRESS = (PFN)0;
	if (DosQueryProcAddr(__THE_DLL__, 0, __FUNCTION_NAME__, &ADDRESS) == 0)
		return (ADDRESS);

	return ((PFN)0);
}

#				define CLOSE_DLL(__DLL_FILE_FOR_CLOSE__) \
					(DosFreeModule(__DLL_FILE_FOR_CLOSE__) == 0)
#				ifdef __GNUC__
#					define DYNAMIC __declspec(dllexport)
#				else /* OLDER OS/2 COMPILERS */
#					define DYNAMIC _export
#				endif /* __GNUC__ */
#			else /* 16BIT */
/* **************************** [v] INCLUDES [v] **************************** */
#		define INCL_DOSMODULEMGR
#		include <os2.h> /*
#		typedef SEL;
#		typedef USHORT;
#		typedef PFN;
#		 APIRET DosLoadSeg(PCSZ, PSEL);
#		 APIRET DosGetProcAddr(SEL, USHORT, PFN *);
#		 APIRET DosFreeSeg(SEL);
#		        */
/* **************************** [^] INCLUDES [^] **************************** */

/* **************************** [v] TYPEDEFS [v] **************************** */
typedef SEL	DLL;
/* **************************** [^] TYPEDEFS [^] **************************** */

#				ifndef KNR_STYLE /* STANDARD C */
static DLL
	OPEN_DLL(char *__DLL_FILE__)
#				else /* K&R */
static DLL
	OPEN_DLL(__DLL_FILE__)
	char	*__DLL_FILE__;
#				endif /* !KNR_STYLE */
{
	SEL		SEGMENT;
	USHORT	RETURN_CODE;

	RETURN_CODE = DosLoadSeg(__DLL_FILE__, &SEGMENT);

	if (RETURN_CODE)
		return ((DLL)0);

	return (SEGMENT);
}

#				ifndef KNR_STYLE /* STANDARD C */
static PFN
	READ_DLL(DLL __THE_DLL__, USHORT __FUNCTION_ORDINAL__)
#				else /* K&R */
static PFN
	READ_DLL(__THE_DLL__, __FUNCTION_ORDINAL__)
	DLL		__THE_DLL__;
	USHORT	__FUNCTION_ORDINAL__;
#				endif /* !KNR_STYLE */
{
	PFN	ADDRESS;

	ADDRESS = (PFN)0;

	if (DosGetProcAddr(__THE_DLL__, __FUNCTION_ORDINAL__, &ADDRESS) == 0)
		return (ADDRESS);

	return ((PFN)0);
}

#				define CLOSE_DLL(__DLL_FILE_FOR_CLOSE__) \
					(DosFreeSeg(__DLL_FILE_FOR_CLOSE__) == 0)
#				define DYNAMIC _export
#			endif /* LOCALMACRO_DLL_FOR_OS2_32BIT */
#		endif /* LOCALMACRO_DLL_FOR_OS2 */
#		ifdef LOCALMACRO_DLL_FOR_UNIX
/* **************************** [v] INCLUDES [v] **************************** */
#			include	<dlfcn.h> /*
#			 define RTLD_LAZY
#			   void *dlopen(char *, int);
#			   void *dlsym(void *, char *);
#			    int dlclose(void *);
#			        */
/* **************************** [^] INCLUDES [^] **************************** */

/* **************************** [v] TYPEDEFS [v] **************************** */
typedef void	*DLL;
/* **************************** [^] TYPEDEFS [^] **************************** */

#			define OPEN_DLL(__DLL_FILE__) \
				(void *)dlopen(__DLL_FILE__, RTLD_LAZY)
#			define READ_DLL(__THE_DLL__, __FUNCTION_NAME__) \
				dlsym(__THE_DLL__, __FUNCTION_NAME__)
#			define CLOSE_DLL(__DLL_FILE_FOR_CLOSE__) \
				dlclose(__DLL_FILE_FOR_CLOSE__)
#			ifdef __GNUC__
#				define DYNAMIC __attribute__((visibility("default")))
#			else
#				ifdef __clang__
#					define DYNAMIC __attribute__((visibility("default")))
#				else // DEFAULT FOR OTHER COMPILERS, LET'S PRAY IT WORKS
#					define DYNAMIC __declspec(dllexport) __cdecl
#				endif /* __clang__ */
#			endif /* __GNUC__ */
#		endif /* LOCALMACRO_DLL_FOR_UNIX */
#		ifdef LOCALMACRO_DLL_FOR_WINDOWS
/* *************************** [v] PROTOTYPES [v] *************************** */
extern void *LoadLibraryA(const char *);
extern void *GetProcAddress(void *, const char *);
extern int FreeLibrary(void *);
/* *************************** [^] PROTOTYPES [^] *************************** */

/* **************************** [v] TYPEDEFS [v] **************************** */
typedef void	*DLL;
/* **************************** [^] TYPEDEFS [^] **************************** */

#			define OPEN_DLL(__DLL_FILE__) LoadLibraryA(__DLL_FILE__)
#			define READ_DLL(__THE_DLL__, __FUNCTION_NAME__) \
				GetProcAddress(__THE_DLL__, __FUNCTION_NAME__)
#			define CLOSE_DLL(__DLL_FILE_FOR_CLOSE__) \
				(int)FreeLibrary(__DLL_FILE_FOR_CLOSE__)
#			ifdef __GNUC__
#				define DYNAMIC __attribute__((visibility("default")))
#			else
#				ifdef __clang__
#					define DYNAMIC __attribute__((visibility("default")))
#				else // FOR MSVC OR SIMILAR WINDOWS COMPILERS
#					define DYNAMIC __declspec(dllexport) __stdcall
#				endif /* __clang__ */
#			endif /* __GNUC__ */
#		endif /* LOCALMACRO_DLL_FOR_WINDOWS */
#		ifdef LOCALMACRO_DLL_FOR_AMIGAOS3
/* **************************** [v] INCLUDES [v] **************************** */
#			include <proto/exec.h> /*
#			 struct Library;
#			>>>>>>> struct Library *
#			^^^^^^^ OpenLibrary(char *, ulong);
#			   void CloseLibrary(struct Library *);
#			        */
#			include <proto/dos.h> /* INCLUDING ANYWAY */
/* **************************** [^] INCLUDES [^] **************************** */

/* **************************** [v] TYPEDEFS [v] **************************** */
typedef struct Library	*DLL;
/* **************************** [^] TYPEDEFS [^] **************************** */

#			define OPEN_DLL(__DLL_FILE__) \
				IExec->OpenLibrary(__DLL_FILE__, (unsigned long)0)
#			define READ_DLL(__THE_DLL__, __FUNCTION_ORDINAL__) \
				(\
					(void (*)())\
					(\
						(char *)(__THE_DLL__)->lib_Open - \
						(6 * (__FUNCTION_ORDINAL__))\
					)\
				)
#			define CLOSE_DLL(__DLL_FILE_FOR_CLOSE__) \
				IExec->CloseLibrary(__DLL_FILE_FOR_CLOSE__)
#			define DYNAMIC
#		endif /* LOCALMACRO_DLL_FOR_AMIGAOS3 */
#	else
#		error "OPERATING SYSTEM OR COMPILER DOESN'T SUPPORT DLL(S)!!!"
#	endif /* LOCALMACRO_DLL_FOUND */

/* *************************** [v] LOWER CASE [v] *************************** */
typedef DLL	dll;

#	define open_dll OPEN_DLL
#	define read_dll READ_DLL
#	define close_dll CLOSE_DLL
#	define dynamic DYNAMIC
/* *************************** [^] LOWER CASE [^] *************************** */

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

#endif /* !DLL_H */
