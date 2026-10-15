#include <iostream>
#include <cstdlib>
using namespace std;

class Monster
{
private:
	int speciesID, hp, level;
public:
	Monster(int id=0,int h=0,int l=1);
	int compPower();
	int getHp() const
	{
		return hp;
	}
	int getLevel() const
	{
		return level;
	}
	int getSpeciesId() const
	{
		return speciesID;
	}
	void copy(const Monster*);
	void operator=(const Monster& m);
};

Monster::Monster(int id, int h, int l):speciesID(id), hp(h), level(l) {}

int Monster::compPower()
{
	return (hp*level) / 10;
}

void Monster::copy(const Monster* m)
{
	speciesID = m->getSpeciesId();
	hp = m->getHp();
	level = m->getLevel();
}

void Monster::operator=(const Monster& m)
{
		speciesID = m.getSpeciesId();
		hp = m.getHp();
		level = m.getLevel();
}

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
	Trainer operator+(Trainer&);
	Trainer& operator+=(Trainer&);
	Monster* operator[](int);
	Trainer& operator++();
private:
	Team myTeam;
	int trainerID;
};

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

int main()
{
	srand(100);
	Trainer t1(1);
	t1.catchMonster(25, 80, 5);
	t1.catchMonster(4, 120, 7);

	Trainer t2(2);
	t2.catchMonster(7, 100, 6);

	Trainer t3(3);
	t3.catchMonster(1, 110, 6);

	Trainer t4 = t2 + t3;
	t1 += t4;

	t1.releaseMonster(1);
	std::cout << t1.getAveragePower() << std::endl;
	t4 = t1;

	for(int i = 0; i < 3; ++i, ++t4);
	std::cout << t4;
	std::cout << std::endl;

	Monster* m = t4[5];
	if(m != nullptr)
	{
		std::cout << m->getSpeciesId() << "," << m->getHp() << "," << m->getLevel();
	}
	else
	{
		std::cout << "out of range" << std::endl;
	}
	return 0;
}