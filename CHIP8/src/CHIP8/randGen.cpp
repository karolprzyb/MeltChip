#include "allInclude.h"
randomGen::randomGen()
{
	srand((unsigned)time(0));
	num = rand() % 128;
	#ifdef DEBUG_INSTRUCT_LOGGING
	extern log mainLog;
	std::ostringstream convert;
	int converint = (int)num;
	convert << converint;
	mainLog.message = "(Init) Number generated:" + convert.str() + "\n";
	mainLog.writeMessage();
	#endif
}

void randomGen::refresh()
{
	//We want 0-255 returned for the chip8 instruction
	num = rand() % 256;
	#ifdef DEBUG_INSTRUCT_LOGGING
	extern log mainLog;
	std::ostringstream convert;
	int converint = (int)num;
	convert << converint;
	mainLog.message = "Number generated:" + convert.str() + "\n";
	mainLog.writeMessage();
	#endif
}
