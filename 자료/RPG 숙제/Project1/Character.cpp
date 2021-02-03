#include "Character.h"


Character::Character()
{

}

void Character::Out_Information(int x, int y)
{
	m_Draw.DrawMidText("=====" + m_Information.Name, x, y);
	cout << "<" << m_Information.Level << "Lv>====";
	m_Draw.DrawMidText("                                               ", x, y + 1); // 텍스트 버그 없애는 용도
	m_Draw.DrawMidText("공격력 = ", x * 0.7f, y + 1);
	cout << m_Information.Demage;
	m_Draw.DrawMidText("생명력 = ", x * 1.3f, y + 1);
	cout << m_Information.Life << "/" << m_Information.Life_Max;
	m_Draw.DrawMidText("경험치 = ", x * 0.7f, y + 2);
	cout << m_Information.Exp << "/" << m_Information.Exp_Max;
	m_Draw.DrawMidText("Get Exp = ", x * 1.3f, y + 2);
	cout << m_Information.Get_Exp;
	m_Draw.DrawMidText("Gold = ", x * 0.7f, y + 3);
	cout << m_Information.Gold;
	if (m_eWeapon != WEAPON_NOT)
		m_Draw.DrawMidText("무기타입 : " + m_Weapon->Out_Kind() + " 무기 이름 :" + m_Weapon->Out_Name() + "공격력 : " + to_string(m_Weapon->Out_Demage()), x*0.2f, y + 4);
}

void Character::Get_Loot(Character * Fighter)
{
	m_Draw.BoxErase(WIDTH, HEIGHT);
	m_Draw.DrawMidText(m_Information.Name + " 승리!!", WIDTH, HEIGHT * 0.3f );
	m_Draw.DrawMidText(m_Information.Name + "가 경험치 " + to_string(Fighter->Out_Exp()) + "를 얻었습니다.", WIDTH, HEIGHT* 0.4f);
	m_Information.Exp += Fighter->Out_Exp();
	m_Information.Gold += Fighter->Out_Gold();
	getch();
	if (m_Information.Exp >= m_Information.Exp_Max)
	{
		Level_Up();
		getch();
	}
}

void Character::Level_Up()
{
	int Up;
	m_Draw.BoxErase(WIDTH, HEIGHT);
	m_Draw.DrawMidText(m_Information.Name + "레벨 업 ", WIDTH, HEIGHT*0.4f);
	Up = rand() % 5 + 1;
	m_Information.Demage += Up;
	m_Draw.DrawMidText("공격력 " + to_string(Up) + " 증가!!", WIDTH, HEIGHT*0.5f);
	Up = rand() % 5 + 5;
	m_Information.Life_Max += Up;
	m_Draw.DrawMidText("생명력 " + to_string(Up) + " 증가!!", WIDTH, HEIGHT*0.6f);

	m_Information.Exp_Max += 3;
	m_Information.Exp = 0;
	m_Information.Level++;
	m_Information.Life = m_Information.Life_Max;

}

void Character::Get_Data(Information load_Data, bool Weapon_has)
{
	m_Information = load_Data;
	if (Weapon_has == false)
		m_eWeapon = WEAPON_NOT;
}

int Character::Attack()
{
	if (m_eWeapon != WEAPON_NOT)
		return m_Weapon->Attack(m_Information.Demage);
	else
		return m_Information.Demage;

}

void Character::Hit(int Demage)
{
	m_Information.Life -= Demage;
	if (m_Information.Life <= 0)
		m_Information.Life = 0;
}

void Character::Data_Save(int Number, string File)
{
	ofstream save;
	save.open(File + to_string(Number) + ".txt");
	save << m_Information.Name;
	save << " " << m_Information.Demage;
	save << " " << m_Information.Life_Max;
	save << " " << m_Information.Exp_Max;
	save << " " << m_Information.Get_Exp;
	save << " " << m_Information.Level;
	save << " " << m_Information.Gold;
	save << " " << m_Information.Exp;
	save << " " << m_Information.Life << endl;

	if (m_eWeapon != WEAPON_NOT)
	{
		save << 1;
		save << " " << m_Weapon->Out_Kind();
		save << " " << m_Weapon->Out_Name();
		save << " " << m_Weapon->Out_Demage();
		save << " " << m_Weapon->Out_Price();
	}
	else
		save << 0;
	save.close();
}

Character::~Character()
{

}