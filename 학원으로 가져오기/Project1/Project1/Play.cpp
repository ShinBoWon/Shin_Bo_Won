#include "Play.h"

Play::Play()
{

}

void Play::Main_Menu()
{
	m_Draw.BoxErase(WIDTH, HEIGHT);
	YELLOW
	m_Draw.DrawMidText("�١� ����ġ�� �ڡ�", WIDTH, HEIGHT * 0.2f);
	m_Draw.DrawMidText("1. Game Start", WIDTH - 1, HEIGHT * 0.4f);
	m_Draw.DrawMidText("2. Rank", WIDTH - 1, HEIGHT * 0.4f + 3 );
	m_Draw.DrawMidText("3. Exit", WIDTH - 1, HEIGHT * 0.4f + 6 );
	ORIGINAL
	//Life �� score Name �� ���� ������ �α�
}

void Play::Game_Play()
{

}
void Play::Show_Reading()
{
	ifstream load;
	string str[READ];
	int i = 0, Read_Time = clock(), Contrast_Time;
	load.open("����ġ��_���丮.txt");

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
			{	 // 1�� �ִ� ������ 0���� ������ 2�� �ִ°� 1�� ������ �ϴ� ��Ŀ��� ���� �Ͻÿ� 
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
		switch (m_Draw.MenuSelectCursor(3,3 /* �޴� ���� �Ÿ�  */,WIDTH / 2 - 8, HEIGHT * 0.4f /* Ŀ���� ���� ��ġ  */))
		{
		case MENU_GAME_START:
			m_Draw.BoxErase(WIDTH, HEIGHT);//��� �ؾ� ������ �Ʒ��� �������� ������ �ұ�....
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
