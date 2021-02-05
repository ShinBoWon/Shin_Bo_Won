#pragma once
#include "MapDraw.h"
#include "Weapon.h"

#define ROCK '1'
#define SCISSORS '2'
#define PAPER '3'

enum FIGHT
{
	FIGHT_ROCK = 1,
	FIGHT_SCISSORS,
	FIGHT_PAPER
	
}; 

typedef struct Information
{
	int Level;
	int Gold;

	int Exp;
	int Exp_Max;
	int Get_Exp;
	int Life;
	int Life_Max;

	int Demage;
	string Name;

};

class Character
{
private:
	
protected:
	Information m_Information;	

	Weapon *m_Weapon;
	WEAPON m_eWeapon;
	MapDraw m_Draw;

	virtual void Level_Up();

public:

	virtual int Attack();
	void Hit(int Demage);
	void Out_Information(int x, int y);

	void Fight_Win(Character * Fighter);
	virtual void Get_Data(Information load_Data, bool Weapon_Has);
	
	void Data_Save(int Number, string File);

	inline int Check_Life()
	{
		return m_Information.Life;
	}
	inline int Out_Gold()
	{
		return m_Information.Gold;
	}
	inline int Out_Exp()
	{
		return m_Information.Get_Exp;
	}

	Character();
	~Character();
	
};

