#include <iostream>
using namespace std;

class Divide
{
private:
	int m_ix, m_iy;
public:
	Divide() {};
	Divide(int x, int y) { m_ix = x; m_iy = y; };
	void Print_Out() { cout << "x = " << m_ix << ", y = " << m_iy << endl; };
	Divide operator/(Divide D1);
};

Divide Divide::operator/(Divide D1)
{
	if (m_ix < D1.m_ix)
		D1.m_ix = D1.m_ix / m_ix;
	else
		D1.m_ix = m_ix / D1.m_ix;

	if (m_iy < D1.m_iy)
		D1.m_iy = D1.m_iy / m_iy;
	else
		D1.m_iy = m_iy / D1.m_iy;
	 
	return D1;
}
void main()
{
	Divide D1(10, 20), D2(5, 40) , Result;
	D1.Print_Out();
	D2.Print_Out();

	cout << "°´Ã¼ / °´Ã¼" << endl;

	Result = D1 / D2;

	Result.Print_Out();

}