#pragma once
#include "Weapon.h" 

// Weapon Data 

class Inventory 
{
	Weapon* data;	
	string name;
public:
	Inventory();
	~Inventory();

	virtual Weapon* Out_Data() = 0;
	virtual void Get_Weapon(Weapon* Data) = 0;
	virtual void Show_Data(int Height) = 0;
	virtual void AddInventory(Inventory* inventory) = 0;
	virtual void RemoveInventory(Inventory* inventory) = 0;

	void GetName(string name);
	void SetParent(Inventory* _parent);
	Inventory* GetParent();
	string GetName();
protected:
	MapDraw m_Draw;
};

class Bag : public Inventory
{
private:
	vector<Inventory*> Bag_Weapon; 
public:
	Bag() {};
	~Bag() { Bag_Weapon.clear(); };

	void Get_Weapon(Weapon * Data) {};
	void Show_Data(int Height) override;
	void AddInventory(Inventory* inventory) override;
	void RemoveInventory(Inventory* inventory) override;

	Weapon * Out_Data();
};

class InvenWeapon : public Inventory
{
private:
	Weapon * m_Data;
public:
	InvenWeapon() {};

	void Get_Weapon(Weapon * Data) override { m_Data = Data; };
	void Show_Data(int Height) override;
	void AddInventory(Inventory* inventory) {};
	void RemoveInventory(Inventory* inventory) {};

	Weapon * Out_Data(){ return m_Data; };
};