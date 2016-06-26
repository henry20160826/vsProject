//用小于等于n元去买100只鸡, 大鸡5元 一只, 小鸡3元 一只, 还有3分之1元每只的一种小鸡, 分别x只,y只,z只。编程求解x,y,z所有可能解。
#include<iostream>
using namespace std;
void main()
{
	float n = 50;
	int x, y, z;
	float yuan, z1;
	for (x = 0; x < 100; x++)
	{
		for (y = 0; y <= 100 - x; y++)
		{
			z = 100 - x - y;
			z1 = (float)z;
			yuan = x * 5 + y * 3 + z1 / 3;
			if (yuan <= n)
			{
				cout << "x:" << x << ",y:" << y << ",z:" << z << "\n";
			}
		}
	}
	while (1);
}