#include <iostream>
#include "Vector.hpp"
using namespace std;
int main()
{
	Vector myVector;
	for (int i = 0; i < 40; ++i)
	{
		myVector.push(i);
	}
	cout << "Prime:\n";
	cout << myVector;
	cout << endl;
	Vector copy = myVector;
	cout << "Copy:\n";
	cout << copy;
	return 0;
}
