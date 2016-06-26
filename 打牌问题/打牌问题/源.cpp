#include<iostream>
#include<stdlib.h>
using namespace std;
void check(char a[], int lena, char c, int lenb)
{
	int j = 0, i;
	char temp = c;

	for (i = 0; i < lena; i++)
	{
		if (a[i] > c)
		{
			break;
		}
	}//找到合适的大牌开始的地方
	for (; i < lena; i++)
	{
		if (j >= lenb)
		{
			break;
		}//数量够了退出
		if (0 == j)
		{
			temp = a[i];
			j++;
		}
		else
		{
			if (temp == a[i] && lenb < 5)
			{
				j++;
			}
			else if (temp + 1 == a[i] && lenb == 5)
			{
				j++;
				temp++;
			}
			else if (temp == a[i] && lenb == 5)
			{
				//等待，不做操作，后面可能有合适的牌
			}
			else
			{
				j = 1;
				temp = a[i];
			}
		}

	}
	if (j >= lenb)
	{
		cout << "yes";
	}
	else
	{
		cout << "no";
	}
}
void main()
{
	char a[] = "12334556";//排好序的牌
	char b[] = "12345";//排序好的牌
	int lenb = strlen(b);//得到不算\0的长度
	int lena = strlen(a);
	//cout << len;
	check(a, lena, b[0], lenb);
	while (true)
	{

	}
}