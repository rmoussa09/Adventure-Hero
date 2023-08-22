#pragma once
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item
{
private:
    int type; // 0-hp, 1-defense, 2-attack
    int value;
public:
    const bool isHP();
    const bool isDefense();
    const bool isAttack();
    const int getValue();
    Item(int t, int v);
};