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
	vector<Ranker*> m_vecRank;	
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

