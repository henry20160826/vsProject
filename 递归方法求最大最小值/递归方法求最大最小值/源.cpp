#include<iostream>
using namespace std;
void MinMaxValue(int *arr, int n, int &max, int &min)
{
	if (n >0)
	{
		if (*arr< min)
		{
			min = *arr;
		}
		if (*arr > max)
		{
			max = *arr;
		}
		//cout << "��ǰ�Ƚ�ֵ��" << *arr << "\n";
		arr++;
		//0��n-1��n����
		//n��1Ҳ��n����
		n--;
		//cout << "min:" << min << "\n" << "max:" << max << "\n";
		MinMaxValue(arr, n, max, min);
	}
}
void main()
{
	int arr[] = {7,8,4,9,7,2,4,10,0,4,2,3,6,8};
	int len = sizeof(arr) / sizeof(int);
	int min = arr[0];
	int max = arr[0];

	MinMaxValue(arr, len, max, min);
	cout << "min:" << min << "\n" << "max:" << max << "\n";
	while (1);
}