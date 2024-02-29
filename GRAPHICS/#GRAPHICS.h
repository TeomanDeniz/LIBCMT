/******************************************************************************\
# H - #GRAPHICS                                  #       Maximum Tension       #
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

#ifndef _GRAPHICS_H
/* *************************** [v] TI CGT CCS [v] *************************** */
#	ifdef __TI_COMPILER_VERSION__
#		error "TI COMPILER DOES NOT SUPPORT GRAPHIC LIBRARY!!!"
#	endif /* __TI_COMPILER_VERSION__ */
/* *************************** [^] TI CGT CCS [^] *************************** */
#	ifdef __cplusplus /* C++ */
		extern "C" {
#	endif /* __cplusplus */
#	define _GRAPHICS_H 202402 /* VERSION */
/* **************************** [v] INCLUDES [v] **************************** */
#	ifdef __APPLE__
#		include	<CoreGraphics/CoreGraphics.h>
#		include	<objc/NSObjCRuntime.h>
#		include	<objc/objc-runtime.h>
#	else
#		ifdef _WIN32
#			include	<windows.h> /*
#			    int	SetWindowText(HWND, LPCSTR);
*/
#			include <wingdi.h> /*
#			 define BI_BITFIELDS;
#           typedef BITMAPINFOHEADER;
*/
#		else /* DOS */
#			ifdef __DJGPP__
#				include	<dpmi.h> /* DOS PROTECTED MODE
#				 struct	__dpmi_regs;
#				    int	__dpmi_int(int, __dpmi_regs *);
*/
#				include	<go32.h> /*
#				 define	_dos_ds;
*/
#				include	<sys/farptr.h> /*
#				   void	_farpokeb(short, long, char);
#				   void	_farsetsel(short);
#				   void	_farnspokeb(long, char);
*/
#				      include	<pc.h> /*
#				         void	outportb(short, char);
#				unsigned char	inportb(short);
*/
#				include	<dos.h> /*
#				 struct	timespec;
#				   void	delay(int);
*/
#			else /* UNIX */
#				if (defined(__linux__) || defined(__gnu_linux__) || \
					defined(__FreeBSD__) || defined(__NetBSD__) || \
					defined(__OpenBSD__) || defined(__DragonFly__) || \
					defined(__sun)) /* __sun IS SOLARIS SYSTEMS */
#					define _DEFAULT_SOURCE 1
#					include	<X11/XKBlib.h>
#					include	<X11/Xlib.h>
#					include	<X11/keysym.h>
#					include	<time.h> /*
#					    int	nanosleep(struct timespec *, struct timespec *);
*/
#				endif /* UNIX */
#			endif /* DJGPP (DOS) */
#		endif /* WINDOWS */
#	endif /* APPLE */
#	include	<stdint.h>
#	include	<stdlib.h>
#	include	"CMT/FUNCTIONS/PREFETCH.h" /*
#	   void	PREFETCH_RANGE(void *VARIABLE, unsigned int LENGHT)
*/
#	include	"CMT/KEYWORDS/INLINE.h" /*
#	 define	INLINE
*/
#	include	"CMT/KEYWORDS/UNUSED.h" /*
#	 define	UNUSED
#	 define	NOPE
*/
#	include	"CMT/ATTRIBUTES/REGPARM.h" /*
#	 define	REGPARM(VALUE)
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
	unsigned int (FPS_START_TIME);
#	if defined(__APPLE__)
	id            (WINDOW_MODULE);
#	else
#		ifdef _WIN32
	HWND          (WINDOW_HANDLE);
#		else /* UNIX */
	Display            *(DISPLAY);
	Window               (WINDOW);
	GC         (GRAPHICS_CONTEXT);
	XImage               *(IMAGE);
#		endif /* WINDOWS */
#	endif /* APPLE */
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
#	if defined(__APPLE__)
	id            (window_module);
#	else
#		ifdef _WIN32
	HWND          (window_handle);
#		else /* UNIX */
	Display            *(display);
	Window               (window);
	GC         (graphics_context);
	XImage               *(image);
#		endif /* WINDOWS */
#	endif /* APPLE */
};
/* ************************* [^] struct graphic [^] ************************* */
 
/* PUT_PIXEL */
#	ifdef __DJGPP__
#		ifdef __STDC__
extern INLINE void
	PUT_PIXEL(\
		struct GRAPHIC *__GRAPHIC__, \
		unsigned int __PUT_PIXEL_X__, \
		unsigned int __PUT_PIXEL_Y__, \
		unsigned long __PUT_PIXEL_COLOR__\
	)
#		else /* K&R */
extern INLINE void
	PUT_PIXEL(\
		__GRAPHIC__, \
		__PUT_PIXEL_X__, \
		__PUT_PIXEL_Y__, \
		__PUT_PIXEL_COLOR__\
	)
	struct GRAPHIC       *(__GRAPHIC__);
	unsigned int      (__PUT_PIXEL_X__);
	unsigned int      (__PUT_PIXEL_Y__);
	unsigned long (__PUT_PIXEL_COLOR__);
#		endif /* __STDC__ */
{
	NOPE __GRAPHIC__;

	_farpokeb(\
		_dos_ds, \
		0XA0000 + (__PUT_PIXEL_Y__ * 320) + __PUT_PIXEL_X__, \
		__PUT_PIXEL_COLOR__\
	);
}

