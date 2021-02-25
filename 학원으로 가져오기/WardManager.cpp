#include "WardManager.h"

WardManager::WardManager()
{
}

void WardManager::Get_Ward()
{
	int Word_Count;
	string Spelling;
	ifstream load;
	load.open("Word.txt");
	load >> Word_Count;
	for (int i = 0; i < Word_Count; i++)
	{
		
		load >> Spelling;
		
	}
	
}


WardManager::~WardManager()
{
}
