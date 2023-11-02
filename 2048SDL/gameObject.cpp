#include "gameObject.hpp"
#include "SDL.h"
#include "SDL_Image.h"

GameObject::GameObject()
{
	srcR.x = 0;
	srcR.y = 0;
	srcR.w = 64;
	srcR.h = 64;

	destR.x = 0;
	destR.y = 0;
	destR.w = srcR.w * 2;
	destR.h = srcR.h * 2;
}

GameObject::~GameObject()
{
}


void GameObject::render()
{
	SDL_RenderCopy(Window::renderer, getTexture(), &srcR, &destR);

}
