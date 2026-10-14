#include"Vector.h"
#include<iostream>
using namespace std;
int main()
{
	Vector a;
	for (int i = 0; i < 40; ++i)
	{
		a.push(i);
	}
	cout << "a:\n" << a;
	Vector b = a;
	cout << "b:\n" << b;
	return 0;
}
