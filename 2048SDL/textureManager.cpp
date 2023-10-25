#include "textureManager.hpp"

SDL_Texture* TextureManager::loadTexture(const char* texture)
{
	SDL_Surface* tmpSur = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSur);
	SDL_FreeSurface(tmpSur);

	return tex;
}

void TextureManager::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}
