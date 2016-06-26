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
	p->next = temp;//��ͷ�巨����½ڵ�
}

void addNode(struct node *head, int n)
{
	struct node *temp, *p;
	p = (struct node*)malloc(sizeof(struct node));
	p->num = n;
	addNode(head, p);//��ͷ�巨����½ڵ�
}
void addNodeToRear(struct node *head,struct node *p)//β�巨����½��
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
	//���ز��ҵ���λ�õ�ǰһ���ڵ�
	//���ص�һ�����ҽ����֮����ܻ��з��������Ľ��
	//��head����һ����㿪ʼ��
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
bool deleteNode(struct node *head, int n)//�п�����Ҫ�޸�head
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
	//ͷ��㲻�����ݣ�ͷ��㴢���ָ�벻��Ҫ�䶯��
	//ֻ���޸�ͷ����nextָ�룬���˴�������ĺ���֮�⣬����λ�ö�����Ҫ����ͷ��������
}
void creatList(struct node *&head)//ָ�������
{
	//struct node *p;
	//int a;
	//head = (struct node*)malloc(sizeof(struct node));//malloc���ص�ָ����extern���������Է���Ŀռ��ں���֮����Ȼ���ڣ����������ľ�̬����
	//p = head;
	//for (int i = 0; i < 4; i++)
	//{
	//	p->next = (struct node*)malloc(sizeof(struct node));
	//	p = p->next;
	//	cin >> p->num;
	//}
	//p->next = NULL;//����β�巨�Ƚϼ����Ĵ��뷽ʽ
	creatEmptyList(head);
	for (int i = 0; i < 4; i++)
	{
		//cin >> a;
		addNode(head, i);
	}
}

void creatList(struct node *&head, int num[], int len)//ͷ�巨��������
{
	//int len = sizeof(num)/sizeof(int);//����ĳ��Ȳ������Ӻ����м���
	creatEmptyList(head);
	for (int i = 0; i < len; i++)
	{
		//cin >> a;
		addNode(head, num[i]);
	}
}
void creatListRear(struct node *&head, int num[], int len)//β�巨��������
{
	//int len = sizeof(num)/sizeof(int);//����ĳ��Ȳ������Ӻ����м���
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
struct node* interSection(struct node *head1, struct node *head2)//�󽻼�
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
	//ȥ���ظ�����
	deleteRedundancy(result);
	return result;
}
struct node* unionSection(struct node *head1, struct node *head2)//�󲢼���Ҫȥ���ظ�������
{
	struct node *result, *p;
	//result = new struct node;//����ʹ��new/delete����malloc��free
	//result->next = NULL;
	creatEmptyList(result);
	//����������ϳ�һ������
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
	//ȥ���ظ�
	deleteRedundancy(result);
	return result;
}
void selectSort(struct node *head)//�����ѡ������
{
	//��С����
	struct node *pminp, *p;
	//pminpָ����Сֵ��ǰһ�����
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
		//�ҵ���Сֵ��ǰһ���ڵ�
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
	//headֻ��Ϊͷ��㣬�����洢����
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
	cout << "������" << endl;
	print(interSection(head, h));
	cout << "������" << endl;
	print(unionSection(head, h));
	//���û���ͷ��ڴ�
	while (1);
}