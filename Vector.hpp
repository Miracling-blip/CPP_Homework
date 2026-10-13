#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <iostream>
using namespace std;

class Vector
{
public:
	void push (int N);
	Vector();
	Vector(Vector& v);
	friend ostream& operator<<(ostream& o, const Vector& v);
private:
	size_t size;
	int* p;
};
#endif
