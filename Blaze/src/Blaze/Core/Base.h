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

// TODO: Make this macro able to take in no arguments except condition
#ifdef BZ_ENABLE_ASSERTS
	#define BZ_ASSERT(x, ...) { if(!(x)) { BZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); BZ_DEBUGBREAK(); } }
	#define BZ_CORE_ASSERT(x, ...) { if(!(x)) { BZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); BZ_DEBUGBREAK(); } }
#else
	#define BZ_ASSERT(x, ...)
	#define BZ_CORE_ASSERT(x, ...)
#endif

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