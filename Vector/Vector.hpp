#pragma once
#include<cstddef>
#include<stdexcept>
#include<iostream>
using namespace std;
template<typename T>
class Vector
{
public:
	Vector(Vector& other);
	Vector();
	~Vector();
	friend T;
	void pushback(T n);
	void show();
	void merge(const Vector*,const Vector*);
	Vector& operator=(const Vector&);
	Vector operator+=(const Vector&);
	T& operator[](int);
	Vector operator+(const Vector&);
private:
	T* p;
	size_t size, len;
};

template<typename T>
Vector<T>::Vector(Vector<T>& other)
{
	size = other.size;
	p = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		p[i] = other.p[i];
	}
}

template<typename T>
Vector<T>::Vector()
{
	size = 0;
	len = 3;
	p = new T[size];
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] p;
}

template<typename T>
void Vector<T>::pushback(T n)
{
	if (size == len)
	{
		len *= 2;
		T* tmp = new T[len];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = p[i];
		}
		tmp[size] = n;
		delete[] p;
		p = tmp;
		tmp = nullptr;
		size++;
	}
	else
	{
		T* tmp = new T[size + 1];
		for (int i = 0; i < size; ++i)
		{
			tmp[i] = p[i];
		}
		tmp[size] = n;
		delete[] p;
		p = tmp;
		tmp = nullptr;
		size++;
	}
}

template<typename T>
void Vector<T>::show()
{
	for (int i = 0; i < size; i++)
	{
		cout << p[i] << ' ';
	}
	cout << endl;
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	size = other.size;
	delete[] p;
	p = new T[size];
	len = other.len;
	for (int i = 0; i < size; i++)
	{
		p[i] = other.p[i];
	}
	return *this;
}

template<typename T>
void Vector<T>::merge(const Vector<T>* v1, const Vector<T>* v2)
{
	size = v1->size + v2 ->size;
	delete[] p;
	p = new T[size];
	for (int i = 0; i < v1->size; i++)
	{
		p[i] = v1->p[i];
	}
	int j = v1->size;
	for (int i = 0; i < v2->size; i++)
	{
		p[j] = v2->p[i];
		j++;
	}
	if (j != size)
	{
		cerr << "WRONG!" <<endl;
	}
}

template<typename T>
Vector<T> Vector<T>::operator+=(const Vector<T>& other)
{
	Vector<T> tmp;
	tmp.merge(this, &other);
	return tmp;
}

template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other)
{
	Vector<T> tmp;
	tmp.merge(this, &other);
	return tmp;
}

template<typename T>
T& Vector<T>::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        throw out_of_range("Index out of range!");
    }
    return p[index];
}
