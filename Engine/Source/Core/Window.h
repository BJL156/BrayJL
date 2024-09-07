#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "Logger.h"
#include "Utilities.h"

#include <cstdint>
#include <string>

namespace brayjl {
	class Window {
	public:
		Window(const std::uint32_t& width, const std::uint32_t& height, const std::string& name);
		~Window();

		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

		void update();

		bool shouldClose() const;
	private:
		void createGlfwWindow();
		void initializeGlad();
		void enableGLFeatures();

		static void framebufferResizeCallback(GLFWwindow* window, int width, int height);

		std::uint32_t m_width;
		std::uint32_t m_height;
		std::string m_name;
		GLFWwindow* m_window;
	};
}

#endif