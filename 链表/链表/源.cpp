#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
	int num;
	struct node *next;
};
void addNode(struct node *head, struct node *p)
{
	struct node *temp;
	temp = head->next;
	head->next = p;
	p->next = temp;//按头插法添加新节点
}

void addNode(struct node *head, int n)
{
	struct node *temp, *p;
	p = (struct node*)malloc(sizeof(struct node));
	p->num = n;
	addNode(head, p);//按头插法添加新节点
}
void addNodeToRear(struct node *head,struct node *p)//尾插法添加新结点
{
	while (NULL != head->next);
	p->next = NULL;
	head->next = p;
}
void addNodeToRear(struct node *head, int n)
{
	struct node *temp, *p;
	p = (struct node*)malloc(sizeof(struct node));
	p->num = n;
	addNodeToRear(head, p);
}
struct node* findNode(struct node *head, int n)
{
	//返回查找到的位置的前一个节点
	//返回第一个查找结果，之后可能还有符合条件的结点
	//从head的下一个结点开始查
	while (NULL != head->next)
	{
		if (head->next->num == n)
		{
			return head;
		}
		head = head->next;
	}
	return NULL;
}
bool deleteNode(struct node *head, int n)//有可能需要修改head
{
	struct node *prior, *p;
	prior = findNode(head, n);
	if (NULL == prior)
	{
		return false;
	}
	p = prior->next;
	prior->next = p->next;
	delete(p);
	return true;
}
void creatEmptyList(struct node *&head)
{
	head = new struct node;
	head->next = NULL;
	//头结点不存数据，头结点储存的指针不需要变动，
	//只需修改头结点的next指针，除了创建链表的函数之外，其余位置都不需要传入头结点的引用
}
void creatList(struct node *&head)//指针的引用
{
	//struct node *p;
	//int a;
	//head = (struct node*)malloc(sizeof(struct node));//malloc返回的指针有extern声明，所以分配的空间在函数之外依然存在，属于匿名的静态变量
	//p = head;
	//for (int i = 0; i < 4; i++)
	//{
	//	p->next = (struct node*)malloc(sizeof(struct node));
	//	p = p->next;
	//	cin >> p->num;
	//}
	//p->next = NULL;//这是尾插法比较简练的代码方式
	creatEmptyList(head);
	for (int i = 0; i < 4; i++)
	{
		//cin >> a;
		addNode(head, i);
	}
}

void creatList(struct node *&head, int num[], int len)//头插法创建链表
{
	//int len = sizeof(num)/sizeof(int);//数组的长度不能在子函数中计算
	creatEmptyList(head);
	for (int i = 0; i < len; i++)
	{
		//cin >> a;
		addNode(head, num[i]);
	}
}
void creatListRear(struct node *&head, int num[], int len)//尾插法创建链表
{
	//int len = sizeof(num)/sizeof(int);//数组的长度不能在子函数中计算
	creatEmptyList(head);
	for (int i = 0; i < len; i++)
	{
		//cin >> a;
		addNodeToRear(head, num[i]);
	}
}

void print(struct node *head)
{
	head = head->next;
	while (head != NULL)
	{
		cout << head->num << ",";
		head = head->next;
	}
	cout << "\b \n";
}
void deleteRedundancy(struct node *head)
{
	struct node *p;
	p = head->next;
	while (p != NULL)
	{
		while (deleteNode(p, p->num));
		p = p->next;
	}
}
struct node* interSection(struct node *head1, struct node *head2)//求交集
{
	struct node *result, *p;
	head1 = head1->next;
	creatEmptyList(result);
	while (head1 != NULL)
	{
		if (findNode(head2, head1->num) != NULL)
		{
			addNode(result, head1->num);
		}
		head1 = head1->next;
	}
	//去除重复内容
	deleteRedundancy(result);
	return result;
}
struct node* unionSection(struct node *head1, struct node *head2)//求并集，要去除重复的内容
{
	struct node *result, *p;
	//result = new struct node;//可以使用new/delete代替malloc与free
	//result->next = NULL;
	creatEmptyList(result);
	//将两个链表合成一个链表
	head1 = head1->next;
	while (head1 != NULL)
	{
		addNode(result, head1->num);
		head1 = head1->next;
	}
	head2 = head2->next;
	while (head2 != NULL)
	{
		addNode(result, head2->num);
		head2 = head2->next;
	}
	//去除重复
	deleteRedundancy(result);
	return result;
}
void selectSort(struct node *head)//链表的选择排序
{
	//从小到大
	struct node *pminp, *p;
	//pminp指向最小值的前一个结点
	while (NULL != head->next)
	{
		pminp = head;
		p = pminp->next;
		while (NULL != p->next)
		{
			if (p->next->num < pminp->next->num)
			{
				pminp = p;
			}
			p = p->next;
		}
		//找到最小值的前一个节点
		p = pminp->next;
		pminp->next = p->next;
		p->next = head->next;
		head->next = p;
		head = head->next;
	}
}
void main()
{
	int num[] = { 2,3,5,1,7,2,8 };
	int len;
	int num1[] = { 2,9,3,5,6 };
	struct node *head, *h;
	//head只作为头结点，并不存储内容
	len = sizeof(num) / sizeof(int);
	creatList(head, num, len);
	print(head);
	addNode(head, 10);
	print(head);
	selectSort(head);
	print(head);
	//deleteNode(head, 10);
	//print(head);
	len = sizeof(num1) / sizeof(int);
	creatList(h, num1, len);
	print(h);
	selectSort(h);
	print(h);
	cout << "*********************\n";
	cout << "交集：" << endl;
	print(interSection(head, h));
	cout << "并集：" << endl;
	print(unionSection(head, h));
	//最后没有释放内存
	while (1);
}