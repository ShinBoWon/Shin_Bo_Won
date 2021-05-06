#include "Weapon.h"

Weapon::Weapon()
{

}


void Weapon::Out_Information(int i)
{
	m_Draw.DrawMidText("가격 :", WIDTH *0.7f, i);
	cout << Get_Price();
	m_Draw.DrawMidText("무기타입 : ",WIDTH *1.3f, i);
	cout << Get_Kind();
	m_Draw.DrawMidText("무기이름 : ", WIDTH * 0.7f, i + 1);
	cout << Get_Name();
	m_Draw.DrawMidText("공격력 : ", WIDTH * 1.3f, i + 1);
	cout << Get_Damege();
}

Weapon::~Weapon()
{
	
}