#include "Interface.h"

Interface::Interface()
{
	srand(time(NULL)); // ���� �ð� ����

	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", HEIGHT + 5, WIDTH * 2); // �ڽ� ũ�� ����
	system(buf);
}

void Interface::Show_Reading()
{
	ifstream load;
	string str[READ];
	char Skip = NULL;
	int i = 0, Read_Time = clock(), Contrast_Time;
	load.open("����ġ��_���丮.txt");
	m_Draw.BoxDraw(WIDTH, HEIGHT * 0.7f, 20, 7);	 // Skip�Ǵ� Name �Է� �ڽ�
	m_Draw.DrawMidText("Skip : s", WIDTH, HEIGHT * 0.7f + 3);

	while (!load.eof() && Skip != SKIP)
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

void Interface::Make_Box()
{
	GREEN
	m_Draw.BoxDraw(0, 0, WIDTH, HEIGHT);
	ORIGINAL
}

void Interface::Show_Information(int Life, int Score, string Name)
{
	// ���ʴ�� DrawMidText ( �ǿ��� �߰� �� ������ )
	m_Draw.DrawPoint("Life : ", 0, HEIGHT + 2);
	for (int i = 0; i < Life; i++)
		cout << "��";
	m_Draw.DrawMidText("Score : ", WIDTH, HEIGHT);
	cout << Score;
	m_Draw.DrawMidText("Name : ", WIDTH, HEIGHT);
	cout << Name;
}
string Interface::Player_Name()
{
	char Name_Ward;
	string Name;	  // string �� �ƴ� Char[] �� �ؾ� �Ұ� ����.
	int Name_Length = 0;
	BLUE
		m_Draw.DrawMidText("                   ", WIDTH, HEIGHT* 0.7f + 3);
	m_Draw.DrawMidText("�̸��� �Է� �ϼ���", WIDTH, HEIGHT * 0.6f);
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

	return Name;
}

void Interface::Show_Inforamtion_Main()
{
	m_Draw.DrawMidText("Life : ", 0, HEIGHT + 2);
	for (int i = 0; i < START_LIFE; i++)
		cout << "��";
	m_Draw.DrawMidText("Score : 0", WIDTH, HEIGHT + 2);
	m_Draw.DrawMidText("Name : ? ? ? ", WIDTH * 2 - 10, HEIGHT + 2);
}

void Interface::Main_Menu()
{
	m_Draw.BoxErase(WIDTH, HEIGHT);
	YELLOW
		m_Draw.DrawMidText("�١� ����ġ�� �ڡ�", WIDTH, HEIGHT * 0.2f);
	m_Draw.DrawMidText("1. Game Start", WIDTH - 1, HEIGHT * 0.4f);
	m_Draw.DrawMidText("2. Rank", WIDTH - 1, HEIGHT * 0.4f + 3);
	m_Draw.DrawMidText("3. Exit", WIDTH - 1, HEIGHT * 0.4f + 6);
	ORIGINAL

	Show_Inforamtion_Main();
}	  

Interface::~Interface()
{
}
