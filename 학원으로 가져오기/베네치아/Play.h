#pragma once
#include "Rank.h"
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
	Rank m_Rank;

public:

	string Get_Name();	
	
	void Main_Play();
	void Game_Play();
	void Save_Game();

	void Input_Result(string &enter_word, bool& Word_Enter_Penalty);
	bool Word_Input(string &enter_word);

	void Penalty_Check();

	void Stage_up();
	void Stage_Box();

	void Main();
	void Input_Data(string Name);
	void Delete_Data();
	Play();
	~Play();
};

