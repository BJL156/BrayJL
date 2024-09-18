#include "EntityManager.h"

namespace brayjl {
	EntityManager::EntityManager(ComponentManager& componentManager)
		: m_componentManager(componentManager) {

	}

	std::size_t EntityManager::createEntity() {
		m_currentEntityCount++;

		if (!m_freedEntities.empty()) {
			std::size_t firstFreedEntityId = m_freedEntities.front();
			m_freedEntities.pop();

			return firstFreedEntityId;
		}

		return m_currentEntityId++;
	}

	void EntityManager::destroyEntity(const std::size_t& entity) {
		if (m_currentEntityCount < 1) {
			return;
		}

		m_currentEntityCount--;
		m_freedEntities.push(entity);

		m_componentManager.removeAllComponents(entity);
	}

	std::size_t EntityManager::getCurrentEntityCount() const {
		return m_currentEntityCount;
	}
}