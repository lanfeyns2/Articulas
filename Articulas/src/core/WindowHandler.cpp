#include <apch.h>
#include "WindowHandler.h"



namespace Articulas
{
	namespace WindowsHandler
	{

		std::vector<Window> windows;

		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (action == GLFW_PRESS)
			{
				ENGINE_LOG_DEBUG("Got input");
				EventHandler::AddToQueue(new Events::KeyDown(key));
			}
		}

		Window::Window(const char* name, uint16_t width, uint16_t height)
		{

			glfwInit();

			glwindow = glfwCreateWindow(width, height, name, NULL, NULL);
			if (!glwindow)
			{
				ENGINE_LOG_INFO("Gayy");
			}

			glfwMakeContextCurrent(glwindow);
			glfwSetKeyCallback(glwindow, key_callback);
		}
		
		const Window& GetWindow(size_t index)
		{
			if (windows.size() < index)
			{
				ENGINE_LOG_ERROR("Could not find window at index: " + std::to_string(index));
			}
			else
			{
				ENGINE_LOG_TRACE("Got window at index: " + std::to_string(index));
				return windows[index];
			}
		}

		const Window& AddWindow(const char* name, uint16_t width, uint16_t height)
		{
			windows.emplace_back(name, width, height);
			return windows.back();
		}
	}
}
