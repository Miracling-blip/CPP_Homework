#ifndef _BIG_INT_H_
#define _BIG_INT_H_
#include<iostream>
using namespace std;
class BigInt
{
public:
	BigInt(int Number);
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
	BigInt& operator+=(const BigInt&);
	BigInt operator+(const BigInt&);
	BigInt& operator*=(const BigInt&);
	BigInt operator*(const BigInt&);
	BigInt operator-(const BigInt&);
	BigInt& operator-=(const BigInt&);
	/*BigInt operator/(const BigInt&);
	BigInt& operator/=(const BigInt&);*/
	friend ostream& operator<<(ostream&, const BigInt&);
	BigInt pureSub(const BigInt& a,const BigInt& b);
	BigInt pureSum(const BigInt&, const BigInt&);
	//pure函数的含义：不管正负号，将两个数进行加减
	int cmpAbsolute(const BigInt*,const BigInt*);
	int compare(const BigInt&, const BigInt&);
	void removeZero();
	void whetherZero();
private:
	bool isZero, isMinus;
	size_t len, size;
	char* s;
};

#endif
