#include "Room.h"

Room::Room(string nam, Room* nor, Room* sou, Room* eas, Room* wes, Item* it, Monster* mon) {
	name = nam;
	east = eas;
	west = wes;
	north = nor;
	south = sou;
	roomMonster = mon;
	roomItem = it;
	exit = false;
}

Room::Room(string nam, Room* nor, Room* sou, Room* eas, Room* wes, Monster* mon) {
	name = nam;
	east = eas;
	west = wes;
	north = nor;
	south = sou;
	roomMonster = mon;
	roomItem = NULL;
	exit = false;
}

Room::Room(string nam, Room* nor, Room* sou, Room* eas, Room* wes, Item* it) {
	name = nam;
	east = eas;
	west = wes;
	north = nor;
	south = sou;
	roomItem = it;
	roomMonster = NULL;
	exit = false;
}

Room::Room(string nam, Room* nor, Room* sou, Room* eas, Room* wes, bool ex) {
	name = nam;
	east = eas;
	west = wes;
	north = nor;
	south = sou;
	exit = ex;
	roomMonster = NULL;
	roomItem = NULL;
}

void Room::setName(string n) {
	name = n;
}

const string Room::getName() {
	return name;
}

void Room::setEastRoom(Room* e) {
	east = e;
}

void Room::setWestRoom(Room* w) {
	west = w;
}

void Room::setNorthRoom(Room* n) {
	north = n;
}

void Room::setSouthRoom(Room* s) {
	south = s;
}

Room* Room::getEastRoom() {
	return east;
}

Room* Room::getWestRoom() {
	return west;
}

Room* Room::getNorthRoom() {
	return north;
}

Room* Room::getSouthRoom() {
	return south;
}

void Room::setRoomMonster(Monster* ro) {
	roomMonster = ro;
}

Monster* Room::getRoomMonster() {
	return roomMonster;
}

void Room::setRoomItem(Item* it) {
	roomItem = it;
}

Item* Room::getRoomItem() {
	return roomItem;
}

bool Room::isExit() {
	if (exit == true)
		return true;

	else
		return false;
}

