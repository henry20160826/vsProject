#include<iostream>
using namespace std;
#pragma warning (disable:4996) 
void main()
{
	char c;
	int count = 0, row=1;
	FILE *fp1, *fp2;
	//���ֶ�txt�ļ��ķ�ʽ�����ܴ���doc��docx
	if ((fp1 = fopen("file1.doc", "r"))==NULL)
	{
		printf("file1��ʧ��\n");
		while (true)
		{

		}
	}
	if ((fp2=fopen("file2.doc","w"))==NULL)
	{
		printf("file2��ʧ��\n");
		while (true)
		{

		}
	}
	fprintf(fp2,"�к�1:");

	while (!feof(fp1))//feof�ļ��������ط���ֵ������������0
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
			fprintf(fp2,"\n�к�%d",row);
		}
		else
		{
			fputc(c,fp2);
		}
	}
	fclose(fp1);
	fclose(fp2);
	cout << "����" << count << "���ǿո��ַ�";
	//�����4���ַ�������5���ַ�����Ϊ��������һ�����������ַ��������
	cout << "ok\n";
	while (1);
}