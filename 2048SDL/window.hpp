#pragma once

#include <iostream>
#include "grid.hpp"

class SDL_Window;
class SDL_Renderer;

class Window {

	Grid grid;

public:

	Window(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	~Window();

	void handleEvents();
	void update();
	void render();

	bool running() { return isRunning; };

	static SDL_Renderer* renderer;

private:

	SDL_Window* window;
	bool isRunning = false;
};