#include "Student.h"


Student::Student()
{
}

void Student::Get_Data(int Number)
{
	cout << "이름을 입력 하세요 :";
	cin >> m_Pinfo.Name;
	cout << "나이를 입력 하세요 : ";
	cin >> m_Pinfo.Age;
	cout << "학년을 입력 하세요 : ";
	cin >> m_Pinfo.Grade;

	m_Pinfo.Number = Number;
}

void Student::Print_Data()
{
	cout << " ---------------------------------------------------" << endl;
	cout << " 이름 : "<<m_Pinfo.Name << "  나이 : " << m_Pinfo.Age << endl;
	cout << " 학년 : " << m_Pinfo.Grade << " 번호  :  " << m_Pinfo.Number;
	cout << endl << endl;
}

Student::~Student()
{
}