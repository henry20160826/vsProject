#include<iostream>
#include<math.h>
using namespace std;
bool check(int n)
{
	double ans = log(n) / log(3);
	return ans == (int)ans ? true : false;
}
void main()
{
	int n = 8;
	if (check(n))
	{
		cout << "yes";
	}
	else 
	{
		cout << "no";
	}
	while (true)
	{

	}
}