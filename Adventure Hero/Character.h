#pragma once
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Character
{
protected:
    int hp = 0;
    int attackPower;
public:
    virtual void setHP(int ahp);
    virtual const int getHP();
    virtual void setAttackPower(int attpow);
    virtual const int getAttackPower();
};