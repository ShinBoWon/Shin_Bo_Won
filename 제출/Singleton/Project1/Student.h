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
	inline int Out_Grade()
	{
		return m_Pinfo.Grade;
	}
	inline int Out_Number()
	{
		return m_Pinfo.Number;
	}

	inline int Out_Age()
	{
		return m_Pinfo.Age;
	}

	void Get_Data(int Number);
	void Print_Data();

	Student();
	~Student();
};

