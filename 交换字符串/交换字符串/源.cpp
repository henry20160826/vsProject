#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)//±ÿ–Î”–’‚æ‰
void swap(char *pa,char *pb)
{
	char temp[100];
	strcpy(temp, pa);
	strcpy(pa, pb);
	strcpy(pb, temp);
}

void main()
{
	char a[50] = {"china"};
	char b[50] = {"us"};
	swap(a, b);
	printf("a:%s,b:%s",a,b);
	while (1);
}