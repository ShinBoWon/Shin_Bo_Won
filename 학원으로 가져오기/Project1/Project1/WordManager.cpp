#include "WordManager.h"

WordManager::WordManager()
{
}

void WordManager::Get_List()
{
	int Word_Count;
	string Spelling;
	ifstream load;
	load.open("Word.txt");
	load >> Word_Count;
	for (int i = 0; i < Word_Count; i++)
	{
		Word *Spell;
		Spell = new Word;
		load >> Spelling;
		Spell->Get_Word(Spelling);
		m_vecWord.push_back(Spell);		
	}
	m_iWord_Count = 0;
	m_iDifficulty = 1;
}

void WordManager::Get_Attack_Word() // 떨어지는 시간에 맞쳐서 만들어지면서 다른 단어 들이랑 겹치지 않고 하기
{
	int Rand_Word, x_Location,Limit_x = WIDTH * 2 - 20;
	string Get_Word;
	for (int i = 0; i <= m_iWord_Count;i++)
	{
		Rand_Word = rand() % m_vecWord.size();
		Get_Word = m_vecWord[Rand_Word]->Word_Out();
		if (m_listVirus.size() != 0)
		{
			for (auto iter = m_listVirus.begin(); iter != m_listVirus.end();iter++)
			{
				if (m_vecWord[i]->Word_Out() != (*iter)->Word_Out())
				{
					Word* Virus;
					Virus = new Word;
					x_Location = rand() % Limit_x + 10;
					Virus->Attack_Location(x_Location, m_vecWord[Rand_Word]->Word_Out());
					m_listVirus.push_back(Virus);
					m_iWord_Count++;
					return;
				}
				else
				{
					--i;
					break;
				}
			}
		}
		else
		{
			Word* Virus;
			Virus = new Word;
			x_Location = rand() % Limit_x + 10;
			Virus->Attack_Location(x_Location, m_vecWord[Rand_Word]->Word_Out());
			m_listVirus.push_back(Virus);

		}
	}
	m_iWord_Count++;
}

bool WordManager::Eating_Word(string Word)
{
	for (auto iter = m_listVirus.begin(); iter != m_listVirus.end(); iter++)
	{
		if ((*iter)->Word_Out() == Word)
			return true;
	}
	return false;
}

void WordManager::Word_Move_Down()
{
	for (auto iter = m_listVirus.begin(); iter != m_listVirus.end(); iter++)
	{
		(*iter)->Drop();
	}
}

void WordManager::Delete_List()
{
	for (auto iter = m_vecWord.begin(); iter != m_vecWord.end(); iter++)
		delete *iter;
	for (auto iter = m_listVirus.begin(); iter != m_listVirus.end(); iter++)
		delete *iter;

	m_vecWord.clear();
	m_listVirus.clear();
}


WordManager::~WordManager()
{
}