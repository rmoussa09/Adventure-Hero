#pragma once
#include "Character.h"

class Monster : public Character
{
public:
    void decreaseAttackPower();
    Monster(int hp, int attpow);
    void setHP(int ahp);
    const int getHP();
    void setAttackPower(int attpow);
    const int getAttackPower();
};