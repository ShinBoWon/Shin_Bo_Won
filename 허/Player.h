#pragma once
#include "Character.h"
#include "Bow.h"
#include "Gun.h"
#include "Dagger.h"
#include "Hammer.h"
#include "Sword.h"
#include "Wand.h"
#include "Inventory.h"

class Player : public Character
{
public:

	FIGHT Attack_Try();
	void New_Data(string File);
	void Old_Data(string File);
	void Has_Weapon(string Kind);

	void Has_Load_Weapon(string Kind, string Name, int Demage, int Price);
	void Get_Weapon(Weapon * weapon);
	void Load_Weapon(Weapon * weapon);
	

	inline string Out_Weapon_Name()
	{
		return m_Weapon->Get_Name();
	}
	inline string Out_Weapon_Kind()
	{
		return m_Weapon->Get_Kind();
	}

	Player();
	~Player();
};

