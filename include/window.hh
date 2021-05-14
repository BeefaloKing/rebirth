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

	// Returns the screen's pixel format as it is needed elsewhere.
	// I'd rather avoid exposing the surface itself though if I can avoid it.
	const SDL_PixelFormat* getScreenFormat() const;

	// Fills entire window surface with blank color.
	void clear();
	// Draws a sprite at the given destination in screen coordinates.
	void draw(const Sprite &sprite, SDL_Rect* dRect);
	// Presents screen surface.
	void update();
};
} // namespace rb
