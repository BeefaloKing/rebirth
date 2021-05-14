#include "client.hh"
#include <SDL2/SDL.h>
#include <stdexcept>
#include "sdlexcept.hh"

namespace rb {
Client::Client() :
	window{"Rebirth", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN},
	rManager{window.getScreenFormat()}
{}

void Client::loop()
{
	while (!quit)
	{
		handleInput();
		// Game logic should advance between these two.
		draw();
	}
}

void Client::handleInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0) // Events on queue.
	{
		switch (e.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			handleKeys(e);
			break;
		default:
			break;
		}
	}
}

void Client::handleKeys(SDL_Event &e)
{
	// Used to determine when associated actions should be registered/unregisted.
	bool down = e.key.state == SDL_PRESSED && e.key.repeat == 0;
	// bool held = e.key.state == SDL_PRESSED;
	// bool up = e.key.state == SDL_RELEASED;

	switch (e.key.keysym.sym)
	{
	case SDLK_ESCAPE:
		quit |= down;
		break;
	default:
		break;
	}
}

void Client::draw()
{
	window.clear();
	// In the future, some sort of "entity" should maintain a copy of the sprites it needs.
	// Manually asking the resource manager for sprites like this should not be done.
	window.draw(rManager.getSprite("assets/testimage.bmp"), nullptr);
	window.update();
}
} //namespace rb
