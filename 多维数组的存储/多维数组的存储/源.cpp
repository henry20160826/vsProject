#include<iostream>
using namespace std;
void main()
{
	int a[5][10] = {0};
	int len = sizeof(a) / sizeof(int);
	cout << len << endl;
	cout << &a[0][8] << endl;
	cout << &a[0][9] << endl;
	cout << &a[1][0] << endl;
	while (true)
	{

	}
}