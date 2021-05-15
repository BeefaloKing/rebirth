#include "sdlexcept.hh"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace rb {
Except::Except(const std::string &err) :
	message{err}
{}

const char* Except::what() const noexcept
{
	return message.c_str();
}

SDLExcept::SDLExcept(const std::string &err) :
	Except{err + ": " + SDL_GetError()}
{}

IMGExcept::IMGExcept(const std::string &err) :
	Except{err + ": " + IMG_GetError()}
{}
} // namespace rb
