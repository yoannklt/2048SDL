#include "gameObject.hpp"
#include "SDL.h"
#include "SDL_Image.h"

GameObject::GameObject()
{
	srcR.x = 0;
	srcR.y = 0;
	srcR.w = 128;
	srcR.h = 128;

	destR.x = 0;
	destR.y = 0;
	destR.w = srcR.w;
	destR.h = srcR.h;
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
