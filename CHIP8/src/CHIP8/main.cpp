// CHIP 8.cpp : Defines the entry point for the console application. Now main.cpp so it compiles in Momentics and makes a binary.
//
#include "allInclude.h"

#ifdef LOGGING_CHIP8
//Global log declaration
log mainLog;
#endif

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	//SDL_Init(SDL_INIT_VIDEO);
	chipTimer timerMain;
	timerMain.setTimer(1.19);
	//INIT VARIABLES
	//Variables include registers, memory, vram, etc...
	#ifdef LOGGING_CHIP8
	mainLog.message = "--------------------INIT--------------------\n";
	mainLog.writeMessage();
	#endif
	int renderDivider = 0;
	int timerDivider = 0;
	controls mainControls;
	renderSDL renderer;
	registers cpu;
	display displayMain;
	stack stackMain;
	memory memoryMain;
	romStream romLoad;
	renderer.init(&displayMain);
	#ifdef LOGGING_CHIP8
	mainLog.message = "--------------------START--------------------\n";
	mainLog.writeMessage();
	#endif
	romLoad.filePath = "INVADERS";
	if(romLoad.checkFile() == false)
		return -1;
	romLoad.loadIntoMem(&memoryMain);
	#ifdef LOGGING_CHIP8
	mainLog.message = "So here is where it clunks\n";
	mainLog.writeMessage();
	#endif
	instructions instructMain(&displayMain, &stackMain, &cpu, &memoryMain, &mainControls);
	#ifdef LOGGING_CHIP8
	mainLog.message = "Seems like all went well. Entering loop of doom.\n";
	mainLog.writeMessage();
	#endif
	randomGen something;
	something.refresh();

	int x = 0;
	for(;;)
	{
		/*
		x++;
		if(x == 1000)
		{
			for(int b = 0; b < 32; b++)
			{
				for(int a = 0; a < 64; a++)
				{
					if((displayMain.buffer_64_32[a][b]) == 1)
					{
						std::cout << "X";
						#ifdef LOGGING_CHIP8
						mainLog.message += "X";
						#endif
					}
					else
					{
						std::cout << "-";
						#ifdef LOGGING_CHIP8
						mainLog.message += "-";
						#endif
					}
				}
				std::cout << std::endl;
				#ifdef LOGGING_CHIP8
				mainLog.message += "\n";
				#endif
			}
			#ifdef LOGGING_CHIP8
			mainLog.writeMessage();
			#endif
		}
		*/


		timerMain.resetTimer();
		instructMain.interpret();
		instructMain.replaceInstruct();
		timerDivider++;
		renderDivider++;
		if(timerDivider == 14)
		{
			timerDivider = 0;
			if(cpu.DT > 0)
				cpu.DT -= 1;
			if(cpu.ST > 0)
				cpu.ST -= 1;
		}
		if(renderDivider == 27)
			renderer.convertToSDL();
		else if(renderDivider == 28)
		{
			renderDivider = 0;
			renderer.draw();
		}
		mainControls.getKey();
		timerMain.loopRemainder();
	}


	/*
	unsigned char passthis[2] = {0xAA, 0x4A};
	instructions thi(&passthis[0], &displayMain, &stackMain, &cpu, &memoryMain);
	std::cout << std::hex <<(int)thi.op.lo << std::endl << std::hex << (int)thi.op.hi<< std::endl << std::hex << (int)thi.op.whole<< std::endl << std::hex << (int)(thi.op.whole >> 4)<< std::endl << std::hex << (int)(thi.op.whole & 0xF0);
	std::cin.get();
	 */
	//The stuff above won't work... instructions are no longer passed in they are simply taken from memory.

	return 0;
}

