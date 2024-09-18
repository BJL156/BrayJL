#include "ComponentManager.h"

namespace brayjl {
	void ComponentManager::removeAllComponents(const std::size_t& entityId) {
		auto& transform = getComponentUnorderedMap<TransformComponent>();
		auto& model = getComponentUnorderedMap<ModelComponent>();

		auto trans = transform.find(entityId);
		if (trans != transform.end()) {
			transform.erase(trans);
		}

		auto mod = model.find(entityId);
		if (mod != model.end()) {
			model.erase(mod);
		}
	}
}