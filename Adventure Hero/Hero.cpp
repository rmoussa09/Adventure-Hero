#include "Hero.h"
//THERE IS 1 MORE


//Done-------------------------
Hero::Hero(int h, int ap, int dp, int rc) {

	hp = h;
	attackPower = ap;
	defensePower = dp;
	retreatCount = rc;
	for (int i = 0; i < 3; i++) {
		bag[i] = NULL;
	}

}

//Done---------------------
void Hero::setDefensePower(int dp) {

	defensePower = dp;
}

//Done----------------------
const int Hero::getDefensePower() {

	return defensePower;

}

//Done-----------------------
void Hero::decreaseDefensePower() {

	defensePower = defensePower - 1;

}

//Done-------------------
const int Hero::getRetreatCount() {

	return retreatCount;

}

//Done-----------------
void Hero::decreaseRetreatCount() {

	retreatCount = retreatCount - 1;

}

//Done---------------------------
const bool Hero::anyItems() {
	bool x = false;
	for (int i = 0; i < 3; i++) {
		if (bag[i] != NULL) {
			return true;
		}
	}

	return false;


}

//Done-------------------------
const bool Hero::isAlive() {
	if (hp > 0)
		return true;
	else
		return false;


}

//Done--------------------------
Hero::Hero() {
	hp = 0;
	attackPower = 0;
	defensePower = 0;
	retreatCount = 3;
	for (int i = 0; i < 3; i++) {
		bag[i] = NULL;
	}
}

//Done--------------------------
void Hero::setHP(int ahp) {
	hp = ahp;
}

//Done--------------------------
const int Hero::getHP() {
	return hp;
}

//Done--------------------------
void Hero::setAttackPower(int attpow) {
	attackPower = attpow;
}

//Done--------------------------
const int Hero::getAttackPower() {
	return attackPower;
}

int Hero::operator*(Monster& m) {
	if (m.getHP() - getAttackPower() < 0)
		m.setHP(0);
	else
		m.setHP(m.getHP() - getAttackPower());

	setHP(getHP() - (m.getAttackPower() / getDefensePower()));

	m.decreaseAttackPower();
	decreaseDefensePower();

	if (getHP() == 0)
		return -1;

	else if (m.getHP() == 0)
		return 1;

	else
		return 0;

}