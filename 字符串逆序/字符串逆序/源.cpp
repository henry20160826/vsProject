#include<iostream>
#include<string.h>
using namespace std;
void reverse(char *s)
{
	int len = strlen(s);
	//printf("len:%d",len);
	char temp;
	//����Ϊ���� ��һ���������ᣬ���������Ҫ���� ��2ȡ����õ�������������ı��
	//����Ϊż�� ÿ��������Ҫ�����������ڲ������� ��2ȡ����õ��ǵڶ����ֵĵ�һ�����ı��
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