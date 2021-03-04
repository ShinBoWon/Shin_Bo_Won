#pragma once
#include "Rank.h"
#include "Interface.h"
#include "WordManager.h"

enum MENU
{
	MENU_GAME_START = 1,
	MENU_RANK,
	MENU_GAME_EIXT
};

typedef struct Player
{
	int Score;
	int Stage;
	int Life;
	string Name;
};

class Play
{
private:

	MapDraw m_Draw;
	Interface m_Interface;
	Player *m_Player;
	WordManager m_Manager;

public:
	void Game_Play();
	void Game_Main();
	void Input_Data(string Name);
	void Delete_Data();
	Play();
	~Play();
};

