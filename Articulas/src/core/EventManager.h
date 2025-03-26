#pragma once

#include <apch.h>

#include "Logging.h"

#include "Events/Event.h"

namespace Articulas
{
	namespace EventHandler
	{

		extern std::unordered_map<unsigned int, std::vector<std::function<void(Events::Event*&)>>> listeners;
		extern std::vector<Events::Event*> events;

		void AddListener(unsigned int listento, std::function<void(Events::Event*&)> func);
		void AddToQueue(Events::Event* IEvent);
		void DispatchEvents();
	}
}