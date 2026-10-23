#include"BigInt.h"
#include<iostream>
#include<cstring>
using namespace std;

BigInt::BigInt(size_t Number)
{
	if (Number == 0)
	{
		isZero = true;
		size = 0;
		s = new char[0];
	}
	else
	{
		isZero = false;
		size_t n = Number, digit;
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
			digit = n % 10;
			s[i] = '0' + digit;
			n /= 10;
		}
		s[size] = '\0';
	}
}

BigInt::BigInt()
{
	size = 0;
	s = new char[0];
	isZero = true;
}

BigInt::BigInt(const char* other)
{
	size = strlen(other);
	s = new char[size + 1];
	strcpy(s, other);
}

BigInt::~BigInt()
{
	delete[] s;
}

BigInt::BigInt(const BigInt& other)
{
	size = other.size;
	s = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		s[i] = other.s[i];
	}
	s[size] = '\0';
}

BigInt& BigInt::operator=(const BigInt& other)
{
	size = other.size;
	delete[] s;
	s = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
                s[i] = other.s[i];
        }
        s[size] = '\0';
	return *this;
}

int BigInt::operator==(const BigInt& other)
{
	bool isDif = cmp(&other, this);
	if(isDif)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int BigInt::operator>=(const BigInt& other)
{
	int judge = cmp(this, &other);
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
        int judge = cmp(this, &other);
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
	int judge = cmp(this, &other);
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
        int judge = cmp(this, &other);
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
        int judge = cmp(this, &other);
        if (judge == 0)
        {
                return 0;
        }
        else
        {
                return 1;
        }
}

ostream& operator<<(ostream& os,const BigInt& other)
{
	for (int i = 0; i < other.size; i++)
	{
		os << other.s[i];
	}
	return os;
}

int BigInt::cmp(const BigInt* b1,const BigInt* b2)
{
	if ( b1->size != b2->size)
	{
		if(b1->size > b2->size)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return strcmp(b1->s, b2->s);
	}
}
