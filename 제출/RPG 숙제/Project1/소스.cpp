#include <iostream>
using namespace std;
int main()
{
	int h, m;
	cin >> h >> m;
	if (m > 45)
	{
		m -= 45;
		cout << h << m;
	}
	else if (m < 45)
	{
		m = m - 45 + 60;

		if (h == 0)
			h += 23;
		else
			h -= 1;

		cout << h << m;
	}
	system("pause");
	return 0;
}