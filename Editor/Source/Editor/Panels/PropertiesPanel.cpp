#include "PropertiesPanel.h"

namespace editor {
	void PropertiesPanel::draw(const int& currentSelectedEntity, brayjl::ComponentManager& componentManager) {
		ImGui::Begin("Properties");
		if (currentSelectedEntity != -1) {
			brayjl::TransformComponent* transform = componentManager.getComponent<brayjl::TransformComponent>(currentSelectedEntity);
			if (transform) {
				ImGui::SeparatorText("Transform Component");

				ImGui::Text("Position");
				ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
				ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
				if (ImGui::Button("X##0")) {
					transform->position.x = 0;
				}
				ImGui::PopStyleColor(3);
				ImGui::SameLine();
				ImGui::SetNextItemWidth(50.0f);
				ImGui::DragFloat("##PositionX", &transform->position.x, 0.1f);
				ImGui::SameLine();

				ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 1.0f, 0.0f, 1.0f));
				ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 1.0f, 0.0f, 1.0f));
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 1.0f, 0.0f, 1.0f));
				if (ImGui::Button("Y##0")) {
					transform->position.y = 0;
				}
				ImGui::PopStyleColor(3);
				ImGui::SameLine();
				ImGui::SetNextItemWidth(50.0f);
				ImGui::DragFloat("##PositionY", &transform->position.y, 0.1f);
				ImGui::SameLine();

				ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 1.0f, 1.0f));
				ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 0.0f, 1.0f, 1.0f));
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 0.0f, 1.0f, 1.0f));
				if (ImGui::Button("Z##0")) {
					transform->position.z = 0;
				}
				ImGui::PopStyleColor(3);
				ImGui::SameLine();
				ImGui::SetNextItemWidth(50.0f);
				ImGui::DragFloat("##PositionZ", &transform->position.z, 0.1f);

				ImGui::Text("Scale");
				ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
				ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
				if (ImGui::Button("X##1")) {
					transform->scale.x = 1.0f;
				}
				ImGui::PopStyleColor(3);
				ImGui::SameLine();
				ImGui::SetNextItemWidth(50.0f);
				ImGui::DragFloat("##ScaleX", &transform->scale.x, 0.1f);
				ImGui::SameLine();

				ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 1.0f, 0.0f, 1.0f));
				ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 1.0f, 0.0f, 1.0f));
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 1.0f, 0.0f, 1.0f));
				if (ImGui::Button("Y##1")) {
					transform->scale.y = 1.0f;
				}
				ImGui::PopStyleColor(3);
				ImGui::SameLine();
				ImGui::SetNextItemWidth(50.0f);
				ImGui::DragFloat("##ScaleY", &transform->scale.y, 0.1f);
				ImGui::SameLine();

				ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 1.0f, 1.0f));
				ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 0.0f, 1.0f, 1.0f));
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 0.0f, 1.0f, 1.0f));
				if (ImGui::Button("Z##1")) {
					transform->scale.z = 1.0f;
				}
				ImGui::PopStyleColor(3);
				ImGui::SameLine();
				ImGui::SetNextItemWidth(50.0f);
				ImGui::DragFloat("##ScaleZ", &transform->scale.z, 0.1f);
			}

			brayjl::ModelComponent* model = componentManager.getComponent<brayjl::ModelComponent>(currentSelectedEntity);
			if (model) {
				ImGui::SeparatorText("Model Component");
				ImGui::Text("Name: %s", model->model->getFilepath().c_str());
			}
		}
		ImGui::End();
	}
}