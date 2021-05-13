#include <SDL2/SDL.h>
#include <cstdio>
#include <stdexcept>
#include "client.hh"

int main(int argc, char* argv[])
{
	try
	{
		rb::Client client;
		client.draw();
		SDL_Delay(2000);
	}
	catch (const std::exception &e)
	{
		printf("Fatal unhandled exception caught.\n%s\n", e.what());
	}

	return 0;
}
