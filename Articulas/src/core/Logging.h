#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Articulas
{
	class Logging
	{
	public:

		void InitLoggers();
	};
}


#define ENGINE_LOG_TRACE(msg) spdlog::get("ENGINE")->trace(msg)
#define ENGINE_LOG_DEBUG(msg) spdlog::get("ENGINE")->debug(msg)
#define ENGINE_LOG_INFO(msg) spdlog::get("ENGINE")->info(msg)
#define ENGINE_LOG_WARN(msg) spdlog::get("ENGINE")->warn(msg)
#define ENGINE_LOG_ERROR(msg) spdlog::get("ENGINE")->error(msg)
#define ENGINE_LOG_CRTICAL(msg) spdlog::get("ENGINE")->critical(msg)

#define CONSOLE_LOG_TRACE(msg) spdlog::get("CONSOLE")->trace(msg)
#define CONSOLE_LOG_DEBUG(msg) spdlog::get("CONSOLE")->debug(msg)
#define CONSOLE_LOG_INFO(msg) spdlog::get("CONSOLE")->info(msg)
#define CONSOLE_LOG_WARN(msg) spdlog::get("CONSOLE")->warn(msg)
#define CONSOLE_LOG_ERROR(msg) spdlog::get("CONSOLE")->error(msg)
#define CONSOLE_LOG_CRTICAL(msg) spdlog::get("CONSOLE")->critical(msg)