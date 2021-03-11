#include "Rank.h"

Rank::Rank()
{
}

void Rank::Load_Ranker()
{	
	Ranker in_Data;
	ifstream load;
	int a;

	load.open("Rank.txt");
	while (!load.eof())
	{
		load >> in_Data.Ranker_Name;
		load >> in_Data.Ranker_Stage;
		load >> in_Data.Ranker_Score;
		m_vecRank.push_back(in_Data); // 마지막에 왜 추가로 한번더 넣을까?

	}
}

void Rank::Rank_List()
{
	string Change ;
	int i = 0;
	Load_Ranker();
	m_Draw.BoxDraw(0, 0, WIDTH, HEIGHT); // 수정할떄 목록 위치만 지우기 
	m_Draw.BoxDraw(WIDTH, HEIGHT * 0.1f + 1 , 30, 4);
	m_Draw.DrawMidText(" Ranking ", WIDTH, HEIGHT * 0.1f + 3);
	
	for (int i = 1; i < WIDTH - 1; i++)
		m_Draw.DrawPoint("=", i, HEIGHT * 0.3f);

	m_Draw.DrawMidText("Name" , WIDTH * 0.7f,HEIGHT * 0.3f +2);
	m_Draw.DrawMidText("Score", WIDTH , HEIGHT * 0.3f + 2);
	m_Draw.DrawMidText("Name", WIDTH * 1.35f, HEIGHT * 0.3f + 2);

	for (auto iter = m_vecRank.begin(); iter != m_vecRank.end(); iter++)
	{
		m_Draw.DrawMidText((*iter).Ranker_Name, WIDTH * 0.7f, HEIGHT * 0.3f + 3 + i);
		m_Draw.DrawMidText(to_string((*iter).Ranker_Stage), WIDTH, HEIGHT * 0.3f + 3 + i);
		m_Draw.DrawMidText(to_string((*iter).Ranker_Score), WIDTH * 1.35f, HEIGHT * 0.3f + 3 + i);
		i += 2;
	}
}

void Rank::Erase_Data()
{
	//m_vecRank.erase;
}



Rank::~Rank()
{
}
