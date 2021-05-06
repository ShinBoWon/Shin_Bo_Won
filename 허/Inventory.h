#pragma once
#include "Weapon.h"

class Slot : public Item
{
public:
	virtual void Show_Data(int Height) = 0;
	
	Slot() {};
	~Slot() {};
};

class PlayerWeapon : public Slot  // �̹� Slot ���� �����͸� ������ �ִµ� ���� ���⼭ �� ��� ���� ������ �ֳ�?.
{
public:
	void Show_Data(int Height);
	
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


	Bag() {};
	~Bag() {};
};