#include<iostream>
using namespace std;
#pragma warning (disable:4996)
void main()
{
	FILE *fp;
	char s[100];
	char c;
	if ((fp=fopen("file.txt","r"))==NULL)
	{
		cout << "�ļ���ʧ��";
	}
	while (!feof(fp))
	{
		//һ�ζ���һ������
		//fscanf(fp,"%s",s);
		//cout << s << "\n"; 


		//һ�ζ���һ���ַ������б���������ַ�
		//c=getc(fp);
		//cout << c<<"\n";
	}
	while (1);
}