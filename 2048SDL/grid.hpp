#pragma once 

#include "cell.hpp"
#include <vector>

class Grid {
public:
	Grid();
	~Grid() {};

	int randomValue();
	void generateRandomCell(int i = -1);
	bool hasLost() { return lost; };
	bool slide();
	void setVect(int x, int y) { directionVect[0] = x; directionVect[1] = y; };
	bool vectEmpty() { if (directionVect[0] + directionVect[1] == 0) return true; return false; }

	void swapCell(Cell** cell1, Cell** cell2);

	void isDefeat();

private:
	bool lost = false;
	std::vector<Cell*> emptyCellGrid;
	int directionVect[2] = { 0, 0 };

protected:
	Cell* tab[4][4];

};