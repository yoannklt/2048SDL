#include "textureManager.hpp"

#include "SDL.h"
#include "SDL_image.h"

SDL_Texture* TextureManager::loadTexture(const char* fileName)
{
	SDL_Surface* tmpSur = IMG_Load(fileName);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Window::renderer, tmpSur);
	SDL_FreeSurface(tmpSur);

	return tex;
}

