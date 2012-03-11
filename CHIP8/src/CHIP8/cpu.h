#ifndef INC_CPU_CHIP8
#define INC_CPU_CHIP8
#include "allInclude.h"
struct instructions{

	union instruct{
	unsigned short int whole;
	struct{
	unsigned char lo;
	unsigned char hi;
	};
	}op;
	randomGen randNum;
	struct registers *cpu;  // UHHHH for some reason VC 9.0 wouldnt compile without struct here. Bug somewhere? (2nd pc compiles it fine struct left for now)
	display *displayMain;	//WARNING so it seems like display was creating a new object since it was not in mains display and I think it has to do with the struct before
	memory *memoryMain;		//registers since it synced fine. I suspect memory and stack didn't sync. May be compiler bug.
	stack *stackMain;		//Perhaps adding struct would have fixes it but moving it below the object with struct prefixed fixed it. Cannot reproduce in current project.
	controls *mainControls;


	instructions();
	instructions(display *displayPassed, stack *stackPassed, registers *cpuPassed, memory *memoryMain, controls *contr);
	void interpret();
	void replaceInstruct();

};
#endif
