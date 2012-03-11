#ifndef INC_DISPLAY_CHIP8
#define INC_DISPLAY_CHIP8
#include "allInclude.h"
struct display{
	unsigned char buffer_64_32[64][32];
	display();
	void reset();
};
#endif