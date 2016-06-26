#include<iostream>
using namespace std;
void main()
{
	int i = 0;
	printf("%d\n", i += 2);//运算在输出之前
	i = 0;
	cout << (i+=2) << endl;//运算在输出之前，这个必须有括号，看起来很明显
	while (1);
}