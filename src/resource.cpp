#include <SDL2/SDL_image.h>
#include "resource.hh"
#include "sdlexcept.hh"

namespace rb {
Resource::Resource(const SDL_PixelFormat* screenFormat) :
	nativeFormat{screenFormat}
{}

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
	SDL_Surface* loaded = IMG_Load(path.c_str());
	if (loaded == nullptr)
	{
		throw IMGExcept{"Unable to load image at " + path};
	}
	// "The flags are unused and should be set to 0".
	SDL_Surface* converted = SDL_ConvertSurface(loaded, nativeFormat, 0);
	if (converted == nullptr)
	{
		throw SDLExcept{"Unable to convert image loaded from " + path};
	}

	SDL_FreeSurface(loaded);
	surfaces.push_back(converted);

	SDL_Rect origin{
		.x = 0,
		.y = 0,
		.w = converted->w,
		.h = converted->h,
	};
	return new Sprite{converted, origin};
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