#		ifdef __STDC__
extern INLINE void
	put_pixel(\
		struct graphic *__graphic__, \
		unsigned int __put_pixel_x__, \
		unsigned int __put_pixel_y__, \
		unsigned long __put_pixel_color__\
	)
#		else /* K&R */
extern INLINE void
	put_pixel(\
		__graphic__, \
		__put_pixel_x__, \
		__put_pixel_y__, \
		__put_pixel_color__\
	)
	struct graphic       *(__graphic__);
	unsigned int      (__put_pixel_x__);
	unsigned int      (__put_pixel_y__);
	unsigned long (__put_pixel_color__);
#		endif /* __STDC__ */
{
	PUT_PIXEL(__graphic__, __put_pixel_x__, __put_pixel_y__, \
		__put_pixel_color__);
}
#	else
#		define PUT_PIXEL(\
			__GRAPHIC__, \
			__PUT_PIXEL_X__, \
			__PUT_PIXEL_Y__, \
			__PUT_PIXEL_COLOR__\
		) (\
			(\
				(__GRAPHIC__)->BUFFER[\
					(\
						(__PUT_PIXEL_Y__) * (__GRAPHIC__)->WIDTH\
					) + (__PUT_PIXEL_X__)\
				]\
			) = __PUT_PIXEL_COLOR__\
		)
#		define put_pixel(\
			__graphic__, \
			__put_pixel_x__, \
			__put_pixel_y__, \
			__put_pixel_color__\
		) (\
			(\
				(__graphic__)->buffer[\
					(\
						(__put_pixel_y__) * (__graphic__)->width\
					) + (__put_pixel_x__)\
				]\
			) = __put_pixel_color__\
		)
#	endif /* __DJGPP__ */
/* PUT_PIXEL */

/* PROTOTPYES */
extern INLINE int	WINDOW_OPEN(struct GRAPHIC *);
extern INLINE int	GRAPHIC_LOOP(struct GRAPHIC *);
extern INLINE void	WINDOW_CLOSE(struct GRAPHIC *);
extern INLINE void	GRAPHIC_SLEEP(long);
extern INLINE long	GRAPHIC_TIME(void);
extern INLINE int	WINDOW_TITLE(struct GRAPHIC *, const char *);
/* PROTOTPYES */

/* WINDOW_OPEN & GRAPHIC_LOOP & WINDOW_CLOSE & GRAPHIC_CLOSE & GRAPHIC_TIME */
#	ifdef __APPLE__
#		define MSG(\
			__MSG_ROUGHNESS__, \
			__MSG_OPTION__, \
			__MSG_SIZE__\
		) (\
			(\
				__MSG_ROUGHNESS__(*)\
				(\
					id, \
					SEL\
				)\
			)\
			objc_msgSend\
		) (\
			__MSG_OPTION__, \
			sel_getUid(__MSG_SIZE__)\
		)
#		define MSG1(\
			__MSG1_ROUGHNESS__, \
			__MSG1_OPTION__, \
			__MSG1_SIZE__, \
			__MSG1_A__, \
			__MSG1_a__\
		) (\
			(\
				__MSG1_ROUGHNESS__(*)\
				(\
					id, \
					SEL, \
					__MSG1_A__\
				)\
			)\
			objc_msgSend\
		) (\
			__MSG1_OPTION__, \
			sel_getUid(__MSG1_SIZE__), \
			__MSG1_a__\
		)
#		define MSG2(\
			__MSG2_ROUGHNESS__, \
			__MSG2_OPTION__, \
			__MSG2_SIZE__, \
			__MSG2_A__, \
			__MSG2_a__, \
			__MSG2_B__, \
			__MSG2_b__\
		) (\
			(\
				__MSG2_ROUGHNESS__(*)\
				(\
					id, \
					SEL, \
					__MSG2_A__, \
					__MSG2_B__\
				)\
			)\
			objc_msgSend\
		) (\
			__MSG2_OPTION__, \
			sel_getUid(__MSG2_SIZE__), \
			__MSG2_a__, \
			__MSG2_b__\
		)
#		define MSG3(\
			__MSG3_ROUGHNESS__, \
			__MSG3_OPTION__, \
			__MSG3_SIZE__, \
			__MSG3_A__, \
			__MSG3_a__, \
			__MSG3_B__, \
			__MSG3_b__, \
			__MSG3_C__, \
			__MSG3_c__\
		) (\
			(\
				__MSG3_ROUGHNESS__(*)\
				(\
					id, \
					SEL, \
					__MSG3_A__, \
					__MSG3_B__, \
					__MSG3_C__\
				)\
			)\
			objc_msgSend\
		) (\
			__MSG3_OPTION__, \
			sel_getUid(__MSG3_SIZE__), \
			__MSG3_a__, \
			__MSG3_b__, \
			__MSG3_c__\
		)
#		define MSG4(__MSG4_ROUGHNESS__, __MSG4_OPTION__, __MSG4_SIZE__, \
			__MSG4_A__, __MSG4_a__, __MSG4_B__, __MSG4_b__, __MSG4_C__, \
			__MSG4_c__, __MSG4_D__, __MSG4_d__) ((__MSG4_ROUGHNESS__(*)(id, \
			SEL, __MSG4_A__, __MSG4_B__, __MSG4_C__, __MSG4_D__))objc_msgSend)\
			(__MSG4_OPTION__, sel_getUid(__MSG4_SIZE__), __MSG4_a__, \
			__MSG4_b__, __MSG4_c__, __MSG4_d__)
