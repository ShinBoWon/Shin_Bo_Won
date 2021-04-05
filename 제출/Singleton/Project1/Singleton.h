#pragma once
#include "Mecro.h"

template <typename T>

class Singleton
{
private:
	static T * m_hThis;
public:
	static T * GetInstance()
	{
		if (m_hThis == NULL)
			m_hThis = new T; // ���Ӱ� ���� �Ҵ��� ������ 

		return m_hThis;
	}

	static T * DeletInstance()
	{
		delete m_hThis;
		return m_hThis;
	}

	Singleton() {};
	~Singleton() {};

};	

template <typename T> T* Singleton<T>::m_hThis = 0;