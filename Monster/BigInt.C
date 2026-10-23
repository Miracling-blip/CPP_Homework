#include"BigInt.h"
#include<iostream>
#include<cstring>
using namespace std;

BigInt::BigInt(size_t Number)
{
	size_t n = Number;
	size = 0;
	len = 0;
	while(Number != 0)
	{
		size++;
		Number /= 10;
	}
	s = new char[size + 1];
	for (int i = size - 1; i >= 0; i--)
	{
		dig = n % 10;
		s[i] = '0' + dig;
		n /= 10;
	}
}

BigInt::BigInt()
{
	size = 0;
	s = new char[0];
	isZero = true;
}

BigInt::BigInt(const char* other):
{
	size = strlen(&other);
	s = new char[size + 1];
	strcpy(s, &other);
}

BigInt::BigInt(const BigInt& other)
{
	size = other.size;
	s = new char[size + 1];
	strcpy(s, &other.s);
}

BigInt& BigInt::operator=(const BigInt& other)
{
	size = other.size;
	delete[] s;
	s = new char[size + 1];
	strcpy(s, &other.s);
	return s;
}

int BigInt::operator==(const BigInt& other)
{
	bool isDif = strcmp(&other.s, &s);
	if(isDif)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int BigInt::operator>=(const BigInt& other)
{
	int judge = strcmp(&s, &other.s);
	if (judge == -1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int BigInt::operator<=(const BigInt& other)
{
        int judge = strcmp(&s, &other.s);
        if (judge == 1)
        {
                return 0;
        }
        else
        {
                return 1;
        }
}

int BigInt::operator>(const BigInt& other)
{
	int judge = strcmp(&s, &other.s);
	if (judge == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int BigInt::operator<(const BigInt& other)
{
        int judge = strcmp(&s, &other.s);
        if (judge == -1)
        {
                return 1;
        }
        else
        {
                return 0;
        }
}

int BigInt::operator!=(const BigInt& other)
{
        int judge = strcmp(&s, &other.s);
        if (judge == 0)
        {
                return 0;
        }
        else
        {
                return 1;
        }
}

ostream& operator<<(ostream& os, BigInt& other)
{
	for (int i = 0; i < other.size; i++)
	{
		os << other.s[i];
	}
	return os;
}
