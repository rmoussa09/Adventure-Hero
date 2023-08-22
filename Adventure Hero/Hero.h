#pragma once
#include "Character.h"
#include "Item.h"
#include "Monster.h"

class Hero : public Character {

private:
    int defensePower;
    int retreatCount;

public:
    Item* bag[3];
    void setDefensePower(int dp);
    const int getDefensePower();
    void decreaseDefensePower();
    const int getRetreatCount();
    void decreaseRetreatCount();
    const bool anyItems();
    const bool isAlive();
    Hero(int h, int ap, int dp, int rc);
    Hero();
    int operator*(Monster& m);
    void setHP(int ahp);
    const int getHP();
    void setAttackPower(int attpow);
    const int getAttackPower();
};
