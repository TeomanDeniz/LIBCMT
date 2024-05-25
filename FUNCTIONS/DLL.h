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
# : License - AGPL-3.0  :: Update - 2024/03/15 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*   NAME    :    TYPE    :                   DESCRIPTION                     *|
|*...........:............:...................................................*|
|* DLL       : typedef    : A VARIABLE TYPE FOR HANDLE THE OPENED DLL         *|
|*...........:............:...................................................*|
|* OPEN_DLL  : #define () : OPEN A DLL FILE                                   *|
|*...........:............:...................................................*|
|* READ_DLL  : #define () : CALL A FUNCTION POINTER FROM THE DLL FILE         *|
|*...........:............:...................................................*|
|* CLOSE_DLL : #define () : CLOSE DLL FILE                                    *|
|*...........:............:...................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::: CREATING A DLL FILE ::::::::::::::::::::::::::: *|
|* FOR CREATING DYNAMIC LINK LIBRARIES, YOU MUST COMPILE YOUR .c FILE WITH    *|
|* [-shared] FLAG.                                                            *|
|*                                                                            *|
|* THEN CONGRATS! YOU NOW CREATED A DYNAMIC LINK LIBRARY!                     *|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: CONNECT DLL ::::::::::::::::::::::::::::::: *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* ;.., int variable[9471];                                                   *|
|*    :                                                                       *|
|*    : DLL dll_file;                                                         *|
|*    : dll_file = open_dll("test.bin");                                      *|
|*    : if (!dll_file) // DO SOMETHING IF DLL FILE COULD'T OPEN               *|
|*    :     exit(1);                                                          *|
|*    :                                                                       *|
|*    : int (*my_write)(int, void *, int); // FUNCTION POINTER                *|
|*    : my_write = (int (*)(int, void *, int)) read_dll(dll_file, "write");   *|
|*    : if (!my_write) // DO SOMETHING IF FUNCTION DOESN'T EXIST FROM DLL     *|
|*    :     exit(1);                                                          *|
|*    :                                                                       *|
|*    : my_write(1, "test\n", 5);                                             *|
|*    : close_dll(dll_file);                                                  *|
|*    :                                                                       *|
|*    ;.., DO NOT CLOSE THE DLL FILE BEFORE USING A FUNCTION FROM IT!!!       *|
|*       : IT WILL CAUSE A SEGMENTATION ERROR!                                *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::::::: DLL ::::::::::::::::::::::::::::::::::: *|
|* DYNAMIC LINK LIBRARIES ARE SEPERATED FILES FROM EXECUTABLES THAT NEEDS     *|
|* FUNCTIONS/VARIABLES FROM THAT FILE.                                        *|
|*                                                                            *|
|* WHY COMPILE THE WHOLE PRINTF FUNCTION FOR PER EXE FILE? JUST MAKE PRINTF   *|
|* A DLL THEN CONNECT ALL EXES TO IT.                                         *|
|*                                                                            *|
|* YOUR 40KB~ EXE FILES WILL BECOME 100~ BYTES. CRAZY RIGHT?                  *|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: THIS LIBRARY :::::::::::::::::::::::::::::: *|
|* YOU CAN GET A FUNTION POINTER FROM A DLL FILE AND USE IT DIRECTLY.         *|
|*                                                                            *|
|* BUT THIS LIBRARY JUST DOES THAT CROSS PLATFORM KEYWORDS.                   *|
|*                                                                            *|
\******************************************************************************/

#ifndef DLL_H
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
#	define DLL_H 202403 /* VERSION */
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
#		*/
#	endif /* UNIX */
#	ifdef _WIN32
#		include <windef.h> /*
#		typedef HINSTANCE;
#		*/
#		include <winbase.h> /*
#		 define LoadLibrary
#		FARPROC GetProcAddress(HINSTANCE, LPCSTR);
#		   BOOL FreeLibrary(HMODULE);
#		*/
#	endif
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
typedef void *DLL;
#			define OPEN_DLL(DLL_FILE) (void *)dlopen(DLL_FILE, RTLD_LAZY)
#			define READ_DLL(THE_DLL, FUNCTION_NAME) \
				dlsym(THE_DLL, FUNCTION_NAME)
#			define CLOSE_DLL(DLL_FILE_FOR_CLOSE) dlclose(DLL_FILE_FOR_CLOSE)
#		ifdef _WIN32 /* WINDOWS */
typedef HINSTANCE DLL;
#			define OPEN_DLL(DLL_FILE) LoadLibrary(DLL_FILE)
#			define READ_DLL(THE_DLL, FUNCTION_NAME) \
				GetProcAddress(THE_DLL, FUNCTION_NAME)
#			define CLOSE_DLL(DLL_FILE_FOR_CLOSE) FreeLibrary(DLL_FILE_FOR_CLOSE)
#		endif /* _WIN32 */
#	endif /* UNIX */
#	ifdef __cplusplus /* C++ */
		}
#	endif /* __cplusplus */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
#endif /* DLL_H */
