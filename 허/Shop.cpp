#include "Shop.h"
Shop::Shop()
{

}

void Shop::Load_Weapon(string File)
{
	ifstream load;
	string Kind, Name;
	int Price, Demage;
	load.open(File);
	while (!load.eof())
	{
		load >> Kind;
		load >> Name;
		load >> Demage;
		load >> Price;
		if (Kind == "Sword")
		{
			Sword *Data;
			Data = new Sword;
			(*Data).Set_Data(Name, Kind, Price, Demage);
			m_vecSword.push_back(Data);
		}
		else if (Kind == "Dagger")
		{
			Dagger *Data;
			Data = new Dagger;
			(*Data).Set_Data(Name, Kind, Price, Demage);
			m_vecDagger.push_back(Data);
		}
		else if (Kind == "Hammer")
		{
			Hammer *Data;
			Data = new Hammer;
			(*Data).Set_Data(Name, Kind, Price, Demage);
			m_vecHammer.push_back(Data);
		}
		else if (Kind == "Bow")
		{
			Bow *Data;
			Data = new Bow;
			(*Data).Set_Data(Name, Kind, Price, Demage);
			m_vecBow.push_back(Data);
		}
		else if (Kind == "Gun")
		{
			Gun *Data;
			Data = new Gun;
			(*Data).Set_Data(Name, Kind, Price, Demage);
			m_vecGun.push_back(Data);
		}
		else if (Kind == "Wand")
		{
			Wand *Data;
			Data = new Wand;
			(*Data).Set_Data(Name, Kind, Price, Demage);
			m_vecWand.push_back(Data);
		}
	}
}

void Shop::Shop_Menu()
{
	m_Draw.BoxErase(WIDTH, HEIGHT);
	m_Draw.DrawMidText("♧  ♣ S H O P  ♣♧  " , WIDTH, HEIGHT * 0.1f);
	m_Draw.DrawMidText("Dagger" , WIDTH, HEIGHT * 0.2f);
	m_Draw.DrawMidText("Gun", WIDTH, HEIGHT * 0.3f);
	m_Draw.DrawMidText("Sword", WIDTH, HEIGHT * 0.4f);
	m_Draw.DrawMidText("Wnad", WIDTH, HEIGHT * 0.5f);
	m_Draw.DrawMidText("Bow", WIDTH, HEIGHT * 0.6f);
	m_Draw.DrawMidText("Hammer", WIDTH, HEIGHT * 0.7f);
	m_Draw.DrawMidText("돌아가기", WIDTH, HEIGHT * 0.8f);
}

void Shop::Weapon_list(Player * player)
{
	int Select, i;
	Weapon* Data;
	
	while (1)
	{
		Shop_Menu();
		Select = m_Draw.MenuSelectCursor(7, HEIGHT*0.1f, WIDTH / 2 - 5, HEIGHT*0.2f);
		switch (Select)
		{
		case WEAPON_DAGGER:
			for (int i = 0; i < m_vecDagger.size(); i++)
			{
				Data = m_vecDagger[i];
				m_vecTemp.push_back(Data);
			}
			break;
		case WEAPON_GUN:
			for (int i = 0; i < m_vecGun.size(); i++)
			{
				Data = m_vecGun[i];
				m_vecTemp.push_back(Data);
			}
			break;
		case WEAPON_BOW:
			for (int i = 0; i < m_vecBow.size(); i++)
			{
				Data = m_vecBow[i];
				m_vecTemp.push_back(Data);
			}
			break;
		case WEAPON_SWORD:
			for (int i = 0; i < m_vecSword.size(); i++)
			{
				Data = m_vecSword[i];
				m_vecTemp.push_back(Data);
			}
			break;
		case WEAPON_WAND:
			for (int i = 0; i < m_vecWand.size(); i++)
			{
				Data = m_vecWand[i];
				m_vecTemp.push_back(Data);
			}
			break;
		case WEAPON_HAMMER:
			for (int i = 0; i < m_vecHammer.size(); i++)
			{
				Data = m_vecHammer[i];
				m_vecTemp.push_back(Data);
			}
			break;
		case WEAPON_NOT:
			return;
		}
		Weapon_Store(player);
		m_vecTemp.clear();
	}
}

