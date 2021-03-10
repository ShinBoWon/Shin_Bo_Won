#pragma once
#include "Rank.h"
#include "Interface.h"
#include "WordManager.h"

#define SCORE_UP 200
#define MAX_WORD 20

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
	int m_iStage_Socre;
	
	MapDraw m_Draw;
	Interface m_Interface;
	Player *m_Player;
	WordManager m_Manager;

public:

	string Get_Name();
	void Word_Check(int &Time, int Fail_Time, string &enter_word);
	void Main_Play();
	void Game_Play();
	void Game_Main();
	void Input_Data(string Name);
	void Delete_Data();
	Play();
	~Play();
};

