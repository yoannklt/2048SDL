#include "cell.hpp"

Cell::Cell()
{
}

Cell::~Cell()
{
}

void Cell::draw()
{

	SDL_RenderCopy(Window::renderer, NULL, &src, &dest);
}