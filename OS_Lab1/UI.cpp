#include "UI.h"

void UI::askParametrs()
{
	int faultLimit;
	int timeLimitMillisec;

	std::cout << "Time limit in Millisec: ";
	std::cin >> timeLimitMillisec;
	std::cout << "           Fault limit: ";
	std::cin >> faultLimit;
	
	m.Initialisation(timeLimitMillisec, faultLimit);
}

float UI::askX()
{
	float x;
	std::cout << "               X-value: ";
	std::cin >> x;
	return x;
}

int UI::Start()
{
	askParametrs();
	float x = askX();
	return m.Compute(x);
}
