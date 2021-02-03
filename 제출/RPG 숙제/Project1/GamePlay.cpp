#include "GamePlay.h"

GamePlay::GamePlay()
{
	srand(time(NULL)); // 렌덤 시간 조절

	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d" ,  HEIGHT + 1 , WIDTH * 2); // 박스 크기 조절
	system(buf);
	
}

void GamePlay::Play_Menu()
{
	m_Draw.BoxErase(WIDTH, HEIGHT);
	m_Draw.DrawMidText("☆★ Menu ☆★", WIDTH, HEIGHT * 0.2f);
	m_Draw.DrawMidText("Dongeon", WIDTH, HEIGHT * 0.3f);
	m_Draw.DrawMidText("Player Info", WIDTH, HEIGHT * 0.4f);
	m_Draw.DrawMidText("Monster Info", WIDTH, HEIGHT * 0.5f);
	m_Draw.DrawMidText("Weapon Shop", WIDTH, HEIGHT * 0.6f);
	m_Draw.DrawMidText("Save", WIDTH, HEIGHT * 0.7f);
	m_Draw.DrawMidText("Exit", WIDTH, HEIGHT * 0.8f);
}


void GamePlay::Weapon_List()
{
	m_Draw.BoxErase(WIDTH, HEIGHT);
	m_Draw.DrawMidText("☆★ S H O P ☆★", WIDTH, HEIGHT * 0.1f);
	m_Draw.DrawMidText("Dagger", WIDTH, HEIGHT * 0.2f);
	m_Draw.DrawMidText("Gun", WIDTH, HEIGHT * 0.3f);
	m_Draw.DrawMidText("Sword", WIDTH, HEIGHT * 0.4f);
	m_Draw.DrawMidText("Wand", WIDTH, HEIGHT * 0.5f);
	m_Draw.DrawMidText("Bow", WIDTH, HEIGHT * 0.6f);
	m_Draw.DrawMidText("Hammer", WIDTH, HEIGHT * 0.7f);
	m_Draw.DrawMidText("돌아가기", WIDTH, HEIGHT * 0.8f);

}

void GamePlay::Dongeon_Menu(int Height)
{
	m_Draw.BoxErase(WIDTH, HEIGHT);
	m_Draw.DrawMidText("----- 던전 입구 -----", WIDTH, Height);
	for (int i = 0; i < m_iMonster_Count; i++)
		m_vecMonster[i]->Monster_Dongeon(i, Height + 2 *(1 + i));
	m_Draw.DrawMidText("Exit", WIDTH, Height + ( m_iMonster_Count + 1 ) * 2);
}

void GamePlay::Dongeon() // 던전 목록 밑 선택
{
	int Height = HEIGHT * 0.15f;
	int Sercet;
	while (m_bGame_Over)
	{
		Dongeon_Menu(Height); // 메뉴 그리기
		Sercet = m_Draw.MenuSelectCursor(m_iMonster_Count + 1, 2, WIDTH / 4 , Height + 2);// 메뉴중 택 1
		if (Sercet == m_iMonster_Count + 1)
			return;
		else
			Fighting(Sercet - 1);
	}
}

void GamePlay::Fighting(int i)
{
	FIGHT P1, Mons; // 공격 한것은 싸움 함수 내에서만 적용
	bool Monster_survival = true;
	Monster Fight_Monster;
	Get_Fight_Monster_Data(Fight_Monster, i);
	m_Draw.BoxErase(WIDTH, HEIGHT);
	while (m_bGame_Over && Monster_survival) // 플레이어와 몬스터가 싸워서 둘중 하나라도 체력이 0 이 될었을 때 게임 종료 
	{
		
		YELLOW
			m_pHero->Out_Information(WIDTH,HEIGHT * 0.1f);
		m_Draw.DrawMidText("가위 : 1   바위 : 2   보 : 3", WIDTH, HEIGHT*0.3f);
		ORIGINAL
		Fight_Monster.Out_Information(WIDTH, HEIGHT * 0.8f);
		m_Draw.DrawMidText("-------------------------- vs --------------------------", WIDTH, HEIGHT*0.5);
		

		P1 = m_pHero->Attack_Try();
		Mons = Fight_Monster.Attack_Try();
 		Battle(P1, Mons, Fight_Monster);
		Fight_Draw(WIDTH, HEIGHT*0.4f, P1);
		Fight_Draw(WIDTH, HEIGHT*0.65f,Mons);

		Verdit(i, Monster_survival ,Fight_Monster);
		// 만약에 몹이나 플레이가 죽었을 때 걸리는 부분
	}
}