#		define REFRESH_SCREEN(__REFRESH_SCREEN_PARAMTER__) (\
			(id)objc_getClass(__REFRESH_SCREEN_PARAMTER__)\
		)

extern id const	NSDefaultRunLoopMode;
extern id const	NSApp;

#		define KEYBOARD_KEYCODES (\
			(char []){\
			 65, 83, 68, 70, 72, 71, 90, 88, 67, 86,  0, 66, 81, 87, 69, 82,\
			 89, 84, 49, 50, 51, 52, 54, 53, 61, 57, 55, 45, 56, 48, 93, 79,\
			 85, 91, 73, 80, 10, 76, 74, 39, 75, 59, 92, 44, 47, 78, 77, 46,\
			  9, 32, 96,  8,  0, 27,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
			  0,  0, 26,  2,  3,127,  0,  5,  0,  4,  0, 20, 19, 18, 17,  0})

static INLINE void
	GRAPHIC_DRAW_RECT(const id VIEW, const SEL SELECTOR, const CGRect RECT)
{
	NOPE RECT;
	NOPE SELECTOR;

	struct GRAPHIC    *(GRAPHIC);
	CGContextRef       (CONTEXT);
	CGColorSpaceRef      (SPACE);
	CGDataProviderRef (PROVIDER);
	CGImageRef           (IMAGE);

	GRAPHIC = (struct GRAPHIC *)objc_getAssociatedObject(VIEW, "GRAPHIC");
	CONTEXT = MSG(CGContextRef, MSG(id, REFRESH_SCREEN("NSGraphicsContext"), \
		"currentContext"), "graphicsPort");
	SPACE = CGColorSpaceCreateDeviceRGB();
	PROVIDER = CGDataProviderCreateWithData(\
		NULL, \
		GRAPHIC->BUFFER, \
		GRAPHIC->WIDTH * GRAPHIC->HEIGHT * 4, \
		NULL\
	);
	IMAGE = CGImageCreate(\
		GRAPHIC->WIDTH, \
		GRAPHIC->HEIGHT, \
		8, \
		32, \
		GRAPHIC->WIDTH * 4, \
		SPACE, \
		(\
			kCGImageAlphaNoneSkipFirst | \
			kCGBitmapByteOrder32Little\
		), \
		PROVIDER, \
		NULL, \
		false, \
		kCGRenderingIntentDefault\
	);
	CGColorSpaceRelease(SPACE);
	CGDataProviderRelease(PROVIDER);
	CGContextDrawImage(\
		CONTEXT, \
		CGRectMake(\
			0, \
			0, \
			GRAPHIC->WIDTH, \
			GRAPHIC->HEIGHT\
		), \
		IMAGE\
	);
	CGImageRelease(IMAGE);
}

static INLINE BOOL
	WINDOW_SHOULD_CLOSE(const id VIEW, const SEL SELECTOR, const id WINDOW)
{
	NOPE VIEW;
	NOPE SELECTOR;
	NOPE WINDOW;

	MSG1(void, NSApp, "terminate:", id, NSApp);
	return (YES);
}

extern INLINE int
	WINDOW_OPEN(struct GRAPHIC *GRAPHIC)
{
	Class    (VOYAGER);
	Class (VIEW_CLASS);
	id         (TITLE);
	id          (VIEW);

	/* PREFETCH POINTERS */
	PREFETCH_RANGE((void *)KEYBOARD_KEYCODES, \
		(unsigned int)sizeof(KEYBOARD_KEYCODES));
	PREFETCH_RANGE((void *)GRAPHIC->BUFFER, GRAPHIC->WIDTH * GRAPHIC->HEIGHT);
	/* PREFETCH POINTERS */

	GRAPHIC->FPS_START_TIME = GRAPHIC_TIME();

	MSG(id, REFRESH_SCREEN("NSApplication"), "sharedApplication");
	MSG1(void, NSApp, "setActivationPolicy:", NSInteger, 0);
	GRAPHIC->WINDOW_MODULE = MSG4(id, MSG(id, REFRESH_SCREEN("NSWindow"), \
		"alloc"), "initWithContentRect:styleMask:backing:defer:", CGRect, \
		CGRectMake(0, 0, GRAPHIC->WIDTH, GRAPHIC->HEIGHT), NSUInteger, 3, \
		NSUInteger, 2, BOOL, NO);

	VOYAGER = objc_allocateClassPair((Class)REFRESH_SCREEN("NSObject"), \
		"WindowDelegate", 0);
	class_addMethod(VOYAGER, sel_getUid("windowShouldClose:"), \
		(IMP)WINDOW_SHOULD_CLOSE, "c@:@");
	objc_registerClassPair(VOYAGER);
	MSG1(void, GRAPHIC->WINDOW_MODULE, "setDelegate:", id, MSG(id, MSG(id, \
		(id)VOYAGER, "alloc"), "init"));

	VIEW_CLASS = objc_allocateClassPair((Class)REFRESH_SCREEN("NSView"), \
		"WindowView", 0);
	class_addMethod(VIEW_CLASS, sel_getUid("drawRect:"), \
		(IMP)GRAPHIC_DRAW_RECT, "i@:@@");
	objc_registerClassPair(VIEW_CLASS);

	VIEW = MSG(id, MSG(id, (id)VIEW_CLASS, "alloc"), "init");
	MSG1(void, GRAPHIC->WINDOW_MODULE, "setContentView:", id, VIEW);
	objc_setAssociatedObject(VIEW, "GRAPHIC", (id)GRAPHIC, \
		OBJC_ASSOCIATION_ASSIGN);

	TITLE = MSG1(id, REFRESH_SCREEN("NSString"), "stringWithUTF8String:", \
		const char *, GRAPHIC->TITLE);
	MSG1(void, GRAPHIC->WINDOW_MODULE, "setTitle:", id, TITLE);
	MSG1(void, GRAPHIC->WINDOW_MODULE, "makeKeyAndOrderFront:", id, nil);
	MSG(void, GRAPHIC->WINDOW_MODULE, "center");
	MSG1(void, NSApp, "activateIgnoringOtherApps:", BOOL, YES);
	return (0);
}

