#pragma once
#include "Word.h"

class WordManager
{
private:
	
	vector<Word*> m_vecWord;
	list<Word*> m_listVirus;
	int m_iWord_Count;
	int m_iDifficulty;

public:

	bool Eating_Word(string Word);
	void Get_List();
	void Get_Attack_Word();
	bool Hit_Damage();

	void Delete_Virus();

	void Delete_List();
	
	WordManager();
	~WordManager();
};

