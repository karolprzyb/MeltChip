#include "allInclude.h"

registers::registers()
{
	for(int x=0; x<0xF; x++)
	{
	V[x]=0;
	}
	SP=0;
	DT=0;
	ST=0;
	I=0;
	PC=0x200;
	#ifdef LOGGING_CHIP8
	extern log mainLog;
	mainLog.message = "Registers init.\n";
	mainLog.writeMessage();
	#endif
}

void registers::reset()
{
	for(int x=0; x<0xF; x++)
	{
	V[x]=0;
	}
	SP=0;
	DT=0;
	ST=0;
	I=0;
	PC=0x200;
	#ifdef LOGGING_CHIP8
	extern log mainLog;
	mainLog.message = "Registers reset.\n";
	mainLog.writeMessage();
	#endif
}
