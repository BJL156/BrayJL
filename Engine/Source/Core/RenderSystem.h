#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "ComponentManager.h"
#include "Graphics/Shader.h"
#include "TransformComponent.h"
#include "ModelComponent.h"

namespace brayjl {
	class RenderSystem {
	public:
		RenderSystem(ComponentManager& componentManager);

		void render(Shader& shader);
	private:
		ComponentManager& m_componentManager;
	};
}

#endif