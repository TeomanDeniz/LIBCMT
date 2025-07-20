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
# : License - AGPL-3.0  :: Update - 2025/07/19 : #    ::::!!!1!!1!!!1!!!::     #
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

#ifndef DLL_H
#	define DLL_H 202507 /* VERSION */

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

/* *************************** [v] C++ (PUSH) [v] *************************** */
#	ifdef __cplusplus /* C++ */
extern "C" {
#	endif /* __cplusplus */
/* *************************** [^] C++ (PUSH) [^] *************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#	if (\
		defined(__APPLE__) || /* MACOS / IOS */\
		defined(__linux__) || /* LINUX */\
		defined(__gnu_linux__) || /* LINUX (GNU) */\
		defined(__FreeBSD__) || /* FREE BSD OS */\
		defined(__NetBSD__) || /* NET BSD OS */\
		defined(__OpenBSD__) || /* OPEN BSD OS */\
		defined(__DragonFly__) || /* DRAGONFLY BSD */\
		defined(__sun) /* SUN STUDIO */\
	) /* UNIX */
#		include	<dlfcn.h> /*
#		 define RTLD_LAZY
#		   void *dlopen(char *, int);
#		   void *dlsym(void *, char *);
#		    int dlclose(void *);
#		        */
#	else /* NOT UNIX */
#		ifdef _WIN32 /* WINDOWS */
#			include <windef.h> /*
#			typedef HINSTANCE;
#			        */
#			include <winbase.h> /*
#			 define LoadLibrary
#			FARPROC GetProcAddress(HINSTANCE, LPCSTR);
#			   BOOL FreeLibrary(HMODULE);
#			        */
#		endif /* WINDOWS */
#	endif /* UNIX */
/* **************************** [^] INCLUDES [^] **************************** */

#	if (\
		defined(__APPLE__) || /* MACOS / IOS */\
		defined(__linux__) || /* LINUX */\
		defined(__gnu_linux__) || /* LINUX (GNU) */\
		defined(__FreeBSD__) || /* FREE BSD OS */\
		defined(__NetBSD__) || /* NET BSD OS */\
		defined(__OpenBSD__) || /* OPEN BSD OS */\
		defined(__DragonFly__) || /* DRAGONFLY BSD */\
		defined(__sun) /* SUN STUDIO */\
	) /* UNIX */
typedef void		*DLL;
#			define OPEN_DLL(DLL_FILE) (void *)dlopen(DLL_FILE, RTLD_LAZY)
#			define READ_DLL(THE_DLL, FUNCTION_NAME) \
				dlsym(THE_DLL, FUNCTION_NAME)
#			define CLOSE_DLL(DLL_FILE_FOR_CLOSE) dlclose(DLL_FILE_FOR_CLOSE)
#			ifdef __GNUC__
#				define DYNAMIC __attribute__((visibility("default")))
#			else
#				ifdef __clang__
#					define DYNAMIC __attribute__((visibility("default")))
#				else // DEFAULT FOR OTHER COMPILERS, LET'S PRAY IT WORKS
#					define DYNAMIC __declspec(dllexport) __cdecl
#				endif /* __clang__ */
#			endif /* __GNUC__ */
#		ifdef _WIN32 /* WINDOWS */
typedef HINSTANCE	DLL;
#			define OPEN_DLL(DLL_FILE) LoadLibrary(DLL_FILE)
#			define READ_DLL(THE_DLL, FUNCTION_NAME) \
				GetProcAddress(THE_DLL, FUNCTION_NAME)
#			define CLOSE_DLL(DLL_FILE_FOR_CLOSE) \
				(int)FreeLibrary(DLL_FILE_FOR_CLOSE)
#			ifdef __GNUC__
#				define DYNAMIC __attribute__((visibility("default")))
#			else
#				ifdef __clang__
#					define DYNAMIC __attribute__((visibility("default")))
#				else // FOR MSVC OR SIMILAR WINDOWS COMPILERS
#					define DYNAMIC __declspec(dllexport) __stdcall
#				endif /* __clang__ */
#			endif /* __GNUC__ */
#		endif /* _WIN32 */
#	endif /* UNIX */

/* *************************** [v] C++ (POP) [v] **************************** */
#	ifdef __cplusplus /* C++ */
}
#	endif /* __cplusplus */
/* *************************** [^] C++ (POP) [^] **************************** */

/* *************************** [v] LOWER CASE [v] *************************** */
typedef DLL	dll;
#	define open_dll OPEN_DLL
#	define close_dll CLOSE_DLL
#	define dynamic DYNAMIC
/* *************************** [^] LOWER CASE [^] *************************** */

/* ************************ [v] TI CGT CCS (POP) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */

#endif /* !DLL_H */
