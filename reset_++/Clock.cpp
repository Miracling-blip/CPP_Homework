#include "Clock.hpp"
#include <iostream>

Clock::Clock(int h, int m, int s) : hour(h), minute(m), second(s) {}

void Clock::showTime() const
{
    std::cout << hour << ":" << minute << ":" << second << std::endl;
}

Clock Clock::operator ++()
{
    ++second;
    if (second >= 60)
    {
        second -= 60;
        ++minute;
        if (minute >= 60)
        {
            minute -= 60;
            ++hour;
            hour %= 24; // Ensure hour wraps around after 23
        }
    }
    return *this;
}

Clock Clock::operator++(int)
{
    Clock temp(*this);
    ++(*this);
    return temp;
}