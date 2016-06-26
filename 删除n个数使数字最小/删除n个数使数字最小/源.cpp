#include<iostream>
#pragma warning (disable:4996)
using namespace std;
void func(const char *longnumber, char *result, int n)
{
	int len = strlen(longnumber);
	//result = new char[len];
	if (len < n)//n大到把所有数据删除
	{
		*result = '0';
		return;
	}
	strcpy(result, longnumber);
	int i = 0, j, min, dnum = 0;
	//dnum 记录已经删掉数字的个数
	while (dnum <= n)
	{
		min = i;//i之前的数保留下来
		for (j = i + 1; j < n + 1 - dnum; j++)//每删掉一些数据，搜索的长度短一些
		{
			if (result[j + i] < result[min])
			{
				//cout << "result[j + i]:" << result[j + i] << endl;
				//cout << "result[min]:" << result[min] << endl;
				min = j + i;
			}
		}//找出最小值
		cout << "min:" << min << endl;
		for (j = 0; j <= len - dnum-i && min != 0; j++)
		{
			result[j+i] = result[j + min];
			//下标为min的数据放在下标为i的地方，i和min-1之间的数据被删除，让min称为i之后最有权力的数
		}
		if (0 == min)
		{
			i++;
		}//第一个已经是最小的了，将它保留下来
		dnum += min;//最小值是下标是min，min之前的都要被删掉，删除了min个数
		cout << "result:" << result << endl;
	}
}
void main()
{
	char a[] = "646544326462433";
	char p[15];
	int n = 5;
	func(a, p, n);
	cout << p << endl;
	while (1);
}