#ifndef INC_REGISTERS_CHIP8
#define INC_REGISTERS_CHIP8
#include "allInclude.h"
//Variables created for all the registers right here.
struct registers{
	unsigned char V[0x10];
	unsigned char SP, DT, ST;
	unsigned short int I, PC;

	registers();
	void reset();
};
#endif
