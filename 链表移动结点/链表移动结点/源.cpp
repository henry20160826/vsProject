#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int num;
	struct node *next;
};
struct node* findMaxPrior(struct node *head)
{
	struct node *p;
	//head = head->next;
	p = head;
	while (head->next)
	{
		if (head->next->num > p->next->num)
		{
			p = head;
		}
		head = head->next;
	}
	return p;
}
void addRear(struct node *head,struct node *p)
{
	while (head->next)
	{
		head = head->next;
	}
	head->next = p;
	p->next = NULL;
}
void print(struct node *head)
{
	head = head->next;
	while (head)
	{
		cout << head->num << ",";
		head = head->next;
	}
	cout <<"\b \n";//字符串时需要使用双引号 如果分不清楚就始终使用双引号
}
void main()
{
	struct node *head,*p,*pmaxp;
	//建立链表
	head = (struct node*)malloc(sizeof(struct node));
	p=head;
	for (int i = 5; i > 0;i--)
	{
		p->next = (struct node*)malloc(sizeof(struct node));
		p = p->next;
		p->num = i;
	}
	p->next= NULL;
	print(head);

	pmaxp = findMaxPrior(head);
	p = pmaxp->next;
	pmaxp->next = p->next;//从链表中摘掉最大值点
	addRear(head, p);
	//cout << '2';
	print(head);
	while (true)
	{

	}
}
