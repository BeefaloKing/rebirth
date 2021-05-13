#include "sprite.hh"
#include "sdlexcept.hh"

namespace rb {
Sprite::Sprite(const std::string &path) :
	image{SDL_LoadBMP(path.c_str())}
{
	if (image == nullptr)
	{
		throw SDLExcept{"Unable to load image at " + path};
	}
}

Sprite::~Sprite()
{
	SDL_FreeSurface(image);
}

SDL_Surface* Sprite::getImage() const
{
	return image;
}
} // namespace rb
