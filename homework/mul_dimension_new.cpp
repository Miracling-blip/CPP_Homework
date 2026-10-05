#include <iostream>
#include <vector>
using namespace std;
void draw (int** p, int rows, int cols)
{
    int number = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            number++;
            p[i][j] = number;
        }
    }
}

void print(int** p, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << p[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int cols, rows;
    cout << "new**:\n";
    cin >> rows >> cols;
    int** p = new int*[rows];
    for (int i = 0; i < rows; ++i)
    {
        p[i] = new int[cols];
    }
    draw (p, rows, cols);
    print(p, rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        delete[] p[i];
    }
    delete[] p;
    p = nullptr;
    //cout << "vectoe\n";
}