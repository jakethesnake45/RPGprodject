#include<iostream>
#include<string>
#include<vector>
#include"Player.h"
#include"Warrior.h"
#include"Priest.h"
#include"Mage.h"

using namespace std;
void printMainMenu();
void printRaceMenu();
Player* createPlayer(string playername, int typeNum, int raceNum);
void doCleanup(vector<Player*> playerList);
Race getRace(int raceNum);
void printAll(vector<Player*> playerList);

int main()
{
	int choice;
	int raceNum;
	string playername;

	vector<Player*> playerList;

	printMainMenu();
	cin >> choice;
	cin.get();

	while (choice != 0)
	{
		cout << "What would like to name your character? " << endl;
		getline(cin,playername);

		printRaceMenu();
		cin >> raceNum;
		cin.get();

		Player* tempPlayer = createPlayer(playername, choice, raceNum);
		playerList.push_back(tempPlayer);

		printMainMenu();
		cin >> choice;
		cin.get();
	}
	printAll(playerList);

	doCleanup(playerList);

	cout << "Program done!" << endl;

	return 0;
}
void printMainMenu()
{
	cout << "Which of the following would you like?" << endl;
	cout << "\t1 - Create a Warrior" << endl;
	cout << "\t2 - Create a Priest" << endl;
	cout << "\t3 - Create a Mage" << endl;
	cout << "\t0 - Finish creating a character!" << endl;
}
void printRaceMenu()
{
	cout << "Now which race would like to pick?" << endl;
	cout << "\t1 Human" << endl;
	cout << "\t2 Elf" << endl; 
	cout << "\t3 Dwarf" << endl;
	cout << "\t4 Orc" << endl;
	cout << "\t5 Troll" << endl; 
}
Player* createPlayer(string playername, int typeNum, int raceNum)
{
	Race playerRace = getRace(raceNum);
	Player* tempPlayer = nullptr;

	if (typeNum == 1)
	{
		tempPlayer = new Warrior(playername, playerRace);
	}
	else if (typeNum == 2)
	{
		tempPlayer = new Priest(playername, playerRace);
	}
	else if (typeNum == 3)
	{
		tempPlayer = new Mage(playername, playerRace);
	}
	return tempPlayer;
}
void doCleanup(vector<Player*> playerList)
{
	for (Player* player : playerList)
	{
		delete player;
	}
	playerList.clear();
}
Race getRace(int raceNum)
{
	Race race;
	if (raceNum == 1)
	{
		race = Human;
	}
	else if (raceNum == 2)
	{
		race = ELF;
	}
	else if (raceNum == 3)
	{
		race = DWARF;
	}
	else if (raceNum == 4)
	{
		race = ORC;
	}
	else 
	{
		race = TROLL;
	}
	return race;
}
void printAll(vector<Player*> playerList)
{
	for (Player* player : playerList)
	{
		cout << "I'm a  " << player->whatRace() << " and my attack is : "
			<< player->attack() << endl;
	}
}