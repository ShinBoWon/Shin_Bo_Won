#include "Play.h"

Play::Play()
{

}

void Play::Main_Menu()
{
	m_Draw.BoxErase(WIDTH, HEIGHT);
	YELLOW
	m_Draw.DrawMidText("☆★ 베네치아 ★☆", WIDTH, HEIGHT * 0.2f);
	m_Draw.DrawMidText("1. Game Start", WIDTH - 1, HEIGHT * 0.4f);
	m_Draw.DrawMidText("2. Rank", WIDTH - 1, HEIGHT * 0.4f + 3 );
	m_Draw.DrawMidText("3. Exit", WIDTH - 1, HEIGHT * 0.4f + 6 );
	ORIGINAL
	//Life 랑 score Name 은 따로 설정해 두기
}

void Play::Game_Play()
{

}
void Play::Show_Reading()
{
	ifstream load;
	string str[READ];
	int i = 0, Read_Time = clock(), Contrast_Time;
	load.open("베네치아_스토리.txt");

	while (!load.eof())
	{
		Contrast_Time = clock();
		if (Contrast_Time - Read_Time > 1000)
		{
			if (i < READ)
			{
				getline(load, str[i]);
				m_Draw.DrawMidText(str[i], WIDTH, HEIGHT  * 0.2f + i);
				i++;
			}
			else
			{	 // 1에 있는 값들을 0으로 보내고 2에 있는걸 1로 보내고 하는 방식예외 설정 하시오 
				for (int j = 0; j < READ; j++)
				{
					if (j < READ - 1)
						str[j] = str[j + 1];
					else
						getline(load, str[i]);					
				}

			}

			Read_Time = Contrast_Time;
		}
	}
}
			   
void Play::Game_Main()
{
	m_Interface.Make_Box();
	while (1)
	{
		Main_Menu();
		switch (m_Draw.MenuSelectCursor(3,3 /* 메뉴 간의 거리  */,WIDTH / 2 - 8, HEIGHT * 0.4f /* 커서의 시작 위치  */))
		{
		case MENU_GAME_START:
			m_Draw.BoxErase(WIDTH, HEIGHT);//어떻게 해야 위에서 아래로 내려오게 적용을 할까....
			Show_Reading();
			Game_Play();
			break;
		case MENU_RANK:
			break;
		case MENU_GAME_EIXT:
			return;
		}
	}
} 

Play::~Play()
{
}
