#include "Complex.hpp"
#include <iostream>
using namespace std;

void Complex::display() const
{
    cout << r << ',' << i << endl;
}

Complex Complex::operator +(const Complex &c2) const
{
    return Complex(r + c2.r, i + c2.i);
}

Complex Complex::operator -(const Complex &c2) const
{
    return Complex(r - c2.r, i - c2.i);
}