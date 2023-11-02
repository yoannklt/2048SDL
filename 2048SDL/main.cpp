#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "window.hpp"


int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	Window game = Window("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512 + 4*10, 532 + 80 + 4*10, false);


	while (game.running())
	{
		frameStart = SDL_GetTicks();

		game.handleEvents();
		game.update();
		game.render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < frameDelay)
			SDL_Delay(frameDelay - frameTime);
	}


	return 0;
}