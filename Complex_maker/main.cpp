#include <iostream>
#include "Complex.hpp"

int main()
{
    double real1, imag1;
    double real2, imag2;
    std::cin >> real1 >> imag1;
    std::cin >> real2 >> imag2;
    Complex c1(real1, imag1), c2(real2, imag2);
    Complex c3(0, 0), c4(0, 0);
    c3 = c1 + c2;
//这时候编译器会把这行指令等效看成：c1.operator +(c2)
    c4 = c1 - c2;
    std::cout << "c1 + c2 = "<< c3;
    c3.display();
    std::cout << "c1 - c2 = "<< c4;
}