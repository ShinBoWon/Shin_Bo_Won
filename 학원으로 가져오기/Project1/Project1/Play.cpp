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
}

void Play::Game_Play()
{
	int Timer, SecTime = clock(), Word_Make, fail_Time = clock();
	m_Draw.BoxErase(WIDTH, HEIGHT);
	while (m_Player->Life != 0 )
	{
		Timer = clock();
		if (Timer - SecTime >= 1000)
		{ // 1초마다 단어가 한칸씩 내려오고 
			// 단어가 하나씩 생겨 야함 클리어 
			if (Word_Make = rand() % 3 == 0)
				m_Manager.Get_Attack_Word();

			m_Manager.Word_Move_Down();
			m_Interface.Input_Box();
			SecTime = Timer;
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
			Input_Data(m_Interface.Player_Name());
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
