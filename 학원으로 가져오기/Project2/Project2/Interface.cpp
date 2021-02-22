#include "Interface.h"

Interface::Interface()
{
}

void Interface::Make_Box()
{
	GREEN
	m_Draw.BoxDraw(0, 0, WIDTH, HEIGHT);
	ORIGINAL
}

void Interface::Story_Reading() // 시간 조절 할 것 . 
{
	ifstream load;
	string str;
	load.open("베네치아_스토리.txt");
	while (!load.eof())
	{
		getline(load,str);
		cout << str << endl;
	}

}

void Interface::Show_Interface()
{
	// Life , Score,  Name 이 세가지가 보여야 한다.
}


Interface::~Interface()
{
}
