#include "Manager.h"
#include <chrono>

Manager::Manager(int faultLimit, int timeLimit)
{
	this->timer = new Timer(timeLimit);
	this->g.SetFaultLimit(faultLimit);
	this->f.SetFaultLimit(faultLimit);
}

int Manager::Compute(int x)
{
	if (memory.ContainElement(x))
		return memory.GetOutput(x);
	std::future<bool> futureTimerStart = std::async(&Timer::Start, timer);
	std::atomic<bool> flag = ATOMIC_VAR_INIT(false);
	std::future<Result> future1 = std::async(&Fx::Compute, f,  x, std::ref(flag));
	std::future<Result> future2 = std::async(&Gx::Compute, g,  x, std::ref(flag));
	while((future1._Is_ready() == false && future2._Is_ready() == false) && (futureTimerStart._Is_ready() == false)) {
		
	}
	if (futureTimerStart._Is_ready()) {
		flag.exchange(true);
		std::cout << "Out of time\n";
		return -3;
	}
	timer->Stop();
	Result r1 = future1.get();
	Result r2 = future2.get();	

	if (r1.GetError() == ERROR::Hard) {
		std::cout << "Fatal fault in function f(" << x << ")\n";
		return -1;
	}
	if(r2.GetError() == ERROR::Hard) {
		std::cout << "Fatal fault in function g(" << x << ")\n";
		return -2;
	}
	std::cout << x << std::endl;
	if (r1.GetValue() > r2.GetValue()) {
		memory.AddPair(x, 1);
		return 1;
	}
	if (r1.GetValue() < r2.GetValue()) {
		memory.AddPair(x, 2);
		return 2;
	}
	memory.AddPair(x, 0);
	return 0;
}

Result Manager::GetTotalResult()
{
	return Result();
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
