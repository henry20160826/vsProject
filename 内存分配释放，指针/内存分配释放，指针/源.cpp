#include<iostream>
#include<stdlib.h>
using namespace std;
void main()
{
	int *p, *q;
	p = (int*)malloc(sizeof(int) * 20);
	q = (int*)malloc(sizeof(int) * 10);
	q = p;
	free(p);
	//free(q);//ͬһ���ڴ汻����ͷţ�����
	//ԭ��p���ڴ�ռ�û���ͷţ��ڴ�й¶
	while (1);
}