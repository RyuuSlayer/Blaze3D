#include "bzpch.h"
#include "Blaze/Core/Input.h"

#ifdef BZ_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsInput.h"
#endif

namespace Blaze {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
#ifdef BZ_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
#else
		BZ_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}