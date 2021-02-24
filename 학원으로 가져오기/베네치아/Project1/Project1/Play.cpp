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

void Play::Input_Player_Data()
{
	
	char Name[10];	  // string �� �ƴ� Char[] �� �ؾ� �Ұ� ����.
	int Name_Length = 0;
	Player *Attend_Player;
	Attend_Player = new Player;
	BLUE
		m_Draw.DrawMidText("                   " , WIDTH,HEIGHT* 0.7f + 3);
		m_Draw.DrawMidText("�̸��� �Է� �ϼ���", WIDTH, HEIGHT * 0.6f );
	m_Draw.DrawMidText("", WIDTH, HEIGHT * 0.7f + 3);
	while (Name_Length < 10)
	{
		Name[Name_Length] = getch();
		if (Name[Name_Length] == 13)
			break;
		m_Draw.DrawMidText("                   ", WIDTH, HEIGHT* 0.7f + 3);
		m_Draw.DrawMidText(Name, WIDTH, HEIGHT* 0.7f + 3);
		
		Name_Length++;		
	}
	if (Name_Length == 10)
	{
		m_Draw.DrawMidText("10���� �Է� �ʰ�!!", WIDTH, HEIGHT * 0.6f + 1);
		char skip = getch();
	}
	ORIGINAL

		system("pause");
	
}

void Play::Game_Play()
{
	
}
void Play::Show_Reading()
{
	ifstream load;
	string str[READ];
	char Skip = NULL;
	int i = 0, Read_Time = clock(), Contrast_Time;
	load.open("����ġ��_���丮.txt");
	m_Draw.BoxDraw(WIDTH , HEIGHT * 0.7f , 20 , 7);	 // Skip�Ǵ� Name �Է� �ڽ�
	m_Draw.DrawMidText("Skip : s", WIDTH, HEIGHT * 0.7f + 3);

	while (!load.eof() && Skip != SKIP )
	{
		if (kbhit())
			Skip = getch();

		Contrast_Time = clock();
		if (Contrast_Time - Read_Time > 1000)
		{
			if (i < READ)
			{
				getline(load, str[i]);
				BLUE
					m_Draw.DrawMidText(str[i], WIDTH, HEIGHT  * 0.2f + i);
				ORIGINAL
					i++;
			}
			else
			{	 // 1�� �ִ� ������ 0���� ������ 2�� �ִ°� 1�� ������ �ϴ� ��Ŀ��� ���� �Ͻÿ� 
				for (int j = 0; j < READ; j++)
					m_Draw.DrawMidText("                                                           ", WIDTH, HEIGHT * 0.2f + j);

				for (int j = 0; j < READ; j++)
				{
					if (j < READ - 1)
						str[j] = str[j + 1];
					else
						getline(load, str[i - 1]);
				}

				for (int j = 0; j < READ; j++)
				{
					BLUE
						m_Draw.DrawMidText(str[j], WIDTH, HEIGHT  * 0.2f + j);
					ORIGINAL
				}

			}

			Read_Time = Contrast_Time;
		}
	}
	for (int j = 0; j < READ; j++)
		m_Draw.DrawMidText("                                                           ", WIDTH, HEIGHT * 0.2f + j);
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
			Input_Player_Data();
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
