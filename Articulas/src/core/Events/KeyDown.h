#pragma once

#include "Event.h"

namespace Articulas
{
	namespace Events
	{
		struct KeyDown : public Event
		{

			KeyDown(int action)
				: key(action)
			{
				
			}

			const int key;

			EventType GetType() override { return EventType::KEYDOWN; };
		};
	}
}