#include "Item.h"
//FINISHED CLASS


//Done----------------
const bool Item::isHP() {
    if (type == 0)
        return true;

    else
        return false;
}

//Done---------------------
const bool Item::isDefense() {
    if (type == 1)
        return true;

    else
        return false;
}

//Done--------------------------
const bool Item::isAttack() {
    if (type == 2)
        return true;

    else
        return false;
}

//Done------------------------

const int Item::getValue() {
    return value;
}

//Done-----------------------------
Item::Item(int atype, int avalue) {
    type = atype;
    value = avalue;
}