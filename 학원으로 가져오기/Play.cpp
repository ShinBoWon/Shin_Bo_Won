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

void Play::Name_Check()
{	
	char Name_Ward;
	string Name;	  // string �� �ƴ� Char[] �� �ؾ� �Ұ� ����.
	int Name_Length = 0;
	BLUE
	m_Draw.DrawMidText("                   " , WIDTH,HEIGHT* 0.7f + 3);
	m_Draw.DrawMidText("�̸��� �Է� �ϼ���", WIDTH, HEIGHT * 0.6f );
	m_Draw.DrawMidText("", WIDTH, HEIGHT * 0.7f + 3);
	while (Name_Length < 10)
	{
		Name_Ward = getch();
		Name += Name_Ward;
		m_Draw.DrawMidText("                   ", WIDTH, HEIGHT * 0.7f + 3);
		m_Draw.DrawMidText(Name, WIDTH, HEIGHT * 0.7f + 3);
		if (Name_Ward == 13)
			break;
		Name_Length++;
	}
	if (Name_Length == 10)
	{
		m_Draw.DrawMidText("10���� �Է� �ʰ�!!", WIDTH, HEIGHT * 0.6f + 1);
		char skip = getch();
	}
	ORIGINAL
	Player_Input_Data(Name);
	
}

void Play::Player_Input_Data(string Name)
{
	Player *Player_Data;
	Player_Data = new Player;

	Player_Data->Name = Name;
	Player_Data->Score = 0;
	Player_Data->Stage = 1;

	m_Player = Player_Data;
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
			Name_Check();
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
