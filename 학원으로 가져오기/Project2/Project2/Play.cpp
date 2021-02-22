#include "Play.h"

Play::Play()
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
