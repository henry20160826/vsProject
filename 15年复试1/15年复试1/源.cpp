#include<iostream>
using namespace std;
void main()
{
	char *p = "bc";
	char *q = "xyz";
	int i, j;
	i = 0;
	while (*(p + i) != '\0') i++;//������i=2
	cout << i;
	j = 0; i++;//��һ���ӣ���ʱi=3
	while (*(q + j) != '\0')
	{
		*(p + i + j) = *(q + j);//����д���Ӧ������Ŀ����
		j++;
	}
	while (true)
	{

	}
}