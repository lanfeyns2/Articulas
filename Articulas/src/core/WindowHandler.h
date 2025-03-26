#pragma once
#include <apch.h>

#include "EventManager.h"

#include "Events/KeyDown.h"

namespace Articulas
{
	namespace WindowsHandler
	{

		struct Window
		{
			Window(const char* name,uint16_t width,uint16_t height);

			GLFWwindow* glwindow;
		};

		extern std::vector<Window> windows;

		const Window& GetWindow(size_t index);
		const Window& AddWindow(const char* name, uint16_t width, uint16_t height);
	}
}