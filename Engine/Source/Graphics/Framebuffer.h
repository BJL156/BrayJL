#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <glad/glad.h>

#include "Graphics/Shader.h"
#include "Platform/Window.h"

namespace brayjl {
	class Framebuffer {
	public:
		Framebuffer(Window& window);
		~Framebuffer();

		void bind();
		void unbind();

		void draw();

		void resize(const std::uint32_t& width, const std::uint32_t& height);
	private:
		void createTexture();
		void createRenderbuffer();
		void createFramebuffer();
		void createRenderData();

		Window& m_window;

		unsigned int m_framebuffer;
		unsigned int m_texture;
		unsigned int m_renderbuffer;

		unsigned int m_vbo;
		unsigned int m_vao;
		unsigned int m_ebo;

		std::uint32_t m_currentWidth = m_window.getWidth();
		std::uint32_t m_currentHeight = m_window.getHeight();

		Shader m_shader{ "Resources/Shaders/Framebuffer.vert", "Resources/Shaders/Framebuffer.frag" };
	};
}

#endif