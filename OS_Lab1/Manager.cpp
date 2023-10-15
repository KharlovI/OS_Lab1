#include "Manager.h"
#include <chrono>

Result F(int x, int faultLimit) {
	Result result;
	std::cout << "F start"<< std::endl;
	if (x % 5 == 0) {
		try {
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			//float foo = 1 / 0;
		}
		catch (std::exception e) {
			return Result(0, ERROR::Hard);
		}
	}
	else if (x % 2 == 0) {
		try {
			std::this_thread::sleep_for(std::chrono::milliseconds(750));
			for (int i = 0; i < faultLimit; i++) {
				if (rand() % 3 != 0) {
					
				}
			}
		}
		catch (std::exception e) {
			return Result(0, ERROR::Hard);
		}
	}
	else {

	}
	std::cout << "F finish" << std::endl;
	return Result(15);
}

Result G(int x, int faultLimit) {
	std::cout << "G start" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "G finish" << std::endl;
	return Result(45);
}

void Manager::IncrementFaultCount()
{
	this->currentFaultCount++;
}

bool Manager::FaultLimitAchieved()
{
	return this->currentFaultCount == this->faultLimit;
}

Manager::Manager(int faultLimit, int timeLimit)
{
	this->timer = new Timer(timeLimit);
	this->faultLimit = faultLimit;
}

void Manager::Compute(int x)
{
	std::future<bool> futureTimerStart = std::async(&Timer::Start, timer);
	std::future<Result> future1 = std::async(F, x, faultLimit);
	std::future<Result> future2 = std::async(G, x, faultLimit);
	std::future<void> futureTimerStop = std::async(&Timer::Stop, timer);
	if (futureTimerStart.get() == false) {
		std::cout << "Out of time\n";
	}

	Result r1 = future1.get();
	Result r2 = future2.get();
	std::cout << "Result F: " << r1.GetValue() << "\nResult G: " << r2.GetValue() << "\n";
}

Result Manager::GetTotalResult()
{
	
	Result totalResult = Result(this->fx.GetValue() + this->gx.GetValue());
	return totalResult;
}

void Manager::Initialisation(int limit)
{
	//f.SetFaultsLimit(limit);
	//g.SetFaultsLimit(limit);
}

Manager::~Manager()
{
	delete timer;
}
