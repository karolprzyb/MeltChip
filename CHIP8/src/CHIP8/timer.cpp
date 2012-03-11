#include "allInclude.h"

chipTimer::chipTimer()
{
	count = 0;
}

chipTimer::~chipTimer()
{

}

void chipTimer::setTimer(double msec)
{
	#ifdef LOGGING_CHIP8
	extern log mainLog;
	#endif
	waitMsec = msec;
	waitMsecU = (Uint32)waitMsec;
	fractionFixer();
}

void chipTimer::resetTimer(void)
{
	startMsec = SDL_GetTicks();
	endMsec = startMsec + waitMsecU;
	count++;
	if(count == countMany)
	{
		count = 0;
		endMsec += 1;
	}
}

void chipTimer::loopRemainder(void)
{
	#ifdef LOGGING_CHIP8
	extern log mainLog;
	#endif
	while(endMsec > SDL_GetTicks())
	{
	}
}

void chipTimer::sleepRemainder(void)
{
	/*
	#ifdef LOGGING_CHIP8
	extern log mainLog;
	#endif
	if(endMsec > SDL_GetTicks())
	{
		#ifdef LOGGING_CHIP8
		mainLog.message = "Not sleeping...";
		mainLog.writeMessage();
		#endif
		return;
	}
	remainMsec = SDL_GetTicks() - endMsec;
	if(remainMsec > waitMsec)
	{
		#ifdef LOGGING_CHIP8
		mainLog.message = "Not sleeping 2...";
		mainLog.writeMessage();
		#endif
		return;
	}
	timerspecSleep->tv_nsec = (remainMsec * 1000000) + (1000000000 / countMany); //Times 10^6 since thats how much more exact nanoseconds are than milliseconds.
	timerspecSleep->tv_sec = 0;
	if(nanosleep(timerspecSleep, timerspecSleep2) == 0)
	{
		#ifdef LOGGING_CHIP8
		mainLog.message = "Sleeping successful";
		mainLog.writeMessage();
		#endif
	}
	else
	{
		#ifdef LOGGING_CHIP8
		mainLog.message = "SLEEP ERROR!";
		mainLog.writeMessage();
		#endif
	}
	*/
}

void chipTimer::fractionFixer(void)
{
	#ifdef LOGGING_CHIP8
	extern log mainLog;
	#endif
	iMsec = waitMsec;
	aMsec = (waitMsec - (double)iMsec);
	iMsec = (aMsec * (double)1000);
	countMany = 1000/iMsec;
	#ifdef LOGGING_CHIP8
	//mainLog.message = "Counts determined " + countMany; //BUGGEED
	//mainLog.writeMessage();
	#endif
}

