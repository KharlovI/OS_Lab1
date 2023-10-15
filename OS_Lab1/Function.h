#pragma once
#include"Utility.h"
#include <chrono>
#include <iostream>
class Function
{
public:
	virtual Result Compute(int x, const std::atomic<bool>& flag);
	virtual void SetFunctionName();	
	void SetFaultLimit(int limit);
	Result GetResult();
protected:
	Result res;
	std::string name;
	int faultLimit = 0;
};

