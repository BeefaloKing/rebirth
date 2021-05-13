#pragma once
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

	// Loads image at `path` and returns a new Sprite object.
	Sprite* createSprite(const std::string &path);
public:
	~Resource();

	const Sprite &getSprite(const std::string &path);
};
} // namepace rb
