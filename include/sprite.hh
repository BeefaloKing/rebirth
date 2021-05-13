#pragma once
#include <SDL2/SDL.h>
#include <string>

namespace rb {
class Sprite
{
private:
	SDL_Surface* image = nullptr;
public:
	Sprite() = delete;
	Sprite(const std::string &path);
	~Sprite();

	SDL_Surface* getImage() const;
};
} // namespace rb
