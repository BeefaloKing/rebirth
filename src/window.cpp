#include "window.hh"
#include "sdlexcept.hh"

namespace rb {
Window::Window(const std::string &title, int x, int y, int w, int h, uint32_t windowFlags,
	uint32_t rendererFlags)
{
	window = SDL_CreateWindow(title.c_str(), x, y, w, h, windowFlags);
	if (window == nullptr)
	{
		throw SDLExcept{"Unable to create window"};
	}

	renderer = SDL_CreateRenderer(window, -1, rendererFlags);
	if (renderer == nullptr)
	{
		throw SDLExcept{"Unable to create renderer"};
	}
}

Window::~Window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

SDL_Renderer* Window::getRenderer()
{
	return renderer;
}

void Window::clear()
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(renderer);
}

void Window::draw(const Sprite& sprite, SDL_Rect* dRect)
{
	sprite.draw(renderer, dRect);
}

void Window::update()
{
	SDL_RenderPresent(renderer);
}
} // namespace rb
