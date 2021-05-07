#include "Inventory.h"

void PlayerWeapon::Show_Data(int Height)
{
	m_Draw.gotoxy(WIDTH / 6, Height);
	cout << "이름 : " << m_strName << " 종류 : " << m_strKind << endl;
	cout <<" 공격력 : " << m_iDamege << " 가격 : " << m_iPrice << endl;
}

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

void Bag::Show_Data(int Height)
{
	int Start_Height = Height * 0.1f;
	for (auto iter = m_Bag.begin(); iter != m_Bag.end(); iter++)	   // + 2개 씩
		(*iter)->Show_Data(Start_Height += 2);
}