extern INLINE int
	WINDOW_TITLE(struct GRAPHIC *GRAPHIC, const char *TITLE)
{
	id (TITLE_ID);

	if (!GRAPHIC->WINDOW_MODULE || !TITLE)
		return (-1);

	TITLE_ID = MSG1(id, REFRESH_SCREEN("NSString"), "stringWithUTF8String:", \
		const char *, TITLE);
	GRAPHIC->TITLE = TITLE;

	MSG1(void, GRAPHIC->WINDOW_MODULE, "setTitle:", id, TITLE_ID);
	return (0);
}

extern INLINE void
	WINDOW_CLOSE(struct GRAPHIC *GRAPHIC)
{
	if (GRAPHIC->WINDOW_MODULE)
		MSG(void, GRAPHIC->WINDOW_MODULE, "close");
}

extern INLINE int
	GRAPHIC_LOOP(struct GRAPHIC *GRAPHIC)
{
	NSUInteger (EVENT_TYPE);
	id              (EVENT);

	MSG1(void, MSG(id, GRAPHIC->WINDOW_MODULE, "contentView"), \
		"setNeedsDisplay:", BOOL, YES);
	EVENT = MSG4(id, NSApp, "nextEventMatchingMask:untilDate:inMode:dequeue:", \
		NSUInteger, NSUIntegerMax, id, NULL, id, NSDefaultRunLoopMode, BOOL, \
		YES);
	if (!EVENT)
		return (0);

	EVENT_TYPE = MSG(NSUInteger, EVENT, "type");

	if (EVENT_TYPE == 1) /* NSEventTypeMouseDown */
		GRAPHIC->MOUSE |= 1;
	else
	{
		if (EVENT_TYPE == 2) /* NSEventTypeMouseUp*/
			GRAPHIC->MOUSE &= ~1;
		else
		{
			if (EVENT_TYPE == 5 || EVENT_TYPE == 6) /* NSEventTypeMouseMoved */
			{
				register CGPoint (X_AND_Y);

				X_AND_Y = MSG(CGPoint, EVENT, "locationInWindow");
				GRAPHIC->X = (int)X_AND_Y.x;
				GRAPHIC->Y = (int)(GRAPHIC->HEIGHT - X_AND_Y.y);
				return (0);
			}
			else
			{
				if (EVENT_TYPE == 10 /* NSEventTypeKeyDown */ \
					|| EVENT_TYPE == 11 /* NSEventTypeKeyUp */ \
					|| EVENT_TYPE == 12 /* SPECIAL KEY */)
				{
					register NSUInteger      (KEY);
					register NSUInteger (KEY_MODE);

					KEY = MSG(NSUInteger, EVENT, "keyCode");
					if (KEY < 127)
						GRAPHIC->KEYS[(int)KEYBOARD_KEYCODES[KEY]] = \
						(EVENT_TYPE == 10);
					else
						GRAPHIC->KEYS[0] = (EVENT_TYPE == 10);

					KEY_MODE = MSG(NSUInteger, EVENT, "modifierFlags") >> 15;
					GRAPHIC->KEY_MODE = \
						(KEY_MODE & 0XC) | \
						((KEY_MODE & 1) << 1) | \
						((KEY_MODE >> 1) & 1); /*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ISSUE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
					return (0);
				} /* EVENT_TYPE == 10 || EVENT_TYPE == 11 */
			} /* EVENT_TYPE == 5 || EVENT_TYPE == 6 */
		} /* EVENT_TYPE == 2 */
	} /* EVENT_TYPE == 1 */

	MSG1(void, NSApp, "sendEvent:", id, EVENT);
	return (0);
}
#	else
#		ifdef __DJGPP__ /* MSDOS */
const char KEYBOARD_KEYCODES[340] = {\
			  0, 27, 49, 50, 51, 52, 53, 54, 55, 56, 57, 48, 45, 61,  8,  9,
			 81, 87, 69, 82, 84, 89, 85, 73, 79, 80, 91, 93, 10,  0, 65, 83,
			 68, 70, 71, 72, 74, 75, 76, 59, 39, 96,  0, 92, 90, 88, 67, 86,
			 66, 78, 77, 44, 46, 47,  0,  0,  0, 32,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  2, 17,  3,  0, 20,  0, 19,  0,  5,
			 18,  4, 26,127};

#	ifdef __STDC__ /* STANDARD C */
extern INLINE void
	WINDOW_OPEN(struct GRAPHIC *GRAPHIC)
#	else /* K&R */
extern INLINE void
	WINDOW_OPEN(GRAPHIC)

	struct GRAPHIC *(GRAPHIC);
#	endif /* __STDC__ */
{
	GRAPHIC->FPS_START_TIME = GRAPHIC_TIME();
	__dpmi_regs (__REGISTER__);
	__REGISTER__.x.ax = 19; /* 0X13 | 13H */
	__dpmi_int(0X10, &__REGISTER__);
}

#	ifdef __STDC__ /* STANDARD C */
extern INLINE UNUSED int
	GRAPHIC_LOOP(struct GRAPHIC *GRAPHIC)
#	else /* K&R */
extern INLINE UNUSED int
	GRAPHIC_LOOP(GRAPHIC)

	struct GRAPHIC *(GRAPHIC);
#	endif /* __STDC__ */
{
	NOPE GRAPHIC;

	return (0);
}

#	ifdef __STDC__ /* STANDARD C */
extern INLINE void
	WINDOW_CLOSE(struct GRAPHIC *GRAPHIC)
#	else /* K&R */
extern INLINE void
	WINDOW_CLOSE(GRAPHIC)

	struct GRAPHIC *(GRAPHIC);
#	endif /* __STDC__ */
{
	NOPE GRAPHIC;

	__dpmi_regs (__REGISTER__);

	__REGISTER__.x.ax = 3;
	__dpmi_int(0X10, &__REGISTER__);
}

#	ifdef __STDC__ /* STANDARD C */
extern INLINE UNUSED int
	WINDOW_TITLE(struct GRAPHIC *GRAPHIC, const char *TITLE)
#	else /* K&R */
extern INLINE UNUSED int
	WINDOW_TITLE(GRAPHIC, TITLE)

	struct GRAPHIC *(GRAPHIC);
	const char       *(TITLE);
#	endif /* __STDC__ */
{
	NOPE GRAPHIC;
	NOPE TITLE;

	return (0);
}
#		else
#			ifdef _WIN32
#				ifdef __TINYC__ /* TCC */
const char KEYBOARD_KEYCODES[340] = {\
			  0, 27, 49, 50, 51, 52, 53, 54, 55, 56, 57, 48, 45, 61,  8,  9, \
			 81, 87, 69, 82, 84, 89, 85, 73, 79, 80, 91, 93, 10,  0, 65, 83, \
			 68, 70, 71, 72, 74, 75, 76, 59, 39, 96,  0, 92, 90, 88, 67, 86, \
			 66, 78, 77, 44, 46, 47,  0,  0,  0, 32,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  2, 17,  3,  0, 20,  0, 19,  0,  5, \
			 18,  4, 26,127};
#				else /* GCC */
#					define KEYBOARD_KEYCODES (\
						(char [340]){\
			  0, 27, 49, 50, 51, 52, 53, 54, 55, 56, 57, 48, 45, 61,  8,  9, \
			 81, 87, 69, 82, 84, 89, 85, 73, 79, 80, 91, 93, 10,  0, 65, 83, \
			 68, 70, 71, 72, 74, 75, 76, 59, 39, 96,  0, 92, 90, 88, 67, 86, \
			 66, 78, 77, 44, 46, 47,  0,  0,  0, 32,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, \
			  0,  0,  0,  0,  0,  0,  0,  2, 17,  3,  0, 20,  0, 19,  0,  5, \
			 18,  4, 26,127})
