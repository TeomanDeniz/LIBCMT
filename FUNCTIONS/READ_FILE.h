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
# : License - AGPL-3.0  :: Update - 2025/06/19 : #    ::::!!!1!!1!!!1!!!::     #
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
|*    : if (!read_file("file_name.txt", &file_content))                       *|
|*    :     printf("%d - [%s]\n", content.size, content.data);                *|
|*    : else                                                                  *|
|*    :     printf("Failed to open file.\n");                                 *|
|*    :                                                                       *|
|*    : free(file_content.data); // <-- DON'T FORGET THAT :D                  *|
|*                                                                            *|
|*                              ................                              *|
|*                            .:: ERROR LEVELS ::.                            *|
|* ..........................::::::::::::::::::::::.......................... *|
|* : 0 : FILE OPENED AND READED SUCCESSFULLY!                               : *|
|* :...:....................................................................: *|
|* : 1 : FILE DOES NOT EXIST!                                               : *|
|* :...:....................................................................: *|
|* : 2 : FAILED TO ALLOCATE NECESSARY MEMORY FROM RAM FOR STRCUT'S DATA.    : *|
|* :...:....................................................................: *|
|* : 3 : PERMISSION DENIED WHILE TRYING TO READ THE FILE.                   : *|
|* :...:....................................................................: *|
|*                                                                            *|
|* ::::::::::::::::::::::::::::: STRUCTURE INFO ::::::::::::::::::::::::::::: *|
|*                                                                            *|
|* struct s_file                                                              *|
|* {                                                                          *|
|*     size_t size; <-- SIZE OF THE FILE (BYTES)                              *|
|*     char   *data; <- EVERY BYTE OF THE FILE                                *|
|* };                                                                         *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                              WTF THAT DOES?                              #*|
|*############################################################################*|
|*                                                                            *|
|* READS THE ENTIRE CONTENTS OF A FILE SPECIFIED BY FILE_PATH INTO MEMORY AND *|
|* STORES IT IN A PROVIDED S_FILE STRUCTURE.                                  *|
|*                                                                            *|
\******************************************************************************/

/*############################################################################*\
|*#                                SIDE NOTES                                #*|
|*############################################################################*|
|*                                                                            *|
|* YES, YOU HAVE TO FREE "data" OF THE STRUCTURE WHEN YOU'RE DONE.            *|
|*                                                                            *|
\******************************************************************************/

#ifndef READ_FILE_H
#	define READ_FILE_H 202506 /* VERSION */

/* *********************** [v] TI CGT CCS (PUSH) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_push /* TI CGT CCS COMPILER DIRECTIVES */
#		pragma CHECK_MISRA("5.4") /* TAG NAMES SHALL BE A UNIQUE IDENTIFIER */
#		pragma CHECK_MISRA("19.3") /*
#			THE #INCLUDE DIRECTIVE SHALL BE FOLLOWED BY EITHER A <FILENAME> OR
#			"FILENAME" SEQUENCE
#		*/
#	endif /* __TI_COMPILER_VERSION__ */
/* *********************** [^] TI CGT CCS (PUSH) [^] ************************ */

#	ifdef __cplusplus /* C++ */
/* **************************** [v] INCLUDES [v] **************************** */
#		include <iostream> /*
#		nmspace std;
#		  class std::streamsize;
#		        */
#		include <ios> /*
#		  class std::ios;
#		        */
#		include <new> /*
#		>>>>>>> std::nothrow_t
#		^^^^^^^ nothrow;
#		        */
#		include <cstddef> /*
#		typedef size_t;
#		        */
#		include <string> /*
#		  class std::string;
#		        */
#		include <fstream> /*
#		  class std::ifstream;
#		        */
#		include	"../KEYWORDS/INLINE.h" /*
#		 define INLINE
#		        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] STRUCT [v] ***************************** */
struct S_FILE
{
	size_t	SIZE = 0;
	char	*DATA = (char *)0;
};

struct s_file
{
	size_t	size = 0;
	char	*data = (char *)0;
};
/* ***************************** [^] STRUCT [^] ***************************** */

static INLINE int
	READ_FILE(const std::string &FILE_PATH, struct S_FILE *const FILE_STRUCT)
{
	if (FILE_PATH.empty())
		return (1);

	std::ifstream	INPUT(FILE_PATH, std::ios::binary | std::ios::ate);

	if (!INPUT)
		return (1);

	std::streamsize	FILE_SIZE = INPUT.tellg();

	if (FILE_SIZE <= 0)
		return (1);

	INPUT.seekg(0, std::ios::beg);

	FILE_STRUCT->DATA = new(std::nothrow) char[FILE_SIZE];

	if (!FILE_STRUCT->DATA)
		return (2);

	if (!INPUT.read(FILE_STRUCT->DATA, FILE_SIZE))
	{
		delete[] FILE_STRUCT->DATA;
		FILE_STRUCT->DATA = (char *)0;
		return (3);
	}

	FILE_STRUCT->SIZE = static_cast<size_t>(FILE_SIZE);
	return (0);
}

