#ifndef INC_CONTROLS_CHIP8
#define INC_CONTROLS_CHIP8
#include "allInclude.h"
class controls{
private:
	SDL_Event pressEvent;
public:
	char key[16];
	char button[5];

	controls(void);
	~controls(void);
	void getKey(void);
	void getButton(void);
	char stallPress(void);
};
#endif
