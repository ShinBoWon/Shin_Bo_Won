#include "Interface.h"

Interface::Interface()
{
	srand(time(NULL)); // ���� �ð� ����

	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", HEIGHT + 5, WIDTH * 2); // �ڽ� ũ�� ����
	system(buf);
}

void Interface::Make_Box()
{
	GREEN
	m_Draw.BoxDraw(0, 0, WIDTH, HEIGHT);
	ORIGINAL
}

void Interface::Show_Information()
{
	// ���ʴ�� �ǾƷ� ( �ǿ��� �߰� �� ������ )
	m_Draw.DrawPoint("Life : ",WIDTH,HEIGHT);
	m_Draw.DrawPoint("Score : ", WIDTH, HEIGHT);
	m_Draw.DrawPoint("Name : ", WIDTH, HEIGHT); 
}


Interface::~Interface()
{
}
