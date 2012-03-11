#ifndef INC_STACK_CHIP8
#define INC_STACK_CHIP8
#include "allInclude.h"
struct stack{
	unsigned short int place[16]; //Don't worry buffer overflow protection is added in stack.cpp push and pop functions... a little performance lost
	unsigned char pos;
	stack();
	void push(unsigned short int pushOn);
	unsigned short int pop();
	void reset();
};
#endif
