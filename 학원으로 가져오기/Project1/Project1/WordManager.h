#pragma once
#include "Word.h"

class WordManager : public Word
{
private:
	
	vector<Word*> m_vecWord;
	list<Word*> m_listVirus;
	int m_iWord_Count;
	int m_iDifficulty;

public:
	int Stage_Diffculty();
	bool Eating_Word(string Word);
	void Get_List();
	void Get_Attack_Word();
	void Word_Move_Down();

	void Delete_List();
	
	WordManager();
	~WordManager();
};

