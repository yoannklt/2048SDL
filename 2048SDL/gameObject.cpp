#include "gameObject.hpp"
#include "SDL.h"
#include "SDL_Image.h"

GameObject::GameObject()
{
	srcR.x = 0;
	srcR.y = 0;
	srcR.w = 200;
	srcR.h = 200;

	destR.x = 0;
	destR.y = 0;
	destR.w = 128;
	destR.h = 128;
}

GameObject::~GameObject()
{
}


void GameObject::setRect(int x, int y)
{
}

void GameObject::render()
{
}
