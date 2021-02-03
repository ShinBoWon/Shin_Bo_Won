#include "Bow.h"
#include "Dagger.h"
#include "Gun.h"
#include "Hammer.h"
#include "Sword.h"
#include "Wand.h"
#include "Player.h"
#include "MapDraw.h"

class Shop
{
private:
	// 무기 목록
	vector<Dagger*> m_vecDagger;
	vector<Gun*> m_vecGun;
	vector<Bow*> m_vecBow;
	vector<Sword*> m_vecSword;
	vector<Wand*> m_vecWand;	
	vector<Hammer*> m_vecHammer;

	vector<Weapon*> m_vecTemp; // 임시 벡터 ...
	
	MapDraw m_Draw;

public:

	void Load_Weapon(string File);
	void Shop_Menu();

	void Weapon_list(Player *player);
	void Weapon_Store(Player *player);
	void Delete_Weapon();

	void Player_Data_Load(string Kind);
	Weapon* Load_Weapon(string Kind, string Name);

	Shop();
	~Shop();

};

