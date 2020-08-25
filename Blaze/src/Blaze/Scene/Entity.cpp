#include "bzpch.h"
#include "Entity.h"

namespace Blaze {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}