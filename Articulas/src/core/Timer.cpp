#include "apch.h"
#include "Timer.h"

namespace Articulas
{
	namespace Time
	{
		Timer::Timer(const char* tag,bool trace)
			: m_startPoint(Articulas::Time::GetSystemTime()), m_tag(tag),m_trace(trace)
		{

			ENGINE_LOG_INFO("TIMER MADE");

		}
		Timer::~Timer()
		{
			auto now = Articulas::Time::GetSystemTime();
			auto distance = now - m_startPoint;

			std::string timerMsg = "TIMER ENDED: ";

			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(distance);

			if (m_tag == "")
			{
				timerMsg = timerMsg + "took " + std::to_string(duration.count()) + " seconds";
			}
			else
			{
				timerMsg = timerMsg + m_tag + ": " + "took " + std::to_string(duration.count()) + " seconds";
			}

			if (m_trace == true)
			{

				ENGINE_LOG_TRACE(timerMsg);
			}
			else
			{
				ENGINE_LOG_DEBUG(timerMsg);
			}
		}
	}
}
