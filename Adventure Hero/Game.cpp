#include "Game.h"


Game::Game() {
	Alex.setHP(5);
	Alex.setAttackPower(3);
	Alex.setDefensePower(5);
	createMap();
}

void Game::createMap() {
	Monster* Farid = new Monster(3, 2);
	Monster* Raja = new Monster(1, 10);
	Item* h = new Item(0, 3);
	Item* d = new Item(1, 3);
	Item* a = new Item(2, 3);

	//                 name, north, south, east, west, item/mon
	Room* A1 = new Room("Start Room", NULL, NULL, NULL, NULL, false);
	Room* B1 = new Room("B1", NULL, NULL, NULL, A1, a);
	A1->setEastRoom(B1);
	Room* B2 = new Room("B2", NULL, B1, NULL, NULL, d);
	B1->setNorthRoom(B2);
	Room* C1 = new Room("C1", NULL, NULL, NULL, B1, Farid);
	Room* D1 = new Room("D1", NULL, NULL, NULL, C1, h);
	C1->setEastRoom(D1);
	Room* D0 = new Room("D0", D1, NULL, NULL, NULL, Raja);
	Room* D2 = new Room("Exit Room", NULL, D1, NULL, NULL, true);
	D1->setNorthRoom(D2);
	D1->setSouthRoom(D0);
	currentRoom = A1;

}



