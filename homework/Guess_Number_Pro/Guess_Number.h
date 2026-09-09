#pragma once
#include <iostream>
#include <vector>

class GuessNumber
{
    public:
        GuessNumber();
        void run();
        double cal_deviation();
        double cal_score(int N, int M);
    private:
        double sum, answer, average;
        std::vector<double> score;
        int round, guesstime;
};