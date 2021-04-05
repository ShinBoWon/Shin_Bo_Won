#include "Rank.h"

Rank::Rank()
{
}

void Rank::Load_Ranker()
{	
	Ranker *in_Data;
	ifstream load;
	int a;

	load.open("Rank.txt");
	while (!load.eof())
	{
		in_Data = new Ranker;
		load >> in_Data->Ranker_Name;
		load >> in_Data->Ranker_Stage;
		load >> in_Data->Ranker_Score;
		m_vecRank.push_back(in_Data); // 마지막에 왜 추가로 한번더 넣을까?
	}
	Set_Ranking();
}

void Rank::Rank_List()
{
	string Change ;
	
	Load_Ranker();
	
	MapDraw::GetInstance()->BoxDraw(WIDTH, HEIGHT * 0.1f + 1 , 30, 4);
	MapDraw::GetInstance()->DrawMidText(" Ranking ", WIDTH, HEIGHT * 0.1f + 3);
	
	for (int i = 1; i < WIDTH - 1; i++)
		MapDraw::GetInstance()->DrawPoint("=", i, HEIGHT * 0.3f);

	MapDraw::GetInstance()->DrawMidText("Name" , WIDTH * 0.7f,HEIGHT * 0.3f +2);
	MapDraw::GetInstance()->DrawMidText("Stage", WIDTH , HEIGHT * 0.3f + 2);
	MapDraw::GetInstance()->DrawMidText("Score", WIDTH * 1.35f, HEIGHT * 0.3f + 2);

	int i = 1;

	for (auto iter = m_vecRank.begin(); iter != m_vecRank.end(); iter++)
	{
		MapDraw::GetInstance()->DrawMidText( (*iter)->Ranker_Name, WIDTH * 0.7f, HEIGHT * 0.3f + 2 + i);
		MapDraw::GetInstance()->DrawMidText( to_string((*iter)->Ranker_Stage), WIDTH, HEIGHT * 0.3f + 2 + i);
		MapDraw::GetInstance()->DrawMidText( to_string((*iter)->Ranker_Score), WIDTH * 1.35f, HEIGHT * 0.3f + 2 + i);
		i += 2;
	}

	getch();
	Erase();
}

void Rank::Chage_Location(int i, int j)
{
	Ranker *Change_Ranker;

	Change_Ranker = m_vecRank[i];
	m_vecRank[i] = m_vecRank[j];
	m_vecRank[j] = Change_Ranker;

}

void Rank::Set_Ranking()
{
	
	for (int i = 0; i < m_vecRank.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (m_vecRank[j]->Ranker_Stage < m_vecRank[i]->Ranker_Stage)
				Chage_Location(i, j); // 스테이지가 다를 때 교환
			else if (m_vecRank[j]->Ranker_Stage == m_vecRank[i]->Ranker_Stage && m_vecRank[j]->Ranker_Score < m_vecRank[i]->Ranker_Score)
				Chage_Location(i, j); // 스테이지가 같지만 점수가 다를 때  교환
		}
	}
}

void Rank::Delete_Data()
{
	int i = 1;
	for (auto iter = m_vecRank.begin(); iter != m_vecRank.end(); iter++)
	{
		MapDraw::GetInstance()->DrawMidText("            ", WIDTH * 0.7f, HEIGHT * 0.3f + 2 + i);
		MapDraw::GetInstance()->DrawMidText("            ", WIDTH, HEIGHT * 0.3f + 2 + i);
		MapDraw::GetInstance()->DrawMidText("            ", WIDTH * 1.35f, HEIGHT * 0.3f + 2 + i);
		i += 2;

		delete (*iter); 
	}

	m_vecRank.clear();
}

void Rank::Erase()
{
	// 상자 지우기
	MapDraw::GetInstance()->BoxDraw(WIDTH, HEIGHT * 0.1f + 1, 30, 4);
	for (int i = 0; i <= 4; i++)
		MapDraw::GetInstance()->DrawMidText("                                                               ", WIDTH, HEIGHT * 0.1f + i);

	// 맨위 rank 표시 지우기
	MapDraw::GetInstance()->DrawMidText("          ", WIDTH, HEIGHT * 0.1f + 3);
	// 첫단 지우기
	MapDraw::GetInstance()->DrawMidText("      ", WIDTH * 0.7f, HEIGHT * 0.3f + 2);
	MapDraw::GetInstance()->DrawMidText("      ", WIDTH, HEIGHT * 0.3f + 2);
	MapDraw::GetInstance()->DrawMidText("      ", WIDTH * 1.35f, HEIGHT * 0.3f + 2);
	// 줄 지우기
	for (int i = 1; i < WIDTH - 1; i++)
		MapDraw::GetInstance()->DrawPoint(" ", i, HEIGHT * 0.3f);

	Delete_Data();
}

Rank::~Rank()
{
}
