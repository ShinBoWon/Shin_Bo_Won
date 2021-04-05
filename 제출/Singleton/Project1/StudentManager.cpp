#include "StudentManager.h"

StudentManager::StudentManager()
{
	m_iNumber = 0;
}

void StudentManager::Get_Student()
{
	Student * Get_Student;

	Get_Student = new Student;
	
	m_iNumber++;
	Get_Student->Get_Data(m_iNumber);

	m_listStudent.push_back(Get_Student);
	m_vecSort.push_back(Get_Student);
}

void StudentManager::Sort_Grade()
{
	Student * Change;
	for (int i = 0; i < m_vecSort.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (m_vecSort[i]->Out_Grade() < m_vecSort[j]->Out_Grade ())
			{
				Change = m_vecSort[i];
				m_vecSort[i] = m_vecSort[j];
				m_vecSort[j] = Change;
			}
		}
	}
	Print_Student_List();
	system("pause");
}

void StudentManager::Sort_Age()
{
	Student * Change;
	for (int i = 0; i < m_vecSort.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (m_vecSort[i]->Out_Age() < m_vecSort[j]->Out_Age())
			{
				Change = m_vecSort[i];
				m_vecSort[i] = m_vecSort[j];
				m_vecSort[j] = Change;
			}
		}
	}
	Print_Student_List();
	system("pause");
}

void StudentManager::Sort_Number()
{
	Student * Change;
	for (int i = 0; i < m_vecSort.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (m_vecSort[i]->Out_Number() < m_vecSort[j]->Out_Number() )
			{
				Change = m_vecSort[i];
				m_vecSort[i] = m_vecSort[j];
				m_vecSort[j] = Change;
			}
		}
	}
	Print_Student_List();
	system("pause");
}

void StudentManager::Print_Student_List()
{
	for (auto iter = m_vecSort.begin(); iter != m_vecSort.end(); iter++)
	{
		cout << endl;
		(*iter)->Print_Data();		
	}
}

void StudentManager::Delete_Student()
{
	int Number;

	cout << " 삭제하고자 하는 학생의 번로를 입력 하시오  : ";
	cin >> Number;

	for (auto iter = m_vecSort.begin(); iter != m_vecSort.end(); iter++)
	{
		if (Number == (*iter)->Out_Number())
			m_vecSort.erase(iter);
	}
	for (auto iter = m_listStudent.begin(); iter != m_listStudent.end(); iter++)
	{
		if (Number == (*iter)->Out_Number())
		{
			delete (*iter);
			m_listStudent.erase(iter);
		}
		else
		{
			cout << "삭제하고자 하는 학생의 정보가 없습니다." << endl;
			system("pause");
		}
	}
	
}

void StudentManager::Delete_Student_List()
{
	for (auto iter = m_listStudent.begin(); iter != m_listStudent.end(); iter++)
		delete(*iter);

	m_listStudent.clear();
	m_vecSort.clear();
}

StudentManager::~StudentManager()
{
}