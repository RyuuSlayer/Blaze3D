#pragma once

#include "Blaze/Core/Base.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Blaze {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define BZ_CORE_TRACE(...)     ::Blaze::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BZ_CORE_INFO(...)      ::Blaze::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BZ_CORE_WARN(...)      ::Blaze::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BZ_CORE_ERROR(...)     ::Blaze::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BZ_CORE_CRITICAL(...)     ::Blaze::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define BZ_TRACE(...)          ::Blaze::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BZ_INFO(...)           ::Blaze::Log::GetClientLogger()->info(__VA_ARGS__)
#define BZ_WARN(...)           ::Blaze::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BZ_ERROR(...)          ::Blaze::Log::GetClientLogger()->error(__VA_ARGS__)
#define BZ_CRITICAL(...)          ::Blaze::Log::GetClientLogger()->critical(__VA_ARGS__)