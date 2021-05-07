#pragma once
#include "Weapon.h"

class Slot : public Item
{
public:
	virtual void Show_Data(int Height) = 0;
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
	void Show_Data(int Height);
	Weapon* Get_Address()override;
	void Set_Weapon(Weapon*Data)override;
	
	PlayerWeapon() {};
	~PlayerWeapon() {};
};

class Bag
{
private:
	list<Slot*> m_Bag;

public:
	void Add_Data(Slot * Data);
	void Show_Data(int Height);
	inline int Get_Weapon_Count()
	{
		return m_Bag.size();
	}


	Bag() {};
	~Bag() {};
};