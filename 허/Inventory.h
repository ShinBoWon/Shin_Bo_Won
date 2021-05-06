#pragma once
#include "Weapon.h"

class Slot : public Item
{
public:
	virtual void Show_Data(int Height) = 0;
	
	Slot() {};
	~Slot() {};
};

class PlayerWeapon : public Slot  // 이미 Slot 에서 데이터를 가지고 있는데 굳이 여기서 또 상속 받을 이유가 있나?.
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