#pragma once
#include "Monster.h"
#include "Player.h"
#include "Shop.h"

#define SAVE_FILE 10

class GamePlay
{
private:
	int m_iWidth; 
	int m_iHeight;
	int m_iMonster_Count; // 몬스터 마리 수

	bool m_bGame_Over;

	MapDraw m_Draw;
	vector<Monster*> m_vecMonster;
	Player *m_pHero;
	
	Shop m_Shop;

public:

	void Map();
	void Game();
	bool New_Game();

	void Cout_Save_Data(int Width, int Height);
	bool Save_Data_Check();
	void Load_Data(int Number);
	bool Monster_Data_Check(int Count);
	bool Player_Data_Check(int Count);

	void Data_Save();


	void Play_Menu();
	void Main_Menu();
	void Dongeon_Menu(int Height);

	void Dongeon();
	
	void Get_Monster(string File);
	bool Get_Weapon();
	void Get_Fight_Monster_Data(Monster &Fight_Monster,int i);
	void Fighting(int i);
	
	void Battle(FIGHT P1, FIGHT P2 , Monster &Fighter);
	void Fight_Draw(int x, int y, FIGHT ch);

	void Weapon_Shop();
	void Weapon_List();

	void Verdit(int i, bool & Monster_survival , Monster Figher);
	
	void Delete_Data();

	GamePlay();
	~GamePlay();

};

