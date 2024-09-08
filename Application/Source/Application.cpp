#include "Application.h"

void Application::run() {
	brayjl::Shader shader{	"Resources/Shaders/Model.vert",
							"Resources/Shaders/Model.frag"};

	brayjl::Model model{ "Resources/Models/ds1/ds1.obj" };

	while (!m_window.shouldClose()) {
		m_window.update();

		glm::mat4 modelMatrix = glm::mat4(1.0f);
		glm::mat4 viewMatrix = glm::mat4(1.0f);
		glm::mat4 projMatrix = glm::perspective(glm::radians(90.0f), static_cast<float>(m_window.getWidth()) / m_window.getHeight(), 0.1f, 1000.0f);

		shader.use();
		shader.setMat4("model", modelMatrix);
		shader.setMat4("view", viewMatrix);
		shader.setMat4("proj", projMatrix);

		model.draw(shader);
	}
}