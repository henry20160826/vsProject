#include<iostream>
using namespace std;
int getPLen(char a[], int mid, int start, int end)
{
	int left = mid, right = mid;
	while (start <= left && right <= end)
	{
		if (a[left] != a[right])
		{
			break;
		}
		left--;
		right++;
	}
	return right - left - 1;
}
void main()
{
	while (1);
}