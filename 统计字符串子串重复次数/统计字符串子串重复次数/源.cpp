#include<iostream>
using namespace std;
struct node
{
	int start;
	int count;
};
void printSubString(const char *a,int start,int sublen)
{
	//输出子串
	for (int i = 0; i < sublen;i++)
	{
		cout << a[start+i];
	}
}
void selectSort(struct node *list,int listlen)
{
	//结果排序
	int max;
	struct node temp;
	for (int i = 0; i < listlen-1; i++)
	{
		max = i;
		for (int j = i + 1; j < listlen;j++)
		{
			if (list[j].count > list[max].count)
			{
				max = j;
			}
		}
		if (i != max)
		{
			temp = list[max];
			list[max] = list[i];
			list[i] = temp;
		}
	}
}
void print(struct node *list,const char *a, int listlen,int sublen)
{
	//输出结果
	for (int i = 0; i < listlen; i++)
	{
		if (list[i].count>0)
		{
			printSubString(a, list[i].start, sublen);
			cout << ":" << list[i].count << endl;
		}
	}
}
bool compare(const char *a,const char *b,int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (a[i]!=b[i])
		{
			break;
		}
	}
	return i == len;
}
void func(const char *a, int sublen)
{
	int len = strlen(a);
	int listlen = len - sublen + 1;
	struct node *list = new struct node[listlen];
	int i, j, k;
	print(list, a, listlen, sublen);
	for (i = 0; i < listlen; i++)
	{
		list[i].start = i;
		list[i].count = 1;
	}//初始化list,list需要初始化
	print(list, a, listlen, sublen);
	for (i = 0; i < listlen; i++)
	{
		if (list[i].count == -1)
		{
			continue;
		}
		else
		{
			for (j = i + 1; j < listlen; j++)
			{
				if (compare(&a[list[i].start], &a[list[j].start],sublen))
				{
					list[i].count++;
					list[j].count = -1;
				}
			}
		}
	}
	cout << "*******************************************"<<endl;
	selectSort(list, listlen);
	print(list,a,listlen,sublen);
	delete(list);//有借有还
}
void main()
{
	char a[] = "adfqefqf";
	func(a, 2);
	while (1);
}