void GamePlay::Battle(FIGHT P1, FIGHT P2, Monster &Fighter)
{

	if (P1 == FIGHT_ROCK)
	{
		if (P2 == FIGHT_SCISSORS)
		{
			m_Draw.DrawMidText("Win", WIDTH, HEIGHT*0.45f);
			m_Draw.DrawMidText("Lose", WIDTH, HEIGHT*0.6f);	
			Fighter.Hit(m_pHero->Attack());
		}
		else if (P2 == FIGHT_PAPER)
		{
			m_Draw.DrawMidText("Lose", WIDTH, HEIGHT*0.45f);
			m_Draw.DrawMidText("Win", WIDTH, HEIGHT*0.6f);
			m_pHero->Hit(Fighter.Attack());
		}
	}
	else if (P1 == FIGHT_SCISSORS)
	{
		if (P2 == FIGHT_ROCK)
		{
			m_Draw.DrawMidText("Lose", WIDTH, HEIGHT*0.45f);
			m_Draw.DrawMidText("Win", WIDTH, HEIGHT*0.6f);
			m_pHero->Hit(Fighter.Attack());
		}
		else if (P2 == FIGHT_PAPER)
		{
			m_Draw.DrawMidText("Win", WIDTH, HEIGHT*0.45f);
			m_Draw.DrawMidText("Lose", WIDTH, HEIGHT*0.6f);
			Fighter.Hit(m_pHero->Attack());
		}
	}
	else if (P1 == FIGHT_PAPER)
	{
		if (P2 == FIGHT_ROCK)
		{
			m_Draw.DrawMidText("Win", WIDTH, HEIGHT*0.45f);
			m_Draw.DrawMidText("Lose", WIDTH, HEIGHT*0.6f);		
			Fighter.Hit(m_pHero->Attack());
		}
		else if (P2 == FIGHT_SCISSORS)
		{
			m_Draw.DrawMidText("Lose", WIDTH, HEIGHT*0.45f);
			m_Draw.DrawMidText("Win", WIDTH, HEIGHT*0.6f);
			m_pHero->Hit(Fighter.Attack());
		}
	}

}
void GamePlay::Fight_Draw(int x, int y, FIGHT ch)
{
	m_Draw.DrawMidText("                      ", x, y);
	switch (ch)
	{
	case FIGHT_ROCK:
		m_Draw.DrawMidText("바위", x, y);
		break;
	case FIGHT_SCISSORS:
		m_Draw.DrawMidText("가위", x, y);
		break;
	case FIGHT_PAPER:
		m_Draw.DrawMidText("보", x, y);
		break;
	default:
		break;
	}
}

void GamePlay::Get_Fight_Monster_Data(Monster& Fight_Monster, int i)
{
	Information Data;
	Data = m_vecMonster[i]->Out_Info();
	Fight_Monster.Get_Data(Data, false);
}

void GamePlay::Verdit(int i, bool &Monster_survival , Monster Fighter) // 체력 소진 했을때 몬스터 밑 플레이어 상황
{
	if (m_pHero->Check_Life() <= 0)
	{
		m_bGame_Over = false;
		Fighter.Get_Loot(m_pHero);
	}
	else if (Fighter.Check_Life() <= 0)
	{
		Monster_survival = false; // 몬스터가 죽은 것 이니 플레이어는 경험치를 얻고 몬스터는 리셋 데이터를 얻는다.
		m_pHero->Get_Loot(&Fighter);
	}
}

void GamePlay::Weapon_Shop()
{
	while (1)
	{
		Weapon_List();
		switch (m_Draw.MenuSelectCursor(7, HEIGHT*0.1f, WIDTH / 2 - 5, HEIGHT*0.2f))
		{
		case WEAPON_DAGGER:
			break;
		case WEAPON_GUN:
			break;
		case WEAPON_SWORD:
			break;
		case WEAPON_WAND:
			break;
		case WEAPON_BOW:
			break;
		case WEAPON_HAMMER:
			break;
		case WEAPON_NOT:
			return;
		}
	}
}

