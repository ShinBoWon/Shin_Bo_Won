#pragma once
#include "mecro.h"

template <typename T>
class Singleton
{
	static T * m_hThis;
public:
	static T* GetInstance()
	{
		if (m_hThis == NULL)
			m_hThis = new T;

		return m_hThis;
	}

	static T* DeleteInstance()
	{
		delete m_hThis;
		return m_hThis;
	}

	Singleton() {};
	~Singleton() {};
};

template <typename T> T * Singleton<T>::m_hThis = NULL;