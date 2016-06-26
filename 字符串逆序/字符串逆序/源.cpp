#include<iostream>
#include<string.h>
using namespace std;
void reverse(char *s)
{
	int len = strlen(s);
	//printf("len:%d",len);
	char temp;
	//长度为奇数 有一个数是中轴，这个数不需要交换 对2取整后得到的正好是中轴的编号
	//长度为偶数 每个数都需要交换，不存在不动的数 对2取整后得到是第二部分的第一个数的编号
	for (int i = 0; i <len/2;i++)
	{
		temp = s[i];
		s[i] = s[len-1-i];
		s[len - 1 - i] = temp;
	}
}
void main()
{
	char s[] = { "abcd" };
	reverse(s);
	printf("%s", s);
	while (true)
	{

	}
}