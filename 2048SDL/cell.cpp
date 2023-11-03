#include "cell.hpp"
#include "textureManager.hpp"
#include <iostream>
#include <SDL.h>
#include <string>

Cell::Cell()
{
}

Cell::~Cell()
{
}

void Cell::setRect(int x, int y)
{
	this->destR.x = x;
	this->destR.y = y;
}

void Cell::render()
{
	std::string path = "img/" + std::to_string(value) + ".png";
	if (SDL_RenderCopy(Window::renderer, TextureManager::getTexture(path), &srcR, &destR) != 0)
		std::cout << SDL_GetError() << std::endl;
	
}


