#include "Interface.h"

Interface::Interface()
{
	srand(time(NULL)); // ���� �ð� ����

	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", HEIGHT + 5, WIDTH * 2); // �ڽ� ũ�� ����
	system(buf);
}

void Interface::Win_Text()
{
	int i = 0, Time = clock(), Sec_Time;
	char enter;
	m_Draw.BoxDraw(0, 0, WIDTH, HEIGHT);

	while (1)
	{
		Sec_Time = clock();
		if (Sec_Time - Time >= ONE_SEC)
		{
			if (i == 0)
			{
				RED
					i++;
				m_Draw.DrawMidText("�ڡ١ڡ١ڡ�", WIDTH * 0.5f, HEIGHT * 0.5f);
				m_Draw.DrawMidText("�ڡ١ڡ١ڡ�", WIDTH * 1.5f, HEIGHT * 0.5f);
			}
			else
			{
				BLUE
					i--;
				m_Draw.DrawMidText("�١ڡ١ڡ١�", WIDTH * 0.5f, HEIGHT * 0.5f);
				m_Draw.DrawMidText("�١ڡ١ڡ١�", WIDTH * 1.5f, HEIGHT * 0.5f);
			}
			m_Draw.DrawMidText(" W i n ", WIDTH, HEIGHT * 0.5f);
			m_Draw.DrawMidText("Press 'Enter' Over_Game ", WIDTH, HEIGHT * 0.75f);
			Time = Sec_Time;
		}
		if (kbhit())
		{
			enter = getch();
			if (enter == 13)
				break;
		}
	}
	ORIGINAL
		m_Draw.DrawMidText("                        ", WIDTH, HEIGHT * 0.75f);
		m_Draw.DrawMidText("       ", WIDTH, HEIGHT * 0.5f);
	m_Draw.DrawMidText("            ", WIDTH * 0.5f, HEIGHT * 0.5f);
	m_Draw.DrawMidText("            ", WIDTH * 1.5f, HEIGHT * 0.5f);
}

void Interface::Input_Box()
{
	BLUE
	m_Draw.BoxDraw(WIDTH, HEIGHT * 0.7f, 20, INPUT_BOX);	 // Skip�Ǵ� Name �Է� �ڽ� + �ܾ� �Է� �ڽ�
	ORIGINAL
}

void Interface::Erase_Input_Box()
{
	for (int i = 0; i <= INPUT_BOX; i++)
		m_Draw.DrawMidText("                            ", WIDTH, HEIGHT * 0.7f + i);
}

void Interface::Make_Box()
{
	GREEN
		m_Draw.BoxDraw(0, 0, WIDTH, HEIGHT);
	ORIGINAL
}

void Interface::Show_Reading()
{
	ifstream load;
	string str[READ];
	char Skip = NULL;
	int i = 0, Contrast_Time, Read_Time = clock();

	Input_Box();
	m_Draw.DrawMidText("Skip : s", WIDTH, HEIGHT * 0.7f + 3);

	load.open("����ġ��_���丮.txt");	

	while (!load.eof() && Skip != SKIP)
	{
		if (kbhit())
			Skip = getch();

		Contrast_Time = clock();
		if (Contrast_Time - Read_Time > ONE_SEC)
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
		m_Draw.DrawMidText("                                              ", WIDTH, HEIGHT * 0.2f + j);
}

void Interface::Player_Life(int Life)
{
	m_Draw.DrawMidText("                                        ", 0, HEIGHT + 2);

	m_Draw.DrawMidText("Life : ", 0, HEIGHT + 2);
	for (int i = 0; i < Life; i++)
		cout << "��";
}

void Interface::Player_Score(int Score)
{
	m_Draw.DrawMidText("                      ", WIDTH, HEIGHT + 2);
	
	m_Draw.DrawMidText("Score : ", WIDTH, HEIGHT + 2);
	cout << Score;
}

void Interface::Show_Information(int Life, int Score, string Name)
{
	// ���ʴ�� DrawMidText ( �ǿ��� �߰� �� ������ )
	m_Draw.DrawMidText("                                        ", 0, HEIGHT + 2);
	m_Draw.DrawMidText("                      ", WIDTH, HEIGHT + 2);
	m_Draw.DrawMidText("                            ", WIDTH * 2 - 20, HEIGHT + 2 );

	m_Draw.DrawMidText("Life : ", 0, HEIGHT + 2);
	for (int i = 0; i < Life; i++)
		cout << "��";
	m_Draw.DrawMidText("Score : ", WIDTH, HEIGHT + 2);
	cout << Score;
	m_Draw.DrawMidText("Name : ", WIDTH * 2 - 20, HEIGHT + 2 );
	cout << Name;
}

void Interface::Main_Menu()
{
	YELLOW
		m_Draw.DrawMidText("�١� ����ġ�� �ڡ�", WIDTH, HEIGHT * 0.2f);
	m_Draw.DrawMidText("1. Game Start", WIDTH - 1, HEIGHT * 0.4f);
	m_Draw.DrawMidText("2. Rank", WIDTH - 1, HEIGHT * 0.4f + 3);
	m_Draw.DrawMidText("3. Exit", WIDTH - 1, HEIGHT * 0.4f + 6);
	ORIGINAL

	Show_Information(START_LIFE ,0," ? ? ? ");
}	  

void Interface::Erase_Main_Menu()
{
	m_Draw.DrawMidText("                                        ", WIDTH, HEIGHT * 0.2f);
	m_Draw.DrawMidText("                                          ", WIDTH - 1, HEIGHT * 0.4f);
	m_Draw.DrawMidText("                                        ", WIDTH - 1, HEIGHT * 0.4f + 3);
	m_Draw.DrawMidText("                                         ", WIDTH - 1, HEIGHT * 0.4f + 6);
}



Interface::~Interface()
{
}
