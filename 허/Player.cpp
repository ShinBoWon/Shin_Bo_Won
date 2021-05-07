#include "Player.h"


Player::Player()
{
	
}

FIGHT Player::Attack_Try()
{
	char ch;
	while (1)
	{
		ch = getch();
		switch (ch)
		{
		case ROCK:
			return FIGHT_ROCK;
		case SCISSORS:
			return FIGHT_SCISSORS;
		case PAPER:
			return FIGHT_PAPER;
		}
	}
}

void Player::Load_Weapon(Weapon * weapon) // 저장된 무기 불러오기
{
	m_Weapon = weapon;
	Has_Weapon(m_Weapon->Get_Kind());
}

void Player::Get_Weapon(Weapon *weapon)
{
	if (m_eWeapon != WEAPON_NOT )
	{
		m_Weapon = weapon;
		Has_Weapon(m_Weapon->Get_Kind());
		m_Information.Gold -= weapon->Get_Price();
	}
	else
	{
		m_temWeapon->Set_Weapon(m_Weapon);
		m_Bag->Add_Data(m_temWeapon);
		m_Weapon = weapon;
		Has_Weapon(m_Weapon->Get_Kind());
		m_Information.Gold -= weapon->Get_Price();
	}
}

void Player::Has_Weapon(string Kind)
{
	if (Kind == "Dagger")
		m_eWeapon = WEAPON_DAGGER;
	else if (Kind == "Bow")
		m_eWeapon = WEAPON_BOW;
	else if (Kind == "GUN")
		m_eWeapon = WEAPON_GUN;
	else if (Kind == "Sword")
		m_eWeapon = WEAPON_SWORD;
	else if (Kind == "Wnad")
		m_eWeapon = WEAPON_WAND;
	else if (Kind == "Hammer")
		m_eWeapon = WEAPON_HAMMER;

}

void Player::Has_Load_Weapon(string Kind, string Name, int Demage, int Price)
{
	if (Kind == "Dagger")
	{
		Dagger * dagger;
		dagger = new Dagger;
		dagger->Set_Data(Name,Kind,Price,Demage);
		m_Weapon = dagger;
	}
	else if (Kind == "Gun")
	{
		Gun * gun;
		gun = new Gun;
		gun->Set_Data(Name, Kind, Price, Demage);
		m_Weapon = gun;
	}
	else if (Kind == "Bow")
	{
		Bow * bow;
		bow = new Bow;
		bow->Set_Data(Name, Kind, Price, Demage);
		m_Weapon = bow;
	}
	else if (Kind == "Sword")
	{
		Sword * sword;
		sword = new Sword;
		sword->Set_Data(Name, Kind, Price, Demage);
		m_Weapon = sword;
	}
	else if (Kind == "Wnad")
	{
		Wand * wand;
		wand = new Wand;
		wand->Set_Data(Name, Kind, Price, Demage);
		m_Weapon = wand;
	}
	else if (Kind == "Hammer")
	{
		Hammer * hammer;
		hammer = new Hammer;
		hammer->Set_Data(Name, Kind, Price, Demage);
		m_Weapon = hammer;
	}
}

void Player::Old_Data(string File)
{
	Information Data;
	ifstream load;
	int Weapon_Check , Weapon_Demage, Weapon_Price;
	string Weapon_Kind, Weapon_Name;
	load.open(File);
	load >> Data.Name;
	load >> Data.Demage;
	load >> Data.Life_Max;
	load >> Data.Exp_Max;
	load >> Data.Get_Exp;
	load >> Data.Level;
	load >> Data.Gold;
	load >> Data.Exp;
	load >> Data.Life;
	load >> Weapon_Check;
	if (Weapon_Check != 0)
	{
		load >> Weapon_Kind;
		load >> Weapon_Name;
		load >> Weapon_Demage;
		load >> Weapon_Price;
		Has_Load_Weapon(Weapon_Kind, Weapon_Name, Weapon_Demage, Weapon_Price);
	}
	Character::Get_Data(Data, Weapon_Check);

}

void Player::New_Data(string File)
{
	Information Data;
	ifstream load;

	m_Draw.DrawMidText("Plyaer 이름 입력  : ", WIDTH, HEIGHT * 0.5f);
	cin >> Data.Name;

	load.open(File);
	load >> Data.Demage;
	load >> Data.Life_Max;
	load >> Data.Exp_Max;
	load >> Data.Get_Exp;
	load >> Data.Level;
	load >> Data.Gold;
	Data.Exp = 0;
	Data.Life = Data.Life_Max;

	Character::Get_Data(Data,false);
}

Player::~Player()
{

}