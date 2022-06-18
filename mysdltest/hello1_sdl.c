#include <stdio.h>
#include <SDL2/SDL.h>

int main(void)
{
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("error initializing SDL: %s\n", SDL_GetError());
		return 1;
	}
	printf("initialisation successful!\n");
	return 0;
	
	SDL_Quit();
}
