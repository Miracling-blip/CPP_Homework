#ifndef _BIG_INT_H_
#define _BIG_INT_H_
#include<iostream>
using namespace std;
class BigInt
{
public:
	BigInt(size_t Number);
	BigInt(const char* other);
	BigInt(const BigInt& other);
	BigInt();
	~BigInt();
	BigInt& operator=(const BigInt& other);
	int operator==(const BigInt&);
	int operator<=(const BigInt&);
	int operator>=(const BigInt&);
	int operator<(const BigInt&);
	int operator>(const BigInt&);
	int operator!=(const BigInt&);
	friend ostream& operator<<(ostream&, const BigInt&);
	int cmp(const BigInt*,const BigInt*);
private:
	bool isZero;
	size_t len, size;
	char* s;
};

#endif
