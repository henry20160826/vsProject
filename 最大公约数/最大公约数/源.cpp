#include<iostream>
using namespace std;
int gys(int n, int m)//辗转相除法
{
	int x;
	while (m)
	{
		x = n%m;
		n = m;
		m = x;
	}
	return n;
}
//基本思想：
//将n分成多份，每份大小为m，会有x剩下，不能分完
//已经被分好的部分每份都是m，所以现在只要将m分成每份为x，如果没有剩余就可以分完。
//如果没有分完就令n=m，m=x，然后重复上述过程。

int gcd(int a, int b)//stein算法
{
	int	c = 1;
	int n, m;
	while (a != 0 && b != 0)
	{
		n = a % 2;
		m = b % 2;
		if (n == 0 && m == 0)
		{
			a /= 2;
			b /= 2;
			c *= 2;
		}
		else if (n == 0 && m != 0)
		{
			a /= 2;

		}
		else if (n != 0 && m == 0)
		{
			b /= 2;
		}
		else //(n != 0 && m != 0)
		{
			n = a;
			a =a > b ? (a - b) : (b - a);
			b = n < b ? n : b;
		}
		cout << "a:" << a << ",";
		cout << "b:" << b << ",";
		cout << "c:" << c << "\n";
	}
	if (0 == a)
	{
		c = c*b;
	}
	else
	{
		c = c*a;
	}
	return c;
}

void main()
{
	cout << gys(96, 72);
	while (1);
}