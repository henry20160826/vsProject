#include<iostream>
#include<math.h>
using namespace std;
void takePart(int n)
{
	int a;
	int looplen = sqrt(n);//使用开方减少循环次数
	bool flag = true;//n是否是质数的标记
	for (int i = 2; i <= looplen;i++)
	{
		if (n%i==0)
		{
			n = n / i;
			//takePart(i);
			//第一个被提出来的数一定是质数
			cout << i << "*";
			//继续分解第二个数
			takePart(n);
			flag = false;//n可以被分解，n不是质数
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