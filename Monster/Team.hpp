#pragma once
#include "Monster.h"

class Team
{
private:
	Monster* monsters;
	int capacity, count, len;
public:
	Team();
	~Team();
	void add(const Monster&);
	void release(int);
	int getCount() return count;
	int getTotalPower();
	Monster* get(int i);
	Team& operator=(Team&);
	Team& operator+(Team&,Team&)
}
