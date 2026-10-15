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
	int getCount() const
	{
		return count;
	}
	int getTotalPower() const;
	Monster* get(int i);
	Team& operator=(const Team&);
	Team operator+(const Team&);
	void merge(const Team& a, const Team& b);
};
