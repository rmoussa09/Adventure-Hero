#include "Monster.h"

// DONE
void Monster::setHP(int ahp) {
	hp = ahp;
}

//DONE
const int Monster::getHP() {
	return hp;
}

//DONE
void Monster::setAttackPower(int attpow) {
	attackPower = attpow;

}

//DONE
const int Monster::getAttackPower() {
	return attackPower;
}

//DONE
void Monster::decreaseAttackPower() {
	attackPower = attackPower - 1;
}

//DONE
Monster::Monster(int ahp, int aattpow) {
	hp = ahp;
	attackPower = aattpow;
}