/******************************************************************************\
# H - GRAPHICS                                   #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
# ---------------------------------------------- #  :!:    : :: : :  :  ::::!: #
# Serge Zaitsev (Aka: zserge)                    #   :!:: :!:!1:!:!::1:::!!!:  #
# Dimitri Sokolyuk (Aka: dim13)                  #   ::!::!!1001010!:!11!!::   #
# Ian Bryant (Aka: recidivism5)                  #   :!1!!11000000000011!!:    #
# Kirill (Aka: dartvader316)                     #    ::::!!!1!!1!!!1!!!::     #
# Grauho (Aka: grauho)                           #       ::::!::!:::!::::      #
#                                                #                             #
# +.....................++.....................+ #                             #
# : C - Maximum Tension :: Create - 2023/05/25 : #                             #
# :---------------------::---------------------: #                             #
# : License - AGPL-3.0  :: Update - 2024/01/24 : #                             #
# +.....................++.....................+ #                             #
\******************************************************************************/

/*
#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 400

int
	main(void)
{
	unsigned int	BUFFER[SCREEN_WIDTH * SCREEN_HEIGHT];

	struct GRAPHIC GRAPHIC = {
		.TITLE = "TEST TITLE",
		.WIDTH = SCREEN_WIDTH,
		.HEIGHT = SCREEN_HEIGHT,
		.BUFFER = BUFFER,
	};

	WINDOW_OPEN(&GRAPHIC);  // OPEN WINDOW

		GRAPHIC_PIXEL(&GRAPHIC, 200, 200, 0XFFFFFF); // PUT A WHITE PIXEL IN THE MIDDLE

		WINDOW_TITLE(&GRAPHIC, "ANOTHER TEST TITLE"); // EDIT WINDOW TITLE

	WINDOW_CLOSE(&GRAPHIC); // CLOSE WINDOW
	return (0);
}
*/

/*

 ____ ____ ____ ____ ____ ____ ____ ____ _________ ____ ____ ____ ____ ____ 
||K |||E |||Y |||B |||O |||A |||R |||D |||       |||I |||N |||P |||U |||T ||
||__|||__|||__|||__|||__|||__|||__|||__|||_______|||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|/__\|/__\|/__\|/_______\|/__\|/__\|/__\|/__\|/__\|

27: ESC
8: Backspace
9: Tab
13: Enter
32: Spacebar
127: Delete
48-57: 0-9 (number keys)
65-90: A-Z / a-z (letter keys)

Arrow keys:
17: Up Arrow
18: Down Arrow
19: Right Arrow
20: Left Arrow

Modifier keys:
2: Home
3: Page Up
4: Page Down
5: End

*/

