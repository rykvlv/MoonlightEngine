#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace ML {
	class MOONLIGHT_API Log {
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		Log();
		~Log();
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define ML_CORE_TRACE(...)    ::ML::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ML_CORE_INFO(...)     ::ML::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ML_CORE_WARN(...)     ::ML::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ML_CORE_ERROR(...)    ::ML::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ML_CORE_FATAL(...)    ::ML::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define ML_TRACE(...)         ::ML::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ML_INFO(...)          ::ML::Log::GetClientLogger()->info(__VA_ARGS__)
#define ML_WARN(...)          ::ML::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ML_ERROR(...)         ::ML::Log::GetClientLogger()->error(__VA_ARGS__)
#define ML_FATAL(...)         ::ML::Log::GetClientLogger()->fatal(__VA_ARGS__)