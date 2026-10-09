#pragma once

class Complex
{
public:
    void display() const;
    Complex(double real, double imag): r(real), i(imag){}
    Complex operator + (const Complex &c2) const;
    Complex operator - (const Complex &c2) const;
private:
    double r, i;
};