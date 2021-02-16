#include "Time.h"
void Print_Men(int Day)
{
	cout << "----- 공부 시간 관리 프로그램 < " << Day << " Day >========" << endl;
	cout << "\t\t 1. 시간 등록" << endl;
	cout << "\t\t 2. 종료" << endl;
	cout << "\t\t 입력 : ";
}
void main()
{
	int Menu, Day = 1;
	Time Main;

	while (1)
	{
		system("cls");
		Main.ShowTime();
		Print_Men(Day);
		cin >> Menu;
		switch (Menu)
		{
		case MENU_PLUSE_TIME:
		{
			int Hour, Min;
			cout << "시간 : ";
			cin >> Hour;
			cout << "분 : ";
			cin >> Min;

			Time Pluse(Hour, Min);

			Main = Pluse + Main;
			Day++;
			break;
		}
		case MENU_END:
			return;
		}
	}
}