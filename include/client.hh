#pragma once
#include <SDL2/SDL.h>
#include "sprite.hh"
#include "window.hh"

namespace rb {
class Client
{
private:
	Window window;

	// Placeholder for tutorial.
	Sprite testimage;
public:
	Client();

	// Placeholder for tutorial.
	void draw();
};
} // namespace rb
