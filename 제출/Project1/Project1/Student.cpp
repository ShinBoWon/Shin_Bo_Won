#include "Student.h"


Student::Student()
{
}

void Student::Get_Data(int Number)
{
	cout << "�̸��� �Է� �ϼ��� :";
	cin >> m_Pinfo.Name;
	cout << "���̸� �Է� �ϼ��� : ";
	cin >> m_Pinfo.Age;
	cout << "�г��� �Է� �ϼ��� : ";
	cin >> m_Pinfo.Grade;

	m_Pinfo.Number = Number;
}

void Student::Print_Data()
{
	cout << " ---------------------------------------------------" << endl;
	cout << " �̸� : "<<m_Pinfo.Name << "  ���� : " << m_Pinfo.Age << endl;
	cout << " �г� : " << m_Pinfo.Grade << " ��ȣ  :  " << m_Pinfo.Number;
	cout << endl << endl;
}

Student::~Student()
{
}