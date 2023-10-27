#pragma once
#include "Function.h"
class Gx : public Function
{
public:
	Gx();
	Result Compute(float x, const std::atomic<bool>& flag) override;
	void SetFunctionName() override;
};

