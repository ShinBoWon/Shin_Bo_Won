#pragma once
#include "Character.h"
class Monster : public Character
{

public:
	FIGHT Attack_Try();
	void Monster_Dongeon(int i, int Height);
	void Data_Save_Add(int Number, string File);
	bool Fight_Win();

	inline int Check_Life()
	{
		return m_Information.Life;
	}

	inline Information Out_Info()
	{
		return m_Information;
	}

	Monster();
	~Monster();	
};

