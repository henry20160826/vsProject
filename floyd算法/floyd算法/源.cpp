#include<iostream>
using namespace std;
#define N 4 //�˴������зֺ�
//�������ͼ
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
	//cin >> a >> b;//��һ��ֵ����a���ڶ���ֵ����b
	//cout << a << b;//��һ��ֵ���a���ڶ���ֵ���b
	int path[N][N] =
	{
	0,2,6,4,
	0,0,3,0,
	7,0,0,1,
	5,0,12,0
	};
	int pathDetail[N][N];//��������¼
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
				if (path[i][k] != 0 && path[k][j] != 0)//�ж�·����Ч��
				{
					newPath = path[i][k] + path[k][j];
					path[i][j] = newPath < path[i][j] ? newPath : path[i][j];
					if (path[i][j] == 0 && i != j)
					{
						path[i][j] = newPath;
					}
					if (oldPath != path[i][j])//����k��·�����̣���Ҫ�޸�pathDetail
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