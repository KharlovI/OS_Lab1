#include <iostream>
#include "Manager.h"
#include "Timer.h"
#include <ctime>
#include "Memory.h"
int main()
{
    Manager m = Manager(3, 5000);
    return m.Compute(2);
}