#include <iostream>
using namespace std;
template <typename Type2>
Type2 Min(Type2 Num1, Type2 Num2)
{
	if (Num1 < Num2)
		return Num1;
	else
		return Num2;
}

void main()
{
	int Num1, Num2;
	cout << "�μ��� �Է� �Ͻÿ�  : ";
	cin >> Num1 >> Num2;
	cout << "�μ��� �ּҰ��� " << Min(Num1, Num2);
}