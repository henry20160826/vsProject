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
	}//�ҵ����ʵĴ��ƿ�ʼ�ĵط�
	for (; i < lena; i++)
	{
		if (j >= lenb)
		{
			break;
		}//���������˳�
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
				//�ȴ���������������������к��ʵ���
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
	char a[] = "12334556";//�ź������
	char b[] = "12345";//����õ���
	int lenb = strlen(b);//�õ�����\0�ĳ���
	int lena = strlen(a);
	//cout << len;
	check(a, lena, b[0], lenb);
	while (true)
	{

	}
}