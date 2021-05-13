#include "client.hh"
#include <SDL2/SDL.h>
#include <stdexcept>
#include "sdlexcept.hh"

namespace rb {
Client::Client()
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		throw SDLExcept{"Unable to initialize SDL"};
	}

	window = SDL_CreateWindow("Rebirth", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480,
		SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		SDL_Quit();
		throw SDLExcept{"Unable to create window"};
	}

	screen = SDL_GetWindowSurface(window);
}

Client::~Client()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Client::draw()
{
	SDL_FillRect(screen, nullptr, SDL_MapRGB(screen->format, 0xC0, 0xFF, 0xEE));
	SDL_UpdateWindowSurface(window);
}
} //namespace rb
