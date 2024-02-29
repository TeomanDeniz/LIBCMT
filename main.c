#include "GRAPHICS.h"

#include <stdbool.h>

#define W 500
#define H 500



void
	GRAPHIC_FPS(struct GRAPHIC *WINDOW, unsigned int FPS)
{
	unsigned long long (time);

	time = GRAPHIC_TIME();
	if (time - WINDOW->FPS_START_TIME < 1000 / FPS)
		GRAPHIC_SLEEP(time - WINDOW->FPS_START_TIME);
	WINDOW->FPS_START_TIME = time;
}

void graphic_rect(struct GRAPHIC *WINDOW, int x, int y, int w, int h,
												 uint32_t c) {
	int row;
	int col;

	for (row = 0; row < h; row++) {
		for (col = 0; col < w; col++) {
			GRAPHIC_PIXEL(WINDOW, x + col, y + row, c);
		}
	}
}

// clang-format off

static unsigned short font5x3[95] = {
	0X0000, 0X2092, 0X002d, 0X5f7d, 0X279e,
	0X52a5, 0X7ad6, 0X0012, 0X4494, 0X1491,
	0X017a, 0X05d0, 0X1400, 0X01c0, 0X0400,
	0X12a4, 0X2b6a, 0X749a, 0X752a, 0X38a3,
	0X4f4a, 0X38cf, 0X3bce, 0X12a7, 0X3aae,
	0X49ae, 0X0410, 0X1410, 0X4454, 0X0e38,
	0X1511, 0X10e3, 0X73ee, 0X5f7a, 0X3beb,
	0X624e, 0X3b6b, 0X73cf, 0X13cf, 0X6b4e,
	0X5bed, 0X7497, 0X2b27, 0X5add, 0X7249,
	0X5b7d, 0X5b6b, 0X3b6e, 0X12eb, 0X4f6b,
	0X5aeb, 0X388e, 0X2497, 0X6b6d, 0X256d,
	0X5f6d, 0X5aad, 0X24ad, 0X72a7, 0X6496,
	0X4889, 0X3493, 0X002a, 0Xf000, 0X0011,
	0X6b98, 0X3b79, 0X7270, 0X7b74, 0X6750,
	0X95d6, 0Xb9ee, 0X5b59, 0X6410, 0Xb482,
	0X56e8, 0X6492, 0X5be8, 0X5b58, 0X3b70,
	0X976a, 0Xcd6a, 0X1370, 0X38f0, 0X64ba,
	0X3b68, 0X2568, 0X5f68, 0X54a8, 0Xb9ad,
	0X73b8, 0X64d6, 0X2492, 0X3593, 0X03e0
};

// clang-format on
static void graphic_text(struct GRAPHIC *WINDOW, int x, int y, char *s, int scale, uint32_t c) {
	int dy;
	int dx;

	while (*s) {
		char chr = *s++;
		if (chr > 32) {
			uint16_t bmp = font5x3[(int)chr];
			for (dy = 0; dy < 5; dy++) {
				for (dx = 0; dx < 3; dx++) {
					if (bmp >> (dy * 3 + dx) & 1) {
						graphic_rect(WINDOW, x + dx * scale, y + dy * scale, scale, scale, c);
					}
				}
			}
		}
		x = x + 4 * scale;
	}
}

/* ============================================================
 * A small example demostrating keymaps/keycodes:
 * - On all platforms keys usually correspond to upper-case ASCII
 * - Enter code is 10, Tab is 9, Backspace is 8, Escape is 27
 * - Delete is 127, Space is 32
 * - Modifiers are: Ctrl=1, Shift=2, Ctrl+Shift=3
 *
 * This demo prints currently pressed keys with modifiers.
 * ============================================================ */


int
	main(void)
{
	bool           (has_keys);
	int            (i);
	unsigned int   (buffer)[W * H];
	struct GRAPHIC (WINDOW);

	WINDOW.TITLE = "Press any key...";
	WINDOW.WIDTH = W;
	WINDOW.HEIGHT = H;
	WINDOW.BUFFER = buffer;
	WINDOW_OPEN(&WINDOW);

	while (!GRAPHIC_LOOP(&WINDOW))
	{
		has_keys = false;
		char s[32];
		char *p = s;
		i = -1;
		while (++i, i < 128)
		{
			if (WINDOW.KEYS[i])
			{
				has_keys = true;
				*p++ = i;
			}
		}
		*p = '\0';
		graphic_rect(&WINDOW, 0, 0, W, H, 0);

		/* draw mouse "pointer" */
		if (WINDOW.X > 5 && WINDOW.Y > 5 && WINDOW.X < WINDOW.WIDTH - 5 && \
			WINDOW.Y < WINDOW.HEIGHT - 5)
			graphic_rect(&WINDOW, WINDOW.X - 3, WINDOW.Y - 3, 6, 6, WINDOW.MOUSE ? 0xffffff : 0xff0000);

		graphic_text(&WINDOW, 8, 8, s, 4, 0xffffff);
		if (has_keys)
		{
			if (WINDOW.KEY_MODE & 1)
				graphic_text(&WINDOW, 8, 40, "Ctrl", 4, 0xffffff);

			if (WINDOW.KEY_MODE & 2)
				graphic_text(&WINDOW, 8, 80, "Shift", 4, 0xffffff);
		}

		if (WINDOW.KEYS[27])
			break;

		GRAPHIC_FPS(&WINDOW, 60);
	}

	WINDOW_CLOSE(&WINDOW);
	return (0);
}
