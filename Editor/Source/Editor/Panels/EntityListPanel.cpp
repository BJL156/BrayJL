#include "EntityListPanel.h"

namespace editor {
	int EntityListPanel::m_currentSelectedEntity = -1;

	void EntityListPanel::draw(brayjl::EntityManager& entityManager, brayjl::ComponentManager& componentManager) {
		ImGui::Begin("Entity List");
		if (ImGui::Button("Add entity")) {
			std::size_t e = entityManager.createEntity();
			{
				auto transform = std::make_unique<brayjl::TransformComponent>();
				transform->position = { 0.0f, 0.0f, 0.0f };
				transform->scale = { 1.0f, 1.0f, 1.0f };
				componentManager.addComponent(e, std::move(transform));
				/*auto modelComponent = std::make_unique<brayjl::ModelComponent>();
				modelComponent->model = &ds1Model;
				componentManager.addComponent(e, std::move(modelComponent));*/
			}
		}

		if (ImGui::Button("Destroy entity")) {
			entityManager.destroyEntity(m_currentSelectedEntity);
		}

		for (std::size_t i = 0; i < entityManager.getCurrentEntityCount(); i++) {
			std::string buttonText = "Entity [" + std::to_string(i) + "]";

			bool selectedButton = m_currentSelectedEntity == i;

			if (selectedButton) {
				ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(editor::EditorInstance::getAccentColor().x * 0.9f, editor::EditorInstance::getAccentColor().y * 0.9f, editor::EditorInstance::getAccentColor().z * 0.9f, editor::EditorInstance::getAccentColor().z));
				ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(editor::EditorInstance::getAccentColor().x * 0.9f, editor::EditorInstance::getAccentColor().y * 0.9f, editor::EditorInstance::getAccentColor().z * 0.9f, editor::EditorInstance::getAccentColor().z));
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(editor::EditorInstance::getAccentColor().x * 0.9f, editor::EditorInstance::getAccentColor().y * 0.9f, editor::EditorInstance::getAccentColor().z * 0.9f, editor::EditorInstance::getAccentColor().z));
			}

			if (ImGui::Button(buttonText.c_str())) {
				m_currentSelectedEntity = i;
			}

			if (selectedButton) {
				ImGui::PopStyleColor(3);
			}
		}
		ImGui::End();
	}

	int EntityListPanel::getCurrentSelectedEntity() {
		return m_currentSelectedEntity;
	}
}