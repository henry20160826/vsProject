#include<iostream>
#include<string.h>
using namespace std;
void deleteChar(char s[], char c)//���ַ�����ɾ��ĳ���ַ�
{
	//s���ַ���
	//len���ַ�������
	//c��Ҫɾ�����ַ�
	int len = strlen(s);//ͳ�Ƶ��ַ������Ȳ�������\0��
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
	//���ַ����ĳ�����֮ǰ�ĳ��ȼ�ȥɾ���ַ�������
}
void deleteSome(char s[])
{
	//s���ַ���
	//len���ַ�������
	int len = strlen(s);//ͳ�Ƶ��ַ������Ȳ�������\0��
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
	//���ַ����ĳ�����֮ǰ�ĳ��ȼ�ȥɾ���ַ�������
}
//void move(char s[], int len)//֮ǰ���õ�ɾ���㷨
//{
//for (int i = 0; i < len; i++)
//{
//	if ('a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z' || '0' <= s[i] && s[i] <= '9')//������ȼ����ڻ�
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
	int len = strlen(s);//ͳ�Ƶ��ַ������Ȳ�������\0��
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
			//û���ҵ�����ַ�
			if (alen == 100)
			{
				printf("��������");
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
			//�ҵ�����ַ�
			ai[j]++;
		}
	}
	cout << "��������" << alen << "��,"<<len<<"���ַ�" << "\n";
	for (j = 0; j < alen; j++)
	{
		printf("%c������%d��\n", a[j], ai[j]);
	}
	cout << "\n";
}
void main()
{
	char s[100] = { "6f99f(fqf;;488M44%449A94" };
	//char s[100];
	//cin >> s;

	//�鿴����ַ�
	cout << s << "\n";
	analysis(s);

	//����ɾ��һ���ַ�
	//move(s, len);
	deleteChar(s, '4');
	cout << s << "\n";
	analysis(s);

	//����ɾ�������ַ�
	deleteSome(s);
	cout << s << "\n";
	analysis(s);

	while (1);
}