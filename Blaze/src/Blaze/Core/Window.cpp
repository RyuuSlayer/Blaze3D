#include "bzpch.h"
#include "Blaze/Core/Window.h"

#ifdef BZ_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Blaze
{

	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef BZ_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		BZ_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}