#pragma once
#include "MapDraw.h"
class Item
{
protected:
	string m_strName;
	string m_strKind;
	int m_iPrice;	 
	int m_iDamege;	

	MapDraw m_Draw;
public:
	Item();
	~Item();

	void Set_Data(string Name, string Kind, int Price, int Damege);

	string Get_Name() const { return m_strName; }
	string Get_Kind() const { return m_strKind; }
	int Get_Price() const { return m_iPrice; }
	int Get_Damege() const { return m_iDamege; }
};

