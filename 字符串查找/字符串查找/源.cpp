#include<iostream>
#include<stdlib.h>
using namespace std;
//自己弄得字符串匹配算法，似乎和KMP有些不一样
//还想过用自己的名字命名这个，但是这个算法不算太酷，所以还是叫改进的KMP算法
//查找在字符串a中是否含有字符串b，如果有则返回a含有的第一个b串在a中的下标，如果没有则返回-1

//算法思想：在比较时i表示a的下标，j表示b的下标，i==alen || j==blen时比较结束
//i==alen时表明在a中没有找到了与b匹配的字符串
//j==blen时表明在a中已经找到了与b匹配的字符串
//i只向下标增大的方向移动
//使用b生成key数组，key数组控制匹配时j应该向后移动到下标为多少的位置，如果key[j]的值为-1表明i需要向前移动一个，且下次比较时j=0。
//i只在两种情况下移动，一种是a[i]==b[j],当前值匹配成功，继续匹配接下来的值，另一种是a[i]!==b[j],这时去查key表，
//若查到的结果为-1.i向前移动，且下一次比较时j=0。

//整个算法的关键是生成正确的key数组
//key数组的第一个值一定是-1
//第二个值
int*get_next(char*T, int*next)
{
	//百度百科的版本，和这个结果一样，这么看来我的算法写对了
	//不过也说明早就有人想到了优化的方法
	int i = 0,j = -1;
	int length =strlen(T);
	int *temp = next;
	*next = -1;

	while (i<length)
	{
		if (j == -1 || *(T + i) == *(T + j))
		{
			i++;
			j++;//优化后的get_next方法，可以防止出现形如"aaaaab"这种模式的计算退化
			if (*(T + i) != *(T + j))
				*(next + i) = j;
			else
				*(next + i) = *(next + j);
		}
		else
			j = *(next + j);
	}
	return temp;
}
void print(int a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << ",";
	}
	cout << endl;
}
int* getkey(char b[])//根据字符串生成key数组
{
	int len = strlen(b);
	int *key = new int[len];
	key[0] = -1;
	key[1] = b[1] == b[0] ? -1 : 0;
	int j = 0;
	for (int i = 2; i < len; i++)
	{
		if (b[j] == b[i-1])
		{
			//b[i]的前面和b最前面有j+1个一样的字符
			//如果b[i]处与a[i]不匹配，b[j+1]有可能和此处匹配
			j++;
			if (b[i] == b[j])
			{
				key[i] = key[j];
			}
			else
			{
				key[i] = j;
			}
		}
		else
		{
			j = 0;
			key[i] = b[i] == b[0] ? -1 : 0;
		}
	}
	//print(ak, len);
	return key;
}
int KMP(char a[], char b[])//查找a中是否含有b，如果有返回匹配串第一个字符的编号，如果没有返回-1
{
	int alen = strlen(a);
	int blen = strlen(b);
	int *key = getkey(b);
	int j = 0;
	int i;
	for (i = 0; i < alen;)
	{
		if (a[i] == b[j])
		{
			j++;
			i++;
		}
		else
		{
			j = key[j];
		}
		if (-1 == j)//第一个字符就不匹配，向后继续比较
		{
			i++;
			j++;
		}
		if (j == blen)
		{
			break;
		}
	}
	return j == blen ? i - blen : -1;
}
int bruteForce(char a[],char b[])
{
	//暴力搜索法，还是这个方法来的简单直接
	//算法复杂度n*m，n和m分别为a和b的长度
	int alen = strlen(a);
	int blen = strlen(b);
	if (alen < blen)
	{
		return -1;
	}
	bool flag = false;
	int i,j;
	int ilen = alen - blen + 1;
	for (i = 0; i < ilen;i++)//后面长度不够就不用比了
	{
		for (j = 0; j < blen;j++)
		{
			if (a[i+j]!=b[j])
			{
				break;
			}
		}
		if (j == blen)
		{
			flag = true;
			break;
		}
	}
	return true == flag ? i : -1;
}
void main()
{
	char a[] = "cacdabaaaabaaccdddefg";
	char b[] = "aaaabaa";
	int next[100];
	//char b[] = "abc";
	//cout << start(a, b) << endl;
	int *p = getkey(b);
	print(p,strlen(b));
	get_next(b,next);
	print(next, strlen(b));
	cout << bruteForce(a, b) << endl;
	cout << KMP(a, b) << endl;

	while (1);
}