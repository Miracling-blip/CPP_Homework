#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    srand(100);
    for (int i = 0; i < 10; i++)
    {
        cout << rand() << endl;
    }
}