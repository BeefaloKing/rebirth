#include "resource.hh"
#include "sdlexcept.hh"

namespace rb {
Resource::~Resource()
{
	for (auto &[path, sprite] : sprites)
	{
		delete sprite;
	}

	for (SDL_Surface* surface : surfaces)
	{
		SDL_FreeSurface(surface);
	}
}

Sprite* Resource::createSprite(const std::string &path)
{
	SDL_Surface* surface = SDL_LoadBMP(path.c_str());
	if (surface == nullptr)
	{
		throw SDLExcept{"Unable to load image at " + path};
	}
	surfaces.push_back(surface);

	SDL_Rect origin{
		.x = 0,
		.y = 0,
		.w = surface->w,
		.h = surface->h,
	};
	return new Sprite{surface, origin};
}

const Sprite &Resource::getSprite(const std::string &path)
{
	if (sprites.count(path) == 0)
	{
		sprites.emplace(path, createSprite(path));
	}
	return *sprites[path];
}
} // namepace rb
