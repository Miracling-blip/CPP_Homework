#include "Vector.hpp"
#include <iostream>
using namespace std;

Vector::Vector():size(0)
{
	p = new int[0];
}

void Vector::push(int N)
{
	size++;
	int* tmp = new int[size]{0};
	if(size == 1)
	{
		tmp[0] = N;
	}
	else
	{
		for (size_t i = 0; i < size - 1; ++i)
		{
			tmp[i] = p[i];
		}
		tmp[size - 1] = N;
	}
	delete[] p;
	p = tmp;
	tmp = nullptr;
}

Vector::Vector(Vector& v):size(v.size)
{
	p = new int[size];
	for (size_t i = 0; i < size; ++i)
	{
		p[i] = v.p[i];
	}
}


ostream& operator<<(ostream& o, const Vector& v)
{
	for (size_t i = 0; i < v.size; ++i)
	{
		o << v.p[i] << ' ';
	}
	return o;
}
