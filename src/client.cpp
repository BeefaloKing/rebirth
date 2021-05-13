#include "client.hh"
#include <SDL2/SDL.h>
#include <stdexcept>
#include "sdlexcept.hh"

namespace rb {
Client::Client() :
	window{"Rebirth", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN}
{}

void Client::draw()
{
	window.clear();
	// In the future, some sort of "entity" shoul maintain a copy of the sprites it needs.
	// Manually asking the resource manager for sprites like this should not be done.
	window.draw(rManager.getSprite("assets/testimage.bmp"), nullptr);
	window.update();
}
} //namespace rb
