#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996)
void print(int a[],int len)
{
	printf("ͳ�ƽ����\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d�ĸ���Ϊ%d,", i, a[i]);
	}
	printf("\n\n");
}
void main()
{
	char s[50];
	int a[10] = {0};//������ȫ����ʼ��Ϊ0
	int len;
	scanf("%s",s);
	len = strlen(s);
	//for (int i = 0; i < 10; i++)
	//{
	//	a[i] = 0;
	//}//��֮ǰ��ɵ��ʽ��ʼ������
	print(a, 10);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (s[j]==i+'0')
			{
				a[i]++;
			}
		}
	}
	print(a, 10);
	while (true)
	{

	}
}