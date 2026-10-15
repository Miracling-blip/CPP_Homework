#include<iostream>
#include"Team.h"
using namespace std;
Team::Team(): capacity(0), count(0), len(3)
{
	monsters = new Monster[3];
}
Team::~Team()
{
	delete[] monsters;
}

void Team::add(const Monster& m)
{
	if(count == len)
	{
		len += 3;
		Monster* tmp = new Monster[len];
		for (int i = 0; i < count; ++i)
		{
			tmp[i] = monsters[i];
		}
		tmp[count] = m;
		delete[] monsters;
		monsters = tmp;
		tmp = nullptr;
		count++;
	}
	else
	{
		monsters[count++] = m;
	}
}

void Team::release(int index)
{
	if (index < 0 || index > count - 1)
	{
		return;
	}
	else
	{
		int tmpIndex = 0;
		Monster* tmp = new Monster[count - 1];
		for (int i = 0; i < count; ++i)
		{
			if(i != index)
			{
				tmp[tmpIndex] = monsters[i];
				tmpIndex++;
			}
		}
		if(tmpIndex != count - 1)
		{
			cout << endl << "WRONG" <<endl;
		}
		delete[] monsters;
		monsters = tmp;
		tmp = nullptr;
		count--;
	}
}

int Team::getTotalPower() const
{
	int totalPower = 0;
	for (int i = 0; i < count; ++i)
	{
		totalPower += monsters[i].compPower();
	}
	return totalPower;
}

Team& Team::operator=(const Team& t)
{
	capacity = t.capacity;
	count = t.count;
	len = t.len;
	delete[] monsters;
	monsters = new Monster[len];
	for (int i = 0; i < count; ++i)
	{
		monsters[i] = t.monsters[i];
	}
	return *this;
}

Team Team::operator+(const Team& t)
{
	Team tmpTeam;
	tmpTeam.capacity = this->capacity + t.capacity;
	tmpTeam.count = this->count + t.count;
	tmpTeam.len = tmpTeam.count;
	tmpTeam.merge(*this, t);
	return tmpTeam;
}

void Team::merge(const Team& a, const Team& b)
{
	int j = 0;
	delete[] monsters;
	monsters = new Monster[count];
	for (int i = 0; i < count; ++i)
	{
		if (i >= a.count)
		{
			monsters[i] = b.monsters[j];
			j++;
		}
		else
		{
			monsters[i] = a.monsters[i];
		}
	}
}

Monster* Team::get(int index)
{
	if(index < 0 || index >= count)
	{
		return nullptr;
	}
	else
	{
		return &monsters[index];
	}
}
