#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n, a[100];
    double sqrsum = 0.0, sum = 0.0, varians = 0.0;
    cout << "Enter the number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        sqrsum += pow(a[i], 2);
    }
    varians = (sqrsum / n) - pow((sum / n), 2);
    cout << varians;
    return 0;
}