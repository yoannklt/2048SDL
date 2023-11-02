#pragma once
#include "window.hpp"


class GameObject
{
public:
	GameObject();
	~GameObject();

	void createTexture(const char* fileName);
	void render();

private:
	SDL_Rect srcR, destR;
	SDL_Texture* tex;
};