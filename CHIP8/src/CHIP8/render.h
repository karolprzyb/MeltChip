#ifndef INC_RENDER_CHIP8
#define INC_RENDER_CHIP8
#include "allInclude.h"
class renderSDL{
private:
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	int SCREEN_BPP;
	SDL_Surface *screen;
	SDL_Surface *bgLoad;
	SDL_Surface *bgOpt;
	SDL_Surface *keyPadLoad;
	SDL_Surface *keyPadOpt;
	SDL_Surface *pauseLoad;
	SDL_Surface *pauseOpt;
	SDL_Surface *resumeLoad;
	SDL_Surface *resumeOpt;
	SDL_Surface *bannerLoad;
	SDL_Surface *bannerOpt;
	SDL_Surface *borderLoad;
	SDL_Surface *borderOpt;
	SDL_Surface *chip8;
	SDL_Surface *chip8tmp;
	SDL_Surface *onLoad;
	SDL_Surface *onOpt;
	SDL_Surface *offLoad;
	SDL_Surface *offOpt;
	SDL_Rect pauseOffset;
	SDL_Rect resumeOffset;
	SDL_Rect bannerOffset;
	SDL_Rect keyPadOffset;
	SDL_Rect chip8Offset;
	SDL_Rect borderOffset;
	SDL_Rect pixelOffset;
	struct display *chip8Disp;
	Uint32 colorGreen;
	Uint32 colorBlack;
public:
	renderSDL();
	~renderSDL();
	void init(display *disp);
	void convertToSDL(void);
	void draw(void);
};
#endif
