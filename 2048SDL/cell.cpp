#include "cell.hpp"

Cell::Cell()
{
}

Cell::~Cell()
{
}

void Cell::render()
{

	SDL_RenderCopy(Window::renderer, this->tex, &srcR, &destR);
}

