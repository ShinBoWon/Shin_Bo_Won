#include "Inventory.h"

void PlayerWeapon::Show_Data(int Height)
{
	m_Draw.gotoxy(WIDTH / 6, Height);
	cout << "�̸� : " << m_strName << " ���� : " << m_strKind << endl;
	cout <<" ���ݷ� : " << m_iDamege << " ���� : " << m_iPrice << endl;
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
	for (auto iter = m_Bag.begin(); iter != m_Bag.end(); iter++)	   // + 2�� ��
		(*iter)->Show_Data(Start_Height += 2);
}