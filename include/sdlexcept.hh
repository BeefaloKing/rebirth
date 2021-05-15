#pragma once
#include <stdexcept>
#include <string>

namespace rb {
/* Base exception with a message returned by `what()`.
 */
class Except : public std::exception
{
protected:
	std::string message;

	Except() = delete;
	Except(const std::string &err);
public:
	const char* what() const noexcept override;
};

/* Represents problems raised by an SDL function call.
 * Calls SDL_GetError(), so you should not throw an SDLExcept unless an SDL function has failed.
 */
class SDLExcept : public Except
{
public:
	SDLExcept(const std::string &err);
};

/* Represents problems raised by an SDL_image function call.
 * Calls IMG_GetError(), so you should not throw an IMGExcept unless an IMG function has failed.
 */
class IMGExcept : public Except
{
public:
	IMGExcept(const std::string &err);
};
} // namespace rb
