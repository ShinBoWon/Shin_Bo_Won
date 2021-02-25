#include "Rank.h"

Rank::Rank()
{
}

void Rank::Load_Ranker()
{
	ifstream load;
	string Name;
	int Stage, Score;
	Ranker in_Data;
	load.open("Rank.txt");
	while (!load.eof())
	{
		load >> Name;
		load >> Stage;
		load >> Score;
		in_Data.Ranker_Name = Name;
		in_Data.Ranker_Stage = Stage;
		in_Data.Ranker_Score = Score;
		m_vecRank.push_back(in_Data);
	}
}

void Rank::Erase_Data()
{
	//m_vecRank.erase;
}



Rank::~Rank()
{
}
