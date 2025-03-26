#include <apch.h>
#include "Application.h"

namespace Articulas
{

	Application::Application()
	{

		Logging loggers;
		loggers.InitLoggers();
	}
	Application::~Application()
	{
		spdlog::get("ENGINE")->info("Destroyed");
	}
	void Application::run()
	{

		while (running)
		{
			EventHandler::DispatchEvents();
			Layerstack::RenderStack();
		}

		
	}
}