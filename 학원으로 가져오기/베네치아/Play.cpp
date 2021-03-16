#include "Play.h"

Play::Play()
{

}

void Play::Stage_Box()
{
	m_Draw.BoxErase(WIDTH, HEIGHT);
	string Stage = to_string(m_Player->Stage);
	m_Draw.DrawMidText("★ " + Stage + " Stage  ★", WIDTH, HEIGHT * 0.2f);
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

	m_Player = Player_Data;	 // 플레이어 등록 완료  정도? 

	m_Manager.Get_List();   // 단어 데이터를 다 얻은 시점.
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
	m_iStage_Socre += 200;
	m_Player->Score = 0;
	m_Manager.Delete_Virus();
	m_Interface.Erase_Input_Box();
}

void Play::Game_Play()
{
	int Timer,Penalty_Time, Word_Make, SecTime = clock(), Fail_Time = clock();
	string enter_word = "";

	bool Word_Enter_Penalty = true;

	m_Interface.Input_Box();
	while (m_Player->Life != 0 && m_Player->Score <= m_iStage_Socre)
	{
		Timer = clock();
		if (Timer - SecTime > ONE_SEC * 0.5f ) // 1초 
		{
			// 단어가 하나씩 생겨 야함 클리어 
			if (Word_Make = rand() % 3 == 0) // 존나 피곤하네
				m_Manager.Get_Attack_Word();

			if (!m_Manager.Hit_Damage())
			{
				m_Player->Life--;
				m_Interface.Playing_Information(m_Player->Life, m_Player->Score);
			}

			m_Interface.Input_Box();

			if (Word_Enter_Penalty)
			{
				BLUE
					m_Draw.DrawMidText(enter_word, WIDTH, HEIGHT * 0.7f + 3);
				ORIGINAL
			}
			else
			{
				RED
					m_Draw.DrawMidText(enter_word, WIDTH, HEIGHT * 0.7f + 3);
				ORIGINAL
			}
			SecTime = Timer; // 시간 관리
		}

		if (!Word_Enter_Penalty)
		{
			Penalty_Time = clock();
			if (Penalty_Time - Fail_Time > ONE_SEC * 3)
			{
				Word_Enter_Penalty = true;
				enter_word = "";
				SecTime = Penalty_Time;
			}
		}

		if (Word_Enter_Penalty)
		{
			if (kbhit()) // kbhit 는 주변의 진행 영향을 크게 주지는 않지만
			{
				if (!Word_Input(enter_word))  // word_input 함수는 getch 함수 덕분에 주변 진행에 영향을 주어서 진행 속도를 더디게 한다.
				{
					Input_Result(enter_word, Word_Enter_Penalty);
				}
			}
		}
	}
}

void Play::Input_Result(string &enter_word , bool &Word_Enter_Penalty)
{
	if (m_Manager.Eating_Word(enter_word)) // 먹은거 확인 했을때 
	{ // 성공시
		int Plus_Score = rand() % 100 + 70; // 70 점에서 169 점 사이의 점수 획듯
		m_Player->Score += Plus_Score;
		if (m_Player->Score >= m_iStage_Socre)
			m_Player->Stage++;
		enter_word = "";
		m_Interface.Playing_Information(m_Player->Life, m_Player->Score);
	}
	else
	{
		enter_word = " Fail Compare !! ";
		RED
			m_Draw.DrawMidText("                   ", WIDTH, HEIGHT * 0.7f + 3);
		m_Draw.DrawMidText(enter_word, WIDTH, HEIGHT * 0.7f + 3);
		ORIGINAL
			Word_Enter_Penalty = false;
	}
}


bool Play::Word_Input(string& enter_word) // 단어 적는거 
{
	char word = NULL;

	if (enter_word.length() <= MAX_WORD) // 그 확인 도 해보자 씨플.
	{
		word = getch();
		BLUE
			m_Draw.DrawMidText("                   ", WIDTH, HEIGHT * 0.7f + 3);
		m_Draw.DrawMidText(enter_word, WIDTH, HEIGHT * 0.7f + 3);
		ORIGINAL
			if (word == 13 && enter_word.length() >= 1)
				return false;
			else if (word == 8 && enter_word.length() > 0)
				enter_word.pop_back();
			else if (word != 13 && word != 8)
				enter_word += word;
	}

	return true;
}

string Play::Get_Name()
{
	char Name_Ward;
	string Name; 

	BLUE
		m_Draw.DrawMidText("                   ", WIDTH, HEIGHT* 0.7f + 3);
	m_Draw.DrawMidText("이름을 입력 하세요", WIDTH, HEIGHT * 0.6f);
	m_Draw.DrawMidText("", WIDTH, HEIGHT * 0.7f + 3);
	while (Name.length() < 10)
	{
		Name_Ward = getch();
		if (Name_Ward == 13 && Name != "")
			break;
		else if (Name_Ward == 8 && Name.length() > 0)
			Name.pop_back();
		else if (Name_Ward != 13 && Name_Ward != 8)
			Name += Name_Ward;		

		m_Draw.DrawMidText("                   ", WIDTH, HEIGHT * 0.7f + 3);
		m_Draw.DrawMidText(Name, WIDTH, HEIGHT * 0.7f + 3);

	}
	if (Name.length() == 10)
	{
		m_Draw.DrawMidText("10글자 입력 초과!!", WIDTH, HEIGHT * 0.6f + 1);
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
		switch (m_Draw.MenuSelectCursor(3,3 /* 메뉴 간의 거리  */,WIDTH / 2 - 8, HEIGHT * 0.4f /* 커서의 시작 위치  */))
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
