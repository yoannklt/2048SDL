#include "grid.hpp"

#include <iostream>

#include "Cell.hpp"

Grid::Grid()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tab[i][j] = new Cell();  
		}
	}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (tab[i][j]->getValue() == 0)
				emptyCellGrid.push_back(tab[i][j]);


	srand(static_cast<unsigned>(time(0)));

	generateRandomCell();
	generateRandomCell();
}

int Grid::randomValue()
{
	int randomValue = (rand() % 2) == 0 ? 2 : 4; 
	return randomValue;
}

void Grid::generateRandomCell(/*int i = -1*/)
{
	int randomNumber = 0;
	if (emptyCellGrid.empty()) {
		this->lost = true;
		return;
	}

	// int randomNumber = i;
	if (randomNumber == -1)
		randomNumber = rand() % emptyCellGrid.size();

	emptyCellGrid[randomNumber]->setValue(randomValue());
	emptyCellGrid.erase(emptyCellGrid.begin() + randomNumber);
}

bool Grid::slide()
{
	bool doesMove = false;

	int iAdd = 0;
	if (directionVect[1] == -1) {
		iAdd = 3;
	}
	int yAdd = 0;
	if (directionVect[0] == -1) {
		yAdd = 3;
	}

	for (int row = 0; row < 4; row++) {

		for (int i = 3; i >= 0; i--) {

			int indexOne = row * (directionVect[0] * directionVect[0]) + directionVect[1] * i + iAdd;
			int indexTwo = row * (directionVect[1] * directionVect[1]) + directionVect[0] * i + yAdd;
			Cell** oCell1 = &tab[indexOne][indexTwo];
			int iValue1 = (*oCell1)->getValue();
			for (int iCompare = i - 1; iCompare >= 0; iCompare--)
			{
				int indexCompareOne = row * (directionVect[0] * directionVect[0]) + directionVect[1] * iCompare + iAdd;
				int indexCompareTwo = row * (directionVect[1] * directionVect[1]) + directionVect[0] * iCompare + yAdd;
				Cell** oCell2 = &tab[indexCompareOne][indexCompareTwo];
				int iValue2 = (*oCell2)->getValue();
				if (iValue2 == 0)
					continue;

				if (iValue1 == 0) {
					swapCell(oCell1, oCell2);
					i++;
					doesMove = true;
					break;
				}

				if (iValue1 == iValue2) {
					(*oCell1)->setValue(iValue1 + iValue2);
					(*oCell2)->setValue(0);
					emptyCellGrid.push_back(*oCell2);
					doesMove = true;
					break;
				}

				break;
			}
		}
	}
	directionVect[0] = 0;
	directionVect[1] = 0;
	return doesMove;
}

void Grid::setAnimation()
{
	int iMove = 0;
	int temp = 0;
	int iAdd = 0;
	int yAdd = 0;

	if (directionVect[1] == -1) {
		iAdd = 3;
	}
	if (directionVect[0] == -1) {
		yAdd = 3;
	}

	for (int row = 0; row < 4; row++) {

		for (int i = 3; i >= 0; i--) {

			int indexOne = row * (directionVect[0] * directionVect[0]) + directionVect[1] * i + iAdd;
			int indexTwo = row * (directionVect[1] * directionVect[1]) + directionVect[0] * i + yAdd;
			Cell* cell = tab[indexOne][indexTwo];

			if (cell->getValue() == 0) {
				iMove++;
			}
			else if (cell->getValue() == temp) {
				iMove++;
				cell->moveDist = iMove;
			}
			else {
				cell->moveDist = iMove;
			}
			temp = cell->getValue();
		}
	}
	animation();
}

void Grid::animation() {
	bool endAnim = false;
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	for (int k = 0; k < 60; k++) {

		int frameStart = SDL_GetTicks();

		for (int i = 0; i < 4; i++) {

			for (int j = 0; j < 4; j++) {

				if (tab[i][j]->moveDist != 0) {
					int x = tab[i][j]->getRect().x + ((directionVect[0] * tab[i][j]->moveDist) / FPS);
					int y = tab[i][j]->getRect().y + ((directionVect[1] * tab[i][j]->moveDist) / FPS);
					tab[i][j]->setRect(x, y);

					if (tab[i][j]->getValue() != 0)
						tab[i][j]->render();
				}
			}
		}

		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < frameDelay)
			SDL_Delay(frameDelay - frameTime);
	}
}

void Grid::render() {

	if (hasLost()) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tab[i][j]->setRect((128 + 10) * j + 5, (128 + 10) * i + 100);
			switch (tab[i][j]->getValue())
			{
			case 0:
				break;
			default:
				tab[i][j]->render();
				break;
			}
		}
	}
}

void Grid::swapCell(Cell** cell1, Cell** cell2)
{
	Cell* intermediateCell = *cell1;
	*cell1 = *cell2;
	*cell2 = intermediateCell;
}

void Grid::isDefeat()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			int tabIJ = tab[i][j]->getValue();
			int tabIJNext = tab[i][j + 1]->getValue();
			if (tabIJ == tabIJNext or tabIJ == 0)
				return;
		}
		if (tab[i][3]->getValue() == 0)
			return;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			int tabIJ = tab[j][i]->getValue();
			int tabIJNext = tab[j + 1][i]->getValue();
			if (tabIJ == tabIJNext)
				return;
		}
	}
	lost = true;
}
