#include<iostream>
#pragma warning (disable:4996)
using namespace std;
void func(const char *longnumber, char *result, int n)
{
	int len = strlen(longnumber);
	//result = new char[len];
	if (len < n)//n�󵽰���������ɾ��
	{
		*result = '0';
		return;
	}
	strcpy(result, longnumber);
	int i = 0, j, min, dnum = 0;
	//dnum ��¼�Ѿ�ɾ�����ֵĸ���
	while (dnum <= n)
	{
		min = i;//i֮ǰ������������
		for (j = i + 1; j < n + 1 - dnum; j++)//ÿɾ��һЩ���ݣ������ĳ��ȶ�һЩ
		{
			if (result[j + i] < result[min])
			{
				//cout << "result[j + i]:" << result[j + i] << endl;
				//cout << "result[min]:" << result[min] << endl;
				min = j + i;
			}
		}//�ҳ���Сֵ
		cout << "min:" << min << endl;
		for (j = 0; j <= len - dnum-i && min != 0; j++)
		{
			result[j+i] = result[j + min];
			//�±�Ϊmin�����ݷ����±�Ϊi�ĵط���i��min-1֮������ݱ�ɾ������min��Ϊi֮������Ȩ������
		}
		if (0 == min)
		{
			i++;
		}//��һ���Ѿ�����С���ˣ�������������
		dnum += min;//��Сֵ���±���min��min֮ǰ�Ķ�Ҫ��ɾ����ɾ����min����
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