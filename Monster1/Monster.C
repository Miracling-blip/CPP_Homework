#include"Monster.h"

Monster::Monster(int id = 0, int h = 0, int l = 1):speciesId(id), hp(h), l(level) {}

Monster::power()
{
	return (hp*level) / 10;
}
