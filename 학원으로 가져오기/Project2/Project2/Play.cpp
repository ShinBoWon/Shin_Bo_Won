#include "Play.h"

Play::Play()
{
	srand(time(NULL)); // ���� �ð� ����

	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d" ,   WIDTH , HEIGHT * 2 ); // �ڽ� ũ�� ����
	system(buf);
}

void Play::Menu()
{
	m_Draw.DrawMidText("�١� ����ġ�� �ڡ�",WIDTH,HEIGHT *0.2f);
	m_Draw.DrawMidText("1. Game Start",WIDTH,HEIGHT *0.4f);
	m_Draw.DrawMidText("2, Rank",WIDTH,HEIGHT *0.5f);
	m_Draw.DrawMidText("3. Exit",WIDTH,HEIGHT *0.6f);

	m_Draw.DrawPoint("Life : ��������������������",WIDTH,HEIGHT); // ���� ���� ��
	m_Draw.DrawPoint("Score: 0",WIDTH,HEIGHT); // �߾�
	m_Draw.DrawPoint("Name : ? ? ? ",WIDTH,HEIGHT); // ������ ��
	
}

void Play::Game_Playing()
{
	while (1)
	{
		Menu();
		switch (m_Draw.MenuSelectCursor(1,2,3,4))
		{
		case MENU_GAME_START:
			break;
		case MENU_RANK:
			break;
		case MENU_EXIT:
			return;

		}
	}
}


Play::~Play()
{

}
