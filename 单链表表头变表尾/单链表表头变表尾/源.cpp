#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num;
	struct node* next;
};
void print(struct node* head)
{
	head = head->next;
	while (head)
	{
		printf("%d,", head->num);
		head = head->next;
	}
	printf("\n");
}
void turn(struct node* head)
{
	struct node *p, *pn,*temp;
	p = head->next;
	pn = p->next;
	p->next = NULL;
	while (pn!= NULL)
	{
		temp = pn->next;
		pn->next = p;
		p = pn;
		pn = temp;
	}
	head->next= p;

}
void main()
{
	struct node *head,*p;
	head= (struct node*)malloc(sizeof(struct node));
	p= (struct node*)malloc(sizeof(struct node));
	head->next= p;
	p->num = 0;
	for (int i = 1; i < 10; i++) 
	{
		p->next= (struct node*)malloc(sizeof(struct node));
		p = p->next;
		p->num = i;
	}
	p->next = NULL;

	print(head);

	turn(head);
	print(head);

	while (true);
}