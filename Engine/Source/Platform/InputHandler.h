#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "Window.h"

namespace brayjl {
	class InputHandler {
	public:
		static bool getKeyDown(const Window& window, const std::uint32_t& inputCode);
		static bool getKeyUp(const Window& window, const std::uint32_t& inputCode);
	};
}

#endif