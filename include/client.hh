#pragma once
#include <SDL2/SDL.h>
#include "resource.hh"
#include "sprite.hh"
#include "window.hh"

namespace rb {
class Client
{
private:
	Window window;
	Resource rManager;
public:
	Client();

	// Placeholder for tutorial.
	void draw();
};
} // namespace rb
