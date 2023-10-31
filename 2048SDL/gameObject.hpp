#pragma once

#include "textureManager.hpp"

class GameObject
{
public:
	GameObject();
	~GameObject();

protected:

	SDL_Rect src;
	SDL_Rect dest;

};
