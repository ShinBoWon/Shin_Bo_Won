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

void Interface::Story_Reading() // �ð� ���� �� �� . 
{
	ifstream load;
	string str;
	load.open("����ġ��_���丮.txt");
	while (!load.eof())
	{
		getline(load,str);
		cout << str << endl;
	}

}

void Interface::Show_Interface()
{
	// Life , Score,  Name �� �������� ������ �Ѵ�.
}


Interface::~Interface()
{
}
