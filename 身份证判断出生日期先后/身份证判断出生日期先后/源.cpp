#include<iostream>
#include<string.h>
using namespace std;
void copy(char *dest, char *src)
{
	for (int i = 0; i < 8; i++)
	{
		dest[i] = src[i + 6];
	}
	dest[8] = '\0';//ע��Ҫ�ӽ�����
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
	if (result > 0)//ǰһ���󷵻�ֵ�����㣬ǰһ��ֵС����ֵС���㣬��ȷ���ֵ������
	{
		printf("��һ���˱ȵڶ�����С");//��������С
	}
	else if (result < 0)
	{
		printf("��һ���˱ȵڶ����˴�");
	}
	else
	{
		printf("������һ����");
	}
	while (true)
	{

	}
}