#pragma once
#include "Rank.h"
#include "Interface.h"
#include "WardManager.h"

#define READ 10

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
	int m_iScore;
	int m_iStage;
	string m_strName;

public:
	void Show_Reading();
	void Game_Play();
	void Main_Menu();
	void Game_Main();
	Play();
	~Play();
};

