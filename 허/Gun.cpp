#include "Gun.h"

Gun::Gun()
{

}

int Gun::Attack(int Character_Demage)
{
	m_Draw.DrawMidText("                              ", WIDTH, HEIGHT*0.46f + 1);
	int Demage = Character_Demage + m_iDamege;
	if (rand() % 100 <= 40)
	{
		m_Draw.DrawMidText("Çìµå¼¦ (Damage : " + to_string(Demage * 10) + ")", WIDTH, HEIGHT*0.46f + 1);
		getch();
		return Demage * 2;
	}
	else
		return Demage;
}

Gun::~Gun()
{

}