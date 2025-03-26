#pragma once

#include "core/Layers/Layer.h"

#include <apch.h>
#include "core/WindowHandler.h"

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

				WindowsHandler::AddWindow("Sandbox", 1280, 720);

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