#include "window.hpp"
#include <string>


SDL_Renderer* Window::renderer = nullptr;

int Window::size = 0;

Window::Window(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	Window::size++;

	int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	TTF_Init();

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem Initialized !" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
			std::cout << "Window created!" << std::endl;

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 237.2, 235.7, 202.2, 255);
			std::cout << "Renderer Created" << std::endl;
		}

		loadFont();

		isRunning = true;
	}
	else
		isRunning = false;
}

Window::~Window()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << std::endl << "Subsystems, Renderer and Window destroyed." << std::endl;
}

SDL_Texture* Window::loadFont()
{  
	int fontsize = 24 * 2.5;
	SDL_Color text_color = { 0,0,0 };
	std::string fontpath = "fonts/RobotoFlex-Regular.ttf";
	std::string text = "2048";
	TTF_Font* font = TTF_OpenFont(fontpath.c_str(), fontsize);
	if (font == NULL)
		std::cout << TTF_GetError() << std::endl;

	SDL_Surface* text_surface = TTF_RenderText_Solid(font, text.c_str(), text_color);
	if (text_surface == NULL)
		std::cout << TTF_GetError() << std::endl;   
	this->ftexture = SDL_CreateTextureFromSurface(renderer, text_surface);
	if (ftexture == NULL)
		std::cout << TTF_GetError() << std::endl;
	SDL_FreeSurface(text_surface); 

	return this->ftexture;
}

void Window::drawScore()
{ 
	if (SDL_RenderCopy(renderer, ftexture, NULL, &dst) != 0) 
		std::cout << TTF_GetError() << std::endl;
}

void Window::handleEvents()
{
	if (grid.hasLost())
		isRunning = false;

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
			grid.setVect(0, -1);
			break;

		case SDLK_DOWN:
			grid.setVect(0, 1);
			break;

		case SDLK_LEFT:
			grid.setVect(-1, 0);
			break;

		case SDLK_RIGHT:
			grid.setVect(1, 0);
			break;
		}
		break;

	default:
		break;
	}
}

void Window::update()
{
	if (grid.hasLost()) {
		isRunning = false;
		std::cout << std::endl << "Perdu c'est CIAOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << std::endl;
	}

	if (!grid.vectEmpty())
	{
	    grid.setAnimation();
		if (grid.slide())
		{
			grid.generateRandomCell();
			grid.isDefeat();
		} 
	}
}

void Window::render()
{
	SDL_RenderClear(renderer);

	// T'ajoutes les trucs que tu veux afficher là 
	grid.render();
	drawScore();


	SDL_RenderPresent(renderer);
}