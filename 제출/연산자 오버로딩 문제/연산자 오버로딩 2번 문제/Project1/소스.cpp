#include "Time.h"
void Print_Men(int Day)
{
	cout << "----- ���� �ð� ���� ���α׷� < " << Day << " Day >========" << endl;
	cout << "\t\t 1. �ð� ���" << endl;
	cout << "\t\t 2. ����" << endl;
	cout << "\t\t �Է� : ";
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
			cout << "�ð� : ";
			cin >> Hour;
			cout << "�� : ";
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