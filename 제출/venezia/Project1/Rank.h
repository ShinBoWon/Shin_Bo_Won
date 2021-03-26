#pragma once
#include "Interface.h"

typedef struct Ranker
{
	string Ranker_Name;
	int Ranker_Stage;
	int Ranker_Score;
};
class Rank
{
private:
	Interface m_Interface;
	vector<Ranker*> m_vecRank;	
	MapDraw m_Draw;
public:

	void Rank_List();

	void Erase();

	void Load_Ranker();

	void Set_Ranking();

	void Delete_Data();

	void Chage_Location(int i, int j);
	
	Rank();
	~Rank();
};

