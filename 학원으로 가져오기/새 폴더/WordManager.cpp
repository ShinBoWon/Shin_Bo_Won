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

void WordManager::Get_Attack_Word() // 떨어지는 시간에 맞쳐서 만들어지면서 다른 단어 들이랑 겹치지 않고 하기
{
	for (int i = 0; m_vecWord.size();i++)
	{
		for (int Sam_Word; Sam_Word <i; Sam_Word)
			;
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