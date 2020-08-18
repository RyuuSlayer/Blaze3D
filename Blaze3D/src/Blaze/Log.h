#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Blaze {

	class BLAZE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define BZ_CORE_TRACE(...)     ::Blaze::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BZ_CORE_INFO(...)      ::Blaze::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BZ_CORE_WARN(...)      ::Blaze::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BZ_CORE_ERROR(...)     ::Blaze::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BZ_CORE_FATAL(...)     ::Blaze::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define BZ_TRACE(...)          ::Blaze::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BZ_INFO(...)           ::Blaze::Log::GetClientLogger()->info(__VA_ARGS__)
#define BZ_WARN(...)           ::Blaze::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BZ_ERROR(...)          ::Blaze::Log::GetClientLogger()->error(__VA_ARGS__)
#define BZ_FATAL(...)          ::Blaze::Log::GetClientLogger()->fatal(__VA_ARGS__)