#include<iostream>
using namespace std;
void main()
{
	int a[] = { 1,9,8,3,5 };
	int *p = a;
	cout << *p++ << endl;//pȡ������ָ��ĵ�ַ��Ȼ��p��λ��++��������p����ָ�������++��*��++�Ƿֱ�������p��
	cout << *p << endl;
	while (1);
}