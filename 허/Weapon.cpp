#include "Weapon.h"

Weapon::Weapon()
{

}


void Weapon::Out_Information(int i)
{
	m_Draw.DrawMidText("���� :", WIDTH *0.7f, i);
	cout << Get_Price();
	m_Draw.DrawMidText("����Ÿ�� : ",WIDTH *1.3f, i);
	cout << Get_Kind();
	m_Draw.DrawMidText("�����̸� : ", WIDTH * 0.7f, i + 1);
	cout << Get_Name();
	m_Draw.DrawMidText("���ݷ� : ", WIDTH * 1.3f, i + 1);
	cout << Get_Damege();
}

Weapon::~Weapon()
{
	
}