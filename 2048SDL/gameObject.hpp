#pragma once
#include "window.hpp"


class GameObject
{
public:
	GameObject();
	~GameObject();

	void render();

private:
	SDL_Rect srcR, destR;
};