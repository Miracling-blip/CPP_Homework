#include"Vector.hpp"
#include<iostream>
using namespace std;
int main()
{
	Vector<int> v1;
	v1.pushback(10);
	v1.pushback(40);
	v1.pushback(30);
	v1.show();

	Vector<int> v2 = v1;
	v2[0] = 99;
	v1.show();
	v2.show();

	Vector<int> v4 = v1 + v2;
	v4.show();

	v4 += v2;
	v4.show();

	Vector<char> vs;
	vs.pushback('h');
	vs.pushback('i');
	vs.show();

	return 0;
}
