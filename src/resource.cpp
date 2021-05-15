#include <SDL2/SDL_image.h>
#include "resource.hh"
#include "sdlexcept.hh"

namespace rb {
Resource::Resource(SDL_Renderer* renderer) :
	renderer{renderer}
{}

Resource::~Resource()
{
	for (auto &[path, sprite] : sprites)
	{
		delete sprite;
	}

	for (SDL_Texture* texture : textures)
	{
		SDL_DestroyTexture(texture);
	}
}

Sprite* Resource::createSprite(const std::string &path)
{
	SDL_Surface* loaded = IMG_Load(path.c_str());
	if (loaded == nullptr)
	{
		throw IMGExcept{"Unable to load image at " + path};
	}

	SDL_Texture* converted = SDL_CreateTextureFromSurface(renderer, loaded);
	if (converted == nullptr)
	{
		throw SDLExcept{"Unable to create texture of image loaded from " + path};
	}

	SDL_Rect origin{
		.x = 0,
		.y = 0,
		.w = loaded->w,
		.h = loaded->h,
	};
	SDL_FreeSurface(loaded);

	textures.push_back(converted);
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
