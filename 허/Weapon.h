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

	//Weapon& operator=(const Weapon& data)
	//{
	//	m_strName = data.m_strName;
	//	m_strKind = data.m_strKind;
	//	m_iPrice = data.m_iPrice;
	//	m_iDamege = data.m_iDamege;
	//}
};