#				endif /* __TINYC__ */

typedef struct BINFO
{
		BITMAPINFOHEADER (BITMAP_HEADER);
		RGBQUAD          (BITMAP_COLORS)[3];
} BINFO;

extern INLINE LRESULT CALLBACK
	GRAPHIC_WINDOW_PROCESS_HANDLE(const HWND WINDOW_HANDLE, const UINT MSG, \
		const WPARAM W_PARAM, const LPARAM L_PARAM)
{
	struct GRAPHIC *(GRAPHIC);

	GRAPHIC = (struct GRAPHIC *)GetWindowLongPtr(WINDOW_HANDLE, GWLP_USERDATA);
	if (MSG == WM_PAINT)
	{
		PAINTSTRUCT   (PAINTSTRUCT);
		HDC (HANDLE_DEVICE_CONTEXT);
		HDC (MEMORY_DEVICE_CONTEXT);
		HBITMAP     (HANDLE_BITMAP);
		HBITMAP (HANDLE_OLD_BITMAP);
		BINFO         (BITMAP_INFO);

		BITMAP_INFO.BITMAP_HEADER.biSize = (DWORD) sizeof(BITMAP_INFO);
		BITMAP_INFO.BITMAP_HEADER.biWidth = (LONG) GRAPHIC->WIDTH;
		BITMAP_INFO.BITMAP_HEADER.biHeight = (LONG) -(GRAPHIC->HEIGHT);
		BITMAP_INFO.BITMAP_HEADER.biPlanes = (WORD) 1;
		BITMAP_INFO.BITMAP_HEADER.biBitCount = (WORD) 32;
		BITMAP_INFO.BITMAP_HEADER.biCompression = (DWORD) BI_BITFIELDS;
		HANDLE_DEVICE_CONTEXT = BeginPaint(WINDOW_HANDLE, &PAINTSTRUCT);
		MEMORY_DEVICE_CONTEXT = CreateCompatibleDC(HANDLE_DEVICE_CONTEXT);
		HANDLE_BITMAP = CreateCompatibleBitmap(HANDLE_DEVICE_CONTEXT, \
			GRAPHIC->WIDTH, GRAPHIC->HEIGHT);
		HANDLE_OLD_BITMAP = SelectObject(MEMORY_DEVICE_CONTEXT, HANDLE_BITMAP);

		BITMAP_INFO.BITMAP_COLORS[0].rgbRed = 0XFF;
		BITMAP_INFO.BITMAP_COLORS[1].rgbGreen = 0XFF;
		BITMAP_INFO.BITMAP_COLORS[2].rgbBlue = 0XFF;
		SetDIBitsToDevice(MEMORY_DEVICE_CONTEXT, 0, 0, \
			GRAPHIC->WIDTH, GRAPHIC->HEIGHT, 0, 0, 0, GRAPHIC->HEIGHT, \
			GRAPHIC->BUFFER, (BITMAPINFO *)&BITMAP_INFO, DIB_RGB_COLORS);
		BitBlt(HANDLE_DEVICE_CONTEXT, 0, 0, GRAPHIC->WIDTH, GRAPHIC->HEIGHT, \
			MEMORY_DEVICE_CONTEXT, 0, 0, SRCCOPY);
		SelectObject(MEMORY_DEVICE_CONTEXT, HANDLE_OLD_BITMAP);
		DeleteObject(HANDLE_BITMAP);
		DeleteDC(MEMORY_DEVICE_CONTEXT);
		EndPaint(WINDOW_HANDLE, &PAINTSTRUCT);
	}
	else if (MSG == WM_CLOSE)
		DestroyWindow(WINDOW_HANDLE);
	else if (MSG == WM_LBUTTONDOWN || MSG == WM_LBUTTONUP)
		GRAPHIC->MOUSE = (MSG == WM_LBUTTONDOWN);
	else if (MSG == WM_MOUSEMOVE)
		GRAPHIC->Y = HIWORD(L_PARAM), GRAPHIC->X = LOWORD(L_PARAM);
	else if (MSG == WM_KEYDOWN || MSG == WM_KEYUP)
	{
		GRAPHIC->KEY_MODE = ((GetKeyState(VK_CONTROL) & 0X8000) >> 15) | \
			((GetKeyState(VK_SHIFT) & 0X8000) >> 14) | \
			((GetKeyState(VK_MENU) & 0X8000) >> 13) | \
			(((GetKeyState(VK_LWIN) | GetKeyState(VK_RWIN)) & 0X8000) >> 12);
		GRAPHIC->KEYS[(int) KEYBOARD_KEYCODES[(int) \
			(HIWORD(L_PARAM) & 0X1FF)]] = !((L_PARAM >> 31) & 1);
	}
	else if (MSG == WM_DESTROY)
		PostQuitMessage(0);
	else
		return (DefWindowProc(WINDOW_HANDLE, MSG, W_PARAM, L_PARAM));

	return (0);
}

