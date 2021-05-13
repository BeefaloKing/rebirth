#include <SDL2/SDL.h>
#include <cstdio>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[])
{
	SDL_Window* window = nullptr;
	SDL_Surface* screen = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO))
	{
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow("Rebirth", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		printf("Unable to create window: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	screen = SDL_GetWindowSurface(window);
	SDL_FillRect(screen, nullptr, SDL_MapRGB(screen->format, 0xC0, 0xFF, 0xEE));
	SDL_UpdateWindowSurface(window);
	SDL_Delay(2000);

	return 0;
}
