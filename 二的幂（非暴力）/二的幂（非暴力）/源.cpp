#include<iostream>
using namespace std;
bool check(int a)
{
	int x = a&(a - 1);
	//cout << "\n" << x << "\n";
	return x== 0 ? true : false;
}
void main()
{
	int n = 1024;
	int temp;
	while (1)
	{
		temp = n & 1;
		if (temp == 1)
		{
			if (n == 1)
			{
				cout << "��";
				break;
			}
			else
			{
				cout << "��";
				break;
			}
		}
		n = n >> 1;
	}
	//�����ǱȽϱ��İ汾

	cout << "\n";

	n = 16;
	cout << "nȡ����" << (n-1) << "\n";
	//������ ���ü��İ汾
	if (check(n))
	{
		cout << "yes";
	}
	else
	{
		cout << "no";
	}
	while (1);
}