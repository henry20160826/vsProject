#include<stdio.h>
struct student
{
	char snum;
	int grade;
};
void main()
{
	struct student list[100];
	int highgrade;
	int lowgrade;
	highgrade = 0;
	lowgrade = 100;
	for (int i = 0; i < 100; i++)
	{
		if (list[i].grade < lowgrade)
		{
			lowgrade = list[i].grade;
		}
		if (list[i].grade > highgrade)
		{
			highgrade = list[i].grade;
		}
	}
	printf("��߷�ѧ�ţ�\n");
	for (int i = 0; i < 100;i++)
	{
		if (list[i].grade == highgrade)
		{
			printf("%s",list[i].snum);
		}
	}
	printf("��ͷ�ѧ�ţ�\n");
	for (int i = 0; i < 100; i++)
	{
		if (list[i].grade == lowgrade)
		{
			printf("%s", list[i].snum);
		}
	}
}