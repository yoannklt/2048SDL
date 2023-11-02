#pragma once

#include <map>
#include <string>

struct SDL_Texture;

class TextureManager {

public:
	static std::map<std::string, SDL_Texture*> textures;

	static SDL_Texture* getTexture(const std::string& fileName);

private:

};