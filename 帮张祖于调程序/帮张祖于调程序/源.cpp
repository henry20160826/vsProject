#include<stdio.h>
#define N 2
#pragma warning (disable:4996)
struct Stu
{
	char id[20];
	char name[15];
	double score;
};
void main()
{
	int i;
	struct Stu stu[N];
	for (i = 0; i<N; i++)
	{
		printf("Please input id%d,name%d,score%d:", i + 1, i + 1, i + 1);
		scanf("%s", stu[i].id);
		scanf("%s,", stu[i].name);
		scanf("%lf", &stu[i].score);
	}

	puts(stu[1].name);
	while (1);
}