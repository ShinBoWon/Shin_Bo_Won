#include "Time.h"

Time::Time()
{
	m_iHour = 0;
	m_iMin = 0;
}
Time::Time(int Hour, int Min)
{
	m_iHour = Hour;
	m_iMin = Min;
}

void Time::ShowTime()
{
	cout << "ÃÑ °øºÎ ½Ã°£ : " << m_iHour << " : " << m_iMin << endl;
}

Time Time::operator+(Time time)
{
	time.m_iHour += m_iHour;
	time.m_iMin += m_iMin;

	while (time.m_iMin >= 60 )
	{
		time.m_iMin -= 60;
		time.m_iHour++;
	}

	return time;
}

Time::~Time()
{

}