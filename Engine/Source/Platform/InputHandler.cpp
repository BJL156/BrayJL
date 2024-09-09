#include "InputHandler.h"

namespace brayjl {
	bool InputHandler::getKeyDown(const Window& window, const std::uint32_t& inputCode) {
		return glfwGetKey(window.getWindow(), inputCode) == GLFW_PRESS;
	}

	bool InputHandler::getKeyUp(const Window& window, const std::uint32_t& inputCode) {
		return glfwGetKey(window.getWindow(), inputCode) == GLFW_RELEASE;
	}
}