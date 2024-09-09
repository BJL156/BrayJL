#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <glm/glm.hpp>

#include "Window.h"

namespace brayjl {
	class InputHandler {
	public:
		static void initialize(Window& window);

		static bool isKeyDown(std::uint32_t code);
		static bool isKeyUp(std::uint32_t code);
		static bool isKeyPressed(std::uint32_t code);

		static bool isMouseButtonDown(std::uint32_t code);
		static bool isMouseButtonUp(std::uint32_t code);
		static bool isMouseButtonPressed(std::uint32_t code);

		static glm::vec2 getCursorPosition();

		static void setScrollOffsetX(double offset);
		static void setScrollOffsetY(double offset);
		static glm::vec2 getScrollOffset();

		static void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);
	private:
		static bool m_keys[GLFW_KEY_LAST];
		static bool m_mouseButtons[GLFW_MOUSE_BUTTON_LAST];

		static double m_scrollOffsetX;
		static double m_scrollOffsetY;

		static Window* m_window;
	};
}

#endif