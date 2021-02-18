#include <iostream>

using namespace std;

template <typename Tque>
class QUE
{
private:
	Tque * Que;
	int m_isize;
	int m_iFront;
	int m_iRear;
	int m_iCount;
public:
	QUE(int s)
	{
		m_isize = s;
		Que = new Tque[m_isize];
		m_iFront = 0;
		m_iRear = 0;
		m_iCount = 0;
	};

	void Enque(Tque Data)
	{
		if (m_iCount != m_isize)
		{
			Que[m_iFront] = Data;
			m_iFront++;
			m_iCount++;
			cout << "큐 에 " << Data << " 가 추가 되었습니다." << m_iCount <<  endl;
			if (m_iFront  == m_isize)
				m_iFront = 0;
		}
		else
			cout << "더이상 들어갈 자리가 없습니다." << endl;
	};

	void Deque()
	{
		if (m_iCount != 0)
		{
			cout << "큐 에 " << Que[m_iRear] << " 가 삭제 되었습니다." << --m_iCount << endl;
			m_iRear++;
			if (m_iRear  == m_isize)
				m_iRear = 0;
		}
		else
			cout << "더이상 지울 공간이 없습니다." << endl;
	};
};

void main()
{
	QUE <double> Que(6);
	Que.Enque(4.5);//1
	Que.Enque(8.5);
	Que.Enque(6.5);
	Que.Enque(1.5);
	Que.Enque(3.7);
	Que.Deque();
	Que.Enque(1.7);
	Que.Enque(8.7);
	Que.Enque(8.7);
	Que.Enque(8.7);
	Que.Enque(8.7);
	Que.Enque(8.7);
	Que.Enque(8.7);
	Que.Deque();
	Que.Deque();
	Que.Deque();
	Que.Deque();
	Que.Deque();
	Que.Deque();
	Que.Deque();
	Que.Deque();
	Que.Deque();
}