#include<stdio.h>
#include<iostream>
using namespace std;
#pragma warning (disable:4996)
void main()
{
	double x;
	int n = 3, nj = 1;
	double  sum = 1.0, xf = 1.0;
	//scanf_s("%f", &x);//输入就有错误结果
	cin >> x;//c++ 的操作方法就可以，慢慢开始尝试c++编程
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
	printf("结果：%f", sum);
	while (1);
}