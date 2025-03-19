#include "Application.h"

namespace Articulas
{
	Application::Application()
	{
		Logging loggers;
		loggers.InitLoggers();

		spdlog::set_level(spdlog::level::trace);
		spdlog::set_pattern("%^[%T] %n: %v%$");
		spdlog::get("ENGINE")->info("INIT LOGGING");
		spdlog::get("CONSOLE")->info("INIT LOGGING");

	}
	Application::~Application()
	{
		spdlog::get("ENGINE")->info("Destroyed");
	}
	void Application::run()
	{
		for (int i = 0; i < 10; i++)
		{
			Layerstack::RenderStack();
		}
	}
}