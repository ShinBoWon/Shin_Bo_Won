#include "Bow.h"

Bow::Bow()
{

}

int Bow::Attack(int Character_Demage)
{
	m_Draw.DrawMidText("                              ", WIDTH, HEIGHT*0.46f + 1);
	int Demage = Character_Demage + m_iDemage;
	if (rand() % 100 <= 10)
	{
		m_Draw.DrawMidText("Çìµå¼¦!!(Damage : " + to_string(Demage * 10) + ")", WIDTH, HEIGHT*0.46f + 1);
		getch();
		return Demage * 10;
	}
	else
		return Demage;
}

Bow::~Bow()
{

}