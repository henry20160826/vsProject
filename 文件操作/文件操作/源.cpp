#include<iostream>
using namespace std;
#pragma warning (disable:4996) 
void main()
{
	char c;
	int count = 0, row=1;
	FILE *fp1, *fp2;
	//这种读txt文件的方式，不能处理doc和docx
	if ((fp1 = fopen("file1.doc", "r"))==NULL)
	{
		printf("file1打开失败\n");
		while (true)
		{

		}
	}
	if ((fp2=fopen("file2.doc","w"))==NULL)
	{
		printf("file2打开失败\n");
		while (true)
		{

		}
	}
	fprintf(fp2,"行号1:");

	while (!feof(fp1))//feof文件结束返回非零值，不结束返回0
	{
		c = fgetc(fp1);
		cout << c << "\n";
		if (c != ' ')
		{
			count++;
		}
		if (c == '\n')
		{
			row++;
			fprintf(fp2,"\n行号%d",row);
		}
		else
		{
			fputc(c,fp2);
		}
	}
	fclose(fp1);
	fclose(fp2);
	cout << "共有" << count << "个非空格字符";
	//如果是4个字符会计算出5个字符，因为最后会多出来一个看不到的字符，很奇怪
	cout << "ok\n";
	while (1);
}