void GamePlay::Game()
{
	int Select;

	while (m_bGame_Over)
	{
		Play_Menu();
		switch (m_Draw.MenuSelectCursor(6, HEIGHT*0.1f, WIDTH / 2 - 4, HEIGHT*0.3f))
		{
		case PLAYING_DONGEON:
			Dongeon();
			break;
		case PLAYING_PLAYER_INFO:
			m_Draw.BoxErase(WIDTH, HEIGHT);
			m_pHero->Out_Information(WIDTH, HEIGHT * 0.5f);
			getch();
			break;
		case PLAYING_MONSTER_INFO:
			m_Draw.BoxErase(WIDTH, HEIGHT);
			for (int i = 0; i < m_iMonster_Count; i++)
			{
				m_vecMonster[i]->Out_Information(WIDTH,( HEIGHT + 10) * 0.1f +i *4);
			}
			getch();
			break;
		case PLAYING_WEAPON_SHOP:
			m_Shop.Weapon_list(m_pHero);
			break;
		case PLAYING_SAVE:
			Data_Save();
			break;
		case PLAYING_EXIT:
			Delete_Data();
			return;
		}
	}
	Delete_Data();
}

void GamePlay::Data_Save()
{
	int Width = WIDTH / 3, Height = HEIGHT * 0.1f + 2, Select;
	string File;
	ofstream save;
	Cout_Save_Data(Width, Height);
	Select = m_Draw.MenuSelectCursor(SAVE_FILE + 1, 2, Width - 2, Height);

	File = "SavePlayer";
	m_pHero->Data_Save(Select, File);

	File = "SaveMonster";
	save.open(File + to_string(Select) + ".txt");
	save << m_iMonster_Count << endl;
	save.close();
	for (int i = 0; i < m_iMonster_Count; i++)
		m_vecMonster[i]->Data_Save_Add(Select, File);
}

void GamePlay::Get_Monster(string File)
{
	ifstream load;
	string Name;
	Monster * Monster_Data;
	Information Data;

	load.open(File);
	load >> m_iMonster_Count;
	for (int i = 0; i < m_iMonster_Count; i++)
	{
		Monster_Data = new Monster;
		load >> Data.Name;
		load >> Data.Demage;
		load >> Data.Life_Max;
		load >> Data.Exp_Max;
		load >> Data.Get_Exp;
		load >> Data.Level;
		load >> Data.Gold;
		Data.Exp = 0;
		Data.Life = Data.Life_Max;
		(*Monster_Data).Get_Data(Data, false);
		m_vecMonster.push_back(Monster_Data);
	}
}

bool GamePlay::New_Game()
{
	ifstream Player_load, Monster_load;
	m_Draw.BoxErase(WIDTH, HEIGHT);
	Player_load.open("DefaultPlayer.txt");

	if (Player_load.is_open()) // 있는지 없는지 체크
	{
		m_pHero = new Player;
		m_pHero->New_Data("DefaultPlayer.txt");
		m_bGame_Over = true; // 케릭터가 만들어지면 게임 실행  false 케릭터가 죽으면 게임 끝
	}
	else
	{
		m_Draw.DrawMidText(" 기본 파일이 없습니다 ", WIDTH, HEIGHT * 0.5f);
		system("pause");
		return false;
	}

	Monster_load.open("DefaultMonster.txt");

	if (Monster_load.is_open())
		Get_Monster("DefaultMonster.txt");
	else
	{
		m_Draw.DrawMidText(" 기본 파일이 없습니다 ", WIDTH, HEIGHT * 0.5f);
		system("pause");
		return false;
	}

	
	return true && Get_Weapon();
}

bool GamePlay::Get_Weapon()
{
	ifstream  Weapon_load;
	Weapon_load.open("WeaponList.txt");

	if (Weapon_load.is_open())
		m_Shop.Load_Weapon("WeaponList.txt");
	else
	{
		m_Draw.DrawMidText("무기 파일이 없습니다. ", WIDTH, HEIGHT * 0.5f);
		system("pause");
		return false;
	}

	return true;
}

