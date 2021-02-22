#pragma once
#include "Rank.h"
#include "Interface.h"
#include "MapDraw.h"

enum MENU
{
	MENU_GAME_START = 1,
	MENU_RANK,
	MENU_EXIT
};
class Play
{
private:
	MapDraw m_Draw;
public:
	void Game_Playing();
	void Menu();

	Play();
	~Play();
};

