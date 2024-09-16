#include "RenderSystem.h"

namespace brayjl {
	RenderSystem::RenderSystem(ComponentManager& componentManager)
		: m_componentManager(componentManager) {

	}

	void RenderSystem::render(Shader& shader) {
		shader.use();

		for (auto& [entity, transform] : m_componentManager.getComponentUnorderedMap<TransformComponent>()) {
			auto modelComponent = m_componentManager.getComponent<ModelComponent>(entity);

			if (modelComponent && modelComponent->model) {
				glm::mat4 modelMatrix = glm::mat4(1.0f);
				modelMatrix = glm::translate(modelMatrix, transform->position);
				modelMatrix = glm::scale(modelMatrix, transform->scale);
				
				shader.setMat4("model", modelMatrix);

				modelComponent->model->draw(shader);
			}
		}
	}
}