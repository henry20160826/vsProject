#include<iostream>
using namespace std;
void main()
{
	char *p = "bc";
	char *q = "xyz";
	int i, j;
	i = 0;
	while (*(p + i) != '\0') i++;//运行完i=2
	cout << i;
	j = 0; i++;//第一个坑，此时i=3
	while (*(q + j) != '\0')
	{
		*(p + i + j) = *(q + j);//这句有错误，应该是题目不对
		j++;
	}
	while (true)
	{

	}
}