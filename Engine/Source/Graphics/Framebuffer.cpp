#include "Framebuffer.h"

namespace brayjl {
	Framebuffer::Framebuffer(Window& window)
		: m_window(window) {
		createTexture();
		createRenderbuffer();
		createFramebuffer();
		createRenderData();
	}

	Framebuffer::~Framebuffer() {
		glDeleteBuffers(1, &m_vbo);
		glDeleteVertexArrays(1, &m_vao);
		glDeleteBuffers(1, &m_ebo);

		glDeleteTextures(1, &m_texture);
		glDeleteRenderbuffers(1, &m_renderbuffer);
		glDeleteFramebuffers(1, &m_framebuffer);
	}

	void Framebuffer::bind() {
		glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Framebuffer::unbind() {
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Framebuffer::draw() {
		if (m_currentWidth != m_window.getWidth() || m_currentHeight != m_window.getHeight()) {
			m_currentWidth = m_window.getWidth();
			m_currentHeight = m_window.getHeight();
			resize(m_currentWidth, m_currentHeight);

			glViewport(0, 0, m_currentWidth, m_currentHeight);
		}

		m_shader.use();

		glBindVertexArray(m_vao);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);

		glBindTexture(GL_TEXTURE_2D, m_texture);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindTexture(GL_TEXTURE_2D, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
		glBindVertexArray(m_vao);
	}

	void Framebuffer::resize(const std::uint32_t& width, const std::uint32_t& height) {
		glBindTexture(GL_TEXTURE_2D, m_texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
		glBindTexture(GL_TEXTURE_2D, 0);

		glBindRenderbuffer(GL_RENDERBUFFER, m_renderbuffer);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
	}

	unsigned int Framebuffer::getFramebuffer() const {
		return m_framebuffer;
	}

	unsigned int Framebuffer::getTexture() const {
		return m_texture;
	}

	unsigned int Framebuffer::getRenderbuffer() const {
		return m_renderbuffer;
	}

	void Framebuffer::createTexture() {
		glGenTextures(1, &m_texture);
		glBindTexture(GL_TEXTURE_2D, m_texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_currentWidth, m_currentHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Framebuffer::createRenderbuffer() {
		glGenRenderbuffers(1, &m_renderbuffer);
		glBindRenderbuffer(GL_RENDERBUFFER, m_renderbuffer);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, m_currentWidth, m_currentHeight);
	}

	void Framebuffer::createFramebuffer() {
		glGenFramebuffers(1, &m_framebuffer);
		glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer);

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_texture, 0);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_renderbuffer);

		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
			Logger::error("Framebuffer isn't complete.");
		}

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void Framebuffer::createRenderData() {
		const float vertices[] = {
			-1.0f, 1.0f,	0.0f, 1.0f,
			-1.0f, -1.0f,	0.0f, 0.0f,
			1.0f, -1.0f,	1.0f, 0.0f,
			1.0f, 1.0f,		1.0f, 1.0f
		};

		const int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		glGenBuffers(1, &m_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glGenVertexArrays(1, &m_vao);
		glBindVertexArray(m_vao);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glGenBuffers(1, &m_ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}