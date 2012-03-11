#ifndef INC_TIMER_CHIP8
#define INC_TIMER_CHIP8
#include "allInclude.h"
class chipTimer{
private:
	timespec *timerspecSleep;
	timespec *timerspecSleep2;
	Uint32 startMsec;
	Uint32 endMsec;
	Uint32 waitMsecU;
	Uint32 remainMsec;
	long iMsec;
	double aMsec;
	double waitMsec;
	int count;
	int countMany;

	void fractionFixer(void);

public:
	chipTimer();
	~chipTimer();
	void setTimer(double msec);
	void resetTimer(void);
	void loopRemainder(void); //This doesn't actually sleep it loops and kills time for performance reasons and because posix is evil.
	void sleepRemainder(void); //Attempt to sleep natively...?
};
#endif
