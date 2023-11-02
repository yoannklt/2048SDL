#include "textureManager.hpp"

#include <SDL.h>
#include <SDL_image.h>

#include "window.hpp"

std::map<std::string, SDL_Texture*> TextureManager::textures;

SDL_Texture* TextureManager::getTexture(const std::string& fileName)
{
	auto it = TextureManager::textures.find(fileName);
	if (it != TextureManager::textures.end())
	{
		return it->second;
	}

	SDL_Surface* tmpSur = IMG_Load(fileName.c_str());
	if (tmpSur == NULL) 
	{
		std::cout << "ERROR ";
		exit(1);
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(Window::renderer, tmpSur);
	SDL_FreeSurface(tmpSur);

	TextureManager::textures[fileName] = tex;

	return tex;
}