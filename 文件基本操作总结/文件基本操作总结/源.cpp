#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996)
int main()
{
	FILE *fp;
	if ((fp = fopen("test.txt", "r")) == NULL)
	{
		printf("�ļ���ʧ��");
		return 1;
		while (1);
	}
	while (!feof(fp))//�ļ�����������0������ʱ���ط�0ֵ
	{
		printf("%c",fgetc(fp));
	}//���ֽڶ��ļ�

	char s[10];
	while (!feof(fp))
	{
		fscanf(fp, "%s", s);
		printf("%s\n", s);
	}//���ж��ļ�
	fclose(fp);


	if ((fp = fopen("test1.txt", "w+")) == NULL)
	{
		printf("�ļ���ʧ��");
		return 1;
		while (1);
	}
	char s1[] = "132141\n";
	int len = strlen(s1);
	for (int i = 0; i < len; i++)
	{
		fputc(s1[i], fp);
	}//���ֽ�д��

	fprintf(fp, "%s", s1);//����д��

	fclose(fp);
	while (1);
	return 0;
}
