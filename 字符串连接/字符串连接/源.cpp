#include<iostream>
using namespace std;
void strcat(char *str1,char *str2)
{
	char *p = str1;
	while (*p != '\0')
	{
		p++;
	}
	while (*str2 != '\0')
	{
		*p++ = *str2++;
	}
}
void main()
{
	char str1[10] = "abc";
	char str2[] = "def";
	strcat(str1, str2);
	cout << str1;
	while (1);
}