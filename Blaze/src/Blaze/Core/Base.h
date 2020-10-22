#pragma once

#include <memory>

#include "Blaze/Core/PlatformDetection.h"

#ifdef BZ_DEBUG
#if defined(BZ_PLATFORM_WINDOWS)
#define BZ_DEBUGBREAK() __debugbreak()
#elif defined(BZ_PLATFORM_LINUX)
#include <signal.h>
#define BZ_DEBUGBREAK() raise(SIGTRAP)
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define BZ_ENABLE_ASSERTS
#else
#define BZ_DEBUGBREAK()
#endif

#define BZ_EXPAND_MACRO(x) x
#define BZ_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define BZ_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Blaze {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "Blaze/Core/Log.h"
#include "Blaze/Core/Assert.h"
