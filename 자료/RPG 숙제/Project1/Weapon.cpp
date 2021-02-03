#include "Weapon.h"

Weapon::Weapon()
{

}

void Weapon::Get_Data(string Kind, string Name, int Price, int Demage)
{
	m_strKind = Kind;
	m_strName = Name;
	m_iPrice = Price;
	m_iDemage = Demage;
}

void Weapon::Out_Information(int i)
{
	m_Draw.DrawMidText("가격 :", WIDTH *0.7f, i);
	cout << m_iPrice;
	m_Draw.DrawMidText("무기타입 : ",WIDTH *1.3f, i);
	cout << m_strKind;
	m_Draw.DrawMidText("무기이름 : ", WIDTH * 0.7f, i + 1);
	cout << m_strName;
	m_Draw.DrawMidText("공격력 : ", WIDTH * 1.3f, i + 1);
	cout << m_iDemage;
}

Weapon::~Weapon()
{
	
}