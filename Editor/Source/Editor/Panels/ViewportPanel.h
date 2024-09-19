#ifndef VIEWPORT_PANEL_H
#define VIEWPORT_PANEL_H

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include "Graphics/Framebuffer.h"
#include "Platform/Window.h"
#include "Editor/EditorInstance.h"

namespace editor {
	class ViewportPanel {
	public:
		static void draw(const brayjl::Window& window, brayjl::Framebuffer& framebuffer);
	};
}

#endif