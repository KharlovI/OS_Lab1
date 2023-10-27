#pragma once
#include"Function.h"
#include<atomic>
class Fx : public Function
{
public:
	Fx();
	Result Compute(float x, const std::atomic<bool>& flag) override;
	void SetFunctionName() override;
};

