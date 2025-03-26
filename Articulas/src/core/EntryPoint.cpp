#include <apch.h>

#include "Application.h"

extern Articulas::Application* Articulas::CreateApplication();

int main()
{
	auto app = Articulas::CreateApplication();

	app->run();
}