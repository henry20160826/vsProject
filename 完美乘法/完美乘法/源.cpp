#include<iostream>
using namespace std;
//����Ϊ�ųƵ�����ֻ��һ�������������ô��
bool check(int a[])
{
	bool flag = true;
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (a[i] == a[j])
			{
				flag = false;
				break;
			}
		}
	}
	if (flag)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << a[i] << ",";
		}
		cout << "\b \n";
	}
	return flag;
}
void main()
{
	int i, j, mul, a[10], k, n;
	/*
	һ��10����
	���Էֳ�1λ*4λ=5λ
			2λ*3λ=5λ

	*/
	for (i = 2; i < 9; i++)//i��С������1λ
	{
		for (j = 1234; j < 9876; j++) //j�Ǵ������4λ
		{
			mul = i*j;
			if (mul / 10000 == 0)//mul����5λ
			{
				continue;
			}
			if (mul / 100000 != 0)//mul����5λ
			{
				continue;
			}
			a[0] = i;
			n = 1000;
			for (k = 0; k < 4; k++)
			{
				a[k + 1] = j / n % 10;
				n /= 10;
			}
			n = 10000;
			for (k = 0; k < 5;k++)
			{
				a[k + 5] = mul / n % 10;
				n /= 10;
			}
			if (check(a))
			{
				printf("%d*%d=%d\n",i,j,mul);
			}
		}
	}
	for (i = 12; i < 98; i++)//i��С������2λ
	{
		for (j = 123; j < 987; j++) //j�Ǵ������3λ
		{
			if (i % 11 == 0)//i���������ظ�
			{
				continue;
			}
			mul = i*j;
			if (mul / 10000 == 0)//mul����5λ
			{
				continue;
			}
			if (mul / 100000 != 0)//mul����5λ
			{
				continue;
			}
			a[0] = i / 10;
			a[1] = i % 10;
			n = 100;
			for (k = 0; k < 3; k++)
			{
				a[k + 2] = j / n % 10;
				n /= 10;
			}
			n = 10000;
			for (k = 0; k < 5; k++)
			{
				a[k + 5] = mul / n % 10;
				n /= 10;
			}
			if (check(a))
			{
				printf("%d*%d=%d\n", i, j, mul);
			}
		}
	}
	while (1);
}