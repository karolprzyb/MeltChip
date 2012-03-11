#include "allInclude.h"

controls::controls(void)
{
	for(int count=0;count<16;count++)
		key[count] = 0;
	for(int count=0;count<5;count++)
		button[count] = 0;
}

controls::~controls(void)
{

}

void controls::getKey(void)
{
	for(int count = 0; count<5; count++)
	{
		SDL_PollEvent(&pressEvent);
		if(pressEvent.type == SDL_KEYDOWN)
		{
			switch(pressEvent.key.keysym.sym)
			{
			case SDLK_0:
				key[0] = 1;
				break;
			case SDLK_1:
				key[1] = 1;
				break;
			case SDLK_2:
				key[2] = 1;
				break;
			case SDLK_3:
				key[3] = 1;
				break;
			case SDLK_4:
				key[4] = 1;
				break;
			case SDLK_5:
				key[5] = 1;
				break;
			case SDLK_6:
				key[6] = 1;
				break;
			case SDLK_7:
				key[7] = 1;
				break;
			case SDLK_8:
				key[8] = 1;
				break;
			case SDLK_9:
				key[9] = 1;
				break;
			case SDLK_a:
				key[10] = 1;
				break;
			case SDLK_b:
				key[11] = 1;
				break;
			case SDLK_c:
				key[12] = 1;
				break;
			case SDLK_d:
				key[13] = 1;
				break;
			case SDLK_e:
				key[14] = 1;
				break;
			case SDLK_f:
				key[15] = 1;
				break;
			}
		}
		else if(pressEvent.type == SDL_KEYUP)
		{
			switch(pressEvent.key.keysym.sym)
			{
			case SDLK_0:
				key[0] = 0;
				break;
			case SDLK_1:
				key[1] = 0;
				break;
			case SDLK_2:
				key[2] = 0;
				break;
			case SDLK_3:
				key[3] = 0;
				break;
			case SDLK_4:
				key[4] = 0;
				break;
			case SDLK_5:
				key[5] = 0;
				break;
			case SDLK_6:
				key[6] = 0;
				break;
			case SDLK_7:
				key[7] = 0;
				break;
			case SDLK_8:
				key[8] = 0;
				break;
			case SDLK_9:
				key[9] = 0;
				break;
			case SDLK_a:
				key[10] = 0;
				break;
			case SDLK_b:
				key[11] = 0;
				break;
			case SDLK_c:
				key[12] = 0;
				break;
			case SDLK_d:
				key[13] = 0;
				break;
			case SDLK_e:
				key[14] = 0;
				break;
			case SDLK_f:
				key[15] = 0;
				break;
			}
		}
	}
}

void controls::getButton(void)
{
	for(int count = 0; count<5; count++)
	{
		SDL_PollEvent(&pressEvent);
		if(pressEvent.type == SDL_KEYDOWN)
		{
			switch(pressEvent.key.keysym.sym)
			{
			case SDLK_j:
				button[0] = 1;
				break;
			case SDLK_k:
				button[1] = 1;
				break;
			case SDLK_l:
				button[2] = 1;
				break;
			case SDLK_m:
				button[3] = 1;
				break;
			case SDLK_n:
				button[4] = 1;
				break;
			}
		}
		else if(pressEvent.type == SDL_KEYUP)
		{
			switch(pressEvent.key.keysym.sym)
			{
			case SDLK_j:
				button[0] = 0;
				break;
			case SDLK_k:
				button[1] = 0;
				break;
			case SDLK_l:
				button[2] = 0;
				break;
			case SDLK_m:
				button[3] = 0;
				break;
			case SDLK_n:
				button[4] = 0;
				break;
			}
		}
	}
}

char controls::stallPress(void)
{
	for(;;)
	{
		SDL_PollEvent(&pressEvent);
		std::cout << "looping"<< std::endl;
		if(pressEvent.type == SDL_KEYDOWN)
		{
			std::cout<<"yes";
			switch(pressEvent.key.keysym.sym)
			{
			case SDLK_0:
				return 0;
				break;
			case SDLK_1:
				return 1;
				break;
			case SDLK_2:
				return 2;
				break;
			case SDLK_3:
				return 3;
				break;
			case SDLK_4:
				return 4;
				break;
			case SDLK_5:
				return 5;
				break;
			case SDLK_6:
				return 6;
				break;
			case SDLK_7:
				return 7;
				break;
			case SDLK_8:
				return 8;
				break;
			case SDLK_9:
				return 9;
				break;
			case SDLK_a:
				return 10;
				break;
			case SDLK_b:
				return 11;
				break;
			case SDLK_c:
				return 12;
				break;
			case SDLK_d:
				return 13;
				break;
			case SDLK_e:
				return 14;
				break;
			case SDLK_f:
				return 15;
				break;
			}
		}
	}
}
