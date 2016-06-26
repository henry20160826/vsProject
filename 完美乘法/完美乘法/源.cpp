#include<iostream>
using namespace std;
//还以为号称的完美只有一两个，结果有那么多
bool check(int a[])
{
	bool flag = true;
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (a[i] == a[j])
			{
				flag = false;
				break;
			}
		}
	}
	if (flag)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << a[i] << ",";
		}
		cout << "\b \n";
	}
	return flag;
}
void main()
{
	int i, j, mul, a[10], k, n;
	/*
	一共10个数
	可以分成1位*4位=5位
			2位*3位=5位

	*/
	for (i = 2; i < 9; i++)//i是小的数，1位
	{
		for (j = 1234; j < 9876; j++) //j是大的数，4位
		{
			mul = i*j;
			if (mul / 10000 == 0)//mul不足5位
			{
				continue;
			}
			if (mul / 100000 != 0)//mul大于5位
			{
				continue;
			}
			a[0] = i;
			n = 1000;
			for (k = 0; k < 4; k++)
			{
				a[k + 1] = j / n % 10;
				n /= 10;
			}
			n = 10000;
			for (k = 0; k < 5;k++)
			{
				a[k + 5] = mul / n % 10;
				n /= 10;
			}
			if (check(a))
			{
				printf("%d*%d=%d\n",i,j,mul);
			}
		}
	}
	for (i = 12; i < 98; i++)//i是小的数，2位
	{
		for (j = 123; j < 987; j++) //j是大的数，3位
		{
			if (i % 11 == 0)//i中有数字重复
			{
				continue;
			}
			mul = i*j;
			if (mul / 10000 == 0)//mul不足5位
			{
				continue;
			}
			if (mul / 100000 != 0)//mul大于5位
			{
				continue;
			}
			a[0] = i / 10;
			a[1] = i % 10;
			n = 100;
			for (k = 0; k < 3; k++)
			{
				a[k + 2] = j / n % 10;
				n /= 10;
			}
			n = 10000;
			for (k = 0; k < 5; k++)
			{
				a[k + 5] = mul / n % 10;
				n /= 10;
			}
			if (check(a))
			{
				printf("%d*%d=%d\n", i, j, mul);
			}
		}
	}
	while (1);
}