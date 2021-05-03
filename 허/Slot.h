#pragma once
#include "Weapon.h"
class Slot
{
private:
	Weapon * Data;
	string name;

public:
	Slot();
	~Slot();
};

class Inventory : public Slot
{
private:
	vector<Slot*> Weapon_Bag;

public:
	Inventory() {};
	~Inventory() {};
};