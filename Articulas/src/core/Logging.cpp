#include <apch.h>
#include "Logging.h"

namespace Articulas
{
	void Logging::InitLoggers()
	{
		auto ENGINE = spdlog::stdout_color_mt("ENGINE");
		auto CONSOLE = spdlog::stdout_color_mt("CONSOLE");

		spdlog::set_level(spdlog::level::trace);
		spdlog::set_pattern("%^[%T] %n: %v%$");
		spdlog::get("ENGINE")->trace("INIT LOGGING");
		spdlog::get("CONSOLE")->trace("INIT LOGGING");
	}
}