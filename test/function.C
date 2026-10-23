#include<iostream>
using namespace std;
class A {
    int x;
public:
    A() {cout << "C1" << endl;}
    A(int y) : x(y) {cout << "C2" << endl;}
    A(const A& a): x(a.x) {cout << "C3" << endl;}
    A& operator=(const A& a) {cout << "=" << endl; return *this;}
    ~A() {cout << "D" << endl;}
};

A f1(A a) {return a;}

int main() {
    A a;
    a = f1(a);
}
