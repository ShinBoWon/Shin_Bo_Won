#include "Play.h"

Play::Play()
{

}

void Play::Input_Data(string Name)
{
	Player *Player_Data;
	Player_Data = new Player;

	Player_Data->Name = Name;
	Player_Data->Score = 0;
	Player_Data->Stage = 1;
	Player_Data->Life = START_LIFE;

	m_Player = Player_Data;	 // �÷��̾� ��� �Ϸ�  ����? 

	m_Manager.Get_List();   // �ܾ� �����͸� �� ���� ����.
	m_iStage_Socre = 1000;
}

void Play::Main_Play()
{
	while (m_Player->Life != 0)
	{
		m_Draw.BoxErase(WIDTH, HEIGHT);
		string Stage = to_string(m_Player->Stage);
		m_Draw.DrawMidText("�� " + Stage + " Stage  ��", WIDTH, HEIGHT * 0.2f);
		Sleep(ONE_SEC * 1.5f);
		m_Draw.DrawMidText("                           ", WIDTH, HEIGHT * 0.2f);
		Game_Play();
		/*
		if (m_Player->Score <= m_iStage_Socre)
		{
			m_iStage_Socre += SCORE_UP;
		}*/
	}
	Delete_Data();	
}

void Play::Game_Play()
{
	int Timer, Word_Make, SecTime = clock(), Fail_Time;
	string enter_word;
	m_Interface.Input_Box();
	while (m_Player->Life != 0 && m_Player->Score <= ONE_SEC * 1.5f )
	{
		Timer = clock();
		Fail_Time = clock();
		if (Timer - SecTime >= ONE_SEC)
		{ // 1�ʸ��� �ܾ ��ĭ�� �������� 
			// �ܾ �ϳ��� ���� ���� Ŭ���� 
			if (Word_Make = rand() % 3 == 0)
				m_Manager.Get_Attack_Word();

			m_Manager.Word_Move_Down();
			m_Interface.Input_Box();
			SecTime = Timer;
		}
		Word_Check(SecTime,Fail_Time ,enter_word);
	}
}

void Play::Word_Check(int &Time, int Fail_Time, string &enter_word)
{
	char word = NULL;
	
	bool Checking = true;

	if (enter_word.length() < MAX_WORD && Checking ) // �� Ȯ�� �� �غ��� ����.
	{
		if (kbhit())
		{
			word = getch();
			enter_word += word;
			BLUE
			m_Draw.DrawMidText("                   ", WIDTH, HEIGHT * 0.7f + 3);
			m_Draw.DrawMidText(enter_word, WIDTH, HEIGHT * 0.7f + 3);
			ORIGINAL
			if (word == 13)
			{
				if (!m_Manager.Eating_Word(enter_word))
				{
					Checking = false;
					RED
					m_Draw.DrawMidText("                   ", WIDTH, HEIGHT * 0.7f + 3);
					m_Draw.DrawMidText(" Fail Compare !! ", WIDTH, HEIGHT * 0.7f + 3);
					ORIGINAL
				}
			}
		}		
		
		
	}
	else 
	{
		if (Fail_Time - Time >= ONE_SEC)
		{
			Checking = true;
			Time = Fail_Time;
		}
	}

}

void Play::Delete_Data()
{
	delete m_Player;
	m_Manager.Delete_List();
}
			   
void Play::Game_Main()
{
	m_Interface.Make_Box();
	while (1)
	{
		m_Interface.Main_Menu();
		switch (m_Draw.MenuSelectCursor(3,3 /* �޴� ���� �Ÿ�  */,WIDTH / 2 - 8, HEIGHT * 0.4f /* Ŀ���� ���� ��ġ  */))
		{
		case MENU_GAME_START:
			m_Draw.BoxErase(WIDTH, HEIGHT);
			m_Interface.Show_Reading();
			Input_Data(m_Interface.Player_Name());
			Main_Play();
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
