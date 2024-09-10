#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <cstddef>

namespace brayjl {
	class EntityManager {
	public:
		EntityManager() = default;
		~EntityManager() = default;

		std::size_t createEntity();
	private:
		std::size_t m_currentEntityId = 0;
	};
}

#endif