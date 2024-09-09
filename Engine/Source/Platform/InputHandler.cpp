#include "InputHandler.h"

namespace brayjl {
	bool InputHandler::m_keys[GLFW_KEY_LAST];
	bool InputHandler::m_mouseButtons[GLFW_MOUSE_BUTTON_LAST];

	double InputHandler::m_scrollOffsetX;
	double InputHandler::m_scrollOffsetY;

	Window* InputHandler::m_window = nullptr;

	void InputHandler::initialize(Window& window) {
		m_window = &window;

		for (std::size_t i = 0; i < GLFW_KEY_LAST; ++i) {
			m_keys[i] = false;
		}

		for (std::size_t i = 0; i < GLFW_MOUSE_BUTTON_LAST; ++i) {
			m_mouseButtons[i] = false;
		}

		glfwSetScrollCallback(window.getWindow(), scrollCallback);
	}

	bool InputHandler::isKeyDown(std::uint32_t code) {
		return glfwGetKey(m_window->getWindow(), code) == GLFW_PRESS;
	}

	bool InputHandler::isKeyUp(std::uint32_t code) {
		return glfwGetKey(m_window->getWindow(), code) == GLFW_RELEASE;
	}

	bool InputHandler::isKeyPressed(std::uint32_t code) {
		if (isKeyDown(code) && !m_keys[code]) {
			m_keys[code] = true;
			return true;
		}
		else if (isKeyUp(code)) {
			m_keys[code] = false;
		}

		return false;
	}

	bool InputHandler::isMouseButtonDown(std::uint32_t code) {
		return glfwGetMouseButton(m_window->getWindow(), code) == GLFW_PRESS;
	}

	bool InputHandler::isMouseButtonUp(std::uint32_t code) {
		return glfwGetMouseButton(m_window->getWindow(), code) == GLFW_RELEASE;
	}

	bool InputHandler::isMouseButtonPressed(std::uint32_t code) {
		if (isMouseButtonDown(code) && !m_mouseButtons[code]) {
			m_mouseButtons[code] = true;
			return true;
		}
		else if (isMouseButtonUp(code)) {
			m_mouseButtons[code] = false;
		}

		return false;
	}

	glm::vec2 InputHandler::getCursorPosition() {
		double xpos, ypos;
		glfwGetCursorPos(m_window->getWindow(), &xpos, &ypos);
		return { xpos, ypos };
	}

	void InputHandler::setScrollOffsetX(double offset) {
		m_scrollOffsetX = offset;
	}

	void InputHandler::setScrollOffsetY(double offset) {
		m_scrollOffsetY = offset;
	}

	glm::vec2 InputHandler::getScrollOffset() {
		return { m_scrollOffsetX, m_scrollOffsetY };
	}

	void InputHandler::scrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
		m_scrollOffsetX = xOffset;
		m_scrollOffsetY = yOffset;
	}
}