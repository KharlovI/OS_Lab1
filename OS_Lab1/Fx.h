#pragma once
#include"Function.h"
#include<atomic>
class Fx : public Function
{
public:
	Fx();
	Result Compute(int x, const std::atomic<bool>& flag) override;
	void SetFunctionName() override;
};

