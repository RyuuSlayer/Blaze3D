#include "Application.h"

#include "Blaze/Events/ApplicationEvent.h"
#include "Blaze/Log.h"

namespace Blaze {

	Application::Application()
	{
	}
	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			BZ_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			BZ_TRACE(e);
		}

		while (true);
	}

}