#include<iostream>
#include<stdlib.h>
using namespace std;
void main()
{
	int n, m;
	int *pn, *pm;
	bool flag = false;
	cin >> n;
	pn = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		cin >> pn[i];
	}
	cin >> m;
	pm = (int*)malloc(sizeof(int)*m);
	for (int i = 0; i < m; i++)
	{
		cin >> pm[i];
	}
	for (int j = 0; j < m; j++)
	{
		flag = false;
		for (int i = 0; i < n; i++)
		{
			if (pn[i] == pm[j])
			{
				flag = true;
			}
		}
		if (flag)
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
	}
	while (1);
}