#include"BigInt.h"
#include<iostream>

int main() {
	BigInt a(12345);
	BigInt b("98765432109876543210");
	BigInt c("2345");
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;

	BigInt d = b;
	std::cout << "d (copy of b) = " << d << std::endl;
	BigInt e;
	e = a;
	std::cout << "e (assigned from a) = " << e << std::endl;

	std::cout << "--- Comparisons ---" << std::endl;
	std::cout << "a == e : " << (a == e) << std::endl; // 1
	std::cout << "a <= e : " << (a <= e) << std::endl; // 1
	std::cout << "a != b : " << (a != b) << std::endl; // 1
	std::cout << "a <  b : " << (a < b) << std::endl; // 1
	std::cout << "a >= b : " << (a >= b) << std::endl; // 0
	std::cout << "b >  a : " << (b > a) << std::endl; // 1
	std::cout << "c == a : " << (c == a) << std::endl; // 0
	std::cout << "c <  a : " << (c < a) << std::endl; // 1

	return 0;
}
