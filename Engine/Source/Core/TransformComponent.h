#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include <glm/glm.hpp>

namespace brayjl {
	struct TransformComponent {
		glm::vec3 position;
		glm::vec3 scale;
	};
}

#endif