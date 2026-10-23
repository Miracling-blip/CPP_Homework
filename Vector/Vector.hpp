#include<cstddef>
#pragma once

template<typename T>
class Vector
{
public:
	Vector(Vector& other);
	Vector();
	friend T;
	void pushback(T n);
	void show();
	void merge(Vector*,Vector*);
	Vector& operator=(const Vector&);
	Vector operator+=(const Vector&);
	T& operator[](int);
	Vector operator+(const Vector&);
private:
	T* p;
	size_t size, len;
};
