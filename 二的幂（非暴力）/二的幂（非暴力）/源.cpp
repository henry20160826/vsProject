#include<iostream>
using namespace std;
bool check(int a)
{
	int x = a&(a - 1);
	//cout << "\n" << x << "\n";
	return x== 0 ? true : false;
}
void main()
{
	int n = 1024;
	int temp;
	while (1)
	{
		temp = n & 1;
		if (temp == 1)
		{
			if (n == 1)
			{
				cout << "是";
				break;
			}
			else
			{
				cout << "否";
				break;
			}
		}
		n = n >> 1;
	}
	//以上是比较笨的版本

	cout << "\n";

	n = 16;
	cout << "n取反：" << (n-1) << "\n";
	//以下是 殿堂级的版本
	if (check(n))
	{
		cout << "yes";
	}
	else
	{
		cout << "no";
	}
	while (1);
}