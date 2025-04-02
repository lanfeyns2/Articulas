#pragma once

#include <apch.h>
#include "core/Layers/Layer.h"
#include "core/WindowHandler.h"
#include "utils/FileStreamer.h"
#include "core/SceneManager.h"

namespace Articulas
{
	namespace Layers
	{
		class GameLayer : public Layer
		{
		public:

			GameLayer(bool& running)
				: m_running(running), mainWindow("Sandbox",1280,720)
			{

			}

			inline void OnAdded()
			{
				SceneManager::GetInstance().LoadSceneFromFile("C:/Users/liams/OneDrive/Desktop/Applications/Test/dog.ascn");
			}
			inline void OnDestroyed()
			{


			}

			inline void OnUpdate()
			{

				if (!glfwWindowShouldClose(mainWindow.glwindow))
				{
					glfwPollEvents();
					glfwSwapBuffers(mainWindow.glwindow);
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
		public:
			Articulas::WindowsHandler::Window mainWindow;
		};
	}
}