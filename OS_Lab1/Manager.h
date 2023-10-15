#pragma once
#include <future>
#include <iostream>
#include"Utility.h"
#include "Timer.h"
#include "Fx.h"
#include "Gx.h"

class Manager
{
private:
	Fx f;
	Gx g;
	Timer* timer;
public:
	Manager(int faultLimit, int timeLimit);
	int Compute(int x);
	Result GetTotalResult();
	void Initialisation(int limit);
	~Manager();
};