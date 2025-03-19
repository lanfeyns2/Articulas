#include "Logging.h"

namespace Articulas
{
	void Logging::InitLoggers()
	{
		auto ENGINE = spdlog::stdout_color_mt("ENGINE");
		auto CONSOLE = spdlog::stdout_color_mt("CONSOLE");
	}
}