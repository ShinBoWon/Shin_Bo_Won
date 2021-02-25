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
	
}

void WordManager::Delete_List()
{
	for (auto iter = m_vecWord.begin(); iter != m_vecWord.end(); iter++)
		delete *iter;

	m_vecWord.erase;

	for (auto iter = m_listVirus.begin(); iter != m_listVirus.end(); iter++)
		delete *iter;

	m_listVirus.erase;

}


WordManager::~WordManager()
{
}