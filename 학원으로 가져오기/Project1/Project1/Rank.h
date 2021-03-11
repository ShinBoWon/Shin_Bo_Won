#pragma once
#include "MapDraw.h" // Rank ������ �̸��� Rank

typedef struct Ranker
{
	string Ranker_Name;
	int Ranker_Stage;
	int Ranker_Score;
};
class Rank
{
private:
	vector<Ranker> m_vecRank;	
	MapDraw m_Draw;
public:

	void Rank_List();

	void Erase_Data();
	void Load_Ranker();
	
	Rank();
	~Rank();
};

