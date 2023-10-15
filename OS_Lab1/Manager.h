#pragma once
#include <future>
#include <iostream>
#include"Utility.h"
#include "Timer.h"
class Manager
{
private:
	Result fx;	
	Result gx;
	int faultLimit;
	int currentFaultCount = 0;
	Timer* timer;


	// METHODS
	void IncrementFaultCount();
	bool FaultLimitAchieved();
public:
	Manager(int faultLimit, int timeLimit);
	void Compute(int x);
	Result GetTotalResult();
	void Initialisation(int limit);
	~Manager();
};