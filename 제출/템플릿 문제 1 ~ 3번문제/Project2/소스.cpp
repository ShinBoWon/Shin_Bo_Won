#include <iostream>
using namespace std;

template <typename Type1>
Type1 Increase(Type1 Number)
{
	cout << 1 << " + " << Number++ << endl;
	return Number;
}

template <typename Type2>
Type2 Min(Type2 Num1, Type2 Num2)
{
	if (Num1 < Num2)
		return Num1;
	else
		return Num2;
}
template <typename Type3>
Type3 Max(Type3 Num1, Type3 Num2, Type3 Num3)
{
	if (Num1 >= Num2)
	{
		if (Num1 >= Num3)
			return Num1;
		else
			return Num3;
	}
	else if (Num2 >= Num3)
	{
		if (Num2 >= Num1)
			return Num2;
		else
			return Num1;
	}
	else if (Num3 >= Num1)
	{
		if (Num3 >= Num2)
			return Num3;
		else
			return Num2;
	}
}

void main()
{
	int Num1, Num2, Num3;

	cout << "���� �Է� :";
	cin >> Num1;
	cout << Increase(Num1) << endl << endl;
	
	cout << "�μ��� �Է� �Ͻÿ�  : ";
	cin >> Num1 >> Num2;
	cout << "�μ��� �ּҰ��� " << Min(Num1, Num2) << endl << endl;

	cout << "�� ���� �Է� �Ͻÿ�  : ";
	cin >> Num1 >> Num2 >> Num3;
	cout << "�� ���� �ִ밪��  " << Max(Num1, Num2, Num3);
}