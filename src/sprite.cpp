#include "sprite.hh"
#include "sdlexcept.hh"

namespace rb {
Sprite::Sprite(SDL_Texture* texture, SDL_Rect &origin) :
	texture{texture},
	origin{origin}
{}

void Sprite::draw(SDL_Renderer* renderer, SDL_Rect* dRect) const
{
	SDL_RenderCopy(renderer, texture, &origin, dRect);
}
} // namespace rb
