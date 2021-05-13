#pragma once
#include <SDL2/SDL.h>

namespace rb {
class Client
{
private:
	SDL_Window* window;
	SDL_Surface* screen;
public:
	Client();
	~Client();

	// Placeholder for tutorial.
	void draw();
};
} // namespace rb
