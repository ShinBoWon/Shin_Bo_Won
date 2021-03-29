#pragma once
#include "Word.h"

#define ABILITY 500

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
	int Speed_Up_Check;
	int Speed_Down_Start;
	int Speed_Down_Check;

	int Stop_Start;
	int Stop_Time_Check;
	bool Stop_Check;

	int Black_Start;
	int Black_Time_Check;
	bool Black_Check;
};

class WordManager
{
private:
	
	vector<Word*> m_vecWord;
	list<Word*> m_listVirus;
	int m_iWord_Count;
	int m_iSpeed;
	int m_iMake_Count;
	int m_iPercent;

	Item_Check m_Item_Check;
	Timer m_Timer;

public:
	void Get_List();
	void Get_Attack_Word();
	void Create_Word_Count(int Stage);
	bool Word_Size_Check(int Location_x, int Word_Location,string Word);

	bool Hit_Damage();
	bool Chekcing_Word(string Word);
	
	void Check_Stage(int Stage);

	void Item_Ability();
	void Item_Abliity_Check();
	void Black_Item();

	void Word_Drop();
	bool Drop_Time_Control(int Stage,int &Main_Time, int &Sec_Time, bool &Life_Check );

	void Delete_Virus();
	void Delete_List();
	
	WordManager();
	~WordManager();
};

