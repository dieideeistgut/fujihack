#ifndef MODEL_NAME
	#include "../model/xf1.h"
#endif

#include <string.h>
#include <stdint.h>
#include "fujifilm.h"
#include "sqlite.h"

#if 0
#include "font/font.h"

void pixel(int x, int y) {
	int *buf = (int *)SCREEN_BUFFER;
	buf[SCREEN_WIDTH * y + x] = 0x0;
}

void rect(int x1, int y1, int w1, int h1) {
	for (int x = x1; x < w1+x1; x++) {
		for (int y = y1; y < h1+y1; y++) {
			pixel(x, y);
		}
	}
}

int printChar(int x, int y, char c) {
	// Loop to "null terminator character"
	int match = 0;
	for (int l = 0; font[l].letter != 0; l++) {
		if (font[l].letter == c) {
			match = l;
			break;
		}
	}

	// Loop through 7 high 5 wide monochrome font
	int maxLength = 0;
	for (int py = 0; py < 7; py++) {
		for (int px = 0; px < 5; px++) {
			if (font[match].code[py][px] == '#') {
				pixel(x + px, y + py);

				// Dynamix width character spacing
				if (px > maxLength) {
					maxLength = px;
				}
			}
		}
	}

	return maxLength;
}
#endif

void entry() {
	int buf;
	int r = fuji_malloc(0x014559c8, &buf, -1);

	char *a = (char*)MEM_MODEL_TEXT;

	sqlite_snprintf(40, a, "E %d", r);
}