extern INLINE int
	WINDOW_OPEN(struct GRAPHIC *GRAPHIC)
{
	WNDCLASSEX            (WINDOW_CLASS);
	register HINSTANCE (HANDLE_INSTANCE);

	HANDLE_INSTANCE = GetModuleHandle(NULL);

	/* WINDOW_CLASS */
	WINDOW_CLASS = (WNDCLASSEX){0};
	WINDOW_CLASS.cbSize = sizeof(WNDCLASSEX);
	WINDOW_CLASS.style = CS_VREDRAW | CS_HREDRAW;
	WINDOW_CLASS.lpfnWndProc = GRAPHIC_WINDOW_PROCESS_HANDLE;
	WINDOW_CLASS.hInstance = HANDLE_INSTANCE;
	WINDOW_CLASS.lpszClassName = GRAPHIC->TITLE;
	/* WINDOW_CLASS */

	/* PREFETCH POINTERS */
	PREFETCH_RANGE((void *) KEYBOARD_KEYCODES, (unsigned int) \
		sizeof(KEYBOARD_KEYCODES));
	PREFETCH_RANGE((void *) GRAPHIC->BUFFER, GRAPHIC->WIDTH * GRAPHIC->HEIGHT);
	/* PREFETCH POINTERS */

	GRAPHIC->FPS_START_TIME = GRAPHIC_TIME();
	RegisterClassEx(&WINDOW_CLASS);
	GRAPHIC->WINDOW_HANDLE = CreateWindowEx(WS_EX_CLIENTEDGE, GRAPHIC->TITLE, \
		GRAPHIC->TITLE, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, \
		GRAPHIC->WIDTH, GRAPHIC->HEIGHT, NULL, NULL, HANDLE_INSTANCE, NULL);
	if (GRAPHIC->WINDOW_HANDLE == NULL)
		return (-1);

	SetWindowLongPtr(GRAPHIC->WINDOW_HANDLE, GWLP_USERDATA, (LONG_PTR)GRAPHIC);
	ShowWindow(GRAPHIC->WINDOW_HANDLE, SW_NORMAL);
	UpdateWindow(GRAPHIC->WINDOW_HANDLE);
	return (0);
}

extern INLINE void
	WINDOW_CLOSE(struct GRAPHIC *GRAPHIC)
{
	NOPE GRAPHIC; /* DO NOTHING */
}

extern INLINE int
	GRAPHIC_LOOP(struct GRAPHIC *GRAPHIC)
{
	MSG (MSG);

	while (PeekMessage(&MSG, NULL, 0, 0, PM_REMOVE))
	{
		if (MSG.message == WM_QUIT)
			return (-1);

		TranslateMessage(&MSG);
		DispatchMessage(&MSG);
	}

	InvalidateRect(GRAPHIC->WINDOW_HANDLE, NULL, TRUE);
	return (0);
}

