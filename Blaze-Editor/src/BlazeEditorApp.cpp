#include <Blaze.h>
#include <Blaze/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Blaze {

	class BlazeEditor : public Application
	{
	public:
		BlazeEditor()
		{
			PushLayer(new EditorLayer());
		}

		~BlazeEditor()
		{
		}
	};

	Application* CreateApplication()
	{
		return new BlazeEditor();
	}
}

