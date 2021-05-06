#include "Sword.h"

Sword::Sword()
{

}

int Sword::Attack(int Character_Demage)
{
	m_Draw.DrawMidText("                              ", WIDTH, HEIGHT*0.46f + 1);
	int Demage = Character_Demage + m_iDamege;
	if (rand() % 100 <= 50)
	{
		m_Draw.DrawMidText("°Ë ±â (Damage : " + to_string(Demage * 10) + ")", WIDTH, HEIGHT*0.46f + 1);
		getch();
		return Demage * 2;
	}
	else
		return Demage;
}

Sword::~Sword()
{

}