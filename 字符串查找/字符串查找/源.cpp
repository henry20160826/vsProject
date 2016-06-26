#include<iostream>
#include<stdlib.h>
using namespace std;
//�Լ�Ū���ַ���ƥ���㷨���ƺ���KMP��Щ��һ��
//��������Լ������������������������㷨����̫�ᣬ���Ի��ǽиĽ���KMP�㷨
//�������ַ���a���Ƿ����ַ���b��������򷵻�a���еĵ�һ��b����a�е��±꣬���û���򷵻�-1

//�㷨˼�룺�ڱȽ�ʱi��ʾa���±꣬j��ʾb���±꣬i==alen || j==blenʱ�ȽϽ���
//i==alenʱ������a��û���ҵ�����bƥ����ַ���
//j==blenʱ������a���Ѿ��ҵ�����bƥ����ַ���
//iֻ���±�����ķ����ƶ�
//ʹ��b����key���飬key�������ƥ��ʱjӦ������ƶ����±�Ϊ���ٵ�λ�ã����key[j]��ֵΪ-1����i��Ҫ��ǰ�ƶ�һ�������´αȽ�ʱj=0��
//iֻ������������ƶ���һ����a[i]==b[j],��ǰֵƥ��ɹ�������ƥ���������ֵ����һ����a[i]!==b[j],��ʱȥ��key��
//���鵽�Ľ��Ϊ-1.i��ǰ�ƶ�������һ�αȽ�ʱj=0��

//�����㷨�Ĺؼ���������ȷ��key����
//key����ĵ�һ��ֵһ����-1
//�ڶ���ֵ
int*get_next(char*T, int*next)
{
	//�ٶȰٿƵİ汾����������һ������ô�����ҵ��㷨д����
	//����Ҳ˵����������뵽���Ż��ķ���
	int i = 0,j = -1;
	int length =strlen(T);
	int *temp = next;
	*next = -1;

	while (i<length)
	{
		if (j == -1 || *(T + i) == *(T + j))
		{
			i++;
			j++;//�Ż����get_next���������Է�ֹ��������"aaaaab"����ģʽ�ļ����˻�
			if (*(T + i) != *(T + j))
				*(next + i) = j;
			else
				*(next + i) = *(next + j);
		}
		else
			j = *(next + j);
	}
	return temp;
}
void print(int a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << ",";
	}
	cout << endl;
}
int* getkey(char b[])//�����ַ�������key����
{
	int len = strlen(b);
	int *key = new int[len];
	key[0] = -1;
	key[1] = b[1] == b[0] ? -1 : 0;
	int j = 0;
	for (int i = 2; i < len; i++)
	{
		if (b[j] == b[i-1])
		{
			//b[i]��ǰ���b��ǰ����j+1��һ�����ַ�
			//���b[i]����a[i]��ƥ�䣬b[j+1]�п��ܺʹ˴�ƥ��
			j++;
			if (b[i] == b[j])
			{
				key[i] = key[j];
			}
			else
			{
				key[i] = j;
			}
		}
		else
		{
			j = 0;
			key[i] = b[i] == b[0] ? -1 : 0;
		}
	}
	//print(ak, len);
	return key;
}
int KMP(char a[], char b[])//����a���Ƿ���b������з���ƥ�䴮��һ���ַ��ı�ţ����û�з���-1
{
	int alen = strlen(a);
	int blen = strlen(b);
	int *key = getkey(b);
	int j = 0;
	int i;
	for (i = 0; i < alen;)
	{
		if (a[i] == b[j])
		{
			j++;
			i++;
		}
		else
		{
			j = key[j];
		}
		if (-1 == j)//��һ���ַ��Ͳ�ƥ�䣬�������Ƚ�
		{
			i++;
			j++;
		}
		if (j == blen)
		{
			break;
		}
	}
	return j == blen ? i - blen : -1;
}
int bruteForce(char a[],char b[])
{
	//��������������������������ļ�ֱ��
	//�㷨���Ӷ�n*m��n��m�ֱ�Ϊa��b�ĳ���
	int alen = strlen(a);
	int blen = strlen(b);
	if (alen < blen)
	{
		return -1;
	}
	bool flag = false;
	int i,j;
	int ilen = alen - blen + 1;
	for (i = 0; i < ilen;i++)//���泤�Ȳ����Ͳ��ñ���
	{
		for (j = 0; j < blen;j++)
		{
			if (a[i+j]!=b[j])
			{
				break;
			}
		}
		if (j == blen)
		{
			flag = true;
			break;
		}
	}
	return true == flag ? i : -1;
}
void main()
{
	char a[] = "cacdabaaaabaaccdddefg";
	char b[] = "aaaabaa";
	int next[100];
	//char b[] = "abc";
	//cout << start(a, b) << endl;
	int *p = getkey(b);
	print(p,strlen(b));
	get_next(b,next);
	print(next, strlen(b));
	cout << bruteForce(a, b) << endl;
	cout << KMP(a, b) << endl;

	while (1);
}