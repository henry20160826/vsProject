#include<stdio.h>
#pragma warning(disable:4996)
void main()
{
	int a;
	scanf("%d", &a);
	printf("%d=",a);
	for (int i = 2; i <=a; i++)
	{
		if (a % i == 0)
		{
			a /= i;
			printf("%d*", i);
			i--;
		}
	}
	printf("\b ");
	while (1);
}