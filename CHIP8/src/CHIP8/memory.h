#ifndef INC_MEMORY_CHIP8
#define INC_MEMORY_CHIP8
#include "allInclude.h"

struct memory{
	unsigned char mem[4096];
	memory();
	void reset();
};

#endif