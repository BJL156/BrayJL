#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include <unordered_map>
#include <memory>

namespace brayjl {
	class ComponentManager {
	public:
		template<typename T>
		void addComponent(const std::size_t& entityId, std::unique_ptr<T> component);

		template<typename T>
		T* getComponent(const std::size_t& entityId);

		template<typename T>
		std::unordered_map<std::size_t, std::unique_ptr<T>>& getComponentUnorderedMap();
	};

	template<typename T>
	void ComponentManager::addComponent(const std::size_t& entityId, std::unique_ptr<T> component) {
		auto& componentUnorderedMap = getComponentUnorderedMap<T>();
		componentUnorderedMap[entityId] = std::move(component);
	}

	template<typename T>
	T* ComponentManager::getComponent(const std::size_t& entityId) {
		auto& componentUnorderedMap = getComponentUnorderedMap<T>();
		auto component = componentUnorderedMap.find(entityId);

		return component != componentUnorderedMap.end() ? component->second.get() : nullptr;
	}

	template<typename T>
	std::unordered_map<std::size_t, std::unique_ptr<T>>& ComponentManager::getComponentUnorderedMap() {
		static std::unordered_map<std::size_t, std::unique_ptr<T>> unorderedMap;

		return unorderedMap;
	}
}

#endif