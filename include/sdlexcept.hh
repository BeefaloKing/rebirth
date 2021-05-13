#pragma once
#include <stdexcept>
#include <string>

namespace rb {
/* Represents problems raised by an SDL function call.
 * Calls SDL_GetError(), so you should not throw an SDLExcept unless an SDL function has failed.
 */
class SDLExcept : public std::exception
{
private:
	std::string message;
public:
	SDLExcept(const std::string &message);

	const char* what() const noexcept override;
};
} // namespace rb
