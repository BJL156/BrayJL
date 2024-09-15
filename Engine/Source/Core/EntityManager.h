#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <cstddef>

namespace brayjl {
	class EntityManager {
	public:
		EntityManager() = default;
		~EntityManager() = default;

		std::size_t createEntity();

		std::size_t getCurrentEntityCount() const;
	private:
		std::size_t m_currentEntityId = 0;
		std::size_t m_currentEntityCount = 0;
	};
}

#endif