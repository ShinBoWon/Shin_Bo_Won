#pragma once
#include <iostream>
using namespace std;

enum MENU
{
	MENU_PLUSE_TIME = 1,
	MENU_END
};

class Time
{
private:
	int m_iHour;
	int m_iMin;
public:
	void ShowTime();
	Time operator + (Time time);
	Time();
	Time(int Hour, int Min);
	~Time();
};

