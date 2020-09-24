#pragma once

#include "Blaze/Core/Base.h"
#include "Blaze/Core/Log.h"
#include "Blaze/Scene/Scene.h"
#include "Blaze/Scene/Entity.h"

namespace Blaze {

	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& scene);

		void SetContext(const Ref<Scene>& scene);

		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};

}
