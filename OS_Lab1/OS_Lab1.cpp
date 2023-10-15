#include <iostream>
#include "Manager.h"
#include "Timer.h"
int main()
{
    Manager m = Manager(3, 10000);
    m.Compute(7);
}