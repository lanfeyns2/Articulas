#include "apch.h"
#include "SceneManager.h"

namespace Articulas
{
	Scene& SceneManager::LoadSceneFromFile(const char* path)
	{
		FileStreamer stream(path, 0);
		
		auto name = std::filesystem::path(path).stem();
		auto extension = std::filesystem::path(path).extension();
		
		if (extension.string() == ".ascn")
		{
			ENGINE_LOG_INFO("Is a Articulas scene file");
		}
		else
		{
			ENGINE_LOG_WARN("Not an Articulas scene file");
		
			return Scene();
		}
	}
	Scene& SceneManager::NewScene()
	{
		return Scene();
	}
	Scene& SceneManager::LoadScene(std::variant<uint64_t, const char*>)
	{
		return Scene();
	}
	Scene& SceneManager::SaveScene(std::variant<uint64_t, const char*>)
	{
		return Scene();
	}
	SceneManager& SceneManager::GetInstance()
	{
		static SceneManager* s_instance = new SceneManager();
		return *s_instance;
	}
	void SceneManager::Shutdown()
	{
		delete &GetInstance();
	}
}