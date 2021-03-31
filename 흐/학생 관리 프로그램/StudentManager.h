#pragma once
#include "Singleton.h"
#include "Student.h"

class StudentManager : public Singleton<Student>
{
private:
	vector<Singleton> m_vecStudent;
	
public:

	void Get_Student();
	void Sort_Number();
	void Sort_Grade();

	void Print_Student_List();
	
	void Delete_Student_List();

	StudentManager() ;
	~StudentManager() ;

};

