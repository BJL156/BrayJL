#include "Application.h"

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

void Application::run() {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(m_window.getWindow(), true);
	ImGui_ImplOpenGL3_Init("#version 460");

	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

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

	brayjl::Framebuffer framebuffer(m_window);

	while (!m_window.shouldClose()) {
		m_window.update();

		camera.update(m_window, m_window.getDeltaTime());

		glm::mat4 viewMatrix = camera.getViewMatrix();
		glm::mat4 projMatrix = glm::perspective(glm::radians(camera.getFov()), static_cast<float>(m_window.getWidth()) / m_window.getHeight(), 0.1f, 1000.0f);

		shader.use();
		shader.setMat4("view", viewMatrix);
		shader.setMat4("proj", projMatrix);

		framebuffer.bind();
		renderSystem.render(shader);
		framebuffer.unbind();

		framebuffer.draw();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::ShowDemoWindow();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
}