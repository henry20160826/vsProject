#include<iostream>
#include<string.h>
using namespace std;
void copy(char *dest, char *src)
{
	for (int i = 0; i < 8; i++)
	{
		dest[i] = src[i + 6];
	}
	dest[8] = '\0';//注意要加结束符
}
void main()
{
	char s1[18], s1s[8];
	char s2[18], s2s[8];
	cin >> s1;
	cin >> s2;
	copy(s1s, s1);
	copy(s2s, s2);
	//printf("%s\n%s\n", s1s, s2s);
	int result = strcmp(s1s, s2s);
	if (result > 0)//前一个大返回值大于零，前一个值小返回值小于零，相等返回值等于零
	{
		printf("第一个人比第二个人小");//数大年龄小
	}
	else if (result < 0)
	{
		printf("第一个人比第二个人大");
	}
	else
	{
		printf("两个人一样大");
	}
	while (true)
	{

	}
}