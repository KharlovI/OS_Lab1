#pragma once
#include <chrono>
#include <future>
#include <atomic>
class Timer
{
private:
	int limitInMillisec;
	std::atomic<bool> flag = false;
	std::chrono::time_point<std::chrono::system_clock> start;
public:
	Timer() {};
	Timer(int limit);
	bool Start();
	void Stop();

};

