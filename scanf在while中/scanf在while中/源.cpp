#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
int a[100];
int isPrime(int n)
{
	int i;
	for (i = 2; i <= sqrt(n); i++)
		if (n%i == 0)
			return 0;
	return 1;
}
int main()
{
	int i, j, in;
	//scanf�ķ���ֵ ��ȷ�������ݵĸ���
	while (scanf("%d", &in))
	{
		if (in == 0 || in == 1)
			printf("û��������");
		else
		{
			j = 0;
			printf("%d=", in);
			while (in>3)
			{
				for (i = 2; i <= in; i++)
				{
					if (isPrime(i) && in%i == 0)
						break;
				}
				in = in / i;
				a[j++] = i;
			}
			if (in>1)
				a[j++] = in;
			for (i = 0; i<j; i++)
			{
				printf("%d", a[i]);
				if (i<j - 1)
					printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}
