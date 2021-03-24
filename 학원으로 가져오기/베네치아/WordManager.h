#pragma once
#include "Word.h"

typedef struct Item_Check
{
	bool Speed_Up;
	bool Speed_Down;
	bool Stop;
	bool Black;
};

typedef struct Timer
{
	int Speed_Up_Start;
	int Speed_Up_Stop;
	int Speed_Down_Start;
	int Speed_Down_Stop;
	int Stop_Start;
	int Stop_Stop;
	bool Stop_Check;
	int Black_Start;
	int Black_Stop;
	bool Black_Check;
};

class WordManager
{
private:
	
	vector<Word*> m_vecWord;
	list<Word*> m_listVirus;
	int m_iWord_Count;
	int m_iSpeed;

	ITEM m_Now_Item;

	Item_Check m_Item_Check;
	Timer m_Timer;

public:
	void Get_List();
	void Get_Attack_Word();

	bool Hit_Damage();
	bool Chekcing_Word(string Word);
	void Item_Aability();

	void Word_Drop();
	bool Drop_Time_Control(int Stage, int & Life,int &Main_Time, int &Sec_Time, bool &Life_Check );

	void Delete_Virus();
	void Delete_List();
	
	WordManager();
	~WordManager();
};

