#pragma once
#include "Weapon.h"

class Slot : public Item
{
public:
	virtual Weapon* Get_Address() = 0;
	virtual void Set_Weapon(Weapon* Data) = 0;
	
	Slot() {};
	~Slot() {};
};

class PlayerWeapon : public Slot  // �̹� Slot ���� �����͸� ������ �ִµ� ���� ���⼭ �� ��� ���� ������ �ֳ�?.
{
private:
	Weapon* m_Weapon;
public:
	Weapon* Get_Address()override;
	void Set_Weapon(Weapon*Data)override;
	
	PlayerWeapon() {};
	~PlayerWeapon() {};
};

class Bag
{
private:
	list<Slot*> m_Bag;
	MapDraw m_Draw;

public:
	void Add_Data(Slot * Data);
	void Show_List(int Width, int Height);
	Slot* Get_Slot(int Number);
	void Delete_Data(int Number);

	inline int Get_Weapon_Count()
	{
		return m_Bag.size();
	}


	Bag() {};
	~Bag() {};
};