extern INLINE int
	WINDOW_TITLE(struct GRAPHIC *GRAPHIC, const char *TITLE)
{
	if (!GRAPHIC->WINDOW_HANDLE || !TITLE)
		return (-1);

	SetWindowText(GRAPHIC->WINDOW_HANDLE, TITLE);
	GRAPHIC->TITLE = TITLE;
	return (0);
}
#			else
#				if (defined(__linux__) || defined(__gnu_linux__) || \
					defined(__FreeBSD__) || defined(__NetBSD__) || \
					defined(__OpenBSD__) || defined(__DragonFly__) || \
					defined(__sun)) /* __sun IS SOLARIS SYSTEMS */
#					define KEYBOARD_KEYCODES (\
					(unsigned int []){\
					XK_BackSpace,  8,      XK_Delete,127,         XK_Down, 18,\
					      XK_End,  5,      XK_Escape, 27,         XK_Home,  2,\
					   XK_Insert, 26,        XK_Left, 20,    XK_Page_Down,  4,\
					  XK_Page_Up,  3,      XK_Return, 10,        XK_Right, 19,\
					      XK_Tab,  9,          XK_Up, 17,   XK_apostrophe, 39,\
					XK_backslash, 92, XK_bracketleft, 91, XK_bracketright, 93,\
					    XK_comma, 44,       XK_equal, 61,        XK_grave, 96,\
					    XK_minus, 45,      XK_period, 46,    XK_semicolon, 59,\
					    XK_slash, 47,       XK_space, 32,            XK_a, 65,\
					        XK_b, 66,           XK_c, 67,            XK_d, 68,\
					        XK_e, 69,           XK_f, 70,            XK_g, 71,\
					        XK_h, 72,           XK_i, 73,            XK_j, 74,\
					        XK_k, 75,           XK_l, 76,            XK_m, 77,\
					        XK_n, 78,           XK_o, 79,            XK_p, 80,\
					        XK_q, 81,           XK_r, 82,            XK_s, 83,\
					        XK_t, 84,           XK_u, 85,            XK_v, 86,\
					        XK_w, 87,           XK_x, 88,            XK_y, 89,\
					        XK_z, 90,           XK_0, 48,            XK_1, 49,\
					        XK_2, 50,           XK_3, 51,            XK_4, 52,\
					        XK_5, 53,           XK_6, 54,            XK_7, 55,\
					        XK_8, 56,           XK_9, 57})

extern INLINE int
	WINDOW_OPEN(struct GRAPHIC *GRAPHIC)
{
	register int (SCREEN);

	GRAPHIC->DISPLAY = XOpenDisplay(NULL);
	SCREEN = DefaultScreen(GRAPHIC->DISPLAY);
	GRAPHIC->WINDOW = XCreateSimpleWindow(GRAPHIC->DISPLAY, \
		RootWindow(GRAPHIC->DISPLAY, SCREEN), 0, 0, GRAPHIC->WIDTH, \
		GRAPHIC->HEIGHT, 0, BlackPixel(GRAPHIC->DISPLAY, SCREEN), \
		WhitePixel(GRAPHIC->DISPLAY, SCREEN));
	GRAPHIC->GRAPHICS_CONTEXT = XCreateGC(GRAPHIC->DISPLAY, \
		GRAPHIC->WINDOW, 0, 0);

	/* PREFETCH POINTERS */
	PREFETCH_RANGE((void *) KEYBOARD_KEYCODES, (unsigned int) \
		sizeof(KEYBOARD_KEYCODES));
	PREFETCH_RANGE((void *) GRAPHIC->BUFFER, GRAPHIC->WIDTH * GRAPHIC->HEIGHT);
	/* PREFETCH POINTERS */

	GRAPHIC->FPS_START_TIME = GRAPHIC_TIME();
	XSelectInput(GRAPHIC->DISPLAY, GRAPHIC->WINDOW, ExposureMask | \
		KeyPressMask | KeyReleaseMask | ButtonPressMask | \
		ButtonReleaseMask | PointerMotionMask);
	XStoreName(GRAPHIC->DISPLAY, GRAPHIC->WINDOW, GRAPHIC->TITLE);
	XMapWindow(GRAPHIC->DISPLAY, GRAPHIC->WINDOW);
	XSync(GRAPHIC->DISPLAY, GRAPHIC->WINDOW);
	GRAPHIC->IMAGE = XCreateImage(GRAPHIC->DISPLAY, \
		DefaultVisual(GRAPHIC->DISPLAY, 0), 24, ZPixmap, 0, \
		(char *)GRAPHIC->BUFFER, GRAPHIC->WIDTH, GRAPHIC->HEIGHT, 32, 0);
	return (0);
}

extern INLINE void
	WINDOW_CLOSE(struct GRAPHIC *GRAPHIC)
{
	XCloseDisplay(GRAPHIC->DISPLAY);
}

