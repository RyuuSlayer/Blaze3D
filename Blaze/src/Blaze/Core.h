#pragma once

#ifdef BZ_PLATFORM_WINDOWS
	#ifdef BZ_BUILD_DLL
		#define BLAZE_API __declspec(dllexport)
	#else
		#define BLAZE_API __declspec(dllimport)
	#endif
#else
	#error Blaze only supports Windows!
#endif

#ifdef BZ_DEBUG
	#define BZ_ENABLE_ASSERTS
#endif

#ifdef BZ_ENABLE_ASSERTS
	#define BZ_ASSERT(x, ...) { if(!(x)) { BZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define BZ_CORE_ASSERT(x, ...) { if(!(x)) { BZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define BZ_ASSERT(x, ...)
	#define BZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define BZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)