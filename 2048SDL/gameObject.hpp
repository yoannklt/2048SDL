#pragma once
#include "window.hpp"


class GameObject
{
public:
	GameObject();
	~GameObject();

	void createTexture(const char* fileName);
	void setRect(int x, int y);
	virtual void render();

protected:
	SDL_Rect srcR, destR;
};