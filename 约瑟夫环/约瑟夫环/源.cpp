#include<iostream>
using namespace std;
void main()
{
	//以下是模拟游戏过程
	int N;
	cin >> N;
	const int M = 11;
	int *a = new int[N];
	int alive = N, i = 0, j = 1;
	for (int i = 0; i < N; i++)
	{
		a[i] = 1;//1表示活着，0表示死亡
	}
	while (alive!=1)
	{
		if (a[i] == 1)
		{
			if (j == M)
			{
				a[i] = 0;//报到关键数据，出去
				alive--;
				j = 1;
			}
			else {
				j++;
			}
		}
		i++;
		i %= N;
	}
	for (i = 0; i < N; i++)
	{
		if (a[i] == 1)
		{
			break;
		}
	}
	printf("第%d个人活下来",i+1);
	cout << '\n';
	//以上是模拟游戏过程


	//以下是递推公式
	//上面写了那么多其实信息量不大，但是下面这几句很难懂

	//N个人编号从0到N-1，M个编号从0到M-1，报到M-1的人出局
	int f = 0;//极限情况只有一个人，活下来的必然是他
	for (int i = 1; i <= N; i++)//i表示当前游戏人数
	{
		//老编号 = （新编号 + k） % (老游戏人数)
		//k是被干掉的下一个人的编号
		//被干掉人的编号=（M-1）%（当前游戏人数）
		//k=（M）%（当前游戏人数）
		f = (f + M) % i; //不断推导出多一个游戏的幸存者编号
	}
	//将编号修正为1到N
	cout << f + 1 << endl;
	while (1);
}