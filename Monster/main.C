#include"Trainer.h"
#include"Monster.h"
#include"Team.h"
#include <iostream>
#include <cstdlib>

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
		std::cout << m->getSpeciesId() << "," << m->getHp() << "," << m->getLevel() << std::endl;
	}
	else
	{
		std::cout << "out of range" << std::endl;
	}
	return 0;
}
