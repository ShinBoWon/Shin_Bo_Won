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
	cout << "무기 종류 : " << m_Data->Out_Kind() << " 무기 이름 : " << m_Data->Out_Name() << endl;
	cout << "무기 가격 : " << m_Data->Out_Price() << " 무기 공격력 : " << m_Data->Out_Demage() << endl;
}
