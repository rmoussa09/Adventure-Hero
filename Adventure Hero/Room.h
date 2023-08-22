#pragma once
#include "Monster.h"
#include "Hero.h"

class Room
{
private:
	string name;
	Room* east;
	Room* west;
	Room* north;
	Room* south;
	Monster* roomMonster;
	Item* roomItem;
	bool exit;

public:
	Room(string nam, Room* nor, Room* sou, Room* eas, Room* wes, Item* it, Monster* mon);
	Room(string nam, Room* nor, Room* sou, Room* eas, Room* wes, Monster* mon);
	Room(string nam, Room* nor, Room* sou, Room* eas, Room* wes, Item* it);
	Room(string nam, Room* nor, Room* sou, Room* eas, Room* wes, bool ex);
	void setName(string n);
	const string getName();
	void setEastRoom(Room* e);
	void setWestRoom(Room* w);
	void setNorthRoom(Room* n);
	void setSouthRoom(Room* s);
	Room* getEastRoom();
	Room* getWestRoom();
	Room* getNorthRoom();
	Room* getSouthRoom();
	void setRoomMonster(Monster* ro);
	Monster* getRoomMonster();
	void setRoomItem(Item* it);
	Item* getRoomItem();
	bool isExit();
};