#include "Interface.h"

Interface::Interface()
{
	srand(time(NULL)); // 렌덤 시간 조절

	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", HEIGHT + 5, WIDTH * 2); // 박스 크기 조절
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
	// 차례대로 맨아래 ( 맨왼쪽 중간 맨 오른쪽 )
	m_Draw.DrawPoint("Life : ",WIDTH,HEIGHT);
	m_Draw.DrawPoint("Score : ", WIDTH, HEIGHT);
	m_Draw.DrawPoint("Name : ", WIDTH, HEIGHT); 
}


Interface::~Interface()
{
}
