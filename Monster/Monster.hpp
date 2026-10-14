#pragma once

class Monster
{
private:
	int speciesID, hp, level;
public:
	Monster(int,int,int);
	int power();
	int getHp() return hp;
	int getLevel() return level;
	int getSpeciesId() return speciesId;
	void push(const Monster& m);
};
