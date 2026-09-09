#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int cal_score(int N, int GN)
{
    if (GN == N)
        return 10;
    else if (GN >= N - 1 && GN <= N + 1)
        return 5;
    else if (GN >= N - 3 && GN <= N + 3)
        return 2;
    else
        return 0;
}

double cal_average(int *s, int size)
{
    double average = 0.0;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += s[i];
    }
    average = (sum + 0.0) / size;
    return average;
}

int main()
{
    bool isover = false;
    while (!isover)
    {
        // 生成随机数
        int number = 0, seed, score[11] = {};
        double average_score = 0.0;
        char go;
        cout << "Please type in the seed to generate random number:";
        cin >> seed;
        srand(seed);
        if (seed == -1)
        {
            exit(0);
        }
        else
        {
            number = rand() % 21;
            cout << number << endl;
            // 进行一次游戏（跑10次）
            for (int i = 0; i < 10; i++)
            {
                int guess_number;
                while (true)
                {
                    cout << "Please type in the number(between 0 and 20) you guess:";
                    cin >> guess_number;
                    if (guess_number >= 0 && guess_number <= 20)
                    {
                        score[i] = cal_score(number, guess_number);
                        break;
                    }
                    else
                    {
                        cout << "Illegal Static!" << endl;
                        continue;
                    }
                }
            }
            average_score = cal_average(score, 10);
            cout << "This turn your score is:" << average_score << endl;

            while (true)
            {
                cout << "Do you want to continue the game?(Y/n):";
                cin >> go;
                if (go == 'Y')
                {
                    isover = false;
                    break;
                }
                else if (go == 'n')
                {
                    isover = true;
                    break;
                }
                else
                {
                    cout << "Illegal input!" << endl;
                    continue;
                }
            }
        }
    }
    return 0;
}
