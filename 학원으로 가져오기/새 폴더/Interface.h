#include "MapDraw.h"

#define READ 10
#define SKIP 's'
#define START_LIFE 10

class Interface
{
private:
	MapDraw m_Draw;

public:
	void Show_Reading();
	void Make_Box();
	void Show_Information(int Life, int Score, string Name);
	void Show_Inforamtion_Main();
	void Main_Menu();
	string Player_Name();
	Interface();
	~Interface();
};