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
	//a,b���Ƿǵݼ�����
	//m������a�ĳ���
	//n������b�ĳ���
	int temp, i = 0, j = 0, position = -1;
	while (i < m&&j < n)
	{
		if (a[i] > b[j])
		{
			temp = b[j];
			//�ƶ�b
			for (int k = j; k > 0; k--)
			{
				b[k] = b[k - 1];
			}
			//�ƶ�a
			b[0] = a[m - 1];
			for (int k = m; k > i; k--)
			{
				a[k] = a[k - 1];
			}
			a[i] = temp;
			j++;//b����ƶ���
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