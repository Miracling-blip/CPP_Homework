#include <iostream>
#include "Clock.hpp"

int main()
{
    Clock c(23, 59, 59), c1(0, 0, 0), c2(0, 0, 0);
    c1 = c++;
    c2 = ++c;
    c1.showTime();
    c2.showTime();
}