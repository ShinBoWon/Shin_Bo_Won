#include "Hammer.h"

Hammer::Hammer()
{

}

int Hammer::Attack(int Character_Demage)
{
	m_Draw.DrawMidText("                              ", WIDTH, HEIGHT*0.46f + 1);
	int Demage = Character_Demage + m_iDemage;
	if (rand() % 100 <= 60)
	{
		m_Draw.DrawMidText("대지 가르기 (Damage : " + to_string(Demage * 10) + ")", WIDTH, HEIGHT*0.46f + 1);
		getch();
		return Demage * 1.5f;
	}
	else
		return Demage;
}

Hammer::~Hammer()
{

}