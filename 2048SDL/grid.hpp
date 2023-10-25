#include <iostream>
#include "game.hpp"

class Grid {
public:
	Grid();
	~Grid();

	void displayGrid();

private:
	int grid[4][4] = { 0 };
	bool lost = false;
};