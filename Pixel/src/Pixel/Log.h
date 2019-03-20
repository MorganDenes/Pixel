#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Pxl
{
	class PIXEL_API Log
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


#define PXL_CORE_TRACE(...)  ::Pxl::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PXL_CORE_INFO(...)   ::Pxl::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PXL_CORE_WARN(...)   ::Pxl::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PXL_CORE_ERROR(...)  ::Pxl::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PXL_CORE_CRITICAL(...)  ::Pxl::Log::GetCoreLogger()->critical(__VA_ARGS__)


#define PXL_TRACE(...)       ::Pxl::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PXL_INFO(...)        ::Pxl::Log::GetClientLogger()->info(__VA_ARGS__)
#define PXL_WARN(...)        ::Pxl::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PXL_ERROR(...)       ::Pxl::Log::GetClientLogger()->error(__VA_ARGS__)
#define PXL_CRITICAL(...)       ::Pxl::Log::GetClientLogger()->critical(__VA_ARGS__)
