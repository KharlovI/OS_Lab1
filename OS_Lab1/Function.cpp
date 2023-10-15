#include "Function.h"

Result Function::Compute(int x, const std::atomic<bool>& flag)
{
	// Empty function
	return Result();
}

void Function::SetFunctionName()
{
	name = "Unknown function";
}

Result Function::GetResult()
{
	return res;
}

void Function::SetFaultLimit(int limit)
{
	this->faultLimit = limit;
	this->res.SetLimit(limit);
}
