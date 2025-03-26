#include <apch.h>
#include "EventManager.h"

namespace Articulas
{
	namespace EventHandler
	{

		std::unordered_map<unsigned int, std::vector<std::function<void(Events::Event*&)>>> listeners;
		std::vector<Events::Event*> events;

		void AddListener(unsigned int listento, std::function<void(Events::Event*&)> func)
		{
			listeners[listento].emplace_back(func);
		}

		void AddToQueue(Events::Event* IEvent)
		{
			events.emplace_back(IEvent);
		}

		void DispatchEvents()
		{
			for (auto& IEvent : events)
			{
				for (auto& listener : listeners[IEvent->GetType()])
				{
					listener(IEvent);
				}

				events.erase(std::find(events.begin(), events.end(), IEvent));
			}
		}

	}
}