/* *************************** [v] LOWER CASE [v] *************************** */
static INLINE int
	read_file(const std::string &file_path, struct s_file *const file_struct)
{
	return (READ_FILE(file_path, (struct S_FILE *)file_struct));
}
/* *************************** [^] LOWER CASE [^] *************************** */

#	else /* C */

/* **************************** [v] INCLUDES [v] **************************** */
#		include <stddef.h> /*
#		typedef size_t;
#		        */
#		include <stdio.h> /*
#		 define SEEK_END
		typedef FILE;
		   FILE *fopen(char *, char *);
		    int fseek(FILE *, long, int);
		    int fclose(FILE *);
		   long ftell(FILE *);
		   void rewind(FILE *);
		 size_t fread(void *, size_t, size_t, FILE *);
#		        */
#		ifndef KNR_STYLE /* STANDARD C */
#			include <stdlib.h> /*
			   void *malloc(size_t);
			   void free(void *);
#			        */
#		else /* K&R */
// <stdlib.h> MAY NOT EXIST
extern void	*malloc();
extern void	free();
#		endif /* !KNR_STYLE */
#		include "../KEYWORDS/INLINE.h" /*
#		 define INLINE
#		        */
#		include "../ATTRIBUTES/FAR.h" /*
#		 define FAR
#		        */
#		include "../ENVIRONMENTS/KNR_STYLE.h" /*
#		 define KNR_STYLE
#		        */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] STRUCT [v] ***************************** */
struct S_FILE
{
	size_t		SIZE;
	FAR char	*DATA;
};

struct s_file
{
	size_t		size;
	FAR char	*data;
};
/* ***************************** [^] STRUCT [^] ***************************** */

/* **************************** [v] TYPEDEFS [v] **************************** */
typedef struct S_FILE	T_FILE;
typedef struct s_file	t_file;
/* **************************** [^] TYPEDEFS [^] **************************** */

#		ifndef KNR_STYLE /* STANDARD C */
static INLINE int
	READ_FILE(const char *FILE_PATH, FAR struct S_FILE *const FILE_STRUCT)
#		else /* K&R */
static INLINE int
	READ_FILE(FILE, FILE_STRUCT)
	char				*FILE_PATH;
	FAR struct S_FILE	*FILE_STRUCT;
#		endif /* !KNR_STYLE */
{
	FILE	*FILE_POINTER;

	if (!FILE_PATH || !FILE_STRUCT)
		return (1);

	FILE_STRUCT->DATA = (char *)0;
	FILE_STRUCT->SIZE = (size_t)0;
	FILE_POINTER = fopen(FILE_PATH, "rb");

	if (!FILE_POINTER)
		return (1);

	if (fseek(FILE_POINTER, 0, SEEK_END) != 0)
	{
		fclose(FILE_POINTER);
		return (1);
	}

	FILE_STRUCT->SIZE = ftell(FILE_POINTER);

	if (FILE_STRUCT->SIZE <= 0)
	{
		fclose(FILE_POINTER);
		return (1);
	}

	rewind(FILE_POINTER);
	FILE_STRUCT->DATA = (FAR char *)malloc(FILE_STRUCT->SIZE);

	if (!FILE_STRUCT->DATA)
	{
		fclose(FILE_POINTER);
		return (2);
	}

	if (
		fread(
			FILE_STRUCT->DATA,
			1,
			FILE_STRUCT->SIZE,
			FILE_POINTER
		) != FILE_STRUCT->SIZE
	)
	{
		free(FILE_STRUCT->DATA);
		FILE_STRUCT->DATA = (char *)0;
		fclose(FILE_POINTER);
		return (3);
	}

	fclose(FILE_POINTER);
	return (0);
}

/* *************************** [v] LOWER CASE [v] *************************** */
#		ifndef KNR_STYLE /* K&R */
static INLINE int
	read_file(const char *file_path, FAR struct s_file *const file_struct)
#		else /* STANDARD C */
static INLINE int
	read_file(file_path, file_struct)
	char				*file_path;
	FAR struct s_file	*file_struct;
#		endif /* !KNR_STYLE */
{
	return (READ_FILE(file_path, (FAR struct S_FILE *)file_struct));
}
/* *************************** [^] LOWER CASE [^] *************************** */

#	endif /* __cplusplus */

/* ************************ [v] TI CGT CCS (POP) [v] ************************ */
#	ifdef __TI_COMPILER_VERSION__
#		pragma diag_pop /* TI CGT CCS COMPILER DIRECTIVES */
#	endif /* __TI_COMPILER_VERSION__ */
/* ************************ [^] TI CGT CCS (POP) [^] ************************ */

#endif /* !READ_FILE_H */
