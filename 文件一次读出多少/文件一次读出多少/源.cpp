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
		cout << "文件打开失败";
	}
	while (!feof(fp))
	{
		//一次读出一行数据
		//fscanf(fp,"%s",s);
		//cout << s << "\n"; 


		//一次读出一个字符，换行变成了两个字符
		//c=getc(fp);
		//cout << c<<"\n";
	}
	while (1);
}