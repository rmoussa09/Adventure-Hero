#pragma once
#include "Room.h"

class Game
{
private:
	Room* currentRoom;
	Hero Alex;
public:
	Game();
	void run();
	void createMap();

};