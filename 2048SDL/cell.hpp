#pragma once

#include <iostream>
#include <vector>
#include "gameObject.hpp"


class Cell : GameObject
{

public:
	Cell();
	~Cell();

	bool isMerge() { return merge; };
	void merged() { merge = true; };
	void resetMerge() { merge = false; };
	void setValue(int newValue) { value = newValue; };
	int getValue() { return value; };
	void setRect(int x, int y) override;
	SDL_Rect getRect() override { return destR; };
	void render() override;

	int moveDist = 0;

private:
	int value = 0;
	bool merge = false;
};