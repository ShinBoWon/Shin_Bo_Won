#pragma once
#include "Item.h"

enum WEAPON
{
	WEAPON_DAGGER = 1,
	WEAPON_GUN,
	WEAPON_SWORD,
	WEAPON_WAND,
	WEAPON_BOW,
	WEAPON_HAMMER,	
	WEAPON_NOT
};

class Weapon : public Item
{	
public:
	
	virtual int Attack(int Character_Demage) = 0 ;
	void Out_Information(int i);

	Weapon();
	virtual ~Weapon();

};

