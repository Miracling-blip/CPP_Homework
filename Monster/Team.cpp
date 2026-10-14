#include"Monster.h"
#include<iostream>
#include"Team.h"

Team::Team(): capacity(0), count(0), len(3)
{
    monsters = new Monster[3]{0, 0, 0};
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
    if (index < 0 || index >= count - 1)
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
                tmp[tmpIndex] = monster[i]
            }
            tmpIndex++;
        }
        delete[] monsters;
        monsters = tmp;
        tmp = nullptr;
        count--;
    }
}

int Team::getTotalPower()
{
    int totalPower = 0;
    for (int i = 0; i < count; ++i)
    {
        totalPower += monsters.power();
    }
    return totalPower;
}

Team& Team::operator=(Team& t)
{
    capacity = t.capacity;
    count = t.count;
    len = t.len;
    delete[] monsters;
    monsters = new Monsters[count];
    for (int i = 0; i < count; ++i)
    {
        monsters[i]->copy(t.monsters[i]);
    }
}

Team& Team::operator+(Team& t)
{
    Team tmpTeam;
    tmpTeam.capacity = this->capacity + t.capacity;
    tmpTeam.count = this->count + t.count;
    tmpTeam.len = this->len + t.len;
    tmpTeam.merge(*this, t);
    return tmpTeam;
}

void Team::merge(const Team& a, const Team& b)
{
    delete[] monsters;
    monsters = new Monster[count];
    for (int i = 0; i < count; ++i)
    {
        monsters[i]->
    }
}