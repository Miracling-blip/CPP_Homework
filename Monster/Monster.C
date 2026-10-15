#include"Monster.h"

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
