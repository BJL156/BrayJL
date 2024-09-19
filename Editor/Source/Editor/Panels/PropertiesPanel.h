#ifndef PROPERTIES_PANEL_H
#define PROPERTIES_PANEL_H

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include "ECS/EntityManager.h"
#include "ECS/ComponentManager.h"
#include "Editor/EditorInstance.h"

namespace editor {
	class PropertiesPanel {
	public:
		static void draw(const int& currentSelectedEntity, brayjl::ComponentManager& componentManager);
	};
}

#endif