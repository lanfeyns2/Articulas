#pragma once

#include <apch.h>
#include <utils/FileStreamer.h>
#include "Scene.h"

namespace Articulas
{
	class SceneManager
	{
	public:

		Scene& LoadSceneFromFile(const char* path);
		Scene& NewScene();
		Scene& LoadScene(std::variant<uint64_t, const char*>);
		Scene& SaveScene(std::variant<uint64_t, const char*>);

		static SceneManager& GetInstance();
		void Shutdown();
	public:
		std::map<std::pair<uint64_t, const char*>, Scene> scenes;
		std::pair<uint64_t, const char*> currentScene;
	};
}