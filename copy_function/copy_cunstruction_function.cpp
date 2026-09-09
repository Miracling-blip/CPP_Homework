#include<iostream>
#include "Point.h"
using namespace std;

int main(){
    Point a[5] = {Point(0, 0), Point(0, 0), Point(0, 0), Point(0, 0), Point(0, 0)};
    Point standard(1, 1);
    for (int i = 0; i < 5; i++){
        a[i] = Point (standard);
    }
    for (int i = 0; i < 5; i++){
        cout << a[i].Calculation() << endl;
    }
}