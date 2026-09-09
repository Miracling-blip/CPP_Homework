#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

int cal_score(int N, int M)  //判断得分
{
    if (M == N)
        return 10;
    else if (M >= N - 1 && M <= N + 1)
        return 5;
    else if (M >= N - 3 && M <= N + 3)
        return 2;
    else
        return 0;
}

double cal_average(int *s, int size) //计算平均数
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

double cal_deviation(double *arr, int gametime)
{
    double sum = 0.0, average = 0.0, sd = 0.0;
    for (int i = 0; i < gametime; i++)
    {
        sum += arr[i];
    }
    average = sum / gametime;
    for (int i = 0; i < gametime; i++)
    {
        sd += (arr[i] - average) * (arr[i] - average);
    }
    sd = sqrt(sd / gametime);
    return sd;
}

int main()
{
    bool isover = false;
    while (!isover)
    {
        // 生成随机数
        int number = 0, seed, score[11] = {}, gametime = 0;
        double average_score[11] = (0.0), sd = 0.0;
        cin >> seed;
        srand(seed);
        if (seed == -1)
        {
            sd = cal_deviation(average_score, gametime);
            cout << sd <<endl;
            exit(0);
        }
        else
        {
            number = rand() % 21;
            //cout << number << endl;
            // 进行一次游戏（跑10次）
            for (int i = 0; i < 10; i++)
            {
                int guess_number;
                while (true)
                {
                    cin >> guess_number;
                    if (guess_number >= 0 && guess_number <= 20)
                    {
                        score[i] = cal_score(number, guess_number);
                        break;
                    }
                    else
                    {
                        cerr << "Illegal Static!" << endl;
                        continue;
                    }
                }
            }
            gametime++;
            average_score[gametime - 1] = cal_average(score, 10);
    	}
	}
    return 0;
}
