#include"Monster.hpp"

Monster::Monster(int id = 0, int h = 0, int l = 1):speciesID(id), hp(h), l(level) {}

Monster::power()
{
	return (hp*level) / 10;
}

void Monster::copy(const Monster* m)
{
	speciesID = m->getSpeciesId();
	hp = m->getHp();
	level = m->getLevel();
}
