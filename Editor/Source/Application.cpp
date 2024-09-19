#include "Application.h"

void Application::run() {
	editor::EditorInstance::initialize(m_window);
	brayjl::InputHandler::initialize(m_window);

	brayjl::Shader shader{	"Resources/Shaders/Model.vert",
							"Resources/Shaders/Model.frag" };

	brayjl::Model ds1Model{ "Resources/Models/ds1/ds1.obj" };
	brayjl::Model tifaModel{ "Resources/Models/tifa/Tifa.obj" };

	Camera camera{};

	brayjl::ComponentManager componentManager{};
	brayjl::EntityManager entityManager(componentManager);
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

	std::size_t e3 = entityManager.createEntity();
	{
		auto transform = std::make_unique<brayjl::TransformComponent>();
		transform->position = { 0.0f, 0.0f, -3.0f };
		transform->scale = { 3.0f, 3.0f, 3.0f };
		componentManager.addComponent(e3, std::move(transform));
		auto modelComponent = std::make_unique<brayjl::ModelComponent>();
		modelComponent->model = &ds1Model;
		componentManager.addComponent(e3, std::move(modelComponent));
	}

	brayjl::Framebuffer framebuffer(m_window);
	brayjl::Framebuffer imguiFramebuffer(m_window);

	std::size_t currentSelectedEntity = -1;

	while (!m_window.shouldClose()) {
		m_window.update();

		camera.update(m_window, m_window.getDeltaTime());

		glm::mat4 viewMatrix = camera.getViewMatrix();
		glm::mat4 projMatrix = glm::perspective(glm::radians(camera.getFov()), static_cast<float>(m_window.getWidth()) / m_window.getHeight(), 0.01f, 1000.0f);

		shader.use();
		shader.setMat4("view", viewMatrix);
		shader.setMat4("proj", projMatrix);

		framebuffer.bind();
		renderSystem.render(shader);
		framebuffer.unbind();

		imguiFramebuffer.bind();
		framebuffer.draw();
		imguiFramebuffer.unbind();
		imguiFramebuffer.draw();

		editor::EditorInstance::update();
		editor::ViewportPanel::draw(m_window, imguiFramebuffer);
		editor::EntityListPanel::draw(entityManager, componentManager);
		editor::PropertiesPanel::draw(editor::EntityListPanel::getCurrentSelectedEntity(), componentManager);
		editor::EditorInstance::render();
	}
}