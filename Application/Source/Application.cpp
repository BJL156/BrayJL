#include "Application.h"

void Application::run() {
	brayjl::InputHandler::initialize(m_window);

	brayjl::Shader shader{	"Resources/Shaders/Model.vert",
							"Resources/Shaders/Model.frag" };

	brayjl::Model ds1Model{ "Resources/Models/ds1/ds1.obj" };
	brayjl::Model tifaModel{ "Resources/Models/tifa/Tifa.obj" };

	Camera camera{};

	brayjl::EntityManager entityManager{};
	brayjl::ComponentManager componentManager{};
	brayjl::RenderSystem renderSystem(componentManager);

	std::size_t e1 = entityManager.createEntity();
	{
		auto transform = std::make_unique<brayjl::TransformComponent>();
		transform->position = { 0.0f, 0.0f, 0.0f };
		transform->scale = { 1.0f, 1.0f, 1.0f };
		componentManager.addComponent(e1, std::move(transform));
		auto modelComponent = std::make_unique<brayjl::ModelComponent>();
		modelComponent->model = &ds1Model;
		componentManager.addComponent(e1, std::move(modelComponent));
	}

	std::size_t e2 = entityManager.createEntity();
	{
		auto transform = std::make_unique<brayjl::TransformComponent>();
		transform->position = { 1.0f, 1.0f, -1.0f };
		transform->scale = { 0.025f, 0.025f, 0.025f };
		componentManager.addComponent(e2, std::move(transform));
		auto modelComponent = std::make_unique<brayjl::ModelComponent>();
		modelComponent->model = &tifaModel;
		componentManager.addComponent(e2, std::move(modelComponent));
	}

	while (!m_window.shouldClose()) {
		m_window.update();

		camera.update(m_window, m_window.getDeltaTime());

		glm::mat4 viewMatrix = camera.getViewMatrix();
		glm::mat4 projMatrix = glm::perspective(glm::radians(90.0f), static_cast<float>(m_window.getWidth()) / m_window.getHeight(), 0.1f, 1000.0f);

		shader.use();
		shader.setMat4("view", viewMatrix);
		shader.setMat4("proj", projMatrix);

		renderSystem.render(shader);
	}
}