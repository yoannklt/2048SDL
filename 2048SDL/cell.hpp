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
	void render() override;

private:
	int value = 0;
	bool merge = false;
};