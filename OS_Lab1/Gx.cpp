#include "Gx.h"
#include <thread>

Gx::Gx()
{
}

Result Gx::Compute(int x, const std::atomic<bool>& flag)
{
	srand(time(0));
	std::cout << "G start" << std::endl;
	
	if (x % 7 == 0) {
		try {
			for (int i = 0; i < Constants::_timeSegmentsCount; i++) {
				std::this_thread::sleep_for(std::chrono::milliseconds(60));
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
				std::this_thread::sleep_for(std::chrono::milliseconds(30));
				if (flag)
					return res;
			}
			res.SetValue(x);
		}
		catch (std::exception e) {
			res = Result(0, ERROR::Hard);
		}
	}
	else {
		try {
			for (int i = 0; i < Constants::_timeSegmentsCount; i++) {
				std::this_thread::sleep_for(std::chrono::milliseconds(22));
				if (flag)
					return res;
			}
			if (rand() % 3 == 0) {
				for (int i = 0; i < faultLimit; i++) {
					if (rand() % 3 != 0) {
						this->res.IncrementErrorCount();
						std::cout << "Soft fault in g(x)\n";
					}
				}
			}
			if (res.ErrorLimitAchiened()) {
				res.SetError(ERROR::Hard);
				std::cout << "Soft Fault limit has been achived if g(x)\n";
			}
			else
				res.SetValue(x / 2);
		}
		catch (std::exception e) {
			res = Result(0, ERROR::Hard);
		}
	}

	std::cout << "G finish" << std::endl;
	return res;
}

void Gx::SetFunctionName()
{
	this->name = "G(x)";
}
