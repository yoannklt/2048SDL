#pragma once
#include "window.hpp"


class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void setRect(int x, int y);
	virtual SDL_Rect getRect() { return destR; };
	virtual void render();

protected:
	SDL_Rect srcR, destR;
};