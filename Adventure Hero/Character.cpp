#include "Character.h"

void Character::setHP(int ahp) {
	hp = ahp;

}

const int Character::getHP() {
	return hp;
}

void Character::setAttackPower(int attpow) {
	attackPower = attpow;
}

const int Character::getAttackPower() {
	return attackPower;
}