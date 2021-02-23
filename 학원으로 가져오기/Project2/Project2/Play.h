#pragma once
#include "Rank.h"
#include "Interface.h"
#include "WardManager.h"

enum MENU
{
	MENU_GAME_START = 1,
	MENU_RANK,
	MENU_GAME_EIXT
};
class Play
{
private:
	MapDraw m_Draw;
	Interface m_Interface;

public:
	void Game_Play();
	void Main_Menu();
	void Game_Main();
	Play();
	~Play();
};

