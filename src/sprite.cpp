#include "sprite.hh"
#include "sdlexcept.hh"

namespace rb {
Sprite::Sprite(SDL_Surface* image, SDL_Rect &origin) :
	image{image},
	origin{origin}
{}

void Sprite::blit(SDL_Surface* dest, SDL_Rect* dRect) const
{
	SDL_BlitSurface(image, &origin, dest, dRect);
}
} // namespace rb