extern INLINE int
	GRAPHIC_LOOP(struct GRAPHIC *GRAPHIC)
{
	XEvent (EVENT);

	XPutImage(GRAPHIC->DISPLAY, GRAPHIC->WINDOW, GRAPHIC->GRAPHICS_CONTEXT, \
		GRAPHIC->IMAGE, 0, 0, 0, 0, GRAPHIC->WIDTH, GRAPHIC->HEIGHT);
	XFlush(GRAPHIC->DISPLAY);
	while (XPending(GRAPHIC->DISPLAY))
	{
		XNextEvent(GRAPHIC->DISPLAY, &EVENT);
		if (EVENT.type == ButtonPress || EVENT.type == ButtonRelease)
			GRAPHIC->MOSUE = (EVENT.type == ButtonPress);
		else if (EVENT.type == MotionNotify)
			GRAPHIC->X = EVENT.xmotion.x, GRAPHIC->Y = EVENT.xmotion.y;
		else if (EVENT.type == KeyPress || EVENT.type == KeyRelease)
		{
			register int     (KEY_MODE);
			register int          (KEY);
			register unsigned int (ECX);

			KEY_MODE = EVENT.xkey.state;
			KEY = XkbKeycodeToKeysym(GRAPHIC->DISPLAY, \
				EVENT.xkey.keycode, 0, 0);
			ECX = 0;
			while (ECX < 124)
			{
				if (KEYBOARD_KEYCODES[ECX] == KEY)
				{
					GRAPHIC->KEYS[KEYBOARD_KEYCODES[ECX + 1]] = \
						(EVENT.type == KeyPress);
					break ;
				}

				ECX += 2;
			}

			GRAPHIC->KEY_MODE = (!!(KEY_MODE & ControlMask)) | \
				(!!(KEY_MODE & ShiftMask) << 1) | \
				(!!(KEY_MODE & Mod1Mask) << 2) | \
				(!!(KEY_MODE & Mod4Mask) << 3);
		}
	}

	return (0);
}

extern INLINE int
	WINDOW_TITLE(struct GRAPHIC *GRAPHIC, const char *TITLE)
{
	if (!GRAPHIC->DISPLAY || !GRAPHIC->WINDOW || !TITLE)
		return (-1);

	XStoreName(GRAPHIC->DISPLAY, GRAPHIC->WINDOW, TITLE);
	XSync(GRAPHIC->DISPLAY, GRAPHIC->WINDOW);
	GRAPHIC->TITLE = TITLE;

	return (0);
}
#				else
"THIS OS OR DEVICE DOES NOT SUPPORT GRAPHICS LMAO" <- error
#				endif /* UNIX */
#			endif /* WINDOWS */
#		endif /* DJGPP */
#	endif /* APPLE */
/* WINDOW_OPEN & GRAPHIC_LOOP & WINDOW_CLOSE & GRAPHIC_CLOSE & GRAPHIC_TIME */

/* GRAPHIC_SLEEP & GRAPHIC_TIME */
#	ifdef _WIN32
extern INLINE void
	GRAPHIC_SLEEP(const long MILLISECONDS)
{
	Sleep(MILLISECONDS);
}

extern INLINE long
	GRAPHIC_TIME(void)
{
	LARGE_INTEGER (FREQUENCY);
	LARGE_INTEGER       (ECX);

	QueryPerformanceFrequency(&FREQUENCY);
	QueryPerformanceCounter(&ECX);
	return ((long)(ECX.QuadPart * 1000.0 / FREQUENCY.QuadPart));
}
#	else /* DJGPP || UNIX */
#		ifdef __DJGPP__

extern INLINE REGPARM(1) void
	GRAPHIC_SLEEP(int MILLISECONDS)
{
	delay((unsigned int) MILLISECONDS);
}

extern INLINE long
	GRAPHIC_TIME(void)
{
	struct time (TIME);
	long      (RESULT);

	gettime(&TIME);
	RESULT = (long)TIME.ti_hund;
	RESULT += (long)TIME.ti_sec * 100L;
	RESULT += (long)TIME.ti_min * 6000L;
	RESULT += (long)TIME.ti_hour * 360000L;
	return (RESULT);
}

#		else /* UNIX */
extern INLINE void
	GRAPHIC_SLEEP(const long MILLISECONDS)
{
	struct timespec (TIME_SPECIAL);

	TIME_SPECIAL.tv_sec = MILLISECONDS / 1000L;
	TIME_SPECIAL.tv_nsec = (MILLISECONDS % 1000L) * 1000000L;

	nanosleep(&TIME_SPECIAL, NULL);
}

extern INLINE long
	GRAPHIC_TIME(void)
{
	struct timespec (TIME);

	clock_gettime(CLOCK_REALTIME, &TIME);
	return (TIME.tv_sec * 1000L + (TIME.tv_nsec / 1000000L));
}
#		endif /* DJGPP || UNIX */
#	endif /* WINDOWS */
/* GRAPHIC_SLEEP & GRAPHIC_TIME */

/* ***************************** [V] LOWERCASE [V] ************************** */
extern INLINE int
	window_open(struct graphic *graphic)
{
	return (WINDOW_OPEN((struct GRAPHIC *) graphic));
}

extern INLINE int
	graphic_loop(struct graphic *graphic)
{
	return (GRAPHIC_LOOP((struct GRAPHIC *) graphic));
}

extern INLINE void
	window_close(struct graphic *graphic)
{
	WINDOW_CLOSE((struct GRAPHIC *) graphic);
}

extern INLINE int
	window_title(struct graphic *graphic, char *title)
{
	return (WINDOW_TITLE((struct GRAPHIC *) graphic, title));
}

extern INLINE void
	graphic_sleep(const long milliseconds)
{
	GRAPHIC_SLEEP(milliseconds);
}

extern INLINE long
	graphic_time(void)
{
	return (GRAPHIC_TIME());
}
/* ***************************** [^] LOWERCASE [^] ************************** */
#	ifdef __cplusplus /* C++ */
		}
#	endif /* __cplusplus */
#endif /* _GRAPHICS_H */
