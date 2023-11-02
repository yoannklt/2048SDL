#pragma once

#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"
#include "grid.hpp"

class Window {

	Grid grid;

public:

	static int size;
	Window(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	~Window();

	SDL_Texture* loadFont();
	void drawScore();

	void handleEvents();
	void update();
	void render();

	bool running() { return isRunning; };

	static SDL_Renderer* renderer;


private:
	
	SDL_Texture* ftexture; // our font-texture

	int x = 210;
	int y = 10;
	int t_width = 150; // width of the loaded font-texture
	int t_height = 100; // height of the loaded font-texture
	SDL_Rect dst = { x, y, t_width, t_height };
	SDL_Window* window;
	bool isRunning = false; 
};