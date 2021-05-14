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
	std::vector<SDL_Surface*> surfaces;
	std::unordered_map<std::string, Sprite*> sprites;

	// The native pixel format used by the screen surface.
	const SDL_PixelFormat* nativeFormat;

	// Loads image at `path` and returns a new Sprite object.
	Sprite* createSprite(const std::string &path);
public:
	Resource() = delete;
	Resource(const SDL_PixelFormat* screenFormat);
	~Resource();

	const Sprite &getSprite(const std::string &path);
};
} // namepace rb
