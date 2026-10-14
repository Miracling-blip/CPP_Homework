#include"Trainer.hpp"
#include<iostream>
#include"Monster.hpp"
#include"Team.hpp"
#include<cstdlib>

Trainer::Trainer(int id = 0):trainerID(id) {}

Trainer::Trainer(Trainer& other):trainerID(other.trainerID), myTeam(other.myTeam) {}

void Trainer::catchMonster(int id, int hp, int level)
{
	static Monster m(id, hp, level);
	myTeam.add(m);
}

void Trainer::releaseMonster(int index)
{
	myTeam.release(index);
}

double getAveragePower()
{
	double averagePower = myTeam.getTotalPower() / myTeam.getCount();
}

Trainer& Trainer::operator=(Trainer& t)
{
	trainerID(t.trainerID);
	myTeam = t.myTeam;
	return *this;
}

ostream& operator<<(ostream& os, Trainer& t)
{
	os << t.trainerID << t.myTeam.getCount();
	return os;
}

Trainer& Trainer::operator+(Trainer& t1, Trainer& t2)
{
	trainerID = t1.trainerID + t2.trainerID;
	myTeam = t1.myTeam + t2.myTeam;
	return *this;
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
