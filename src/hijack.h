// Broken and has never worked
#include <stdint.h>

void assemble_b(uintptr_t *from, uintptr_t *to, uint8_t buf[4]) {
	uint32_t temp = (uintptr_t)to;

	// Assemble instruction based on location
	// of new addr relative to old address
	if (from < to) {
		temp = (temp - 8) / 4;
		memcpy(buf, &temp, 4);
	} else {
		temp = 0xffffff - ((from - to + 4) / 4);
		memcpy(buf, &temp, 4);
	}
	
	// arm32 branch "b"
	buf[3] = 0xea;
}
