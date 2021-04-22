#include "Inventory.h"


Inventory::Inventory(string name) : name(name)
{
	parent = NULL;
}

void Inventory::SetParent(Inventory * _parent)
{
	parent = _parent;
}

Inventory * Inventory::GetParent()
{
	return parent;
}

string Inventory::GetName()
{
	return name;
}

void Bag::Show_Data(int Height)
{
	for (auto iter = Bag_Weapon.begin(); iter != Bag_Weapon.end(); iter++)
		(*iter)->Show_Data(Height += 2);		 		 	
}
Weapon * Bag::Out_Data()
{
	int Select, Weapon_Number = 0;
	m_Draw.gotoxy(WIDTH / 4, HEIGHT * 0.1f);
	if (Bag_Weapon.size() != 0)
	{
		cout << " ���濡 �ִ� ������ ������ " << Bag_Weapon.size()<< "�Դϴ�" << endl;
		cout << " �ʿ��� ������ ��ȣ�� �Է� �ϼ��� " << endl;
		cin >> Select;
		for (auto iter = Bag_Weapon.begin(); iter != Bag_Weapon.end(); iter++)
		{
			if (Select == Weapon_Number)
				return (*iter)->Out_Data();
			Weapon_Number++;
		}
	}
	else
	{
		cout << "���濡 ���Ⱑ ���� ���� �ʽ��ϴ�. ";
		return NULL;
	}
}

void Bag::AddInventory(Inventory* inventory)
{

	inventory->SetParent(this);	
	Bag_Weapon.push_back(inventory);
}

void Bag::RemoveInventory(Inventory* inventory)
{
	vector<Inventory*>::iterator remove = find(Bag_Weapon.begin(), Bag_Weapon.end(), inventory);

	if (remove != Bag_Weapon.end())
	{
		Bag_Weapon.erase(remove);
	}
}

void InvenWeapon::Show_Data(int Height)
{
	m_Draw.gotoxy(WIDTH / 4, Height);
	cout << "���� ���� : " << m_Data->Out_Kind() << " ���� �̸� : " << m_Data->Out_Name() << endl;
	cout << "���� ���� : " << m_Data->Out_Price() << " ���� ���ݷ� : " << m_Data->Out_Demage() << endl;
}
