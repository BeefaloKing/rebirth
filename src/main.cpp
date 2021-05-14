#include <SDL2/SDL.h>
#include <cstdio>
#include <stdexcept>
#include "client.hh"
#include "sdlexcept.hh"

int main(int argc, char* argv[])
{
	try
	{
		if (SDL_Init(SDL_INIT_VIDEO))
		{
			throw rb::SDLExcept{"Unable to initialize SDL"};
		}

		rb::Client client;
		client.loop();
	}
	catch (const std::exception &e)
	{
		printf("%s\n", e.what());
	}

	SDL_Quit();
	return 0;
}
