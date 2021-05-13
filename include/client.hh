#pragma once
#include <SDL2/SDL.h>
#include "window.hh"

namespace rb {
class Client
{
private:
	Window window;
public:
	Client();

	// Placeholder for tutorial.
	void draw();
};
} // namespace rb
