#pragma once
#include "Word.h"
class WordManager : public Word
{
private:
	vector<Word*> m_vecWord;
	list<Word*> m_listVirus;
public:
	void Get_List();

	void Delete_List();
	
	WordManager();
	~WordManager();
};

