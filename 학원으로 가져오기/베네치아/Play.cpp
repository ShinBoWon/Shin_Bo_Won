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

	m_Player = Player_Data;	 // 플레이어 등록 완료  정도? 

	m_Manager.Get_List();   // 단어 데이터를 다 얻은 시점.
	m_iStage_Socre = 1000;
}

void Play::Main_Play()
{
	while (m_Player->Life != 0)
	{
		m_Draw.BoxErase(WIDTH, HEIGHT);
		string Stage = to_string(m_Player->Stage);
		m_Draw.DrawMidText("★ " + Stage + " Stage  ★", WIDTH, HEIGHT * 0.2f);
		Sleep(ONE_SEC * 1.5f);
		m_Draw.DrawMidText("                           ", WIDTH, HEIGHT * 0.2f);
		Game_Play();
	}
	Delete_Data();	
}

void Play::Game_Play()
{
	int Timer, Word_Make, SecTime = clock(), Fail_Time;
	string enter_word = "";
	m_Interface.Input_Box();
	while (m_Player->Life != 0 && m_Player->Score <= ONE_SEC * 1.5f )
	{
		Timer = clock();
		Fail_Time = clock();
		if (Timer - SecTime >= ONE_SEC)
		{ // 1초마다 단어가 한칸씩 내려오고 
			// 단어가 하나씩 생겨 야함 클리어 
			if (Word_Make = rand() % 3 == 0)
				m_Manager.Get_Attack_Word();

			m_Manager.Word_Move_Down();
			m_Interface.Input_Box();
			BLUE
			m_Draw.DrawMidText(enter_word, WIDTH, HEIGHT * 0.7f + 3);
			ORIGINAL
			SecTime = Timer;
		}
		if (kbhit())
			Word_Check(SecTime, Fail_Time, enter_word);
		
	}
}

string Play::Get_Name()
{
	char Name_Ward;
	string Name;  // string 이 아닌 Char[] 로 해야 할거 같음
	BLUE
		m_Draw.DrawMidText("                   ", WIDTH, HEIGHT* 0.7f + 3);
	m_Draw.DrawMidText("이름을 입력 하세요", WIDTH, HEIGHT * 0.6f);
	m_Draw.DrawMidText("", WIDTH, HEIGHT * 0.7f + 3);
	while (Name.length() < 10)
	{
		Name_Ward = getch();
		if (Name_Ward == 13)
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

void Play::Word_Check(int &Time, int Fail_Time, string &enter_word)
{
	char word = NULL;
	
	bool Checking = true;

	if (enter_word.length() <= MAX_WORD && Checking ) // 그 확인 도 해보자 씨플.
	{
		word = getch();
		BLUE
			m_Draw.DrawMidText("                   ", WIDTH, HEIGHT * 0.7f + 3);
		m_Draw.DrawMidText(enter_word, WIDTH, HEIGHT * 0.7f + 3);
		ORIGINAL
 		if (word == 13 && enter_word.length() >= 1)
		{
			if (!m_Manager.Eating_Word(enter_word))
			{
				Checking = false;
				RED
				m_Draw.DrawMidText("                   ", WIDTH, HEIGHT * 0.7f + 3);
				m_Draw.DrawMidText(" Fail Compare !! ", WIDTH, HEIGHT * 0.7f + 3);
				ORIGINAL
			}
			enter_word = "";
		}
		else if (word == 8 && enter_word.length() > 0 )
			enter_word.pop_back();
		else if (word != 13 && word != 8)
			enter_word += word;		
	}
	else 
	{
		if (Fail_Time - Time >= ONE_SEC * 4)
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
		switch (m_Draw.MenuSelectCursor(3,3 /* 메뉴 간의 거리  */,WIDTH / 2 - 8, HEIGHT * 0.4f /* 커서의 시작 위치  */))
		{
		case MENU_GAME_START:
			m_Draw.BoxErase(WIDTH, HEIGHT);
			m_Interface.Show_Reading();
			Input_Data(Get_Name());
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
