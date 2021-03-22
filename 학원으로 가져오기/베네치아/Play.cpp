#include "Play.h"

Play::Play()
{

}

void Play::Stage_Box() // �������̽��� 
{
	m_Draw.BoxErase(WIDTH, HEIGHT);
	string Stage = to_string(m_Player->Stage);
	m_Draw.DrawMidText("�� " + Stage + " Stage  ��", WIDTH, HEIGHT * 0.2f);
	Sleep(ONE_SEC * 1.5f);
	m_Draw.DrawMidText("                           ", WIDTH, HEIGHT * 0.2f);
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
										
void Play::Delete_Data()
{
	delete m_Player;
	m_Manager.Delete_List();
}

void Play::Save_Game()
{
	ofstream save;
	save.open("Rank.txt", ios::app);
	if (save.is_open())
	{
		save << endl;
		save << m_Player->Name << " " << m_Player->Stage << " " << m_Player->Score;
		save.close();
	}
}

void Play::Main_Play()
{
	while (m_Player->Life != 0)
	{
		m_Interface.Show_Information(m_Player->Life, m_Player->Score, m_Player->Name);
		Stage_Box();

		Game_Play();
		if (m_Player->Life != 0)
			Stage_up();
	}

	Save_Game();
	Delete_Data();
}

void Play::Stage_up()
{
	m_Player->Stage++;
	m_iStage_Socre += 200;
	m_Player->Score = 0;
	m_Manager.Delete_Virus();
	m_Interface.Erase_Input_Box();
}

void Play::Get_Score()
{
	int Plus_Score = rand() % 100 + 70; // 70 ������ 169 �� ������ ���� ȹ��
	m_Player->Score += Plus_Score;
}

void Play::Game_Play()
{
	int  Timer, Main_Time = clock();
	string Input_Word = "";
	bool Enter = false;
	m_Interface.Input_Box();

	while (m_Player->Life != 0 && m_Player->Score <= m_iStage_Socre)
	{
		Timer = clock();

		if (kbhit() && !Enter) // �г�Ƽ �ֱ�
			Enter_Word(Input_Word, Enter);

		if (Enter)
		{
			if (!m_Manager.Chekcing_Word(Input_Word)) // Ʋ������ �г�Ƽ
			{
				RED
					m_Draw.DrawMidText("               ", WIDTH, HEIGHT * 0.7f + 3);
				Input_Word = " Fail Compare !! "; 
				m_Draw.DrawMidText(Input_Word, WIDTH, HEIGHT * 0.7f + 3);
				ORIGINAL
			}
			else
			{
				Get_Score();
				Input_Word = "";
			}
			Enter = false;
		} // ���� �� ����.


		m_Manager.Drop_Time_Control(m_Player->Stage,m_Player->Life, Main_Time,Timer);

	}
}

void Play::Enter_Word(string & enter_word , bool  & Enter)
{
	char word = NULL;
	bool Checking = true; // ���� �ִ� .�ƹ��� �����ٰ� �ص� Checking ���� true �� �ٲ�� ������ main_Play ���� �����ϴ°� �� ����

	if (enter_word.length() <= MAX_WORD && Checking) // �� Ȯ�� �� �غ��� ����.
	{
		word = getch();
		if (word == 13 && enter_word.length() >= 1)
			Enter = true;
		else if (word == 8 && enter_word.length() > 0)
			enter_word.pop_back();
		else if (word >= 'a' && word <= 'z')
			enter_word += word;
		BLUE
		m_Draw.DrawMidText("                   ", WIDTH, HEIGHT * 0.7f + 3);
		m_Draw.DrawMidText(enter_word, WIDTH, HEIGHT * 0.7f + 3);
		ORIGINAL
	}
}

string Play::Get_Name()
{
	char Name_Ward;
	string Name; 

	BLUE
		m_Draw.DrawMidText("                   ", WIDTH, HEIGHT* 0.7f + 3);
	m_Draw.DrawMidText("�̸��� �Է� �ϼ���", WIDTH, HEIGHT * 0.6f);
	m_Draw.DrawMidText("", WIDTH, HEIGHT * 0.7f + 3);
	while (Name.length() < 10)
	{
		Name_Ward = getch();
		if (Name_Ward == 13 && Name != "")
			break;
		else if (Name_Ward == 8 && Name.length() > 0)
			Name.pop_back();
		else if (Name_Ward >= 'a' && Name_Ward <= 'z')
			Name += Name_Ward;		

		m_Draw.DrawMidText("                   ", WIDTH, HEIGHT * 0.7f + 3);
		m_Draw.DrawMidText(Name, WIDTH, HEIGHT * 0.7f + 3);

	}
	if (Name.length() == 10)
	{
		m_Draw.DrawMidText("10���� �Է� �ʰ�!!", WIDTH, HEIGHT * 0.6f + 1);
		char skip = getch();
	}
	ORIGINAL
		return Name;
}
			   
void Play::Main()
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
			Input_Data(Get_Name());
			Main_Play();
			break;
		case MENU_RANK:
			m_Rank.Rank_List();
			break;
		case MENU_GAME_EIXT:
			return;
		}
	}
} 

Play::~Play()
{
}
