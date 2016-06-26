#include<iostream>
using namespace std;
#pragma warning (disable:4996)
//还以为号称的完美只有一两个，结果有那么多
int intToChar(int a, char *p)
{
	//char *p = new char[10];
	//cout << "数字：" << a << endl;
	int i;
	for (i = 0; a != 0; i++)
	{
		p[i] = a % 10 + '0';
		a /= 10;
	}
	p[i] = '\0';
	//cout << "字符串："<<p << endl;
	//cout <<"长度："<< i << endl;
	return i;
}
void check(int a, int b, int mul, char *pa, char *pb, char*pmul)
{
	int alen = intToChar(a, pa);
	int blen = intToChar(b, pb);
	int mullen = intToChar(mul, pmul);
	//cout << pa << endl;
	//cout << pb << endl;
	//cout << pmul << endl;
	if (alen + blen + mullen != 10)
	{
		return;
	}
	bool flag = true;
	strcat(pmul, pa);
	strcat(pmul, pb);
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (pmul[i] == pmul[j])
			{
				flag = false;
				break;
			}
		}
	}//查重
	if (flag)
	{
		cout << a << "*" << b << "=" << mul << endl;
	}
}
void main()
{
	int i, j, mul;
	/*
	一共10个数
	可以分成1位*4位=5位
	2位*3位=5位
	*/
	//cout << weishu(100);
	char *pa = new char[10];
	char *pb = new char[10];
	char *pmul = new char[10];
	for (i = 2; i < 98; i++)
	{
		for (j = 123; j < 9876; j++)
		{
			mul = i*j;
			check(i, j, mul, pa, pb, pmul);
		}
	}
	while (1);
}