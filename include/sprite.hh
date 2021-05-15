#pragma once
#include <SDL2/SDL.h>
#include <string>

namespace rb {
class Sprite
{
private:
	SDL_Texture* texture = nullptr;
	SDL_Rect origin;
public:
	Sprite() = delete;
	Sprite(SDL_Texture* texture, SDL_Rect &origin);

	// Renders sprite at the given screen coordinates.
	void draw(SDL_Renderer* renderer, SDL_Rect* dRect) const;
};
} // namespace rb
