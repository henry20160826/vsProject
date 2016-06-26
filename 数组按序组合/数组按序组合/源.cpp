#include<iostream>
using namespace std;
void print(int a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << ",";
	}
	cout << endl;
}
void insert(int a[], int b[], int m, int n)
{
	//a,b都是非递减序列
	//m是数组a的长度
	//n是数组b的长度
	int temp, i = 0, j = 0, position = -1;
	while (i < m&&j < n)
	{
		if (a[i] > b[j])
		{
			temp = b[j];
			//移动b
			for (int k = j; k > 0; k--)
			{
				b[k] = b[k - 1];
			}
			//移动a
			b[0] = a[m - 1];
			for (int k = m; k > i; k--)
			{
				a[k] = a[k - 1];
			}
			a[i] = temp;
			j++;//b向后移动了
			//print(a, m);
			//print(b, n);
		}
		i++;
	}
}


void main()
{
	int a[] = { 4,6,7 };
	int b[] = { 1,2 };
	int m = sizeof(a) / sizeof(int);
	int n = sizeof(b) / sizeof(int);
	insert(a, b, m, n);
	print(a, m);
	print(b, n);
	while (1);
}