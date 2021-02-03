#pragma once
#include "Weapon.h"
class Bow:public Weapon
{
public:
	int Attack(int Character_Demage);
	Bow();
	~Bow();
};

