#include"Trainer.h"
#include<iostream>
#include<cstdlib>
using namespace std;
Trainer::Trainer(int id):trainerID(id) {}

Trainer::Trainer(Trainer& other):trainerID(other.trainerID)
{
	myTeam = other.myTeam;
}

void Trainer::catchMonster(int id, int hp, int level)
{
	Monster m(id, hp, level);
	myTeam.add(m);
}

void Trainer::releaseMonster(int index)
{
	myTeam.release(index);
}

double Trainer::getAveragePower()
{
	double averagePower = (myTeam.getTotalPower()) / (myTeam.getCount()*1.0);
	return averagePower;
}

Trainer& Trainer::operator=(Trainer& t)
{
	trainerID = t.trainerID;
	myTeam = t.myTeam;
	return *this;
}

ostream& operator<<(ostream& os, Trainer& t)
{
	os << t.trainerID<<":" << t.myTeam.getCount();
	return os;
}

Trainer Trainer::operator+(Trainer& t1)
{
	Trainer tmp(10);
	tmp.myTeam = t1.myTeam + myTeam;
	return tmp;
}

Monster* Trainer::operator[](int index)
{
	return myTeam.get(index);
}

Trainer& Trainer::operator++()
{
	Monster m(rand(), rand(), rand());
	myTeam.add(m);
	return *this;
}

Trainer& Trainer::operator+=(Trainer& t)
{
	myTeam = myTeam + t.myTeam;
	return *this;
}
