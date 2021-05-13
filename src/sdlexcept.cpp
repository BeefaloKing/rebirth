#include "sdlexcept.hh"
#include <SDL2/SDL.h>

namespace rb {
SDLExcept::SDLExcept(const std::string &message) :
	message{message + ": " + SDL_GetError()}
{}

const char* SDLExcept::what() const noexcept
{
	return message.c_str();
}
}
