#pragma once

class Clock
{
public:
    Clock(int h, int m, int s);
    void showTime() const;
    Clock operator++(); // Prefix increment
    Clock operator++(int); // 后置++专门要写上一个不用的形参，用于与前置++区分
private:
    int hour, minute, second;
};