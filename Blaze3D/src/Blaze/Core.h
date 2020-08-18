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