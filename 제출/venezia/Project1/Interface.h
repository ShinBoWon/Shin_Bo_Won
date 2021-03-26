#include "MapDraw.h"

#define READ 10
#define SKIP 's'
#define START_LIFE 10
#define INPUT_BOX 7

class Interface
{
private:
	MapDraw m_Draw;

public:
	void Show_Reading();
	void Make_Box();

	void Show_Information(int Life, int Score, string Name);
	
	void Main_Menu();

	void Erase_Main_Menu();
	void Erase_Rank_Box();
	void Erase_Input_Box();

	void Input_Box();
	
	void Player_Score(int Score);

	void Player_Life(int Life);

	

	Interface();
	~Interface();
};