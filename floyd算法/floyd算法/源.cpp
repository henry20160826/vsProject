#include<iostream>
using namespace std;
#define N 4 //此处不能有分号
//下面这个图
//http://developer.51cto.com/art/201403/433874.htm
void print(int a[][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << a[i][j] << ",";
		}
		cout << "\n";
	}
}
void main()
{
	//int a, b;
	//cin >> a >> b;//第一个值赋给a，第二个值赋给b
	//cout << a << b;//第一个值输出a，第二个值输出b
	int path[N][N] =
	{
	0,2,6,4,
	0,0,3,0,
	7,0,0,1,
	5,0,12,0
	};
	int pathDetail[N][N];//按后驱记录
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			pathDetail[i][j] = path[i][j]>0 ? j : -1;
		}
	}
	int newPath = 0;
	int oldPath = 0;
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				oldPath = path[i][j];
				if (path[i][k] != 0 && path[k][j] != 0)//判断路径有效性
				{
					newPath = path[i][k] + path[k][j];
					path[i][j] = newPath < path[i][j] ? newPath : path[i][j];
					if (path[i][j] == 0 && i != j)
					{
						path[i][j] = newPath;
					}
					if (oldPath != path[i][j])//加入k后路径更短，需要修改pathDetail
					{
						pathDetail[i][j] = pathDetail[i][k];
					}
				}
			}
		}
	}
	print(path);
	cout << "\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			pathDetail[i][j]++;
		}
	}
	print(pathDetail);
	while (1);
}