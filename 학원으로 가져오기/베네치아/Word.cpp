#include "Word.h"

Word::Word()
{
}

void Word::Get_Word(string Word)
{
	m_strWord = Word;
}

void Word::Pick_Up(int x_Location, string Word)
{
	m_strWord = Word;
	m_iLocation_x = x_Location;
	m_iLocation_y = 1;
	if (rand() % 2 == 0) // 10 ���� 1 Ȯ�� 
		Get_Item(rand() % ITEM_COUNT);
	else 
		m_Item = ITEM_DONT;
}

void Word::Die()
{
	m_Draw.gotoxy(m_iLocation_x, m_iLocation_y);
	for (int i = 0; i < m_strWord.size(); i++)
		cout << " ";
}

void Word::Get_Item(int Rand)
{
	switch (Rand)
	{
	case ITEM_SPEED_DOWN:
		m_Item = ITEM_SPEED_DOWN;
		break;
	case ITEM_SPEED_UP:
		m_Item = ITEM_SPEED_UP;
		break;
	case ITEM_STOP:
		m_Item = ITEM_STOP;
		break;
	case ITEM_CLEAR:
		m_Item = ITEM_CLEAR;
		break;
	case ITEM_BLACK:
		m_Item = ITEM_BLACK;
		break;
	}
}

void Word::Draw_Word(bool Black)
{
	m_Draw.gotoxy(m_iLocation_x, m_iLocation_y);
	if (Black)
	{
		if (m_Item != ITEM_DONT)
			RED
			cout << m_strWord;
		ORIGINAL
	}
	else
	{
		char Black = '=';
		string Blind = "";
		for (int i = 0; i < m_strWord.size(); i++)
			Blind += Black;
		BLUE
			cout << m_strWord;
		ORIGINAL
	}
}

bool Word::Drop() // ������ �� ���ÿ� �׷���
{
	Die();
	if (m_iLocation_y + 1< HEIGHT - 2)
	{
		m_iLocation_y++;
		return true;
	}
	else
		return false;	
}

Word::~Word()
{
}