void Shop::Weapon_Store(Player *player )
{
	int  i = 0 ,Page = 0, Select, count ,Height = HEIGHT * 0.1f;
	bool Page_Check;
	while (1)
	{
		count = 0;
		m_Draw.BoxErase(WIDTH, HEIGHT);
		m_Draw.DrawMidText("보유 골드 : ", WIDTH, Height);
		cout << player->Out_Gold();
		m_Draw.DrawMidText("Dagger Shop", WIDTH, Height + 2); // typ
		for ( ;i < m_vecTemp.size() && i < (Page +1 ) * 5; i++)
		{
			if (i < (Page + 1 )*  5 )
			{
				m_vecTemp[i]->Out_Information(Height + 2 + 3*count);
				count++;
			}
		}

		if (count + m_vecTemp.size() % 5 > (Page + 1 )*5 )
			Page_Check = true;
		else
			Page_Check = false;
		m_Draw.DrawMidText("이전 페이지", WIDTH, Height + 3 * (count + 1) - 1);
		m_Draw.DrawMidText("다음 페이지", WIDTH, Height + 3 * (count + 2) - 1);
		m_Draw.DrawMidText("나가기", WIDTH, Height + 3 * (count + 3) - 1);
		 // 선택 갯수 리스트에 있는 무기의 갯수 + 3
		Select = m_Draw.MenuSelectCursor(count + 3, 3 , WIDTH / 4 , Height + 2);

		if (count + 3 == Select)
			return;
		else if (count + 1 == Select && Page != 0)// 이전 페이지 가기
		{
			Page--;
			i = i - 5 - m_vecTemp.size() % 5;
		}
		else if (count + 1 == Select && Page == 0)
			i = 0;
		else if (count + 2 == Select && Page_Check)
			Page++;
		else if (count + 2 == Select && !Page_Check) // 다음 페이지가 없을때 겟수 만큼  뺌
		{
			if (m_vecTemp.size() % 5 == 0)
				i -= 5;
			else
				i -= m_vecTemp.size() % 5;
		} // 예외 조건들 
		else if (Select >= 0 && Select <= count )
		{
			if (player->Out_Gold() >= m_vecTemp[Select + Page * 5 - 1]->Get_Price())
			{
				player->Get_Weapon(m_vecTemp[Select + Page * 5 - 1]);// 무기를 사는 함수
			}

			// 무기를 선택하고 다시 선택 할 수 있으니 선택한 목록을 다시 그리는 조건
			if (Page_Check) 
				i -= 5;
			else
			{
				if (m_vecTemp.size() % 5 == 0)
					i -= 5;
				else
					i -= m_vecTemp.size() % 5;
			}
		}

	}
}

void Shop::Delete_Weapon() // 게임이 종료 될때 무기 데이터 초기화
{
	for (auto iter = m_vecDagger.begin(); iter != m_vecDagger.end(); iter++)
		delete* iter;
	for (auto iter = m_vecGun.begin(); iter != m_vecGun.end(); iter++)
		delete* iter;
	for (auto iter = m_vecBow.begin(); iter != m_vecBow.end(); iter++)
		delete* iter;
	for (auto iter = m_vecSword.begin(); iter != m_vecSword.end(); iter++)
		delete* iter;
	for (auto iter = m_vecWand.begin(); iter != m_vecWand.end(); iter++)
		delete* iter;
	for (auto iter = m_vecHammer.begin(); iter != m_vecHammer.end(); iter++)
		delete* iter;

	m_vecDagger.clear();
	m_vecGun.clear();
	m_vecBow.clear();
	m_vecSword.clear();
	m_vecWand.clear();
	m_vecHammer.clear();
}

void Shop::Player_Data_Load(string Kind)
{
	Weapon *Data;
	if (Kind == "Dagger")
	{
		for (int i = 0; i < m_vecDagger.size(); i++)
		{
			Data = m_vecDagger[i];
			m_vecTemp.push_back(Data);
		}
	}
	else if (Kind == "Bow")
	{
		for (int i = 0; i < m_vecBow.size(); i++)
		{
			Data = m_vecBow[i];
			m_vecTemp.push_back(Data);
		}
	}
	else if (Kind == "GUN")
	{
		for (int i = 0; i < m_vecGun.size(); i++)
		{
			Data = m_vecGun[i];
			m_vecTemp.push_back(Data);
		}
	}
	else if (Kind == "Sword")
	{
		for (int i = 0; i < m_vecSword.size(); i++)
		{
			Data = m_vecSword[i];
			m_vecTemp.push_back(Data);
		}
	}
	else if (Kind == "Wnad")
	{
		for (int i = 0; i < m_vecWand.size(); i++)
		{
			Data = m_vecWand[i];
			m_vecTemp.push_back(Data);
		}
	}
	else if (Kind == "Hammer")
	{
		for (int i = 0; i < m_vecHammer.size(); i++)
		{
			Data = m_vecHammer[i];
			m_vecTemp.push_back(Data);
		}
	}
}

Weapon* Shop::Load_Weapon(string Kind, string Name)
{
	Weapon *Data;
	Player_Data_Load(Kind);
	for (int i = 0; i < m_vecTemp.size(); i++)
	{
		if (m_vecTemp[i]->Get_Name() == Name)
			Data = m_vecTemp[i];
	}
	m_vecTemp.clear();
	return Data;
}
Shop::~Shop()
{

}