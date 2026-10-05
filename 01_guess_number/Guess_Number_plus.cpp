#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;
int compScore(int,int);
double run();
int* oneRound(int);
double cal_deviation(int**,int,int);
void cleaning(int* const*,int);

double run()
{
    bool isover = false;
    int round = 0, gametime = 0, adding = 10;
    int** score = new int*[1]();
    while (!isover)
    {
        round++;
        if(round != 1)
        {
            int** tmp = new int*[round];
            for (int i = 0; i < round - 1; ++i)
            {
                tmp[i] = score[i];
            }
            tmp[round - 1] = nullptr;
            delete[] score;
            score = tmp;
        }
        // 生成随机数
        int number = 0, seed;
        double average_score, sd = 0.0;
        /*if(per_ten == 11)
        {
            adding += 10; //表示动态数组应该有的行数
            per_ten = 1;
            int** tmp = new int*[adding]();
            for (int i = 0; i < (adding - 10); ++i)
            {
                tmp[i] = score[i];
            }
            cleaning(score);
            score = nullptr;
        }*/
        cin >> seed;
        srand(seed);
        if (seed == -1)
        {
            isover = true;
            if(round != 1)
            {
                sd = cal_deviation(score, gametime, round-1);
                cleaning(score, round - 1);
                score = nullptr;
                return sd;
            }
            else 
            {
                cleaning(score, round - 1);
                score = nullptr;
                return 0;
            }
            break;
        }
        else
        {
            number = rand() % 21;
            score[round - 1] = oneRound(number);
            gametime += 10;
        }
	}
    return 0;
}

int compScore(int N, int M)  //判断得分
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

int* oneRound(int N)
{
    int* arr = new int[11];
    for (int i = 0; i < 10; i++)
    {
        int guess_number;
        while (true)
        {
            cin >> guess_number;
            if (guess_number >= 0 && guess_number <= 20)
            {
                arr[i] = compScore(N, guess_number);
                break;
            }
            else
            {
                //cerr << "Illegal Static!" << endl;
                continue;
            }
        }
	}
    return arr;
}

double cal_deviation(int** arr, int gametime, int round)
{
    int sum = 0;
    double average = 0.0, stan = 0.0, answer = 0.0;
    for (int i = 0; i < round; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            sum += arr[i][j];
        }
    }
    average = (double)sum / gametime;
    for (int i = 0; i < round; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            stan += pow(average - arr[i][j], 2);
        }
    }
    stan /= gametime;
    answer = sqrt(stan);
    return answer;
}

void cleaning(int* const* score, int round)
{
    for (int i = 0; i < round; ++i)
    {
        delete[] score[i];
    }
    delete[] score;
}

int main()
{
    cout << run();
    return 0;
}
