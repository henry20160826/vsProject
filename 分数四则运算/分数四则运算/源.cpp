#include<stdio.h>
#include<iostream>
using namespace std;
#pragma warning (disable:4996)
void print(long up, long down)
{
	//我的约分方法
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
	//此时a为最大公约数
	//cout << a << "\n";
	up /= a;
	down /= a;
	if(1==down)
	{//分母为1只输出分子
		printf("%ld", up);
	}
	else if(down>0)
	{
		printf("%ld/%ld", up, down);
	}
	else 
	{//防止负数出现在分母上
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
			printf("符号错误");
		}
	}
	while (true);
}