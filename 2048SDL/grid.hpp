#include <iostream>
#include "game.hpp"

class Grid {
public:
	Grid();
	~Grid();


private:
	int grid[4][4] = { 0 };
	bool lost = false;
};