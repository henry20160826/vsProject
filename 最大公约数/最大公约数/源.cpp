#include<iostream>
using namespace std;
int gys(int n, int m)//շת�����
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
//����˼�룺
//��n�ֳɶ�ݣ�ÿ�ݴ�СΪm������xʣ�£����ܷ���
//�Ѿ����ֺõĲ���ÿ�ݶ���m����������ֻҪ��m�ֳ�ÿ��Ϊx�����û��ʣ��Ϳ��Է��ꡣ
//���û�з������n=m��m=x��Ȼ���ظ��������̡�

int gcd(int a, int b)//stein�㷨
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