#pragma once
#include"Team.h"
#include <iostream>
#include"Monster.h"

class Trainer
{
public:
	Trainer(int id = 0);
	Trainer(Trainer&);
	
	void catchMonster(int,int,int);
	void releaseMonster(int);
	double getAveragePower();

	Trainer& operator=(Trainer&);
	friend ostream& operator<<(ostream& os, Trainer&);
	Trainer& operator+(Trainer&);
	Trainer& operator+=(Trainer&, Trainer&);
	Monster* operator[](int);
	Trainer& operator++();
private:
	Team myTeam;
	int trainerID;
};
