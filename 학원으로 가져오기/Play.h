#pragma once
#include "Rank.h"
#include "Interface.h"
#include "WardManager.h"

#define READ 10
#define SKIP 's'

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
	string Name;
};
class Play
{
private:
	MapDraw m_Draw;
	Interface m_Interface;
	Player *m_Player;
public:
	void Show_Reading();
	void Game_Play();
	void Main_Menu();
	void Game_Main();
	void Name_Check();
	void Player_Input_Data(string Name);
	Play();
	~Play();
};

