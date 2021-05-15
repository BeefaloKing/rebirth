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
	SDL_Renderer* renderer = nullptr;
public:
	Window() = delete;
	// Parameters passed through to `SDL_CreateWindow()`.
	Window(const std::string &title, int x, int y, int w, int h, uint32_t windowFlags,
		uint32_t rendererFlags);
	~Window();

	// Returns the renderer created from the window as it is needed elsewhere.
	// Maybe this is a sign that Window shouldn't own the renderer.
	SDL_Renderer* getRenderer();

	// Fills entire window surface with blank color.
	void clear();
	// Draws a sprite at the given destination in screen coordinates.
	void draw(const Sprite &sprite, SDL_Rect* dRect);
	// Presents screen surface.
	void update();
};
} // namespace rb
