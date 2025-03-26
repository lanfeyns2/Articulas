#pragma once

#include "../utils/Time.h"
#include "Logging.h"

namespace Articulas
{
	namespace Time
	{
		class Timer
		{
		public:
			Timer(const char* tag,bool trace);
			~Timer();
		public:
			
		private:
			std::chrono::system_clock::time_point m_startPoint;
			bool m_trace = true;
			const char* m_tag = "";
		};
	}
}