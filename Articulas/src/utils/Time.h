#pragma once

#include <chrono>
#include <ctime>
#include <string>

namespace Articulas
{
	namespace Time
	{
		inline std::chrono::system_clock::time_point GetSystemTime()
		{
			auto currentTime = std::chrono::system_clock::now();

			return currentTime;
		};

		inline std::string GetClockTime(const char* format)
		{
			std::time_t currentTime = std::time(nullptr);

			// Convert time_t to tm structure for local time
			std::tm* localTime = std::localtime(&currentTime);

			char buffer[256];

			strftime(buffer, sizeof(buffer), format, localTime);

			return std::string(buffer);
		}

	}
}