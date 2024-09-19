#ifndef ENTITY_LIST_PANEL_H
#define ENTITY_LIST_PANEL_H

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include "ECS/EntityManager.h"
#include "ECS/ComponentManager.h"
#include "Editor/EditorInstance.h"

namespace editor {
	class EntityListPanel {
	public:
		static void draw(brayjl::EntityManager& entityManager, brayjl::ComponentManager& componentManager);

		static int getCurrentSelectedEntity();
	private:
		static int m_currentSelectedEntity;
	};
}

#endif