#include <iostream>
using namespace std;
int main()
{
    int a[10];
    a[1] = 100; // 100 to the second element
    a[9] = 101; // 101 to the last element
    int i=1, j=2;
    a[i+j] = 10; // 10 to the 4th element      
    a[i+j] += 2; // add 2 to the 4th element,    
    a[i] = a[i+1] = 1;
    a[i++] = 2;
    if (a[1] > a[2]) a[1] = a[2]; 
    return 0;
}