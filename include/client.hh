#pragma once
#include <SDL2/SDL.h>
#include "resource.hh"
#include "sprite.hh"
#include "window.hh"

namespace rb {
class Client
{
private:
	Window window;
	Resource rManager;

	// Placeholder state variables for tutorial.
	bool quit = false;
public:
	Client();

	// Main loop. More or less a place holder. May evolve.
	void loop();
	// Event handling loop.
	void handleInput();
	void handleKeys(SDL_Event &e);
	// Placeholder for tutorial.
	void draw();
};
} // namespace rb
