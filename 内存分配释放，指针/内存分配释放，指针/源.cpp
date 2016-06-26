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
	//free(q);//同一块内存被多次释放，报错
	//原来p的内存空间没有释放，内存泄露
	while (1);
}