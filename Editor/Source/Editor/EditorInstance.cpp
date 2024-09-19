#include "EditorInstance.h"

namespace editor {
	const ImVec4 EditorInstance::m_textColor = { 1.0f, 1.0f, 1.0f, 1.0f };
	const ImVec4 EditorInstance::m_mainColor = { 0.1f, 0.1f, 0.1f, 1.0f };
	const ImVec4 EditorInstance::m_accentColor = { 0.7f, 0.6f, 0.3f, 1.0f };
	const ImVec4 EditorInstance::m_buttonColor  = { 0.2f, 0.2f, 0.2f, 1.0f };

	void EditorInstance::initialize(const brayjl::Window& window) {
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		ImGui::StyleColorsDark();

		ImGui_ImplGlfw_InitForOpenGL(window.getWindow(), true);
		ImGui_ImplOpenGL3_Init("#version 460");

		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.Fonts->AddFontFromFileTTF("Resources/Fonts/Lato/Lato-Bold.ttf", 20.0f);

		ImGuiStyle& style = ImGui::GetStyle();
		style.Colors[ImGuiCol_Text] = m_textColor;
		style.Colors[ImGuiCol_TextDisabled] = ImVec4(m_textColor.x * 0.9f, m_textColor.y * 0.9f, m_textColor.z * 0.9f, 1.0f);
		style.Colors[ImGuiCol_WindowBg] = m_mainColor;
		style.Colors[ImGuiCol_ChildBg] = m_mainColor;
		style.Colors[ImGuiCol_PopupBg] = m_mainColor;
		style.Colors[ImGuiCol_Border] = m_mainColor;
		style.Colors[ImGuiCol_BorderShadow] = m_accentColor;
		style.Colors[ImGuiCol_FrameBg] = m_accentColor;
		style.Colors[ImGuiCol_FrameBgHovered] = m_accentColor;
		style.Colors[ImGuiCol_FrameBgActive] = m_accentColor;
		style.Colors[ImGuiCol_TitleBg] = m_accentColor;
		style.Colors[ImGuiCol_TitleBgActive] = m_accentColor;
		style.Colors[ImGuiCol_TitleBgCollapsed] = m_accentColor;
		style.Colors[ImGuiCol_MenuBarBg] = m_accentColor;
		style.Colors[ImGuiCol_ScrollbarBg] = m_mainColor;
		style.Colors[ImGuiCol_ScrollbarGrab] = m_accentColor;
		style.Colors[ImGuiCol_ScrollbarGrabHovered] = m_accentColor;
		style.Colors[ImGuiCol_ScrollbarGrabActive] = m_accentColor;
		style.Colors[ImGuiCol_CheckMark] = m_mainColor;
		style.Colors[ImGuiCol_SliderGrab] = m_mainColor;
		style.Colors[ImGuiCol_SliderGrabActive] = m_mainColor;
		style.Colors[ImGuiCol_Button] = m_accentColor;
		style.Colors[ImGuiCol_ButtonHovered] = m_accentColor;
		style.Colors[ImGuiCol_ButtonActive] = m_accentColor;
		style.Colors[ImGuiCol_Header] = m_accentColor;
		style.Colors[ImGuiCol_HeaderHovered] = m_accentColor;
		style.Colors[ImGuiCol_HeaderActive] = m_accentColor;
		style.Colors[ImGuiCol_Separator] = m_accentColor;
		style.Colors[ImGuiCol_SeparatorHovered] = m_accentColor;
		style.Colors[ImGuiCol_SeparatorActive] = m_accentColor;
		style.Colors[ImGuiCol_ResizeGrip] = m_accentColor;
		style.Colors[ImGuiCol_ResizeGripHovered] = m_accentColor;
		style.Colors[ImGuiCol_ResizeGripActive] = m_accentColor;
		style.Colors[ImGuiCol_Tab] = m_accentColor;
		style.Colors[ImGuiCol_TabHovered] = m_accentColor;
		style.Colors[ImGuiCol_TabActive] = m_accentColor;
		style.Colors[ImGuiCol_TabUnfocused] = m_accentColor;
		style.Colors[ImGuiCol_TabUnfocusedActive] = m_accentColor;
		style.Colors[ImGuiCol_DockingPreview] = ImVec4(m_accentColor.x * 0.9f, m_accentColor.y * 0.9f, m_accentColor.z * 0.9f, m_accentColor.w);
		style.Colors[ImGuiCol_DockingEmptyBg] = ImVec4(m_mainColor.x * 0.9f, m_mainColor.y * 0.9f, m_mainColor.z * 0.9f, m_mainColor.w);
		style.Colors[ImGuiCol_PlotLines] = m_accentColor;
		style.Colors[ImGuiCol_PlotLinesHovered] = m_accentColor;
		style.Colors[ImGuiCol_PlotHistogram] = m_accentColor;
		style.Colors[ImGuiCol_PlotHistogramHovered] = m_accentColor;
		style.Colors[ImGuiCol_TableHeaderBg] = m_accentColor;
		style.Colors[ImGuiCol_TableBorderStrong] = m_accentColor;
		style.Colors[ImGuiCol_TableBorderLight] = m_accentColor;
		style.Colors[ImGuiCol_TableRowBg] = m_accentColor;
		style.Colors[ImGuiCol_TableRowBgAlt] = m_accentColor;
		style.Colors[ImGuiCol_TextSelectedBg] = m_accentColor;
		style.Colors[ImGuiCol_DragDropTarget] = m_accentColor;
		style.Colors[ImGuiCol_NavHighlight] = m_accentColor;
		style.Colors[ImGuiCol_NavWindowingHighlight] = m_accentColor;
		style.Colors[ImGuiCol_NavWindowingDimBg] = m_accentColor;
		style.Colors[ImGuiCol_ModalWindowDimBg] = m_accentColor;

		style.WindowRounding = 4.0f;
	}

	void EditorInstance::update() {
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
	}

	void EditorInstance::render() {
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	ImVec4 EditorInstance::getTextColor() {
		return m_textColor;
	}

	ImVec4 EditorInstance::getMainColor() {
		return m_mainColor;
	}

	ImVec4 EditorInstance::getAccentColor() {
		return m_accentColor;
	}

	ImVec4 EditorInstance::getButtonColor() {
		return m_buttonColor;
	}
}