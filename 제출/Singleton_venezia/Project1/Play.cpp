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

	WordManager::GetInstance()->Get_List();// �ܾ� �����͸� �� ���� ����.
	m_iStage_Socre = 1000;
}
										
void Play::Delete_Data()
{
	delete m_Player;
	WordManager::GetInstance()->Delete_List();
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
	while (m_Player->Life != 0 && m_Player->Stage < LAST_STAGE)
	{
		Interface::GetInstance()->Show_Information(m_Player->Life, m_Player->Score, m_Player->Name);
		WordManager::GetInstance()->Check_Stage(m_Player->Stage);
		Stage_Box();

		Game_Play();
		if (m_Player->Life != 0)
			Stage_up();
	}

	if (m_Player->Stage > LAST_STAGE)
		Interface::GetInstance()->Win_Text();
	else
		m_Draw.BoxDraw(0, 0, WIDTH, HEIGHT);

	Save_Game();
	Delete_Data();
}

void Play::Stage_up()
{
	m_Player->Stage++;
	m_iStage_Socre += 200;
	m_Player->Score = 0;
	WordManager::GetInstance()->Delete_Virus();
	Interface::GetInstance()->Erase_Input_Box();
}

void Play::Get_Score()
{
	int Plus_Score = rand() % 100 + 70; // 70 ������ 169 �� ������ ���� ȹ��
	m_Player->Score += Plus_Score;
	Interface::GetInstance()->Player_Score(m_Player->Score);
}

void Play::Game_Play()
{
	int Height_Location, Timer, Main_Time = clock();
	int Penalty_Time = 0;
	string Input_Word = "";
	bool Enter = false, Life_Check = false,Penalty_Check = true;
	Interface::GetInstance()->Input_Box();
	while (m_Player->Life != 0 && m_Player->Score <= m_iStage_Socre)
	{
		Timer = clock();

		if (kbhit() && Penalty_Check)
			Enter_Word(Input_Word, Enter);

		if (Enter && Penalty_Check)
		{
			if (!WordManager::GetInstance()->Chekcing_Word(Input_Word))// Ʋ������ �г�Ƽ
			{
				m_Draw.DrawMidText("                       ", WIDTH, HEIGHT * 0.7f + 3);
				RED					
				Input_Word = " Fail Compare !! "; 
				m_Draw.DrawMidText(Input_Word, WIDTH, HEIGHT * 0.7f + 3);
				ORIGINAL
					Penalty_Check = false;
				Penalty_Time = clock();
			}
			else
			{
				m_Draw.DrawMidText("                 ", WIDTH, HEIGHT * 0.7f + 3);
				Get_Score();
				Input_Word = "";
				m_Draw.DrawMidText(Input_Word, WIDTH, HEIGHT * 0.7f + 3);
			}
			Enter = false;
		} // ���� �� ����.

		if (!Penalty_Check && (Timer - Penalty_Time >= ONE_SEC * 3 ))
		{
			Penalty_Check = true;
			Input_Word = "";
			m_Draw.DrawMidText("                 ", WIDTH, HEIGHT * 0.7f + 3);
			Penalty_Time = 0;
		}
		if (WordManager::GetInstance()->Drop_Time_Control(m_Player->Stage, Main_Time, Timer, Life_Check))
		{
			WordManager::GetInstance()->Word_Drop();
			Interface::GetInstance()->Input_Box();

			if (!Penalty_Check)
				RED
			else
				BLUE
			m_Draw.DrawMidText(Input_Word, WIDTH, HEIGHT * 0.7f + 3);
			ORIGINAL
		}

		if (Life_Check)
		{
			m_Player->Life--;
			Interface::GetInstance()->Player_Life(m_Player->Life);
			Life_Check = false;
		}
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
	Interface::GetInstance()->Make_Box();
	while (1)
	{
		Interface::GetInstance()->Main_Menu();
		switch (m_Draw.MenuSelectCursor(3,3 /* �޴� ���� �Ÿ�  */,WIDTH / 2 - 8, HEIGHT * 0.4f /* Ŀ���� ���� ��ġ  */))
		{	
		case MENU_GAME_START:
			m_Draw.BoxErase(WIDTH, HEIGHT);

			Interface::GetInstance()->Show_Reading();
			Input_Data(Get_Name());
			Main_Play();
			break;
		case MENU_RANK:
			m_Rank.Rank_List();
			break;
		case MENU_GAME_EIXT:
			Interface::DeleteInstance();
			WordManager::DeleteInstance();
			return;
		}
	}
} 

Play::~Play()
{
}
