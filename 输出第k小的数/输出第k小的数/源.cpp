//查找一个数组的第K小的数，注意同样大小算一样大。
//如  2 1 3 4 5 2 第三小数为3。
#include<iostream>
using namespace std;
void sort(int a[], int len)
{
	int temp, min;
	for (int i = 0; i < len - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		if (i != min)
		{
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}
}
void main()
{
	int a[] = { 2,1,3,4,5,2 };
	int k = 3, temp;
	int len;
	len = sizeof(a) / sizeof(int);
	//cout << len;
	sort(a, len);
	temp = a[0];
	int j = 1;
	for (int i = 1; i < len; i++)
	{
		if (temp != a[i])
		{
			temp = a[i];
			j++;
		}
		if (j == k)
		{
			cout << a[i];
			break;
		}
	}
	while (1);
}