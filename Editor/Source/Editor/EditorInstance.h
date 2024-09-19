#ifndef EDITOR_INSTANCE_H
#define EDITOR_INSTANCE_H

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include "Platform/Window.h"

namespace editor {
	class EditorInstance {
	public:
		static void initialize(const brayjl::Window& window);
		static void update();
		static void render();
	
		static ImVec4 getTextColor();
		static ImVec4 getMainColor();
		static ImVec4 getAccentColor();
		static ImVec4 getButtonColor();
	private:
		static const ImVec4 m_textColor;
		static const ImVec4 m_mainColor;
		static const ImVec4 m_accentColor;
		static const ImVec4 m_buttonColor;
	};
}

#endif