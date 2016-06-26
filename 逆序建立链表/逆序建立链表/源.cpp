#include<iostream>
#include<stdlib.h>
using namespace std;

struct node 
{
	int num;
	struct node *next;
};
void print(struct node *head)//输出头结点不储存数据的链表
{
	head = head->next;
	while (head)
	{
		printf("%d,", head->num);
		head = head->next;
	}
	cout << "\n";
}
void reverse(struct node *head)//用头插法将已有链表逆序
{
	struct node *p,*pp;
	pp = head->next;
	head->next = NULL;
	while (pp!=NULL)
	{
		p = pp->next;
		pp->next = head->next;
		head->next = pp;
		pp = p;
	}
}
void main()
{
	const int N = 3;
	int a[N];
	for (int i = 0; i < N; i++)
	{
		cout << "将要输入的是第" << i+1<< "个\n";
		cin >> a[i];
	}
	struct node *head,*p;
	p = (struct node*)malloc(sizeof(struct node));
	head = p;//头结点没存内容
	for (int i = 0; i < N; i++)
	{
		p->next = (struct node*)malloc(sizeof(struct node));
		p = p->next;
		p->num = a[N-i-1];
	}
	p->next= NULL;
	print(head);
	reverse(head);
	print(head);
	while (1);
}