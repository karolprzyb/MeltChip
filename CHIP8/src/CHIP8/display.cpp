#include "allInclude.h"

display::display()
{
	for(int x = 0; x < 64; x++)
		for(int y = 0; y < 32; y++)
			buffer_64_32[x][y] = 0;
	#ifdef LOGGING_CHIP8
	extern log mainLog;
	mainLog.message = "Init display memory.\n";
	mainLog.writeMessage();
	#endif
}

void display::reset()
{
	for(int x = 0; x < 64; x++)
		for(int y = 0; y < 32; y++)
			buffer_64_32[x][y] = 0;
	#ifdef DEBUG_INSTRUCT_LOGGING
	extern log mainLog;
	mainLog.message = "Screen memory reset or cleared by instruction.\n";
	mainLog.writeMessage();
	#endif
}
