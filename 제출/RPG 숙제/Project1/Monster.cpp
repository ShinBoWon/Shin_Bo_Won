#include "Monster.h"


Monster::Monster()
{

}

FIGHT Monster::Attack_Try()
{
	int At;
	At = rand() % 3 + 1;
	switch (At)
	{
	case FIGHT_ROCK:
		return FIGHT_ROCK;
	case FIGHT_SCISSORS:
		return FIGHT_SCISSORS;
	case FIGHT_PAPER:
		return FIGHT_PAPER;
	}
}

bool Monster::Fight_Win()
{
	m_Draw.BoxErase(WIDTH, HEIGHT);
	m_Draw.DrawMidText(m_Information.Name + " 승리 !!", WIDTH, HEIGHT * 0.3f);
	m_Draw.DrawMidText("GAME OVER !!", WIDTH, HEIGHT*0.3f + 2);
	m_Draw.DrawMidText("게임이 종료 됩니다.", WIDTH, HEIGHT*0.3f + 4);
	getch();
	return false;
}

void Monster::Monster_Dongeon(int i ,int Height)
{
	m_Draw.DrawMidText(to_string(i+1) + "층던전 : ["+ m_Information.Name + "]",WIDTH, Height); // 
}

void Monster::Data_Save_Add(int Number, string File)
{
	ofstream save;
	save.open(File + to_string(Number) + ".txt",ios::app);
	save << m_Information.Name;
	save << " " << m_Information.Demage;
	save << " " << m_Information.Life_Max;
	save << " " << m_Information.Exp_Max;
	save << " " << m_Information.Get_Exp;
	save << " " << m_Information.Level;
	save << " " << m_Information.Gold << endl;

	if (m_eWeapon != WEAPON_NOT)
	{
		save << " " << m_Weapon->Out_Kind();
		save << " " << m_Weapon->Out_Name();
		save << " " << m_Weapon->Out_Demage();
		save << " " << m_Weapon->Out_Price();
	}
	save.close();
}


Monster::~Monster()
{

}