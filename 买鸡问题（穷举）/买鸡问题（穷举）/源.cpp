//��С�ڵ���nԪȥ��100ֻ��, ��5Ԫ һֻ, С��3Ԫ һֻ, ����3��֮1Ԫÿֻ��һ��С��, �ֱ�xֻ,yֻ,zֻ��������x,y,z���п��ܽ⡣
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