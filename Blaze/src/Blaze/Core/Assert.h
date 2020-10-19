#pragma once

#include "Blaze/Core/Base.h"
#include "Blaze/Core/Log.h"
#include <filesystem>

#ifdef BZ_ENABLE_ASSERTS

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define BZ_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { BZ##type##ERROR(msg, __VA_ARGS__); BZ_DEBUGBREAK(); } }
	#define BZ_INTERNAL_ASSERT_WITH_MSG(type, check, ...) BZ_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define BZ_INTERNAL_ASSERT_NO_MSG(type, check) BZ_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", BZ_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define BZ_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define BZ_INTERNAL_ASSERT_GET_MACRO(...) BZ_EXPAND_MACRO( BZ_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, BZ_INTERNAL_ASSERT_WITH_MSG, BZ_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define BZ_ASSERT(...) BZ_EXPAND_MACRO( BZ_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define BZ_CORE_ASSERT(...) BZ_EXPAND_MACRO( BZ_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define BZ_ASSERT(...)
	#define BZ_CORE_ASSERT(...)
#endif
