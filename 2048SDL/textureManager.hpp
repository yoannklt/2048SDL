#pragma once

#include <iostream>
#include <vector>
#include "window.hpp"

class SDL_Texture;

class TextureManager {

public:

	std::vector<SDL_Texture*> textures;

	static SDL_Texture* loadTexture(const char* fileName);

private:

};