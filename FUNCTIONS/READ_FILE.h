/******************************************************************************\
# H - READ_FILE                                  #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2025/03/29 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - AGPL-3.0  :: Update - 2025/03/31 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

/*############################################################################*\
|*#                                 CONTENTS                                 #*|
|*############################################################################*|
|*............................................................................*|
|*   NAME    :    TYPE    :                   DESCRIPTION                     *|
|*...........:............:...................................................*|
|* READ_FILE : (*F)()     : READS A FILE AND RETURNS IT'S CONTENT             *|
|* read_file :            :                                                   *|
|*...........:............:...................................................*|
|* S_FILE    : struct     : STRUCT TYPE RETURNS FROM "READ_FILE" FUNCTION     *|
|* s_file    :            :                                                   *|
|*...........:............:...................................................*|
|* T_FILE    : typedef    : struct S_FILE                                     *|
|* t_file    :            : struct s_file                                     *|
|*...........:............:...................................................*|
\******************************************************************************/

/*############################################################################*\
|*#                                HOW TO USE                                #*|
|*############################################################################*|
|*                                                                            *|
|* O - EXAMPLE                                                                *|
|* :                                                                          *|
|* ;.., struct s_file file_content;                                           *|
|*    :                                                                       *|
|*    : if (read_file("file_name.txt", &file_content))                        *|
|*    :     printf("%d - [%s]\n", content.size, content.data);                *|
|*    : else                                                                  *|
|*    :     printf("Failed to open file.\n");                                 *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* :::::::::::::::::::::::::::::: EXPLANATION ::::::::::::::::::::::::::::::: *|
|* RETURNS YOU THE CONTENT OF THE FILE YOU GAVE TO FUNCTION.                  *|
|*                                                                            *|
|*                              ................                              *|
|*                            .:: ERROR LEVELS ::.                            *|
|* ..........................::::::::::::::::::::::.......................... *|
|* : 0 : FILE OPENED AND READED SUCCESSFULLY!                               : *|
|* :...:....................................................................: *|
|* : 1 : FILE DOES NOT EXIST!                                               : *|
|* :...:....................................................................: *|
|* : 2 : FAILED TO ALLOCATE NECESSARY MEMORY FROM RAM FRO STRCUT'S DATA.    : *|
|* :...:....................................................................: *|
|* : 3 : PERMISSION DENIED WHILE TRYING TO READ THE FILE.                   : *|
|* :...:....................................................................: *|
|*                                                                            *|
\******************************************************************************/

#ifndef READ_FILE_H
#	define READ_FILE_H 202503 /* VERSION */

/* *********************** [v] TI CGT CCS (PUSH) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_push /* TI CGT CCS COMPILER DIRECTIVES */
#		pragma CHECK_MISRA("-5.4") /* TAG NAMES SHALL BE A UNIQUE IDENTIFIER */
#		pragma CHECK_MISRA("-19.3") /* THE #INCLUDE DIRECTIVE SHALL BE FOLLOWED
#		BY EITHER A <FILENAME> OR "FILENAME" SEQUENCE */
#	endif /* __TI_COMPILER_VERSION__ */
/* *********************** [^] TI CGT CCS (PUSH) [^] ************************ */

/* *************************** [v] MVS LINKER [v] *************************** */
/* **** MVS LINKER DOES NOT SUPPORT EXTERNAL NAMES LARGER THAN 8 BYTES!! **** */
// NOTE: TARGETING IBM MAINFRAME SYSTEMS (Z/OS)
#ifdef (__MVS__)
#	pragma map(READ_FILE, "RD_FILE0")
#	pragma map(read_file, "rd_file1")
#endif /* __MVS__ */
/* *************************** [^] MVS LINKER [^] *************************** */

/* *************************** [v] C++ (PUSH) [v] *************************** */
#	ifdef __cplusplus /* C++ */
		extern "C" {
#	endif /* __cplusplus */
/* *************************** [^] C++ (PUSH) [^] *************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#	include	"../KEYWORDS/INLINE.h" /*
#	 define INLINE
#	        */
#	include	"../ATTRIBUTES/FAR.h" /*
#	 define FAR
#	        */
#	include	"../ENVIRONMENTS/KNR_STYLE.h" /*
#	 define KNR_STYLE
#	        */
#	include <stdio.h> /*
#	 define SEEK_END
	typedef FILE;
	   FILE *fopen(char *, char *);
	    int fseek(FILE *, long, int);
	    int fclose(FILE *);
	   long ftell(FILE *);
	   void rewind(FILE *);
	  size_t fread(void *, size_t, size_t, FILE *);
#	        */
#	ifdef __STDC__ /* STANDARD C */
#		include <stdlib.h> /*
		   void *malloc(size_t);
		   void free(void *);
#		        */
#	else /* K&R */
extern void	*malloc();
extern void	free();
#	endif /* __STDC__ */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] STRUCT [v] ***************************** */
struct S_FILE
{
	long		SIZE;
	FAR char	*DATA;
};

struct s_file
{
	long		size;
	FAR char	*data;
};
/* ***************************** [^] STRUCT [^] ***************************** */

/* **************************** [v] TYPEDEFS [v] **************************** */
typedef struct S_FILE	T_FILE;
typedef struct s_file	t_file;
/* **************************** [^] TYPEDEFS [^] **************************** */

#	ifndef KNR_STYLE /* K&R */
extern INLINE int
	READ_FILE(const char *FILE, FAR struct S_FILE *const THIS)
#	else /* STANDARD C */
extern INLINE int
	READ_FILE(FILE, THIS)
	char				*FILE;
	FAR struct S_FILE	*THIS;
#	endif /* KNR_STYLE */
{
	FILE	*FILE_POINTER;

	if (!FILE || !THIS)
		return (1);

	THIS->DATA = (void *)0;
	THIS->SIZE = (long)0;
	FILE_POINTER = fopen(FILE, "rb");

	if (!FILE_POINTER)
		return (1);

	if (fseek(FILE_POINTER, 0, SEEK_END) != 0)
	{
		fclose(FILE_POINTER);
		return (1);
	}

	THIS->SIZE = ftell(FILE_POINTER);

	if (THIS->SIZE <= 0)
	{
		fclose(FILE_POINTER);
		return (1);
	}

	rewind(FILE_POINTER);
	THIS->DATA = (FAR char *)malloc(THIS->SIZE);

	if (!THIS->DATA)
	{
		fclose(FILE_POINTER);
		return (2);
	}

	if (fread(THIS->DATA, 1, THIS->SIZE, FILE_POINTER) != THIS->SIZE)
	{
		free(THIS->DATA);
		THIS->DATA = (void *)0;
		fclose(FILE_POINTER);
		return (3);
	}

	fclose(FILE_POINTER);
	return (0);
}

#	ifndef KNR_STYLE /* K&R */
extern INLINE int
	read_file(const char *file, FAR struct s_file *const this)
#	else /* STANDARD C */
extern INLINE int
	read_file(file, this)
	char				*file;
	FAR struct s_file	*this;
#	endif /* KNR_STYLE */
{
	return (READ_FILE(file, (FAR struct S_FILE *)this));
}

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

#endif /* READ_FILE_H */
