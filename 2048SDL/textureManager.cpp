#include "textureManager.hpp"

SDL_Texture* TextureManager::loadTexture(const char* fileName)
{
	SDL_Surface* tmpSur = IMG_Load(fileName);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Window::renderer, tmpSur);
	SDL_FreeSurface(tmpSur);

	return tex;
}

void TextureManager::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Window::renderer, tex, &src, &dest);
}
