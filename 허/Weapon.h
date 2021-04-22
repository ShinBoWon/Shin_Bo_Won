#pragma once
#include "MapDraw.h"
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
class Weapon
{
protected:
	string m_strName;
	string m_strKind;
	int m_iPrice;
	int m_iDemage;

	MapDraw m_Draw;

public:
	
	virtual int Attack(int Character_Demage) { return 1; };
	void Get_Data(string Kind, string Name, int Price, int Demage);
	void Out_Information(int i);

	inline string Out_Name()
	{
		return m_strName;
	}
	inline string Out_Kind()
	{
		return m_strKind;
	}
	inline int Out_Price()
	{
		return m_iPrice;
	}
	inline int Out_Demage()
	{
		return m_iDemage;
	}
	Weapon();
	~Weapon();

};

