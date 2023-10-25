#include "game.hpp"

SDL_Renderer* Game::renderer = nullptr;

Game::Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem Initialized !" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
			std::cout << "Window created!" << std::endl;

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
			std::cout << "Renderer Created" << std::endl;
		}

		isRunning = true;
	}
	else
		isRunning = false;
}

Game::~Game()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << std::endl << "Subsystems, Renderer and Window destroyed." << std::endl;
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_UP: 
			std::cout << "UP ARROW PRESSED" << std::endl;
			break;

		case SDLK_DOWN:
			std::cout << "DOWN ARROW PRESSED" << std::endl;
			break;

		case SDLK_LEFT:
			std::cout << "LEFT ARROW PRESSED" << std::endl;
			break;

		case SDLK_RIGHT:
			std::cout << "RIGHT ARROW PRESSED" << std::endl;
			break;
		}
		break;

	default:
		break;
	}
}

void Game::update()
{

}

void Game::render()
{
	SDL_RenderClear(renderer);

	// T'ajoutes les trucs que tu veux afficher là 


	SDL_RenderPresent(renderer);
}