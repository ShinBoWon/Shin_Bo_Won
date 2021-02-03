#include "Dagger.h"

Dagger::Dagger()
{

}

int Dagger::Attack(int Character_Demage)
{
	m_Draw.DrawMidText("                              ", WIDTH, HEIGHT*0.46f + 1);
	int Demage = Character_Demage + m_iDemage;
	if (rand() % 100 <= 40)
	{
		m_Draw.DrawMidText("Å©¸®Æ¼ÄÃ ¼¦ (Damage : " + to_string(Demage * 10) + ")", WIDTH, HEIGHT*0.46f + 1);
		getch();
		return Demage * 2;
	}
	else
		return Demage;
}

Dagger::~Dagger()
{

}