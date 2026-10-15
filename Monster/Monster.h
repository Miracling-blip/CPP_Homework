#pragma once

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
