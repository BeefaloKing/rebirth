#include "window.hh"
#include "sdlexcept.hh"

namespace rb {
Window::Window(const std::string &title, int x, int y, int w, int h, uint32_t flags) :
	window{SDL_CreateWindow(title.c_str(), x, y, w, h, flags)}
{
	if (window == nullptr)
	{
		throw SDLExcept{"Unable to create window"};
	}
	screen = SDL_GetWindowSurface(window);
}

Window::~Window()
{
	SDL_DestroyWindow(window);
}

void Window::clear()
{
	SDL_FillRect(screen, nullptr, SDL_MapRGB(screen->format, 0xC0, 0xFF, 0xEE));
}

void Window::update()
{
	SDL_UpdateWindowSurface(window);
}
}
