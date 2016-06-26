#include<iostream>
#include<string.h>
using namespace std;
void deleteChar(char s[], char c)//从字符串中删除某个字符
{
	//s是字符串
	//len是字符串长度
	//c是要删除的字符
	int len = strlen(s);//统计的字符串长度不包括‘\0’
	int num = 0;
	for (int i = 0; i <= len; i++)
	{
		if (num != 0)
		{
			s[i - num] = s[i];
		}
		if (s[i] == c)
		{
			num++;
		}
	}
	//新字符串的长度是之前的长度减去删除字符的数量
}
void deleteSome(char s[])
{
	//s是字符串
	//len是字符串长度
	int len = strlen(s);//统计的字符串长度不包括‘\0’
	int num = 0;
	for (int i = 0; i <= len; i++)
	{
		if (num != 0)
		{
			s[i - num] = s[i];
		}
		if ('a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z' || '0' <= s[i] && s[i] <= '9')
		{
			num++;
		}
	}
	//新字符串的长度是之前的长度减去删除字符的数量
}
//void move(char s[], int len)//之前不好的删除算法
//{
//for (int i = 0; i < len; i++)
//{
//	if ('a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z' || '0' <= s[i] && s[i] <= '9')//与的优先级高于或
//	{
//		s[i] = NULL;
//		//s[i] = '0';
//	}
//}
//	int num = 0;
//	for (int i = 0; i < len;)
//	{
//		if (NULL == s[i])
//		{
//			num++;
//			i++;
//			for (; s[i] != NULL&& i < len; i++)
//			{
//				s[i - num] = s[i];
//			}
//		}
//		else
//		{
//			i++;
//		}
//	}
//	s[len - num] = '\0';
//}
void analysis(char s[])
{
	int len = strlen(s);//统计的字符串长度不包括‘\0’
	char a[100];
	int ai[100], alen = 0, j;
	for (int i = 0; i < len; i++)
	{
		for (j = 0; j < alen; j++)
		{
			if (s[i] == a[j])
			{
				break;
			}
		}
		if (j == alen)
		{
			//没有找到这个字符
			if (alen == 100)
			{
				printf("缓存已满");
				break;
			}
			else
			{
				a[alen] = s[i];
				ai[alen] = 1;
				alen++;
			}
		}
		else
		{
			//找到这个字符
			ai[j]++;
		}
	}
	cout << "共出现了" << alen << "种,"<<len<<"个字符" << "\n";
	for (j = 0; j < alen; j++)
	{
		printf("%c出现了%d次\n", a[j], ai[j]);
	}
	cout << "\n";
}
void main()
{
	char s[100] = { "6f99f(fqf;;488M44%449A94" };
	//char s[100];
	//cin >> s;

	//查看最初字符
	cout << s << "\n";
	analysis(s);

	//测试删除一种字符
	//move(s, len);
	deleteChar(s, '4');
	cout << s << "\n";
	analysis(s);

	//测试删除多种字符
	deleteSome(s);
	cout << s << "\n";
	analysis(s);

	while (1);
}