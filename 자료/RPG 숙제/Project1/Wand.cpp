#include "Wand.h"

Wand::Wand()
{

}

int Wand::Attack(int Character_Demage)
{
	m_Draw.DrawMidText("                              ", WIDTH, HEIGHT*0.46f + 1);
	int Demage = Character_Demage + m_iDemage;
	if (rand() % 100 <= 1)
	{
		m_Draw.DrawMidText("Áï ÞÝ(Damage : " + to_string(Demage * 10) + ")", WIDTH, HEIGHT*0.46f + 1);
		getch();
		return Demage * 2500;
	}
	else
		return Demage;
}

Wand::~Wand()
{

}