bool GamePlay::Monster_Data_Check(int Count)
{
	ifstream load;
	load.open("SaveMonster" + to_string(Count + 1) + ".txt");
	if (load.is_open())
		return true;
	else
		return false;
}

bool GamePlay::Player_Data_Check(int Count)
{
	ifstream load;
	load.open("SavePlayer" + to_string(Count + 1) + ".txt");
	if (load.is_open())
		return true;
	else
		return false;
}

void GamePlay::Cout_Save_Data(int Width, int Height)
{
	string OX;

	m_Draw.BoxErase(WIDTH, HEIGHT);
	for (int i = 0; i < SAVE_FILE; i++)
	{
		if (Monster_Data_Check(i) && Player_Data_Check(i))
			OX = "o";
		else
			OX = "X";
		m_Draw.DrawPoint(to_string(i + 1) + "번슬롯 : < 파일여부 :" + OX + ">", Width, Height + 2 * i);
	}
	m_Draw.DrawPoint(to_string(SAVE_FILE + 1) + ". 돌아가기", Width, Height + 2 * SAVE_FILE);
}

bool GamePlay::Save_Data_Check()
{
	int Width = WIDTH / 3, Height = HEIGHT * 0.1f + 2, Select;
	
	
	while (1)
	{
		Cout_Save_Data(Width, Height);
		Select = m_Draw.MenuSelectCursor(SAVE_FILE + 1, 2, Width - 2, Height);
		if (Monster_Data_Check(Select) && Player_Data_Check(Select) && Get_Weapon() && Select != SAVE_FILE + 1)
		{
			Load_Data(Select);
			return true;
		}
		else
		{
			m_Draw.BoxErase(WIDTH, HEIGHT);
			m_Draw.DrawMidText("해당 파일이 없습니다.", WIDTH, HEIGHT / 2);
			getch();
		}

		if (Select == SAVE_FILE + 1)
			return false;
	}
}

void GamePlay::Load_Data(int Number)
{	
	if (Player_Data_Check(Number - 1) && Monster_Data_Check(Number - 1))
	{
		Weapon * Data;
		m_pHero = new Player;
		m_pHero->Old_Data("SavePlayer" + to_string(Number) + ".txt");
		Get_Monster("SaveMonster" + to_string(Number) + ".txt");
		Get_Weapon();
	}
	else
	{
		m_Draw.BoxErase(WIDTH, HEIGHT);
		m_Draw.DrawMidText("해당 파일이 없습니다.", WIDTH, HEIGHT / 2);
	}

}

void GamePlay::Delete_Data()
{
	for (auto iter = m_vecMonster.begin(); iter != m_vecMonster.end(); iter++)
		delete *iter;
	m_vecMonster.clear();

	m_pHero = NULL;
	delete m_pHero;
	m_Shop.Delete_Weapon();
}

void GamePlay::Main_Menu()
{
	m_Draw.BoxErase(WIDTH, HEIGHT);
	m_Draw.DrawMidText("☆★ DonGeonRPG ☆★", WIDTH, HEIGHT * 0.4f);
	m_Draw.DrawMidText("New Game", WIDTH, HEIGHT * 0.5f);
	m_Draw.DrawMidText("Load Game", WIDTH, HEIGHT * 0.6f);
	m_Draw.DrawMidText("Game Exit", WIDTH, HEIGHT * 0.7f);
}

void GamePlay::Map()
{
	int Select;
	m_Draw.BoxDraw(0, 0, WIDTH, HEIGHT);
	while (1)
	{
		Main_Menu();
		Select = m_Draw.MenuSelectCursor(3, HEIGHT*0.1f, WIDTH / 2 - 4, HEIGHT*0.5f);
		switch (Select)
		{
		case GAME_NEW:
			if (New_Game())
				Game();
			break;
		case GAME_LOAD: // save 게임 실행
			if (Save_Data_Check())
				Game();
			break;
		case GAME_END:
			return;
		}

	}
	system("pause");
}

GamePlay::~GamePlay()
{

}