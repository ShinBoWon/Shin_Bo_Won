#include "StudentManager.h"

enum
{
	MENU_INPUT = 1,
	MENU_NUMBER_SORT,
	MENU_AGE_SORT,
	MENU_GRADE_SORT,
	MENU_ONE_DELETE,
	MENU_ALL_DELETE,
	MENU_END
};

void Main_Menu()
{
	cout << " ============================" <<endl;
	cout << "1. �л� �Է� " << endl;
	cout << "2. ��ȣ ����" << endl;
	cout << "3. ���� ����" << endl;
	cout << "4. �� ���� " << endl;	
	cout << "5. �л� ���� ����" << endl;
	cout << "6. ��ü �л� ���� ���� " << endl;
	cout << "7.  ����  " << endl;
}

void main()
{
	int Select;
	while (1)
	{
		system("cls");
		Main_Menu();
		cin >> Select;
		switch (Select)
		{
		case MENU_INPUT:
			StudentManager::GetInstance()->Get_Student();
			break;
		case MENU_NUMBER_SORT:
			StudentManager::GetInstance()->Sort_Number();
			break;
		case MENU_AGE_SORT:
			StudentManager::GetInstance()->Sort_Age();
			break;
		case MENU_GRADE_SORT:
			StudentManager::GetInstance()->Sort_Grade();
			break;
		case MENU_ONE_DELETE:
			StudentManager::GetInstance()->Delete_Student();
			break;
		case MENU_ALL_DELETE:
			StudentManager::GetInstance()->Delete_Student_List();
			break;
		case MENU_END:
			StudentManager::DeletInstance();
			return;
		}
	}
}
