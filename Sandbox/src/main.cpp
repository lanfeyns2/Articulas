#include <Core/Application.h>
#include "Layers/GameLayer.h"

class Sandbox : public Articulas::Application
{
public:
	Sandbox()
	{
		Articulas::Layerstack::PushLayer(new Articulas::Layers::GameLayer(running));
	}

	~Sandbox()
	{

	}
};

Articulas::Application* Articulas::CreateApplication()
{
	return new Sandbox();
}