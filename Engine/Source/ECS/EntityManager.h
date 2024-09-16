#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <cstddef>
#include <queue>

namespace brayjl {
	class EntityManager {
	public:
		EntityManager() = default;
		~EntityManager() = default;

		std::size_t createEntity();
		void destroyEntity(const std::size_t& entity);

		std::size_t getCurrentEntityCount() const;
	private:
		std::size_t m_currentEntityId = 0;
		std::size_t m_currentEntityCount = 0;

		std::queue<std::size_t> m_freedEntities;
	};
}

#endif