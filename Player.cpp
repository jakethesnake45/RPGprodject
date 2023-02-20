#include"Player.h"


Player::Player(string name, Race race,
	int hitpoints, int magicPoints)
{
	this->name = name;
	this->race = race;
	this->hitpoints = hitpoints;
	this->magicPoints = magicPoints;
}



//----------------------getters
string Player::getName() const
{
	return name;
}
Race Player::getRace() const
{
	return race;
}
string Player::whatRace() const
{
	string result = "";
	if (race == Human)
	{
		result = "Human";
	}
	else if (race == ELF)
	{
		result = "ELF";
	}
	else if (race == DWARF)
	{
		result = "Dwarf";
	}
	else if (race == ORC)
	{
		result = "ORC";
	}
	else if (race == TROLL)
	{
		result = "TROLL";
	}
	return result; 
}
int Player::getHitPoints() const
{
	return hitpoints;
}
int Player::getMagicPoints()const
{
	return magicPoints;
}



//-------------------setters
void Player::setName(string name)
{
	this->name = name;
}
void Player::setRace(Race race)
{
	this->race = race;
}
void Player::setHitPoints(int hitpoints)
{
	this->hitpoints = hitpoints;
}
void Player::setMagicPoints(int magicpoints)
{
	this->magicPoints = magicpoints;
}