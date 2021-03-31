#include "Student.h"


Student::Student()
{
}

void Student::Get_Data(Person Info)
{
	m_Pinfo = Info;
}

void Student::Print_Data()
{
	cout << " ---------------------------------------------------" << endl;
	cout << m_Pinfo.Name << "  " << m_Pinfo.Age << endl;
	cout << m_Pinfo.Grade << "  " << m_Pinfo.Number;
	cout << endl << endl;
}

Student::~Student()
{
}