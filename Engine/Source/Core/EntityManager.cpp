#include "EntityManager.h"

namespace brayjl {
	std::size_t EntityManager::createEntity() {
		m_currentEntityCount++;
		return m_currentEntityId++;
	}

	std::size_t EntityManager::getCurrentEntityCount() const {
		return m_currentEntityCount;
	}
}