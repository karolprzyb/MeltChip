#include "allInclude.h"

renderSDL::renderSDL()
{
	SCREEN_WIDTH = 1024;
	SCREEN_HEIGHT = 600;
	SCREEN_BPP = 32;
}

renderSDL::~renderSDL()
{

}

void renderSDL::init(display *disp)
{
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
	colorGreen = SDL_MapRGB( screen->format, 255, 0, 0 );
	colorBlack = SDL_MapRGB( screen->format, 0, 255, 0 );
	SDL_ShowCursor(SDL_DISABLE);

	chip8tmp = SDL_LoadBMP("chip8Placehold.bmp");
	borderLoad = SDL_LoadBMP("border.bmp");
	bgLoad = SDL_LoadBMP("bg.bmp");
	keyPadLoad = SDL_LoadBMP("keypad.bmp");
	pauseLoad = SDL_LoadBMP("pause.bmp");
	resumeLoad = SDL_LoadBMP("resume.bmp");
	bannerLoad = SDL_LoadBMP("banner.bmp");
	onLoad = SDL_LoadBMP("on.bmp");
	offLoad = SDL_LoadBMP("off.bmp");

	borderOpt = SDL_DisplayFormat(borderLoad);
	chip8 = SDL_DisplayFormat(chip8tmp);
	bgOpt = SDL_DisplayFormat(bgLoad);
	keyPadOpt = SDL_DisplayFormat(keyPadLoad);
	pauseOpt = SDL_DisplayFormat(pauseLoad);
	resumeOpt = SDL_DisplayFormat(resumeLoad);
	bannerOpt = SDL_DisplayFormat(bannerLoad);
	onOpt = SDL_DisplayFormat(onLoad);
	offOpt = SDL_DisplayFormat(offLoad);

	SDL_FreeSurface(borderLoad);
	SDL_FreeSurface(chip8tmp);
	SDL_FreeSurface(bgLoad);
	SDL_FreeSurface(pauseLoad);
	SDL_FreeSurface(resumeLoad);
	SDL_FreeSurface(bannerLoad);
	SDL_FreeSurface(keyPadLoad);
	SDL_FreeSurface(onLoad);
	SDL_FreeSurface(offLoad);

	pauseOffset.x = 0;
	pauseOffset.y = 152;
	resumeOffset.x = 128;
	resumeOffset.y = 152;
	bannerOffset.x = 256;
	bannerOffset.y = 0;
	keyPadOffset.x = 0;
	keyPadOffset.y = 344;
	chip8Offset.x = 256;
	chip8Offset.y = 152;
	borderOffset.x = 253;
	borderOffset.y = 149;

	SDL_BlitSurface(bgOpt, NULL, screen, NULL);
	//SDL_BlitSurface(pauseOpt, NULL, screen, &pauseOffset);
//	SDL_BlitSurface(resumeOpt, NULL, screen, &resumeOffset);
	SDL_BlitSurface(bannerOpt, NULL, screen, &bannerOffset);
	SDL_BlitSurface(keyPadOpt, NULL, screen, &keyPadOffset);
	SDL_BlitSurface(borderOpt, NULL, screen, &borderOffset);
	SDL_BlitSurface(chip8, NULL, screen, &chip8Offset);
	SDL_Flip(screen);

	chip8Disp = disp;
}

void renderSDL::convertToSDL()
{
	Uint32 *mem;
	for(int b = 0; b < 32; b++)
	{
		for(int a = 0; a < 64; a++)
		{
			//SDL_BlitSurface(chip8, NULL, screen, &chip8Offset);
			//SDL_Flip(screen);
			pixelOffset.x = a*12;
			pixelOffset.y = b*14;
			if((chip8Disp->buffer_64_32[a][b]) == 1)
			{
				SDL_BlitSurface(onOpt, NULL, chip8, &pixelOffset);
			}
			else
			{
				SDL_BlitSurface(offOpt, NULL, chip8, &pixelOffset);
			}
		}
	}
}

void renderSDL::draw()
{
	SDL_BlitSurface(chip8, NULL, screen, &chip8Offset);
	SDL_Flip(screen);
}
