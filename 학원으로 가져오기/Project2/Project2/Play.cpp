#include "Play.h"

Play::Play()
{
}

void Play::Main_Menu()
{
	m_Draw.DrawMidText("�١� ����ġ�� �ڡ�", WIDTH, HEIGHT);
	m_Draw.DrawMidText("1. Game STart", WIDTH, HEIGHT);
	m_Draw.DrawMidText("2. Rank", WIDTH, HEIGHT);
	m_Draw.DrawMidText("3. Exit", WIDTH, HEIGHT);
	//Life �� score Name �� ���� ������ �α�
}

void Play::Game_Play()
{

}

void Play::Game_Main()
{
	m_Interface.Make_Box();
	while (1)
	{
		switch (m_Draw.MenuSelectCursor(3,2 /* �޴� ���� �Ÿ�  */,3,4 /* Ŀ���� ���� ��ġ  */))
		{
		case MENU_GAME_START:
			break;
		case MENU_RANK:
			break;
		case MENU_GAME_EIXT:
			return;
		}
	}
} 

Play::~Play()
{
}
