#include "Word.h"

Word::Word()
{
}

void Word::Get_Word(string Word)
{
	m_strWord = Word;
}

void Word::Attack_Location(int x_Location, string Word)
{
	m_strWord = Word;
	m_iLocation_x = x_Location;
	m_iLocation_y = 1;
}

void Word::Drop() // ¶³¾îÁü °ú µ¿½Ã¿¡ ±×·ÁÁü
{
	if (m_iLocation_y != 1)
		m_Draw.DrawMidText("             ", m_iLocation_x, m_iLocation_y);	

	m_iLocation_y++;
	m_Draw.DrawMidText(m_strWord, m_iLocation_x, m_iLocation_y);
}

Word::~Word()
{
}
