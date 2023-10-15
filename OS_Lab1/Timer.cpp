#include "Timer.h"

Timer::Timer(int limit)
{
	limitInMillisec = limit;
}

bool Timer::Start()
{
	start = std::chrono::system_clock::now();
	while (!flag.load()) {
		if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() >= this->limitInMillisec)
			return false;
	}
	return true;
}

void Timer::Stop()
{
	flag.store(true);
}
