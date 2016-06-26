#include<iostream>
using namespace std;
struct node
{
	int num;
	struct node *next;
};
class LinkedList
{
public:
	LinkedList()
	{
		creatEmptyList();//���к������Ե���˽�к���
	}
	LinkedList(int num[], int len)
	{
		creatList(num, len);//���к������Ե���˽�к���
	}
	~LinkedList()
	{
		struct node *p;
		p = head->next;
		while (p != NULL)
		{
			delete(head);
			head = p;
			p = p->next;
		}
		delete(head);
		cout << "�ұ�����" << endl;
	}
	struct node* gethead()
	{
		return head;
	}
	struct node* findNode(struct node *tempHead, int n)
	{
		//���ز��ҵ���λ�õ�ǰһ���ڵ�
		//���ص�һ�����ҽ����֮����ܻ��з��������Ľ��
		//��p����һ����㿪ʼ��
		while (NULL != tempHead->next)
		{
			if (tempHead->next->num == n)
			{
				return tempHead;
			}
			tempHead = tempHead->next;
		}
		return NULL;
	}
	struct node* update(struct node *tempHead,int oldData, int newData)//ֻ����tempHead����Ľ�㣬ֻ���·��ֵĵ�һ�����
	{
		tempHead = findNode(tempHead, oldData);
		if (NULL == tempHead)
		{
			return tempHead;
		}
		tempHead->next->num = newData;
		return tempHead;
	}
	bool updateAll(int oldData,int newData)//������������
	{
		struct node *tempHead = head;
		bool flag = false;
		tempHead = update(tempHead, oldData, newData);
		flag = (tempHead != NULL);
		while (tempHead!=NULL)
		{
			tempHead=update(tempHead, oldData, newData);
		}
		return flag;
	}
	bool deleteNode(struct node *tempHead, int n)//ɾ��p���֮�󣨲�����p�������ֵΪn�Ľ�㣨ֻɾ����һ����������ܻ��У�
	{
		struct node *prior, *p;
		prior = findNode(tempHead, n);
		if (NULL == prior)
		{
			return false;
		}
		p = prior->next;
		prior->next = p->next;
		delete(p);
		return true;
	}
	void addNode(struct node *p)
	{
		struct node *temp;
		temp = head->next;
		head->next = p;
		p->next = temp;//��ͷ�巨����½ڵ�
	}

	void addNode(int n)
	{
		struct node *p;
		p = (struct node*)malloc(sizeof(struct node));
		p->num = n;
		addNode(p);//��ͷ�巨����½ڵ�
	}
	void addNodeToRear(struct node *p)//β�巨����½��
	{
		struct node *tempHead = head;
		while (NULL != tempHead->next);
		p->next = NULL;
		tempHead->next = p;
	}
	void addNodeToRear(int n)
	{
		struct node *p;
		p = (struct node*)malloc(sizeof(struct node));
		p->num = n;
		addNodeToRear(p);
	}
	void print()
	{
		struct node *tempHead = head;
		tempHead = tempHead->next;
		while (tempHead != NULL)
		{
			cout << tempHead->num << ",";
			tempHead = tempHead->next;
		}
		cout << "\b \n";
	}
	void deleteRedundancy()
	{
		struct node *p = head->next;
		while (p != NULL)
		{
			while (deleteNode(p, p->num));
			p = p->next;
		}
	}
	LinkedList* interSection(LinkedList *list2)//�󽻼�
	{
		LinkedList *result = new LinkedList();
		struct node *tempHead1 = head;
		struct node *temphead2 = list2->gethead();
		tempHead1 = tempHead1->next;
		while (tempHead1 != NULL)
		{
			if (findNode(temphead2, tempHead1->num) != NULL)
			{
				result->addNode(tempHead1->num);
			}
			tempHead1 = tempHead1->next;
		}
		//ȥ���ظ�����
		result->deleteRedundancy();
		return result;
	}
	LinkedList* unionSection(LinkedList *list2)//�󲢼���Ҫȥ���ظ�������
	{
		LinkedList *result = new LinkedList();
		//����ʹ��new/delete����malloc��free
		//����������ϳ�һ������
		struct node *tempHead1 = head;
		struct node *temphead2 = list2->gethead();
		tempHead1 = tempHead1->next;
		while (tempHead1 != NULL)
		{
			result->addNode(tempHead1->num);
			tempHead1 = tempHead1->next;
		}
		temphead2 = temphead2->next;
		while (temphead2 != NULL)
		{
			result->addNode(temphead2->num);
			temphead2 = temphead2->next;
		}
		//ȥ���ظ�
		result->deleteRedundancy();
		return result;
	}
	void selectSort()//�����ѡ������
	{
		//��С����
		struct node *pminp, *p;
		struct node *tempHead1 = head;

		//pminpָ����Сֵ��ǰһ�����
		while (NULL != tempHead1->next)
		{
			pminp = tempHead1;
			p = pminp->next;
			//�ҵ���Сֵ��ǰһ���ڵ㣬pminpָ��������
			while (NULL != p->next)
			{
				if (p->next->num < pminp->next->num)
				{
					pminp = p;
				}
				p = p->next;
			}
			//ժ��pminp
			p = pminp->next;
			pminp->next = p->next;
			//����pminp
			p->next = tempHead1->next;
			tempHead1->next = p;
			tempHead1 = tempHead1->next;
		}
	}
private:
	struct node *head;
	void creatEmptyList()
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
		creatEmptyList();
		for (int i = 0; i < 4; i++)
		{
			//cin >> a;
			addNode(i);
		}
	}
	void creatList(int num[], int len)//ͷ�巨��������
	{
		//int len = sizeof(num)/sizeof(int);//����ĳ��Ȳ������Ӻ����м���
		creatEmptyList();
		for (int i = 0; i < len; i++)
		{
			//cin >> a;
			addNode(num[i]);
		}
	}
	void creatListRear(int num[], int len)//β�巨��������
	{
		//int len = sizeof(num)/sizeof(int);//����ĳ��Ȳ������Ӻ����м���
		creatEmptyList();
		for (int i = 0; i < len; i++)
		{
			//cin >> a;
			addNodeToRear(num[i]);
		}
	}
};
void main()
{
	int num[] = { 2,3,5,1,7,2,8 };
	int len;
	int num1[] = { 2,9,3,5,6 };
	LinkedList *l1, *l2, *lj, *lu;
	len = sizeof(num) / sizeof(int);
	l1 = new LinkedList(num, len);
	l1->print();
	l1->addNode(10);
	l1->print();
	l1->selectSort();
	l1->print();
	//deleteNode(head, 10);
	//print(head);
	len = sizeof(num1) / sizeof(int);
	l2 = new LinkedList(num1, len);
	l2->print();
	l2->selectSort();
	l2->print();
	cout << "*********************\n";
	cout << "������" << endl;
	lj = l1->interSection(l2);
	lj->print();
	cout << "������" << endl;
	lu = l1->unionSection(l2);
	lu->print();
	delete(l1);
	delete(l2);
	delete(lj);
	delete(lu);
	while (1);
}