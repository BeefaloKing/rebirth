# pragma once
#include <SDL2/SDL.h>
#include <cstddef>
#include <string>
#include "sprite.hh"

namespace rb {
class Window
{
private:
	SDL_Window* window = nullptr;
	SDL_Surface* screen = nullptr;
public:
	Window() = delete;
	// Parameters passed through to `SDL_CreateWindow()`.
	Window(const std::string &title, int x, int y, int w, int h, uint32_t flags);
	~Window();

	// Fills entire window surface with blank color.
	void clear();
	// Copies sprite (to given screen coordinates).
	void blit(const Sprite &sprite);
	// Presents screen surface.
	void update();
};
} // namespace rb
