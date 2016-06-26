#include<iostream>
using namespace std;
void main()
{
	int a[] = { 1,9,8,3,5 };
	int *p = a;
	cout << *p++ << endl;//p取出现在指向的地址，然后p的位置++，并不是p现在指向的内容++。*和++是分别作用于p的
	cout << *p << endl;
	while (1);
}