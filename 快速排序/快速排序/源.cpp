#include<iostream>
using namespace std;
void print(int a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << ",";
	}
	cout << "\n";
}
void quick_sort(int a[], int start, int end)
{
	int startC = start;
	int endC = end;
	int temp = a[start];
	bool flag = false;//方向标记
	while (start < end)
	{
		if (flag == false)//end向着编号小的方向移动
		{
			if (a[end]>temp)
			{
				end--;
			}
			else
			{
				a[start] = a[end];
				//print(a, 9);
				start++;
				flag = true;
			}
		}
		if (flag == true)//start向着编号大的方向移动
		{
			if (a[start] < temp)
			{
				start++;
			}
			else
			{
				a[end] = a[start];
				//print(a, 9);
				end--;
				flag = false;
			}
		}
	}
	if (flag == true)
	{
		a[end] = temp;
	}
	else
	{
		a[start] = temp;
	}//把中轴填上

	//print(a, 9);
	cout << start << "\n";
	if (startC < start - 1)
	{
		quick_sort(a, startC, start - 1);
	}
	if (start + 1 < endC)
	{
		quick_sort(a, start + 1, endC);
	}
}

void main()
{
	int a[] = { 5,4,8,9,10,3,2,1,6 };
	int len = sizeof(a) / sizeof(int);
	cout << len << "\n";
	print(a, len);
	quick_sort(a, 0, len - 1);
	while (1);
}