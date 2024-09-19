#include "ViewportPanel.h"

namespace editor {
	void ViewportPanel::draw(const brayjl::Window& window, brayjl::Framebuffer& framebuffer) {
		ImGui::Begin("Viewport");
		ImVec2 pos = ImGui::GetCursorScreenPos();

		ImVec2 imguiWindowSize = ImGui::GetWindowSize();
		float aspectRatio = static_cast<float>(window.getWidth()) / window.getHeight();

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
			IM_COL32(EditorInstance::getAccentColor().x * 255, editor::EditorInstance::getAccentColor().y * 255, editor::EditorInstance::getAccentColor().z * 255, 255),
			0.0f,
			0,
			borderThickness
		);

		ImGui::GetWindowDrawList()->AddImage(
			(void*)framebuffer.getTexture(),
			imagePosition,
			ImVec2(imagePosition.x + newWidth - borderThickness, imagePosition.y + newHeight - borderThickness),
			ImVec2(0.0f, 1.0f),
			ImVec2(1.0f, 0.0f)
		);
		ImGui::End();
	}
}