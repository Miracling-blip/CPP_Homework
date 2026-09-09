#pragma once
#include <iostream>
using namespace std;

class Point{
private:
    int x, y;
public:
    Point(int x1, int y1){
        x = x1;
        y = y1;
    }
    Point(const Point &other) :x(other.x), y(other.y){}
    int Calculation(){
        return sqr(x) + sqr(y);
    }
    int sqr(int a){
        return a * a;
    }
};