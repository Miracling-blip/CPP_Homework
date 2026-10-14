#pragma once
#include<iostream>

class Complex
{
public:
    void display() const;
    Complex(double real, double imag): r(real), i(imag){}
    Complex operator + (const Complex &c2) const;
    Complex operator - (const Complex &c2) const;
    friend istream& operator>>(istream& s, Complex a);
    friend ostream& 
private:
    double r, i;
};