#pragma once
#include "Singleton.h"
#include "Student.h"

class StudentManager : public Singleton<StudentManager>
{
private:
	list<Student*> m_listStudent;
	vector<Student*> m_vecSort;
	int m_iNumber;
	
public:

	void Get_Student();
	void Sort_Number();
	void Sort_Grade();
	void Sort_Age();

	void Print_Student_List();
	
	void Delete_Student();
	void Delete_Student_List();

	StudentManager() ;
	~StudentManager() ;

};

