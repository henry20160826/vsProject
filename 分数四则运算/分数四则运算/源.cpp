#include<stdio.h>
#include<iostream>
using namespace std;
#pragma warning (disable:4996)
void print(long up, long down)
{
	//�ҵ�Լ�ַ���
	//long i = 1;
	//while (i <= up&&i <= down)
	//{
	//	if (up%i == 0 && down%i== 0)
	//	{
	//		up /= i;
	//		down /= i;
	//		i = 1;
	//	}
	//	i++;
	//}
	long a = up;
	long b = down;
	long r;
	while (b)
	{
		r = a%b;
		a = b;
		b = r;
	}
	//��ʱaΪ���Լ��
	//cout << a << "\n";
	up /= a;
	down /= a;
	if(1==down)
	{//��ĸΪ1ֻ�������
		printf("%ld", up);
	}
	else if(down>0)
	{
		printf("%ld/%ld", up, down);
	}
	else 
	{//��ֹ���������ڷ�ĸ��
		up = -up;
		down = -down;
		printf("%ld/%ld", up, down);
	}
	
}
void cal(long up1, long down1, long up2, long down2, char c)
{
	long up3, down3;
	switch (c)
	{
	case'+':
		up1 *= down2;
		up2 *= down1;
		down3 = down1*down2;
		up3 = up1 + up2; 
		break;
	case'-':
		up1 *= down2;
		up2 *= down1;
		down3 = down1*down2;
		up3 = up1 - up2; 
		break;
	case'*':
		up3 = up1*up2;
		down3 = down1*down2; 
		break;
	case'/':
		up3 = up1*down2;
		down3 = up2*down1; 
		break;
	}
	print(up3, down3);
}

void main()
{
	long up1, up2, down1, down2;
	char c;
	while (scanf("%ld/%ld%c%ld/%ld", &up1, &down1, &c, &up2, &down2)==5)
	{
		//up1 = 1;
		//down1 = 4;
		//up2 = 1;
		//down2 = 3;
		//c = '+';
		if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			cal(up1, down1, up2, down2, c);
		}
		else
		{
			printf("���Ŵ���");
		}
	}
	while (true);
}