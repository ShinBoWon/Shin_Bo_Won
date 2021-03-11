#pragma once
#include"mecro.h"
#define UP 'w'
#define DOWN 's'
#define ENTER 13

enum PLAYING
{
	PLAYING_DONGEON = 1,
	PLAYING_PLAYER_INFO,
	PLAYING_MONSTER_INFO,
	PLAYING_WEAPON_SHOP,
	PLAYING_SAVE,
	PLAYING_EXIT
};
class MapDraw
{
public:
	void BoxDraw(int Start_x,int Start_y, int Width, int Height);
	void BoxErase(int Width, int Height);
	void DrawPoint(string str, int x, int y);
	void DrawMidText(string str, int x, int y);
	void TextDraw(string str, int x, int y);
	void ErasePoint(int x, int y);
	int MenuSelectCursor(int MenuLen, int AddCol, int x, int y);
	MapDraw();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	~MapDraw();
};

