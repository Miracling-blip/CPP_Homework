#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

class Round;

class Game
{
public:
    Game();
    ~Game();
    void Play();
    double Calculate();
private:
    Round** r;
    size_t round;
    bool isover;
};

class Round
{
public:
    Round();
    ~Round();
    void Play(int);
    int compScore(int,int);
    int getGametime() const
    {
        return gameTime;
    }
    int getScore(int i) const
    {
        return score[i];
    }
    int getTotalScore() const
    {
        return totalScore;
    }
private:
    int* score;
    bool isover;
    int gameTime, totalScore;
};

Game::Game(): round(0), isover(false)
{
    r = new Round*[2];
    for (int i = 0; i < 2; ++i)
    {
        r[i] = new Round;
    }
}

Game::~Game()
{
    for (int i = 0; i < round; ++i)
    {
        delete r[i];
    }
    delete[] r;
    r = nullptr;
}

void Game::Play()
{
    while(!isover)
    {
        if(round >= 2)
        {
            Round** tmp = new Round*[round + 1];
            for (int i = 0; i < round; ++i)
            {
                tmp[i] = r[i];
            }
            tmp[round] = new Round;
            r = tmp;
        }
        int seed, number;
        cin >> seed;
        if(seed == -1)
        {
            isover = true;
        }
        else
        {
            srand(seed);
            number = rand() % 21;
            r[round]->Play(number);
            round++;
        }
    }
}

double Game::Calculate()  //这相当于ppt中捏合收尾两轮的函数
{
    int total = r[0]->getGametime() + r[round - 1]->getGametime(), k = 0;
    int* finalScore = new int[total];
    double totalScore = 0.0, average = 0.0;
    for (int i = 0; i < r[0]->getGametime(); ++i)
    {
        totalScore += r[0]->getScore(i);
    }
    for (int j = r[0]->getGametime(); j < total; ++j)
    {
        totalScore += r[round - 1]->getScore(k);
        k++;
    }
    average = totalScore / total;
    return average;
    //average = (r[0]->getTotalScore() + r[round - 1]->getTotalScore()) / total;
    //return average;
}

Round::Round(): isover(false), gameTime(0)
{
    score = new int[1];
}

void Round::Play(int N)
{
    while(!isover)
    {
        int guessNumber;
        cin >> guessNumber;
        if(guessNumber > 20 || guessNumber < 0)
        {
            isover = true;
        }
        else
        {
            if(gameTime != 0)
            {
                int* tmp = new int[gameTime + 1];
                for (int i = 0; i < gameTime; ++i)
                {
                    tmp[i] = score[i];
                }
                delete[] score;
                score = tmp;
                tmp = nullptr;   
            }
            score[gameTime] = compScore(N, guessNumber);
            totalScore += score[gameTime];
            gameTime++;
        }
    }
}

int Round::compScore(int N, int M)  //判断得分
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

Round::~Round()
{
    delete[] score;
    score = nullptr;
}

int main()
{
    Game g;
    g.Play();
    cout << g.Calculate();
}