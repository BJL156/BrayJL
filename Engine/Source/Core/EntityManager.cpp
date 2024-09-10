#include "EntityManager.h"

namespace brayjl {
	std::size_t EntityManager::createEntity() {
		return m_currentEntityId++;
	}
}