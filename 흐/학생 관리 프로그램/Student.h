#pragma once
#include "Mecro.h"

typedef struct Person
{
	string Name;
	int Age;
	int Grade;
	int Number;
};

class Student
{
private:
	Person m_Pinfo;
	
public:

	void Get_Data(Person Info);
	void Print_Data();

	Student();
	~Student();
};

