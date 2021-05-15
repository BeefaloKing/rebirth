#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <unordered_map>
#include <vector>
#include "sprite.hh"

namespace rb {
class Resource
{
private:
	// For storing sprite atlases when we get there.
	std::vector<SDL_Texture*> textures;
	std::unordered_map<std::string, Sprite*> sprites;

	// Renderer used by the window.
	SDL_Renderer* renderer;

	// Loads image at `path` and returns a new Sprite object.
	Sprite* createSprite(const std::string &path);
public:
	Resource() = delete;
	Resource(SDL_Renderer* renderer);
	~Resource();

	const Sprite &getSprite(const std::string &path);
};
} // namepace rb
