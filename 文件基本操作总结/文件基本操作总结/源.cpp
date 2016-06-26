#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996)
int main()
{
	FILE *fp;
	if ((fp = fopen("test.txt", "r")) == NULL)
	{
		printf("文件打开失败");
		return 1;
		while (1);
	}
	while (!feof(fp))//文件不结束返回0，结束时返回非0值
	{
		printf("%c",fgetc(fp));
	}//按字节读文件

	char s[10];
	while (!feof(fp))
	{
		fscanf(fp, "%s", s);
		printf("%s\n", s);
	}//按行读文件
	fclose(fp);


	if ((fp = fopen("test1.txt", "w+")) == NULL)
	{
		printf("文件打开失败");
		return 1;
		while (1);
	}
	char s1[] = "132141\n";
	int len = strlen(s1);
	for (int i = 0; i < len; i++)
	{
		fputc(s1[i], fp);
	}//按字节写入

	fprintf(fp, "%s", s1);//按行写入

	fclose(fp);
	while (1);
	return 0;
}