#ifndef GRAPHICS_H
/* *************************** [v] TI CGT CCS [v] *************************** */
#	ifdef __TI_COMPILER_VERSION__
#		error "TI COMPILER DOES NOT SUPPORT GRAPHIC LIBRARY!!!"
#	endif /* __TI_COMPILER_VERSION__ */
/* *************************** [^] TI CGT CCS [^] *************************** */
#	ifdef __cplusplus /* C++ */
		extern "C" {
#	endif /* __cplusplus */
#	define GRAPHICS_H 202402 /* VERSION */
/* **************************** [v] INCLUDES [v] **************************** */
#	include	"CMT/KEYWORDS/INLINE.h" /*
#	 define	INLINE
*/
/* **************************** [^] INCLUDES [^] **************************** */
/* ************************* [v] struct GRAPHIC [v] ************************* */
struct GRAPHIC
{
	const char           *(TITLE);
	int                   (WIDTH);
	int                  (HEIGHT);
	unsigned int        *(BUFFER);
	int                    (KEYS)[256];
	int                (KEY_MODE);
	int                       (X); /* MOUSE X */
	int                       (Y); /* MOUSE Y */
	int                   (MOUSE); /* MOUSE INPUT */
};
/* ************************* [^] struct GRAPHIC [^] ************************* */
/* ************************* [v] struct graphic [v] ************************* */
struct graphic
{
	const char           *(title);
	int                   (width);
	int                  (height);
	unsigned int        *(buffer);
	int                    (keys)[256];
	int                (key_mode);
	int                       (x); /* MOUSE X */
	int                       (y); /* MOUSE Y */
	int                   (mouse); /* MOUSE INPUT */
};
/* ************************* [^] struct graphic [^] ************************* */
 
/* *************************** [v] PUT_PIXEL [v] **************************** */
#	ifdef __DJGPP__
#		ifdef __STDC__
extern INLINE void	PUT_PIXEL(\
		struct GRAPHIC *__GRAPHIC__, \
		unsigned int __PUT_PIXEL_X__, \
		unsigned int __PUT_PIXEL_Y__, \
		unsigned long __PUT_PIXEL_COLOR__\
	);
#		else /* K&R */
extern INLINE void	PUT_PIXEL();
#		endif /* __STDC__ */

#		ifdef __STDC__
extern INLINE void	put_pixel(\
		struct graphic *__graphic__, \
		unsigned int __put_pixel_x__, \
		unsigned int __put_pixel_y__, \
		unsigned long __put_pixel_color__\
	);
#		else /* K&R */
extern INLINE void	put_pixel();
#		endif /* __STDC__ */
#	else
#		include "putpixel.c" /////////////////////////////////////
#	endif /* __DJGPP__ */
/* *************************** [^] PUT_PIXEL [^] **************************** */

extern INLINE int	WINDOW_OPEN(struct GRAPHIC *GRAPHIC);
extern INLINE void	WINDOW_CLOSE(struct GRAPHIC *GRAPHIC);
extern INLINE int	GRAPHIC_LOOP(struct GRAPHIC *GRAPHIC);
extern INLINE int	WINDOW_TITLE(struct GRAPHIC *GRAPHIC, const char *TITLE);
extern INLINE void	GRAPHIC_SLEEP(const long MILLISECONDS);
extern INLINE long	GRAPHIC_TIME(void);

/* ***************************** [V] LOWERCASE [V] ************************** */
extern INLINE int	window_open(struct graphic *graphic);
extern INLINE int	graphic_loop(struct graphic *graphic);
extern INLINE void	window_close(struct graphic *graphic);
extern INLINE int	window_title(struct graphic *graphic, char *title);
extern INLINE void	graphic_sleep(const long milliseconds);
extern INLINE long	graphic_time(void);
/* ***************************** [^] LOWERCASE [^] ************************** */

/* ***************************** [V] C++ CLASS [V] ************************** */
#	ifdef __cplusplus /* C++ */
		} /* C++ */

class GRAPHIC
{
	struct GRAPHIC (GRAPHIC);
	long               (NOW);

public: /* ************************* [v] PUBLIC [v] ************************* */
/* ************************** [v] CONSTRUCTOR [v] *************************** */
	GRAPHIC(const unsigned int WIDTH, const unsigned int HEIGHT, char *TITLE)
		: GRAPHIC {.TITLE = TITLE, .WIDTH = WIDTH, .HEIGHT = HEIGHT}
	{
		this->GRAPHIC.BUFFER = new unsigned int [WIDTH * HEIGHT];
		this->NOW = GRAPHIC_TIME();
		WINDOW_OPEN(&this->GRAPHIC);
	}
/* ************************** [^] CONSTRUCTOR [^] *************************** */
/* *************************** [v] DESTRUCTOR [v] *************************** */
	~GRAPHIC(void)
	{
		WINDOW_CLOSE(&this->GRAPHIC);
		delete [] this->GRAPHIC.BUFFER;
	}
/* *************************** [^] DESTRUCTOR [^] *************************** */
	REGPARM(1) bool
		LOOP(const int FPS)
	{
		long (TIME);

		TIME = GRAPHIC_TIME();

		if (TIME - this->NOW < 1000 / FPS)
			GRAPHIC_SLEEP(TIME - NOW);

		this->NOW = TIME;
		return (GRAPHIC_LOOP(&this->GRAPHIC) == 0);
	}

	REGPARM(3) void
		PIXEL(const unsigned int X, const unsigned int Y, \
			const unsigned long COLOR)
	{
		GRAPHIC_PIXEL(this->GRAPHIC, X, Y, COLOR);
	}

	REGPARM(1) bool
		KEY(int CHARACTER)
	{
		if (CHARACTER >= 0 && CHARACTER < 128)
			return (this->GRAPHIC.KEYS[CHARACTER])

		return (false);
	}

	int
		X(void)
	{
		return (this->GRAPHIC.X);
	}

	int
		Y(void)
	{
		return (this->GRAPHIC.Y);
	}

	int
		MOUSE(void)
	{
		return (this->GRAPHIC.MOUSE);
	}

	int
		KEY_MODE(void)
	{
		return (this->GRAPHIC.KEY_MODE);
	}
/* ***************************** [^] PUBLIC [^] ***************************** */
};
#	endif /* C++ */
/* ***************************** [^] C++ CLASS [^] ************************** */
#endif /* GRAPHICS_H */
