#include "Guess_Number.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>


GuessNumber::GuessNumber() : sum(0.0), answer(0.0), round(0), guesstime(0), average(0.0)
{
}

void GuessNumber::run()
{
    while(true)
    {
        int seed;
        std::cout << "Please input a seed number (or -1 to exit): ";
        std::cin >> seed;
        if(seed == -1)
        {
            average = sum / (double)guesstime;
            answer = cal_deviation();
            std::cout << answer;
            exit(0);
        }
        else
        {
            std::srand(seed);
            int number = rand() % 21;
            std::cout << "Please Guess ten numbers (between 0 and 20): ";
            for (int i = 0; i < 10; ++i)
            {
                int guess;
                while(true)
                {
                    std::cin >> guess;
                    if (guess >= 0 && guess <= 20)
                    {
                        guesstime++;
                        sum += cal_score(number, guess);
                        score.push_back(cal_score(number, guess));
                        break;
                    }
                    else
                    {
                        std::cerr << "Invalid guess. Please try again." << std::endl;
                        continue;
                    }
                }
            }
        }
    }
}

double GuessNumber::cal_deviation()
{
    double sum_of_squares = 0.0;
    for (int i = 0; i < guesstime; ++i)
    {
        sum_of_squares += (score[i] - average) * (score[i] - average);
    }
    return std::sqrt(sum_of_squares / guesstime);
}

double GuessNumber::cal_score(int N, int M)
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