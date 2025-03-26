#pragma once

namespace Articulas
{
	namespace Events
	{

		enum EventType
		{
			MOUSEMOVE,
			KEYDOWN
		};

		struct Event
		{

			virtual EventType GetType() = 0;

		};
	}
}