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
	io.Fonts->AddFontFromFileTTF("Resources/Fonts/Lato/Lato-Bold.ttf", 20.0f);

	ImVec4 textColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	ImVec4 headerColors = ImVec4(0.025f, 0.025f, 0.025f, 1.0f);
	ImVec4 windowColor = ImVec4(0.05f, 0.05f, 0.05f, 1.0f);
	ImVec4 buttonColor = ImVec4(0.1f, 0.1f, 0.1f, 1.0f);

	ImGuiStyle& style = ImGui::GetStyle();
	style.Colors[ImGuiCol_Text] = textColor;
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(textColor.x / 0.1f, textColor.y / 0.1f, textColor.z / 0.1f, 1.0f);
	style.Colors[ImGuiCol_WindowBg] = windowColor;

	style.Colors[ImGuiCol_TitleBg] = headerColors;
	style.Colors[ImGuiCol_TitleBgActive] = headerColors;
	style.Colors[ImGuiCol_TitleBgCollapsed] = headerColors;
	style.Colors[ImGuiCol_Header] = headerColors;
	style.Colors[ImGuiCol_HeaderActive] = headerColors;
	style.Colors[ImGuiCol_HeaderHovered] = headerColors;
	style.Colors[ImGuiCol_MenuBarBg] = headerColors;
	style.Colors[ImGuiCol_ResizeGripActive] = headerColors;
	style.Colors[ImGuiCol_ResizeGripHovered] = headerColors;
	style.Colors[ImGuiCol_ResizeGrip] = headerColors;
	style.Colors[ImGuiCol_ChildBg] = headerColors;
	style.Colors[ImGuiCol_TabActive] = headerColors;
	style.Colors[ImGuiCol_TabHovered] = headerColors;
	style.Colors[ImGuiCol_TabUnfocused] = headerColors;
	style.Colors[ImGuiCol_TabUnfocusedActive] = headerColors;

	style.Colors[ImGuiCol_Button] = buttonColor;
	style.Colors[ImGuiCol_ButtonActive] = buttonColor;
	style.Colors[ImGuiCol_ButtonHovered] = buttonColor;
	style.Colors[ImGuiCol_CheckMark] = buttonColor;
	style.Colors[ImGuiCol_Tab] = buttonColor;
	style.Colors[ImGuiCol_SliderGrab] = buttonColor;
	style.Colors[ImGuiCol_SliderGrabActive] = buttonColor;
	style.Colors[ImGuiCol_FrameBg] = buttonColor;
	style.Colors[ImGuiCol_Border] = buttonColor;
	style.Colors[ImGuiCol_CheckMark] = buttonColor;
	style.Colors[ImGuiCol_FrameBgHovered] = buttonColor;
	style.Colors[ImGuiCol_FrameBgActive] = buttonColor;

	style.WindowRounding = 4.0f;


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
		transform->position = { 1.0f, 1.0f, 1.0f };
		transform->scale = { 0.025f, 0.025f, 0.025f };
		componentManager.addComponent(e2, std::move(transform));
		auto modelComponent = std::make_unique<brayjl::ModelComponent>();
		modelComponent->model = &ds1Model;
		componentManager.addComponent(e2, std::move(modelComponent));
	}

	brayjl::Framebuffer framebuffer(m_window);
	brayjl::Framebuffer imguiFramebuffer(m_window);

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

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

		ImGui::Begin("Viewport");
		ImVec2 pos = ImGui::GetCursorScreenPos();

		ImVec2 imguiWindowSize = ImGui::GetWindowSize();
		float aspectRatio = static_cast<float>(m_window.getWidth()) / m_window.getHeight();

		float newWidth;
		float newHeight;
		if (imguiWindowSize.x / imguiWindowSize.y > aspectRatio) {
			newHeight = imguiWindowSize.y;
			newWidth = imguiWindowSize.y * aspectRatio;
		}
		else {
			newWidth = imguiWindowSize.x;
			newHeight = imguiWindowSize.x / aspectRatio;
		}

		ImVec2 cursorPosition = ImGui::GetCursorScreenPos();
		ImVec2 imagePosition = ImVec2(
			cursorPosition.x + (imguiWindowSize.x - newWidth) * 0.5f,
			cursorPosition.y + (imguiWindowSize.y - newHeight) * 0.5f
		);

		ImGui::GetWindowDrawList()->AddImage(
			(void*)imguiFramebuffer.getTexture(),
			imagePosition,
			ImVec2(imagePosition.x + newWidth, imagePosition.y + newHeight),
			ImVec2(0, 1), ImVec2(1, 0));
		ImGui::End();

		ImGui::ShowDemoWindow();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
}