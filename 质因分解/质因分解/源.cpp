#include<iostream>
#include<math.h>
using namespace std;
void takePart(int n)
{
	int a;
	int looplen = sqrt(n);//ʹ�ÿ�������ѭ������
	bool flag = true;//n�Ƿ��������ı��
	for (int i = 2; i <= looplen;i++)
	{
		if (n%i==0)
		{
			n = n / i;
			//takePart(i);
			//��һ�������������һ��������
			cout << i << "*";
			//�����ֽ�ڶ�����
			takePart(n);
			flag = false;//n���Ա��ֽ⣬n��������
			break;
		}
	}
	if (flag)
	{
		cout << n<<"*";
	}
}
void main()
{
	int a = 1;
	cout << a << "=";
	takePart(a);
	cout << "\b ";
	while (1);
}