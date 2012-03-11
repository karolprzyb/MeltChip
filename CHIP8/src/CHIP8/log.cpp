#include "allInclude.h"
#ifdef LOGGING_CHIP8
log::log()
{
	message = "";
	filePath = logPath;
}

void log::writeMessage()
{
	std::ofstream file;
	char filenamechars[0x200];
	strcpy(filenamechars, filePath.c_str());
	file.open(filenamechars, ios::out | ios::app);
	if (!file.is_open())
		return;                     //THROW AN ERROR TO SOMETHINGGGGGGG!!!!
	file << message.c_str();
	file.close();
	message = "";
}

bool log::checkFile()
{
	std::ofstream file;
	char filenamechars[0x200];
	strcpy(filenamechars, filePath.c_str());
	file.open(filenamechars);
	if (!file.is_open())
		return false;
	else
	{
		file.close();
		return true;
	}
}
#endif
