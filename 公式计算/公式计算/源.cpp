#include<stdio.h>
#include<iostream>
using namespace std;
#pragma warning (disable:4996)
void main()
{
	double x;
	int n = 3, nj = 1;
	double  sum = 1.0, xf = 1.0;
	//scanf_s("%f", &x);//������д�����
	cin >> x;//c++ �Ĳ��������Ϳ��ԣ�������ʼ����c++���
	//printf("%f\n", x);
	for (int i = 1; i <= n; i++)
	{
		xf *= x;
		nj *= i;
		if (i % 2 == 1)
		{
			//-
			sum -= (xf / nj);
		}
		else
		{
			//+
			sum += (xf / nj);
		}
	}
	printf("�����%f", sum);
	while (1);
}