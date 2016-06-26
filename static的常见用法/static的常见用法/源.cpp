#include<iostream>
using namespace std;
static int a = 1;
void main()
{
	static int b = 2;
	cout << a << "\n";
	while (true);
}