void Game::run() {

	Monster* Farid = new Monster(3, 3);
	Monster* Raja = new Monster(8, 5);
	Item* h = new Item(0, 3);
	Item* d = new Item(1, 3);
	Item* a = new Item(2, 3);

	//                 name, north, south, east, west, item/mon
	Room* A1 = new Room("Start Room", NULL, NULL, NULL, NULL, false);
	Room* B1 = new Room("B1", NULL, NULL, NULL, A1, a);
	A1->setEastRoom(B1);
	Room* B2 = new Room("B2", NULL, B1, NULL, NULL, d);
	B1->setNorthRoom(B2);
	Room* C1 = new Room("C1", NULL, NULL, NULL, B1, Farid);
	B1->setEastRoom(C1);
	Room* D1 = new Room("D1", NULL, NULL, NULL, C1, h);
	C1->setEastRoom(D1);
	Room* D0 = new Room("D0", D1, NULL, NULL, NULL, Raja);
	Room* D2 = new Room("D2", NULL, D1, NULL, NULL, true);
	D1->setNorthRoom(D2);
	D1->setSouthRoom(D0);




	currentRoom = A1;
	Room* PreviousRoom = NULL;

	while (Alex.isAlive() && !currentRoom->isExit()) {
		cout << "* Alex: HP/" << Alex.getHP() << " : AP/" << Alex.getAttackPower() << " : DP/" << Alex.getDefensePower() << " : RC/" << Alex.getRetreatCount() << endl << endl;


		cout << "*** RETREAT SECTION\n";
		if (currentRoom->getRoomMonster() != NULL) {
			char input;
			cout << "Would you like to retreat? [y/n]? \n";
			cin >> input;
			if (input == 'y' || input == 'Y') {
				currentRoom = PreviousRoom;
				Alex.decreaseRetreatCount();
				cout << "Moved to previous room: " << currentRoom->getName();

			}

		}


		cout << "*** ITEMS SECTION\n";
		if (Alex.anyItems()) {
			char input;
			string thing;
			int x;
			int counter = 0;
			cout << "Do you want to use an Item [y/n]? \n";
			cin >> input;
			if (input == 'y' || input == 'Y') {
				for (int i = 0; i < 3; i++) {
					if (Alex.bag[i] != NULL) {
						if (Alex.bag[i]->isHP())
							thing = "HP";
						else if (Alex.bag[i]->isDefense())
							thing = "DP";
						else if (Alex.bag[i]->isAttack())
							thing = "AP";
						cout << i << ") " << "Type/" << thing << " Value/" << Alex.bag[i]->getValue() << endl;
						counter++;
					}
					else
						cout << i << ") None" << endl;
				}
				cout << "Which item would you like to use? [0-" << counter << "]";
				cin >> x;

				if (Alex.bag[x]->isHP())
					Alex.setHP(Alex.getHP() + Alex.bag[x]->getValue());
				else if (Alex.bag[x]->isDefense())
					Alex.setDefensePower(Alex.getDefensePower() + Alex.bag[x]->getValue());
				else if (Alex.bag[x]->isAttack())
					Alex.setAttackPower(Alex.getAttackPower() + Alex.bag[x]->getValue());
				Alex.bag[x] = NULL;

			}
		}

		cout << "*** BATTLE SECTION\n";
		if (currentRoom->getRoomMonster() != NULL) {
			cout << "Battle!!";
			while (Alex.getHP() > 0 && currentRoom->getRoomMonster()->getHP() > 0) {
				cout << "* Alex: HP/" << Alex.getHP() << " : AP/" << Alex.getAttackPower() << " : DP/" << Alex.getDefensePower() << " : RC/" << Alex.getRetreatCount() << endl << endl;
				cout << "* Monster: HP/" << currentRoom->getRoomMonster()->getHP() << " : AP/" << currentRoom->getRoomMonster()->getAttackPower() << endl << endl;

				if (currentRoom->getRoomMonster()->getHP() - Alex.getAttackPower() < 0)
					currentRoom->getRoomMonster()->setHP(0);
				else
					currentRoom->getRoomMonster()->setHP(currentRoom->getRoomMonster()->getHP() - Alex.getAttackPower());

				Alex.setHP(Alex.getHP() - (currentRoom->getRoomMonster()->getAttackPower() / Alex.getDefensePower()));
				currentRoom->getRoomMonster()->decreaseAttackPower();
				Alex.decreaseDefensePower();
			}
		}

		cout << "*** POST-BATTLE SECTION\n";
		if (Alex.isAlive()) {
			char input;
			string thing;
			int x;

			if (currentRoom->getRoomItem() != NULL) {
				cout << "Do you want to pick up the room's item [y/n]?";
				cin >> input;
				cout << endl;
				if (input == 'y' || input == 'Y') {
					for (int i = 0; i < 3; i++) {
						if (Alex.bag[i] != NULL) {
							if (Alex.bag[i]->isHP())
								thing = "HP";
							else if (Alex.bag[i]->isDefense())
								thing = "DP";
							else if (Alex.bag[i]->isAttack())
								thing = "AP";
							cout << i << ") " << "Type/" << thing << " Value/" << Alex.bag[i]->getValue() << endl;
						}
						else {
							cout << i << ") None" << endl;
						}
					}

					cout << "Which position would you like to use? [0-2]";
					cin >> x;
					Alex.bag[x] = currentRoom->getRoomItem();
					currentRoom->setRoomItem(NULL);
					cout << "\nThe new item is now in the bag";
				}
			}

			int dir;
			cout << "\n= Directions = \n";
			if (currentRoom->getNorthRoom() != NULL)
				cout << "0) North: " << currentRoom->getNorthRoom()->getName() << endl;
			else
				cout << "0) North: You can not go here\n";

			if (currentRoom->getSouthRoom() != NULL)
				cout << "1) South: " << currentRoom->getSouthRoom()->getName() << endl;
			else
				cout << "1) South: You can not go here\n";

			if (currentRoom->getEastRoom() != NULL)
				cout << "2) East: " << currentRoom->getEastRoom()->getName() << endl;
			else
				cout << "2) East: You can not go here\n";

			if (currentRoom->getWestRoom() != NULL)
				cout << "3) West: " << currentRoom->getWestRoom()->getName() << endl;
			else
				cout << "3) West: You can not go here\n";

			cout << "Where do you want to go? [0-3]";
			cin >> dir;
			PreviousRoom = currentRoom;

			if (dir == 0)
				currentRoom = currentRoom->getNorthRoom();
			else if (dir == 1)
				currentRoom = currentRoom->getSouthRoom();
			else if (dir == 2)
				currentRoom = currentRoom->getEastRoom();
			else if (dir == 3)
				currentRoom = currentRoom->getWestRoom();
		}
	}

	if (currentRoom->isExit())
		cout << "\n\n\n\nCongratulations\n\n\n\n\n\n";
	else
		cout << "\n\n\n\nGame Over\n\n\n\n\n\n\n";
}

