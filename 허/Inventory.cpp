#include "Inventory.h"

Weapon * PlayerWeapon::Get_Address()
{
	return m_Weapon;
}

void PlayerWeapon::Set_Weapon(Weapon* Data)
{
	m_Weapon = Data;
}

void Bag::Add_Data(Slot* Data)
{
	m_Bag.push_back(Data);
}

void Bag::Show_List(int Width, int Height)
{
	int Plus_x = 0;
	int Weapon_Count = 1;
	m_Draw.gotoxy(Width, Height);
	for (auto iter = m_Bag.begin(); iter != m_Bag.end(); iter++)
	{
		if (Plus_x != 2)
		{
			cout << Weapon_Count << ". 이름 : " << (*iter)->Get_Name() << " 종류" << (*iter)->Get_Kind();
			Plus_x++;
		}
		else
		{
			cout << Weapon_Count << ". 이름 : " << (*iter)->Get_Name() <<" 종류" << (*iter)->Get_Kind() << endl << endl;
			Plus_x = 0;
		}
	}
}

Slot* Bag::Get_Slot(int Number)
{
	int Count = 0;
	for (auto iter = m_Bag.begin(); iter != m_Bag.end(); iter++)
	{
		if (Count == Number)
			return (*iter);
		Count++;
	}
}

void Bag::Delete_Data(int Number)
{
	int Count = 0;
	for (auto iter = m_Bag.begin(); iter != m_Bag.end(); iter++)
	{
		if (Count == Number)
		{
			iter = m_Bag.erase(iter);
			break;
		}
		Count++;
	}
}