#include "Interface.h"

Interface::Interface()
{
	srand(time(NULL)); // 렌덤 시간 조절

	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", HEIGHT + 5, WIDTH * 2); // 박스 크기 조절
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
				m_Draw.DrawMidText("★☆★☆★☆", WIDTH * 0.5f, HEIGHT * 0.5f);
				m_Draw.DrawMidText("★☆★☆★☆", WIDTH * 1.5f, HEIGHT * 0.5f);
			}
			else
			{
				BLUE
					i--;
				m_Draw.DrawMidText("☆★☆★☆★", WIDTH * 0.5f, HEIGHT * 0.5f);
				m_Draw.DrawMidText("☆★☆★☆★", WIDTH * 1.5f, HEIGHT * 0.5f);
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
	m_Draw.BoxDraw(WIDTH, HEIGHT * 0.7f, 20, INPUT_BOX);	 // Skip또는 Name 입력 박스 + 단어 입력 박스
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

	load.open("베네치아_스토리.txt");	

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
			{	 // 1에 있는 값들을 0으로 보내고 2에 있는걸 1로 보내고 하는 방식예외 설정 하시오 
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
		cout << "♥";
}

void Interface::Player_Score(int Score)
{
	m_Draw.DrawMidText("                      ", WIDTH, HEIGHT + 2);
	
	m_Draw.DrawMidText("Score : ", WIDTH, HEIGHT + 2);
	cout << Score;
}

void Interface::Show_Information(int Life, int Score, string Name)
{
	// 차례대로 DrawMidText ( 맨왼쪽 중간 맨 오른쪽 )
	m_Draw.DrawMidText("                                        ", 0, HEIGHT + 2);
	m_Draw.DrawMidText("                      ", WIDTH, HEIGHT + 2);
	m_Draw.DrawMidText("                            ", WIDTH * 2 - 20, HEIGHT + 2 );

	m_Draw.DrawMidText("Life : ", 0, HEIGHT + 2);
	for (int i = 0; i < Life; i++)
		cout << "♥";
	m_Draw.DrawMidText("Score : ", WIDTH, HEIGHT + 2);
	cout << Score;
	m_Draw.DrawMidText("Name : ", WIDTH * 2 - 20, HEIGHT + 2 );
	cout << Name;
}

void Interface::Main_Menu()
{
	YELLOW
		m_Draw.DrawMidText("☆★ 베네치아 ★☆", WIDTH, HEIGHT * 0.2f);
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
