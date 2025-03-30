#pragma once

#include <apch.h>
#include "core/Layers/Layer.h"
#include "core/WindowHandler.h"
#include "utils/FileStreamer.h"

namespace Articulas
{
	namespace Layers
	{
		class GameLayer : public Layer
		{
		public:

			GameLayer(bool& running)
				: m_running(running)
			{

			}

			inline void OnAdded()
			{
				FileStreamer test("C:/Users/liams/OneDrive/Desktop/Applications/Test/dog.txt", 0);
				auto dog = test.Read(5,1);
				WindowsHandler::AddWindow("Sandbox", 1280, 720);
				spdlog::set_level(spdlog::level::debug);
				ENGINE_LOG_INFO(dog);
			}
			inline void OnDestroyed()
			{


			}

			inline void OnUpdate()
			{
				auto& window = WindowsHandler::GetWindow(0);

				if (!glfwWindowShouldClose(window.glwindow))
				{
					glfwPollEvents();
					glfwSwapBuffers(window.glwindow);
				}
				else
				{
					m_running = false;
				}
			}

			inline void OnEvent()
			{

			}

		private:
			bool& m_running;
		};
	}
}