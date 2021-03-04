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
}

void Play::Game_Play()
{
	int Timer, SecTime = clock(), int Word_Make;
	while (m_Player->Life != 0 )
	{
		Timer = clock();
		if (Timer - SecTime >= 1500)
		{ // 1.5�ʸ��� �ܾ ��ĭ�� �������� 
			// �ܾ �ϳ��� ���� ����
			if (Word_Make = rand() % 3 == 0)
				m_Manager.Get_Attack_Word();
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
		switch (m_Draw.MenuSelectCursor(3,3 /* �޴� ���� �Ÿ�  */,WIDTH / 2 - 8, HEIGHT * 0.4f /* Ŀ���� ���� ��ġ  */))
		{
		case MENU_GAME_START:
			m_Draw.BoxErase(WIDTH, HEIGHT);//��� �ؾ� ������ �Ʒ��� �������� ������ �ұ�....
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
