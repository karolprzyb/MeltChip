#ifndef INC_FILEIO_CHIP8
#define INC_FILEIO_CHIP8
#include "allInclude.h"
struct romStream{
	std::string filePath;
	romStream();
	bool checkFile();
	void loadIntoMem(memory *memMain);
};
#endif
