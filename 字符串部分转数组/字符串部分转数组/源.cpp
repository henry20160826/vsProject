#include<iostream>
#include<string.h>
using namespace std;
int convert(char *s, int i, int *a, int j)
{
	int sum;
	sum = s[i] - '0';
	i++;
	while ('0' <=s[i] && s[i] <='9')
	{
		sum = sum * 10 + s[i] - '0';
		i++;
	}
	a[j] = sum;
	return --i;
}
void main()
{
	char s[] = "UESTC2015CS820C#";
	int a[100];
	int len, j = 0;
	len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if ('#' == s[i])
		{
			break;
		}
		if ('0' <=s[i] && s[i] <='9')
		{
			i = convert(s, i, a, j);
			j++;
		}
	}
	for (int k = 0; k < j; k++)
	{
		cout << a[k] << ",";
	}
	cout << "\b ";
	while (true)
	{

	}
}