#include <iostream>
#include "Manager.h"
#include "Timer.h"
#include <ctime>
int main()
{
    Manager m = Manager(3, 5000);
    return m.Compute(2);
}