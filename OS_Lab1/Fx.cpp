#include "Fx.h"
#include <thread>

Fx::Fx()
{
}

Result Fx::Compute(int x, const std::atomic<bool>& flag)
{
	srand(time(0));
	std::cout << "F start" << std::endl;
	if (x % 5 == 0) {
		try {
			for (int i = 0; i < Constants::_timeSegmentsCount; i++) {
				std::this_thread::sleep_for(std::chrono::milliseconds(15));
				if (flag)
					return res;
			}
		}
		catch (std::exception e) {
			this->res = Result(0, ERROR::Hard);
		}
		res.SetError(ERROR::Hard);
	}
	else if (x % 2 == 0) {
		try {
			for (int i = 0; i < Constants::_timeSegmentsCount; i++) {
				std::this_thread::sleep_for(std::chrono::milliseconds(45));
				if (flag)
					return res;
			}
			for (int i = 0; i < faultLimit; i++) {
				if (rand() % 5 != 0) {
					this->res.IncrementErrorCount();
					std::cout << "Soft fault in f(x)\n";
				}
			}
			if (res.ErrorLimitAchiened())
			{
				res.SetError(ERROR::Hard); 
				std::cout << "Soft Fault limit has been achived if f(x)\n";
			}
			else
				res.SetValue(x / 2);
		}
		catch (std::exception e) {
			res = Result(0, ERROR::Hard);
		}
	}
	else {
		try {
			for (int i = 0; i < Constants::_timeSegmentsCount; i++) {
				std::this_thread::sleep_for(std::chrono::milliseconds(67));
				if (flag)
					return res;
			}
			res.SetValue(x);
		}
		catch (std::exception e) {
			res = Result(0, ERROR::Hard);
		}
	}
	std::cout << "F finish" << std::endl;
	return res;
}

void Fx::SetFunctionName()
{
	name = "F(x)";
}
