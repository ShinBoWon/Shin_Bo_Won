#include "Play.h"

Play::Play()
{
}

void Play::Main_Menu()
{
	m_Draw.DrawMidText("☆★ 베네치아 ★☆", WIDTH, HEIGHT);
	m_Draw.DrawMidText("1. Game STart", WIDTH, HEIGHT);
	m_Draw.DrawMidText("2. Rank", WIDTH, HEIGHT);
	m_Draw.DrawMidText("3. Exit", WIDTH, HEIGHT);
	//Life 랑 score Name 은 따로 설정해 두기
}

void Play::Game_Play()
{

}

void Play::Game_Main()
{
	m_Interface.Make_Box();
	while (1)
	{
		switch (m_Draw.MenuSelectCursor(3,2 /* 메뉴 간의 거리  */,3,4 /* 커서의 시작 위치  */))
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
