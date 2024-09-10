#include "InputHandler.h"

namespace brayjl {
	bool InputHandler::m_keys[static_cast<int>(Key::LAST)];
	bool InputHandler::m_mouseButtons[static_cast<int>(Mouse::LAST)];

	double InputHandler::m_scrollOffsetX;
	double InputHandler::m_scrollOffsetY;

	Window* InputHandler::m_window = nullptr;

	void InputHandler::initialize(Window& window) {
		m_window = &window;

		for (std::size_t i = 0; i < static_cast<int>(Key::LAST); ++i) {
			m_keys[i] = false;
		}

		for (std::size_t i = 0; i < static_cast<int>(Mouse::LAST); ++i) {
			m_mouseButtons[i] = false;
		}

		glfwSetScrollCallback(window.getWindow(), scrollCallback);
	}

	bool InputHandler::isKeyDown(const Key& keyCode) {
		return glfwGetKey(m_window->getWindow(), static_cast<int>(keyCode)) == GLFW_PRESS;
	}

	bool InputHandler::isKeyUp(const Key& keyCode) {
		return glfwGetKey(m_window->getWindow(), static_cast<int>(keyCode)) == GLFW_RELEASE;
	}

	bool InputHandler::isKeyPressed(const Key& keyCode) {
		if (isKeyDown(keyCode) && !m_keys[static_cast<int>(keyCode)]) {
			m_keys[static_cast<int>(keyCode)] = true;
			return true;
		}
		else if (isKeyUp(keyCode)) {
			m_keys[static_cast<int>(keyCode)] = false;
		}

		return false;
	}

	bool InputHandler::isMouseButtonDown(const Mouse& mouseCode) {
		return glfwGetMouseButton(m_window->getWindow(), static_cast<int>(mouseCode)) == GLFW_PRESS;
	}

	bool InputHandler::isMouseButtonUp(const Mouse& mouseCode) {
		return glfwGetMouseButton(m_window->getWindow(), static_cast<int>(mouseCode)) == GLFW_RELEASE;
	}

	bool InputHandler::isMouseButtonPressed(const Mouse& mouseCode) {
		if (isMouseButtonDown(mouseCode) && !m_mouseButtons[static_cast<int>(mouseCode)]) {
			m_mouseButtons[static_cast<int>(mouseCode)] = true;
			return true;
		}
		else if (isMouseButtonUp(mouseCode)) {
			m_mouseButtons[static_cast<int>(mouseCode)] = false;
		}

		return false;
	}

	glm::vec2 InputHandler::getCursorPosition() {
		double xpos, ypos;
		glfwGetCursorPos(m_window->getWindow(), &xpos, &ypos);
		return { xpos, ypos };
	}

	void InputHandler::setScrollOffsetX(const double& offset) {
		m_scrollOffsetX = offset;
	}

	void InputHandler::setScrollOffsetY(const double& offset) {
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