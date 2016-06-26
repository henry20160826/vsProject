#include<iostream>
#include<string.h>
#include <iomanip>//格式控制需要的头文件
using namespace std;
void print(int *a, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << ",";
	}
	cout << "\b \n";
}
void print(float *a, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << setiosflags(ios::showpoint) << a[i] << ",";//格式控制强制显示小数点
	}
	cout << "\b \n";
}
void selectSort(int a[], int len, int b)
{
	//b=0 从大到小
	//b=1 从小到大
	int m, temp;
	for (int i = 0; i < len; i++)
	{
		m = i;
		for (int j = i + 1; j < len; j++)
		{
			if (a[m] < a[j] && 0 == b)
			{
				m = j;
			}
			if (a[m] > a[j] && 1 == b)
			{
				m = j;
			}
		}
		temp = a[i];
		a[i] = a[m];
		a[m] = temp;
	}
}
void selectSort(float a[], int len, int b)
{
	//b=0 从大到小
	//b=1 从小到大
	int m;
	float temp;
	for (int i = 0; i < len; i++)
	{
		m = i;
		for (int j = i + 1; j < len; j++)
		{
			if (a[m] < a[j] && 0 == b)
			{
				m = j;
			}
			if (a[m] > a[j] && 1 == b)
			{
				m = j;
			}
		}
		temp = a[i];
		a[i] = a[m];
		a[m] = temp;
	}
}
void main()
{
	char s[] = "3 1.0 2 1 2.2 3.5 9";
	int z[100], zx, len, zi = 0, fi = 0;
	float f[100], x, dot = 0.0;
	len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		zx = s[i] - '0';
		i++;
		while (' ' != s[i] && i < len)
		{
			if ('0' <= s[i] && s[i] <= '9')
			{
				if (0.0 == dot)//没有出现小数点
				{
					zx = zx * 10 + s[i] - '0';
				}
				else
				{
					x = x + dot*(s[i] - '0');
					dot *= 0.1;
				}
			}
			else if ('.' == s[i])
			{
				dot = 0.1;
				x = zx;
			}
			i++;
		}
		if (0.0 == dot)//整数
		{
			z[zi] = zx;
			zi++;
		}
		else//浮点数
		{
			f[fi] = x;
			fi++;
			dot = 0.0;
		}
	}
	selectSort(z, zi, 1);
	selectSort(f, fi, 0);
	print(z, zi);
	print(f, fi);
	while (true)
	{

	}
}