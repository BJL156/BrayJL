#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <glm/glm.hpp>

#include "Window.h"
#include "InputCodes.h"

namespace brayjl {
	class InputHandler {
	public:
		static void initialize(Window& window);

		static bool isKeyDown(const Key& keyCode);
		static bool isKeyUp(const Key& keyCode);
		static bool isKeyPressed(const Key& keyCode);

		static bool isMouseButtonDown(const Mouse& mouseCode);
		static bool isMouseButtonUp(const Mouse& mouseCode);
		static bool isMouseButtonPressed(const Mouse& mouseCode);

		static glm::vec2 getCursorPosition();

		static void setScrollOffsetX(const double& offset);
		static void setScrollOffsetY(const double& offset);
		static glm::vec2 getScrollOffset();

		static void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);
	private:
		static bool m_keys[static_cast<int>(Key::LAST)];
		static bool m_mouseButtons[static_cast<int>(Mouse::LAST)];

		static double m_scrollOffsetX;
		static double m_scrollOffsetY;

		static Window* m_window;
	};
}

#endif