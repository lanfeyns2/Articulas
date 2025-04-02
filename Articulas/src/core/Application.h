#pragma once

#include <apch.h>

#include "Logging.h"
#include "Timer.h"

#include "LayerStack.h"
#include "EventManager.h"
#include "SceneManager.h"

#include "Events/KeyDown.h"

#include "WindowHandler.h"

namespace Articulas
{

	class Application
	{
	public:

		Application();

		~Application();

		void run();
	public:
		bool running = true;
	};

	Application* CreateApplication();
}

