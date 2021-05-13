#include "client.hh"
#include <SDL2/SDL.h>
#include <stdexcept>
#include "sdlexcept.hh"

namespace rb {
Client::Client() :
	window{"Rebirth", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN},
	testimage{"assets/testimage.bmp"}
{}

void Client::draw()
{
	window.clear();
	window.blit(testimage);
	window.update();
}
} //namespace rb
