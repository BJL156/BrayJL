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
	ImVec4 mainColor = ImVec4(0.1f, 0.1f, 0.1f, 1.0f);
	ImVec4 accentColor = ImVec4(0.0f, 0.4f, 0.5f, 1.0f);
	ImVec4 buttonColor = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);

	ImGuiStyle& style = ImGui::GetStyle();
	style.Colors[ImGuiCol_Text] = textColor;
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(textColor.x * 0.9f, textColor.y / 0.9f, textColor.z / 0.9f, 1.0f);
	style.Colors[ImGuiCol_WindowBg] = mainColor;
	style.Colors[ImGuiCol_ChildBg] = mainColor;
	style.Colors[ImGuiCol_PopupBg] = mainColor;
	style.Colors[ImGuiCol_Border] = mainColor;
	style.Colors[ImGuiCol_BorderShadow] = accentColor;
	style.Colors[ImGuiCol_FrameBg] = accentColor;
	style.Colors[ImGuiCol_FrameBgHovered] = accentColor;
	style.Colors[ImGuiCol_FrameBgActive] = accentColor;
	style.Colors[ImGuiCol_TitleBg] = accentColor;
	style.Colors[ImGuiCol_TitleBgActive] = accentColor;
	style.Colors[ImGuiCol_TitleBgCollapsed] = accentColor;
	style.Colors[ImGuiCol_MenuBarBg] = accentColor;
	style.Colors[ImGuiCol_ScrollbarBg] = mainColor;
	style.Colors[ImGuiCol_ScrollbarGrab] = accentColor;
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = accentColor;
	style.Colors[ImGuiCol_ScrollbarGrabActive] = accentColor;
	style.Colors[ImGuiCol_CheckMark] = mainColor;
	style.Colors[ImGuiCol_SliderGrab] = mainColor;
	style.Colors[ImGuiCol_SliderGrabActive] = mainColor;
	style.Colors[ImGuiCol_Button] = accentColor;
	style.Colors[ImGuiCol_ButtonHovered] = accentColor;
	style.Colors[ImGuiCol_ButtonActive] = accentColor;
	style.Colors[ImGuiCol_Header] = accentColor;
	style.Colors[ImGuiCol_HeaderHovered] = accentColor;
	style.Colors[ImGuiCol_HeaderActive] = accentColor;
	style.Colors[ImGuiCol_Separator] = accentColor;
	style.Colors[ImGuiCol_SeparatorHovered] = accentColor;
	style.Colors[ImGuiCol_SeparatorActive] = accentColor;
	style.Colors[ImGuiCol_ResizeGrip] = accentColor;
	style.Colors[ImGuiCol_ResizeGripHovered] = accentColor;
	style.Colors[ImGuiCol_ResizeGripActive] = accentColor;
	style.Colors[ImGuiCol_Tab] = accentColor;
	style.Colors[ImGuiCol_TabHovered] = accentColor;
	style.Colors[ImGuiCol_TabActive] = accentColor;
	style.Colors[ImGuiCol_TabUnfocused] = accentColor;
	style.Colors[ImGuiCol_TabUnfocusedActive] = accentColor;
	style.Colors[ImGuiCol_DockingPreview] = accentColor;
	style.Colors[ImGuiCol_DockingEmptyBg] = accentColor;
	style.Colors[ImGuiCol_PlotLines] = accentColor;
	style.Colors[ImGuiCol_PlotLinesHovered] = accentColor;
	style.Colors[ImGuiCol_PlotHistogram] = accentColor;
	style.Colors[ImGuiCol_PlotHistogramHovered] = accentColor;
	style.Colors[ImGuiCol_TableHeaderBg] = accentColor;
	style.Colors[ImGuiCol_TableBorderStrong] = accentColor;
	style.Colors[ImGuiCol_TableBorderLight] = accentColor;
	style.Colors[ImGuiCol_TableRowBg] = accentColor;
	style.Colors[ImGuiCol_TableRowBgAlt] = accentColor;
	style.Colors[ImGuiCol_TextSelectedBg] = accentColor;
	style.Colors[ImGuiCol_DragDropTarget] = accentColor;
	style.Colors[ImGuiCol_NavHighlight] = accentColor;
	style.Colors[ImGuiCol_NavWindowingHighlight] = accentColor;
	style.Colors[ImGuiCol_NavWindowingDimBg] = accentColor;
	style.Colors[ImGuiCol_ModalWindowDimBg] = accentColor;

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

		float borderThickness = 16.0f;
		ImGui::GetWindowDrawList()->AddRect(
			imagePosition,
			ImVec2(imagePosition.x + newWidth - borderThickness, imagePosition.y + newHeight - borderThickness),
			IM_COL32(accentColor.x * 255, accentColor.y * 255, accentColor.z * 255, 255),
			0.0f,
			0,
			borderThickness
		);

		ImGui::GetWindowDrawList()->AddImage(
			(void*)imguiFramebuffer.getTexture(),
			imagePosition,
			ImVec2(imagePosition.x + newWidth - borderThickness, imagePosition.y + newHeight - borderThickness),
			ImVec2(0.0f, 1.0f),
			ImVec2(1.0f, 0.0f)
		);
		ImGui::End();

		ImGui::Begin("Entity List");
		if (ImGui::Button("Add entity")) {
			std::size_t e = entityManager.createEntity();
			{
				auto transform = std::make_unique<brayjl::TransformComponent>();
				transform->position = { 0.0f, 0.0f, 0.0f };
				transform->scale = { 1.0f, 1.0f, 1.0f };
				componentManager.addComponent(e, std::move(transform));
				auto modelComponent = std::make_unique<brayjl::ModelComponent>();
				modelComponent->model = &ds1Model;
				componentManager.addComponent(e, std::move(modelComponent));
			}
		}

		if (ImGui::Button("Destroy entity")) {
			entityManager.destroyEntity(currentSelectedEntity);
		}

		for (std::size_t i = 0; i < entityManager.getCurrentEntityCount(); i++) {
			std::string buttonText = "Entity [" + std::to_string(i) + "]";
			
			bool selectedButton = currentSelectedEntity == i;

			if (selectedButton) {
				ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(accentColor.x * 0.9f, accentColor.y * 0.9f, accentColor.z * 0.9f, accentColor.z));
				ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(accentColor.x * 0.9f, accentColor.y * 0.9f, accentColor.z * 0.9f, accentColor.z));
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(accentColor.x * 0.9f, accentColor.y * 0.9f, accentColor.z * 0.9f, accentColor.z));
			}

			if (ImGui::Button(buttonText.c_str())) {
				currentSelectedEntity = i;
			}

			if (selectedButton) {
				ImGui::PopStyleColor(3);
			}
		}
		ImGui::End();

		ImGui::Begin("Properties");
		if (currentSelectedEntity != -1) {
			brayjl::TransformComponent* transform = componentManager.getComponent<brayjl::TransformComponent>(currentSelectedEntity);
			if (transform) {
				ImGui::SeparatorText("Transform Component");
				ImGui::Text("Position: (%.2f, %.2f, %.2f)", transform->position.x, transform->position.y, transform->position.z);
				ImGui::Text("Scale: (%.2f, %.2f, %.2f)", transform->scale.x, transform->scale.y, transform->scale.z);
			}

			brayjl::ModelComponent* model = componentManager.getComponent<brayjl::ModelComponent>(currentSelectedEntity);
			if (model) {
				ImGui::SeparatorText("Model Component");
				ImGui::Text("Name: %s", model->model->getFilepath().c_str());
			}
		}
		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
}