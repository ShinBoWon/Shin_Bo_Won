#pragma once
#include "Interface.h"
#include "Singleton.h"

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

	void Load_Ranker();

	void Rank_List();
	void Set_Ranking();	
	void Chage_Location(int i, int j);

	void Delete_Data();
	void Erase();

	
	
	Rank();
	~Rank();
};

