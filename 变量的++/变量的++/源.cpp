#include<iostream>
using namespace std;
void main()
{
	int i = 0;
	cout << i++ << endl;//先使用i的值，然后对i++
	cout << i << endl;
	i = 0;
	cout << ++i<< endl;//先对i++，然后使用i的值
	while (1);
}