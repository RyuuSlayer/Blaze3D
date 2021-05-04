#include <Blaze.h>
#include <Blaze/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Blaze {

	class BlazeEditor : public Application
	{
	public:
		BlazeEditor(ApplicationCommandLineArgs args)
			: Application("BlazeEditor", args)
		{
			PushLayer(new EditorLayer());
		}

		~BlazeEditor()
		{
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new BlazeEditor(args);
	}
}
