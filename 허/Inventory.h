#pragma once
#include "Weapon.h"
class Inventory	: public Weapon
{
	Inventory* parent;
	const string name;
public:
	Inventory() {};
	Inventory(string name);

	virtual Weapon* Out_Data() = 0;
	virtual void Get_Weapon(Weapon* Data) = 0;
	virtual void Show_Data(int Height) = 0;
	virtual void AddInventory(Inventory* inventory) = 0;
	virtual void RemoveInventory(Inventory* inventory) = 0;

	void SetParent(Inventory* _parent);
	Inventory* GetParent();
	string GetName();
protected:
	MapDraw m_Draw;
};

class Bag : public Inventory
{
	vector<Inventory*> Bag_Weapon;
public:
	Bag(string name) : Inventory(name) {};
	~Bag() { Bag_Weapon.clear(); };

	Weapon * Out_Data();
	void Get_Weapon(Weapon * Data) {};
	void Show_Data(int Height) override;
	void AddInventory(Inventory* inventory) override;
	void RemoveInventory(Inventory* inventory) override;
};

class InvenWeapon : public Inventory
{
private:
	Weapon * m_Data;
public:
	InvenWeapon(string name) :Inventory(name) {};

	void Get_Weapon(Weapon * Data) override { m_Data = Data; };
	void Show_Data(int Height) override;
	void AddInventory(Inventory* inventory) {};
	void RemoveInventory(Inventory* inventory) {};
	Weapon * Out_Data(){ return m_Data; };
};