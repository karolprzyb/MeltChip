#ifdef LOGGING_CHIP8
#ifndef INC_LOG_CHIP8
#define INC_LOG_CHIP8
#include "allInclude.h"
struct log{
	private:
	std::string filePath;
	public:
	std::string message;
	log();
	void writeMessage();
	bool checkFile();
};
#endif
#endif
