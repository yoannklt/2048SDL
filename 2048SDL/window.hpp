#include <iostream>
#include "SDL.h"

class Window
{
public:
	Window(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	~Window();
	
	static SDL_Renderer* renderer;

	bool isRunning = false;

private:
	SDL_Window* window;
};
