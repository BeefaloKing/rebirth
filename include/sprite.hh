#pragma once
#include <SDL2/SDL.h>
#include <string>

namespace rb {
class Sprite
{
private:
	SDL_Surface* image = nullptr;
	SDL_Rect origin;
public:
	Sprite() = delete;
	Sprite(SDL_Surface* image, SDL_Rect &origin);

	// Draws sprite to a given surface.
	void blit(SDL_Surface* dest, SDL_Rect* dRect) const;
};
} // namespace rb
