#include "Fx.h"
#include <thread>

Fx::Fx()
{
}

Result Fx::Compute(float x, const std::atomic<bool>& flag)
{
	srand(time(0));
	if (int(x) % 5 == 0) {
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
	else if (int(x) % 2 == 0) {
		try {
			for (int i = 0; i < Constants::_timeSegmentsCount; i++) {
				std::this_thread::sleep_for(std::chrono::milliseconds(45));
				if (flag)
					return res;
			}
			for (int i = 0; i < faultLimit; i++) {
				if (rand() % 5 != 0) {
					this->res.IncrementErrorCount();
				}
			}
			if (res.ErrorLimitAchiened())
			{
				res.SetError(ERROR::Hard); 
				std::cout << "Soft Fault limit has been achived in f(" << x << ")\n";
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
	return res;
}

void Fx::SetFunctionName()
{
	name = "F(x)";
}
