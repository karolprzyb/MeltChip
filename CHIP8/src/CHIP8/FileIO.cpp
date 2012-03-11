#include "allInclude.h"

romStream::romStream()
{
}

bool romStream::checkFile()
{
	#ifdef LOGGING_CHIP8
	extern log mainLog;
	#endif
	std::ifstream file;
	char filenamechars[0x200];
	strcpy(filenamechars, filePath.c_str());
	file.open(filenamechars);
	if (!file.is_open())
	{
		#ifdef LOGGING_CHIP8
		mainLog.message = "This ROM seems to not be opening... ITS LIKE ITS NOT THERE!!! :O\n";
		mainLog.writeMessage();
		#endif
		return false;
	}
	else
	{
		file.close();
		#ifdef LOGGING_CHIP8
		mainLog.message = "This ROM opens! :D\n";
		mainLog.writeMessage();
		#endif
		return true;
	}
}

void romStream::loadIntoMem(memory *memMain)
{
	#ifdef LOGGING_CHIP8
	extern log mainLog;
	#endif
	char filenamechars[0x200];
	strcpy(filenamechars, filePath.c_str());
	std::ifstream file;
	file.open(filenamechars, std::ios::in | std::ios::binary);
	file.seekg(0, ios::beg);
	int begin = file.tellg();
	file.seekg(0, ios::end);
	int end = file.tellg();
	int length = end-begin;
	file.seekg(0, ios::beg);
	if(length > 0xDFF)
	{
		#ifdef LOGGING_CHIP8
		mainLog.message = "TEH FILE IS TOOO BIG ABOOOORTT LOADINGGG!!!\n";
		mainLog.writeMessage();
		#endif
		return;
	}
	char readArray[0xDFF] = {0x00};
	for(int a = 0; a < 0xDFF; a++)
	{
		readArray[a] = 0;
	}
	file.read(readArray, length);
	#ifdef LOGGING_CHIP8
	if((file.fail() != 0))
	{
		mainLog.message = "FAILURE AHAHAHAHAHAAHHAHA GOTCHA (TEH ROM WONT REAAD!!!)\n";
		mainLog.writeMessage();
	}
	#endif
	for(int a = 0; a < 0xDFF; a++)
	{
		memMain->mem[a + 0x200] = readArray[a];
	}
	//THE ABOVE IS SUCH A HACCKKKKK... I wonder if just changing everything to a non unsigned char array would work... it probably would.
	file.close();
	//AHAHAHAAHAH GOT IT (this was when I learned to use extern :D
	#ifdef LOGGING_CHIP8
	mainLog.message = "ROM loaded!\n" + filePath + "\n";
	mainLog.writeMessage();
	#endif
}
