#pragma once
#include "Word.h"
class WardManager : public Word
{
private:
	vector<Word> m_vecWard;
public:
	void Get_Ward();
	
	WardManager();
	~WardManager();
};

