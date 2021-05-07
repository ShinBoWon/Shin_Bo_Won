#include "Player.h"


Player::Player()
{
	m_Bag = new Bag;
	m_temWeapon = new PlayerWeapon;
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
	if (m_eWeapon == WEAPON_NOT )
	{
		m_Weapon = weapon;
		Has_Weapon(m_Weapon->Get_Kind());
		m_Information.Gold -= weapon->Get_Price();
	}
	else
	{
		//m_temWeapon->Set_Weapon(m_Weapon); 
		PlayerWeapon* temp = new PlayerWeapon;
		temp->Set_Weapon(m_Weapon);
		m_Bag->Add_Data(temp);
		// 기존에 있는 무기를 가방안에 넣고
		// 새로 산 무기는 장비 
		m_Weapon = weapon;
		Has_Weapon(m_Weapon->Get_Kind());
		m_Information.Gold -= weapon->Get_Price();
	}
}

void Player::Weapon_Info(int Height)
{
	int Width = WIDTH / 5;
	char Y_N = NULL;
	if (m_eWeapon != WEAPON_NOT )
	{
		m_Draw.gotoxy(Width, Height);
		cout << "무기 이름 : " << m_Weapon->Get_Name() << " 종류 : " << m_Weapon->Get_Kind();
		m_Draw.gotoxy(Width, Height + 1);
		cout << " 공격력 : " << m_Weapon->Get_Damege() << " 가격 : " << m_Weapon->Get_Price();
	}
	m_Draw.gotoxy(Width, Height + 2);
	cout << " 교체 가능한 무기 :" << m_Bag->Get_Weapon_Count();	
	m_Draw.gotoxy(Width, Height + 3);
	cout << "교체 여부  Y or 아무키  :";
	Y_N = getch();

	if (m_Bag->Get_Weapon_Count() != 0 && Y_N == 'y')
	{
		int Serlect;
		m_Draw.BoxErase(WIDTH, HEIGHT);
		m_Bag->Show_List(Width, Height);
		cout << " 꺼낼 무기 번호를 입력 하세요  : ";
		cin >> Serlect;
		m_temWeapon->Set_Weapon(m_Weapon);
		m_Bag->Add_Data(m_temWeapon);
		m_temWeapon = m_Bag->Get_Slot(Serlect);
		m_Bag->Delete_Data(Serlect);
		m_Weapon = m_temWeapon->Get_Address();
	}
}

void Player::Has_Weapon(string Kind)
{
	if (Kind == "Dagger")
		m_eWeapon = WEAPON_DAGGER;
	else if (Kind == "Bow")
		m_eWeapon = WEAPON_BOW;
	else if (Kind == "Gun")
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
	delete m_Bag;
}